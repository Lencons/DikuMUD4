<div class="mw-parser-output"><h3><span class="mw-headline" id="Color_code_descriptions_and_examples">Color code descriptions and examples</span></h3>
<dl><dt>&amp;c and &amp;b</dt>
<dd>In order to allow you to change the colors there are two codes.  One is for the foreground color (&amp;c) and the other is for the background color (&amp;b).  '&amp;c' is used with one or two arguments depending on brightness, while the '&amp;b' s only used with one because it has only one brightness.  They both have the forms as follows:</dd></dl>
<pre>	&amp;c&lt;bright&gt;&lt;color&gt;
	&amp;b&lt;color&gt;
</pre>
<p>It is important to set both the foreground and background color
	because if a player has his default background color set to blue and you
	use blue as a foreground color it will make the letters invisible to the
	player.  It is also important to set the colors back to the default
	color when done.  this is done by using the following command:
</p>
<pre>	&amp;[default]
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>The '&amp;[default]' command will be described in the next section.  It is enough to know for now that it will return the players colors to their default colors.</p></blockquote>
<p>	Before we give some color examples we should now define the
	symbols for brightness and the symbols for each color and what they
	are.
</p>
<table class="wikitable">
<caption>Colors
</caption>
<tbody><tr>
<th>Code
</th>
<th>Color
</th></tr>
<tr>
<td>n
</td>
<td>Black
</td></tr>
<tr>
<td>r
</td>
<td>Red
</td></tr>
<tr>
<td>g
</td>
<td>Green
</td></tr>
<tr>
<td>y
</td>
<td>Yellow
</td></tr>
<tr>
<td>b
</td>
<td>Blue
</td></tr>
<tr>
<td>m
</td>
<td>Magenta
</td></tr>
<tr>
<td>c
</td>
<td>Cyan
</td></tr>
<tr>
<td>w
</td>
<td>White
</td></tr></tbody></table>
<table class="wikitable">
<caption>Sample Color codes
</caption>
<tbody><tr>
<th>Code
</th>
<th>Resulting Colors
</th></tr>
<tr>
<td>&amp;cb&amp;bw
</td>
<td><span style="color: darkblue; background-color: #cccccc;"><b>Example</b></span>
</td></tr>
<tr>
<td>&amp;c+g&amp;bn
</td>
<td><span style="color: lightgreen; background-color: black;"><b>Example</b></span>
</td></tr>
<tr>
<td>&amp;c+w&amp;br
</td>
<td><span style="color: white; background-color: maroon;"><b>Example</b></span>
</td></tr>
<tr>
<td>&amp;c+w&amp;bn
</td>
<td><span style="color: white; background-color: black;"><b>Example</b></span>
</td></tr></tbody></table>
<dl><dt>&amp;[&lt;color&gt;]</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>	As we have said in the previous section if you are not careful you
	can make your text not visible by the player by setting the foreground to
	the same color as the background.  In order to make it possible for you
	to easily change how the color looks and to even match it with the way
	players have their colors set already we have created colors that the
	players can set.  and you can use.  The VME comes
	with a default list of colors which can be added to by either the
	<i>color.def</i> or even by a DIL
	program on line.   The default colors are as follows:
</p>
<table class="wikitable">

<tbody><tr>
<td>death
</td>
<td>default
</td>
<td>exit
</td></tr>
<tr>
<td>group
</td>
<td>hit_me
</td>
<td>hit_opponent
</td></tr>
<tr>
<td>hit_other
</td>
<td>immort_descr
</td>
<td>immort_title
</td></tr>
<tr>
<td>log
</td>
<td>miss_me
</td>
<td>miss_opponent
</td></tr>
<tr>
<td>miss_other
</td>
<td>nodam_me
</td>
<td>nodam_opponent
</td></tr>
<tr>
<td>nodam_other
</td>
<td>npc_descr
</td>
<td>npc_title
</td></tr>
<tr>
<td>obj_descr
</td>
<td>obj_title
</td>
<td>pc_descr
</td></tr>
<tr>
<td>pc_title
</td>
<td>prompt
</td>
<td>respond
</td></tr>
<tr>
<td>room_descr
</td>
<td>broom_title
</td>
<td>say_other
</td></tr>
<tr>
<td>say_self
</td>
<td>shield_me
</td>
<td>shield_opponent
</td></tr>
<tr>
<td>shield_other
</td>
<td>shout_other
</td>
<td>shout_self
</td></tr>
<tr>
<td>social_other
</td>
<td>social_self
</td>
<td>spells
</td></tr>
<tr>
<td>tell_other
</td>
<td>tell_self
</td>
<td>time
</td></tr>
<tr>
<td>weather
</td>
<td>whisper
</td>
<td>who
</td></tr>
<tr>
<td>who_guild
</td>
<td>who_inv
</td>
<td>who_name
</td></tr>
<tr>
<td>who_title
</td>
<td>wiz
</td>
<td>xpgain
</td></tr></tbody></table>
<p>	To use these colors all you have to do is use the following formatting command:
</p>
<pre>	&amp;[color]
</pre>
<p>The color that will be shown is the color that the player has set
	for the color in question.  If for example the player has his or her
	'death' color set to bright red with a black background and you have a
	description as follows:
</p>
<pre>	descr
	"This is a &amp;[death]death&amp;[room_descr]room"
</pre>
<p>The description would be in the players 'room_descr' color while
	the word death would be in his or hers 'death' color.  You should note
	we had to set the color back to the room description color so that the
	rest of the description was not in the 'death' color.
</p><p>	To change the players color to the default out put color which is the color that is
	used when no color is specified by the server then you use
	'default'.  You probably won't use this in normal zone building but it
	is very important to know it exists when you start making spells,
	skills, and commands with DIL
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-Color-and-Formatting-Codes-Formatting-code-descriptions-and-examples" title="Manual:Zone Manual/Color and Formatting Codes/Formatting code descriptions and examples">Previous: Formatting code descriptions and examples</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-DIL-Section" title="Manual:Zone Manual/The DIL Section">Next: The DIL Section</a></div></div>