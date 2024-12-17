<div class="mw-parser-output"><p><br />
<span id="upcnpc"></span>
</p>
<pre><b>if the type is UNIT_ST_PC or UNIT_ST_NPC </b>
</pre>
<pre>      'speed'        :integer (RO)
         The current default combat-speed (as seen by wstat)
      'fighting'     :unitptr (RO)
         The unit the PC/NPC is fighting.
      'master'       :unitptr (RO)
         The unit the PC/NPC is following.
      'follower'     :unitptr (RO)
         The first follower of a PC/NPC. There is currently no way
         of finding other followers, except using a foreach loop in
         the local environment.
      'exp'          :integer (RO)
         The number of experience points for PC, or experience
         quality of monster. The exp can be set by the function
         'experience()'
      'charflags'     :integer (RW)
         Bits specifying by spells affects and other PC/NPC affects,
         and many other things, see CHAR_* in values.h and/or vme.h
      'lastroom'     :unitptr (RO)
         The room the player just left.
      'mana'         :integer (RW)
         The amount of mana a PC/CHAR has left.
      'dex_red'      :integer (RO)
         The amount of DEX reduction the PC/NPC suffers due to
         encumbrance or otherwise.
      'endurance'    :integer (RW)
         The amount of endurance a PC/NPC has left.
      'attack_type'  :integer (RW)
         The non-weapon attack type of a PC/NPC.
      'race'         :integer (RW)
         The race of a PC/NPC, see RACE_* in values.h and/or vme.h
      'sex'          :integer (RW)
         The sex of a PC/NPC, see SEX_* in values.h and/or vme.h
      'level'        :integer (RO)
         The level of a PC/NPC.
      'position'     :integer (RW)
         The position of a PC/NPC, see POSITION_* in values.h and/or vme.h
         affected by the 'position_update()' procedure
      'abilities'[]  :integer (RO)
         The abilities of a PC/NPC. Index should be ABIL_* in values.h and/or vme.h
      'weapons'[]    :integer (RO)
         The weapon skills of a PC/NPC. Index should be WPN_* in values.h and/or vme.h
      'opponentcount' :integer (RO)
         The number of opponents the player is fighting.
</pre></div>