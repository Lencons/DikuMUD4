<div class="mw-parser-output"><h1><span id="stringlist_getaffects(u_:_unitptr)"></span><span class="mw-headline" id="stringlist_getaffects.28u_:_unitptr.29">stringlist getaffects(u&#160;: unitptr)</span></h1>
<pre> u&#160;: The unit to scan for affects
 result&#160;: Returns stringlist of affects as described below.
</pre>
<p><b>Example</b>:
</p>
<pre> sl&#160;:= getaffects(self);
</pre>
<p>For each affect on a unit, two strings are added to the stringlist.
The first string is the description of what gets modified, e.g. an 
ability. The second string contains the three data value data0,data1
and data2, as well as the duration left.
</p><p>Could look like this:
</p>
<pre> {"Ability Adjustment", "6,6,0,-1",
  "Weapon adjustment", "12,14,0,-1"}
</pre>
<p>Use the <a href="./Manual:DIL-Manual-split()" title="Manual:DIL Manual/split()">split()</a> command to separate the numerical values.
</p><p><br />
See also:
</p>
<pre> &gt; <a href="./Manual:DIL-Manual-isaff()" title="Manual:DIL Manual/isaff()">isaff()</a>
 &gt; <a href="./Manual:DIL-Manual-addaff()" title="Manual:DIL Manual/addaff()">addaff()</a>
 &gt; <a class="mw-selflink selflink">getaffects()</a>
</pre></div>