<div class="mw-parser-output"><h2><span class="mw-headline" id="General_compiler_information">General compiler information</span></h2>
<p>		In order to get your zone onto a valhalla Mud Engine (VME) server you must convert your zone from readable
		english text to binary form the server can understand.  The way
		you do this is with a compiler.  No don't freak out you don't have
		to be a skilled programmer to use a compiler.  The only thing you
		have to do is format your rooms, objects, and Non-player characters
		(NPC) in a form which the compiler can understand.  The great thing
		about the VME is you can do all your zone writing in your favorite
		editor with out having to log on to code.  For those of you who have
		coded for other mud servers and are used to coding online this may
		be a new experience to you but you will find you can plan out
		better and more well designed areas offline than you can on
		line.
</p>
	<blockquote style="background-color: #E8E8E8; font-style: italic;">
<p>		In the future the VME coding team is thinking of adding
		an	online coding module for those mud administrators that can not
		live with out it.  If you are one of these make sure you write
		whistler@valhalla.com and express your desires so
		you can be counted.
</p>
	</blockquote>
<p>		This chapter will mainly cover the Valhalla Mud Compiler (VMC), how it works, and
		the Valhalla Mud pre processor (VMC -p) works.  We will also throw in some debugging
		hints but debugging will be covered more as you begin creating parts of
		your areas in the following chapters.
</p>
<h3><span class="mw-headline" id="The_compiler">The compiler</span></h3>
<p>		<i>VMC</i> is the Valhalla Mud Engine Compiler.
		for VME servers.  A compiler takes a source file or better described
		as your areas input file and converts it to a binary file the
		server can then load and use online.  In the VME we call areas
		you build 'zones', therefore the source file for a zone has the
		extension 'zon'.  In order to make this more clear we will start
		with our first example.
</p><p>		Lets say you were making a Zone of dragons.  You may want to
		call the file something resembling its contents like,
		<i>dragon.zon</i>.  Notice we have appended the
		'.zon' extension.  The compiler requires all zones to end in '.zon'
		in order for it to know this is a zone source file.
</p><p>		Now lets say we have completed writing our first zone and want
		to compile it.  The command is simply:
		<b>VMC&gt; dragon.zon</b>
		If the zone compiles correctly it will indicate success by printing
		a message to the screen and outputting two files both with the same
		root name as the original zone source file but with different
		extensions.  In this case there would be the following:
</p>
<dl><dt><i>dragon.data</i></dt>
<dd>The file holding the binary version of the zone</dd>
<dt><i>dragon.reset</i></dt>
<dd>The file containing the reset information for the zone.</dd></dl>
<p>If the zone doesn't compile correctly and you have errors it will print a list of the errors and the location where they can be found so you can fix them.  The debugging process will be explained more as you learn how to create rooms, monsters, and objects.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-Introduction" title="Manual:Zone Manual/Introduction">Previous: Introduction</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-General-Compiler-Information-The-VMC-pre-processor" title="Manual:Zone Manual/General Compiler Information/The VMC pre-processor">Next: The VMC pre-processor</a></div></div>