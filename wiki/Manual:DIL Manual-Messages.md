<div class="mw-parser-output"><p><br />
<span id="messies"></span>
</p>
 <h3><span class="mw-headline" id="Messages:">Messages:</span></h3>
<pre>  In DIL, a program attached to a unit gets activated when the program receives
a message. In order to save CPU usage, there are a number of different message
categories which can cause activation of a program.  The 'wait()' commands first
parameter is an integer, telling what message categories the program should
reactivate on.  The second parameter is an expression, which also must evaluate
to TRUE. 'pause' is just special instances of the 'wait()' command.
</pre>
<p><br />
</p>
<pre><strong>Caveat Builder: </strong>
</pre>
<pre>  Whenever you construct the arguments for the wait command, bear in mind that
ALL your tests will be executed EVERYTIME a message of the relevant kind comes
through.  Thus you should keep the length of the activation expression to a
reasonable minimum, and you should NEVER use the time-consuming findxxx-functions.
</pre>
<pre>Valid example (That prohibits a player from removing an object):
</pre>
<pre>:glue:
</pre>
<p><br />
</p>
<pre>	wait(SFB_CMD,command(CMD_REMOVE));
	u&#160;:= findunit(activator,argument,FIND_UNIT_IN_ME,null );
	if (u&#160;!= self)
	 {
		goto glue;
	 }
	act("You can't remove $2n, it's sticky.",
	   A_SOMEONE,activator,self,null,TO_CHAR););
	block;
	goto glue;
</pre>
<pre><b>See Also:</b>
<a href="#findunit.html">Dil and Findunit()</a>
</pre>
<pre>The message categories are as follows:
---~---~---~---~---~---~---~---~---
</pre></div>