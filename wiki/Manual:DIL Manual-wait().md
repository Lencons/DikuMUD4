<div class="mw-parser-output"><p><br />
<span id="bpwait"></span>
</p>
<pre>wait ( i&#160;: integer , dilexp )
   i&#160;: Message class to accept, see SFB_* in values.h and/or vme.h
   dilexp&#160;: Expression that has to be TRUE or not null to accept message.
   result: Waits for a command, matching the flagset, and satisfies the
           expression. When using the 'wait()' command, the first argument
           is an integer, that tells what classes of messages to wait for.
           Each message class is represented by a bit named as described in
           the chapter on messages.
<b>Example:</b>
</pre>
<pre>   wait (SFB_TICK|SFB_MSG, TRUE)
   /* Will accept a message, either from another DIL program or a
      timer message. As the second argument is always TRUE, any
      such message will reactivate the DIL program.
    */
</pre>
<pre><b>Example:</b>
</pre>
<pre>  wait (SFB_CMD, command("transmutate"))
  /* waits for an command entered named 'transmutate'.
     Activates the DIL program, that then can block the command, or
     let it pass (and then let the game produce the normal error
     message for unknown commands).
  */
</pre></div>