<div class="mw-parser-output"><h2><span class="mw-headline" id="The_NPC_section">The NPC section</span></h2>
<p>	Now that you have rooms down it is time to start filling your area
	with some life.  The NPC is the Non-player Character or mobile.  These
	are the things players will hunt and interact with
</p><p>	In order to get started building NPCs you should first be aware
	of the NPC fields you can use.  The (Link to npcfields) shows a full listing
	of all the NPC fields and their types as defined in (Link to ch-03).
</p>
<table class="wikitable">
<caption>NPC fields and types
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
<td>Symbolic name
</td>
<td>Symbol
</td>
<td>level
</td>
<td>Integer
</td></tr>
<tr>
<td>names
</td>
<td>Stringlist
</td>
<td>height
</td>
<td>Integer
</td></tr>
<tr>
<td>title
</td>
<td>String
</td>
<td>race
</td>
<td>Integer
</td></tr>
<tr>
<td>descr
</td>
<td>String
</td>
<td>attack
</td>
<td>Integer
</td></tr>
<tr>
<td>inside_descr
</td>
<td>String
</td>
<td>armour
</td>
<td>Integer
</td></tr>
<tr>
<td>extra
</td>
<td>Structure
</td>
<td>speed
</td>
<td>Integer
</td></tr>
<tr>
<td>manipulate
</td>
<td>Integer
</td>
<td>position
</td>
<td>Integer
</td></tr>
<tr>
<td>flags
</td>
<td>Integer
</td>
<td>default
</td>
<td>Integer
</td></tr>
<tr>
<td>weight
</td>
<td>Integer
</td>
<td>ability
</td>
<td>two Integers
</td></tr>
<tr>
<td>capacity
</td>
<td>Integer
</td>
<td>weapon
</td>
<td>two Integers
</td></tr>
<tr>
<td>dilbegin or dilcopy
</td>
<td>Function pointer
</td>
<td>spell
</td>
<td>two Integers
</td></tr>
<tr>
<td>defensive
</td>
<td>Integer
</td>
<td>romflags
</td>
<td>Integer
</td></tr>
<tr>
<td>offensive
</td>
<td>Integer
</td>
<td>light
</td>
<td>Integer
</td></tr>
<tr>
<td>mana
</td>
<td>Integer
</td>
<td>alignment
</td>
<td>Integer
</td></tr>
<tr>
<td>hit
</td>
<td>Integer
</td>
<td>minv
</td>
<td>Integer
</td></tr>
<tr>
<td>money
</td>
<td>Integer
</td>
<td>key
</td>
<td>String
</td></tr>
<tr>
<td>exp
</td>
<td>Integer
</td>
<td>open
</td>
<td>Integer
</td></tr>
<tr>
<td>sex
</td>
<td>Integer
</td>
<td>end tag
</td>
<td>Symbol
</td></tr></tbody></table>
<p>Many of the same fields you found in rooms, as you can see from
	(Link to npcfields), can also be found in NPCs.  The fields do
	not always have exactly the same use when coding rooms, NPCs, and
	objects but they are normally set in the same manor.  It is very
	important that you read and understand the differences of each field as
	they pertains to rooms and or NPCs.
</p>
<h3><span class="mw-headline" id="Description_of_NPC_fields">Description of NPC fields</span></h3>
<dl><dt>symbolic name</dt>
<dd>The rules of the symbols has been explained in (Link to ch-03), if you didn't read them yet you may want to review.</dd></dl>
<p>	 The important thing to realize with the NPC symbol is it is always
	 good practice to give the NPC a symbol that resembles the title so
	 that administrators and builders can use the
	 <b>load</b> and the <b>wstat</b> to easily
	locate, examine, and load the NPC in question.
</p>
<dl><dt>title</dt>
<dd>The NPC title is what is shown if the NPC is being attacked or talking.</dd></dl>
<p>	It is also what is shown if the NPC can be picked up.  there should be
	no punctuation in the NPC title because of how it is used in the VME
	server.  If you add punctuation or forget to capitalize something
	that the VMC thinks you should it will give you a warning when you
	compile.
