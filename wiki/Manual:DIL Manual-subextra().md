<div class="mw-parser-output"><p><br />
<span id="bpsubex"></span>
</p>
<pre>subextra ( var e&#160;: extraptr, s&#160;: string )
   e&#160;: Extra description list to remove element from.
   s&#160;: String matching .names field in element
   result: Removes first extra description from list with matching name.
</pre>
<pre>&lt;emp&gt;CAVEAT&lt;/EMP&gt; builder: You cannot use an extraptr variable as the e
argument, but you may continue to use the following form:
</pre>
<pre>   ...
   ...
   subextra (self.quests, "Bozo's Quest");
   ...
   ...
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>