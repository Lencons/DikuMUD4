<div class="mw-parser-output"><p><br />
<span id="sfbcmd"></span>
</p>
<pre>SFB_CMD            Command message
</pre>
<pre>  When this flag is set, the program gets activated by all commands (legal
  or illegal) issued by PC's or NPC's. Moving around is also considered a
  command.
</pre>
<pre>  Assume a janitor executes the command '
  Ge all from corpse',
  And Ge interprets to 'get'
</pre>
<pre>  then this will occur in the DIL program:
</pre>
<pre>     'activator'... is a unitptr to the janitor.
     'cmdstr'...... is a string which contains 'get'
     'excmdstr'...... is a string which contains 'ge'
     'excmdstr_case'...... is a string which contains 'Ge'
     'argument'.... will contain 'all from corpse'
</pre>
<pre>     command(CMD_GET) will evaluate to TRUE.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>