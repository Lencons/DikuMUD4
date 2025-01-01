/** @file
 * @brief Manage the reading and writing of player data to disk.
 * 
 * Functions to save and retrieve Player data saved to the local filesystem.
 * The Player's character data is stored within the server configured PlyDir
 * Player data directory in a file with the filename of the Player name in
 * lowercase and a ".dat" file extension.
 * 
 * Global Player ID
 * ================
 * The global variable g_player_id is used to store the ID of the next player
 * to be created within the game engine. This value is generated at server
 * boot time by scanning all '.dat' files within the Player data directory to
 * identify the highest currently allocated ID, then that ID plus 1 is stored
 * g_player_id for the operational use of this module.
 *      
 */

#include "account.h"
#include "affect.h"
#include "comm.h"
#include "db.h"
#include "db_file.h"
#include "dilrun.h"
#include "error.h"
#include "files.h"
#include "formatter.h"
#include "handler.h"
#include "interpreter.h"
#include "mobact.h"
#include "money.h"
#include "reception.h"
#include "slog.h"
#include "textutil.h"
#include "utils.h"

#include <cstdio>
#include <cstring>
#include <ctime>
#include <dirent.h>
#include <sys/stat.h>

sbit32 g_player_id = 1;

void assign_player_file_index(unit_data *pc)
{
    zone_type *z = find_zone(g_player_zone);
    pc->setFileIndex(z->findOrCreatePlayerFileIndex(PC_FILENAME(pc)));
}


/****************************************************************************
 * @brief Generate base Filename for Player data files.
 * 
 * Generates the base filename prefixed with the server configured Player
 * data directory for the storing of Player specific data. It is expected that
 * any service within the server that is managing stored Player data is using
 * a unique file extension associated to the data that is being stored.
 * 
 * @param player_name   Pointer to character name string.
 * @return              Player data file with path.
 * 
 ****************************************************************************/
std::string player_filename(const char *player_name)
{
    std::string filename = "";

    if (!player_name) {
        slog(
            LOG_ALL,
            0,
            "ERROR - Null string provided to player_filename()!!!!",
            nullptr
        );
    }
    else {
        char *tmp_name = str_dup(player_name);
        char *p = tmp_name;
        while (*p) {
            *p = tolower(*p);
            p++;
        }

        filename = diku::format_to_str(
                        "%s%s.dat",
                        g_cServerConfig.getPlyDir(),
                        tmp_name
                   );
    }

    return filename;
}


/****************************************************************************
 * Test if a Player already exists.
 *
 * A Player is deemed to exist if a character data file exists for that
 * Player.
 * 
 * @param player_name   Pointer to character name string.
 * @return              True if Player data is found, otherwise FALSE.
 * 
 ****************************************************************************/
int player_exists(const char *player_name)
{
    return file_exists(player_filename(player_name));
}


unit_data *find_player(char *name)
{
    descriptor_data *d = nullptr;

    d = find_descriptor(name, nullptr);

    if (d && (d->getFunctionPtr() == descriptor_interpreter) && d->cgetCharacter())
    {
        return d->getCharacter();
    }
    else
    {
        return nullptr;
    }
}


/****************************************************************************
 * Delete a Players inventory data.
 * 
 * Delete the stored inventory for the provided Player name. This is just a
 * matter of removing the inventory file for the player.
 * 
 * @param player_name   Pointer to character name string.
 * @return              True if the Players inventory is removed, otherwise
 *                      False.
 * 
 ****************************************************************************/
int delete_inventory(const char *player_name)
{
    if (std::remove(inventory_filename(player_name).c_str())) {
        return FALSE;
    }

    return TRUE;
}


/****************************************************************************
 * Delete a Players data.
 * 
 * Delete the stored data for the provided Player name. This includes any
 * inventory which has also been saved for the Player.
 * 
 * @param player_name   Pointer to character name string.
 * @return              True if the Players data is removed, otherwise Fales.
 * 
 ****************************************************************************/
int delete_player(const char *player_name)
{
    if (std::remove(player_filename(player_name).c_str())){
        return FALSE;
    }

    return delete_inventory(player_name);
}

/****************************************************************************
 * Retrieve a Players ID from their stored data.
 * 
 * For the provided Player name, read their data faile and extract the Player
 * ID that has been assigned to them.
 * 
 * @param player_name   Pointer to character name string.
 * @return              The ID of the Player, -1 on Player not found.
 * 
 ****************************************************************************/
