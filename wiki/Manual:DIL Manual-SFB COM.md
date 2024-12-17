<div class="mw-parser-output"><h1><span class="mw-headline" id="SFB_COM">SFB_COM</span></h1>
<p>SFB_COM is a combat message that is sent during combat.
</p><p>When this flag is used in a wait() statement, it will trigger on combat messages.
The unit containing the DIL program needs not be involved in the combat itself,
it will react to any combat in it's local environment. The combat message is sent
just prior to the hit.
</p><p>Only the following global value is set in a SFB_COM combat message:
</p>
<pre> 'activator'&#160;: is a unitptr to the PC/NPC about to hit someone else.
</pre>
<p>Note that:
</p>
<pre> command(CMD_AUTO_COMBAT) 
</pre>
<p>will evaluate to TRUE.
</p><p>Example:
</p>
<pre> wait(SFB_COM, activator == self);
</pre>
<p>Example:
</p>
<pre> wait(SFB_COM, activator == self.fighting);
</pre>
<p>Example:
</p>
<pre> wait(SFB_ALL, TRUE);
 if (command(CMD_AUTO_COMBAT))
   exec("flee", self);
</pre>
<p>You may want to take a look at the DIL vorpalweapon() in one of the distribution zones.
</p><p>See also:
</p>
<pre> &gt; wait
 &gt; SFB_PRE
 &gt; CMD_AUTO_DAMAGE
</pre></div>