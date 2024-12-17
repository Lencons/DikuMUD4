<div class="mw-parser-output"><p><br />
<span id="strl"></span>
</p>
<pre><b>Stringlist:</b>
</pre>
<pre>  A stringlist is a list of separate strings. This is used for things such as
(multiple) names or keywords. You may request a specified word in a stringlist
by its number.
<b>Example:</b>
</pre>
<pre>  mystring&#160;:= self.names.[2];
</pre>
<pre>  Returning null if out of bounds of the stringlist (see 'length()'). Static
stringlists are defined just as in the rest of the zonefile, as a comma separated
list of static strings within curly brackets.
</pre>
<pre><b>Example:</b>
</pre>
<pre>  mysrtringlist&#160;:= {"Some string","another string","the last string"}
</pre>
<pre>  Stringlists are modified through the 'addstring()' and 'substring()' procedures.
Stringlists are searched easily by the 'in' operator. See documentation below.
They can also be set directly (see example above).  Variables of type string are
saved with DIL programs, if attached to a saved unit.
</pre>
<pre>  Elements of each separate string in a stringlist can be accessed by appending
a separate position at the end of the request for a string as follows:
</pre>
<pre><b>Example</b>
if (strlist.[5].[3]=="b"){
do something
}
</pre>
<pre><b>Note</b>
  See the strings for more information on accessing a single element.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>