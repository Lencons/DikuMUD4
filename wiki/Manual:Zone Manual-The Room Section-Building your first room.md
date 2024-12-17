<div class="mw-parser-output"><h3><span class="mw-headline" id="Building_your_first_room">Building your first room</span></h3>
<p>	Now you are ready!  With all you have learned about room
	fields you are now ready to build your first room.  I personally
	like dragons and I like space so I have chosen to make a dragon
	station.  We will first do a simple room and build on to it in the
	next sections.  In this section we will walk you through creating a
	basic room and why we choose what we do where we do.
</p><p>	When making rooms you create the zone source file first as shown
	in (Link to ch-02).  If you only have rooms you do not need the
	%reset, %objects, and %mobiles.  For the examples in this chapter we
	will use the zone we created in (Link to ch-02) and add the %room
	tag where we will put all the rooms.  At the end of the chapter we will
	have the entire zone so you can see it all together.
</p><p>	The first part of all rooms is the symbolic name it is good to
	always pick a name that will match the title so you can use the
	administrator command <b>goto</b> to easily get to the
	room.  The reason is when you use the command
	<b>wstat</b> it will only show you a list of the rooms
	by symbolic name for example if you type
	<b>wstat zone dragon room</b>
	You will get  the following:
</p>
<pre>	List of rooms in zone Dragon:
	chamber portal office
</pre>
<p>If you didn't make it clear what the rooms were by the symbolic name
	it might look like this:
</p>
<pre>	List of rooms in zone Dragon:
	st_rm1 st_rm2 st_rm3
</pre>
<p>While this might be great when you first start imagine trying to
	remember what all one hundred rooms are.
</p><p>	The first room we will create will be a simple chamber with nothing special.  We can build on to it later if we need to.
</p>
<pre>	chamber
	end
</pre>
<p>Pretty easy so far.  Now lets add some life to it.  The room
	will need a title and a description.  The title should be a one line
	description of a room sort of like if you were walking someone
	around your house and telling them what each room was like this is
	'My houses big bathroom' or maybe this is 'The computer room'.  The
	description should be something you would tell an interior
	decorator you were talking to on the phone and asking for
	advice.  He would want to know everything about the room you
	can see so he could give you good advice.
</p>
<pre>	chamber
	title "The middle chamber of the station"
	descr
	"This chamber seems to have the entire station rotating around it.
	Small human size ornate chairs with dragon designs scrawled on the
	arms and back are arranged in a triangle like setting with one large
	chair at the front.  This must be where all station meetings are held.
	large pictures cover the walls depicting dragons in all kinds of
	situations.  Small passages lead of to the west and the east.
	."
	end
</pre>
<p>It is a matter of taste if you want the descriptions of the
	exits in your description or not but I like them so I put them.  Now
	if you were reading this description to someone the person might ask
	you what is on the pictures or maybe even what exactly do the chairs
	look like so we better take care of that by adding some extras to
	our little room.
</p>
<pre>	extra {"chairs","chair"}
	"The chairs are made of some metal you don't recognize and every inch is covered
	with some kind of dragon."

	extra  {"dragon picture","picture"}
	"Thousands of dragons dot the skies of this rather life like picture.  In the
	center you see something move.  It looks to be a little green dragon."

	extra{"green dragon","dragon","green"}
	"An intelligent looking dragon is sitting perched on a large chair watching you."
</pre>
<p>Normally we could put a movement type for the amount of
	endurance lost when a person is moving through the area but we will
	leave it blank and go with the default which is SECT_CITY since
	with the fake gravity that is the closest we could come with the
	sector types availible.  The last thing we need to finish our room
	is the two exits leading to the other rooms.
</p>
<pre>	west to portal descr "You see a small room.";

	east to office descr "You see what looks to be an office.";
</pre>
<p>Thats it that is all there is to making a room.  In the next
	couple of sections we are going to add some more rooms with more
	advanced features and give some debugging hints for compiling your
	rooms but if you understand everything so far your going to have no
	problem.  Lets take a look at our entire finished first room
</p>
<pre>	chamber
	title "The middle chamber of the station"
	descr
	"This chamber seems to have the entire station rotating around it.
	Small human size ornate chairs with dragon designs scrawled on the
	arms and back are arranged in a triangle like setting with one large
	chair at the front.  This must be where all station meetings are held.
	large pictures cover the walls depicting dragons in all kinds of
	situations.  Small passages lead of to the west and the east.
	."

	extra {"chairs","chair"}
	"The chairs are made of some metal you don't recognize and every inch is covered
	with some kind of dragon."

	extra  {"dragon picture","picture"}
	"Thousands of dragons dot the skies of this rather life like picture.  In the
	center you see something move.  It looks to be a little green dragon."

	extra{"green dragon","dragon","green"}
	"An intelligent looking dragon is sitting perched on a large chair watching you."
	west to portal descr "You see a small room.";

	east to office descr "You see what looks to be an office.";
	end
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section" title="Manual:Zone Manual/The Room Section">Previous: The Room Section</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Room-Section-Compiling-and-debugging-your-first-room" title="Manual:Zone Manual/The Room Section/Compiling and debugging your first room">Next: Compiling and debugging your first room</a></div></div>