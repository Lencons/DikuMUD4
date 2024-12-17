<div class="mw-parser-output"><p><br />
<span id="bpinsert"></span>
</p>
<pre><b>Function:  </b><i>insert( sl&#160;: &lt;stringlist or intlist&gt;, i&#160;: integer, s&#160;: string )&#160;;</i>
</pre>
<pre>  <b>sl</b>
         the stringlist or intlist you are inserting to
  <b>i</b>
         the index where you want to insert the string
  <b>s</b>
         the string you want to insert
</pre>
<pre>This function allows you to insert a string in a stringlist or intlist
with out re-writing the entire stringlist or intlist to do it.  The
following Dil will add a string in order to a stringlist.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin stringlist add_in_order (sl:stringlist,s:string);
var
 i:integer;
 ln:integer;
code
{
if (length(sl)==0)
 {
 addstring (sl,s);
 return (sl);
 }
</pre></i><i><pre>ln:=length(s);
i:=0;
while (i&lt;ln)
 {
 if (length(sl.[i]) &lt;=ln)
  {
  insert (sl,i,s);
 return(sl);
 }
 i:=i+1;
 }
</pre></i><i><pre>addstring (sl,s);
return (sl);
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>