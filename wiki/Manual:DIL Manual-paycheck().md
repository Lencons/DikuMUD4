<div class="mw-parser-output"><p><br />
<span id="bfpaychk"></span>
</p>
<pre>integer paycheck( u1&#160;: unitptr, u2:unitptr)
   u1&#160;: unit to check against
   u2&#160;: player to check access for
   return: TRUE if the player u2 has pay access to the location
	in which the unit u1 is located. FALSE if the player does not
	have access. Using non-players as u2 will return TRUE. The
	function checks if the player has pay-access (if needed) to
	the zone in which u1 is located.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>