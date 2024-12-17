<div class="mw-parser-output"><p><br />
<span id="bpchngs"></span>
</p>
<pre>change_speed( u&#160;: unitptr, i&#160;: integer )
  u&#160;: the unit on which you wish to alter the current combat speed.
  i&#160;: the amount to add to the speed.
</pre>
<pre>  Beware, this is not the 'speed' as in the speed field, rather this is
  the speed which is calculated during combat. It is used for spells like
  'stun' which effectively puts the character out of combat for one
  round. Such a spell would be implemented like:
</pre>
<pre>   change_speed(u, 12)
</pre>
<pre>  and would only cause any effect if 'u' was fighting already (if not,
  use setfighting).
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>