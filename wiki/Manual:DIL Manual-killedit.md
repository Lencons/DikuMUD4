<div class="mw-parser-output"><p><br />
<span id="bpkilledit"></span>
</p>
<pre><b>Function:  </b><i>killedit&#160;;</i>
This function is used to kill the editor on a PC if it needs to
stop editing before the PC is done editing.  An example of when this is needed
is when a player is killed while editing or is transfered away from a place where he was editing.
You can let them finish but it may be wierd for a person to finish
posting in one room while in another.
<b>Example</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin editextra (arg:string);
code
{
interrupt (SFB_DEAD,self==activator,int_quit);
        beginedit (self);
        wait(SFB_EDIT,self==activator)&#160;;
        temp&#160;:= textformat(argument);
addextra (self.outside.extra ,{"graphitee"},temp);
quit;
:int_quit:
killedit;
quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>