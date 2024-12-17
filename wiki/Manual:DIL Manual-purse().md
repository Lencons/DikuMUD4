<div class="mw-parser-output"><p><br />
<span id="bfpurse"></span>
</p>
<pre>integer purse(u&#160;: unitptr, coinage&#160;: integer)
   u&#160;: The unit to check
   coinage: The money type (e.g. gold, silver), one of IRON_PIECE, etc.
   Returns: The number of such units found.
   Example: if (purse(self, PLATINUM_PIECE) &gt; 10)
              exec("say I am loaded with platinum!", self);
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>