<div class="mw-parser-output"><p><br />
<span id="bpatt_s"></span>
</p>
<pre>integer attack_spell( n&#160;: integer, caster&#160;: unitptr, medium&#160;: unitptr,
                      target&#160;: unitptr, bonus&#160;: integer)
   Returns&#160;: The amount of damage given.
   n&#160;: The spell index of the offensive spell (SPL_XXX)
   caster&#160;: The caster of the spell.
   medium&#160;: The medium, with which the spell is cast, might be caster.
   target&#160;: The target of the spell.
   bonus  : Possible (+) advantage or (-) penalty.
</pre>
<pre>   This is low-level internal spell stuff used to develop new spells. Do not
   use unless you know what you are doing and have been allowed to do so by
   your Admin.
</pre></div>