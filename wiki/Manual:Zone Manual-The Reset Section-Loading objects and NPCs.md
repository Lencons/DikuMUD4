<div class="mw-parser-output"><h3><span class="mw-headline" id="Loading_objects_and_NPCs">Loading objects and NPCs</span></h3>
<p>	Time to start loading your zone with its life and all the other
	strange things you have built.  There is two commands that do all the
	loading and equipping of objects.  Oddly enough the commands are called
	'load' and 'equip'.  The format of the commands are almost the same
	but equip must be used inside a NPC grouping.  With that in mind lets
	start with simple loads and work our way up.
</p><p>	The command to load an object or an NPC into a room is as
	follows:
</p>
<pre>	load &lt;object or NPC&gt; [into] [&lt;room&lt;] [&lt;load amount&gt;]
	  [{Other loads and equip commands}]
</pre>
<dl><dt>object or NPC</dt>
<dd>The first argument to the load command is the object or NPC symbolic name that you want to load.  The first argument is the only one that must be included in all load commands.</dd>
<dt>into</dt>
<dd>This is just a symbol that tells the reset that we are loading the object or NPC into some other unit.</dd>
<dt>object, NPC, and room</dt>
<dd>The third argument is the symbolic name of the place where you are loading the object and the NPC.</dd>
<dt>load amount</dt>
<dd>the fourth argument is an optional argument that tells the reset how many of the objects are allowed in the world, zone, or locally.  The possible values for this field are as follows:</dd></dl>
<dl><dt>max &lt;num&gt;</dt>
<dd>This  command  is  always  part  of  another reset command (load,</dd></dl>
<p>	equip, etc.).  At reset time the entire world is scanned for occurences
	of the loaded unit - only if the currently existing number is less than
	&lt;num&gt; will the command be executed.
</p>
<dl><dt>local &lt;num&gt;</dt>
<dd>This command is always  part  of  another  reset  command  (load,</dd></dl>
<p>	equip, etc.).  At reset time the location of which the unit is to
	be loaded into is scanned for occurences of the loaded unit only  if  the currently
	existing number is less than &lt;num&gt; will the
	command be executed.
</p>
<dl><dt>zonemax &lt;num&gt;</dt>
<dd>This command is always  part  of  another  reset  command  (load,</dd></dl>
<p>	equip,  etc.).   At  reset  time  the  entire zone being reset is
	scanned for occurences of the loaded unit - only if the currently
	existing number is less than &lt;num&gt; will the command be
	executed.
</p>
<dl><dt>Optional grouping</dt>
<dd>Any reset command may be followed by a pair of curly brackets {}</dd></dl>
<p>	containing  more reset commands. The commands inside the brackets
	will only be executed in case the associated command was successful.
</p><p>Don't be alarmed if this sounds a bit hard.  It all gets much
	more clear as some examples are explained.  Lets take a look at the
	following example and see if we can't make this much more clear.
</p>
<pre>	load udgaard/fido into midgaard/temple max 1
</pre>
<p>This example is pretty simple it says load the fido into the
	temple only if there isn't already 1 in the world.  Now lets get a bit
	more complicated.
</p>
<pre>	load udgaard/fido into midgaard/temple max 1
	{
	   load bone
	   load excrement into midgaard/temple
	}
</pre>
<p>Now we have said again load the fido into the temple if there is
	not already one in the world.  Then if fido loads fill his inventory
	with a bone and load excrement into the temple as well.
</p><p>	We can get even more complicated but still just using the load
	commands by doing the following
</p>
<pre>	load udgaard/fido into midgaard/temple max 1
	{
	   load bone
	   load excrement into midgaard/temple
	      load bag
	   {
	      load apple max 1
	   }
	}
</pre>
<p>now we still have the fido loading if there isn't one already in
	the world then the bone and the excrement and finally we load a bag.
	If there isn't an apple already in the world we load the bag with a
	apple in it other wise the bag will be empty.
</p><p>	Well that should be enough load examples for now but we will get
	right back to them in a bit.  Now we should introduce another reset
	command called the 'equip' command that we have already mentioned.  The
	'equip' command works a lot like load but has much simpler arguments.
	The 'equip' command is as follows.
</p>
<pre>	equip &lt;symbol&gt; position [load amount &lt;num&gt;]
</pre>
<dl><dt>symbol</dt>
<dd>The first argument is just the symbolic name of the item being worn by the NPC.</dd>
<dt>position</dt>
<dd>The position is any of the positions available in the</dd></dl>
<p>	<i>vme.h</i>.  The following are all the positions along
	side there defines as found in the <i>vme.h</i>.
