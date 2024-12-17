<div class="mw-parser-output"><p><br />
<span id="bforoll"></span>
</p>
<pre>integer openroll( dice&#160;: integer , end&#160;: integer )
   dice&#160;: The size of the dice being rolled.
   end  : The margin for the open-ended roll.
   return: A random integer in approximately +/- 2^31 in worst case.
   Example: i&#160;:= openroll(100,5); The "100" roll continues on values
            96 - 100 and on values 1 - 5.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>