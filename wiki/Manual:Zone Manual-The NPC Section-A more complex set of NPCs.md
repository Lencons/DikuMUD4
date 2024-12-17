<div class="mw-parser-output"><div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1 tocsection-1"><a href="#A-more-complex-set-of-NPCs"><span class="tocnumber">1</span> <span class="toctext">A more complex set of NPCs</span></a>
<ul>
<li class="toclevel-2 tocsection-2"><a href="#Magic-casting-NPC"><span class="tocnumber">1.1</span> <span class="toctext">Magic casting NPC</span></a></li>
<li class="toclevel-2 tocsection-3"><a href="#A-wandering-janitor"><span class="tocnumber">1.2</span> <span class="toctext">A wandering janitor</span></a></li>
<li class="toclevel-2 tocsection-4"><a href="#Creating-a-teacher"><span class="tocnumber">1.3</span> <span class="toctext">Creating a teacher</span></a></li>
<li class="toclevel-2 tocsection-5"><a href="#Teacher-acts"><span class="tocnumber">1.4</span> <span class="toctext">Teacher acts</span></a></li>
<li class="toclevel-2 tocsection-6"><a href="#Guild-master-functions"><span class="tocnumber">1.5</span> <span class="toctext">Guild master functions</span></a></li>
<li class="toclevel-2 tocsection-7"><a href="#NPC-banker"><span class="tocnumber">1.6</span> <span class="toctext">NPC banker</span></a></li>
</ul>
</li>
</ul>
</div>

<h3><span class="mw-headline" id="A_more_complex_set_of_NPCs">A more complex set of NPCs</span></h3>
<p>	In the last sections you learned all the fields and how to make a basic NPC.
	In this section we will use the information from the last sections to
	create some more unique NPCs for our dragon station zone There is not a
	lot of new information here we will be using the DIL functions from the previous
	section and adding some flags to the NPCs to make them act
	different.
</p>
<h4><span class="mw-headline" id="Magic_casting_NPC">Magic casting NPC</span></h4>
<p>	The basic Dragon we made in the (Link to npcbasic) looks
	like a real dragon but it is a bit boring when you fight a dragon and
	don't get toasted by an acid or fire spell or two.  in (Link to npcdilfunc) the 'combat_magic' function was described.  This
	is the function you use to make all NPCs cast magic while in combat.
	With that in mind lets take a look at how we can make our dragon a bit
	more interesting	g.
</p><p>	Well lets see a black dragon is supposed to have the ability to
	either cast fire breath or acid breath depending on who you talk to.
	Once you learn DIL you could even make fire breath be a skill not a
	spell but for now we will stick with what we know.  I like the acts of
	the acid breath spell so we will use that as the spell of choice.  The
	NPC as we defined it before hasn't changed so the following would be the
	entire dragon with the combat magic function.
</p>
<pre>	bldragon

	title "a black dragon"
	descr "A big ugly black dragon is clawing the ground here."
	names {"big ugly black dragon","ugly black dragon","big black dragon",
	"black dragon","dragon"}

	extra {}
	"The black dragons scales glitter like black granite that has been
	polished for years by water.  He has a large neck and huge bat like
	wings.  his eyes watch you as you stand before him.  One claw seems to be
	tapping slightly on the ground as if the dragon is waiting for
	something."

	extra {"eye","eyes"}
	"The dragons eyes seem to follow you no matter where you go in the room
	nothing seems to escape the dragons attention."

	extra {"claws","claw"}
	"The claw is big black and it looks very deadly.  It seems like the
	dragon has two sets of 4 large claws and 2 sets of 4 smaller claws which
	to say means the claws are about the size of short swords and long
	swords."

	extra {"scales","scale"}
	"Its a scale!  Haven't you ever seen a dragon before!"

	extra {"bat wings","wings"}
	"The dragon sees you looking and flaps his wings creating one heck of a
	wind blast."

		race RACE_DRAGON_BLACK
		sex SEX_MALE
		height 625
		weight 1250
		level 70
	 NATURAL_DEF (WPN_CLAW, ARM_PLATE)
		alignment -900
	MSET_ABILITY(20,12,12,12,12,12,20,0)
	MSET_WEAPON(10,10,10,5,30,5)
	MSET_SPELL(0,0,0,0,0,0,0,0,0,0,30)

	//Combat Magic added.
	   dilcopy combat_mag@function("acid breath", "", 25, 2);

	end
