<div class="mw-parser-output"><p><br />
<span id="esins"></span>
</p>
<pre>string 'in' string
   Argument 1: A string to find.
   Argument 2: A string to search.
   Return: TRUE, if first string is found in second string.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     if ("guard" in activator.title)
       exec("say hello guard",self);
     pause;
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>