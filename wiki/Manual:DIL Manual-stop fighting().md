<div class="mw-parser-output"><p><br />
<span id="bpstopfighting"></span>
</p>
<pre><b>Function:</b>  <i>stop_fighting( ch: unitptr, vict&#160;: unitptr )&#160;;</i>
</pre>
<pre>  <b>ch</b>
         unitptr - person you are stoping the fighting for
  <b>vict</b>
         unitptr - person you are removing from the fighting or null for everyone
</pre>
<pre>This function can be used to cancel combat in a room or with two people.
The following example copied to a player will stop any fight the player is in.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin stop_combat();
code
{
stop_fighting(self,null);
quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>