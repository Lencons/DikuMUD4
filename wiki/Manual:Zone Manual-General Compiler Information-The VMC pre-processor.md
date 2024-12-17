<div class="mw-parser-output"><div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1 tocsection-1"><a href="#The-VMC-pre-processor"><span class="tocnumber">1</span> <span class="toctext">The VMC pre-processor</span></a>
<ul>
<li class="toclevel-2 tocsection-2"><a href="#Commenting-your-zone"><span class="tocnumber">1.1</span> <span class="toctext">Commenting your zone</span></a></li>
<li class="toclevel-2 tocsection-3"><a href="#Macros-and-what-they-can-do-for-you"><span class="tocnumber">1.2</span> <span class="toctext">Macros and what they can do for you</span></a></li>
<li class="toclevel-2 tocsection-4"><a href="#Including-other-files-in-your-zone"><span class="tocnumber">1.3</span> <span class="toctext">Including other files in your zone</span></a></li>
<li class="toclevel-2 tocsection-5"><a href="#Doing-minor-calculations"><span class="tocnumber">1.4</span> <span class="toctext">Doing minor calculations</span></a></li>
</ul>
</li>
</ul>
</div>

<h3><span class="mw-headline" id="The_VMC_pre-processor">The VMC pre-processor</span></h3>
<p>		The VMC Pre-Processor (VMC -p) can be thought of as a powerful
		search and replace tool used by the compiler before it
		converts the zone to its binary form.  This tool gives you the
		builder the ability to add comments, create short hand expressions
		for repeated items, include other files in your zone, and even to do
		some minor calculations when necessary.
</p>
		<blockquote style="background-color: #E8E8E8; font-style: italic;"><p> If you have coded in C or c++ before the Pre Processor the VMC uses is no different and you can skip this section. </p></blockquote>
<h4><span class="mw-headline" id="Commenting_your_zone">Commenting your zone</span></h4>
<p>		The practice of adding comments to your zone is a good thing
		to get into so the administrators and other builders can help
		you with your zone and know what you were trying to do if there are
		problems.  Comments aren't as important when writing the zone as
		they will be when you start writing your own special DIL functions
		but it is important to know how comments work and that you can use
		them if you need to.  A comment is a block of text the compiler
		will never see and is there only for you and who ever reads the
		file.  In order to make it so the compiler will not see the block of
		text you must surround it by a set of symbols that tell the CPP to
		strip it out before passing the zone on to the compiler.  These
		symbols are the '/*' and the '*/' symbols or the '//' symbols together in front of a single line.
</p><p>		In order to best explain how comments work we will give you a some
		what strange example.  First we will start by showing you a very basic
		line you will see time and time again in rooms.
</p>
<pre>	title "this is a title"
</pre>
<p>This is a title it will show up in everything from rooms, to objects
		and even NPCs.  Now lets see what a commented line would look like.
</p>
<pre>	//I am going to make a title now
	title /* I put the keyword
	first*/ "this is a title/*then the title*/
</pre>
<p>This of course is very ugly but the point is not to be pretty it is
		to show you both the first way and the second way will look
		exactly the same to the compiler because all comments are removed
		before the compiler ever gets it.  A better use of a comment in a
		zone however would be something like this:
</p>
<pre>	/*
	The following ten rooms are the vineyards,
	there are 97 rooms in the zone.
	*/

	//Zone first created 1994
</pre>
<p>You will find comments will make coding large zones much easier
		because you can add text meant just for the builders
		eyes.
</p>
		<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>You will have to decide if you want a multi-line comment or a single line comment and use the '//' or the '/**/' respectively.  The rule of thumb is if the comment is longer than 1 line it is easier to put the '/**/' around the comment than to comment each individual line.</p></blockquote>
<h4><span class="mw-headline" id="Macros_and_what_they_can_do_for_you">Macros and what they can do for you</span></h4>
<p>		When making a zone you will find there are things you use more
		than once.  In fact you may find things you want others to use or
		things you want to use in multiple zones.  Its true you could block
		and copy and stick them everywhere. in fact that is what I did when
		I first started building.  I soon found my zone file was
		extremely large and hard to upkeep.  With a few minor changes and a
		lot of deleting I used short hand or better known in the world of coding
		as macros to make my zone readable.
</p><p>		Lets say you had some flags you were going to set in
		fifty rooms and you knew they would all be the same.  You could type
		the following line 50 times.
