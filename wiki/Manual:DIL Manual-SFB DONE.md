<div class="mw-parser-output"><p><br />
<span id="sfbdone"></span>
</p>
<pre>SFB_DONE           'Command has now been executed' message
</pre>
<pre>  When this flag is set, the program gets activated by all successful commands
  issued by PC's or NPC's. The 'activator', 'medium' and 'target' special
  values are used as follows:
</pre>
<pre>     'activator'... The PC / NPC which executed the command
     'medium'...... The unit which is operated upon.
     'target'...... The target of the operation.
</pre>
<pre>  For example, assume the player John gives a garlic to Mary the Lumberjack
  wife. The following values are set:
</pre>
<pre>     activator == John (unitptr)
     medium    == Mushroom (unitptr)
     target    == Mary (unitptr)
</pre>
<pre>  command(CMD_GIVE) will evaluate to true.
</pre>
<pre>  You thus know that Mary has in fact received the mushroom. It is NOT possible
  to block (using the 'block' command) these commands since they have already
  been executed at the time of notification.  In a 'get' command, medium would
  be a unitptr to where the unit was taken from, and target would be the object
  which was taken.
</pre>
<pre>  See the file commands.txt for a description of how the arguments are set for
  each command. If you can not find a command in there, just ask to get it
  implemented. Especially you should pay attention to the non-obvious SFB_DONE
  command(CMD_AUTO_ENTER).
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>