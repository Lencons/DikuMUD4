<div class="mw-parser-output"><p><br />
<span id="sfbdead"></span>
</p>
<pre>SFB_DEAD           Death message
</pre>
<pre>  When this flag is set, the routine gets activated when a PC or NPC dies:
</pre>
<pre>     'activator'... will point to the PC/NPC that is about to die.
     'argument'.... is empty.
</pre>
<pre>      command(CMD_AUTO_DEATH) will evaluate to TRUE
</pre>
<pre>  The SFB_DEAD message is sent, just as the character dies, while his items are
  still equipped, just before the corpse is created.  The character's '.fighting'
  field points to his primary opponent, although this person does not necessarily
  have to be the one that killed him.
</pre>
<pre>  This can be exploited by making items wiz invisible (the .minv field) just as
  the message is received, causing them to stay inside the player rather than
  being transferred to the corpse. This does both give the ultimate crash
  protection, as well as a means of letting items, such as bribe items, forever
  be a part of the player (remember to make it un-wizinvis when the player
  returns from heaven - players should not have access to items while in heaven).
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>