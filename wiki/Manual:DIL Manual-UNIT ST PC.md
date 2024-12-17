<div class="mw-parser-output"><p><br />
<span id="upc"></span>
</p>
<pre><b>if the type is UNIT_ST_PC</b>
</pre>
<pre>      'birth'         :integer (RO)
         The time a PC was created.
	  'editing'         :integer (RO)
	     Is the PC editing?  TRUE for yes FALSE for no.
      'hometown'      :integer (RO)
         The hometown of a PC.
      'pcflags'       :integer (RW)
         The setup of player options. See PC_* in values.h and/or vme.h
      'playtime'      :integer (RO)
         The time a PC has played.
      'skill_points'   :integer (RW)
         The amount of unused skill points the PC has.
      'ability_points' :integer (RW)
         The amount of unused ability points the PC has.
	        'exptol' :integer (RW)
         The amount of experience player needs to level
      'skills'[]     :integer (RO)
         The skills of a PC. Index should be SKI_* in values.h and/or vme.h
      'guild'        :string (RW)
         The guild the PC belongs to.
      'prompt'        :string (RW)
         The players prompt string..
      'crimes'       :integer (RW)
         The number of crimes the PC has.
      'full'         :integer (RW)
         How hungry the PC is.
      'thirst'       :integer (RW)
         How thirsty the PC is.
      'drunk'        :integer (RW)
         How drunk the PC is.
      'quests'       :extraptr (RW)
         The quests a PC is finishing/has finished.
      'info'         :extraptr (RW)
         The info structure of a PC.
      'acc_balance'  : integer (RO)
         If the game is in accounting mode, then this returns the balance
         of the player, what would be shown on balance in wstat &lt;player&gt; acc.
      'acc_total'  : integer (RO)
         If the game is in accounting mode, then this returns the total
         credit of the player, what would be shown on total in wstat
         &amp;ltplayer&amp;gt acc.
</pre></div>