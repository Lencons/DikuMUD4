<div class="mw-parser-output"><p><br />
<span id="hb"></span>
</p>
<pre>'heartbeat'
   This is the DIL programs heartbeat. It can be assigned runtime to
   change the rate with which SFB_TICK is activated. Do not set it
   too low, and remember that it is specified in 1/4th of a second.
   use the constant PULSE_SEC to multiply your wanted delay, for
   Example:
      heartbeat&#160;:= PULSE_SEC*25; /* Tick every 25 seconds */
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>