</p>
<pre>	title "a small dog"
	title "Hansen"
	title "a black dragon"
	title "Drako"
	title "an elephant"
</pre>
<dl><dt>descr</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>	The description field is what the player sees when walking into the room
	or when looking with no arguments. The description on a NPC will only
	show up when the NPC is in the standing position.  All other positions
	will show the title and the position they are in.
</p>
<pre>	descr
	"a small fluffy dog is chasing its tail here."
	descr
	"Hansen is standing here sorting the mail."
</pre>
<dl><dt>names</dt>
<dd>The NPC name field is much more important then the room name field.  It is what is used when players are hunting and killing and even for administrators who are trying to use their administrator commands on a NPC.  The names should match the title and the descr fields and have all normal combinations of each.</dd></dl>
<pre>	title "a baby black dragon"
	descr "a tiny baby black dragon is here playing."
	names {"tiny baby black dragon", "tiny black dragon",
	"baby black dragon", "black dragon", "tiny dragon",
	"baby dragon","dragon"}

	title "Hansen"
	descr "Hansen the post man is standing here sorting mail."
	names{"postman","hansen"}
</pre>
<p>The idea of course is to make any combination that a player may
	type to try and act upon your NPC.  You would not want to describe and
	title your NPC with an entirely different theme than you created its
	names with because a player would not know what it is called.
</p>
<dl><dt>inside_descr</dt>
<dd>The inside description is what a player sees if it is inside the NPC.  This could be used to show the player its stomach or if on a mount it could be used to show the back of the horse.</dd></dl>
<pre>	inside_descr
	"The lining of this stomach looks indestructible.  Looks like you are in
	for a long digestion cycle."
</pre>
<dl><dt>extra</dt>
<dd>The extra's on the NPC can be used to do many things.  It can be used to store information for DIL programs or it can be used to show a part of the NPC like the room extras show a part of the room.  There is also a special extra, the NPCs description when you look at it with the look &lt;NPC&gt; command.</dd></dl>
<p>	Lets show the NPC description extra first.  If you use an extra
	with no names list it will become the NPCs description when you look at
	any of the names on the NPC.
</p>
<pre>	extra {}
	"The green furry hamster seems to be glowing and it doesn't seem very
	happy."
</pre>
<p>You can also use extras to show parts of the NPC.
</p>
<pre>	extra {"hamster head","head"}
	"This human like head is covered with a lot of green fur and it looks
	really  upset."
</pre>
<p>You can also use the extras to give more detailed and vivid
	descriptions when the NPC is acted upon.
</p>
<table class="wikitable">
<caption>NPC special action extras
</caption>
<tbody><tr>
<th>Extra
</th>
<th>Description
</th></tr>
<tr>
<td>$get_s
</td>
<td>A message shown to activator when getting a NPC.
</td></tr>
<tr>
<td>$get_o
</td>
<td>A message shown to others when getting a NPC.
</td></tr>
<tr>
<td>$drop_s
</td>
<td>a message shown to activator when dropping a NPC.
</td></tr>
<tr>
<td>$drop_o
</td>
<td>A message shown to others when dropping an NPC.
</td></tr>
<tr>
<td>$enter_s
</td>
<td>A message shown to activator When mounting
</td></tr>
<tr>
<td>$enter_o
</td>
<td>A message shown to others when mounting.
</td></tr>
<tr>
<td>$exit_s
</td>
<td>A message shown to others when dismounting
</td></tr>
<tr>
<td>$exit_o
</td>
<td>a message shown to others when dismounting
</td></tr></tbody></table>
<p>In the following example, $1n is the activator and $2n is the
	unit in question.  Assume you are defining a familiar.
</p>
<pre>	extra {"$get_s"}
	"You pick up the $2n it is very warm and cuddles right up to you."

	extra {"$get_o"}
	"$1n picks up the $2n and you see them cuddle together."
</pre>
<p>Finally you can use extras to store information for DIL programs.
	We will not cover this because it is a topic covered in-depth in
	the DIL documentation.
