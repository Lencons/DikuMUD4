<div class="mw-parser-output"><h2><span class="mw-headline" id="The_objects_section">The objects section</span></h2>
<p>	The previous chapters would be enough for you to create an entire
	game of nudists with no technology and no items of any kind.  This of
	corse would be a very boring game of naked people fighting with no
	weapons.  don't worry the VME has a solution to this you can build
	objects to dress up the NPCs and to fill the rooms with cluttered
	junk.
</p><p>	In order to get started building objects you should first be aware
	of the object fields you can use.  The (Link to objfields) shows a full listing
	of all the object fields and their types as defined in (Link to ch-03).
</p>
<table class="wikitable">
<caption>Object fields and types
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
<td>affect
</td>
<td>affect function
</td></tr>
<tr>
<td>names
</td>
<td>Stringlist
</td>
<td>dilbegin or dilcopy
</td>
<td>function pointer
</td></tr>
<tr>
<td>title
</td>
<td>String
</td>
<td>key
</td>
<td>String
</td></tr>
<tr>
<td>descr
</td>
<td>String
</td>
<td>open
</td>
<td>Integer
</td></tr>
<tr>
<td>inside_descr
</td>
<td>String
</td>
<td>manipulate
</td>
<td>Integer
</td></tr>
<tr>
<td>extra
</td>
<td>Structure
</td>
<td>spell
</td>
<td>Integer
</td></tr>
<tr>
<td>minv
</td>
<td>Integer
</td>
<td>value
</td>
<td>Integer
</td></tr>
<tr>
<td>alignment
</td>
<td>Integer
</td>
<td>cost
</td>
<td>Integer
</td></tr>
<tr>
<td>flags
</td>
<td>Integer
</td>
<td>rent
</td>
<td>Integer
</td></tr>
<tr>
<td>weight
</td>
<td>Integer
</td>
<td>type
</td>
<td>Integer
</td></tr>
<tr>
<td>capacity
</td>
<td>Integer
</td>
<td>end tag
</td>
<td>Symbol
</td></tr>
<tr>
<td>light
</td>
<td>Integer
</td>
<td>
</td>
<td>
</td></tr></tbody></table>
<p>Many of the same fields you found in rooms and NPCs, as you can see from
	(Link to objfields), can also be found in objects.  The fields do
	not always have exactly the same use when coding rooms, NPCs, and
	objects but they are normally set in the same manor.  It is very
	important that you read and understand the differences of each field as
	they pertains to rooms, objects, and or NPCs.
</p>
<h3><span class="mw-headline" id="Description_of_object_fields">Description of object fields</span></h3>
<dl><dt>symbolic name</dt>
<dd>The rules of the symbols has been explained in</dd></dl>
<p>	(Link to ch-03), if you didn't read them yet you may want to review.
	 The important thing to realize with the object symbol is it is always
	 good practice to give the object a symbol that resembles the title and
	 description so administrators and builders can use the
	 <b>load</b> and the <b>wstat</b> to easily
	 locate, examine, and load the object in question.
</p>
<dl><dt>title</dt>
<dd>The object title is what is shown if the object is being picked up, dropped, given to someone, when you do the inventory command, , or being used in combat.</dd></dl>
<p>	there should be no punctuation in the object title
	because of how it is used in the VME server.  If you add punctuation or
	forget to capitalize something that the VMC thinks you should it will
	give you a warning when you compile. The following are good examples of
	an object title.
</p>
<pre>	title "a big rock"
	title "the flame tongue"
	title "a lap top"
	title "a garbage bag"
	title "an oval hover car"
</pre>
<dl><dt>descr</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>The description field is what the player sees when walking into the room
	or when looking with no arguments.  It is good practice to make this no
	longer than one line not counting the 'descr' tag.
</p><p>	Some examples of the object description field would be as
	follows:
</p>
<pre>	descr
	"a green bloody sword is laying here."

	descr
	"A massive wooden round table sits here."

	descr
	"a funny looking hammer is laying here."
</pre>
<dl><dt>names</dt>
<dd>The object names are as important as the NPC names.  They are what you act on when picking the object up, dropping it, throwing it, just about anything you do to objects use these name fields.  On drink containers you add the liquid name at the end, so people can drink the liquid.  You always need to make sure you put every possible name that the player may use to examine or take your item.  The rule of thumb is if it is in the title or description it should be in the names list.  conversely if it is not in the title or description it shouldn't be in the names list because the players will not use it if they don't know about it.</dd></dl>
<p>	The following is some examples of good 'names' fields with respect to
	        their 'title' and 'descr'.
