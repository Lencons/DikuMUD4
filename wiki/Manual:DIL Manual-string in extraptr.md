<div class="mw-parser-output"><p><br />
<span id="esine"></span>
</p>
<pre>string in extraptr
   Argument 1: A string to find.
   Argument 2: An extra description list to search.
   Return: Extraptr to first entry with string matching .names or
           null if none. (names must be exact letter by letter
           match, although case is ignored).
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     if ("Rabbit Stew Complete" in activator.quests) {
       exec("say wow!, you helped Mary get her stew!", self);
       exec("app ", self);
     }
     pause;
   }
   dilend
</pre></div>