</p>
<dl><dt>manipulate</dt>
<dd>The manipulate filed only has two values for NPCs The two values are 'MANIPULATE_TAKE' and 'MANIPULATE_ENTER'.  The 'MANIPULATE_TAKE'</dd></dl>
<p>	makes it possible for a NPC to be picked up this would be good for
	something like a familiar.  The 'MANIPULATE_ENTER' is used for things
	like mounts when making a mount you will also have to set the capacity
	so a fat player can jump on.  The following is how you set the
	manipulate flag.
</p>
<pre>	//Make a  NPC takable.
	manipulate {MANIPULATE_TAKE}

	//Make a NPC takable and able to be entered
	manipulate {MANIPULATE_TAKE|MANIPULATE_ENTER}
</pre>
<dl><dt>flags</dt>
<dd>This field on a NPC is used to set special attributes in order to make the NPC able to be buried or not or no-teleportable and many others.  The NPC flag list uses the UNIT_FL_* variables that both the objects and the rooms also use, therefore while you can set some flags on an NPC it may not have any affect unless you as a builder or administrator adds the functionality.  You can also add extras on an NPC that can be used as a special flag which you will learn as you learn to use DIL.  The following is a full list of all unit flags and how they affect NPC, if they do.</dd></dl>
<table class="wikitable">
<caption>NPC unit flag affects
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
<td>Makes it so you can create NPC that can be taken like familiars or
<p>	pets that can not be buried.  This flag is not needed on every NPC
	because the bury command will not allow you to bury an NPC outside of
	your inventory.
</p>
</td></tr>
<tr>
<td>UNIT_FL_BURIED
</td>
<td>Makes unit buried when loaded
</td></tr>
<tr>
<td>UNIT_FL_NO_TELEPORT
</td>
<td>Makes it so you can not summon the NPC with this flag and the NPC with
<p>	this flag can not teleport.  You can still teleport to NPC with this
	flag the current way teleport is written.  Remember all spells are in
	DIL and you can modify them in <i>spells.zon</i>
</p>
</td></tr>
<tr>
<td>UNIT_FL_NO_MOB
</td>
<td>Currently has no affect on a NPC.
</td></tr>
<tr>
<td>UNIT_FL_NO_WEATHER
</td>
<td>Currently has no affect on a NPC.
</td></tr>
<tr>
<td>UNIT_FL_INDOORS
</td>
<td>Currently has no affect on NPC.
</td></tr>
<tr>
<td>UNIT_FL_TRANS
</td>
<td>Makes unit transparent If the Unit is transparent you will be able
<p>	to see any other NPCs that it is carrying.  For example if a NPC was
	carrying a familiar you would see that as you walked into the room.  It
	also is used in mounts so the PC can see outside its mount.  If the
	flag is not set on its mount the player will not see what is in the
	room.
</p>
</td></tr>
<tr>
<td>UNIT_FL_NO_SAVE
</td>
<td>Makes it so a PC can't save with unit
</td></tr>
<tr>
<td>UNIT_FL_SACRED
</td>
<td>Currently has no affect on a NPC.
</td></tr>
<tr>
<td>UNIT_FL_MAGIC
</td>
<td>Currently has no affect on a NPC.
</td></tr></tbody></table>
<p>If you wanted to make a NPC that a player can carry around but can
	not save you would set the manipulate and flags as follows.
</p>
<pre>	manipulate {MANIPULATE_TAKE}
	flags {UNIT_FL_NO_SAVE}
