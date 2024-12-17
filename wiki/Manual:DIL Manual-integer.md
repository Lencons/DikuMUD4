<div class="mw-parser-output"><p><br />
<span id="int"></span>
</p>
<pre><b>Integer:</b>
</pre>
<pre>  Non-fraction numbers can be used throughout your DIL programs.  They are given
normally, or in normal C style hexadecimal, preceded with '0x'. Integers are
signed 32-bit integers.  Variables of type string are saved with DIL programs,
if attached to a saved unit.
</pre>
<pre><b>Example:</b>
</pre>
<pre>  0x10
</pre>
<pre><b>Example:</b>
</pre>
<pre>  2
</pre>
<pre>  Integers are used within expressions as both number value and boolean(true/false)
values. You may use comparison between integers through the comparison operators:
'==' (equality),
'&lt;' (less than),
'&gt;' (greater than),
'&lt;=' (less or equal),
'&gt;=' (greater or equal)
'!=' (not equal).
</pre>
<p><br />
</p>
<pre><b>Example:</b>
</pre>
<pre>  if (42&lt;12) ...
</pre>
<pre>  Returning the boolean value (true/false) depending on the comparison between
integers. The result may be stored in an integer variable, and tested later, or
used directly in an 'if' or 'while', etc.  You may also operate on boolean
expression themselves, using LOGICAL operators 'and','not','or', which allows
you to combine the expressions.
</pre>
<pre><b>Example:</b>
</pre>
<pre>  if ( not ( (self.hp&lt;42) or (self.level&gt;10) ) ) ..
</pre>
<pre>Integer expressions may also use a number of other operators:
'+' (addition)
'-' (subtraction/negation),
'*' (multiplication),
'/' (division),
'|' (bitwise or, for flags),
'&amp;' (bitwise and, for flags)
</pre>
<pre>Precedence rules for using these operators are still somewhat messed up.  You'd
better use parenthesis where ever possible.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>