<div class="mw-parser-output"><h2><span class="mw-headline" id="Unit_building_blocks">Unit building blocks</span></h2>
<p>		When creating your zone you will find some basic
		structures are used in all three unit types rooms, objects, and
		NPCs. In this chapter we will define the main building blocks of
		all units along with some helpful hints
</p><p>		No matter which unit type you are dealing with there is a
		simple basic structure that lets the compiler know not only what
		unit type it is dealing with but where one unit begins and where it
		ends.  The way the compiler tells what unit type it is dealing with
		is by the section header '%rooms', '%objects', and '%mobiles'.  All
		rooms must be defined under the '%rooms' header and likewise objects
		and NPCS under their respective headers.  Each unit starts with a
		symbolic name called the unit symbol and ends with the keyword
		end.  The following would be a legal definition of any
		unit type:
</p>
<pre>	symbol_name
	end
</pre>
<p>If you define a unit like this when it loads it will be blank, while
		this is not	 extremely useful it is good to know you can leave
		out any field you don't feel you need.
</p>
<h4><span class="mw-headline" id="Unit_building_blocks_2">Unit building blocks</span></h4>
<dl><dt>symbol field</dt>
<dd>In the last chapter we defined the different field types and the rules you must follow when defining a symbol.  It is important enough to relist these rules here so you do not run into problems when creating your units.</dd></dl>
<ul><li>The first letter of the</li></ul>
<p>		symbol must be a letter of the alphabet or a '_' character
</p>
<ul><li>Characters following the first can be numbers, alphabet</li></ul>
<p>		letters, and '_' characters
</p>
<ul><li>The symbol can be no longer than</li></ul>
<p>		15 characters
</p>
<ul><li>No reserved keywords can be used as a symbol(Link to app-b)</li></ul>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>It is also important to know currently it is hard to deal with units having capital letters in them, this may be fixed in the future but it is good practice to use all lower case characters in the symbols.</p></blockquote>
<p>		Another thing you should think about when defining your symbol
		names is to be clear about what the unit is.  When you list units on
		the VME server with <b>wstat</b> the symbolic names are
		shown
		if you were to see the list:
</p>
<pre>i6853 b2419 l1854
</pre>
<p>You would have no idea what those three items were unless you
		personally built them recently, therefore it is a much better coding
		practice to name things what they are like:
</p>
<pre>long_sword healer_hut dog
</pre>
<dl><dt>title field</dt>
<dd>The title field is probably the easiest field on all units it is what is shown on the first line of a room when you enter and it is the name shown when you get an object or attack a NPC.</dd></dl>
<p>		There is only two important things to look at when defining titles
		one is punctuation and the other is capitalization.  Room titles
		need to be capitalized and so do proper names but the first letter of an object
		title or a NPC title do not normally need to be capitalized. this is
		best explained by some examples.
</p>
<pre>	title "The dragons in."/*good*/
	title "a big bull dog."/*bad has a period at the end*/
	title "Bill the destroyer"/*good*/
	title "A long dagger"/*bad capital 'a'*/
</pre>
<p>Now to show why some of those are good we will demonstrate by some
		sample output in the game.
</p>
<pre>prompt:  l
		The Dragons Inn
		You are standing in a moldy inn.

		prompt: get A long dagger
		You get A long dagger.

		prompt kick dog
		You kick a bull dog. in the head.
</pre>
<p>Notice the 'A' and the extra period do not really look right where
		they end up appearing in the game.  These may be minor nit picky
		details but if you do it right the first time you won't have to deal
		with the english major that just happens to be playing on your
		mud.
</p>
<dl><dt>names field</dt>
<dd>The 'names' field defines the names everything in the game can use to interact with your unit.  For rooms the names are used as teleport or goto points for characters and NPCs or they are sometimes	used for special DIL functions on objects to trigger in certain rooms.  On NPCs and objects names can be used for anything from poking a player to giving a player an object.  The names field is very flexible it has even been used to store what a container is holding in order to have quick access to the names in the container.</dd></dl>
<p>		When making rooms it is not necessary to put room names.  In
		fact it is a good way of making sure players can't teleport to
		certain rooms because if the room doesn't have a name the person
		can't teleport to it.  Objects and NPCs must have names because if
		you leave names off of them you can not pick them up or kill them
		depending on which you are dealing with.  It is also good practice
		to use all combinations of the object or NPCs title so a
		player will know exactly what to type to use the item for example:
