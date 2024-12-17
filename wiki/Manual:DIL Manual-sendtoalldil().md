<div class="mw-parser-output"><p><br />
<span id="bpsendalld"></span>
</p>
<pre>sendtoalldil( m&#160;: string, s&#160;: string )
   m&#160;: Message to send.
   s&#160;: Name idx to a DIL program to send message to.
   result: Send a message to all DIL programs matching a given database name.
</pre>
<pre><b>Example:</b>
</pre>
<pre>   sendtoalldil ( "some message", "intercomm@cemetery");
</pre>
<pre>   The message "some message" is sent to all DIL program in the world
   matching the data base name "intercomm@cemetery".
   Like 'send()' and 'sendto()', the
   message received matches the SFB_MSG message class.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>