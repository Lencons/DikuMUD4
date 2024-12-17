<div class="mw-parser-output"><p><br />
<span id="bfdelstr"></span>
</p>
<pre><b>Function:</b>  <i>integer delstr( filename&#160;: string )&#160;;</i>
</pre>
<pre>  <b>filename</b>
         The name of the String file to be deleted
  <b>Return</b>
         Returns an integer TRUE if deleted FALSE if not
</pre>
<pre>The delstr is used to delete files that are used with the 'loadstr' and
'savestr'       functions.  The delstr function will only delete files that
each individual Zone has access to which is set up in the Zonelist file in the
VME etc directory.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin news|del ("arg&#160;: string /*filename to be deleted);
var
        ret:integer;/*to hold the return value if deleted or not*/
code
{
ret:= delstr("news.txt");
if (!ret)
        {
        log ("File not deleted.");
        quit;
        }
</pre></i><i><pre>sendtext ("News file deleted[&amp;]n",self);
quit;/*dil delete routine done
}
dilend
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also</b> <i>
<a href="#bfloadstr">Load String file</a> and
<a href="#bfsavestr">Save String file</a></i>
</pre></div>