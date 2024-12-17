<div class="mw-parser-output"><p><br />
<span id="bfsend_pre"></span>
</p>
<pre><b>Function:</b>send_pre( c&#160;: string, a :unitptr, m&#160;: unitptr, t :unitptr, p&#160;: integer, arg&#160;: string, o&#160;: unitptr);
</pre>
<pre>  <b>c</b>
         the command string that is sending the message
  <b>a</b>
         the unitptr (activator) that activated the message
  <b>m</b>
         the unitptr (medium) that the Dil is acting through
  <b>t</b>
         the unitptr (target) the Dil is acting on
  <b>p</b>
         the power of the message
  <b>arg</b>
         the argument sent with the message
  <b>o</b>
         the unitptr (other) you also want the message to go to
</pre>
<p><br />
</p>
<pre>New Function send_pre() takes same arguments as send_done but returns either
 SFR_SHARE or SFR_BLOCK.
If the command is blocked by another special or dil, then SFB_BLOCK will be returned,
 and you should quit your dil.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin cmdtst(arg&#160;: string);
var
  i&#160;: integer;
code
{
   i:=send_pre("cmdtest",self,null,null,0,argument,null);
</pre></i><i><pre>if (i == SFR_BLOCK)
  quit;
</pre></i><i><pre>          sendtext ("No one blocked me!&amp;n",self);
          quit;
          }
          dilend
</pre></i><i><p><br />
</p></i><i><pre>dilbegin pretest();
code
{
   :loop:
   wait(SFB_PRE, command("cmdtest"));
   block;
        act("hahahaha I blocked your cmdtest command",
       A_SOMEONE, activator, medium, null, TO_ALL);
        goto loop;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>