</pre>
<p>That is all there is to it.  If you are wondering where I got the
	'acid breath' part of the DIL copy all the spells names are in the
	<i>spells.def</i> or you can just pick a spell by what you
	would type if you wanted to cast it yourself in the game.  Now if this
	still looks like a lot to do to make a dragon the dragon above could
	have been created with exactly the same information by using the
	<i>composed.h</i> and the 'M_DRAGON_BLACK_OLD' macro.  If
	we use the macro the dragon would look like this
</p>
<pre>	bldragon

	title "a black dragon"
	descr "A big ugly black dragon is clawing the ground here."
	names {"big ugly black dragon","ugly black dragon","big black dragon",
	"black dragon","dragon"}

	extra {}
	"The black dragons scales glitter like black granite that has been
	polished for years by water.  He has a large neck and huge bat like
	wings.  his eyes watch you as you stand before him.  One claw seems to be
	tapping slightly on the ground as if the dragon is waiting for
	something."

	extra {"eye","eyes"}
	"The dragons eyes seem to follow you no matter where you go in the room
	nothing seems to escape the dragons attention."

	extra {"claws","claw"}
	"The claw is big black and it looks very deadly.  It seems like the
	dragon has two sets of 4 large claws and 2 sets of 4 smaller claws which
	to say means the claws are about the size of short swords and long
	swords."

	extra {"scales","scale"}
	"Its a scale!  Haven't you ever seen a dragon before!"

	extra {"bat wings","wings"}
	"The dragon sees you looking and flaps his wings creating one heck of a
	wind blast."

	M_DRAGON_BLACK_OLD(SEX_MALE)

	end
</pre>
<p>As you can see with the second way the dragon was a lot easier to
	make because we let the macro set all the other values we just described
	the NPC and set the macro.
</p>
<h4><span class="mw-headline" id="A_wandering_janitor">A wandering janitor</span></h4>
<p>	Our space station is nice but we wouldn't want a lot of people
	coming to visit if we didn't have a janitor to walk around cleaning up.
	Dragons most likely wouldn't be low life enough to be Janitors so I
	think we will leave that up to a hobgoblin.  the following would be the
	definition of a hobgoblin wandering Janitor.
</p>
<pre>	janitor
	names {"ugly janitor", "janitor", "hobgoblin"}
	title "an ugly janitor"
	descr "an ugly janitor is walking around, cleaning up."

	extra{}
	"This ugly green thing looks more goblin than hobgoblin but he seems
	intent on cleaning everything around him."

	race RACE_HOBGOBLIN
	level 6
	sex SEX_MALE
	height   130       /* cm            */
	weight   120       /* Pounds        */
	// he is sort of good for cleaning so much
	alignment 900

	NATURAL_DEF(WPN_FIST, ARM_LEATHER)
	MSET_ABILITY(10,10,10,23,15,22,10,0)   \
	MSET_WEAPON(10,10,10,10,10,10)    /*  Average in everything, any wpn */
	MSET_SPELL(4,2,2,2,2,2,2,6,6,6,6)  /* Resistances       */

	//give him some money
	money 5 IRON_PIECE

	dilcopy janitors@function(15);

	// only want him cleaning the station
	dilcopy wander_zones@function("dragonst", 20, 1, 1);

	end
</pre>
<p>Like with the dragon if we wanted to create this NPC easier we
	would use the Hobgoblin defines in <i>composed.h</i> so we
	don't have to fill out all the information.  If we did this it would
	simply look as follows:
</p>
<pre>	janitor
	names {"ugly janitor", "janitor", "hobgoblin"}
	title "an ugly janitor"
	descr "an ugly janitor is walking around, cleaning up."

	extra{}
	"This ugly green thing looks more goblin than hobgoblin but he seems intent
	on cleaning everything around him."

	M_AVG_HOBGOBLIN(6, SEX_MALE)

	// he is sort of good for cleaning so much
	alignment 900

	//give him some money
	money 5 IRON_PIECE

	dilcopy janitors@function(15);

	// only want him cleaning the station
	dilcopy wander_zones@function("dragonst", 20, 1, 1);

	end
