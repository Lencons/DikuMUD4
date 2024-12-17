<div class="mw-parser-output"><h2><span class="mw-headline" id="The_room_section">The room section</span></h2>
<p>		 The previous chapter gave you the basic building blocks that
		will be used all through creating rooms, NPCs, and objects.  If you
		jumped straight to this chapter without reading about the general
		building blocks you might want to return to (Link to ch-03)
		first.  This chapter will deal with all the fields
		of rooms what they are and how to use them but with out the previous
		chapter you may get lost.
</p><p>		In order to get started building rooms you should first be aware
		of the room fields you can use.  The (Link to rmfields) shows a full listing
		of all the room fields and their types as defined in (Link to ch-03).
</p>
<table class="wikitable">
<caption>Room fields and types listing
</caption>
<tbody><tr>
<th>Field
</th>
<th>Type
</th>
<th>Field
</th>
<th>Type
</th></tr>
<tr>
<td>symbolic name
</td>
<td>Symbol
</td>
<td>manipulate
</td>
<td>Integer
</td></tr>
<tr>
<td>names
</td>
<td>Stringlist
</td>
<td>alignment
</td>
<td>Integer
</td></tr>
<tr>
<td>title
</td>
<td>String
</td>
<td>flags
</td>
<td>Integer
</td></tr>
<tr>
<td>descr
</td>
<td>String
</td>
<td>weight
</td>
<td>Integer
</td></tr>
<tr>
<td>outside_descr
</td>
<td>String
</td>
<td>capacity
</td>
<td>Integer
</td></tr>
<tr>
<td>extra
</td>
<td>Structure
</td>
<td>light
</td>
<td>Integer
</td></tr>
<tr>
<td>minv
</td>
<td>Integer
</td>
<td>exit
</td>
<td>Structure
</td></tr>
<tr>
<td>key
</td>
<td>string
</td>
<td>movement
</td>
<td>Integer
</td></tr>
<tr>
<td>spell
</td>
<td>Integer
</td>
<td>end
</td>
<td>Symbol
</td></tr>
<tr>
<td>dilbegin or dilcopy
</td>
<td>Function pointer
</td>
<td>
</td>
<td>
</td></tr></tbody></table>
<p>As you can see there is not a whole lot of fields you have to
		learn in order to make a room.  In fact as you will see shortly some of
		these fields are not even used on rooms.  In (Link to rmfielddescr) we will expand your knowledge from just knowing what the
		field types are to how to set them as well.
</p>
<h3><span class="mw-headline" id="Description_of_room_fields">Description of room fields</span></h3>
<dl><dt>symbolic name</dt>
<dd>The rules of the symbols has been explained in (Link to ch-03), if you didn't read them yet you may want to review.</dd></dl>
<p>		 The important thing to realize with the room symbol is it is always
		 good practice to give the room a symbol resembling the title so
		 administrators and builders can use the
		 <b>goto</b> and the <b>wstat</b> to easily
		 goto the room in question.
</p>
<dl><dt>title</dt>
<dd>The room title field should start with a capital and depending on your preference the compiler will not complain if you add punctuation at the end.  The following are good examples of a room title.</dd></dl>
<pre>	title "The Post Office"
	title "The deep dark jungle floor:"
	title "The Dragon Station control room"
</pre>
<p>It is really up to you weather you want to use punctuation or not, it
		is more administrator personal opinion than anything.
</p>
<dl><dt>names</dt>
<dd>The names field on the rooms are not that important and only should be used if the builder wishes the room to be accessed by the players by a teleport command.  If the room has no names no one will be able to teleport to it.  On some muds there will be no teleport spell so the only use for this field will be for DIL functions the administrator creates.  If a builder wants the room to be accessible by teleport then the names should match the title since that is what the player will try to teleport to.  A few good examples of names on a room would look as follows.</dd></dl>
<pre>	title "The Post Office"
	Names {"post office","office"}

	title "the thrown room"
	names {"thrown room","thrown"}
</pre>
<dl><dt>descr</dt>
<dd>The description field is what the player sees when walking into the room or when looking with no arguments.</dd>
<dt>outside_descr</dt>
<dd>This field is what is shown to a char if the room is loaded inside another room.  For example if you had a room linked inside another room and called a barrel this would be the description that lets the character know it is a barrel.  An example would be like:</dd></dl>
<pre>	outside_descr "a big old barrel is laying here on its side."
</pre>
<p>This allows a builder to make a room that looks like an object
		inside another room.
