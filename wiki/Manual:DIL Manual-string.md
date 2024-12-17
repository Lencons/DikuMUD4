<div class="mw-parser-output"><p><br />
<span id="str"></span>
</p>
<pre><b>String:</b>
</pre>
<pre>   A string is some text. They are used for a lot of things such as command
arguments, room descriptions etc. String variables are automatically resized and
allocated when you assign them, so you do not have to worry about the string
length nor allocation in your DIL programs. Strings may be compared either with
'==' (equal to),
'!=' (not equal),
'&lt;=' (less than or equal to),
'&gt;=' (greater than or equal to)
'&lt;' (less than),
 '&gt;' (greater than.
</pre>
<pre>  Static strings are defined just as in the rest of the zone, within double
quotations.  Strings may be searched easily with the 'in' operator.  Variables
of type string are saved with DIL programs, if attached to a saved unit.
</pre>
<pre><b>Example:</b>
</pre>
<pre>  "This is a static string"
</pre>
<pre>Strings may also be added to each other, in an expression.
</pre>
<pre><b>Example:</b>
</pre>
<pre>  "say "+itoa(42)+" is the answer!"
</pre>
<pre><b>Example:</b>
</pre>
<pre>  if (self.name == self.names.[1]) ...
</pre>
<pre>  Elements of the string can also be accessed by referencing them by their position.
</pre>
<pre>  <b>Example</b>
  if (str.[3]==f])
  {
  exec ("say The 4th element is a F.",self);
  }
</pre>
<pre>  <b>Note</b>
  Currently you can only access the single elements of a string you can not set
them.  In the future this will be possible.  You can still accomplish this by
copying one string to the other one element at a time and changing any that you
want something like this.
</pre>
<pre><b>Example</b>
i:=0;
ln:=length (str);
while (str.[i]&lt;ln)
	{
	if (str.[i]=="f")
	newstr.[i]:="b";
	else
	newstr:=str.[i];
	i:=i+1;
	}
	str:=newstr;
</pre>
<pre>  This snip of Dil would replace any 'f' in a string with a 'b' remember dil is
not case sensitive so it will also replace an 'F'.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>