<div class="mw-parser-output"><p><br />
<span id="bffits"></span>
</p>
<pre>string fits( char&#160;: unitptr, obj&#160;: unitptr, pos&#160;: integer );
   char: Character which we want to test if obj can be fitted upon
   obj:  The object we want to see if fits char.
   pos:  -1 or WEAR_XXX
   Returns: Empty string if ok, or a textual description of the size problem.
</pre>
<pre>   Fits tests if "obj" can be worn by "char" in position "pos". If
   pos is -1, then fits automatically figures out the default worn
   position for "obj".
</pre>
<pre>   Example:
</pre>
<pre>      s&#160;:= fits(self, obj, -1);
      if (s&#160;!= "")
        exec("say Don't buy it, its "+s, self);
</pre></div>