</p>
<dl><dt>movement</dt>
<dd>The movement field defines the endurance cost to a character when moving through this room.  In the future these fields will be adjustable by the use of a define file.  Currently all movement fields are constants and are defined in the</dd></dl>
<p>	<i>vme.h</i>  The following is the movement sector types and their values.
</p>
<table class="wikitable">
<caption>Sector movement values
</caption>
<tbody><tr>
<th>Symbol
</th>
<th>Name
</th>
<th>Endurance Cost
</th></tr>
<tr>
<td>SECT_INSIDE
</td>
<td>inside
</td>
<td>1
</td></tr>
<tr>
<td>SECT_CITY
</td>
<td>city
</td>
<td>1
</td></tr>
<tr>
<td>SECT_FIELD
</td>
<td>field
</td>
<td>2
</td></tr>
<tr>
<td>SECT_FOREST
</td>
<td>forest
</td>
<td>3
</td></tr>
<tr>
<td>SECT_HILLS
</td>
<td>hills
</td>
<td>4
</td></tr>
<tr>
<td>SECT_MOUNTAIN
</td>
<td>mountain
</td>
<td>6
</td></tr>
<tr>
<td>SECT_DESERT
</td>
<td>desert
</td>
<td>8
</td></tr>
<tr>
<td>SECT_SWAMP
</td>
<td>swamp
</td>
<td>8
</td></tr>
<tr>
<td>SECT_WATER_SWIM
</td>
<td>water-swim
</td>
<td>4
</td></tr>
<tr>
<td>SECT_WATER_SAIL
</td>
<td>water-sail
</td>
<td>50
</td></tr>
<tr>
<td>SECT_UNDER_WATER
</td>
<td>under-water
</td>
<td>8
</td></tr>
<tr>
<td>SECT_SNOW
</td>
<td>snow
</td>
<td>8
</td></tr>
<tr>
<td>SECT_SLUSH
</td>
<td>slush
</td>
<td>6
</td></tr>
<tr>
<td>SECT_ICE
</td>
<td>ice
</td>
<td>10
</td></tr></tbody></table>
<p>The movement is simply defined by placing the 'movement' keyword first
	followed by the type of sector you desire.  For example a few
	movement fields would look as follows:
</p>
<pre>	movement SECT_FOREST
	movement SECT_HILLS
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>Only one movement is needed for a room if you put more than one the last one added will be the one used.</p></blockquote>
<dl><dt>flags</dt>
<dd>This field on a room is used to set special attributes in order to make the room private or no-teleportable and many others.  The following is the list of possible already defined flags.  Extras can also be used to create special room flags.</dd></dl>
<table class="wikitable">
<caption>Room unit flag affects
</caption>
<tbody><tr>
<th>Flag
</th>
<th>Description
</th></tr>
<tr>
<td>UNIT_FL_PRIVATE
</td>
<td>When this flag is set on a room it marks it as a private room.  Commands
<p>	that honor the private flag will not let more than 2 players into this room.
	Commands like <b>goto</b> and direction commands are a few
	commands that do honor this flag.
</p>
</td></tr>
<tr>
<td>UNIT_FL_INVISIBLE
</td>
<td>Makes unit invisible
</td></tr>
<tr>
<td>UNIT_FL_NO_BURY
</td>
<td>Makes a hard floor so items can't be buried.
</td></tr>
<tr>
<td>UNIT_FL_BURIED
</td>
<td>Makes unit buried when loaded
</td></tr>
<tr>
<td>UNIT_FL_NO_TELEPORT
</td>
<td>makes unit so no one can teleport to it
</td></tr>
<tr>
<td>UNIT_FL_NO_MOB
</td>
<td>Makes it so no mobile will enter the unit
</td></tr>
<tr>
<td>UNIT_FL_NO_WEATHER
</td>
<td>keeps weather and natural light out of unit
</td></tr>
<tr>
<td>UNIT_FL_INDOORS
</td>
<td>Makes unit inside and doesn't affect weather
</td></tr>
<tr>
<td>UNIT_FL_TRANS
</td>
<td>Makes unit transparent
</td></tr>
<tr>
<td>UNIT_FL_NO_SAVE
</td>
<td>Makes it so you can't save with unit
</td></tr>
<tr>
<td>UNIT_FL_SACRED
</td>
<td>Makes unit a double gain unit
</td></tr>
<tr>
<td>UNIT_FL_MAGIC
</td>
<td>Marks a unit to be magic
</td></tr></tbody></table>
<dl><dt>extra</dt>
<dd>Extras are the work horse of the VME.  Extras are used in everything from DIL to just normal extra descriptions on rooms.  The first job for an extra was to hold extra description information on a room.  For example if you had a computer room and you described it might look something like this:</dd></dl>
<pre>	descr
	"This small room houses the computer power of the VME development team.
	All four walls are lined with various pieces of computer equipment old pizza
	boxes and plenty of empty soda cans."
