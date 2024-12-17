<div class="mw-parser-output"><h3><span class="mw-headline" id="Compiling_and_debugging_your_first_room">Compiling and debugging your first room</span></h3>
<p>	It is time we put the zone header information together with
	your first zone and compile it into a format the VME server can
	use.  This is done by using the VMC compiler.  Depending on if you
	are doing this on your own Linux server or if you are building for a
	VME already set up you will have to use the compiler access
	method they have defined.  No matter if you are compiling by email,
	ftp, or at the command line with VMC the error messages will all be
	the same.  Since I have no idea how your particular set up is
	designed I will explain the errors that the compiler will return and
	you will have to ask your system administrator how to access the
	compiler.  The rest of this section is written as if you have your
	own VME running on your own Linux box using the VMC at the command
	line.
</p><p>	When you are working on your first zone it is always a good
	idea to start with one or two rooms and compile them instead of
	writing all the rooms and then trying to compile.  The reason is the
	more rooms you have the more confused you can make the compiler if
	you have a lot of errors and you may not be able to figure out where
	your first mistake was easily.  In our case we only have our first
	room and the header information for the zone so lets put it together
	now and try and compile it.
</p>
<pre>	#include composed.h&gt;
	%zone dragonst
	lifespan 20
	reset RESET_ANYHOw
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
	title "The middle chamber of the station
	descr
	"This chamber seems to have the entire station rotating around it.
	Small human size ornate chairs with dragon designs scrawled on the
	arms and back are arranged in a triangle like setting with one large
	chair at the front.  This must be where all station meetings are held.
	large pictures cover the walls depicting dragons in all kinds of
	situations.  Small passages lead of to the west and the east.
	."

	extra {"chair","chairs"}
	"The chairs are made of some metal you don't recognize and every inch is
	covered with some kind of dragon."

	extra  {"dragon picture","picture"}
	"Thousands of dragons dot the skies of this rather life like picture.  In the
	center you see something move.  It looks to be a little green dragon."

	extra{"green dragon","dragon","green"}
	"An intelligent looking dragon is sitting perched on a large chair watching you."
	west to portal descr "You see a small room.";

	east to office descr "You see what looks to be an office.";
	end

	%end
</pre>
<p>We added the %room tag to our zone header stuck our room in
	and now its ready to be compiled and put into the VME server for
	you to be able to look at it in the game.  If you downloaded our
	example zones for this document you can compile this zone along with
	us and fix the errors as we do for practice.  The filename is
	<i>debug_rm.zon</i>.  Just so you know the errors in this
	zone are intentional so please don't write me an email telling me
	there are errors in it.
</p><p>	The command to compile the zone is
	<b>VMC debug_rm.zon</b>.
	Here is what we get when we first try and
	compile the zone.
</p>
<pre>	VMC v2.0 Copyright (C) 2001 by Valhalla [Apr 28 2001]
	Compiling 'debug_rm.zon'
	&lt;debug_rm.zon&gt; @ 2: Bad include argument
	&lt;debug_rm.zon&gt; @ 48: Token too long
	Fatal error compiling in preprocessor stage in file 'debug_rm.zon'.
</pre>
<p>Don't worry if this looks scary, it really is much easier to read than it looks like.
	The first thing you need to realize about compiling is always fix one error
	and compile again because it might fix two or three errors after
	with one fix.  The reason is once a compiler hits something it
	doesn't understand it gets confused with the rest of the file.  It
	is sort of like if you thought the word 'water' meant 'fire' and you
	tried to read a book it would get confusing really fast.  So you have
	to correct the definition of 'water' to understand the rest of the
	book.
</p><p>	Lets take the first error with this in mind.  The first error
	shows up on line three of the error file it says:
</p>
<pre>	&lt;debug_rm.zon&gt; @ 2: Bad include argument
</pre>
<p>This line is not really cryptic reading it in a more english form
	would sound like:  In file 'debug_rm.zon' you have an error at line 2, the
	argument to the include statement is not correct.  Not all errors will
	be this clear but the compiler does its best to get you close to the
	error.  Now if you look at line two in <i>debug_rm.zon</i>,
	you will find, we forgot to put in the '&lt;' symbol.  If you fix
	the line to look like:
</p>
<pre>	#include &lt;composed.h&gt;
</pre>
<p>Then recompile you will have fixed your first error and get a whole new
	set to play with.  The following is the errors we got after fixing line
	two:
</p>
<pre>	VMC v2.0 Copyright (C) 2001 by Valhalla [May  9 2001]
	Compiling 'debug_rm.zon'
	&lt;debug_rm.zon&gt; @ 47: EOF in string
	debug_rm.zon: 4: parse error
	   Token: 'RESET_ANYHOw'
	debug_rm.zon: 21: parse error
	   Token: 'This'
	debug_rm.zon: 26: parse error
	   Token: 'and'
	debug_rm.zon: 26: parse error
	   Token: '.'
	Grave errors in file 'debug_rm.zon'.
</pre>
<p>Now this looks to be a much more interesting error file than the
	previous one.  Remember we mentioned you should always fix the
	first error first so the compiler doesn't get confused.  In this error
	file the first line is not the first error we need to fix.  We have
	to do some logical reasoning here.  The first error the compiler
	came across was the one on line 4 that shows up around line 4 of the
	error file.  The lines before it are letting you know somewhere
	else in the file there is a missing quote.  If we clean up the first
	error however we might be able to find this missing quote much easier.
	So lets do that lets start by looking at line 4 which is saying the
	compiler doesn't understand what the token 'RESET_ANYHOw' is.  This
	makes sense the token should be 'RESET_ANYHOW' and the compiler is
	case sensitive.  So all we need to do to fix this one is capitalize the
	'w' and the error should be cleared up lets try that and recompile and
	see what the errors look like.  With that line fixed the following is
	the errors we get.
</p>
<pre>	VMC v2.0 Copyright (C) 2001 by Valhalla [May  9 2001]
	Compiling 'debug_rm.zon'
	&lt;debug_rm.zon&gt; @ 47: EOF in string
	debug_rm.zon: 21: parse error
	   Token: 'This'
	debug_rm.zon: 26: parse error
	   Token: 'and'
	debug_rm.zon: 26: pars
	e error
	   Token: '.'
	Grave errors in file 'debug_rm.zon'.
</pre>
<p>Again we must figure out which error message we should deal with
	first.  As before we need to deal with the lowest number error.  The
	error we need to fix first then is the one on line '21'.  If you go
	to line '21' you will notice the line looks fine.  When you run
	into an error like this where the error is not exactly on the line
	scroll up to the field before the one in question and you should find the
	problem.  In this case we forgot a '"' on the 'title' line and
	confused the compiler because it thought the ending quote was the one
	after the 'descr' field.  Therefore the compiler didn't understand the
	'This' as a field.  This is one of the harder errors to find but once
	you get used to it will come naturally and the compiler does try to
	get you close.  Now if we add the '"' we are missing and recompile
	the following is the output we get.
</p>
<pre>	VMC v2.0 Copyright (C) 2001 by Valhalla [May  9 2001]
	Compiling 'debug_rm.zon'
	VMC Done.
</pre>
<p>Notice there are no errors and it says 'VMC done', this means
	you have now successfully compiled the zone.  I want you to look at the
	last error file and the fact that we only changed a quote to go from it
	to no errors.  This is why you always deal with one error at a time.
	Sometimes fixing one error can fix a lot of the weird errors that make
	no sense.  In fact I have seen one quote cause as much as 50 errors so
	if you jump around trying to fix errors that look like they make sense
	you may end up making more work for yourself.
</p><p>	Now that you have a compiled zone you should check and make sure
	all the files are there.  When you compile a zone you will end up
	with  three extra files. the files will have the same filename as your zone
	with a new extension in this case you should have the following.
</p>
<pre>	debug_rm.data
	debug_rm.err
	debug_rm.reset
	debug_rm.zon
</pre>
<p>If you have all of these you are all set to go.  If not then there
	is something seriously wrong and you may want to write the VME staff for
	help.  To get your new zone in the mud all that is needed is to make
	sure your zone is in the zonelist in the VME etc directory and copy
	these files into your zone directory.  Then reboot the mud.  You should
	be able to log on your builder character and goto your zone by typing,
	<b>goto chamber@dragonst</b>.
</p><p>	There you go you have now compiled your first zone.  Its not much
	to look at but with what you already know you could make a full zone of
	very basic rooms.  The next few sections will teach you some of the more
	interesting things you can do when making your rooms.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section-Building-your-first-room" title="Manual:Zone Manual/The Room Section/Building your first room">Previous: Building your first room</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section-DIL-functions-for-rooms" title="Manual:Zone Manual/The Room Section/DIL functions for rooms">Next: DIL functions for rooms</a></div></div>