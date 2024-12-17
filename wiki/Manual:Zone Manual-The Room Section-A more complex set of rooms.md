<div class="mw-parser-output"><div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1 tocsection-1"><a href="#A-more-complex-set-of-rooms"><span class="tocnumber">1</span> <span class="toctext">A more complex set of rooms</span></a>
<ul>
<li class="toclevel-2 tocsection-2"><a href="#Exits-with-doors"><span class="tocnumber">1.1</span> <span class="toctext">Exits with doors</span></a></li>
<li class="toclevel-2 tocsection-3"><a href="#Locked-.26-Hidden-Exits"><span class="tocnumber">1.2</span> <span class="toctext">Locked &amp; Hidden Exits</span></a></li>
<li class="toclevel-2 tocsection-4"><a href="#Locked-exits"><span class="tocnumber">1.3</span> <span class="toctext">Locked exits</span></a></li>
<li class="toclevel-2 tocsection-5"><a href="#Hidden-exits"><span class="tocnumber">1.4</span> <span class="toctext">Hidden exits</span></a></li>
<li class="toclevel-2 tocsection-6"><a href="#Rooms-inside-of-rooms"><span class="tocnumber">1.5</span> <span class="toctext">Rooms inside of rooms</span></a></li>
<li class="toclevel-2 tocsection-7"><a href="#A-room-using-force-move."><span class="tocnumber">1.6</span> <span class="toctext">A room using force move.</span></a></li>
<li class="toclevel-2 tocsection-8"><a href="#A-death-room"><span class="tocnumber">1.7</span> <span class="toctext">A death room</span></a></li>
</ul>
</li>
</ul>
</div>

<h3><span class="mw-headline" id="A_more_complex_set_of_rooms">A more complex set of rooms</span></h3>
<p>	In the last section you learned to make basic rooms.  In this
	section we will build on what you already know to allow you to make much
	more fancy rooms.  In this section we will give a much better view of
	the exits and what can be done with them including doors, hidden doors and
	rooms inside other rooms.  We will also show some examples of the room
	DIL functions being used that were described in the previous section.
	Finally we will pull it all together in a completed zone for you to
	compile and play with.
</p>
<h4><span class="mw-headline" id="Exits_with_doors">Exits with doors</span></h4>
<p>	When we first defined exits we included the 'keyword' and 'open'
	fields on a door.  In this section we will give an example of two rooms
	linked together with a door.  There is no new information you have
	not already encountered so we will start with an example.
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
<pre>      One important thing you should notice is, whatever you put as a keyword, 
      along with the direction, is what a person must use to open the door. 
      So make sure there is something in the description or extra that the player 
      can use to discern the correct search term. <br />
</pre>
<p>To make sure the door closes at reset time you will have to add the doors reset to the '%reset' section.  The door resets will be explained in (Link to ch-07).  Notice also in this example we have a direction both in the room you are going to and the room you came from.  This means you need a 'west' direction for every 'east' direction leading to it.  If you do not put both you will end up with a one way direction.
</p>
<h4><span id="Locked_&amp;_Hidden_Exits"></span><span class="mw-headline" id="Locked_.26_Hidden_Exits">Locked &amp; Hidden Exits</span></h4>
<p>An update to the old method of handling searching for hidden doors &amp; picking doors has been made. What was once done individually between hidden &amp; locked doors is now a 'difficulty' rating. This rating will apply to picking locks as well as searching rooms but they will actually call upon the PC's skills and abilities.
</p><p><br />
In our zone, we will denote it like so:
<br />
</p>
<pre>        northeast to aroom
	descr "A small room."
	key key@zone
	keyword {"door"}
	open {EX_OPEN_CLOSE, EX_CLOSED, EX_LOCKED}
	difficulty 10;
</pre>
<p><br />
</p><p>An example of how you apply the same concept to a container would be:<br />
<code>open {EX_OPEN_CLOSE, EX_CLOSED, EX_LOCKED} difficulty 10 </code>
</p><p><br />
</p><p>See this for more information on how the skill and ability levels work:<br />
<a href="./Manual:Game-Mechanics-Skills" title="Manual:Game Mechanics/Skills">Manual:Game Mechanics/Skills</a>
</p>
<h4><span class="mw-headline" id="Locked_exits">Locked exits</span></h4>
<p>	Now that you have making a door down, you may find that it is not
	safe to leave your doors unlocked.  Well the VME is ready for you.  You
	have already seen the 'keyword' and 'open' sections and what you can set
	in them.  Now lets use the 'EX_LOCKED' field with them and introduce a difficulty rating. Generally speaking a rating of 0 is very easy and a rating of 100 is very difficulty. 
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
	key nokey
	open {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED}
        difficulty 10;

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
	key nokey
	open {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED}
        difficulty 10;
	end
</pre>
<p>The only thing you may be wondering about in this example is the
	'key' field.  I have picked 'nokey' as my value of the key.  There is no
	key in this zone so all this does is create a key hole.  If you leave
	the 'key' field out totally the only way you can open the lock is by a
	magical spell.  It is also important that you read about resets of door locks in
	(Link to ch-07).