</pre>
<p>As you can see you can combine the DIL functions you learned in
	(Link to npcdilfunc) to make your NPC do more than one thing.
</p>
<h4><span class="mw-headline" id="Creating_a_teacher">Creating a teacher</span></h4>
<p>	Setting up teachers on valhalla is harder and more strict formed
	than most things in the game.  The reason is the way you set them up is
	to use an old form of functions called special.  In the future guilds
	will be in DIL like everything else but for now the teachers that are
	released with the VME are base code.  Even though the teachers are base
	code they still allow for you to adjust many things.  The truth is you
	don't have to use our teachers you could code your own in DIL but many
	find this easier.
</p><p>	Guild teacher definitions are actually less complex than people think
	they are. There really are no big, mysterious secrets. The key is simply
	to understand the numbers and how the balance is achieved.
	(From here on in, GTD will refer to "guild teacher definition", and
	"entity" will be used to refer to the ability/spell/skill/weapon being
	offered by the GTD.)
</p>
	<blockquote style="background-color: #E8E8E8; font-style: italic;"><p> Using TAB characters in GTDs is a very bad idea! It will have extremely adverse effects, including causing the mud to crash.</p></blockquote>
<p>	We need to tart first and explain that to use the teacher special
	functions you need to use a field not described anywhere else in the NPC
	descriptions.  The field is called a 'special'.  The reason the
	'special' field was not included in the field descriptions is because it
	is being removed from the VME as soon as banks and teachers have been
	replaced by DIL there will be no more special functions.  For now
	however we need to use them for the for mentioned purposes.  The format
	for a special function is as follows:
</p>
<pre>	special &lt;Function define&gt; &lt;function arguments&gt;
</pre>
<p>For teachers the function definition is 'SFUN_TEACH_INIT' and the
	 arguments range from who can join, what the acts of the teacher are,
	 and what the teacher teaches.
</p><p>	In the first part of a SFUN_TEACH_INIT definition, there are several
	pieces of important information which allow the mud to know what you are
	trying to provide to players.  The entire set of arguments are enclosed
	in double quotes.  So a teacher with nothing at all in it would look
	like this:
</p>
<pre>	special SFUN_TEACH_INIT "&lt;arguments go here&gt;"
</pre>
<p>After the opening double quote ("), the first thing necessary
	is the text formatting code '&amp;l', which tells the compiler to ignore the
	standard text formatting protocols for the rest of the string or until the
	'&amp;f' code is given.
</p><p>	Immediately following the '&amp;l' code, with no spaces at all, the type of
	entity the function will teach is defined. It is one of the following
	types:
</p>
<ul><li>abilities</li>
<li>spells</li>
<li>skills</li>
<li>weapons</li></ul>
<p>The first two lines of the SFUN_TEACH_INIT looks like this:
</p>
<pre>	special SFUN_TEACH_INIT
	"&amp;labilities;0;
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>The '0;' is the end of field marker that will be used through out the teacher fields</p></blockquote>
<p>	The next set of arguments to the teacher function is the acts the
	teacher will use when a person is trying to train.  There are seven acts
	total and they are as follows:
</p>
<h4><span class="mw-headline" id="Teacher_acts">Teacher acts</span></h4>
<dl><dt>Line 1</dt>
<dd>This line is displayed when the player makes a mistake in typing the name of an entity, whether or not it is actually offered at the teacher.</dd>
<dt>Line 2</dt>
<dd>This line is similar to the first, but is usually evident of attempting to practice an entity not offered at this particular teacher.</dd>
<dt>Line 3</dt>
<dd>This is the act displayed when the player has insufficient funds to practice the desired entity.</dd>
<dt>Line 4</dt>
<dd>This is displayed when the player has not got enough ability or skill practice points to learn the desired entity.</dd>
<dt>Line 5</dt>
<dd>Simply put, the player has exceeded the teacher's expertise in the offered entity and must go elsewhere to learn more, if at all possible.</dd>
<dt>Line 6</dt>
<dd>This line is displayed when the player is either wearing magical,</dd></dl>
<p>	        stat-modifying equipment or is affected by spells/skills which
	        modify stats.
</p>
<dl><dt>Line 7</dt>
<dd>This line is what is shown when your armour affects you using special functions in base code.  This is rare and may never be seen.  In the future when the teachers are made in DIL this act may not be necessary.</dd></dl>
<p>Now we can add the acts to our example it would look as
	follows:
</p>
<pre>	special SFUN_TEACH_INIT
	"&amp;labilities;0;
	 $1n tells you, 'I have never heard of such an ability.'; $1n
	tells you, 'I do not know how to teach this ability.'; $1n tells you,
	'You haven't got %s for me.'; $1n tells you, 'You haven't got %d ability
	points.'; $1n tells you, 'I can not teach you any more.'; $1n tells you,
	'You must be unaffected by magic, else I can't teach you.'; $1n tells
	you, 'Remove all equipment, please.';
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;">
<p>	   $1n is the substitution variable for the teacher's title (see the DIL
	document for more details).
