<div class="mw-parser-output"><h3><span class="mw-headline" id="Formatting_code_descriptions_and_examples">Formatting code descriptions and examples</span></h3>
<dl><dt>&amp;&amp;</dt>
<dd>If you want a single '&amp;' you must let the VME know that you don't want a formatting or a color code.  You do this by doubling the '&amp;' sign.  The following is a couple examples:</dd></dl>
<table class="wikitable">

<tbody><tr>
<td>text
</td>
<td>Result
</td></tr>
<tr>
<td>&amp;&amp;
</td>
<td>&amp;
</td></tr>
<tr>
<td>&amp;&amp;&amp;&amp;
</td>
<td>&amp;&amp;
</td></tr>
<tr>
<td>&amp;&amp;&amp;&amp;&amp;&amp;
</td>
<td>&amp;&amp;&amp;
</td></tr></tbody></table>
<dl><dt>&amp;l</dt>
<dd>When you want to turn off the formatting you use this formatting code.  Everything after the '&amp;l' will be shown exactly as you put it in the string.</dd></dl>
<pre>	&amp;l
	*     *
	 *   *
	  * *
	   *
	  * *
	 *   *
	*     *
</pre>
<dl><dt>&amp;f</dt>
<dd>The formatted text as we have already said is default.  If you want to turn the formatted text back on after some literal text you will have to use the '&amp;f' code.  The following is an example of some literal text followed by a short bit of formatted text.</dd></dl>
<pre>	&amp;l
	*     *
	 *   *
	  * *
	   *
	  * *
	 *   *
	*     *

	&amp;fThe X marks the spot!
</pre>
<dl><dt>&amp;s&lt;#&gt;</dt>
<dd>If you want to input extra spaces in a sentence with out using the</dd></dl>
<p>	'&amp;l' you can	 add them one at a time or multiple by using the
	'&amp;s' code.
</p>
<pre>	This sentence has 10 spaces&amp;s10before the first word before.
</pre>
<dl><dt>&amp;n</dt>
<dd>If you want to input some blank lines with out using the literal code you can add a '&amp;n'for each line you want.</dd></dl>
<pre>	This sentence&amp;n&amp;n&amp;n would look like this:

	This sentence

	would look like this:
</pre>
<dl><dt>&amp;x</dt>
<dd>The line break is made for use with the DIL language.  You will not need it to do regular text formatting.  It was added so a DIL could split a string that is loaded from a file.  If you don't understand the following example don't worry it is explained more in the DIL reference.</dd></dl>
<pre>	mystrlist:=split(string,"&amp;");
</pre>
<dl><dt>&amp;h</dt>
<dd>On terminals that can handle it the '&amp;h' will clear the screen.  If you wanted a sign that would clear the screen before displaying when a character looked at it would look like this.</dd></dl>
<pre>	&amp;h&amp;l
	*     *
	 *   *
	  * *
	   *
	  * *
	 *   *
	*     *

	&amp;fThe X marks the spot!
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-Color-and-Formatting-Codes-Formatting-codes" title="Manual:Zone Manual/Color and Formatting Codes/Formatting codes">Previous: Formatting codes</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-Color-and-Formatting-Codes-Color-code-descriptions-and-examples" title="Manual:Zone Manual/Color and Formatting Codes/Color code descriptions and examples">Next: Color code descriptions and examples</a></div></div>