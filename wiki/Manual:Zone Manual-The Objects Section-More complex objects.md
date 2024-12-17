<div class="mw-parser-output"><div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1 tocsection-1"><a href="#More-complex-objects"><span class="tocnumber">1</span> <span class="toctext">More complex objects</span></a>
<ul>
<li class="toclevel-2 tocsection-2"><a href="#Making-a-communication-board"><span class="tocnumber">1.1</span> <span class="toctext">Making a communication board</span></a></li>
<li class="toclevel-2 tocsection-3"><a href="#Making-a-container"><span class="tocnumber">1.2</span> <span class="toctext">Making a container</span></a></li>
<li class="toclevel-2 tocsection-4"><a href="#Creating-drinks"><span class="tocnumber">1.3</span> <span class="toctext">Creating drinks</span></a></li>
<li class="toclevel-2 tocsection-5"><a href="#Creating-food"><span class="tocnumber">1.4</span> <span class="toctext">Creating food</span></a></li>
<li class="toclevel-2 tocsection-6"><a href="#Making-a-weapon"><span class="tocnumber">1.5</span> <span class="toctext">Making a weapon</span></a></li>
<li class="toclevel-2 tocsection-7"><a href="#Making-armour"><span class="tocnumber">1.6</span> <span class="toctext">Making armour</span></a></li>
<li class="toclevel-2 tocsection-8"><a href="#Making-non-armour-worn-objects"><span class="tocnumber">1.7</span> <span class="toctext">Making non-armour worn objects</span></a></li>
</ul>
</li>
</ul>
</div>

<h3><span class="mw-headline" id="More_complex_objects">More complex objects</span></h3>
<p>	In the last sections you learned all the fields and how to make a
	basic object. In this section we will use the information from the last
	sections to create some more unique objects for our dragon station zone
	There is not a lot of new information here we will be using the DIL functions,
	fields, and flags to make objects we have only mentioned before.
</p>
<h4><span class="mw-headline" id="Making_a_communication_board">Making a communication board</span></h4>
<p>	In (Link to objdilboard) you learned all there you need to
	know about the boards DIL to create a board.  In this small section we
	are going to show you the rest of a board and what a finished one looks
	like.
</p><p>	As with all objects the first step is to fully describe and name
	your board.  We will stick with the space station theme since our goal
	is to have a complete example zone for you.  The boards symbolic, names, title,
	description and extra turned out like this.