</p><p>	%s is the amount of money the teacher  requires to teach the entity in
	      question.
</p><p>	%d is the amount of ability or skill practice points required to
	      practice the given entity.
</p><p>	The standard GTD termination character, a semicolon (;) ends each
	act
</p>
	</blockquote>
<p>	about the actual GTDs, or the lines that actually define what the
	teachers teach and everything to do about how expensive and how high
	they teach it.  A GTD is a single line, composed of several fields. The data contained
	in these fields determines how a particular entity is practiced.
</p><p>	Here is an example of a GTD:
</p>
<pre>	  0;  100; scan                          ;   9;  9000;   7;          0;
</pre>
<p>Note that it has a lot of white space in it. It is really not necessary,
	as the field terminators are the semicolons. This means that you could just
	as easily write:
</p>
<pre>	0;100;scan;9;9000;7;0;
</pre>
<p>When making teachers most people prefer to put the white space in
	   to make it easier to read and find errors.  A larger example would
	   look as follows:
</p>
<pre>	  0;  100; scan                          ;   9;  9000;   7;          0;
	  0;   90; consider                      ;   4;  4000;   5; 10;      0;
	  0;  100; appraisal                     ;   9;  4000;   5;          0;
	  0;  100; fleeing                       ;   9;  9000;   6; 12;      0;
</pre>
<p>Each part of the GTD separated by a semicolon is called a
	field.  The following is the fields and their definitions.
</p>
<dl><dt>Field 1</dt>
<dd>Field 1 is the guild level. It is simply the level at which one is allowed to practice the particular entity in the guild. A level of 0 indicates that one can practice it from the beginning.</dd>
<dt>Field 2</dt>
<dd>This is the maximum percentage one is allowed to practice the particular entity. It can be anywhere from 1 to 200. For abilities, it should be in increments of 2 (or divisible by 2), and for spells, skills,</dd></dl>
<p>	or weapons, in increments of 5 (or divisible by 5). This means that the
	effective minimum depends on whether the entity is an ability or a spell,
	skill or weapon.
</p><p>	Therefore, the minimums for abilities is 2, and the minimum for spells,
	skills or weapons is 5. Anything less will be automatically practiced to
	the effective minimum. This also means that putting an odd number for
	abilities will result in the player practicing an additional point, and
	for spells, skills or weapons, practicing up to the nearest 5.
</p><p>	For example:    Percentage maximum for an ability is set for 95%. Player practices the
	ability, which then becomes 96%.
	   Player then decides to practice a weapon skill. It is set to 77% maximum.
	After practicing, the player has 80% in the weapon.
	   It is better to simply make the ability 96% and the weapon 80% maximum
	instead.
</p>
<dl><dt>Field 3</dt>
<dd>Name of Entity</dd>
<dt>Field 4</dt>
<dd>This is the practice cost minimum in Old gold pieces. Anything less than 10 here will simply be translated as 1 iron piece. Anything other than a number divisible by 10 is rounded up to the nearest iron piece.</dd>
<dt>Field 5</dt>
<dd>This is the practice cost maximum in old gold pieces. It is generally defined as being 1000 times what Field 4 is defined as:</dd></dl>
<p>	The reason for this is because there is a scale related to the current
	practice percentage of the entity. The practice minimum is what the entity
	costs when it is at 0%, and the practice maximum is what it costs to
	practice it to maximum percentage.
