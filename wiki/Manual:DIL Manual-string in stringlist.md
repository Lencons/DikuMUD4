<div class="mw-parser-output"><p><br />
<span id="esinsl"></span>
</p>
<pre>string 'in' stringlist
   Argument 1: A string to find.
   Argument 2: A stringlist to search.
   Returns: 1.. if first string is found in stringlist, or 0 if it is
            non existent. If found the number equals the index of the
            string found plus one.
</pre>
<pre>Example 1:
  s&#160;:= "c";
  sl&#160;:= {"a","b","c","d"};
  i&#160;:= s in sl;
</pre>
<pre>  The result of 'i' is 3, and sl.[i-1] equals "c" (s).
</pre>
<pre>Example 2:
</pre>
<pre>

   dilbegin foo();
   code
   {
     if ("james" in activator.names)
       exec("say hello james.",self);
     pause;
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>