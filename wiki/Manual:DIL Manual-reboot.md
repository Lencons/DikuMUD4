<div class="mw-parser-output"><p><br />
<span id="bpreboot"></span>
</p>
<pre><b>Function:  </b><i>reboot&#160;;</i>
This function works like a quit command.  Anything after the reboot function in a Dil will not be
executed the mud will reboot instantly.  The zone must have root privileges in
the zonelist in order to use this function.
<b>Simple reboot command</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin cmd_reboot (arg:string);
code
{
sendtext ("Rebooting the mud.&amp;n",self);
reboot;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre></div>