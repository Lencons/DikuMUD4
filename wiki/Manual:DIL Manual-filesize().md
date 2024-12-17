<div class="mw-parser-output"><p><br />
<span id="bffilesize"></span>
</p>
<pre><b>Function:</b>  <i>integer filesize ( filename :string);</i>
</pre>
<pre>  <b>file</b>
         The file name you want to check
  <b>return</b>
         a file size in bites 0 if no file
</pre>
<p><br />
</p><p><br />
</p>
<pre>This function does exactly what it says it does it checks a files size.
</pre>
<pre><b>Example DIL:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin notebook ();
code
{
        ns&#160;:= filesize (self.name+"notebook");
        if ( ns &gt;500000)
        {
                sendtext ("Your notebook is full.&amp;n",self);
                quit;
        }
        else if ( ns &gt; 250000)
        {
                sendtext ("Your notebook is more than half full.&amp;n",self);
                quit;
        }
        else if (ns &gt;125000)
        {
                sendtext ("Your Notebook is only 1/4 full.&amp;n",self);
                quit;
        }
        else if (ns &gt;0)
        {
                sendtext ("Your notebook is less than 1/4 full.&amp;n",self);
                quit;
        }
        else
        {
                sendtext ("You don't have anything in your Notebook.&amp;n",self);
                quit;
        }
</pre></i><i><pre>}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
The previous DIL example shows how you could use the 'filesize' instruction to
check the size of a player stored notebook.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>