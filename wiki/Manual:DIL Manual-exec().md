<div class="mw-parser-output"><p><br />
<span id="bpexec"></span>
</p>
<pre>exec ( s&#160;: string , u&#160;: unitptr )
   s&#160;: Command and arguments to perform.
   u&#160;: Unit to perform command.
   result: Unit (PC/NPC) executes command. The argument is treated just as
           if a normal PC entered a command at the command prompt in the
           game. It is not directly possible to detect whether the command
           was a success or fail. For example, you might force a PC to
           "get key". If there is no 'key' available, the PC will get
           notified the normal way. Plenty of examples are given above.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>