</pre>
<p>The problem is as a player if you saw this description you might want to know what kind
	of pizza we eat or maybe you would want to see what kind of soda we drink.  Or heaven forbid you might want to know
	what kinds of computer equipment is scattered about the room.  In the VME servers we
	do this by adding extra descriptions to the room.  In this case the builder of the zone
	may do something like this:
</p>
<pre>	descr
	"This small room houses the computer power of the VME development team.
	All four walls are lined with various pieces of computer equipment old pizza
	boxes and plenty of empty soda cans."

	extra {"soda cans", "cans", "soda", "can"}
	"These cans are all Canadian blue.  Maybe the Valhalla team hates American
	beer.  Strange all of them look to have strange indentations."

	extra {"strange indentations", "strange indentation","indentation"}
	"They are human bite marks.  Is this what happens when code doesn't work right?"

	extra {"pizza boxes","pizza","boxes","box"}
	"Dominos could make a fortune from all these boxes and probably already have
	from the VME team.  you notice all the boxes are empty at least they finish what
	they start."

	extra {"computer pieces","computer parts", "equipment","hardware", "pieces", "parts"}
	"I bet you thought you would see what we have running.  Yeah right you might come
	over and rob us if we told you that.  All you see is an old XT."

	extra {"xt"}
	"Its a hunk of junk really!"
</pre>
<p>There is a lot to notice in the previous examples.  First we will start with
	extras when defined on rooms, NPC, and objects must be in length
	order for the names.  There are a few reasons for this but lets just
	say the most important reason is we wanted it this way.  If you
	don't put them in order the VMC will give you a fatal error and
	will not compile your zone.
</p><p>	The next thing you should notice is we have used an extra to
	describe something in another extra.  We actually did this twice
	once for the beer cans and once for the computer parts.  That way
	you	can actually give quest information but make the person really
	have to explore your rooms descriptions to find it.
</p><p>	The previous example is what we consider normal extras in a
	room.  There are also extras that hold information for DIL functions.  These
	special extras can have extra fields and they can be hidden to the
	players eyes.  Here are some
	examples of special extras.
</p>
<pre>	extra {"$rockcount"}
	"5"

	extra {"$playerkill"}
	"0"

	extra {"$coke","$milk","$water"}{1,5,10}
	"Drinks and amounts"
</pre>
<p>These extras all have the '$' sign appended to the front of
	the names in order to tell the look command the player
	shouldn't be able to look at the extra.  If you have not already seen
	DIL coding you may not understand why you would want extras
	players can't see.  The DIL language can manipulate these extras by
	reading and writing them in order to change the way a command or
	another function works.  For example the last DIL could be used for
	a shopkeeper to tell how many of each type of drink he has.  Notice
	the drink extra also has something you haven't seen yet, an added integer list after the namelist. all extras can have these but
	only extras being used with DIL functions really need
	them.
</p><p>	Some of these special functions are supported already in the code
	 and the ones that affect the rooms are as follows.  In the
	 following $1n is the activator and $2n is the unit in question.
</p><p>	There is only one special extra already supported for rooms and
	that would be the '$get'.  As we have previously
	mentioned the extras that start with a dollar sign are not seen by the
	players.  This one however is shown to the player when the person
	types get on the other names in the extras list.  This easier to
	describe in an example than in words so the following would be a good
	example.:
</p>
<pre>	extra {"$get", "statues", "statue"}
	"You attempt to pick up a statue but quickly discover your feeble
	attempts will never work."

	{"$get", "red roses", "roses"}
	"You bend down to pick a rose, but then decide to leave the beautiful
	flower to itself."
</pre>
<p>With this one special extra we have made it so you don't need to
	make millions of items so the person can act upon them.  You can
	just make the acts as if the items were in the room.
</p>
<dl><dt>Exits</dt>
<dd>Every room has ten possible exits; North, East, South, West, Northeast, Southeast, Southwest, Northwest, Up and Down. To enable mobile use of these commands, you must specify these exits as outlined below:</dd></dl>
<pre> exit &lt;direction&gt; [to &lt;destination&gt;] [open {&lt;infoflags&gt;}]
 [key &lt;keyname&gt;] [keyword {&lt;keywords&gt;}] descr &lt;description&gt;&#160;;&lt;/nowiki&gt;