</pre>
<dl><dt>romflags</dt>
<dd>Like flags these are just integer values that are used to change how the NPC interacts with its environment.</dd></dl>
<table class="wikitable">
<caption>Room flags for NPCs
</caption>
<tbody><tr>
<th>Flag
</th>
<th>Description
</th></tr>
<tr>
<td>CHAR_PROTECTED
</td>
<td>Set this flag if the character is protected by the law-system.
</td></tr>
<tr>
<td>CHAR_LEGAL_TARGET
</td>
<td>This flag is used by the law system and should not be set unless you are re-writing your law system.
</td></tr>
<tr>
<td>CHAR_OUTLAW
</td>
<td>This flag is used by the law system and should not be set unless you are re-writing your law system.
</td></tr>
<tr>
<td>CHAR_GROUP
</td>
<td>This is used by the follow and group commands and should not be set unless you are re-writing your, movement, status, and combat systems.
</td></tr>
<tr>
<td>CHAR_BLIND
</td>
<td>Set this if the character is blinded.
</td></tr>
<tr>
<td>CHAR_HIDE
</td>
<td>Set flag if character is hidden.
</td></tr>
<tr>
<td>CHAR_MUTE
</td>
<td>Set flag if character is mute.
</td></tr>
<tr>
<td>CHAR_SNEAK
</td>
<td>Set flag if character is in sneaking mode.
</td></tr>
<tr>
<td>CHAR_DETECT_ALIGN
</td>
<td>No actual effect on NPCs.
</td></tr>
<tr>
<td>CHAR_DETECT_INVISIBLE
</td>
<td>Set flag if character can see invisible units.
</td></tr>
<tr>
<td>CHAR_DETECT_MAGIC
</td>
<td>No actual effect on NPCs.
</td></tr>
<tr>
<td>CHAR_DETECT_POISON
</td>
<td>No actual effect on NPCs.
</td></tr>
<tr>
<td>CHAR_DETECT_UNDEAD
</td>
<td>No actual effect on NPCs.
</td></tr>
<tr>
<td>CHAR_DETECT_CURSE
</td>
<td>No actual effect on NPCs.
</td></tr>
<tr>
<td>CHAR_DETECT_LIFE
</td>
<td>No actual effect on NPCs.
</td></tr>
<tr>
<td>CHAR_WIMPY
</td>
<td>Set flag if character if wimpy. Wimpy characters flee when they are
<p>	low on hit points, and they gain less experience when killing others.
	If a character is both wimpy and aggressive (NPC_AGGRESSIVE) it will
	only attack sleeping players.
</p>
</td></tr>
<tr>
<td>CHAR_SELF_DEFENCE
</td>
<td>This is an internal combat flag set this only if you create your own combat system.
</td></tr></tbody></table>
<p>These flags are set in the same way as other flags in rooms NPCs
	and objects.  The following are a few examples.
</p>
<pre>	//wimpy and hidden
	romflags {CHAR_HIDDEN, CHAR_WIMPY}

	//NPC can see invisible
	romflags {CHAR_DETECT_INVISIBLE}
</pre>
<dl><dt>weight</dt>
<dd>The weight is the weight of the NPC in pounds.  In the future we may adjust this to allow you to make things lighter for example you could set it in ounces or grams.  Right now however all we have is pounds so we have some pretty heavy feathers out there.</dd></dl>
<p>	To use this you just enter the 'weight' keyword and then the
	value.
</p>
<pre>	/80 lbs.
	weight 80
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>The weight affects the NPCs natural attack damage.</p></blockquote>
<dl><dt>capacity</dt>
<dd>This field along with the NPCs strength and dexterity decides how much a NPC can carry.  If you set the capacity to 300 lbs.  the NPC will only be able to carry that much depending if it has the strength and dexterity to carry that much.  This of course doesn't affect DIL programs that link the objects directly into the NPC.  To set the capacity you just put the keyword and the amount in your NPC.</dd></dl>
<pre>	capacity  300
</pre>
<dl><dt>height</dt>
<dd>The height field is the size of the NPC in centimeters.  This determines the size of the equipment the NPC is wearing.  You will learn more about size and height in the object section but for now just understand this makes your NPC the right or wrong size.  To set the 'height' you just put the 'height' keyword followed by the number of centimeters.</dd></dl>
<pre>	//6 feet tall since 1 inch equals 2.54
	height 183
</pre>
<dl><dt>dilbegin or dilcopy</dt>
<dd>The DIL functions are what give VME servers the edge over all other muds.</dd></dl>
<p>	We will only give some examples here and leave it up to the DIL manual to teach
	you how to create your own functions that will make your rooms, NPC, and
	objects more than special.
</p><p>	There are several NPC functions that come standard with the VME
	2.0.  The following is a list of the functions.