</p>
<pre>	title "a big rock"
	descr "a big rock is here blocking the road."
	names {"big rock","rock"}

	title "an old twisted staff"
	descr "An old twisted staff has been discarded here."
	names{"old twisted staff","twisted staff","old staff","staff"}
</pre>
<p>The idea of course is to make any combination that a player may
	type to try and act upon your object.  You would not want to describe and
	title your object with an entirely different theme than you created its
	names with because a player would not know what it is called.
</p>
<dl><dt>inside_descr</dt>
<dd>The inside description is what a player sees if it is inside the object.  This is used for things like Coffins or boxes or boats that a player can climb inside.  The inside description is defined the same way the normal description is but you can make it as many lines as you want like you would with a room description.</dd></dl>
<pre>	                                      inside_descr
	"You are inside a black coffin with a red velvet padding - scary!"

	                                      inside_descr
	"You are inside the pink time machine.  a small control panel is on the
	floor and seems to be operated by stepping on it."
</pre>
<dl><dt>extra</dt>
<dd>The extra's on the object like the NPC, can be used to do many things.  It can be used to store information for DIL programs or it can be used to show a part of the object like the room extras show a part of the room.  They can even be used to create new acts when a person picks the item up,</dd></dl>
<p>	drops, or enters it.There is also a special extra that is the object's description when
	you look at it with the look &lt;object&gt; command.
</p><p>	Lets go over the object description extra first.  If you use an extra
	with no names list it will become the object's description when you look at
	any of the names on it.
</p>
<pre>	extra {}
	"Its just a rock nothing special about it."

	extra {}
	"The ice cube is about 40 meters perfectly cubed.  It seems to be
	melting slightly but waiting for it to finish would be sort of like
	waiting for the ice age to end."
</pre>
<p>You can also use extras to show parts of the object.
</p>
<pre>	extra {"crack"}
	"There is a big crack in the side of the ice cube.  Maybe if you mess
	with the crack you will be able to open it or something."

	extra {"bed post","post"}
	"Its a big gold bed post don't you wish you could get this sucker off it
	would make you a rich adventurer indeed."
</pre>
<p>You can also use the extras to give more detailed and vivid
	descriptions when the object is acted upon.
</p>
<table class="wikitable">
<caption>Object special action extras
</caption>
<tbody><tr>
<th>Extra
</th>
<th>Description
</th></tr>
<tr>
<td>$wear_s
</td>
<td>A message shown to activator when wearing (+wield/grab/hold) an
<p>	item.
</p>
</td></tr>
<tr>
<td>$wear_o
</td>
<td>A message shown to others when wearing an item.
</td></tr>
<tr>
<td>$rem_s
</td>
<td>A message shown to activator when removing worn stuff.
</td></tr>
<tr>
<td>$rem_o
</td>
<td>A message shown to others when removing an item.
</td></tr>
<tr>
<td>$get_s
</td>
<td>A message shown to activator when getting an item.
</td></tr>
<tr>
<td>$get_o
</td>
<td>A message shown to others when getting an item.
</td></tr>
<tr>
<td>$drop_s
</td>
<td>A message shown to activator when dropping an item.
</td></tr>
<tr>
<td>$drop_o
</td>
<td>A message shown to other when dropping an object.
</td></tr>
<tr>
<td>$enter_s
</td>
<td>A message shown to activator when entering an item.
</td></tr>
<tr>
<td>$enter_o
</td>
<td>A message shown to other when entering an item.
</td></tr>
<tr>
<td>$exit_s
</td>
<td>A message shown to activator when leaving an item.
</td></tr>
<tr>
<td>$exit_o
</td>
<td>A message shown to other when leaving an item.
</td></tr></tbody></table>
<p>In the following example of an ice cube, 1n is the activator and
	$2n is the unit in question.
</p>
<pre>	extra {"$get_s"}
	"You pick up the $2N, it is very cold and begins to melt in your hands."

	extra {"$get_o"}
	"$1n picks up the $2N, you notice that a drop of water hits the ground as
	it begins to melt in $1s hand."
