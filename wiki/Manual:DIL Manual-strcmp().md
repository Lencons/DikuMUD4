<div class="mw-parser-output"><p><br />
<span id="bfstrcmp"></span>
</p>
<pre><b>Function:</b>  <i>integer strcmp( s1:string, s2:string)&#160;;</i>
</pre>
<pre>  <b>s1</b>
         first string
  <b>s2</b>
         second string
</pre>
<pre> <b>returns</b>
  <b>-1</b>
         if s1 &lt; s2
  <b>0</b>
         if s1 = s2
  <b>1</b>
         if s1 &gt; s2
</pre>
<p><br />
</p>
<pre>This allows you to compare strings with case sensitivity in place.  If
you don't care about the case of the string use the normal '==' '&gt;',
'&lt;', '&lt;=', '&gt;=', symbols.
<b>example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>if (strcmp("I Care about Capitals",s2)==0))
        {
        sendtext ("You care I can see.&amp;n",self);
        quit;
        }
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre></div>