</p><p>	It is not necessary to multiply the minimum by 1000 to define the
	maximum. It can be any number, as long as the maximum exceeds the minimum.
	Failure to do so will result in the mud crashing. It is unknown what will
	happen if the fields have 0 entered in them. I warn that it could be rather
	unpredictable.
</p><p>	Setting the maximum too high will only serve to dissuade players from
	practicing and indeed even playing. This is not to say you cannot make a
	truly powerful entity very expensive. Just make sure that the entity is
	worth the cost.
</p>
<dl><dt>Field 6</dt>
<dd>This is the only necessary practice points field. It allows one to use their skill or ability practice points to increase their character's powers.</dd></dl>
<p>	This number is generally determined by the desire of the builder to make
	the entity easier or harder to practice, based upon the logical
	consideration of how this class would learn/use the entity.
</p><p>	For instance, a Fighter class would find practicing "fist" to be
	exceedingly easy, so they may only need 4 points to practice this skill,
	but on the other hand, a Mage class would not have such an experience so
	it may cost them 15 points to practice.
</p><p>	Don't go overboard, making this field an outrageous number will mean
	that no one is likely to practice the entity, mainly because of lack of
	points. However, like in the cost fields, it can be made expensive to
	reflect the power of the entity.
</p>
<dl><dt>Field 7 - X</dt>
<dd>You can repeat field 6 as many times as you want the player to be able to practice in one level so you can set a point cost each time.  This is so each time they practice at a level you can make it more expensive.</dd></dl>
<p>	An example of this would look as follows:
</p>
<pre>	  0;   90; consider                      ;   4;  4000;   5; 10;      0;
</pre>
<p>This example has consider being practiced at guild level 0 up to 90%,
	costing 4 old gold pieces minimum, 4000 old gold pieces maximum,
	5 practice points for the first practice per level and 10 for the
	second.
</p><p>	   For 15 points a level, the player can practice consider twice. It is
	actually quite nice to be able to do this, and generally easier entities
	take advantage of this more often.
</p><p>	Each additional field is followed by a semicolon
</p>
<dl><dt>Field X</dt>
<dd>This is the termination field for the GTD. It tells the compiler that the GTD is finished. In fact, if you set a practice point field to 0, it would consider that Field X, and end the GTD.</dd></dl>
<p>	Every GTD line must have an end of field marker!
</p><p>When we refer to old gold pieces they represent the VME money system as
	follows:
</p>
<table class="wikitable">
<caption>Old to new money conversions.
</caption>
<tbody><tr>
<th>Old gold piece
</th>
<th>New money
</th></tr>
<tr>
<td>10
</td>
<td>1 Iron Piece (IP)
</td></tr>
<tr>
<td>80
</td>
<td>1 copper piece (CP)
</td></tr>
<tr>
<td>640
</td>
<td>1 silver piece (SP)
</td></tr>
<tr>
<td>5120
</td>
<td>1 gold piece (GP)
</td></tr>
<tr>
<td>40960
</td>
<td>1 platinum piece (PP)
</td></tr></tbody></table>
<p>Of course, to finish up the entire SFUN_TEACH_INIT, you must include a
	closing double quotation mark ("). Failure to do so will cause no end of
	problems for you.
</p><p>	A finished teacher of ability function would look like
	this:
</p>
<pre>	special SFUN_TEACH_INIT
	"&amp;labilities;0;
	$1n tells you, 'I have never heard of such an ability.';
	$1n tells you, 'I do not know how to teach this ability.';
	$1n tells you, 'You haven't got %s for me.';
	$1n tells you, 'You haven't got %d ability points.';
	$1n tells you, 'I can not teach you any more';
	$1n tells you, 'You must be unaffected by magic, otherwise I can't teach
	you.';
	$1n tells you, 'Remove all equipment, please.';

	  0;  100; Strength                      ;   4;  4000;   8;       0;
	  0;   90; Dexterity                     ;  14; 14000;  12;       0;
	  0;   90; Constitution                  ;  14; 14000;   9;       0;
	  0;  100; Hitpoints                     ;   4;  4000;  11;       0;
	  2;   60; Brain                         ;  23; 23000;  14;       0;
	  4;   80; Charisma                      ;  18; 18000;  14;       0;
	"
</pre>
<p>There are two other easy to use specials that you will want to use
	with your teacher.  they are 'SFUN_GUILD_BASIS' and
	'SFUN_MEMBERS_ONLY'.
</p>
<dl><dt>SFUN_GUILD_BASIS</dt>
<dd>This initializes the teacher and the only argument is the guild name</dd></dl>
<pre>	special SFUN_GUILD_BASIS "Udgaard Fighter"
</pre>
<dl><dt>SFUN_MEMBERS_ONLY</dt>
<dd>This simply blocks anyone who is not in the guild from practicing This means the argument is the guild name. and the act separated by a '#', an example would look as follows:</dd></dl>
<pre>	special SFUN_MEMBERS_ONLY "Udgaard fighter#$1n says, 'Buggar ye off, $3n.'"
</pre>
<p>Finally we will show you what a full teacher would look like with
	the entire specials and the NPC definition.
</p>
<pre>	jones

	names {"blacksmith", "smith", "Jones"}
	title "Jones the blacksmith"
	descr "The venerable Jones Blacksmith is here."
	extra {}
	"The smith is old but his arms still retain the strength of his youth.
	He looks as if he has retired, but he can still put you through the
	drills of physical training."
	flags {UNIT_FL_NO_TELEPORT}
	romflags {CHAR_PROTECTED}
	//Define from composed.h
	M_HUMAN_WARRIOR_AXE(80, SEX_MALE)

	//negative exp to discourage killing teacher
	exp -100

	special SFUN_GUILD_BASIS GUILD_UDG_FIGHTER
	special SFUN_MEMBERS_ONLY GUILD_UDG_FIGHTER+"#$1n says, 'Buggar ye off, $3n.'"

	special SFUN_TEACH_INIT
	"&amp;labilities;0;
	$1n tells you, 'I have never heard of such an ability.';
	$1n tells you, 'I do not know how to teach this ability.';
	$1n tells you, 'You haven't got %s for me.';
	$1n tells you, 'You haven't got %d ability points.';
	$1n tells you, 'I can not teach you any more';
	$1n tells you, 'You must be unaffected by magic, otherwise I can't teach
	you.';
	$1n tells you, 'Remove all equipment, please.';

	  0;  100; Strength                      ;   4;  4000;   8;       0;
	  0;   90; Dexterity                     ;  14; 14000;  12;       0;
	  0;   90; Constitution                  ;  14; 14000;   9;       0;
	  0;  100; Hitpoints                     ;   4;  4000;  11;       0;
	  2;   60; Brain                         ;  23; 23000;  14;       0;
	  4;   80; Charisma                      ;  18; 18000;  14;       0;
	"
</pre>
<h4><span class="mw-headline" id="Guild_master_functions">Guild master functions</span></h4>
<p>	When you make a guild you have to make a guild master for it.  This
	NPC will let people join and leave the guild and it also gives titles.
	To create a guild master you need to use three 'special' functions.  The
	functions you need are 'SFUN_GUILD_BASIS', 'SFUN_GUILD_MASTER', and
	'SFUN_GUILD_TITLES'.
</p>
<dl><dt>SFUN_GUILD_BASIS</dt>
<dd>This initializes the master and the only argument is the guild name</dd></dl>
<pre>	special SFUN_GUILD_BASIS "Udgaard Fighter"
</pre>
<dl><dt>SFUN_GUILD_MASTER</dt>
<dd>The guild master function takes 6 arguments.  Like the teacher function the arguments must be surrounded by double quotes.  The strings in the arguments must be surrounded by tilde marks (~).  The following is a description of the arguments and what they do.</dd></dl>
<dl><dt>Line1</dt>
<dd></dd>
<dd>The first argument on is what the guild name is.  As in the teacher you need to pre-pend the '&amp;l' symbol so the VME doesn't mess with the formatting of the string when the guild master is compiled.</dd></dl>
<pre>	 &amp;lGuild = ~Udgaard fighter~
</pre>
<dl><dt>Line 2</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>	 This argument is what quest needs to be done before the character
	 can enter the guild.
</p>
<pre>	 Guild Enter Quest = ~Fighter Proven~
</pre>
<dl><dt>Line 3</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>	  This argument is the amount it costs to enter the guild in old
	  gold pieces.
</p>
<pre>	 Guild Enter Cost = 640
</pre>
<dl><dt>Line 4</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>	  this argument is the quest the player must do before leaving the
	  guild.  If the player has not completed this quest the guild master
	  will not let the player leave.
</p>
<pre>	Guild Leave Quest = ~Wimp proven~
</pre>
<dl><dt>Line 5</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>	 This argument is how much old gold pieces it will cost to quit
	 the guild.  If the player doesn't have enough money the guild master
	 will not let the player join.
</p>
<pre>	Guild Leave Cost = 3200
</pre>
<dl><dt>Line 6</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>	 This argument is what guild the guild master will not accept
	 players from.  For example the following will make it so no Thief can
	 be in the fighter guild.
</p>
<pre>	Guild Exclude Quest = ~Udgaard Thief Quitter~
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>When we refer to old gold pieces they represent the VME money system as shown in (Link to oldgold)</p></blockquote>
<p>	The following is what a full 'SFUN_GUILD_MASTER'
	function would look like
</p>
<pre>	special SFUN_GUILD_MASTER
	"&amp;lGuild               = ~Udgaard fighter~
	Guild Enter Quest    = ~Fighter Proven~
	Guild Enter Cost     = 640
	Guild Leave Quest    = ~Wimp proven~
	Guild Leave Cost     = 3200
	Guild Exclude Quest  = ~Udgaard Fighter Quitter~"
</pre>
<dl><dt>SFUN_GUILD_TITLES</dt>
<dd>This function allows the player to request a title at the guild master.  A title will be given every 5 levels up to level 100 so you have 20 titles you can set.  The title function takes one title for male chars and one title for female chars so you have to set 40 titles.</dd></dl>
<p>	The arguments of this function are easy.  The first thing you do is
	the normal '&amp;l' to let the VME know not to mess with this string.
	Then you put the guild name.  Finally you follow it by the list of 40
	titles.   The following is the fighter guilds title list
</p>
<pre>	special SFUN_GUILD_TITLES
	"&amp;lUdgaard fighter
	the %s Swordpupil
	the %s Swordpupil
	the %s Recruit
	the %s Recruit
	the %s Sentry
	the %s Sentress
	the %s Fighter
	the %s Fighter
	the %s Soldier
	the %s Soldier
	the %s Warrior
	the %s Warrior
	the %s Veteran
	the %s Veteran
	the %s Swordsman
	the %s Swordswoman
	the %s Fencer
	the %s Fenceress
	the %s Combatant
	the %s Combatess
	the %s Hero
	the %s Heroine
	the %s Myrmidon
	the %s Myrmidon
	the %s Swashbuckler
	the %s Swashbuckleress
	the %s Mercenary
	the %s Mercenaress
	the %s Swordmaster
	the %s Swordmistress
	the %s Lieutenant
	the %s Lieutenant
	the %s Champion
	the %s Lady Champion
	the %s Dragoon
	the %s Lady Dragoon
	the %s Cavalier
	the %s Cavalier
	the %s Knight
	the %s Lady Knight"
</pre>
<p>Put all three of these functions on your NPC and your all set you
	have a guild master.
</p>
<h4><span class="mw-headline" id="NPC_banker">NPC banker</span></h4>
<p>	The banker function is the easiest 'special' function there is to
	use.  The following placed on an NPC will make a banker:
</p>
<pre>	special SFUN_BANK
</pre>
<p>As you see its very simple, so we will just show you a completed banker
	and leave it at that.
</p>
<pre>	bob

	names {"Bob"}
	title "Bob"
	descr "Bob the Banker is here, sitting behind the counter."
	extra {}
	"He has a very serious look on his face."

	// define from composed.h
	M_SHOP_KEEPER(4, SEX_MALE, RACE_HUMAN)

	//discourage people from killing banker
	exp -500

	flags {UNIT_FL_NO_TELEPORT}

	special SFUN_BANK
	end
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section-DIL-functions-for-NPCs" title="Manual:Zone Manual/The NPC Section/DIL functions for NPCs">Previous: DIL functions for NPCs</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section-Dragon-station-with-rooms-and-NPCs" title="Manual:Zone Manual/The NPC Section/Dragon station with rooms and NPCs">Next: Dragon station with rooms and NPCs</a></div></div>