</pre>
<dl><dt>exit &lt;directions&gt;</dt>
<dd>Is the direction the exit leads, ie. one of north, south .. up, down.</dd>
<dt>to &lt;destinations&gt;</dt>
<dd>The symbolic reference to the room, you want this exit to lead to. If you reference a room within another zone, post pend the name with @&lt;zone name&gt;</dd></dl>
<pre> to myotherroom
 to hisotherroom@hiszone&lt;/nowiki&gt;
</pre>
<dl><dt>open &lt;info flags&gt;</dt>
<dd>These flags describe the state of the door.  The following is the list of possible door flags.</dd></dl>
<dl><dt>EX_OPEN_CLOSE</dt>
<dd>Set this if you can open and close this exit, be it a door, gate or otherwise.</dd>
<dt>EX_CLOSED</dt>
<dd>Set this if you want the exit to be closed at boot time.</dd>
<dt>EX_LOCKED</dt>
<dd>Set this if you want the exit to be clocked at boot time.</dd></dl>
	<blockquote style="background-color: #E8E8E8; font-style: italic;">
<p>	An interesting aspect is, if you do not specify a key, you can
	    only unlock this door with the 'pick' skill, 'unlock' spell or from
	    DIL with UnSet();
</p>
		</blockquote>
<dl><dt>EX_PICK_PROOF</dt>
<dd>Using this flag renders the 'pick' skill and 'unlock' spell un useable on the lock of this exit.</dd>
<dt>EX_HIDDEN</dt>
<dd>If this bit is set, the exit is hidden until the mobile has successfully searched for it, using the 'search'-command.</dd>
<dt>key &lt;keyname&gt;</dt>
<dd>The symbolic name of a key object used for unlocking this exit.</dd></dl>
<pre> key mykey@myzone&lt;/nowiki&gt;
</pre>
<dl><dt>keyword { &lt;stringlist&gt; }</dt>
<dd>This stringlist holds all the names of the exit, you specify to manipulate the exit. If the exit is hidden exit, these are the keywords the mobile can search for.</dd></dl>
<pre> keyword {"wooden door","door"}
 keyword {"hidden door","door","hatch","floor"}&lt;/nowiki&gt;
</pre>
<dl><dt>descr &lt;description&gt;</dt>
<dd>This string is the description of what you see if you look in the direction of the exit.</dd></dl>
<dl><dt><dl><dt></dt></dl>
</dt><dd>Every exit statement needs to be terminated with a semi-colon.</dd></dl>
<blockquote style="background-color: #E8E8E8; font-style: italic;">
<h4><span class="mw-headline" id="General_notes">General notes</span></h4>
<p>Even though you do not need an exit in all directions, you can use it to place
	descriptions of the direction.
</p>
	</blockquote>
<pre>	      exit north descr "An unsurmountable mountain blocks your way.";
</pre>
<dl><dt>minv</dt>
<dd>This field is rarely used on rooms.  It could however be used to make a room invisible inside another room.  Or it could be used to store numbered values on a room.  The reason this field is on a room is it is part of the base object which all objects are derived from.  If the room is going to be inside another room and you don't want it visible the following would make it invisible to all players below the level of 20.</dd></dl>
<pre>	minv 20
</pre>
<dl><dt>key</dt>
<dd>This field is not used normally on a room.  It is a string that can be used for anything you desire.  The reason it exists on rooms is it is a part of the base object all unitptrs (unit pointers like,</dd></dl>
<p>	rooms, objects, and NPCs) are derived from.
</p>
<dl><dt>manipulate</dt>
<dd>This field is not used normally on a room.  It is an integer that can be used for anything you desire.  The reason it exists on rooms is it is a part of the base object all unitptrs are derived from.</dd>
<dt>alignment</dt>
<dd>This field is not used normally on a room.  It is an integer that can be used for anything you desire.  The reason it exists on rooms is it is a part of the base object all unitptrs are derived from.</dd>
<dt>weight</dt>
<dd>This field is not used normally on a room.  It is an integer that can be used for anything you desire.  The reason it exists on rooms is it is a part of the base object all unitptrs are derived from.</dd>
<dt>capacity</dt>
<dd>This field is not used normally on a room.  It is an integer that can be used for anything you desire.  The reason it exists on rooms is it is a part of the base object all unitptrs are derived from.</dd>
<dt>light</dt>
<dd>This field sets the light on a room.  Normally this is not done directly, instead it is set using macros defined in</dd></dl>
<p>	<i>wmacros.h</i>.
</p>
<table class="wikitable">
<caption>Light defines
</caption>
<tbody><tr>
<th>Define
</th>
<th>Light Value
</th>
<th>Affect
</th></tr>
<tr>
<td>ALWAYS_LIGHT
</td>
<td>1
</td>
<td>Room is always light no matter time of day
</td></tr>
<tr>
<td>IN_ALWAYS_DARK
</td></tr>
<tr>
<td>When an inside room is always dark - both inside and outside
</td></tr>
<tr>
<td>OUT_DARK_NON_NOON
</td></tr>
<tr>
<td>Always a dark room, except when it is high noon
</td></tr>
<tr>
<td>OUT_ALWAYS_DARK
</td></tr>
<tr>
<td>Always a Dark room, no matter the time of day
</td></tr></tbody></table>
<p>To set natural light that changes depending on the type of day
	nothing is needed to be put in the light field the compiler will default
	to '0'.  If you for some reason want to set the light to default
	lighting you can do so but you don't need to.  You will also notice
	there are two macros that set the light to the exact same value.  This is
	for compatibility with older code base and if you wish to combine these
	two macros or only use one it would not change the way the mud
	works.
