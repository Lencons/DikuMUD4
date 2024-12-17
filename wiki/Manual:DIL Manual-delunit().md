<div class="mw-parser-output"><p><br />
<span id="bfdelunit"></span>
</p>
<pre><b>Function:</b>  <i>integer delunit( filename&#160;: string )&#160;;</i>
</pre>
<pre>  <b>filename</b>
         The name of the Unit file to be deleted.
  <b>Return</b>
         Returns an integer TRUE if deleted FALSE if not delunit is used to delete files that are used with the 'Restore' and 'store' functions.
</pre>
<pre><b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin chest_del ("arg&#160;: string /*filename to be deleted*/);
var
        ret:integer;/*to hold the return value if deleted or not*/
code
{
ret:= delstr("chest.file");
if (!ret)
        {
        log ("File not deleted.");
        quit;
        }
</pre></i><i><pre>sendtext("Chest file deleted[&amp;]n",self);
quit;/*dil delete routine done
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also</b>
<a href="#bfrestore">Restore a Unit from a Unit file</a> and
<a href="#bpstore">Store Units to a Unit file</a>.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>