<div class="mw-parser-output"><h3><span class="mw-headline" id="Building_your_first_object">Building your first object</span></h3>
<p>	Now that you have learned how to make rooms and NPCs its time to
	make the objects for your little world.
	In the last couple of sections you have looked
	through the fields.  In this section we are going to make a nice easy
	object.  There is really not that much new from what you have learned
	with rooms and NPCs so this should be a real quick section.  As always
	we will start with something I like which as you remember is dragons.
	So the first object we will make is a dragon head.  I didn't say I liked
	them alive now did I?  Anyway this will be a nice simple object that
	your player can pick up and carry around.
</p><p>	When making objects you create the zone source file first as shown
	in (Link to ch-02).  If you only have objects you do not need the
	%reset, %mobiles, and %rooms fields.  For the examples in this chapter we
	will use the zone we created in (Link to ch-04) and add the
	%objects section where we will put all the object definitions.  At the end
	of this chapter, in (Link to roomnpcobjzone), we will bring it
	all together with the rooms and NPCs we have defined already.
</p><p>	The first part of all object definitions is the symbolic name it is good
	to always pick a name that will match the name of the object so it
	will be easy to load the object.
	The reason the symbolic and name should match is when you use the
	command <b>wstat</b> it will only show you a
	list of the objects by symbolic name for example if you type <b></b>
	wstat zone dragon objects<b> You will get the following:</b>
</p>
<pre>	List of objects in zone Dragon:
	claw info_board dragon_head
</pre>
<p>If you didn't make it clear what the object was by the symbolic name
	it might look like this:
</p>
<pre>	List of objects in zone Dragon:
	obj1 a_obj2 o3
</pre>
<p>While this might be great when you first start imagine trying to
	remember each object if you have over 30 of them.
</p><p>	Now lets get started with our dragon head.  As with the rooms and
	npcs all that is required to make an object is the symbolic and end fields.
	That of course will make a NPC with all defaults.
</p>
<pre>	dragon_head
	end
</pre>
<p>Thats it for that dragon head right?  Nope not quite, like before
	with NPCs, that makes an object with all defaults.  That means this will probably be
	a very blank spot on the screen with no names and no way your players
	can interact with it.
	Now lets start putting the
	Dragon heads other more interesting fields on.
</p><p>	Like with rooms and NPCs, the first three things we need are the
	dragon heads title, description and names.  The description should be what you
	see when you do a 'look' in the room.  The title should be what you see
	when the object is in your inventory or you are whacking someone over the
	head with it.  Since we are not making a weapon though the title is what
	will be shown when you are picking up or dropping the object.
	 Finally the names should cover everything
	in the title and description fields so if your player wants to pick
	the object up or wear it will be easy to figure out what the names
	are.
</p>
<pre>	dragon_head

	title "a gold dragon head"

	descr "A large golden dragon head is laying here looking sad."

	names {"large golden dragon head","large gold dragon head",
	       "golden dragon head","large dragon head","gold dragon head",
	       "dragon head","large head", "sad head","head"}
	...
	end
</pre>
<p>The names, title and description shouldn't be to hard so I don't
	think its necessary to go into any more description on the subject.
	Lets move on.  Now we have to take care of what a player sees when he or
	she looks at an object.  to make the main description of an NPC you place an
	extra on the NPC with no names in the list.  The blank extra is a
	special extra that will be shown every time you look at anything in the
	names list of the object.  So a description of an object would look something
	like this.
</p>
<pre>	extra {}
	"The head is large and beautiful, at least as beautiful as a dead
	dragon head can be.  There is an extreme look of sorrow on the dragons
	face and it seems to be for much more than its own death."
</pre>
<p>Now that you have a main description for the object you need to make
	any smaller descriptions that you want the player to be able to look at.
	In this case it may be good to give some secret information if the
	player looks at the face of the head directly.
</p>
<pre>	extra {"gold dragon head face","dragon head face","head face","face"}
	"Looking into the dragons face your eyes are drawn to the eyes of the
	dead dragon.  Could there be something there?"

	extra {"eyes","eye"}
	"A world of blue skies and no storms is visible through the eyes and it
	seems to be moving as if you were watching the world from space."
</pre>
<p>Now that we have the object all described we only need to give the
	     object the manipulate flags it needs, weight, height, and maybe
	     some extras that will make some cool acts when a player picks it up
	     or drops it.
</p><p>		 First thing to do though is pick the manipulate flags you
		want on the object.  This is not a weapon or armour so all the
		player really needs to be able to do with it is pick it up and maybe
		hold it if you want and I do.  The flags would then be as follows:
</p>
<pre>	manipulate {MANIPULATE_TAKE,MANIPULATE_HOLD}
</pre>
<p>If you were feeling a little weird you could even make the
		 person be able to wear the dragon head on his head but that would
		 just be strange.  of course its always good to know you have
		 options.
</p><p>	Now lets set the height and weight.  Remember you set the height
	in centimeters and the weight in pounds.  In the future the VME will
	standardize to one or the other but for now we have to play the
	conversion game.
</p>
<pre>	//20 feet  (1 inch = 2.54 cm
	height 33

	//566 KG (1 lb. = .45359 kg)
		 weight 50
</pre>
<p>The final touch to our little dragon head is some cute acts
	when the player picks it up or drops it.  If you remember from the extra
	fields in (Link to objfielddescr), there are some special extras
	that are made just for this purpose.
</p>
<pre>	extra {"$get_s"}
	"You suddenly feel very sad for a world that you don't even know."

	extra {"$get_o"}
	"A strange look of sadness crosses $1ns face."

	extra {"$drop_s"}
	"You feel much happier but you remember a feeling of great sorrow."

	extra {"drop_o"}
	"$1n seems to cheer up a bit."
</pre>
<p>There are other things we could add to this item but I want to
	keep this first object simple.  The finished head would then look like
	this:
</p>
<pre>	dragon_head

	title "a gold dragon head"

	descr "A large golden dragon head is laying here looking sad."

	names {"large golden dragon head","large gold dragon head",
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

	manipulate {MANIPULATE_TAKE,MANIPULATE_HOLD}

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
</pre>
<p>Thats all there is to making regular items.  The rest is just
	adding functionality to what you already know.  We will get much deeper
	into what you can do with items in (Link to objcomplex) but first
	we will go over a debugging example and then all the special DIL functions made
	for objects.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section-Object-macros" title="Manual:Zone Manual/The Objects Section/Object macros">Previous: Object macros</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section-Compiling-and-Debugging-your-first-object" title="Manual:Zone Manual/The Objects Section/Compiling and Debugging your first object">Next: Compiling and Debugging your first object</a></div></div>