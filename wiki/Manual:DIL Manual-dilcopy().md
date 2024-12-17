<div class="mw-parser-output"><h1><span id="dilcopy(_s_:_string,_u_:_unitptr_)"></span><span class="mw-headline" id="dilcopy.28_s_:_string.2C_u_:_unitptr_.29">dilcopy( s&#160;: string, u&#160;: unitptr )</span></h1>
<pre>   s&#160;: Name template to attach to unit.
   u&#160;: Unit to attach a dil program to.
   result: Attaches a DIL program to a unit 'u', which uses a template named by 's'.
</pre>
<p>Examples:
</p>
<pre>  dilcopy("master_servant@spells()", u);
  dilcopy("spl_sleep@spells(7)", tgt);
  dilcopy("sendmsg@spells(teleport)", targ);
</pre></div>