</p>
<h4><span class="mw-headline" id="Hidden_exits">Hidden exits</span></h4>
<p>	Locking the doors may not be enough.  In fact sometimes you may
	not want to lock the door but you might want to hide it.  You will denote the hidden doors in much the same way you do above, with the difficulty rating. However, you will also have to give those exits a name or something to search for with the keywords name list.
</p>
<pre>	office
	title "The station office"
	descr
	"Large paintings fill the walls of this part of the station..."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	west to hallway descr
	"You see what looks to be a hallway."
	keyword {"air lock door","air lock","door"}
	open {EX_OPEN_CLOSE, EX_CLOSED};

	south to portal_room descr
	"You see what looks to be a portal room."
	keyword {"air lock door","air lock","staff","door"}
	key nokey
	open {EX_OPEN_CLOSE, EX_CLOSED, EX_LOCKED, EX_HIDDEN}
        difficulty 10;
	end

	portal_room
	title "Green field room"
	descr
	"Like the other rooms on the station this one is large enough for
	dragons to comfortably fit in.  The strange thing about this room though
	is it is totally empty except for a green field right in the center.
	there is a door that leads to another room to the north."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}
	north  to office descr
	"You see what looks to be an office."
	keyword {"air lock door","air lock","door"}
	key nokey
	open {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED}
        difficulty 10;
	end
</pre>
<h4><span class="mw-headline" id="Rooms_inside_of_rooms">Rooms inside of rooms</span></h4>
<p>	Now that you have normal exits down its time to take a look at
	something a bit different.  Lets say you wanted to put a barrel in a
	room that is also a room that has exits to other rooms.  Or maybe in my
	case I want to put a transporter pad in the room that is also a room
	so you can exit back into the room you came from.  In the case of the
	teleporter I could use an object but as you will find it is much easier
	to deal with a room for this than an object.
</p><p>	To put a room in a room it is much different than using the normal
	exit fields.  The only thing needed is the 'in' keyword and the
	room you are linking the current room into. There is no need for a
	semi-colon.  The following is what the line would look like.
</p>
<pre>	in &lt;room that room is in&gt;
</pre>
<p>Not too hard.  The following are two rooms one in the other.
</p>
<pre>	portal_room
	title "Green field room"
	descr
	"Like the other rooms on the station this one is large enough for
	dragons to comfortably fit in.  The strange thing about this room though
	is it is totally empty except for a green field right in the center.
	there is a door that leads to another room to the north."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	extra {"green field","field"}
	"The field looks to be a green fog shifting and churning as you watch.
	if you are nuts you could probably enter it."

	north  to office descr
	"You see what looks to be an office."
	keyword {"air lock door","air lock","door"}
	key nokey
	open {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED};

	//A link to the portal is also here
	end

	room_port
	names{"green field", "field"}
	title "Green field"
	descr
	"Green Mist swirls about you."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	in portal_room
	end
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;">
<p>	After adding a room in a room you should note the room in the
	description or put an 'outside_descr' on the room inside it.  In
	our example we have chosen to add the description into the room instead
</p><p>
	of using the 'outside_descr'.  Also doors and locks work the same way as before you can even hide this exit.</p></blockquote>
<h4><span class="mw-headline" id="A_room_using_force_move.">A room using force move.</span></h4>
<p>			  Sometimes you will want to help players along
	their path.  This could be for a river that flows strongly enough to
	force a players raft down stream or maybe for a room of quick sand that
	sucks the player into another room.  In these situations we need to use
	the force move DIL, explained in the previous section.  Here we
	have built two rooms linked only by a forced move.
</p>
<pre>	portal_room
	title "Green field room"
	descr
	"Like the other rooms on the station this one is large enough for
	dragons to comfortably fit in.  The strange thing about this room though
	is it is totally empty except for a green field right in the center.
	there is a door that leads to another room to the north."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	extra {"green field","field"}
	"The field looks to be a green fog shifting and churning as you watch.
	if you are nuts you could probably enter it."

	north  to office descr
	"You see what looks to be an office."
	keyword {"air lock door","air lock","door"}
	key nokey
	open {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED};

	//A link to the portal is also here

	end
	ship_port
	names{"green field", "field"}
	title "Green field"
	descr
	"Green Mist swirls about you."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	in ship

	dilcopy force_move@function(
	//Time to activation
	4,
	//room and act
	"portal_room@dragonst!You feel your body dissolving for lack of a better
	description.&amp;nYou appear on the deck of a ship.",
	//True or False for randomizing or not
	FALSE);

	end
</pre>
<h4><span class="mw-headline" id="A_death_room">A death room</span></h4>
<p>	As a final touch to my little example zone I want to create a
	room that will kill a player instantly.  I will use the DIL function
	Death room and the room would simply look as follows.
</p>
<pre>	deathspace
	title"Open space"
	descr
	"You see the ship and the station far off in the distance and you are in Space!"

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	dilcopy death_room@function (
	//how often is damage done 4 would be 1 second
	4,
	//damage
	400,
	//act for the damage.
	"You realize	 to late that was the trash disposal transporter and you feel your lungs explode.");

	end
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section-DIL-functions-for-rooms" title="Manual:Zone Manual/The Room Section/DIL functions for rooms">Previous: DIL functions for rooms</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section-Putting-the-rooms-together" title="Manual:Zone Manual/The Room Section/Putting the rooms together">Next: Putting the rooms together</a></div></div>