sbit32 find_player_id(char *player_name)
{
    FILE *pFile = nullptr;
    sbit32 id = 0;

    if (str_is_empty(player_name)) {
        slog(LOG_ALL, 0, "Empty string in find_player_id().");
        return -1;
    }

    pFile = fopen(player_filename(player_name).c_str(), "rb");

    if (pFile == nullptr) {
        slog(
            LOG_ALL,
            0,
            "Unable to open Player file for: %s",
            player_name
        );
        return -1;
    }

    rewind(pFile);
    if (fread(&id, sizeof(sbit32), 1, pFile) != 1){
        slog(
            LOG_ALL,
            0,
            "Unable to read ID for player: '%s'",
            player_name
        );
        return -1;
    }
    fclose(pFile);

    return id;
}

/****************************************************************************
 * Generate the last (highest) Player ID.
 * 
 * Player ID's are unique and assigned to characters on an incrementing
 * basis. To determine what the last created Players ID was, or the maximum
 * currently allocated ID, each Player data file is read and the Player
 * ID stored is evaluated to identify the highest ID.
 * 
 * @return      The highest Player ID currently assigned.
 * 
 ****************************************************************************/
sbit32 max_player_id(void)
{
    sbit32 max_id = -7;     // No players exist, first player will be our god.
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(g_cServerConfig.getPlyDir().c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            // Player data files will end in '.dat'.
            char *p = ent->d_name + strlen(ent->d_name) - 4;
            if (strncmp(p, ".dat", 4) == 0) {
                char *name = strndup(ent->d_name, strlen(ent->d_name) - 4);
                sbit32 id = find_player_id(name);
                if (id > max_id) {
                    max_id = id;
                }
            }
        }
        closedir (dir);
    } else {
        slog(LOG_ALL, 0, "Failed to open Player Data directory!!");
    }

    return max_id;
}


/****************************************************************************
 * Generate the next Player ID.
 * 
 * The currently max Player Id is stored in g_player_id, it is incremented
 * and returned.
 * 
 * @return      The next Player ID.
 * 
 ****************************************************************************/
sbit32 new_player_id()
{
    return g_player_id++;
}


/****************************************************************************
 * Write player data to disk.
 * 
 * Write updated Player data to the players data file on disk. This process
 * is performed in a manner in which limits the chance of a players data
 * becoming corrupted with the following steps:
 *      - Generate update player data in memory
 *      - Rename any exiting Player file to a '.bak' backup
 *      - Write out player data to a new data file
 *      - Remove the backup file
 * If an error is encounted in any part of this process the Player backup file
 * is renamed back to be the active Player data file. This ensures that no
 * existing data is modifed as renaming will only manipluate directoy listing
 * data.
 * 
 * @param player_name   Pointer to character name string.
 * @param id            Character ID from index file.
 * @param buf_len       Length of player data in bytes.
 * @param player_data   Pointer to raw player data.
 * 
 ****************************************************************************/
void save_player_disk(
    const char *player_name,
    sbit32 id,
    int buf_len,
    const ubit8 *player_data)
{
    void *p;
    std::vector<unsigned char> data_buf;
    std::string tmp_filename;
    FILE *fp;
    int write_cnt;

    // Generate byte buffer to write out to player file.
    data_buf.resize(sizeof(id) + sizeof(buf_len) + buf_len);
    p = data_buf.data();
    std::memcpy(p, &id, sizeof(id));
    p = (void *) ((unsigned char *)p + sizeof(id));
    std::memcpy(p, &buf_len, sizeof(buf_len));
    p = (void *) ((unsigned char *)p + sizeof(buf_len));
    std::memcpy(p, player_data, buf_len);

    // Rename any existing player file as a backup.
    if (file_exists(player_filename(player_name).c_str())) {
        tmp_filename = player_filename(player_name) + ".bak";

        // If an existing backup exists, then we assume we are dealing with
        // an error condition and the original backup is more valuable than
        // the currently player file.
        if (file_exists(tmp_filename.c_str())) {
            slog(
                LOG_ALL,
                0,
                "WARNING - Player backup file already exists: %s",
                tmp_filename.c_str()
            );
            slog(
                LOG_ALL,
                0,
                "Deleting Player file in prefence of exisint backup: %s",
                player_filename(player_name).c_str()
            );
            std::remove(player_filename(player_name).c_str());
        }
        else {
            slog(
                LOG_ALL,
                0,
                "Backing up Player file to: %s",
                tmp_filename.c_str()
            );
            std::rename(player_filename(player_name).c_str(), tmp_filename.c_str());
        }
    }

    // Write the Player data to disk
    fp = fopen(player_filename(player_name).c_str(), "wb");
    write_cnt = std::fwrite(data_buf.data(), data_buf.size(), 1, fp);
    fclose(fp);
    if (write_cnt != 1) {
        slog(
            LOG_ALL,
            0,
            "ERROR - Writing to Player data file: %s",
            player_filename(player_name).c_str()
        );
        std::remove(player_filename(player_name).c_str());

        if (!tmp_filename.empty()) {
            slog(
                LOG_ALL,
                0,
                "Restoring backup Player data file: %s",
                tmp_filename.c_str()
            );
            std::rename(tmp_filename.c_str(), player_filename(player_name).c_str());
        }
    }
    else {
        // If we created a backup file, clean-up.
        if (!tmp_filename.empty()) {
            std::remove(tmp_filename.c_str());
            slog(
                LOG_ALL,
                0,
                "Player backup file removed: %s",
                tmp_filename.c_str()
            );
        }
    }
}

