<div class="mw-parser-output"><p><br />
<span id="bpaddex"></span>
</p>
<pre>addextra ( var e&#160;: extraptr, l&#160;: stringlist , s&#160;: string )
   e&#160;: Extra description list to add element to.
   l&#160;: Stringlist for the .names field.
   s&#160;: String for the .descr field.
   result: Adds an extra description to a list of extra descriptions.
</pre>
<pre><strong>CAVEAT</strong> builder: You cannot use an extraptr variable as the e
argument, but you may continue to use the following form:
</pre>
<pre>   ...
   ...
   addextra (self.quests, "Bozo's Quest");
   ...
   ...
</pre>
<p>See also:
</p>
<pre> subextra
</pre></div>