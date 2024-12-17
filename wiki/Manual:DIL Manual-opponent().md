<div class="mw-parser-output"><p><br />
<span id="bfop"></span>
</p>
<pre>integer opponent(u1&#160;: unitptr, u2&#160;: unitptr)
   u1, u2: Two characters
   return: TRUE if u1 is in combat with u2, FALSE otherwise.
   Example: if (opponent(self, victim)) ...
</pre>
<pre>   When in a combat, you are usually only melee-attacking one opponent,
   although you may have many other opponents. This function lets you
   check if you are directly / indirectly an opponent to another unit.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>