</pre>
<p>Finally you can use extras to store information for DIL programs.
	We will not cover this because it is a topic covered in-depth in
	the DIL documentation.
</p>
<dl><dt>manipulate</dt>
<dd>This field is what defines the things that can be done to the object.  For example a piece of armour should be able to be taken and worn, while a fountain should be able to be entered but not taken unless its some magical portable fountain.  There are two sets of manipulate flags even though you can use them together.  We separate them because the first two are flags that tell you if you can take or enter something while the rest of the manipulate flags are for worn positions.</dd></dl>
<p>	First the two flags for taking and entering are:
</p>
<table class="wikitable">
<caption>Take and enter flags
</caption>
<tbody><tr>
<th>Manipulate
</th>
<th>Description
</th></tr>
<tr>
<td>MANIPULATE_TAKE
</td>
<td>Set this flag if the unit can be taken
<p>	(picked up/moved about).
</p>
</td></tr>
<tr>
<td>MANIPULATE_ENTER
</td>
<td>Set this flag if it is possible to
<p>	enter a unit, ie set it in a coffin if you want players to be able to
	enter the coffin.
</p>
</td></tr></tbody></table>
<p>These flags are
	set to indicate on what body positions a particular object can be
	worn:
</p>
<ul><li>MANIPULATE_WEAR_FINGER</li>
<li>MANIPULATE_WEAR_NECK</li>
<li>MANIPULATE_WEAR_BODY</li>
<li>MANIPULATE_WEAR_HEAD</li>
<li>MANIPULATE_WEAR_LEGS</li>
<li>MANIPULATE_WEAR_FEET</li>
<li>MANIPULATE_WEAR_HANDS</li>
<li>MANIPULATE_WEAR_ARMS</li>
<li>MANIPULATE_WEAR_SHIELD</li>
<li>MANIPULATE_WEAR_ABOUT</li>
<li>MANIPULATE_WEAR_WAIST</li>
<li>MANIPULATE_WEAR_WRIST</li>
<li>MANIPULATE_WIELD</li>
<li>MANIPULATE_HOLD</li>
<li>MANIPULATE_WEAR_EAR</li>
<li>MANIPULATE_WEAR_BACK</li>
<li>MANIPULATE_WEAR_CHEST</li>
<li>MANIPULATE_WEAR_ANKLE</li></ul>
<p>Currently you can only set one of the worn positions flags on an
	item at a time.  You can set both enter and take on an item with a
	position or just one or the other.  Some legal examples of combinations
	are as follows:
</p>
<pre>	//An earring
	manipulate {MANIPULATE_TAKE, MANIPULATE_WEAR_EAR}

	//A backpack
	manipulate {MANIPULATE_TAKE, MANIPULATE_ENTER, MANIPULATE_WEAR_BACK}

	//strange true but its legal an earring pack
	manipulate {MANIPULATE_TAKE, MANIPULATE_ENTER, MANIPULATE_WEAR_EAR}
</pre>
<dl><dt>flags</dt>
<dd>This field on an object is used to set special attributes in order to make the object able to be buried or not or no-teleportable and many others.  The object flag list uses the UNIT_FL_* variables that both the NPCs and the rooms also use, therefore while you can set some flags on an object it may not have any affect unless you as a builder or administrator adds the functionality.  You can also add extras on an object that can be used as a special flag which you will learn as you learn to use DIL.  The following is a full list of all unit flags and how they affect objects, if they do.</dd></dl>
<table class="wikitable">
<caption>Object unit flag affects
</caption>
<tbody><tr>
<th>Flag
</th>
<th>Description
</th></tr>
<tr>
<td>UNIT_FL_PRIVATE
</td>
<td>Currently has no affect on a NPC.
</td></tr>
<tr>
<td>UNIT_FL_INVISIBLE
</td>
<td>Makes unit invisible
</td></tr>
<tr>
<td>UNIT_FL_NO_BURY
</td>
<td>Makes it so you can create objects that
<p>	can not be buried for example a weapon that for some reason shouldn't be
	buried.
