/*
 $Author: All $
 $RCSfile: pcsave.cpp,v $
 $Date: 2004/09/21 08:45:46 $
 $Revision: 2.7 $
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
#include <sys/stat.h>

// MS2020 sbit32 g_player_id = -1;
sbit32 g_player_id = 1; // Looks to me like it needs to begin with 1 (crash on start)

void assign_player_file_index(unit_data *pc)
{
    zone_type *z = find_zone(g_player_zone);
    pc->setFileIndex(z->findOrCreatePlayerFileIndex(PC_FILENAME(pc)));
}


/****************************************************************************
 * Generate base Filename for Player data files.
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
std::string PlayerFileName(const char *player_name)
{
    std::string filename = "";

    if (player_name == nullptr) {
        slog(
            LOG_ALL,
            0,
            "ERROR - Null string provided to PlayerFileName()!!!!",
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
                        "%s%c/%s",
                        g_cServerConfig.getPlyDir(),
                        *tmp_name,
                        tmp_name
                   );
    }

    return filename;
}


/****************************************************************************
 * Check that the required data directory extists for the Player.
 * 
 * Make sure that the required directory structure exists for the provided
 * player. This will generally deal with issues when running within a
 * container environment where the player data directory may not initially
 * exist or is complete.
 * 
 * @param player_name   Pointer to character name string.
 * 
 ****************************************************************************/
void check_player_dir(const char *player_name) {

    // Create a lowercase version of the Player name.
    char *tmp_name = str_dup(player_name);
    char *p = tmp_name;
    while (*p) {
        *p = tolower(*p);
        p++;
    }

    if (player_name == nullptr) {
        slog(
            LOG_ALL,
            0,
            "ERROR - Null string provided to check_player_dir()!!!!",
            nullptr
        );

        return;
    }

    // Start with the Player data directory.
    if (!directory_exists(g_cServerConfig.getPlyDir().c_str())) {
        slog(
            LOG_ALL,
            0,
            "Player directory doesn't exist, creating: %s",
            g_cServerConfig.getPlyDir().c_str()
        );
        if (mkdir(g_cServerConfig.getPlyDir().c_str(),S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH) == -1) {
            slog(
                LOG_ALL,
                0,
                "FATAL - Failed to create player data directory.",
                nullptr
            );
            assert(FALSE);
        }
    }

    // Make sure that the Player hash directory exists.
    std::string hash_dir(1, tolower(*player_name));
    hash_dir.insert(0, g_cServerConfig.getPlyDir());

    if (!directory_exists(hash_dir.c_str())) {
        slog(
            LOG_ALL,
            0,
            "Player hash directory doesn't exist, creating: %s",
            hash_dir.c_str()
        );
        if (mkdir(hash_dir.c_str(),S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH) == -1) {
            slog(
                LOG_ALL,
                0,
                "FATAL - Failed to create player hash data directory.",
                nullptr
            );
            assert(FALSE);
        }
    }
}