</p>
<ul><li>Mercenary</li>
<li>obey</li>
<li>evaluate</li>
<li>guard direction</li>
<li>shop keeper</li>
<li>combat magic</li>
<li>fido</li>
<li>zone wander</li>
<li>global wander</li>
<li>team work</li>
<li>rescue</li>
<li>agressive</li></ul>
<p>These are the only NPC functions currently documented in the VME
	2.0 release but if you go through the zones that are released with the
	VME you are sure to find many more.  Hopefully with the descriptions in
	(Link to npcdilfunc).  You will be able to use the functions
	listed here and figure out ones that are not.
</p><p>	Since these are just DIL's written by builders for the
	Valhalla mud all you have to do is use the dilcopy keyword in the
	NPC with the function name you want to use and the arguments that
	function require.  The following is what you would find in the
	<i>function.zon</i> for evaluate.
</p>
<pre>	/* Evaluate DIL. amt is the cost of evaluation in iron pieces.
	  Note: not to be confused with '''evaluate@commands''', which
	  is a command.
	*/
	dilbegin aware evaluate (amt: integer);

	var u1 : unitptr;
	    arg: string;
	    buf: string;
	    cur: integer;
	    craft: integer;
	    category: integer;

	    pc : unitptr;
	    pcn: string;

	    arm_text  : stringlist;
	    shi_text  : stringlist;
	    craft_text: stringlist;
	code
	{

	craft_text:=  {"horrible","very bad","bad","worse than average","average",
	  "a little better than average","better than average","good","very good",
	  "supreme"};
	arm_text:= {"clothes", "leather", "hard leather", "chain", "plate"};
	shi_text:= {"small", "medium", "large"};

	heartbeat:= PULSE_SEC*3;

	:start:
	arg:= "";
	u1:= null;

	wait (SFB_CMD, command("evaluate"));

	if (visible(pc, self) == FALSE)
	    goto start; // Pc is just trying to evaluate using the command

	block;

	pc:= activator;
	if (pc.type == UNIT_ST_PC) pcn := pc.name;
	else pcn := pc.title;

	arg:= argument;

	if (visible(self, pc) == FALSE)
	    {
	    exec ("say I don't do business with people I can't see.", self);
	    goto start;
	    }

	if (arg == "")
	    {
	    exec ("say Which item do you wish to evaluate, "+pcn+"?", self);
	    goto start;
	    }

	u1:= findunit (pc, arg, FIND_UNIT_IN_ME, null);

	if (not u1)
	    {
	    exec ("say You do not have such an item, "+pcn+".", self);
	    goto start;
	    }

	if ((u1.type != UNIT_ST_OBJ) or ( (u1.objecttype != ITEM_WEAPON) and
	    (u1.objecttype != ITEM_ARMOR) and (u1.objecttype != ITEM_SHIELD) ))
	    {
	    exec ("say The "+u1.name+" is neither a sword, shield nor armor!", self);
	    goto start;
	    }

	// Currency, skip for now

	if (not transfermoney (pc, null, amt * IRON_MULT))
	    {
	    exec ("say The cost is merely "+moneystring(amt*IRON_MULT, TRUE)+
	        ", get them first.", self);
	    goto start;
	    }

	category:= u1.value[0];
	craft:= u1.value[1] / 5 + 4; // / 5 + 4 is to get corresponding craft_text val

	if (craft &lt; 0) craft := 0;  if (craft &gt; 9) craft := 9;

	// Change the following to use skill_text(craft) instead of itoa(craft)
	if (u1.objecttype == ITEM_WEAPON)
	    buf := "say The "+u1.name+" is a "+weapon_name(category)+" of "+
	        craft_text.[craft]+" craftmanship and material.";

	if (u1.objecttype == ITEM_ARMOR)
	    buf := "say The "+u1.name+" is made of "+arm_text.[category]+" and is of "+
	        craft_text.[craft]+" craftmanship and material.";

	if (u1.objecttype == ITEM_SHIELD)
	    buf := "say The "+u1.name+" is a "+shi_text.[category]+" shield of "+
	        craft_text.[craft]+" craftmanship and material.";

	exec (buf, self);

	goto start;

	}

	dilend
</pre>
<p>If this DIL function scares you don't worry you don't have to
	understand it or adjust it you only have to use it.  In fact this is a
	really easy DIL to use.  It only has one argument which is 'amt', the integer value of money you want the evaluator to charge when a
	person evaluates their stuff.  So to use this function it would look
	like this on an NPC.
