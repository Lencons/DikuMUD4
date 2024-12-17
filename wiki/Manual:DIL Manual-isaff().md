<div class="mw-parser-output"><h1><span id="integer_isaff_(_u_:_unitptr_,_i_:_integer_)"></span><span class="mw-headline" id="integer_isaff_.28_u_:_unitptr_.2C_i_:_integer_.29">integer isaff ( u&#160;: unitptr , i&#160;: integer )</span></h1>
<pre> u&#160;: A unit to be examined.
 i&#160;: An id of an affect, see ID_* in values.h and/or vme.h
 result: TRUE, if unit 'u' is affected by affect id 'i'
</pre>
<p><b>Examples:</b>
</p>
<pre> if (isaff(self, ID_BLIND_CHAR))
   sendtext("You're blinded", self);
</pre>
<p>This command scans the unit 'u' for any affect matching the id 'i'
and returns TRUE if one is found.
</p><p>See also:
</p>
<pre> &gt; <a href="./Manual:DIL-Manual-subaff()" title="Manual:DIL Manual/subaff()">subaff()</a>
 &gt; <a href="./Manual:DIL-Manual-addaff()" title="Manual:DIL Manual/addaff()">addaff()</a>
 &gt; <a href="./Manual:DIL-Manual-getaffects()" title="Manual:DIL Manual/getaffects()">getaffects()</a>
</pre></div>