</p>
</td></tr>
<tr>
<td>UNIT_FL_BURIED
</td>
<td>Makes
<p>	unit buried when loaded
</p>
</td></tr>
<tr>
<td>UNIT_FL_NO_TELEPORT
</td>
<td>Makes it so you can not teleport into this object.  This flag only
<p>	works on containers.
</p>
</td></tr>
<tr>
<td>UNIT_FL_NO_MOB
</td>
<td>Currently has no affect on an object.
</td></tr>
<tr>
<td>UNIT_FL_NO_WEATHER
</td>
<td>Currently has no affect on a NPC.
</td></tr>
<tr>
<td>UNIT_FL_INDOORS
</td>
<td>Currently has no affect on an object.
</td></tr>
<tr>
<td>UNIT_FL_TRANS
</td>
<td>Makes unit transparent If the Unit is
<p>	transparent you will be able to see any NPCs that it is carrying.
	For example if a canoe was carrying a familiar you would see that as you
	walked into the room.  If this flag is not set and you are in a canoe you
	will not see outside the canoe and no one will see in.
</p>
</td></tr>
<tr>
<td>UNIT_FL_NO_SAVE
</td>
<td>Makes it so a PC can't save with
<p>	unit
</p>
</td></tr>
<tr>
<td>UNIT_FL_SACRED
</td>
<td>Currently has no affect on an object.
</td></tr>
<tr>
<td>UNIT_FL_MAGIC
</td>
<td>This flag is used by spells to tell if the object is magic.
</td></tr></tbody></table>
<p>If you wanted to make an object that a player can carry around but can
	not save you would set the manipulate and flags as follows.
</p>
<pre>	manipulate {MANIPULATE_TAKE}
	flags {UNIT_FL_NO_SAVE}
</pre>
<dl><dt>type</dt>
<dd>This field is what you use to set the objects type.  The type field is used when spells are cast or commands are executed on the object.  You can add your own item types but they will not change the actions of base code commands.  The following is the list of item types and what they mean when you set them.  Some are not supported with the current code but you can add support for them if you like by making DIL commands, which is covered in another manual.</dd></dl>
<table class="wikitable">
<caption>Item types
</caption>
<tbody><tr>
<th>Type
</th>
<th>Description
</th></tr>
<tr>
<td>ITEM_LIGHT
</td>
<td>Items of this type can be lighted and extinguished.
</td></tr>
<tr>
<td>ITEM_SCROLL
</td>
<td>Items of this type can be read as a magical scroll.
</td></tr>
<tr>
<td>ITEM_WAND
</td>
<td>Items of this type can be used with the <b>use</b>
<p>	command.
</p>
</td></tr>
<tr>
<td>ITEM_STAFF
</td>
<td>Items of this type can be used with the <b>tap</b>
<p>	command as a magical staff
</p>
</td></tr>
<tr>
<td>ITEM_WEAPON
</td>
<td>Items of this type are used as weapons.
</td></tr>
<tr>
<td>ITEM_FIREWEAPON
</td>
<td>Currently not supported but could be used to classify a special type
<p>	of weapon.
</p>
</td></tr>
<tr>
<td>ITEM_MISSILE
</td>
<td>Currently not supported but could be used to classify a special type
<p>	of weapon.
</p>
</td></tr>
<tr>
<td>ITEM_TREASURE
</td>
<td>Items of this type are of some great value to sell but nothing else
<p>	like a Gem or a block of gold.
</p>
</td></tr>
<tr>
<td>ITEM_ARMOR
</td>
<td>Items of this type can be worn or used as armour.
</td></tr>
<tr>
<td>ITEM_POTION
</td>
<td>Items of this type can be used with the <b>quaff</b> as
<p>	a position.
</p>
</td></tr>
<tr>
<td>ITEM_WORN
</td>
<td>Items of this type can be worn but not normally used for armour it
<p>	is more for clothing.
</p>
</td></tr>
<tr>
<td>ITEM_OTHER
</td>
<td>This item type is for items that don't fit any other type.  Now
<p>	that you can make your own commands with the VME 2.0 you should just make
	your own item type instead of using this value.
