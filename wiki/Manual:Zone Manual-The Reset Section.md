<div class="mw-parser-output"><h2><span class="mw-headline" id="The_reset_section">The reset section</span></h2>
<p>	Once you have learned to build rooms, objects and NPCs, you will
	find one main missing thing, while you have created NPCs and objects
	they don't exist in the game unless you load them.  When developing the
	VME we found that logging on and loading everything for the players to
	interact with, became a very difficult thing to do when we got over 30
	items.  After many seconds of thought we came up with the idea of a
	reset section that would do all of this work for us.  In fact the reset
	takes care of closing doors after players have opened them, loading NPCs
	and their equipment, loading objects by themselves in rooms or even
	loaded objects in objects.
</p><p>	Everything inside the reset section activates once at boot time and
	then again when the reset time is up and the reset flag is true.  These
	two fields were described in (Link to zoneinfo) and are included
	in the zone header.  The reset section is denoted by the symbol '%reset' and can placed
	anywhere but we try to keep it at the end of our zone files.  There is
	no set order you must reset your doors, objects, and NPCs in but I like
	to do doors first, special reset commands second, objects in rooms third, objects with objects in them
	forth, NPCs fifth,
	and finally NPCs.  You may find that you have a better way of sorting
	them and again it is up to you.
</p>
<h3><span class="mw-headline" id="Door_resets">Door resets</span></h3>
<p>	To show how the door resets work we will revisit an old room
	example from (Link to rmdoorexits). The following two rooms are
	linked with a door and at boot time they are reset to closed.  When the
	mud boots the door flags set on the room are the door flags that are
	used.  After boot up time the reset section is where the VME gets its
	information about what to do with the door.
</p>
<pre>	hallway
	title "Module tunnel"
	descr "The hallway is about 50 meters long and around 100 meters from
	side to side and top to bottom...."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	west to chamber descr
	"The hallway opens up into a chamber.";

	east to office descr
	"You see what looks to be an office."
	keyword {"air lock door","air lock","door"}
	open {EX_OPEN_CLOSE, EX_CLOSED};

	end

	office
	title "The station office"
	descr
	"Large paintings fill the walls of this part of the station...."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	west to hallway descr
	"You see what looks to be a hallway."
	keyword {"air lock door","air lock","door"}
	open {EX_OPEN_CLOSE, EX_CLOSED};
	end
</pre>
<p>Now that we have two rooms lets define the reset command and how
	it works.  All reset commands have a keyword and then a set of
	arguments.  The door reset command is simply 'door' followed by a set of
	arguments that tell the VME where the door is, which door in that
	location, and what you want to do with the door.  The command looks like
	this.
</p>
<pre>	door &lt;room symbol&gt; &lt;Direction number&gt; {&lt;door flags&gt;}
</pre>
<h4><span class="mw-headline" id="Door_argument_explanation">Door argument explanation</span></h4>
<dl><dt>room symbolic</dt>
<dd>As the name indicates this is the room that the door is located in.  If you are resetting a door not in the zone the reset command is in you will need to use a full symbolic name with the zone extension.  The following would be two valid examples.</dd></dl>
<pre>	//room symbolic in  this zone
	door myroom ...

	//room symbolic in another zone
	door out_room@frogwart ...
</pre>
<dl><dt>direction number</dt>
<dd>The direction number can be one of the pre-defined direction numbers in the file <i>vme.h</i>.  shown here so you don't have to go flipping file to file.</dd></dl>
<pre>	#define NORTH 0
	#define EAST  1
	#define SOUTH 2
	#define WEST  3
	#define UP    4
	#define DOWN  5
	#define NORTHEAST 6
	#define NORTHWEST 7
	#define SOUTHEAST 8
	#define SOUTHWEST 9
</pre>
<dl><dt>door flags</dt>
<dd>These flags, surrounded by '{}', describe the state of the door after the reset.  The following is the list of possible door flags.</dd></dl>
<dl><dt>EX_OPEN_CLOSE</dt>
<dd>Set this if you can open and close this exit, be it a door, gate or otherwise.</dd>
<dt>EX_CLOSED</dt>
<dd>Set this if you want the exit to be closed at reset time.</dd>
<dt>EX_LOCKED</dt>
<dd>Set this if you want the exit to be locked at reset time.</dd></dl>
	<blockquote style="background-color: #E8E8E8; font-style: italic;">
<p>	An interesting aspect is that if you do not specify a key, you can
	    only unlock this door with the 'pick' skill, 'unlock' spell or from
	    DIL with UnSet();
</p>
		</blockquote>
<dl><dt>EX_PICK_PROOF</dt>
<dd>Using this flag renders the 'pick' skill and 'unlock' spell un useable on the lock of this exit.</dd>
<dt>EX_HIDDEN</dt>
<dd>If this bit is set, the exit is hidden until the mobile has successfully searched for it, using the 'search'-command.</dd></dl>
<p>Now that we have all the information we need we can close the door
	after the reset time expires.  For our two rooms the door reset would
	look like this.
</p>
<pre>	door hallway EAST {EX_OPEN_CLOSE, EX_CLOSED}
	door office WEST {EX_OPEN_CLOSE, EX_CLOSED}
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>As you can see from the example it is very important to close both sides of the door.  If you do not close both sides you will get very weird and undefined errors when players are trying to open and close them</p></blockquote>
<p>	Another thing that you can do with the door reset command is
	change the doors status.  In our previous example we reset the door to
	its status that it has when it first is loaded into the game.  If
	however we wanted to change the door to a locked door we could do that
	by adding the locked flag like this:
</p>
<pre>	door hallway EAST {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED}
	door office WEST {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED}
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section-Suggested-object-exercises" title="Manual:Zone Manual/The Objects Section/Suggested object exercises">Previous: Suggested object exercises</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Reset-Section-Loading-objects-and-NPCs" title="Manual:Zone Manual/The Reset Section/Loading objects and NPCs">Next: Loading objects and NPCs</a></div></div>