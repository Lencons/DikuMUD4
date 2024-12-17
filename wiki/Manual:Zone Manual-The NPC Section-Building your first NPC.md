<div class="mw-parser-output"><h3><span class="mw-headline" id="Building_your_first_NPC">Building your first NPC</span></h3>
<p>	Now that you have built your first zone with rooms its time to
	populate it with Non playing characters for your players to hunt, kill,
	and or interact with.  In the last couple of sections you have looked
	through the fields.  In this section we are going to make a nice easy
	NPC and then show how to use the <i>composed.h</i> to make
	your NPC building easier.  As I have previously stated in the section on
	room building I like dragons so the first NPC your going to learn to
	build is a big bad ugly dragon.  Don't worry if you hate dragons or you
	just want to build a normal world you will learn plenty from my dragon
	example to be able to adjust it to whatever you want.
</p><p>	When making NPCs you create the zone source file first as shown
	in (Link to ch-02).  If you only have NPCS you do not need the
	%reset, %objects, and %rooms fields.  For the examples in this chapter we
	will use the zone we created in (Link to ch-04) and add the
	%mobiles section where we will put all the NPC definitions.  At the end
	of this chapter, in (Link to roomnpczone), we will bring it all together with the rooms we have
	already defined and our NPCs.
</p><p>	The first part of all NPC definitions is the symbolic name it is good
	to always pick a name that will match the name of the NPC so it
	will be easy to load the NPC.
	The reason the symbolic and name should match is when you use the
	command <b>wstat</b> it will only show you a
	list of the NPCs by symbolic name for example if you type <b></b>
	wstat zone dragon mobiles <b> You will get the following:</b>
</p>
<pre>	List of mobiles in zone Dragon:
	dragon clerk trashman
</pre>
<p>If you didn't make it clear what the NPC was by the symbolic name
	it might look like this:
</p>
<pre>	List of mobiles in zone Dragon:
	npc1 npc2 npc3
</pre>
<p>While this might be great when you first start imagine trying to
	remember each NPC if you have over 30 of them.
</p><p>	Now lets get started with our dragon.  As with the rooms all that is required to make a NPC is the symbolic and end fields.  That of course will make a NPC with all defaults.
</p>
<pre>	bldragon
	end
</pre>
<p>Thats it for that dragon right?  Nope not quite that makes a NPC
	with all defaults.  That means this will probably be a very wimpy human
	with a symbolic name of dragon and no description, in short it will be a
	blank when you load it.  Now lets start putting the Dragon
	together.
</p><p>	The first three things we need are the dragons title, description
	and names.  The description should be what you see when you do a 'look'
	in the room.  The title should be what you see when the NPC is talking
	or fighting.  Finally the names should cover everything in the title and
	description fields so if you wanted to kill them you can easily
	know what to type.
</p>
<pre>	bldragon

	title "a black dragon"
	descr "A big ugly black dragon is clawing the ground here."
	names {"big ugly black dragon","ugly black dragon","big black dragon",
	"black dragon","dragon"}
	...
	end
</pre>
<p>The names, title and description shouldn't be to hard so I don't
	think its necessary to go into any more description on the subject.
	Lets move on.  Now we have to take care of what a player sees when he or
	she looks at a NPC.  to make the main description of an NPC you place an
	extra on the NPC with no names in the list.  The blank extra is a
	special extra that will be shown every time you look at anything in the
	names list of the NPC.  So a description of a NPC would look something
	like this.
</p>
<pre>	extra {}
	"The black dragons scales glitter like black granite that has been
	polished for years by water.  He has a large neck and huge bat like
	wings.  his eyes watch you as you stand before him.  One claw seems to be
	tapping slightly on the ground as if the dragon is waiting for
	something."
</pre>
<p>Now that you have a main description for the NPC you need to make
	any smaller descriptions that you want the player to be able to look at.
	In this case the dragon eyes and claw would be good things to describe
	and maybe a few other things just for humor.