</p>
<pre>	dilcopy evaluate@function (5*GOLD_PIECE);
</pre>
<p>this tells the evaluate DIL to charge 5 gold pieces each time a player
	evaluates something.  For more information on the money see the money
	field.
</p><p>	All released DIL NPC functions are described in
	(Link to npcdilfunc).
	Then we put some to work so you can see how
	to use them in (Link to npccomplex)
</p>
<dl><dt>defensive</dt>
<dd>This field sets the NPC natural defense.  The defense is a natural bonus the NPC gets when being attacked.  If this value is set high enough the NPC becomes almost indestructible.  You should use the macro to set the NPC natural attack and defense in (Link to npcmacroattdef).</dd>
<dt>offensive</dt>
<dd>This field sets the NPC natural offense.  The offense is a natural bonus the NPC gets when being attacked.  If this value is set high enough the NPC can do some serious damage when attacking.  You should use the macro to set the NPC natural attack and defense in (Link to npcmacroattdef).</dd>
<dt>mana</dt>
<dd>This sets the NPC max mana points.  Using this field you can create special NPCs that have more or less mana points than the VME server would normally give when a NPC is loaded.</dd></dl>
<p>	this field is simple all you have to do to set it is put the 'mana'
	keyword followed by the amount of mana points you want the NPC to have as
	its max.  The following definition would make an NPC with only 100 mana
	points no matter what level.
</p>
<pre>	mana 100
</pre>
<dl><dt>hit</dt>
<dd>This sets the NPC max hit points.  Using this field you can create special NPCs that have more or less hit points than the VME server would normally give when a NPC is loaded.</dd></dl>
<p>	this field is simple all you have to do to set it is put the 'hit'
	keyword followed by the amount of hit points you want the NPC to have as
	its max.  The following definition would make an NPC with only 100 hit
	points no matter what level.
</p>
<pre>	hit 100
</pre>
<dl><dt>money</dt>
<dd>The money field is how you give your NPC money to have while going along its marry way through your world.  The money field is an integer that tells the VME how much money the NPC is carrying.  It would however be hard to calculate the amount you want on an NPC with out the macros we have provided.  For example to put 5 gold on an NPC you would have to use the following on your NPC.</dd></dl>
<pre>	money 25600
</pre>
<p>I of course am not sure this will make 5 gold pieces since I did
	the math in my head and with all this righting I am doing my math mind
	doesn't seem to be working right.  So to make life easier for you and me
	we have added some macros to help that are rather self
	explanatory.
</p>
<pre>	IRON_PIECE
	COPPER_PIECE
	SILVER_PIECE
	GOLD_PIECE
	PLATINUM_PIECE
</pre>
<p>Now if we wanted to make a NPC carrying five gold it would be as
	simple as this:
</p>
<pre>	money 5*GOLD_PIECE
</pre>
<p>the macro method also gains you the ability to tell the VME what
	amount of each coin you want on the NPC.  If you set it using a single
	integer the compiler would pick how many of each coin.  This of course
	is not what is desired in fact you want to be able to set your money
	however you like.  So setting more than one coin is as simple as adding
	a comma between the first and second coin.
</p>
<pre>	money 5*GOLD_PIECE, 20*IRON_PIECE
</pre>
<dl><dt>exp</dt>
<dd>By default a monster gives 100% of the experience it is worth.</dd></dl>
<p>	This amount is calculated according to the level of the NPC verses the
	level of the person fighting it.  Sometimes the amount of experience is
	not right since the NPC is really hard to kill for example a dragon with
	breath weapon and heal at the same level as a merchant with a dagger.
	These should of course give different experience.  The 'exp' field is
	designed to do just that.  The possible range for the 'exp' field is
	-500% to 500%.  If you put the NPC at a negative experience value it
	will take experience away when it is killed.  If you want the default of
	100% you do not even need to place this field in your NPC.
</p>
<pre>	//add 50% to the experience gained
	exp 150

	/subtract 150% from the experience gained
	exp -50
