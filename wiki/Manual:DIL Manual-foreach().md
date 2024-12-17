<div class="mw-parser-output"><p><br />
<span id="forea"></span>
</p>
<pre><b>foreach:</b>
  Foreach is an easy way to process all the units in the
  local environment relative to the 'self' executing the
  foreach. Foreach takes care of creating a list of local
  units, and of securing them. You can use both break and
  continue in a foreach statement. The unit executing the
  foreach ('self') is always a part of the foreach.
</pre>
<pre>      It is important to understand that the units in the local
      environment are relative to the 'self' executing the foreach.
</pre>
<pre><b>Example:</b>
    This foreach is copied onto the spell caster, and hence all units
    relative to the spell caster (i.e. self) are processed in the foreach.
    Assume that it was executed on the spell caster's staff, then all units
    found would be relative to the staff, i.e. the spell caster's inventory.
</pre>
<pre>

 ...
    foreach (UNIT_ST_PC|UNIT_ST_NPC, u)
    {
       if (u.hp &lt; u.max_hp)
       {
          act("Warm raindrops fall upon you, cleaning your wounds.",
              A_ALWAYS, u, null, null, TO_CHAR);
          u.hp := u.hp + 6;
          if (u.hp &gt; u.max_hp)
            u.hp := u.max_hp;
       }
       else
         act("Warm raindrops fall upon you.",
             A_ALWAYS, u, null, null, TO_CHAR);
       pause;
    }
 ...
</pre></div>