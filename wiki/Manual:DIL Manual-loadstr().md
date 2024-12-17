<div class="mw-parser-output"><p><br />
<span id="bfloadstr"></span>
</p>
<pre><b>Function:</b>
<i>integer loadstr( filename&#160;: string , buff&#160;: string );</i>
</pre>
<pre>  <b>filename</b>
         The name of the string file to be loaded
  <b>buff</b>
         The string that you wish to read the file contents into
  <b>Return</b>
         <i>FILE_LOADED, FILE_NOT_FOUND, FILE_OUT_OF_MEMORY,or FILE_TO_LARGE</i>
</pre>
<pre>Loadstr is used to load strings from disk that were saved either by savestr
or any text editor.
The 'loadstr' is perfect for operations such as
on-line edited newspaper, a lottery where the tickets are sold to players,
creating smarter NPC's that can remember through reboots who they are hunting,
Dil based teachers, message boards, mail system, news command., zone or
room based help,  competition boards, and much much more.
<b>Disk access is always slow</b>.
attempt to keep file sizes to a minimum for quick loading.  Otherwise you
might cause serious delays on the server.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin news_load ();
var
        ret:integer;/*to hold the return value if loaded or not*/
        buff:string;/*to hold the loaded string*/
code
{
ret:= loadstr("news.txt",buff);
if (!ret)
        {
        log ("File not read.");
        quit;
        }
</pre></i><i><pre>sendtext(buff+"[&amp;]n",self);
quit;/*dil load routine done destroy self.*/
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also</b> <i>
<a href="#bfdelstr">Delete a String file</a> and
<a href="#bfsavestr">Save String file</a></i>
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>