/* Save the player 'pc' (no inventory) */
void save_player_file(unit_data *pc)
{
    static bool locked = FALSE;
    sbit32 nPlyLen = 0;
    int tmp_i = 0;
    unit_data *tmp_u = nullptr;
    unit_data *list = nullptr;
    descriptor_data *tmp_descr = nullptr;
    CByteBuffer *pBuf = &g_FileBuffer;

    pBuf->Clear();

    assert(pc->isPC());
    assert(strlen(PC_FILENAME(pc)) < pc_data::PC_MAX_NAME);
    assert(!pc->is_destructed());

    if (pc->is_destructed())
    {
        return;
    }

    if (locked)
    {
        slog(LOG_ALL, 0, "ERROR: INFORM PAPI OF A RECURSIVE CALL OF SAVE PLAYER!");
        return;
    }

    locked = TRUE;

    if (PC_IS_UNSAVED(pc))
    {
        PC_TIME(pc).incTotalTimePlayedInSecondsBy(1);
    }

    /* PRIMITIVE SANITY CHECK */
    slog(LOG_ALL, 0, "Saving PC %s id =%d", pc->getNames().Name(), PC_ID(pc));
    assert(PC_ID(pc) >= 0 && PC_ID(pc) <= 1000000);

    if (pc->getUnitIn() && !IS_SET(unit_room(pc)->getUnitFlags(), UNIT_FL_NOSAVE))
    {
        UCHAR(pc)->setLastLocation(unit_room(pc));
    }

    tmp_descr = CHAR_DESCRIPTOR(pc);
    UCHAR(pc)->setDescriptor(nullptr); // Do this to turn off all messages!

    /* Remove all inventory and equipment in order to make a CLEAN save */
    while ((tmp_u = pc->getUnitContains()))
    {
        if (tmp_u->isObj())
        {
            if ((tmp_i = OBJ_EQP_POS(tmp_u)))
            {
                unequip_object(tmp_u);
            }
            UOBJ(tmp_u)->setEquipmentPosition(tmp_i);
        }
        unit_from_unit(tmp_u);
        tmp_u->setNext(list);
        list = tmp_u;
    }

    send_save_to(pc, pc); // Tell funcs on PC he is saved now...

    /* Player is now clean (empty and unequipped) */
    nPlyLen = write_unit_string(pBuf, pc);

    save_player_disk(PC_FILENAME(pc), PC_ID(pc), nPlyLen, pBuf->GetData());

    /* Restore all inventory and equipment */
    while ((tmp_u = list))
    {
        list = list->getNext();
        tmp_u->setNext(nullptr);

        unit_to_unit(tmp_u, pc);

        if (tmp_u->isObj())
        {
            tmp_i = OBJ_EQP_POS(tmp_u);
            UOBJ(tmp_u)->setEquipmentPosition(0);
            if (tmp_i)
            {
                equip_char(pc, tmp_u, tmp_i);
            }
        }
    }

    UCHAR(pc)->setDescriptor(tmp_descr); // Turn msgs back on

    locked = FALSE;
}

/* If 'fast' is false compression is used for inventory.       */
void save_player_contents(unit_data *pc, int fast)
{
    static bool locked = FALSE;
    time_t t0 = 0;
    time_t keep_period = 0;
    amount_t daily_cost = 0;
    currency_t cur = local_currency(pc);

    assert(pc->isPC());

    if (locked)
    {
        slog(LOG_ALL, 0, "ERROR: INFORM PAPI OF A RECURSIVE SAVE INVENTORY!");
        return;
    }

    locked = TRUE;

    /* Too much log in convert
       slog(LOG_ALL, "Saving %s [len %d of %d].", PC_FILENAME(pc), len,
       filbuffer_length); */

    /* Calculate for how long player may keep objects until erased */
    t0 = time(nullptr);
    keep_period = t0;

    daily_cost = save_contents(PC_FILENAME(pc), pc, FALSE);

    if (daily_cost <= 0)
    {
        keep_period += SECS_PER_REAL_DAY * 30;
    }
    else
    {
        amount_t amount = char_holds_amount(pc, DEF_CURRENCY);

        if (amount > 0)
        {
            int tmp_i = 0;
            time_t tdiff = 0;

            /* No of days items may be kept (Maximum of 30!) */
            tmp_i = MIN(30, amount / daily_cost);

            if (tmp_i >= 1)
            {
                keep_period += tmp_i * SECS_PER_REAL_DAY;
                amount -= tmp_i * daily_cost;
            }

            if (tmp_i < 30)
            {
                keep_period += (int)(((float)SECS_PER_REAL_DAY * (float)amount) / (float)daily_cost);
            }

            tdiff = (keep_period - t0) / SECS_PER_REAL_HOUR;
            act("Inventory expires in $2d hours ($3t daily).", eA_ALWAYS, pc, (int *)&tdiff, money_string(daily_cost, cur, FALSE), eTO_CHAR);
        }
        else
        {
            act("You can't afford to keep your inventory (cost is $3t).",
                eA_ALWAYS,
                pc,
                cActParameter(),
                money_string(daily_cost, cur, FALSE),
                eTO_CHAR);
        }
    }

    locked = FALSE;
}

