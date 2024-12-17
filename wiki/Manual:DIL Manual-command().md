<div class="mw-parser-output"><p><br />
<span id="bfcomm"></span>
</p>
<pre>integer command ( cmd&#160;: string or integer )
   cmd&#160;: A string of the full typed command, e.g. "push" or "say".
         Alternatively you can specify one of the macros defined in
         values.h and/or vme.h, e.g. CMD_SAY
 return: Whether the command specified by the activator is the one of
         the argument.
</pre>
<pre>It is noteworthy, that unlike simple compares like this;
</pre>
<pre>	if ("spook" in cmdstr) {
	...
	...
	}
or
	if (cmdstr == "spook") {
	...
	...
	}
</pre>
<pre>where the first will activate even if the cmdstr is "nospook", and the
second only if cmdstr equals the word "spook" to the letter, the
following construct will activate as long as the contents
of cmdstr doesn't conflict with cmd;
</pre>
<pre>	if (command("spook")) {
	...
	...
	}
</pre>
<pre>ie, it will receive the same kind of treatment as a 'regular' command.
That means that you provide ease of use to the user (allowing shorthand
notation), while securing that you're doing what the user wants.
<strong>CAVEAT</strong> Builder:
If you use a string argument as cmd, be sure that
there are no white-space in it, ie, that the argument does only
consist of letters.
</pre>
<pre>Example:
    command("spook");
</pre>
<pre>    is a valid string, while this construct;
</pre>
<pre>    command("spook him");
</pre>
<pre>    is NOT valid. The reason of that is that cmdstr only contains the
    FIRST word of the input from the player, and thus the latter
    construct could never evaluate to true. This should be evident
    taking the above information into account, as "spook him" could
    never equal "spook" (which would indeed be the text in cmdstr
    if the player entered the string "spook him".)
</pre></div>