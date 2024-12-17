<div class="mw-parser-output"><h3><span class="mw-headline" id="Compiling_and_Debugging_your_first_object">Compiling and Debugging your first object</span></h3>
<p>	As we have previously mentioned in (Link to rmdebug) and
	(Link to npcdebug) it is always a good idea to build one or two
	things and then compile to make finding errors easy.  In this case we
	have one object to compile and rather than having all the rooms and NPCS
	get in my way while compiling it I have removed them and only have the
	'%objects' section.  The following is what the zone looks like when it
	has only one object in it.
</p>
<pre>	#include &lt;composed.h&gt;
	%zone dragonst
	lifespan 20
	reset RESET_ANYHOW
	creator {"whistler"}

	notes
	"This is the dragon station I shortened it to dragonst for ease in
	loading.  If you have  any questions email me at whistler@valhalla.com"

	help
	"Not sure what could help you now.  You are stuck on one of the
	weirdest space stations you have ever seen and you smell burning
	sulfur."

	%objects

	dragon_head

	title "a gold dragon head"

	descr "A large golden dragon head is laying here looking sad."

	names {"large golden dragon head","large gold dragon head,
	       "golden dragon head","large dragon head","gold dragon head",
	       "dragon head","large head", "sad head","head"}

		   extra {}
	"The head is large and beautiful, at least as beautiful as a dead
	dragon head can be.  There is an extreme look of sorrow on the dragons
	face and it seems to be for much more than its own death."

	extra {"gold dragon head face","dragon head face","head face","face"}
	"Looking into the dragons face your eyes are drawn to the eyes of the
	dead dragon.  Could there be something there?"

	extra {"eyes","eye"}
	"A world of blue skies and no storms is visible through the eyes and it
	seems to be moving as if you were watching the world from space."

	manipulate MANIPULATE_TAKE,MANIPULATE_HOLD

	height 33
		 weight 50

	extra {"$get_s"}
	"You suddenly feel very sad for a world that you don't even know."

	extra {"$get_o"}
	"A strange look of sadness crosses $1ns face."

	extra {"$drop_s"}
	"You feel much happier but you remember a feeling of great sorrow."

	extra {"drop_o"}
	"$1n seems to cheer up a bit."

	end

	%end
</pre>
<p>I removed the '%rooms' and '%mobiles' sections added a '%objects' section and
	stuck the dragon head in and now its ready to be compiled and put into the VME
	server for you to be able to look at it in the game.  If you downloaded
	our example zones for this document you can compile this zone along with
	us and fix the errors as we do for practice.  The filename is
	<i>debug_obj.zon</i>.  Just so you know the errors in this
	zone are intentional so please don't write me an email telling me that
	there are errors in it.
</p><p>	The command to compile the zone is
	<b>VMC debug_obj.zon</b>.
	Here is what we get when we first try and
	compile the zone.
</p>
<pre>	VMC v2.0 Copyright (C) 2001 by Valhalla [May  9 2001]
	Compiling 'debug_obj.zon'
	&lt;debug_obj.zon&gt; @ 65: EOF in string
	debug_obj.zon: 5: parse error
	   Token: '{'
	debug_obj.zon: 25: parse error
	   Token: 'golden'
	Grave errors in file 'debug_obj.zon'.
</pre>
<p>This error file doesn't look any harder than the last one we dealt
	with when compiling our first room or NPC.  We can not stress enough
	always fix the smallest numbered error first.  In this case the lowest
	numbered error shows up in line five of the zone.  The error says
	something is wrong with the '{' but looking at the line it is obvious
	the compiler got confused because I forgot 's' at the end of 'creators'.
	 If we fix line five and recompile this is what we get:
</p>
<pre>	 VMC v2.0 Copyright (C) 2001 by Valhalla [May  9 2001]
	Compiling 'debug_obj.zon'
	&lt;debug_obj.zon&gt; @ 65: EOF in string
	debug_obj.zon: 25: parse error
	   Token: 'golden'
	Grave errors in file 'debug_obj.zon'.
</pre>
<p>Now we have come to another one of those weird errors.  If you
	look at line 25 you will find that the line looks like it is correct.
	As we have said before when you find an error like this it most likely
	means that you are missing a quote or a '{}'.  The only way to find the
	problem is start at the quote or '{}' before the word in the error and
	go backwards through the file till you find a missing one.  Lucky for us
	the missing one is in the very next string.  If you add a double quote
	just before the ending comma on line 24 and recompile you will get the
	following:
</p>
<pre>	VMC v2.0 Copyright (C) 2001 by Valhalla [May  9 2001]
	Compiling 'debug_obj.zon'
	debug_obj.zon: 42: parse error
	   Token: ','
	Compilation aborted.
</pre>
<p>This error is a little tricky.  It seems to be pointing at the ','
	as the problem.  If you look at the line though and remember what you
	need for a manipulate field you will notice that the surrounding '{}' are
	missing.  The reason the compiler is pointing at the comma is because it
	doesn't understand what to do with the comma with out the '{}' grouping
	symbols.  Fixing these and recompiling results in the following message
	from the compiler.
</p>
<pre>	VMC v2.0 Copyright (C) 2001 by Valhalla [May  9 2001]
	Compiling 'debug_obj.zon'
	VMC Done.
</pre>
<p>Notice there are no errors and it says 'VMC done', this means that
	you have now successfully compiled the zone.  This is the last debugging
	walk through in the manual.  If you still have a lot of trouble figuring
	out errors don't stress compiling is an art the more you do it the
	easier it will get.  We suggest you take the zones we have provided in
	our release and create errors so you can get used to the messages
	you will see when you are making your own zones.  Never be afraid to
	ask for help from someone else sometimes a bug is so simple you will
	over look it and sometimes it just takes a second person a single glance
	to find it.  Another trick to finding errors if you have been looking
	for more than 5 minutes take a break and come back in 10 minutes
	sometimes that short relaxing time will help you find the
	problem.
</p><p>	You have now compiled your first object.  The steps are the same
	to get it into the game as it was for the rooms and NPCs.  We will not
	go over them again except to say copy your files that the compiler made
	over into the zone directory of your mud and reboot.  From there log on
	and you should be able to <b>wstat</b> and
	<b>load</b> your object by using its full symbolic
	name.  It would be a good idea to try and get this zone into your server
	and lay with the object a bit so when you get to (Link to objcomplex) you will be ready for anything.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section-Building-your-first-object" title="Manual:Zone Manual/The Objects Section/Building your first object">Previous: Building your first object</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section-DIL-functions-for-objects" title="Manual:Zone Manual/The Objects Section/DIL functions for objects">Next: DIL functions for objects</a></div></div>