</p>
<pre>	info_board

	title "a merchant information board"
	descr "A merchant information Board is mounted on a wall here."

	names {"merchant information board","information board","merchant
	board","board"}

	extra {} "A large flashy black steal board."
</pre>
<p>Just incase the VME server we have has a spell that can damage
	inanimate objects we will give this board a material type.
</p>
<pre>	MATERIAL_METAL("A very fine quality black steel")
</pre>
<p>Now for the special stuff for the board.  We need to give the
	board a type and copy the board DIL to it.
</p>
<pre>	type ITEM_BOARD
	dilcopy board@boards("info","","rem_res@boards","",100);
</pre>
<p>There you go nothing to it you have just created your first board.
	 Now lets bring it all together and tag on an end symbol and we are all
	 finished.
</p>
<pre>	 info_board
	title "a merchant information board"
	descr "A merchant information Board is mounted on a wall here."
	names {"merchant information board","information board","merchant
	board","board"}

	extra {}
	"A large flashy black steal board."

	MATERIAL_METAL("A very fine quality black steel")
	type ITEM_BOARD
	dilcopy board@boards("info","","rem_res@boards","",100);

	end
</pre>
<h4><span class="mw-headline" id="Making_a_container">Making a container</span></h4>
<p>	I thought it would be cool to have a small weapons locker on the
	space station not to mention event hough we went over the container
	macro in (Link to objmacrocontainer), we didn't cover everything
	you need in fact the macro eaves a few things out because you may or may
	not want to set them.
</p><p>	As with all objects we start right off by describing the item.
	There is nothing new here so we will just show it to you and go
	on.
</p>
<pre>	wpn_locker

	title "a weapons locker"
	names {"weapons locker","weapon locker","locker"}

	descr "a small weapons locker hangs on the wall here."

	extra {}
	"It is an ordinary weapons locker that looks like it holds any illegal
	weapons that are taken on the station."
</pre>
<p>Now we need to put in all the information that makes this item a
	container that can't be taken but it can be opened and it is
	locked.
</p>
<pre>	manipulate {MANIPULATE_ENTER}
	CONTAINER_DEF(500)
	open {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED}
	key black_key
</pre>
<p>Notice we didn't make the item 'MANIPULATE_TAKE' because
	we don't want people to be able to walk off with our weapons locker.
	One final touch and we are all finished with the weapons locker.  It is
	always nice to put a material type on your items so a spell or a skill
	can tell if you can do anything with them.  So with our material added
	in the full locker would look like this.
</p>
<pre>	wpn_locker

	title "a weapons locker"
	names {"weapons locker","weapon locker","locker"}
	descr "a small weapons locker hangs on the wall here."

	extra {}
	"It is an ordinary weapons locker that looks like it holds any illegal
	weapons that are taken on the station."

	MATERIAL_METAL("A very fine quality steel")

	manipulate {MANIPULATE_ENTER}
	CONTAINER_DEF(500)
	open {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED}
	key black_key

	end
</pre>
<h4><span class="mw-headline" id="Creating_drinks">Creating drinks</span></h4>
<p>	In (Link to objmacroliqcont), we covered how to set the size and weight of the container and its content but now we need to talk about some other special things about a drink container verses other objects.
</p><p>	The drink container is one of the few objects that has rules on
	how you set the title, description and names fields.  The title and
	description fields should ot have anything to do with the liquid inside
	the container.  This means if you have a barrel full of water you do not
	put the word water in the title or the description.  In our case we have
	a bag full of wine so we do not put wine in either the title or
	description.  The reason for this is if the player drinks the bag empty
	and then fills it with water and we had put wine in the title or
	description it would still be there but the bag would now be full of
	water..  Our symbolic, title, and description would then look like
	this.
</p>
<pre>	liq_ration

	title "a red bag"
	descr "A red bag has been gently placed here."
</pre>
<p>The names on the other hand MUST have the drink name as the last
	name in the name list.  The reason it must be the last one is when a
	player drinks or pours out the liquid the name is removed.  If a player
	then refills the container the name of the new liquid is added to the
	last name.  The bag we are making is full of wine so our names list would
	look like this.
</p>
<pre>	names {"red bag", "bag", "wine"}
</pre>
<p>Now we add the liquid define for wine
</p>
<pre>	LIQ_WINE(1,2,2,0)
</pre>
<p>Finally we add the material type for the bag, the cost to buy the
	container, an extra players can look at, and finally an identify extra so
	if a player casts either the identify or improved identify spell on the
	bag they will se it.  with all that added The finished drink container
	looks like this.
</p>
<pre>	liq_ration
	names {"red bag", "bag", "wine"}
	title "a red bag"
	descr "A red bag has been gently placed here."

	extra {}
	"A small label reads Tassel Grove's finest.  Year 321"

	MATERIAL_ORGANIC("a soft plastic")
	manipulate {MANIPULATE_TAKE}
	LIQ_WINE(1,2,2,0)
	cost 2 IRON_PIECE

	extra {"$identify"}
	"Its the special wine from Tassel grove a small halfling village on the
	planet Valhalla.  It seems like a great vintage wine."

	end
</pre>
<h4><span class="mw-headline" id="Creating_food">Creating food</span></h4>
<p>	The food is very simple to make its just a regular item with the
	macros you learned in (Link to objmacrofood).  In fact making
	food is so simple we almost left it out.  I am only adding this to show
	how simple it is to change a regular item like the dragon head we showed
	you in (Link to objbasic) into a food item.  Now only a sick
	person would make a dragon head into food but if you wanted to you just
	add the 'FOOD_DEF(...)' and your all set.  here is a basic food that you
	might find laying around a space station.
</p>
<pre>	beef_stick

	title "a tough leathery stick"
	descr "A tough leathery looking stick is laying here."
	names {"tough leathery stick","tough leather stick","leathery stick",
	"leather stick","tough stick","stick"}

	extra {}
	"This has the word BEEF burnt into it."

	manipulate {MANIPULATE_TAKE}
	FOOD_DEF(5,0)
	weight 1
	cost 1 COPPER_PIECE
	MATERIAL_ORGANIC("tough beef")

	end
</pre>
<h4><span class="mw-headline" id="Making_a_weapon">Making a weapon</span></h4>
<p>	Whats a game with out some kind of weapon to chop or bash things
	into little pieces.  We examined how to set the weapon fields in (Link to objmacroweapon), the object transfers in (Link to objmacrotransfers), and the restriction DIL functions in (Link to objdilrestrict).  Now we will pull all we have learned together
	and make a pretty nifty little stiletto.
</p><p>	The first part as with all our example objects is to set up the
	symbolic, names, title, description, object extra, and material type.  this is no
	different from any other object so here is what we ended up with
</p>
<pre>	 w_stiletto
	 title "a stiletto"
		 names {"stiletto", "dagger"}
	 descr
	 "A deadly looking stiletto has been left here."

	extra{}
	"This looks like a thieves dream come true. "

	MATERIAL_METAL("A very fine quality steel")
</pre>
<p>Now lets add the defines and DIL functions that make this a special weapon
	along with the manipulate flags that makes it able to be wielded.  We will give
	it a bonus in magic and good craftsmanship along with a plus in
	backstab for all those assassins on the game.
</p>
<pre>	manipulate {MANIPULATE_TAKE, MANIPULATE_WIELD}
	WEAPON_DEF(WPN_DAGGER, 1, 2)
	SKILL_TRANSFER(SKI_BACKSTAB, 2)
	dilcopy abi_restrict@function (ABIL_DEX,10,0,25,"");
</pre>
<p>to finish it off we will give the weapon a cost, rent, and finally
	two identifies for the two identify spells.  Now that we have it all
	defined we pull it together and it looks like this.
</p>
<pre>	 w_stiletto
	 title "a stiletto"
	 names {"deadly looking stiletto","deadly stiletto","stiletto", "dagger"}
	 descr
	 "A deadly looking stiletto has been left here."

	extra{}
	"This looks like a thieves dream come true. "

	MATERIAL_METAL("A very fine quality steel")

	manipulate {MANIPULATE_TAKE, MANIPULATE_WIELD}
	WEAPON_DEF(WPN_DAGGER, 1, 2)
	SKILL_TRANSFER(SKI_BACKSTAB, 2)
	dilcopy abi_restrict@function (ABIL_DEX,10,0,25,"");
	weight 2
	cost 2 GOLD_PIECE
	rent 1 COPPER_PIECE

	extra {"$identify"}
	"The stiletto looks magical in nature and seems really sharp.  You can
	tell if you wield it you would be able to backstab someone really easy."

	extra{"$improved identify"}
	"The stiletto gives you a magical bonus of +1 and has a quality of +2.
	It also raises your back stabbing skill  by 2%.  You have to have at
	least 10% in dex before you can wield this magical weapon."

	end
</pre>
<h4><span class="mw-headline" id="Making_armour">Making armour</span></h4>
<p>	In (Link to objmacroarmour) we explained how to set the
	           armour fields now we will finish off by adding some more
	           important information about armour in general.
</p><p>		   The most important thing to realize is that not all wear
	           positions on the VME server are armour positions.  In fact
	           only seven of the wear positions count as armour the rest are
	           non-armour positions which we will cover next in (Link to objnon-armour).  The following are the armour
	           positions and their defines.
</p>
<table class="wikitable">
<caption>Armour positions
</caption>
<tbody><tr>
<th>Position
</th>
<th>Define
</th></tr>
<tr>
<td>head
</td>
<td>MANIPULATE_WEAR_HEAD
</td></tr>
<tr>
<td>hands
</td>
<td>MANIPULATE_WEAR_HANDS
</td></tr>
<tr>
<td>arms
</td>
<td>MANIPULATE_WEAR_ARMS
</td></tr>
<tr>
<td>body
</td>
<td>MANIPULATE_WEAR_BODY
</td></tr>
<tr>
<td>legs
</td>
<td>MANIPULATE_WEAR_LEGS
</td></tr>
<tr>
<td>feet
</td>
<td>MANIPULATE_WEAR_FEET
</td></tr>
<tr>
<td>cloak
</td>
<td>MANIPULATE_WEAR_ABOUT
</td></tr></tbody></table>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>There is one more field that works as armour, 'MANIPULATE_WEAR_SHIELD' but since that uses another define it is not shown here.  We will leave that for an exercise for you to do later.</p></blockquote>
<p>	First we do the same as we have for every other item, pick the
	symbolic, title, description, extra description, and material type for the plate.
</p>
<pre>	pol_plate
	names {"polished breast plate","polished plate","breast plate","plate"}
	title "a polished breast plate"
	descr "A polished breast plate has been left here."
	MATERIAL_METAL("A high luster silver colored metal")
</pre>
<p>Now we pick the armour type in this case I want it to be made like
	plate mail and I want it to have a magical bonus and a high
	craftsmanship.  Obviously since this is a plate we will pick the body
	position.
</p>
<pre>	manipulate {MANIPULATE_TAKE, MANIPULATE_WEAR_BODY}
	ARMOUR_DEF(ARM_PLATE,5,9)
</pre>
<p>All that is left is to add the cost, rent, the identify extras,
	and I felt like putting a 40% strength restriction on the armour.  With
	all that added together we finish up with the following piece of
	armour.
</p>
<pre>	pol_plate
	names {"polished breast plate","polished plate","breast plate","plate"}
	title "a polished breast plate"
	descr "A polished breast plate has been left here."

	extra{}
	"This is one shiny plate it seems to be made out of one perfect piece of
	metal.  There doesn't even seem to be any markings of owner ship."

	MATERIAL_METAL("A high luster silver colored metal")

	manipulate {MANIPULATE_TAKE, MANIPULATE_WEAR_BODY}
	ARMOUR_DEF(ARM_PLATE,5,9)

	dilcopy abi_restrict@function (ABIL_STR,40,0,25,"");
	cost 2 GOLD_PIECE
	rent 3 COPPER_PIECE weight 25

	extra{"$identify"}
	"This is a high quality plate with a magical feeling."

	extra{"$improved identify"}
	"The plate has a magical bonus to your defence of a +5 and a quality of
	+9.  You need 40% in strength to be able to wear it."
	end
</pre>
<h4><span class="mw-headline" id="Making_non-armour_worn_objects">Making non-armour worn objects</span></h4>
<p>	In the previous section we defined armour that actually protects
	the char in combat.  Here we will learn how to make the clothing and
	jewelery that may not do anything directly to combat but it can give
	your characters bonuses that help in combat in the long run.  We will
	start by listing all the non-armour worn positions and their manipulate
	defines and then we will give a simple ring object.
</p>
<table class="wikitable">
<caption>Non-armour positions
</caption>
<tbody><tr>
<th>Position
</th>
<th>define
</th></tr>
<tr>
<td>ear
</td>
<td>MANIPULATE_WEAR_EAR
</td></tr>
<tr>
<td>neck
</td>
<td>MANIPULATE_WEAR_NECK
</td></tr>
<tr>
<td>wrist
</td>
<td>MANIPULATE_WEAR_WRIST
</td></tr>
<tr>
<td>finger
</td>
<td>MANIPULATE_WEAR_FINGER
</td></tr>
<tr>
<td>chest
</td>
<td>MANIPULATE_WEAR_CHEST
</td></tr>
<tr>
<td>back
</td>
<td>MANIPULATE_WEAR_BACK
</td></tr>
<tr>
<td>waist
</td>
<td>MANIPULATE_WEAR_WAIST
</td></tr>
<tr>
<td>ankle
</td>
<td>MANIPULATE_WEAR_ANKLE
</td></tr></tbody></table>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>When giving ability, skill, weapon, or spell bonuses make sure you realize that positions like ear, neck, wrist, and ankle can all have two on a player.  This means any bonuses you give can be doubled if the player gets two of them</p></blockquote>
<p>	I don't want to beat a dead horse so since I have already
	explained armour in (Link to objarmour) the only difference here
	is there is no 'ARMOUR_DEF' everything else is the same.  The following
	was one of the first items my wife made as a new builder and I have
	always liked it.  I know, I am a lush but this way I don't have to write
	an example.
</p>
<pre>	  maskwa

	names {"maskwa platinum ring", "platinum ring","maskwa ring","maskwa","ring"}
	title "a Maskwa ring"
	descr "A Maskwa platinum ring is laying here."
	MATERIAL_METAL("Platinum, and other precious metals")
	extra {}
	"The ring has a large bear head.  Could this be the legendary head of
	Maskwa?  Any thing formed with its head on it is said to strengthen the
	wearer."
	type ITEM_WORN
	manipulate {MANIPULATE_TAKE, MANIPULATE_HOLD, MANIPULATE_WEAR_FINGER}
	cost 100 COPPER_PIECE
	rent 50 IRON_PIECE
	weight 1
	STR_TRANSFER(+1)
	end
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>One last thing I forgot to mention.  The item type also changes but then that is not hard to understand since this is not armour it should be some other thing.  In the case of non-armour worn items the item type is 'ITEM_WORN'.</p></blockquote>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section-DIL-functions-for-objects" title="Manual:Zone Manual/The Objects Section/DIL functions for objects">Previous: DIL functions for objects</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section-Dragon-station-with-rooms-NPCs-and-objects" title="Manual:Zone Manual/The Objects Section/Dragon station with rooms NPCs and objects">Next: Dragon station with rooms, NPCs, and objects</a></div></div>