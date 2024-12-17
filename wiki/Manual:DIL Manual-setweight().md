<div class="mw-parser-output"><h1><span id="setweight(_u_:_unitptr,_i_:_integer_)"></span><span class="mw-headline" id="setweight.28_u_:_unitptr.2C_i_:_integer_.29">setweight( u&#160;: unitptr, i&#160;: integer )</span></h1>
<p>OBSOLETE.
</p><p>Superseeded by
</p>
<pre> set_weight_base
 set_weight
</pre>
<p><b> Parameters </b>
</p>
<pre> u&#160;: the unit on which you wish to alter the weight.
 i&#160;: the new total weight
</pre>
<p><b> Description </b>
Use this procedure on for example drink-containers if you wish to
remove or add some liquid. This function will ensure the base-weight
is unchanged, and that the weight of the unit is altered according to
the integer i (positive or negative). To ensure weight consistency this
procedure also adjusts the weight of all units outside the altered unit.
</p><p>For example in this hierarchy
</p>
<pre> room
   npc
   pc
     bottle (b:1)
</pre>
<p>Setting the bottle to 5 will add 4 liquid weight to the bottle and
keep the base weight at 1. The pc and the room as well (npc remains unchanged)
</p><p>IMPORTANT: Code review needed here. It looks like its a mess and we need one
function to change the base weight, and one function to change the contents
weight (e.g. adding liquids to a bottle).
</p></div>