<div class="mw-parser-output"><p><br />
<span id="bfstrncmp"></span>
</p>
<pre><b>Function:</b>  <i>integer strcmp( s1:string, s2:string l :integer)&#160;;</i>
</pre>
<pre>  <b>s1</b>
         first string
  <b>s2</b>
         second string
  <b>l</b>
         amount of significant digits to compare
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
<pre>This allows you to compare strings with case sensitivity in place and it
allows you to choose how much of the strings are compared.
<b>example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>if (strcmp("Mark Carper",s2,4)==0))
        {
        sendtext ("Hi Mark how is it going?&amp;n",self);
                quit;
        }
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>