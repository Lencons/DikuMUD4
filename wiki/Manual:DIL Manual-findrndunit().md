<div class="mw-parser-output"><p><br />
<span id="bffindru"></span>
</p>
<pre>unitptr findrndunit( u&#160;: unitptr, sv&#160;: integer, uf&#160;: integer)
   Returns: A pointer to a random unit, or null
   u  : The unit pointer which the search is relative to.
   sv&#160;: The search-location, a value (not bit vector) of FIND_UNIT_XXX
   uf&#160;: Bit vector. The unit flags which can match of UNIT_ST_XXX
</pre>
<pre>   Example: u&#160;:= findrndunit(self, FIND_UNIT_ZONE, UNIT_ST_PC|UNIT_ST_NPC);
</pre>
<pre>   This routine returns a random unit. Notice how the 'uf' lets you
   specify exactly what unit types to look for. The 'sv' is not a
   bit vector, although FIND_UNIT_XXX is usually used as such. If
   you need to search multiple environments, then call the routine
   once for each.
</pre>
<pre>   Using FIND_UNIT_PAY or FIND_UNIT_NOPAY in this function will
   pick a random player which in addition to being in the search
   environment also is registered as valid payer (or not). Asking
   for a room would yield a random room registered to be accessible
   for paying players only (or not). Asking for objects would
   return no unit (null).
</pre></div>