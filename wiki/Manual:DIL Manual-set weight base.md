<div class="mw-parser-output"><h1><span id="set_weight_base(_u_:_unitptr,_lbs_:_integer_)"></span><span class="mw-headline" id="set_weight_base.28_u_:_unitptr.2C_lbs_:_integer_.29">set_weight_base( u&#160;: unitptr, lbs&#160;: integer )</span></h1>
<p><b> Parameters </b>
</p>
<pre> u&#160;: the unit on which you wish to alter the weight.
 lbs&#160;: the new base weight in lbs (½ kg)
</pre>
<p><b> Description </b>
Use this procedure to set a unit's base weight. This function will
ensure the base-weight is set to the new value. To ensure weight 
consistency this procedure also adjusts the weight of all units outside
the altered unit.
</p><p>See also:
</p>
<pre> &gt; <a href="./Manual:DIL-Manual-set-weight" title="Manual:DIL Manual/set weight">set_weight()</a>
</pre></div>