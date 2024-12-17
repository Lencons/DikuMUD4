<div class="mw-parser-output"><p><br />
<span id="excmdstr"></span>
</p>
<pre>'excmdstr'
   This variable is a string which contains the "first string" which was entered
   by a player. The result of adding:
</pre>
<pre>      excmdstr + " " + argument
</pre>
<pre>   is the entire string as entered by the player. The 'excmdstr' is not
   EXPANDED by the interpreter, but it is converted to lower case. So
   assume a player types 'S' then the string is returned as 's'.  The
   'excmdstr' is however changed to all lower case if you don't want
   this see 'excmdstr_case'.
</pre></div>