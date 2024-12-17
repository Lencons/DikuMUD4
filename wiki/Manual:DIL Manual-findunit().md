<div class="mw-parser-output"><p><br />
<span id="bffindu"></span>
</p>
<pre>unitptr findunit ( u&#160;: unitptr , s&#160;: string , i&#160;: integer , l&#160;: unitptr )
     u&#160;: The unit the local environment is relative to.
     s&#160;: A string with name of the unit to find.
     i&#160;: The environment, where to look for it, see FIND_UNIT_*
         in values.h and/or vme.h.
     l&#160;: An optional list of units to search.
 return: If the unit is found, the function returns that unit.
          Returns null if nothing found.
</pre>
<pre>  The first argument is typically the char that's looking for something,
  i.e. if Mary needs a spoon to stir the pot, she'll be the first argument.
</pre>
<pre>  The second argument is what you're looking for, represented by a string.
  In the above mentioned example, that'd be "spoon".
</pre>
<pre>  For the second or third argument, you have a choice, as you'll only need to
  use one of them, and let the other be 0 or null.  For instance, if you have
  a pointer to Mary's kitchen utensil pot, you can use the line:
</pre>
<pre>     findunit(mary, "spoon", 0, pot);
</pre>
<pre>  Or you can just let her look around for it with:
</pre>
<pre>     findunit(mary, "spoon", FIND_UNIT_INVEN or FIND_UNIT_SURRO, null);
</pre>
<pre>  You can use all the FIND_UNIT_ values defined in values.h and/or vme.h, if you
  want to look for something for example within the zone (FIND_UNIT_ZONE), the
  entire world (FIND_UNIT_WORLD) (you rarely need to do that, it's mainly for
  tell etc.), or just the inventory or equipment of the char in question
  (FIND_UNIT_INVEN and FIND_UNIT_EQUIP).  Finally, as in the example above,
  you can look in the room of the char (FIND_UNIT_SURRO).
</pre>
<pre>  Using FIND_UNIT_PAY or FIND_UNIT_NOPAY in this function will be ignored.
</pre>
<pre>The flags for findunit, intuitively:
</pre>
<p><br />
</p>
<pre>FIND_UNIT_EQUIP:
  The objects you will see with `equipment'
  Assumes first argument to findunit is a char.
</pre>
<p><br />
</p>
<pre>FIND_UNIT_INVEN:
  The objects you will see with `inventory' or `look in bag'
</pre>
<p><br />
</p>
<pre>FIND_UNIT_SURRO:
  The objects you can see, and get with `get',
  or the characters you can `poke'&#160;:-)
</pre>
<p><br />
</p>
<pre>FIND_UNIT_ZONE:
  As FIND_UNIT_WORLD, only more local.
</pre>
<p><br />
</p>
<pre>FIND_UNIT_WORLD:
  Any object in the entire world.  Does NOT start looking close to the
  object of findunit's first argument, but rather somewhat randomly.
</pre>
<p><br />
</p>
<pre>On top of these, the following (new) values are defined:
</pre>
<p><br />
</p>
<pre>FIND_UNIT_IN_ME:
  Anything inside of the object of the first argument.
</pre>
<p><br />
</p>
<pre>FIND_UNIT_HERE:
  Anything `here', i.e. in object or around it (same as IN_ME + SURRO)
</pre>
<p><br />
</p>
<pre>FIND_UNIT_GLOBAL:
  ANYTHING, starting close to object and working out.
</pre>
<p><br />
</p><p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>