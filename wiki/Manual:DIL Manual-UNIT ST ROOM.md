<div class="mw-parser-output"><p><br />
<span id="uroom"></span>
</p>
<pre><b>if the type is UNIT_ST_ROOM</b>
</pre>
<pre>      Note: the descr fields of exits are available as standard extra
         keywords, ie. 'north' ,'east',...,'down'.
         Example:
           ex&#160;:= 'north' in self.extra;
</pre>
<pre>      'exit_names'[]  :stringlist (RW)
         The names matching the exit name 'open grate' The index should
         be one of NORTH EAST SOUTH WEST UP DOWN in values.h and/or vme.h
         Example:
           sl&#160;:= self.exit_names[SOUTH];
           act("The $2t slides open as you press the button.",
                A_ALWAYS, activator, sl.[0], null, TO_CHAR);
      'exit_info'[]  :integer (RW)
         Bits specifying the conditions of the exits, see EX_* in
         values.h and/or vme.h The index should be one of NORTH EAST SOUTH WEST
         UP DOWN in values.h and/or vme.h
      'exit_to'[]    :unitptr (RO)
         The unit, the direction exits to. The index should
         be one of NORTH EAST SOUTH WEST UP DOWN in values.h and/or vme.h
         You may not change the directions through DIL programs.
      'roomflags'    :integer (RW)
         Bits specifying properties of the room, see ROOM_FL_* in
         values.h and/or vme.h
      'movement'     :integer (RW)
         The type of movement in the room, see SECT_* in values.h and/or vme.h
</pre></div>