<div class="mw-parser-output"><h3><span class="mw-headline" id="Formatting_codes">Formatting codes</span></h3>
<p>	As you may have noticed the string fields on the VME are formatted
	   in an english paragraph style.  What that means is all text is
	   formatted with he following rules:
</p>
<ul><li class="mw-empty-elt"></li></ul>
<p>	   All leading blanks are stripped away. For room descriptions
	    3 leading spaces are added. This way we ensure a consistent
	    formatting of the displayed room descriptions.
</p>
<ul><li class="mw-empty-elt"></li></ul>
<p>	Spaces and blanks (newlines) are contracted to single spaces
	    yielding a correctly 'wrapped' text for any sentence.
</p>
<ul><li class="mw-empty-elt"></li></ul>
<p>	If a '.' is encountered followed by a blank, a total of two
	    spaces are inserted after the '.'.
These formatting rules are great for normal descriptions and
	extras but what if you want to make a sign or a map.  You don't always
	want the text to be rapped, if the server rapped your sign it would turn
	out looking like a jumble of punctuation in the form of a paragraph.
	(Link to formattable) contains a list of all formatting
	characters and a short description of them.
	(Link to formatdescr) contains a more in depth discussion of each
	format command with examples and (Link to colordescr) deals with
	the color commands.
</p>
<table class="wikitable">
<caption>Formatting and color codes
</caption>
<tbody><tr>
<th>Code
</th>
<th>Description
</th></tr>
<tr>
<td>&amp;
</td>
<td>Used to make an &amp; character instead of an escape code.
</td></tr>
<tr>
<td>l
</td>
<td>Text from this point forward will not be formatted. It will
<p>	               be interpreted literally with newlines, spaces, etc.
	               Useful when making a sign or a map.
</p>
</td></tr>
<tr>
<td>f
</td>
<td>Text from this point forward will be formatted. This option
<p>	               is the reverse of &amp;l and is default on any section of text.
</p>
</td></tr>
<tr>
<td>s&lt;#&gt;
</td>
<td>Force a singe space character (or &lt;#&gt; if specified, may
<p>	               come in handy, instead of having to toggle formatting).
</p>
</td></tr>
<tr>
<td>n
</td>
<td>Force a new line, very handy instead of toggling the &amp;l
<p>	               formatting switch.
</p>
</td></tr>
<tr>
<td>h
</td>
<td>Clears the screen if the terminal of the user supports it.
</td></tr>
<tr>
<td>x
</td>
<td>A file new line used for split so that you can split a file into lines
</td></tr>
<tr>
<td>c&lt;color&gt;
</td>
<td>Set the foreground color.
</td></tr>
<tr>
<td>b&lt;color&gt;
</td>
<td>Set the background color.
</td></tr>
<tr>
<td>[&lt;color&gt;]
</td>
<td>Set a preset foreground and background color.
</td></tr></tbody></table>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-Color-and-Formatting-Codes" title="Manual:Zone Manual/Color and Formatting Codes">Previous: Color and Formatting Codes</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-Color-and-Formatting-Codes-Formatting-code-descriptions-and-examples" title="Manual:Zone Manual/Color and Formatting Codes/Formatting code descriptions and examples">Next: Formatting code descriptions and examples</a></div></div>