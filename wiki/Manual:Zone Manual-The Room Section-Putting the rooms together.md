<div class="mw-parser-output"><h3><span class="mw-headline" id="Putting_the_rooms_together">Putting the rooms together</span></h3>
<p>	Using all you have learned so far and putting it all together into
	one zone.  You end up with a very interesting space station with some
	secret rooms and traps..  The full zone all together looks like
	this.
</p>
<pre>	#include &lt;composed.h&gt;
	%zone dragonst
	lifespan 20
	reset RESET_ANYHOW
	creators {"whistler"}

	notes
	"This is the dragon station I shortened it to dragonst for ease in
	loading.  If you have  any questions email me at whistler@valhalla.com"

	help
	"Not sure what could help you now.  You are stuck on one of the
	weirdest space stations you have ever seen and you smell burning
	sulfur."

	%rooms

	chamber
	title "The middle chamber of the station"
	descr
	"This chamber seems to have the entire station rotating around it.  It is
	unbelievably large the ceiling seems to be a good 200 meeters high and
	the room is perfectly cubic. Small human size ornate chairs with dragon
	designs scrawled on the arms and back are arranged in a triangle like
	setting with one large chair at the front.  This must be where all
	station meetings are held. large pictures cover the walls depicting
	dragons in all kinds of situations.  large passages lead of to the west
	and the east.."

	extra {"chair","chairs"}
	"The chairs are made of some metal you don't recognize and every inch is covered
	with some kind of dragon."

	extra  {"dragon picture","picture"}
	"Thousands of dragons dot the skies of this rather life like picture.  In the
	center you see something move.  It looks to be a little green dragon."

	extra{"green dragon","dragon","green"}
	"An intellegence looking dragon is sitting perched on a large chair watching you."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	west to disposal_room descr
	"You see a small room.";

	east to hallway descr
	"You see what looks to be a hallway.";

	end

	hallway
	title "Module tunnel"
	descr "The hallway is about 50 meters long and around 100 meters from
	side to side and top to bottom.  The hallway seems to be dust free.  The
	walls and the floors seem to be made out of the same sterile
	metal-plastic that all space agencies uses.  There are large plate glass
	windows that open up into space.  The hallway is filled with a dim light
	that seems to come from everywhere yet no where all at once.  You notice
	a glimmer of bright light coming from the windows.  To the east you see
	an air lock and to the west the hallway opens up into a larger room."

	extra {"windows","window"}
	"Your eyes are drawn to a large ship lit up with running lights sitting
	about 1 kilometer from the station."

	extra{"floor","walls","wall"}
	"Well what can be said it looks to be in perfect condition.  what else would you want to know?"

	extra {"large ship" ,"ship"}
	"The ship looks really big and is shaped like a dragon.  The scales
	sparkle and seem to be multiple colors."

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
	"Large paintings fill the walls of this part of the station.  The room
	is as large as the other rooms big enough for Dragons to lounge while
	still having a desk in one corner small enough for a humanoid.  The
	floor along the north wall is lined with some kind of fabric and seems very soft to
	walk on, it may be some kind of dragon lounge judging by how large an
	area it covers.  There is a passage to the west."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	extra {"paintings","painting"}
	"The paintings are of many dragons and riders in all kinds of tasks from
	combat to look out.  All the figures seem to be staring at a staff
	being held by a depiction of a wizard on the south wall."

	extra {"wizard","staff"}
	"The wizard has his hand stretched out and it seems there is a place
	you can almost grab the staff. Maybe if you searched the staff you would
	find it."

	extra {"desk"}
	"Its a desk alright but there doesn't seem to be any drawers and it
	seems totally empty."

	extra{"fabric"}
	"Wussshhhhh you bound across the comfortable floor wasn't that fun."

	west to hallway descr
	"You see what looks to be a hallway."
	keyword {"air lock door","air lock","door"}
	open {EX_OPEN_CLOSE, EX_CLOSED};
	south to portal_room descr
	"You see what looks to be a portal room."
	keyword {"air lock door","air lock","staff","door"}
	key nokey
	open {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED,EX_HIDDEN}
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

		extra {"green field","field"}
		"The field looks to be a green fog shifting and churning as you watch.
		if you are nuts you could probably enter it."

		north  to office descr
		"You see what looks to be an office."
		keyword {"air lock door","air lock","door"}
		key nokey
		open {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED}
                difficulty 10;;

		//A link to the portal is also here from room_port
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

	room_port
	names{"green field", "field"}
	title "Green field"
	descr
	"Green Mist swirls about you."
	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	in portal_room

	dilcopy force_move@function(
	//Time to activation
	4,
	//room and act
	"ship@dragonst!You feel your body dissolving for lack of a better
	description.&amp;nYou appear on the deck of a ship.",
	//True or False for randomizing or not
	FALSE);

	end

	disposal_room
	title "Red field room"
	descr
	"Like the other rooms on the station this one is large enough for
	dragons to comfortably fit in.  The strange thing about this room though
	is it is totally empty except for a red field right in the center.
	there is a door that leads to another room to the east."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	extra {"red field","field"}
	"The field looks to be a red fog shifting and churning as you watch.
	if you are nuts you could probably enter it."

	east to chamber descr
	"You see the main chamber.";

		//A link to the portal is also here from dis_port
	end

	dis_port
	names {"red field","field"}
	title "Red field"
	descr
	"Red Mist swirls about you."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}
	dilcopy force_move@function(
	//how fast to force move in seconds
	4,
	//room to force move to and act
	"deathspace@dragonst!You feel your body dissolving for lack of a better description.",
	//true or false random move or not
	0);
	in disposal_room

	end

	ship
	title "War dragon"
	descr
	"Blue light softly glows from con duets that line the walls of this ship.
	The floors beside the east and west wall have what looks to be soft
	fabric covering.  The south wall has small controls that seem to be made
	for humanoids with two small chairs that look to be pilot seats.  view
	portals are about 50 meters up the side of the ship on the west and east
	wall and some kind of electronic screen covers the south wall.  The ship
	seems to be a one room ship but there is a green field by the north
	wall."

	movement SECT_INSIDE
	ALWAYS_LIGHT
	flags {UNIT_FL_NO_WEATHER, UNIT_FL_INDOORS}

	extra {"view port"}
	"Sorry your not 50 meters tall maybe it is made for a dragon?"

	extra {"view screen","screen"}
	"It seems to be the pilots view screen but you can't seem to see a way
	to turn it on."

	extra {"controls","control"}
	"The controls are in some weird language and your afraid if you start
	pushing buttons you might rocket in to the station or worse slam into
	a planet."

	extra {"soft fabric","fabric"}
	"It looks to be a dragon lounge area."

		//A link to the portal is also here from ship_port
	end

	deathspace
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

	%end
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section-A-more-complex-set-of-rooms" title="Manual:Zone Manual/The Room Section/A more complex set of rooms">Previous: A more complex set of rooms</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section-Suggested-room-exercises" title="Manual:Zone Manual/The Room Section/Suggested room exercises">Next: Suggested room exercises</a></div></div>