</p>
<pre>	flags {UNIT_FL_NO_WEATHER, UNIT_FL_CAN_BURY}
</pre>
<p>With the macros however you could make this much easier by just doing
		the following at the beginning of your zone.
</p>
<pre>	#define DIRTFLOOR flags {UNIT_FL_NO_WEATHER, UNIT_FL_CAN_BURY}
</pre>
<p>Then where ever you want the flags you just type DIRTFLOOR.  You are
		probably thinking, yeah big deal I can do that with block and copy.
		True but there is another benefit to this.  Lets say later you
		wanted to also make these 50 rooms no teleport.  All you would have
		to change is the define like this:
</p>
<pre>	#define DIRTFLOOR flags {UNIT_FL_NO_WEATHER,UNIT_FL_CAN_BURY,UNIT_FL_NO_TELEPORT}
</pre>
<p>Now when you recompile all 50 rooms are changed and you didn't even
		have to do a search and replace.
</p><p>		You can also make macros that take arguments.  The ability to
		take arguments is where macros take a leap and a bound out in front
		of your favorite editor to allow you to do things you can not do easily
		with search and replace.  Lets say you have an exit descr you
		want to use in 50 swamp rooms because heck everything looks the same
		in a swamp when you look one direction to the next.
</p>
<pre>	east to swamp1 descr
	"You see the swamp stretch out for miles";
</pre>
<p>This could be made into a macro like:
</p>
<pre>	#define sexit(direction, place) direction to place descr \
	"You see the swamp stretch out for miles.";
</pre>
<p>Then all you need to use it is:
</p>
<pre>	SEXIT(east,swamp1)
	SEXIT(north,swamp2)
	SEXIT(south,swamp3)
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>There is no space between 'SEXIT' and '(' that is important because the CPP sees 'SEXIT(' and 'SEXIT (' as two different things.  It is also important to notice all defines must start at the beginning of the line and be either one line long or have a '\' telling the Pre Processor that it should continue with the next line as if it was this line.</p></blockquote>
<p>		You can also combine macros together so you have a set
		of macros like:
</p>
<pre>	#define DIRTFLOOR flags {UNIT_FL_NO_WEATHER,UNIT_FL_CAN_BURY,UNIT_FL_NO_TELEPORT}
	#define DIRTSECT  movement SECT_INSIDE \
	DIRTFLOOR
</pre>
<p>You may have noticed I capitalize all macros.  This is not a must but it is
		suggested so you can easily tell what is a macro and what is not.
</p>
<h4><span class="mw-headline" id="Including_other_files_in_your_zone">Including other files in your zone</span></h4>
<p>		Another function of the VMC Pre Processor,
		'#include', allows you to include other files  in
		your zone file.  The VME comes with some basic include files
		you can use the macros out of and use as examples on how to make
		your own include files.  These files are the
		<i>composed.h</i>,, <i>vme.h</i>,
		<i>values.h</i>, <i>base.h</i>,
		<i>liquid.h</i>, and <i>wmacros.h</i>.
		Including <i>composed.h</i> will include all the rest
		of
		the include files into your zone because it has include statements
		that use all the others.
</p>
		<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>You will want to include the files at the beginning of your zone file because all defines you use must be defined before you use them.</p></blockquote>
<h4><span class="mw-headline" id="Doing_minor_calculations">Doing minor calculations</span></h4>
<p>		 You can also do minor calculations in a macro.  Lets say you
		wanted to make it so the higher level an NPC was the heavier he
		was and the taller he was.  This would be simple with a macro.
</p>
<pre>	#define MLEVEL(lvl) \
	level lvl \
	height lvl+72 \
	weight lvl*9
</pre>
<p>This macro would increase the height and weight depending on what
		level you made the NPC pretty simple.  There is much more a macro
		can	do for you but the Pre Processor and all its uses go far beyond the scope
		of this manual.  If you are really interested in all the neat things
		it can do type the following command at the '$' prompt on your
		Linux box.
		<b>man cpp</b>
		The C-Pre Processor is what the VMC Pre Processor is based on and most
		if not all functions of the CPP work in the VMC.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-General-Compiler-Information" title="Manual:Zone Manual/General Compiler Information">Previous: General Compiler Information</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-Zone-Source-File" title="Manual:Zone Manual/Zone Source File">Next: Zone Source File</a></div></div>