<div class="mw-parser-output"><p><br />
<span id="cptr"></span>
</p>
<pre><b>Type:  </b><i>cmdptr</i>
<b>cmdptr fields</b>
</pre>
<p><br />
</p>
<pre><b>name</b>
            string - command name
<b>type</b>
            integer - command type like social or skill or just command
<b>level</b>
            integer - minimum level to use command
<b>loglevel</b>
            integer - level of character that can see the log 0 for no logs
<b>position</b>
            integer - minimum position to use command
<b>next</b>
            cmdptr - pointer to the next cmdptr
<b>previous</b>
            cmdptr - pointer to the previous cmdptr
</pre>
<p><br />
</p>
<pre>  The cmdptr can be used to search the command list or display all the commands.
I0t is also now possible to sort the commands by type by defining your own command
types and using the type field to sort on.
</pre>
<pre>  In order to get the first command in the list you use the following function:
<b>Function:  </b><i>chead();</i>
If you want to get a specific command then you use the following function:
<b>Function:  </b><i>cmdptr&#160;:= getcommand (s&#160;: string );</i>
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin cmdtst(arg&#160;: string);
var
  cmd&#160;: cmdptr;
  st&#160;: string;
</pre></i><i><pre>code
{
   cmd&#160;:= chead();
</pre></i><i><pre>	  while (cmd)
        {
        st&#160;:= cmd.name + " " + itoa(cmd.level) + " " + itoa(cmd.type) + " " +
        itoa(cmd.loglevel) + " " + itoa(cmd.position);
        act("CMD: $2t", A_ALWAYS, self, st, null, TO_CHAR);
        cmd&#160;:= cmd.next;
        }
</pre></i><i><pre>        cmd:=getcommand("kick");
        sendtext ("You must be "+itoa(cmd.level+" to use kick&amp;n",self);
</pre></i><i><pre>           quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>