</p>
</td></tr>
<tr>
<td>ITEM_TRASH
</td>
<td>Items of this type are usually junk or broken equipment.
</td></tr>
<tr>
<td>ITEM_TRAP
</td>
<td>Not currently supported but could be used to make a trap command by
<p>	creating a trap item
</p>
</td></tr>
<tr>
<td>ITEM_CONTAINER
</td>
<td>Items that can be used as containers.
</td></tr>
<tr>
<td>ITEM_NOTE
</td>
<td>Items of this type can be used to write on like paper or
<p>	slates.
</p>
</td></tr>
<tr>
<td>ITEM_DRINKCON
</td>
<td>Items of this type can carry liquids.
</td></tr>
<tr>
<td>ITEM_KEY
</td>
<td>Items of this type can be used as a key.
</td></tr>
<tr>
<td>ITEM_FOOD
</td>
<td>Items of this type can be eaten
</td></tr>
<tr>
<td>ITEM_MONEY
</td>
<td>Items of this type can be spent as currency
</td></tr>
<tr>
<td>ITEM_PEN
</td>
<td>No longer supported but could be used to force people to have a
<p>	writing instrument before writing a message.
</p>
</td></tr>
<tr>
<td>ITEM_BOAT
</td>
<td>Items of this type can be used as a water craft
</td></tr>
<tr>
<td>ITEM_SPELL
</td>
<td>Not currently supported but it could be used to make a page in a spell book
</td></tr>
<tr>
<td>ITEM_BOOK
</td>
<td>Not currently supported but could be used to make
<p>	regular and spell books.
</p>
</td></tr>
<tr>
<td>ITEM_SHIELD
</td>
<td>Items of this type can be used as a shield.
</td></tr>
<tr>
<td>ITEM_SKIN
</td>
<td>Not currently supported in the release but could be used to make the
<p>	skin command and create skins of animals
</p>
</td></tr>
<tr>
<td>ITEM_BOARD
</td>
<td>Items of this type are used for public communications in the form
<p>	of boards that can be read from and written to.
</p>
</td></tr></tbody></table>
<p>Unlike flags and manipulate fields only one item type can be set
	on an object at a time.  The format for the 'type' field is simply the
	keyword followed by the value as follows:
</p>
<pre>	type ITEM_BOARD
</pre>
<dl><dt>weight</dt>
<dd>The weight is the weight of the object in pounds.  In the future we may adjust this to allow you to make things lighter for example you could set it in ounces or grams.  Right now however all we have is pounds so we have some pretty heavy feathers out there.</dd></dl>
<p>	To use this you just enter the 'weight' keyword and then the
	value.
</p>
<pre>	/80 lbs.
	weight 80
</pre>
<dl><dt>capacity</dt>
<dd>This field sets the size of a container object.  If the object does not have the manipulate enter flag set then this field doesn't have to be set.  The capacity is currently by pounds since the weight of objects is set in pounds.  In the future we may take into account size and weight but right now it goes only by weight.  The following line of code would set an item to carry 600 pounds of stuff.</dd></dl>
<pre>	capacity 600
</pre>
<dl><dt>key</dt>
<dd>The key field sets the key name of the key that will open the item.  This field should be set to the symbolic name of the key that opens the item it is on.  If the item is in the same zone as the key then you do not need to put the zone extension on the key name.  The following are the three possible examples of using the key field.</dd></dl>
<pre>	//if object and key are in same zone.
	key brasskey

	//if key and object are in same zone
	key brasskey@zonename

	//if key and object are not in same zone
	key brasskey@otherzonename
</pre>
<p>Notice you can put the zone name on it if the key is in the same
	zone but if the key is not in the same zone you must put the zone name
	on it.
</p>
<dl><dt>cost</dt>
<dd>This is the field you set to add a cost to your object.  If you leave this field out it will default to no cost and will not be able to be sold at stores.  The system for setting cost on an item is the same as setting money on a NPC.  As with a NPC we could set it using a single number but it would not be easy to understand.  For example 5 gold pieces would be something like:</dd></dl>
<pre>	money 25600
</pre>
<p>I am no more sure this will make five gold pieces than I was when
	I used this same example with the money field in NPC.  The problem is I
	just did the math in my head so its not very accurate.  It is much
	easier to use the defined money types to set exactly what you want as
	follows:
</p>
<pre>	IRON_PIECE
	COPPER_PIECE
	SILVER_PIECE
	GOLD_PIECE
	PLATINUM_PIECE
</pre>
<p>Now if we wanted to make an object costing five gold it would be as
	simple as this:
</p>
<pre>	money 5*GOLD_PIECE
</pre>
<p>the define method also gains you the ability to tell the VME what
	amount of each coin you want on the NPC.  If you set it using a single
	integer the compiler would pick how many of each coin.  This of course
	is not what is desired in fact you want to be able to set your cost
	however you like.  So setting more than one coin is as simple as adding
	a comma between the first and second coin.
</p>
<pre>	money 5*GOLD_PIECE, 20*IRON_PIECE
</pre>
<dl><dt>rent</dt>
<dd>This field tells how much it costs you to keep an item while your offline.  The rent is not always taken if the VME server is set up to not take any rent then it will not matter if you set this or not.  Also the VME can be set up to take a percentage of this field so it may not take the exact amount you et.  If the VME server is set up to take 100%</dd></dl>
<p>	of the rent then what you set will be taken.  To set this field you do
	the same as you do with the cost field.
</p>
<pre>	money 5*GOLD_PIECE, 20*IRON_PIECE
</pre>
<dl><dt>minv</dt>
<dd>This field is the administrator invisible level of the object it is set on.  This means that if you set the 'minv' to two hundred it will make it so the object can not be seen by anyone below the administrator level of two hundred.  This is good for hiding objects that you need for administrators but you don't want players to see.</dd></dl>
<p>	In order for the 'minv' to be removed an
	administrator or a DIL function must change it.
</p>
<pre>	minv 239
</pre>
<dl><dt>alignment</dt>
<dd>The object alignment is not currently used.  It is an integer value that can be set on an object to be used with any DIL functions.</dd></dl>
<p>	In the future it will be what determines if a good or evil person can
	wield an item.  The value is set by placing the 'alignment' keyword
	first followed by the alignment desired from -1000 to +1000.
</p>
<pre>	alignment -250
</pre>
<dl><dt>open</dt>
<dd>The open field is used if you want to give your object the ability to be opened, closed, and or locked.  If you add the open flags you need to also add a key field which has already been explained.</dd></dl>
<p>	The following are all
	the possible open flags and what they are used for.
</p>
<dl><dt>EX_OPEN_CLOSE</dt>
<dd>Set this if you can open and close this object.</dd>
<dt>EX_CLOSED</dt>
<dd>Set this if you want the object to be closed when loaded.</dd>
<dt>EX_LOCKED</dt>
<dd>Set this if you want the object to be locked when loaded.</dd></dl>
	<blockquote style="background-color: #E8E8E8; font-style: italic;">
<p>	An interesting aspect is that if you do not specify a key, you can
	    only unlock this door with the 'pick' skill, 'unlock' spell or from
	    DIL with UnSet();
</p>
		</blockquote>
<dl><dt>EX_PICK_PROOF</dt>
<dd>Using this flag renders the 'pick' skill and 'unlock' spell un useable on the lock of this object.</dd>
<dt>EX_INSIDE_OPEN</dt>
<dd>Usable on container objects only, this enables the mobile to 'open' and</dd></dl>
<p>	    'lock' from the inside.
</p><p>The simplest use of this field is to make an object that opens
	and closes.  A coffin for example would have its flags set as
	follows:
</p>
<pre>	open {EX_OPEN_CLOSE}
</pre>
<p>If you wanted to set an object that is locked and closed and
	having a brass key that can open it, when it is loaded.  It would look as follows.
</p>
<pre>	open {EX_OPEN_CLOSE, EX_CLOSED, EX_LOCKED}
	key brass_key
</pre>
<p>You would have to define the key in the object section as well and
	the symbolic name for that key would be 'brass_key'
</p>
<dl><dt>spell</dt>
<dd>The spell field is the power of the objects defense against spells.  You can set it from zero which is just not setting the field all the way to 200% which means a person who has 100% in a spell will fail almost all the time.  To set this field it would look as follows:</dd></dl>
<pre>	//Spell resistance at 150%
	spell 150
</pre>
<dl><dt>value</dt>
<dd>The object values are used for just about any special item from armour to drink containers.  They should not be set directly unless you have a reason to do so, like a special DIL command that checks a value on an item.  You also have to be carefull not to over write what a value is already used for example value one is already used on weapons and armours for craftsman ship that will be explained later in</dd></dl>
<p>	(Link to objmacros).
</p><p>	If you find you need to set the values there are a total of five
	of them and they can be set to any integer value as follows:
</p>
<pre>	   value[0]   5
	   value[1] 16
	   value[2] -2
	   value[3] -10
	   value[4] 12
