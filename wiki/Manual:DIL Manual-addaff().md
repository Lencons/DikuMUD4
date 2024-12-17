<div class="mw-parser-output"><h1><span id="addaff(_u_:_unitptr,_id_:_integer,_duration_:_integer,_beat:_integer,_data0_:_integer,_data1:_integer,_data2:_integer,_tif_first_:_integer,_tif_tick_:_integer,_tif_last_:_integer,_apf_:_integer)"></span><span class="mw-headline" id="addaff.28_u_:_unitptr.2C_id_:_integer.2C_duration_:_integer.2C_beat:_integer.2C_data0_:_integer.2C_data1:_integer.2C_data2:_integer.2C_tif_first_:_integer.2C_tif_tick_:_integer.2C_tif_last_:_integer.2C_apf_:_integer.29">addaff( u&#160;: unitptr, id&#160;: integer, duration&#160;: integer, beat: integer, data0&#160;: integer, data1: integer, data2: integer, tif_first&#160;: integer, tif_tick&#160;: integer, tif_last&#160;: integer, apf&#160;: integer)</span></h1>
<pre> u  : Unit to add affect to.
 id&#160;: Affect id to add, see ID_* in values.h and/or vme.h
 duration&#160;: Number of triggers
 beat&#160;: How often the pulse runs (4 = 1 second)
 data0-2&#160;: Data values for the ID_
 tif  : The message ID 
 apf  : The modification function
 result: Adds affect 'id' at 'u' with first, tick, and last TIF_XXX's, etc.
</pre>
<p>See also:
</p>
<pre> &gt; <a href="./Manual:DIL-Manual-subaff()" title="Manual:DIL Manual/subaff()">subaff()</a>
 &gt; <a href="./Manual:DIL-Manual-isaff()" title="Manual:DIL Manual/isaff()">isaff()</a>
 &gt; <a href="./Manual:DIL-Manual-getaffects()" title="Manual:DIL Manual/getaffects()">getaffects()</a>
</pre></div>