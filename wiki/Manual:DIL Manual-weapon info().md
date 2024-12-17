<div class="mw-parser-output"><p><br />
<span id="bfweapon_info"></span>
</p>
<pre><b>Function:</b>  <i>intlist weapon_info( i&#160;: integer )&#160;;</i>
</pre>
<pre>  <b>i</b>
         Weapon to get the info of ass defined in 'values.h' and 'weapons.def'
  <b>returns</b>
         Intlist containing 4 values:
</pre>
<pre>  <b>0</b>
         Number of hands
  <b>1</b>
         weapon speed
  <b>2</b>
         weapon type
  <b>3</b>
         shield block value
</pre>
<p><br />
</p>
<pre>This function gives you access to the values in the weapons.def file.
With this things like 'wear' equipment' and 'look' are much easier to
write in Dil.
<b>Example</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilcopy id_weap (arg:string);
var
  i:integer;
  il:intlist;
code
{
il:=weapon_info(atoi(arg));
</pre></i><i><pre>if (il!=null)
{
sendtext ("Number of hands:  "+itoa(il.[0])+"&amp;n";
             sendtext ("Speed:  " +itoa(il.[1])+"&amp;n",self);
                         sendtext ("Type:  "+itoa(il.[0])+"&amp;n",self);
                         sendtext ("Shield value:  "+itoa(il.[0])+"&amp;n",self);
                         }
else
{
sendtext ("No such weapon.&amp;n",self);
}
</pre></i><i><pre>quit;
}
dilend
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre></div>