</pre>
<dl><dt>sex</dt>
<dd>Gender, one of these:</dd></dl>
<pre>	SEX_NEUTRAL
	SEX_MALE
	SEX_FEMALE
</pre>
<p>the values are pretty obvious which is which gender so all we will
	show here is how to set it.
</p>
<pre>	//Setting a male NPC
	sex SEX_MALE
</pre>
<dl><dt>level</dt>
<dd>When  creating a NPC it must be between level 0 and  199.  The level  of  the NPC decides how many skill points  and  ability points the NPC has.  It, along with the 'exp' percentage, determines the amount of experience gained when the NPC is killed. To set the level of the NPC you use the 'level' keyword and then follow it by the level you are setting.</dd></dl>
<pre>	//set a NPC to level 50
	level 50
</pre>
<dl><dt>race</dt>
<dd>The 'race' keyword is what you use to set the characters race.</dd></dl>
<p>	Races in VME are defined by using an integer that lets the spells and
	skills act differently for each specific type.  The VME comes standard
	with many races defined in the <i>values.h</i>.  For
	ease in access we have provided them in (Link to app-c).  For now
	you can look at the short list below taken from the over all
	race list.
</p>
<pre>	#define RACE_RAT            1102
	#define RACE_HORSE          1103
	#define RACE_BADGER         1104
	#define RACE_SKUNK          1105
	#define RACE_BOAR           1106
	#define RACE_MOUSE          1107
	#define RACE_MONKEY         1108
	#define RACE_PORCUPINE      1110
	#define RACE_ELEPHANT       1112
	#define RACE_CAMEL          1113
	#define RACE_FERRET         1114
</pre>
<p>If for example you wanted to make a monkey you could simply put
	the 'race' keyword and follow it by the monkey define like this:
</p>
<pre>	race RACE_MONKEY
</pre>
<p>If the race your looking for doesn't exist in the
	<i>values.h</i> list, you can either add one buy picking a
	number not already used and creating your own define in the
	<i>values.h</i> or by adding the define to your zone.
	Defines added to a single zone will not be accessible if another builder
	wants to use it.  You could also just set it using a number.  The
	following two methods would act the same.
</p>
<pre>	//add define to values.h and use in your zone
	#define RACE_SPACE_TROLL  5059
	race RACE_SPACE_TROLL

	//Just plug in a number
	race 5059
</pre>
<p>If you don't use the macros things can get confusing really fast with
	the amount of races there are.
</p>
<dl><dt>attack</dt>
<dd>This field sets the NPCs natural attack type.  Do not use this field directly instead use the macro described in (Link to npcmacroattarm)</dd>
<dt>armour</dt>
<dd>This field sets the NPCs natural armour type.  Do not use this field directly instead use the macro described in (Link to npcmacroattarm)</dd>
<dt>speed</dt>
<dd>Speed determines the NPCs speed.  The range is one to twelve.  You should not set this when compiling an NPC since the result is really undefined.  If you have a special NPC that you want to try to make move faster and hit faster then you could try setting this.  This field is mainly added so DIL can adjust speed.  The lower the number the faster the NPC speed.</dd></dl>
<pre>	//fastest speed.
	speed 0

	//slowest speed
	speed 12
</pre>
<dl><dt>position</dt>
<dd>This field sets the position that the NPC will be in when it is first loaded.  The following positions are recognized by the compiler.</dd></dl>
<pre>	POSITION_DEAD
	POSITION_MORTALLYW
	POSITION_INCAP
	POSITION_STUNNED
	POSITION_SLEEPING
	POSITION_RESTING
	POSITION_SITTING
	POSITION_FIGHTING
	POSITION_STANDING
</pre>
<p>Some of these positions make no sense you would not load a
	  NPC into a fight or you would not load an NPC that is already dead.
	  The positions are availible for DIL and you will need to read the DIL
	  manuals to find out what you would want those for.  For now the
	  following are enough.
</p>
<pre>	  POSITION_SLEEPING
	POSITION_RESTING
	POSITION_SITTING
	POSITION_STANDING
</pre>
<p>The position combined with the default position determines what
	will be shown when a player looks in the room.  If the position of the
	NPC matches its default position the NPC description will be shown.  If
	it doesn't match the NPCs title and position will be shown.  The
	default value for both 'position' and 'default' is 'POSITION_STANDING'
