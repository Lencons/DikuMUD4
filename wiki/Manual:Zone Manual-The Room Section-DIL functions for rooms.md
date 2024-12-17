<div class="mw-parser-output"><h3><span class="mw-headline" id="DIL_functions_for_rooms">DIL functions for rooms</span></h3>
<p>	The DIL language is the language a builder can use to make his own
	special functions on rooms, NPCs, objects, PCs, and much more.  This
	manual is for basic zone writing and therefore will not go into how to
	write your own DIL functions.  The VME however is released with many
	functions for you as an Administrator and your builders to use to make
	special rooms, NPCs, and objects.  The following is a list of all room
	functions released with the VME 2.0 server.
</p><p><br />
</p>
<dl><dt>Death room</dt>
<dd>This function is a simple function that allows you to create a room to do damage to a player. The death_room can kill them slowly like a fire cave would or it can kill them quickly as if you stuck them in a microwave it is all up to how you set the arguments.  It also lets you see the acts the players see so this function can be used on any number of death style rooms.  There is no need to understand how the function works just how to use it so with that in mind the following is the functions header.</dd></dl>
<pre>	//In function.zon
	dilbegin death_room(tick: integer, damage: integer, act_s: string);
</pre>
<p>As with any function all you have to do is 'dilcopy' the function
	onto your room with the correct zone name and arguments and it will do
	the rest.  In this DIL you have three arguments to pass The first is the
	'tick' or time which in this DIL is broken down into 'ticks' which are 4
	ticks per second.  Thus if you wanted to get something to do damage
	every minute you would put '60*4' in that spot.  The next is the amount
	of damage you want done per your time.  If for example you want '60' hit
	+points damage done each round you just put '60' as that argument.
	Finally is the act shown to the character as a string in quotes.  So a
	finished death room on your room would look like this.
</p>
<pre>	dilcopy death_room@function(4*60,60,
	"Flames shoot up from the floor burning your butt.");
</pre>
<dl><dt>Force move</dt>
<dd>This function allows you to move a player or NPC from a room to another room with out having the player or NPC type or do anything.</dd></dl>
<p>	The following is the definition of the force move DIL
</p>
<pre>	dilbegin force_move (tick: integer, strings: string, random: integer);
</pre>
<p>The 'tick' parameter is how fast you want the force move to be
	triggered.  The 'tick' is in 1/4 second increments so to get a one
	second wait you would place a four.  The second parameter is two strings
	the first being the symbolic name of the room you are forcing the
	character to.  The second string is the act you want shown to the player
	or NPC when it is moved.  The final parameter is either a one or a zero.
	The one stands for true and it would make the timer trigger randomly
	fifty percent of the time, while a zero would make it not random.
</p><p>	The following is what the force move would look like if you wanted it to trigger every 30 seconds and give acts of a river.
</p>
<pre>	dilcopy force_move@function(4*30,{"river2@riverzon","You float down the river."},0);
</pre>
<dl><dt>Safe room</dt>
<dd>This function creates a safe room where combat is not allowed.</dd></dl>
<p>	The following is the definition and an example of how to use it.
</p>
<pre>	//Safe room DIL definition
	dilbegin safe_room ();

	//Example use of Safe room
	dilcopy safe_room@function ();
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section-Compiling-and-debugging-your-first-room" title="Manual:Zone Manual/The Room Section/Compiling and debugging your first room">Previous: Compiling and debugging your first room</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section-A-more-complex-set-of-rooms" title="Manual:Zone Manual/The Room Section/A more complex set of rooms">Next: A more complex set of rooms</a></div></div>