</p><p>	This is probably one of the simplest fields you will have to deal
	with in the rooms.  In order to set it all that is needed is to place
	the macro or the light and value on a line in the room and your all
	done.
</p>
<pre>	//To Set always light with macro
	ALWAYS_LIGHT

	//To set Always light with out macro
	light 1
</pre>
<p>You can decide which is easiest for you.
</p>
<dl><dt>link</dt>
<dd></dd>
<dt>spell</dt>
<dd></dd>
<dt>dilbegin or dilcopy</dt>
<dd>The DIL functions are what give VME servers the edge over all other muds.</dd></dl>
<p>	We will only give some examples here and leave it up to the DIL manual to teach
	you how to create your own functions that will make your rooms, NPC, and
	objects more than special.
</p><p>	There are only currently three room functions that come
	standard with a VME in the <i>function.zon</i>.  There
	are much more in the zones released with the VME but you
	will have to hunt for those.  The three that come standard are Safe
	room, Death room, and forced move.  The safe room makes it
	impossible for players to kill each other, the death room is a
	function that lets you make things like rock slides and quick sand,
	and the forced move lets you make an easy river.
</p><p>	Since these are just DIL's written by builders for the
	Valhalla mud all you have to do is use the dilcopy keyword in the
	room with the function name you want to use and the arguments the
	function requires.  The following is what you would find in the
	<i>function.zon</i> for death room.
</p>
<pre>	/* Death room DIL
		*tick is in 4th's of seconds
		* Damage is damage done per tick
		*act_s is string shown to damaged player.
	 */
	dilbegin death_room(tick: integer, damage: integer, act_s: string);

	var ext: extraptr;
	    u  : unitptr;
	    i  : integer;

	code
	{

	if (tick &lt; 12) tick := 12;

	heartbeat := tick;

	if (damage &lt; 0)
	    damage := -damage;

	if ("$death room for mobs" in self.extra)
	    i := UNIT_ST_PC|UNIT_ST_NPC;
	else
	    i := UNIT_ST_PC;

	while (TRUE)
	{
	wait (SFB_TICK, TRUE);

	foreach (i, u)
	    {
	    if (u.level &gt;= IMMORTAL_LEVEL)
	        continue;

	    if (("$no death room" in u.extra) and (u.type == UNIT_ST_NPC))
	        continue; // Don't allow pcs to get this flag

	    if (act_s != "")
	        act ("&amp;[hit_me]"+act_s, A_ALWAYS, u, null, null, TO_CHAR);
	    else
	        act ("&amp;[hit_me]You bleed from your wounds.",
	            A_ALWAYS, u, null, null, TO_CHAR);

	    u.hp := u.hp - damage;
	    position_update (u);
	    }

	}

	}

	dilend
</pre>
<p>If this DIL function scares you don't worry you don't have to
	understand or adjust it you just have to use it.  In this function it requires a time,
	damage, and act.  So you could use this in a room definition like
	this:
</p>
<pre>	dilcopy death@function (60,25,"Flames shoot from the floor burning
	your rear.");
</pre>
<p>This says to copy the DIL from zone function with the arguments 60
	seconds, damage 25% and act as shown.  Pretty simple eh?
</p><p>	All released DIL room functions are described in
	(Link to rmdilfunc).
	Then we put some to work so you can see how
	to use them in (Link to rmcomplex)
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-Unit-Building-Blocks" title="Manual:Zone Manual/Unit Building Blocks">Previous: Unit Building Blocks</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section-Building-your-first-room" title="Manual:Zone Manual/The Room Section/Building your first room">Next: Building your first room</a></div></div>