<div class="mw-parser-output"><p><br />
<span id="bpsendall"></span>
</p>
<pre>sendtoall( m&#160;: string, s&#160;: string )
   m&#160;: Message to send.
   s&#160;: Name idx to send message to.
   result: Send a message to all units matching a given database name.
</pre>
<pre><b>Example:</b>
</pre>
<pre>   sendtoall ( "some message", "rabbit@haon-dor");
</pre>
<pre>   The message "some message" is sent to all units in the world matching the
   data base name "rabbit@haon-dor". Like 'send()' and 'sendto()', the
   message received matches the SFB_MSG message class.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>