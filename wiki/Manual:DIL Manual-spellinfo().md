<div class="mw-parser-output"><p><br />
<span id="bfsplinf"></span>
</p>
<pre>string spellinfo(idx&#160;: integer, i1&#160;: integer, i2&#160;: integer, i3&#160;: integer,
                 i4&#160;: integer, i5&#160;: integer, i6&#160;: integer, i7&#160;: integer, )
</pre>
<pre>    idx&#160;: The spell index (SPL_XXX). You might want to use spellindex
          to find this value.
</pre>
<pre>    Returns:
      The full name of the spell, or the empty string if no such spell.
</pre>
<pre>    All the integer parameters are set to the following values:
      i1  : Spell realm (MAG / DIC)
      i2  : Spell sphere (SPL_XXX)
      i3  : Mana usage
      i4  : 0 if a non-offensive spell, non-zero otherwise
      i5  : Resistance required (SPLCST_XXX)
      i6  : Mediums (MEDIA_XXX)
      i7  : Targets (FIND_UNIT_XXX &amp; TAR_XXX)
</pre>
<pre>  Example:
    s&#160;:= "cu li wo"; /* cure light wounds */
    i&#160;:= spellindex(s);
    s&#160;:= spellinfo(i, i1, i2, i3, i4, i5, i6, i7);
    /* s &amp; i1 - i7 now set */
</pre></div>