/* Return TRUE if exists */
int player_exists(const char *pName)
{
    return file_exists(PlayerFileName(pName));
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

/* Return TRUE if deleted */
int delete_inventory(const char *pName)
{
    if (remove(contents_filename(pName)))
    {
        return FALSE;
    }

    return TRUE;
}

/* Return TRUE if deleted */
int delete_player(const char *pName)
{
    if (remove(PlayerFileName(pName).c_str()))
    {
        return FALSE;
    }

    delete_inventory(pName);

    return TRUE;
}

/* Given a name, return pointer to player-idx blk, or BLK_NULL if non exist */
sbit32 find_player_id(char *pName)
{
    FILE *pFile = nullptr;
    sbit32 id = 0;

    if (str_is_empty(pName))
    {
        slog(LOG_ALL, 0, "Empty string in find_player_id.");
        return -1;
    }

    pFile = fopen(PlayerFileName(pName).c_str(), "rb");

    if (pFile == nullptr)
    {
        return -1;
    }

    rewind(pFile);

    if (fread(&id, sizeof(sbit32), 1, pFile) != 1)
    {
        error(HERE, "Unable to read ID for player: '%s'", pName);
    }

    fclose(pFile);

    return id;
}

/* Call to read current id from file*/
sbit32 read_player_id()
{
    sbit32 tmp_sl = 0;
    FILE *pFile = nullptr;

    /* By using r+ we are sure that we don't erase it accidentially
       if the host crashes just after opening the file. */

    pFile = fopen_cache(g_cServerConfig.getFileInLibDir(PLAYER_ID_NAME), "r+");
    assert(pFile);
    fseek(pFile, 0, SEEK_SET);
    int mstmp = fscanf(pFile, " %d ", &tmp_sl);
    if (mstmp < 1)
    {
        slog(LOG_ALL, 0, "ERROR: Unexpected bytes in read_player_id %d", mstmp);
        assert(FALSE);
    }

    return tmp_sl;
}

/* Call to generate new id */
sbit32 new_player_id()
{
    FILE *pFile = nullptr;

    /* By using r+ we are sure that we don't erase it accidentially
       if the host crashes just after opening the file. */

    pFile = fopen_cache(g_cServerConfig.getFileInLibDir(PLAYER_ID_NAME), "r+");
    assert(pFile);
    fseek(pFile, 0, SEEK_SET);

    fprintf(pFile, " %d ", g_player_id + 1);

    // fflush(pFile);
    slog(LOG_ALL, 0, "new player id = %d", (g_player_id + 1));
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

    // Make sure we have the required Player directory.
    check_player_dir(player_name);

    // Generate byte buffer to write out to player file.
    data_buf.resize(sizeof(id) + sizeof(buf_len) + buf_len);
    p = data_buf.data();
    std::memcpy(p, &id, sizeof(id));
    p = (void *) ((unsigned char *)p + sizeof(id));
    std::memcpy(p, &buf_len, sizeof(buf_len));
    p = (void *) ((unsigned char *)p + sizeof(buf_len));
    std::memcpy(p, player_data, buf_len);

    // Rename any existing player file as a backup.
    if (file_exists(PlayerFileName(player_name).c_str())) {
        tmp_filename = PlayerFileName(player_name) + ".bak";

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
                PlayerFileName(player_name).c_str()
            );
            std::remove(PlayerFileName(player_name).c_str());
        }
        else {
            slog(
                LOG_ALL,
                0,
                "Backing up Player file to: %s",
                tmp_filename.c_str()
            );
            std::rename(PlayerFileName(player_name).c_str(), tmp_filename.c_str());
        }
    }

    // Write the Player data to disk
    fp = fopen(PlayerFileName(player_name).c_str(), "wb");
    write_cnt = std::fwrite(data_buf.data(), data_buf.size(), 1, fp);
    fclose(fp);
    if (write_cnt != 1) {
        slog(
            LOG_ALL,
            0,
            "ERROR - Writing to Player data file: %s",
            PlayerFileName(player_name).c_str()
        );
        std::remove(PlayerFileName(player_name).c_str());

        if (!tmp_filename.empty()) {
            slog(
                LOG_ALL,
                0,
                "Restoring backup Player data file: %s",
                tmp_filename.c_str()
            );
            std::rename(tmp_filename.c_str(), PlayerFileName(player_name).c_str());
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

    pFile = fopen(PlayerFileName(pName).c_str(), "rb");
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

/* Call at boot time to index file */
void player_file_index()
{
    FILE *pFile = nullptr;
    sbit32 tmp_sl = 0;
    int n = 0;
    std::string tmp_player_name = g_cServerConfig.getPlyDir() + "player.tmp";

    /* Get rid of any temporary player save file */
    while (file_exists(tmp_player_name))
    {
        n = std::remove(tmp_player_name.c_str());
        if (n != 0)
        {
            slog(LOG_ALL, 0, "Remove failed");
        }
        if (file_exists(tmp_player_name))
        {
            n = std::rename(tmp_player_name.c_str(), "./playingfuck");
            if (n != 0)
            {
                error(HERE, "Rename failed too - going down :-(");
            }
        }
    }

    if (!file_exists(g_cServerConfig.getFileInLibDir(PLAYER_ID_NAME)))
    {
        touch_file(g_cServerConfig.getFileInLibDir(PLAYER_ID_NAME));
        g_player_id = -7;
        return;
    }

    pFile = fopen_cache(g_cServerConfig.getFileInLibDir(PLAYER_ID_NAME), "r+");
    assert(pFile);

    int mstmp = fscanf(pFile, " %d ", &tmp_sl);
    if (mstmp < 1)
    {
        slog(LOG_ALL, 0, "ERROR: Unexpected bytes in player_file_index %d", mstmp);
        assert(FALSE);
    }

    if ((g_player_id = tmp_sl) <= 0)
    {
        slog(LOG_ALL, 0, "WARNING: Player ID is %d", g_player_id);
    }
}