</p>
<pre>	bad_obj
	title a small dog"
	names{"small dog","small","dog"}
	end
</pre>
<p>It is up to you as a builder if you want to use names like 'small'
		in your names list since you would not 'get small' in real life it
		may not have to be added to the names list.  It is important however
		to define your extras from big to small because of how the VME
		command interpreter handles names of things.  For example if you had
		the following names:
</p>
<pre>	small_item
	title "a small item"
	names {"small","item","small item"}
</pre>
<p>When you try to <b>give small item Bill</b>.  The interpreter
		would try to give
		small to item and that would not be what you wanted to do.  Don't
		worry the compiler will catch this and give you an error something
		like:
</p>
<pre>Fatal name ordering on line ###.
</pre>
<dl><dt>descr field</dt>
<dd>The description building block is used in many places.  You will find description fields on extras, exits, rooms, NPCs, objects, and as you have already seen the help and the notes field of the zone information section are also description fields.</dd></dl>
<p>		  Depending on what
		you are working on description fields can mean totally different
		things to the person looking in the room.  A description field on a
		room can be the inside or outside of the rooms description.  A
		description on extras can be an NPCs descr or an extra description
		on the room like if you looked at a 'rug' or a 'chair'.  On an exit
		the descr field describes what you see when you look in that
		direction from the room you are in.  The important thing right now
		is no matter where you use them they all work the same.
</p><p>		description fields like the title field have a tag or unlike
		the title field can have a set of tags before them like in extras or
		exits but like titles they are just a string surrounded by quotes.
		You can make multiple line descriptions if the description is on a
		NPC you may not want to since it is the description shown when you
		walk into the room.  The following would be some examples of room descriptions.
</p>
<pre>	descr
	"this is how you would define a room descr and as you can see it can
	be much longer than a line if you like."

	extra {"basic extra"}
	"This is a description field on an extra."

	extra{"more advanced","extra"}{1,2,3,4,5,6}
	"This is still the description field.  Like the room description or
	any description field for that matter this can be longer than a
	line."

	east to bathroom descr
	"You see one big toilet!";
</pre>
<dl><dt>extra fields</dt>
<dd>The extra field is the work horse for the builder.  It is the building block that most brings your zone to life.  You can use it to describe body parts or items in a room.  When you use DIL you will use extras to store information like quest information or special information you need later.  Extras also store the main description on NPCs since the descr field on NPCs is really the long title shown in the room which will be explained later in (Link to ch-05).</dd></dl>
<p>		The extra Is the first structure definition you have run into
		so it may take some playing with to figure it out.  The extra has
		actually 4 fields three of them must be there in some form.  The
		first is the identifier that tells the compiler that this is an
		extra, the second is a stringlist, the third is an Optional
		Intlist, and the final one is the extra description field.  If the extra
		had all the fields it would look like this:
</p>
<pre>	extra {"small chair","chair"} {1,2,3,4,5} "Its a chair."
</pre>
<p>If the previous wasn't an example we
		would have left out the Intlist because it is not necessary to put
		the Intlist on a chair unless you want it there for some special DIL
		you are creating. the Intlist is the only field that can be totally
		left out but you can leave the string list blank when you want
		to make the extra the default description when the object, room, or
		NPC is being looked at, like this:
</p>
<pre>	extra {}
	"This would be what you see when you look at any of the names in the
	names list."
</pre>
<p>We will go more in-depth into why you want to do this in the
		following chapters.
</p><p>You are now ready to put these building blocks to work.  You have only
		to learn how to put these fields to work for each of the three unit
		types and you will be off and running.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-Zone-Source-File-Zone-information-section" title="Manual:Zone Manual/Zone Source File/Zone information section">Previous: Zone information section</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section" title="Manual:Zone Manual/The Room Section">Next: The Room Section</a></div></div>