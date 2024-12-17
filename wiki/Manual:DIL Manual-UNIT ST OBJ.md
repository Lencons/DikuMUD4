<div class="mw-parser-output"><p><br />
<span id="uobj"></span>
</p>
<pre><b>if the type is UNIT_ST_OBJ</b>
</pre>
<pre>      'objecttype'   :integer (RW)
         The type of an object, see ITEM_* in values.h and/or vme.h for types.
      'value'[]      :integer (RW)
         Values for an object. The meaning of the values differ
         from object type to object type. Index should be [0..4].
         These values are used differently for each object type.
      'objectflags'  :integer (RW)
         Bits specifying special properties for an object. Some
         combinations may not be logical, see OBJ_* in values.h and/or vme.h
      'cost'         :integer (RW)
         The basic cost of an object. (old gold value)
      'rent'         :integer (RW)
         The basic cost of renting an object. Mostly used on very
         special objects. (old gold value)
      'equip'        :integer (RO)
         The position in equipment. This is used by units in a PC/NPC's
         inventory to tell if they are equipped by that PC/NPC.
         use the 'addequip()' and 'unequip()' procedures.
</pre></div>