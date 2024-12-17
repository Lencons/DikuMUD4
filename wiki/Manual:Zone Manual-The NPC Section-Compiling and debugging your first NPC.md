<div class="mw-parser-output"><h3><span class="mw-headline" id="Compiling_and_debugging_your_first_NPC">Compiling and debugging your first NPC</span></h3>
<p>	As we have previously mentioned in (Link to rmdebug) it is
	always a good idea to build one or two things and then compile to make
	finding errors easy.  In this case we have one NPC to compile and rather
	than having all the rooms get in my way while compiling it I have
	removed them and only have the '%mobiles' section.  The following is
	what the zone looks like when it has only one NPC in it.
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

	%mobiles

	bldragon

	title "a black dragon"
	descr "A big ugly black dragon is clawing the ground here."
	names {"big ugly black dragon","ugly black dragon","big black dragon",
	"black dragon","dragon"}

	extra
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
	MSET_ABILITY(21,12,12,12,12,12,20,0)
	MSET_WEAPON(10,10,10,5,30,5)
	MSET_SPELL(0,0,0,0,0,0,1,0,0,0,30)

	end

	%end
</pre>
<p>I removed the '%rooms' section added a '%mobiles' section and
	stuck the dragon in and now its ready to be compiled and put into the VME
	server for you to be able to look at it in the game.  If you downloaded
	our example zones for this document you can compile this zone along with
	us and fix the errors as we do for practice.  The filename is
	<i>debug_npc.zon</i>.  Just so you know the errors in this
	zone are intentional so please don't write me an email telling me that
	there are errors in it.
</p><p>	The command to compile the zone is
	<b>VMC debug_npc.zon</b>.
	Here is what we get when we first try and
	compile the zone.
</p>
<pre>	VMC v2.0 Copyright (C) 2001 by Valhalla [May  9 2001]
	Compiling 'debug_npc.zon'
	debug_npc.zon: 32: parse error
	   Token: 'extra'
	debug_npc.zon: 55: parse error
	   Token: 'alignment'
	Compilation aborted.
</pre>
<p>This error file doesn't look any harder than the last one we dealt
	with when compiling our first room.  The problem is when we go to line
	'32' and look for an error we don't find one.  This normally means that
	the error was hard for the compiler to figure out.  The best way to deal
	with an error like this is to start at the line it gives you and go up
	and look for an error.  When we do this we notice that the extra right
	above the line that the error is on is missing '{}' so we will add them
	back in.  Most of the time you want to do one error and recompile but
	sometimes you can shorten the process for example in this error file
	the word 'alignment has been spelled wrong so we can fix that before we
	recompile so go to line '56' and fix that.  Now with those two errors
	fixed we can recompile and this is what we get:
</p>
<pre>	VMC v2.0 Copyright (C) 2001 by Valhalla [May  9 2001]
	Compiling 'debug_npc.zon'
	FATAL: Abilities in 'bldragon' sums up to 101,and not 100.
	FATAL: Spells&amp;weapons in 'bldragon' sums up to 101, and not 100.
	WARNING: Fatal errors in zone.
</pre>
<p>As we have said before you have to make sure that abilities add up
	to 100 percent this error is telling us that my math sucks and that I
	have added 1 extra percent to the abilities.  Not only that but again if
	we look at both errors I have also put 1 extra on weapons and spells.
	So we can fix both of these at once.  Notice it doesn't give a line
	number but that is not a problem because you can search for 'MSET_ABIL'
	and it will take you right to the problems.  After I subtract one from the
	abilities and one from either the spells or weapons the following is the
	error file I get.
</p>
<pre>	VMC v2.0 Copyright (C) 2001 by Valhalla [May  9 2001]
	Compiling 'debug_npc.zon'
	VMC Done.
</pre>
<p>Notice there are no errors and it says 'VMC done', this means that
	you have now successfully compiled the zone. The main thing I want to
	point out is that you can sometimes fix more than one error at a time
	but be carefull when doing this if you try to fix some errors before
	fixing the first you will be trying to fix things that are not broken.
	The safest way to compile stuff is still fix one error at a
	time.
</p><p>	Now that you have a compiled zone you should check and make sure
	that all the files are there.  When you compile a zone you will end up
	with  three extra files. the files will have the same filename as your zone
	with a new extension in this case you should have the following.
</p>
<pre>	debug_npc.data
	debug_npc.err
	debug_npc.reset
	debug_rm.zon
</pre>
<p>If you have all of these you are all set to go.  If not then there
	is something seriously wrong and you may want to write the VME staff for
	help.
</p><p>	  To get your new zone in the mud all that is needed is to make
	sure your zone is in the zonelist in the VME etc directory and copy
	these files into your zone directory.  Then reboot the mud.  You should
	be able to log on your builder character and load your NPC by typing
	<b>load bldragon@dragonst</b> and
	you can list your zones NPCs by typing <b>wstat zone dragonst</b>
	mobiles<b>.</b>
</p><p>	There you go you have now compiled your first NPC.  As you can see
	with as little as you have learned so far you can already make a variety
	of monsters and NPCs of any kind.  The next section will cover the DIL
	functions you can use with a NPC and then we will get right into some
	more complex examples.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section-Building-your-first-NPC" title="Manual:Zone Manual/The NPC Section/Building your first NPC">Previous: Building your first NPC</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section-DIL-functions-for-NPCs" title="Manual:Zone Manual/The NPC Section/DIL functions for NPCs">Next: DIL functions for NPCs</a></div></div>