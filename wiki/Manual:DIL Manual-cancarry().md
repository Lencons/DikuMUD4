<div class="mw-parser-output"><p><br />
<span id="bfcancarry"></span>
</p>
<pre>integer can_carry(ch&#160;: unitptr, u&#160;: unitptr, n&#160;: integer)
   ch&#160;: The character to check
   u  : The unit to check if he can carry.
   n  : How many copies of that unit.
</pre>
<pre>   Returns: 0 if 'ch' can carry 'n' times 'u'.
            1 if 'n' items are too many (his hands are full)
            2 if 'n' times 'u' are too heavy
</pre>
<pre>   Example:
</pre>
<pre>      i&#160;:= can_carry(activator, item, 1);
</pre>
<pre>      if (i == 1)
        exec("say Your hands are full!", self);
      else if (i == 2)
        exec("say You cant carry that much weight.", self);
      else
        exec("give "+item.name+" to "+activator.name, self);
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>