<div class="mw-parser-output"><p><br />
<span id="bpp_u"></span>
</p>
<pre>position_update ( u&#160;: unitptr )
   u&#160;: A pointer to a player or a monster. The character will be
       updated and perhaps killed, incapacitated, mortally
       wounded, revived, etc. depending on current hitpoints.
       Useful when tampering with the 'hp' field. Example:
</pre>
<pre>       pc.hp&#160;:= pc.hp - 100;
       position_update(pc);
</pre></div>