<div class="mw-parser-output"><h4><span class="mw-headline" id="Complete_magical_transfers_macros_listing">Complete magical transfers macros listing</span></h4>
<p>This listing of macros was taken from
	<i>wmacros.h</i>.  When building your objects you should
	check the macros file to make sure you have the most up to date
	macros.
</p>
<pre>	#define CHAR_FLAG_TRANSFER(_MFLAGS) \
	flags {UNIT_FL_MAGIC}       \
	affect                            \
	   id ID_TRANSFER_CHARFLAGS       \
	   duration -1                    \
	   data[0] _MFLAGS                \
	   firstf TIF_EYES_TINGLE         \
	   tickf TIF_NONE                 \
	   lastf TIF_EYES_TINGLE          \
	   applyf APF_MOD_CHAR_FLAGS;

	/* skill MUST be one of SKI_XXX, amount in -10 to +10 */
	#define SKILL_TRANSFER(skill, amount) \
	flags {UNIT_FL_MAGIC}        \
	affect                       \
	   id ID_SKILL_TRANSFER      \
	   duration -1               \
	   data[0] skill             \
	   data[1] amount            \
	   firstf  TIF_SKI_INC       \
	   tickf   TIF_NONE          \
	   lastf   TIF_SKI_DEC       \
	   applyf  APF_SKILL_ADJ;

	/* weapon MUST be one of WPN_XXX, amount in -10 to +10 */
	#define WEAPON_TRANSFER(weapon, amount) \
	flags {UNIT_FL_MAGIC}        \
	affect                       \
	   id ID_WEAPON_TRANSFER     \
	   duration -1               \
	   data[0] weapon            \
	   data[1] amount            \
	   firstf  TIF_WPN_INC       \
	   tickf   TIF_NONE          \
	   lastf   TIF_WPN_DEC       \
	   applyf  APF_WEAPON_ADJ;

	/* spell MUST be one of SPL_XXX, amount in -10 to +10 */
	#define SPELL_TRANSFER(spell, amount) \
	flags {UNIT_FL_MAGIC}        \
	affect                       \
	   id ID_SPELL_TRANSFER      \
	   duration -1               /* Must be permanent in the object */  \
	   data[0] spell             /* It is a spell SPL_XXX transfer  */  \
	   data[1] amount            /* Amount of better spell skill    */  \
	   firstf  TIF_SPL_INC       \
	   tickf   TIF_NONE          \
	   lastf   TIF_SPL_DEC       \
	   applyf  APF_SPELL_ADJ;

	#define STR_TRANSFER(amount) \
	flags {UNIT_FL_MAGIC}       \
	affect                       \
	   id ID_TRANSFER_STR        \
	   duration -1                /* Must be permanent in the object */  \
	   data[0] ABIL_STR           /* It is a strength function       */  \
	   data[1] amount             /* Amount of better strength       */  \
	   firstf  TIF_STR_INC       \
	   tickf   TIF_NONE          \
	   lastf   TIF_STR_DEC       \
	   applyf  APF_ABILITY;

	#define DEX_TRANSFER(amount) \
	flags {UNIT_FL_MAGIC}       \
	affect                       \
	   id ID_TRANSFER_DEX        \
	   duration -1                 /* Must be permanent in the object */  \
	   data[0] ABIL_DEX            /* It is a dex function            */  \
	   data[1] amount              /* Amount of better dex            */  \
	   firstf  TIF_DEX_INC       \
	   tickf   TIF_NONE          \
	   lastf   TIF_DEX_DEC       \
	   applyf  APF_ABILITY;

	#define CON_TRANSFER(amount) \
	flags {UNIT_FL_MAGIC}       \
	affect                       \
	   id ID_TRANSFER_CON        \
	   duration -1                 /* Must be permanent in the object */  \
	   data[0] ABIL_CON            /* It is a con function            */  \
	   data[1] amount              /* Amount of better con            */  \
	   firstf  TIF_CON_INC       \
	   tickf   TIF_NONE          \
	   lastf   TIF_CON_DEC       \
	   applyf  APF_ABILITY;

	#define CHA_TRANSFER(amount) \
	flags {UNIT_FL_MAGIC}        \
	affect                       \
	   id ID_TRANSFER_CHA        \
	   duration -1                 /* Must be permanent in the object */  \
	   data[0] ABIL_CHA            /* It is a cha function            */  \
	   data[1] amount              /* Amount of better cha            */  \
	   firstf  TIF_CHA_INC       \
	   tickf   TIF_NONE          \
	   lastf   TIF_CHA_DEC       \
	   applyf  APF_ABILITY;

	#define BRA_TRANSFER(amount) \
	flags {UNIT_FL_MAGIC}       \
	affect                       \
	   id ID_TRANSFER_BRA        \
	   duration -1                 /* Must be permanent in the object */  \
	   data[0] ABIL_BRA            /* It is a bra function            */  \
	   data[1] amount              /* Amount of better bra            */  \
	   firstf  TIF_BRA_INC       \
	   tickf   TIF_NONE          \
	   lastf   TIF_BRA_DEC       \
	   applyf  APF_ABILITY;

	#define MAG_TRANSFER(amount) \
	flags {UNIT_FL_MAGIC}       \
	affect                       \
	   id ID_TRANSFER_MAG        \
	   duration -1                 /* Must be permanent in the object */  \
	   data[0] ABIL_MAG            /* It is a mag function            */  \
	   data[1] amount              /* Amount of better mag            */  \
	   firstf  TIF_MAG_INC       \
	   tickf   TIF_NONE          \
	   lastf   TIF_MAG_DEC       \
	   applyf  APF_ABILITY;

	#define DIV_TRANSFER(amount) \
	flags {UNIT_FL_MAGIC}       \
	affect                       \
	   id ID_TRANSFER_DIV        \
	   duration -1                 /* Must be permanent in the object */  \
	   data[0] ABIL_DIV            /* It is a div function            */  \
	   data[1] amount              /* Amount of better div            */  \
	   firstf  TIF_DIV_INC       \
	   tickf   TIF_NONE          \
	   lastf   TIF_DIV_DEC       \
	   applyf  APF_ABILITY;

	#define HIT_TRANSFER(amount) \
	flags {UNIT_FL_MAGIC}       \
	affect                       \
	   id ID_TRANSFER_HPP        \
	   duration -1                /* Must be permanent in the object */  \
	   data[0] ABIL_HP            /* It is a hit point function       */  \
	   data[1] amount             /* Amount of better strength       */  \
	   firstf  TIF_HIT_INC       \
	   tickf   TIF_NONE          \
	   lastf   TIF_HIT_DEC       \
	   applyf  APF_ABILITY;

	#define SPEED_TRANSFER(newspeed) \
	flags {UNIT_FL_MAGIC}       \
	affect                       \
	   id ID_TRANSFER_SPEED      \
	   duration -1                /* Must be permanent in the object */  \
	   data[0] newspeed          \
	   firstf  TIF_SPEED_BETTER  \
	   tickf   TIF_NONE          \
	   lastf   TIF_SPEED_WORSE   \
	   applyf  APF_SPEED;

	#define SLOW_TRANSFER(amount) \
	flags {UNIT_FL_MAGIC}         \
	affect                        \
	   id ID_TRANSFER_SPEED       \
	   duration -1                \
	   data[0] newspeed           \
	   firstf  TIF_SPEED_WORSE    \
	   tickf   TIF_NONE           \
	   lastf   TIF_SPEED_BETTER   \
	   applyf  APF_SPEED;
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-Appendices-Liquid-macros-file" title="Manual:Zone Manual/Appendices/Liquid macros file">Previous: Liquid macros file</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-Appendices-Skill-definitions-in-values.h" title="Manual:Zone Manual/Appendices/Skill definitions in values.h">Next: Skill definitions in values.h</a></div></div>