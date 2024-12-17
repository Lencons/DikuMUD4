<div class="mw-parser-output"><p><br />
<span id="intlist"></span>
</p>
<pre><b>Intlist:</b>
</pre>
<pre>  Intlists are an array of integer types.  They can be set directly as follows:
</pre>
<pre><b>Example</b>
</pre>
<pre>wpn:={5,3,6,9,3,9};
</pre>
<pre>The intlists can be accessed in the same way stringlist are accessed as follows.
</pre>
<pre><b>Example</b>
</pre>
<pre>if (wpn.[5]==5)
{
do something
}
</pre>
<pre>The intlists are saved on savable units.
</pre>
<pre><b>Type:  </b><i>intlist</i>
</pre>
<pre>  This variable type allows you to keep an ordered list of integers with out
having to create a variable for each integer.
<b>Example:</b>  <i>Setting an intlist</i>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>myintlist:={1,5,9,2,8,5};
myintlist.[10]:=50;
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<pre>  If you set a index that is higher then the highest index, every index in
between will be set to zero.  For example if you only have two values in the
intlist and you set index value 10 to 50 all indexes between 2 and 10 will be
set to 0.
<b>Example:</b>  <i>Using intlists</i>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>if (myintlist.[5]==5){
stuff
}
</pre></i><i><pre>if (myintlist&lt;myint){
stuff
}
</pre></i><i><pre>i:=0;
ln:=length(myintlist);
while (i&lt;ln){
myintlist.[i]:=i;
i:=i+1;
}
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also:</b>
<a href="#bpinsert">Insert</a>
<a href="#bpremove">Remove</a>
<a href="#eptr">Extraptr</a>
</pre></div>