</pre>
<dl><dt>affect</dt>
<dd>The affect field should not be set directly, instead you should use the macros defined in (Link to objmacros).</dd>
<dt>dilbegin or dilcopy</dt>
<dd>As has been mentioned in previous sections the DIL functions are what give VME servers the edge over all other muds.</dd></dl>
<p>	We will only give some examples here and leave it up to the DIL manual to teach
	you how to create your own functions that will make your rooms, NPC, and
	objects more than special.
</p><p>	There are several object functions that come standard with the VME
	2.0.  The following is a list of those functions.
</p>
<ul><li>Guild restrict</li>
<li>Anti-guild restrict</li>
<li>Quest restrict</li>
<li>Quests restrict</li>
<li>Alignment restrict</li>
<li>Level restrict</li>
<li>Virtual level restrict</li>
<li>Race restrict</li>
<li>Ability restrict</li>
<li>Skill restrict</li>
<li>Spell restrict</li>
<li>Weapon restrict</li>
<li>Gender restrict</li>
<li>Player restrict</li>
<li>boards</li>
<li>tuborg/dilbegin</li></ul>
<p>These are the only object functions currently documented in the VME
	2.0 release but if you go through the zones that are released with the
	VME you are sure to find many more.  Hopefully with the descriptions in
	(Link to objdilfunc).  You will be able to use the functions
	listed here and figure out ones that are not.
</p><p>	Since these are just DIL's written by builders for the
	Valhalla mud all you have to do is use the dilcopy keyword in the
	NPC with the function name you want to use and the arguments that
	function requires.  The following is what you would find in the
	<i>function.zon</i> for tuborgs.
</p>
<pre>	dilbegin tuborg(s:string);
	external
		sub_drink_info@commands(d:unitptr);
	var
	  u : unitptr;
	code
	{
	  :start:
	  wait(SFB_CMD, ( (command("drink")) or
		                (command("sip")) or
					  (command("taste")) ) );
		u := activator;
		secure (u,start);
	if (findunit (activator,argument,FIND_UNIT_INVEN|FIND_UNIT_SURRO,null)!=self)
		goto start;
		if ( command("sip") or command("taste") )
		{
		  block;
		  act("$1n tastes $2n enjoying every drop.", A_HIDEINV, u, self, null,
	        TO_ROOM);
	    act("The taste of the $2N is nothing less than divine.", A_HIDEINV, u, self,
		    null, TO_CHAR);
		  goto start;
	   }

		 if ( u.thirst &gt;20 )
		 {
		   block;
		 act("Your not thirsty.", A_HIDEINV, u, null, null, TO_CHAR);
	     goto start;
		 }
	block;
	   act ("You drink $2n and it makes you feel more energetic!", A_HIDEINV, u, self,
		      null, TO_CHAR);
	   act ("$1n drinks $2n and looks more energetic!", A_HIDEINV, u, self,
		      null, TO_ROOM);

		 u.thirst := u.thirst + 10;
		 u.full := u.full + 10;
		 if (u.thirst &gt; 24)
		 {
		   u.thirst := 24;
		 }

		 if (u.full &gt; 24)
		 {
		   u.full := 24;
		 }
		 u.endurance := u.endurance+50;
		 if (u.endurance &gt; u.max_endurance)
		 {
		   u.endurance := u.max_endurance;
		 }
		 sub_drink_info@commands(self);
		 quit;
	}
	dilend
</pre>
<p>If this DIL function scares you don't worry you don't have to
	understand it or adjust it you only have to use it.  In fact this is a
	really easy DIL to use.  The argument on the tuborg function is not used
	yet so all you have to do is pass in a blank string or any string for
	that matter.  So if you wanted to make a tuborg in the game you would
	just add this to your drink container.
</p>
<pre>	dilcopy tuborg@function ("");
</pre>
<p>All of the above listed DIL object functions are described in
	(Link to objdilfunc).
	Then we put some to work so you can see how
	to use them in (Link to objcomplex)
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section-Suggested-NPC-exercises" title="Manual:Zone Manual/The NPC Section/Suggested NPC exercises">Previous: Suggested NPC exercises</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section-Object-macros" title="Manual:Zone Manual/The Objects Section/Object macros">Next: Object macros</a></div></div>