<div class="mw-parser-output"><p><br />
<span id="bpsendto"></span>
</p>
<pre>sendto ( s&#160;: string , u&#160;: unitptr )
   s&#160;: Message to send.
   u&#160;: Unit to send it to.
   result: The message is passed to all DIL programs in unit, matching the
           message class SFB_MSG. The message is not
           received by those DIL programs in the local environment that is
           not set up to wait for that message class.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>