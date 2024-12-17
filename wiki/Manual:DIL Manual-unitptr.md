<div class="mw-parser-output"><h1><span class="mw-headline" id="unitptr">unitptr</span></h1>
<pre><b>The unitptr has the following fields:</b>
</pre>
<pre>   unitptr:
      'names'        :stringlist (RW)
         A list of names that matches the unit.
      'name'         :string (RW)
         The first name in the namelist in 'names'
      'outside_descr' :string (RW)
         The description of the unit from the 'outside'. f.inst.
         the description of a boat, seen from the outside.
      'inside_descr' :string (RW)
         The description of the unit from the 'inside'. f.inst.
         the description of a boat, seen from the inside.
      'next'         :unitptr (RO)
         The next unit in the local list of units. For instance, the
         units in the inventory of a PC, is linked with this field.
      'title'        :string (RW)
         The title of the unit.
      'extra'        :extraptr (RW)
         Extra descriptions of the unit (identify, look at, read etc.).
      'outside'      :unitptr (RO)
         The outside of the unit hierarchy (carried by, contained by).
         For instance, the contents of a bag have their 'outside'
         field pointing to the bag.
      'inside'       :unitptr (RO)
         The inside of the unit hierarchy (carry, contains).
         For instance the first unit in a PC's inventory is referenced
         by the 'inside' field.
      'key'       :string (RO)
         The key that will open this unitptr
         For instance "big_key@blackzon"
		          by the 'inside' field.
      'gnext'        :unitptr (RO)
         Next unit in the global list of units.
      'gprevious'    :unitptr (RO)
         Previous unit in the global list of units.
      'hasfunc'      :integer (RO)
         Returns TRUE if unit has special functions attached to it.
      'max_hp'       :integer (RO/RW)
         The maximum hitpoints of unit, RO for players, RW for mobiles.
      'max_mana'       :integer (RO)
         The maximum mana of the character (player or mobile).
      'max_endurance'  :integer (RO)
         The maximum endurance of the character (player or mobile).
      'lifespan'       :integer (RW)
         The lifespan of a character, write permission only on root access.
      'hp'           :integer (RW)
         The current hitpoints of unit. For objects, this can render
         it 'broken' by being set low. If an unit has -1 hitpoints
         its considered unbreakable.
      'manipulate'   :integer (RW)
         Bits that specify how unit can be handled, see MANIPULATE_*
         flags in values.h and/or vme.h
      'flags'        :integer (RW)
         Bits that specify different properties of a unit, see
         UNIT_FL_* in values.h and/or vme.h
      'baseweight'   :integer (RO)
         The empty weight of the unit. This can be set with the
         procedure 'setweight()'
      'weight'       :integer (RO)
         The current weight of the unit (and its contents).
      'capacity'     :integer (RW)
         The amount of weight the unit can contain.
      'height'       :integer (RW)
         The height of a PC/NPC, the length of a rope, the size of weapons,
         armours, and shields.
      'alignment'    :integer (RW)
         The alignment of the unit. [1000..-1000],
         1000 is good, 0 is neutral, -1000 is evil.
      'openflags'    :integer (RW)
         Bits thats specify how a unit may be opened, locked, etc,
         see EX_* in values.
      'light'        :integer (RO)
         How much light is inside the unit.
      'bright'       :integer (RO)
         How much the unit lights up. This can be set with the
         procedure 'setbright()'
      'illum'        :integer (RO)
         How much light units inside a transparent unit create
      'minv'         :integer (RW)
         The 'wizard invisibility' level.
      'spells'[]     :integer (RO)
         The defence/skill of the different spell spheres/spells
         The index should be one of the SPL_* in values.h and/or vme.h
      'zoneidx'      :string (RO)
         The unique database name (in the zone) for this unit.
      'nameidx'      :string (RO)
         The unique database zone name for this unit.
      'symname'      : string (RO)
         The concatenated nameidx@zoneidx to make it easier to use IRL
      'idx'      :integer (RO)
         Constant ID for players and for non-PCs it is the memory pointer
         converted to an integer. If there are 50 cityguards, you can use
         the idx to figure out which one you're looking for. Use 
         findsymbolic(#,#) to quickly find precisely a unit matching a 
         symbolic name and an idx. 
         Be warned, this value change between each reboot, except for players, so do not
         count on it for purposes of persistence across reboots.
      'zone'         :string (RO)
         The name of the zone the unit is in.
      'type'         :integer (RO)
         The type of the unit, see UNIT_ST_* in values.h and/or vme.h
      'loadcount'    :integer (RO)
         Returns the number of units loaded in the game
         of this definition (zoneidx,nameidx / idx)
</pre>
<h2><span class="mw-headline" id="Char">Char</span></h2>
<p>If the unitptr.type == UNIT_ST_PC or UNIT_ST_NPC then you can use these flags:
</p>
<pre>      'master'         :unitptr (RW)
         The unitptr to the master that this CHAR is following. See also <a href="./Manual:DIL-Manual-follow()" title="Manual:DIL Manual/follow()">follow()</a>
</pre>
<pre>      ... And a whole slew of other fields.
</pre></div>