/* Save the player 'pc'. Update logon and playing time.        */
void save_player(unit_data *pc)
{
    if (CHAR_DESCRIPTOR(pc))
    {
        time_t t0 = 0;
        ubit32 used = 0;

        t0 = time(nullptr);
        if (t0 < CHAR_DESCRIPTOR(pc)->getLastLogonTime())
        {
            slog(LOG_ALL, 0, "PCSAVE: Current less than last logon");
            CHAR_DESCRIPTOR(pc)->setLastLogonTime(t0);
        }

        account_subtract(pc, CHAR_DESCRIPTOR(pc)->getLastLogonTime(), t0);

        used = t0 - CHAR_DESCRIPTOR(pc)->getLastLogonTime();

        PC_TIME(pc).incTotalTimePlayedInSecondsBy(used);
        CHAR_DESCRIPTOR(pc)->setLastLogonTime(t0);

        if (account_is_closed(pc))
        {
            account_closed(pc);
        }
        else if (account_is_overdue(pc))
        {
            account_overdue(pc);
        }
    }

    save_player_file(pc);
}

/* Read player from file, starting at index "index" */
/* String is allocated                              */
unit_data *load_player_file(FILE *pFile)
{
    unit_data *pc = nullptr;
    ubit32 nPlyLen = 0;
    ubit32 n = 0;
    sbit32 id = 0;
    CByteBuffer *pBuf = nullptr;

    assert(pFile);

    n = fread(&id, sizeof(int), 1, pFile);
    if (n != 1)
    {
        return nullptr;
    }

    n = fread(&nPlyLen, sizeof(nPlyLen), 1, pFile);
    if (n != 1)
    {
        return nullptr;
    }

    pBuf = &g_FileBuffer;
    n = pBuf->FileRead(pFile, nPlyLen);

    if (n != nPlyLen)
    {
        slog(LOG_ALL, 0, "ERROR: PC FILE LENGTH MISMATCHED RECORDED LENGTH!");
    }

    pc = read_unit_string(pBuf, UNIT_ST_PC, nPlyLen, "Player");

    if (pc == nullptr)
    {
        return nullptr;
    }

    if (g_nCorrupt)
    {
        return nullptr;
    }

    return pc;
}

/* Read player from file, starting at index "index"   */
/* String is allocated                                */
/* Is neither inserted in unit_list not into anything */
unit_data *load_player(const char *pName)
{
    FILE *pFile = nullptr;
    unit_data *pc = nullptr;

    if (str_is_empty(pName))
    {
        return nullptr;
    }

    pFile = fopen(player_filename(pName).c_str(), "rb");
    if (pFile == nullptr)
    {
        return nullptr;
    }

    pc = load_player_file(pFile);
    assign_player_file_index(pc);

    fclose(pFile);

    if (pc == nullptr)
    {
        slog(LOG_ALL, 0, "Corrupted player %s.", pName);
        return nullptr;
    }
    else
    {
        stop_affect(pc);
        stop_all_special(pc);
        DeactivateDil(pc);
    }

    if (str_ccmp(pName, PC_FILENAME(pc)))
    {
        slog(LOG_ALL, 0, "Mismatching player name %s / %s.", pName, PC_FILENAME(pc));
        extract_unit(pc);
        return nullptr;
    }

    if (PC_IS_UNSAVED(pc))
    {
        slog(LOG_ALL, 0, "PC loaded with unsaved set!", pName);
        PC_TIME(pc).incTotalTimePlayedInSecondsBy(1);
    }

    return pc;
}


/****************************************************************************
 * Boot time Player Indexing.
 * 
 * This is called at server boot time to set up Player indexing.
 * 
 ****************************************************************************/
void player_file_index()
{
    g_player_id = max_player_id();

    if (g_player_id == -7) {
        slog(LOG_ALL, 0, "Must be first server boot, first character will be god.");
    }
    else {
        // stores the next Player ID to use.
        g_player_id++;
    }
}