</p>
<pre>	extra {"eyes","eye"}
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
</pre>
<p>Now that we have the NPC all described we should start setting
	     things like race, gender, level, height, weight, defense, offense,
	     alignment, abilities, and finally skills and spells.  First we will pick a race.  Normally the
	     list of races are in your <i>values.h</i>.  We have
	     the list in (Link to app-c) and I have searched for dragon
	     and found the race I want it is as follows.
</p>
<pre>		race RACE_DRAGON_BLACK
</pre>
<p>If you don't think there is any difference in dragons you can
		 set them all to one race like you could define a race called
		 'RACE_DRAGON' or something like that.
</p><p>		 Now we should chose the gender of our dragon.  Make sure your
	descriptions match what you pick.  It would be pretty weird to have a
	female dragon and have the descriptions say 'he, him, or his'
</p>
<pre>		    sex SEX_MALE
</pre>
<p>Now lets set the height and weight.  Remember you set the height
	in centimeters and the weight in pounds.  In the future the VME will
	standardize to one or the other but for now we have to play the
	conversion game.
</p>
<pre>	//20 feet  (1 inch = 2.54 cm
	height 625

	//566 KG (1 lb. = .45359 kg)
		 weight 1250
</pre>
<p>Now that we have the size of the dragon we can pick a level.
		 My dragon is only 20 feet tall and 1250 pounds so I think maybe he
		 is a bit young and will make his level around 70.
</p>
<pre>		 level 70
</pre>
<p>The dragon may not wear armour but by default a dragon should
		 have an armour equal to someone wearing plate mail.  Not only that
		 but my dragon doesn't like to use his mouth as his natural attack
		 and he sure can't punch with those big claws so we need to set his
		 attack type to claw.
</p>
<pre>		 NATURAL_DEF(WPN_CLAW, ARM_PLATE)
</pre>
<p>Not many black dragons are good so I will pick almost totally
	evil, since totally evil is -1000 I will set it as follows.
</p>
<pre>		 alignment -900
</pre>
<p>Finally we get to the hard part.  Many people have trouble
	setting the NPC abilities, weapons, and spells.  There really is nothing
	to it if you have read (Link to npcmacroability) and (Link to npcmacroweapspl).  The only thing you have to remember is the
	numbers you are putting are not the actual amount but a percentage of
	the skill points you want the game to use on your NPC when having your
	NPC practice as it loads and all amounts of abilities must add up to
	100% as well as all weapons and spells must add up to 100%.  For the
	dragon the following would be what the abilities, weapons, and spells
	would look like.
</p>
<pre>	//big strong and magical most ability points on str and mag
	MSET_ABILITY(20,12,12,12,12,12,20,0)

	//Set natural attack highest of weapons because he fights with claws
	MSET_WEAPON(10,10,10,5,30,5)

	//black dragons have natural defense from acid set it highest
	MSET_SPELL(0,0,0,0,0,0,0,0,0,0,30)
</pre>
<p>That is all you need to make a basic dragon.  True this dragon
	will not do anything but claw you to death if you attack it but in (Link to npccomplex) we will give the dragon some more abilities with
	some special DIL functions.  For now lets take a look at our finished
	product.
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

	extra {"eyes","eye"}
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
		 NATURAL_DEF(WPN_CLAW, ARM_PLATE)
		alignment -900
	MSET_ABILITY(20,12,12,12,12,12,20,0)
	MSET_WEAPON(10,10,10,5,30,5)
	MSET_SPELL(0,0,0,0,0,0,0,0,0,0,30)

	end
</pre>
<p>As you can see there is a bit more to building an NPC than a room
	but its really not that much harder.  Try changing some stuff and make
	sure to practice debugging your errors the more compiling you do the
	better you will get.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section-NPC-macros" title="Manual:Zone Manual/The NPC Section/NPC macros">Previous: NPC macros</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section-Compiling-and-debugging-your-first-NPC" title="Manual:Zone Manual/The NPC Section/Compiling and debugging your first NPC">Next: Compiling and debugging your first NPC</a></div></div>