</p><p>	To set the position like with other fields you type the 'position'
	keyword first and follow it by the position you are setting.
</p>
<pre>	position POSITION_SITTING
</pre>
<dl><dt>default</dt>
<dd>The default position along with the position determines what is shown when a NPC is in each position.  If the position and default positions match the 'descr' field is shown.  If they do not match the NPC title is shown along with the current position information.  If</dd></dl>
<p>	'default' is not set it defaults to 'POSITION_STANDING'.  The following
	are possible default positions.
</p>
<pre>	    POSITION_DEAD
	POSITION_MORTALLYW
	POSITION_INCAP
	POSITION_STUNNED
	POSITION_SLEEPING
	POSITION_RESTING
	POSITION_SITTING
	POSITION_FIGHTING
	POSITION_STANDING
</pre>
<p>Setting the default field is exactly like setting the 'position'
	field you place the 'default' keyword first and then the position you
	want to be default like this:
</p>
<pre>	default POSITION_RESTING
</pre>
<dl><dt>ability</dt>
<dd>this field is used to set each of the NPCs abilities.</dd></dl>
<p>	It should not be used directly but instead set through the macro described
	in (Link to npcmacroability)
</p>
<dl><dt>weapon</dt>
<dd>this field is used to set each of the NPCs weapon proficiencies.</dd></dl>
<p>	It should not be used directly but instead set through the macro described
	in (Link to npcmacroweapspl)
</p>
<dl><dt>spell</dt>
<dd>this field is used to set each of the NPCs spells.</dd></dl>
<p>	It should not be used directly but instead set through the macro described
	in (Link to npcmacroweapspl)
</p>
<dl><dt>light</dt>
<dd>The light field on NPC is not normally set.  If however you have a strange creature like a 'light bug' you can set a light value on a NPC.</dd></dl>
<p>	The default light is set to 0 which means it neither adds or subtracts
	from the rooms light.  To set the light value on a NPC you just put the
	'light' keyword first and then the value you want to add to the current
	light.
</p>
<pre>	//add one to light in room
	light 1

	//default
	light 0

	//take one away
	light -1
</pre>
<dl><dt>alignment</dt>
<dd>This field   is  a  value between -1000 and +1000,  where  -1000  is ultimate  evil, 0 is neutral and +1000 is ultimate good.  Good  is per  definition any value from +1000..+350, neutral is  any  value from  +349..-349 and evil is any value from -350..-1000. Any value in between can also be used.</dd></dl>
<pre>	// Quite evil, maybe a Ghoul
	alignment -750

	// Barely evil.
	alignment -350

	//barely good
	alignment 350
</pre>
<dl><dt>minv</dt>
<dd>This field is the administrator invisible level of the NPC it is set on.  This means that if you set the 'minv' to two hundred it will make it so the NPC can not be seen by anyone below the administrator level of two hundred.  This is good for hiding ghosts that only come visible when they attack.  In order for the 'minv' to be removed an administrator or a DIL function must change it.</dd></dl>
<pre>	minv 239
</pre>
<dl><dt>key</dt>
<dd>Currently this field is not used in the VME 2.0 release.  It was added so in the future you wanted to add keys to a NPC for some weird reason like a living trunk then you can.  In order to set the key you first place the 'key' keyword and then add the symbolic name of the key.</dd></dl>
<pre>	//if the key is in your zone
	key mynpckey

	//if the key is in some other zone
	key someoneelses@keyzone
</pre>
<dl><dt>open</dt>
<dd>this field is not used yet in the VME 2.0 release.  The field was added so you could make a NPC that can be opened, closed, locked,</dd></dl>
<p>	and everything else that a room or an object can have set on it.  For
	now we will not document this but if you are interested in how you could
	use it study the open fields on objects or rooms.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section-Suggested-room-exercises" title="Manual:Zone Manual/The Room Section/Suggested room exercises">Previous: Suggested room exercises</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section-NPC-macros" title="Manual:Zone Manual/The NPC Section/NPC macros">Next: NPC macros</a></div></div>