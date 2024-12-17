<div class="mw-parser-output"><p><br />
<span id="eptr"></span>
</p>
<pre><b>Extraptr:</b>
</pre>
<pre>  Extra descriptions, quests structures, etc can be searched and manipulated
using variables of this type. There is no way to declare static structures of
this type in DIL programs. Lists of extra descriptions are easily searched with
the 'in' operator (See below).  Extraptr variables are 'volatile', and thus
cleared whenever there is a possibility that they are rendered unusable.
</pre>
<p>Members:
</p>
<table class="wikitable">

<tbody><tr>
<th>member</th>
<th>type</th>
<th>description
</th></tr>
<tr>
<td>next</td>
<td>extraptr</td>
<td>Points to the next linked extra description. NULL if none
</td></tr>
<tr>
<td>names</td>
<td><a href="./Manual:DIL-Manual-stringlist" title="Manual:DIL Manual/stringlist">stringlist</a></td>
<td>Array of names on the extra description. NULL if none
</td></tr>
<tr>
<td>vals</td>
<td><a href="./Manual:DIL-Manual-integerlist" title="Manual:DIL Manual/integerlist">intlist</a></td>
<td>Array of integers on the extra description. NULL if none
</td></tr>
<tr>
<td>descr</td>
<td><a href="./Manual:DIL-Manual-string" title="Manual:DIL Manual/string">string</a></td>
<td>string of text
</td></tr></tbody></table></div>