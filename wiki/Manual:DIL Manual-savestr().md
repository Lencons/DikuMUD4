<div class="mw-parser-output"><p><br />
<span id="bfsavestr"></span>
</p>
<pre><b>Function:</b>  <i>integer savestr( filename&#160;: string , buff&#160;: string , wa :string);</i>
</pre>
<pre>  <b>filename</b>
         The name of the String file to save the String to
  <b>buff</b>
         The String you wish to save into the file
  <b>wa</b>
         Write or append
  <b>Return</b>
         <i>FILE_SAVED, FILE_NOT_SAVED, FILE_NOT_CREATED, or FILE_ILEGAL_OPP</i>
</pre>
<pre>Savestr is used to save strings to disk to be loaded later by the 'load' function.
The 'savestr' and 'Loadstr' is perfect for operations such as
on-line edited newspaper, a lottery where the tickets are sold to players,
creating smarter NPC's that can remember through reboots who they are hunting,
Dil based teachers, message boards, mail system, news command., zone or
room based help,  competition boards, and much much more.
<b>Note:</b>The append/write argument must be in lower case and can only be a
'w' or a 'a' surrounded by '"'.  If the argument is a 'w' it will over write
any string file by that name.  If the argument is 'a' it will append to the
file by that name.
<b>Disk access is always slow</b>.
If you use loadstr on a continuous basis always
attempt to keep file sizes to a minimum for quick loading.  Otherwise you
might cause serious delays on the server.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin news_save (arg:string  /*for saving*/);
var
        ret:integer;/*to hold the return value if saved or not*/
code
{
ret:= savestr("news.txt",arg,"w");
if (!ret)
        {
        log ("File not wrote");
        quit;
        }
</pre></i><i><pre>sendtext("New news file wrote.[&amp;]n",self);
quit;/*dil save routine done destroy self.*/
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also</b> <i>
<a href="#bfdelstr">Delete a String file</a> and
<a href="#bfloadstr">Load a String file</a></i>
</pre></div>