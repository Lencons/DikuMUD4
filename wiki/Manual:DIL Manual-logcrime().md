<div class="mw-parser-output"><p><br />
<span id="bplogcrime"></span>
</p>
<pre>logcrime( c&#160;: unitptr, v&#160;: unitptr, t&#160;: integer )
   c&#160;: The criminal (main suspect)
   v&#160;: The victim
   t&#160;: The crime type (CRIME_XXX)
</pre>
<pre>      Registers a crime committed against 'v' by 'c'. Use the
    CRIME_XXX values from values.h and/or vme.h as the 't' argument.
    The logcrime routine automatically registers group members
    of the criminal, etc. In stuff like steal, remember to make
    the criminal visible if he fails his attempts.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>