</p>
<table class="wikitable">
<caption>Wear positions
</caption>
<tbody><tr>
<th>Position
</th>
<th>Define(s)
</th></tr>
<tr>
<td>head
</td>
<td>WEAR_HEAD
</td></tr>
<tr>
<td>hands
</td>
<td>WEAR_HANDS
</td></tr>
<tr>
<td>arms
</td>
<td>WEAR_ARMS
</td></tr>
<tr>
<td>body
</td>
<td>WEAR_BODY
</td></tr>
<tr>
<td>legs
</td>
<td>WEAR_LEGS
</td></tr>
<tr>
<td>feet
</td>
<td>WEAR_FEET
</td></tr>
<tr>
<td>cloak
</td>
<td>WEAR_ABOUT
</td></tr>
<tr>
<td>shield
</td>
<td>WEAR_SHIELD
</td></tr>
<tr>
<td>hold
</td>
<td>WEAR_HOLD
</td></tr>
<tr>
<td>wield
</td>
<td>WEAR_WIELD
</td></tr>
<tr>
<td>ear
</td>
<td>WEAR_EAR_R and WEAR_EAR_L
</td></tr>
<tr>
<td>neck
</td>
<td>WEAR_NECK_1 and WEAR_NECK_2
</td></tr>
<tr>
<td>wrist
</td>
<td>WEAR_WRIST_R and WEAR_WRIST_L
</td></tr>
<tr>
<td>finger
</td>
<td>WEAR_FINGER_R and WEAR_FINGER_L
</td></tr>
<tr>
<td>chest
</td>
<td>MANIPULATE_WEAR_CHEST
</td></tr>
<tr>
<td>back
</td>
<td>MANIPULATE_WEAR_BACK
</td></tr>
<tr>
<td>waist
</td>
<td>MANIPULATE_WEAR_WAIST
</td></tr>
<tr>
<td>ankle
</td>
<td>WEAR_ANKLE_R and WEAR_ANKLE_L
</td></tr></tbody></table>
<dl><dt>load amount</dt>
<dd>the fourth argument is an optional argument that tells the reset how many of the objects are allowed in the world, zone, or locally.  The possible values for this field are as follows:</dd></dl>
<dl><dt>max &lt;num&gt;</dt>
<dd>This  command  is  always  part  of  another reset command (load,</dd></dl>
<p>	equip, etc.).  At reset time the entire world is scanned for occurences
	of the loaded unit - only if the currently existing number is less than
	&lt;num&gt; will the command be executed.
</p>
<dl><dt>local &lt;num&gt;</dt>
<dd>This command is always  part  of  another  reset  command  (load,</dd></dl>
<p>	equip, etc.).  At reset time the location of which the unit is to
	be loaded into is scanned for occurences of the loaded unit - only  if  the currently
	existing number is less than &lt;num&gt; will the
	command be executed.
</p>
<dl><dt>zonemax &lt;num&gt;</dt>
<dd>This command is always  part  of  another  reset  command  (load,</dd></dl>
<p>	equip,  etc.).   At  reset  time  the  entire zone being reset is
	scanned for occurences of the loaded unit - only if the currently
	existing number is less than &lt;num&gt; will the command be
	executed.
</p><p>Now with the equipment command you can now get your NPCs dressed
	and ready for battle.  The 'load' and 'equip' commands are not the
	easiest though so lets go through some simple examples.
</p>
<pre>	load guard into jail
	  {
	  equip helmet WEAR_HEAD
	  equip plate WEAR_BODY
	  equip pants WEAR_LEGS
	  equip specialsword max 1
	  load brass_key
	  }
</pre>
<p>This is how you would equip a NPC with all items from the current
	zone.  As you can see we didn't need full symbolics because the server
	knows to grab the items from the zone the resets are in.
</p>
<pre>	load guard into safe_room max 2
	 {
	 equip plate WEAR_BODY
	 load powersword max1
	  {
	  load silver_pile into safe_room
	  }
	 }
</pre>
<p>In this example we only load the silver pile if the guard loads
	and if the power sword loads which may or may not happen since there is
	only a max of one sword allowed while there is a max of 2 guards
	allowed.  What will happen in this case is at the first reset there will
	be one guard and one pile of silver.  The next reset there will still
	only be one pile of silver but now there will be two guards.
</p><p>	Hopefully you have got the basic resets down.  If not don't worry
	there are plenty more examples to come and we still have to make the
	resets for our dragon station zone.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Reset-Section" title="Manual:Zone Manual/The Reset Section">Previous: The Reset Section</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Reset-Section-Special-reset-functions" title="Manual:Zone Manual/The Reset Section/Special reset functions">Next: Special reset functions</a></div></div>