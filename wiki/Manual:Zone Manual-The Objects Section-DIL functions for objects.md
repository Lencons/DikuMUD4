<div class="mw-parser-output"><div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1 tocsection-1"><a href="#DIL-functions-for-objects"><span class="tocnumber">1</span> <span class="toctext">DIL functions for objects</span></a>
<ul>
<li class="toclevel-2 tocsection-2"><a href="#Restriction-functions"><span class="tocnumber">1.1</span> <span class="toctext">Restriction functions</span></a></li>
<li class="toclevel-2 tocsection-3"><a href="#Tuborg-function"><span class="tocnumber">1.2</span> <span class="toctext">Tuborg function</span></a></li>
<li class="toclevel-2 tocsection-4"><a href="#Message-board"><span class="tocnumber">1.3</span> <span class="toctext">Message board</span></a></li>
</ul>
</li>
</ul>
</div>

<h3><span class="mw-headline" id="DIL_functions_for_objects">DIL functions for objects</span></h3>
<p>	The DIL language is the language a builder can use to make his own
	special functions on rooms, NPCs, objects, PCs, and much more.  This
	manual is for basic zone writing and therefore will not go into how to
	write your own DIL functions.  The VME however is released with many
	functions for you as an Administrator and your builders to use to make
	special rooms, NPCs, and objects.  The following sections contain a full list of all object
	functions released with the VME 2.0 server.
</p>
<h4><span class="mw-headline" id="Restriction_functions">Restriction functions</span></h4>
<p>	The desire to have different equipment comes from every players
	desire to be different.  The restrict functions were designed to help
	make this a reality by only allowing certain groups of players to wear
	some items.  The restrict functions can be used alone or together to
	make a greater restricted item.  for example you could make an item,
	restricted to only females or you could make an item, restricted to females that had a strength greater than 20 and who have
	done a certain quest.
</p><p>	All restrict functions have a name that describes what the
	restriction function is for and four other arguments.  the 2nd, 3rd, and
	4th argument is the exact same for all restrict functions only the name
	of the restrict and the first argument changes.  The format for the
	restrict functions is as follows.
</p>
<pre>	dilcopy &lt;function name&gt; (arg 1, &lt;max damage&gt;,
	    &lt;percentage&gt;,&lt;Optional DIL&gt;);
</pre>
<p>We will skip the function name and the first argument and get back
	to them later.
</p>
<dl><dt>max damage and percentage</dt>
<dd>The second and third arguments set the damage done when the wrong player wears an object. The reason we are explaining them together is they can work together or separately depending on how you set them.</dd></dl>
<p>	The second argument is the max damage the third argument is the
	percentage damage.
</p><p>	When both arguments are set to 0 no damage will be
	done when the item is illegally worn.  When the second argument is set
	to a number like 100 and the third argument is set to 0, exactly 100
	damage will be done to the player no matter how many hit points he/she
	has.  So by setting the second argument to a number and setting the
	third to 0 you could possibly kill your victim since it will remove the
	amount specified no matter how much the player has.
</p><p>	 If you do not want
	to possibly kill your victim the Third argument should be used.  If you
	set the second argument to 0 and the third argument to a number it will
	do a percent of damage to the player. for example if The third argument
	was set to 25 it would do 25&#160;% damage to a player.
</p><p>	  You can also use the second and third argument together if you want to set a max amount of
	damage without possibly killing them.  for example if you set the second
	argument to 100 and third to 25.  The item will do 25% damage up to 100
	hit points of damage. This all might be a bit confusing so let me show
	you a few examples and tell you what they would do.
</p>
<dl><dt>second= 0 third = 25</dt>
<dd>This would do 25% damage to a player. second =100 third = 0 this would do 100 damage to a player no matter his amount of hit points.</dd>
<dt>second = 25 third = 25</dt>
<dd>This would do 25&#160;% damage to a player up to 25 hit points.</dd></dl>
<p>	So if a player had 150 hit points the max that could be removed is 25
	hit points.
</p>
<dl><dt>optional DIL</dt>
<dd>All restrict DIL functions have a default set of acts.  If you want to make your own set of acts you have to create your own DIL that does nothing more than act.  If you don't understand how this works.  You may want to look in the DIL manual about passing DIL functions as arguments.</dd></dl>
<p>Now we should get back to the first argument and function name
	since they are what control the restricts.  The function name has been
	chosen so you can easily tell what the restrict was created for
	while the first argument changes depending on which restrict you use.
	The following are what each function restricts name is and what the function
	name and first argument are.
</p>
<dl><dt>Guild Restrict</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>This function restricts an object to players in a certain
	guild or guilds.  Anyone not in the guild or guilds, will have the damage done as set in the
	2nd and 3rd arguments unless none is set.  Even if no damage is set the
	object will be removed off of the players equipment and placed in their
	inventory.  The following is the definition of the DIL as found in
	<i>function.zon</i>.
</p>
<pre>	dilbegin guild_restrict
	(guilds:stringlist,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first argument is a stringlist.  This
	means you can restrict this item to more than one guild.  All guilds in
	the string list will be able to wear this object.  If we wanted to make
	an item that only Paladins and sorcerers could wear it would look like
	this.
</p>
<pre>	dilcopy guild_restrict@function ({"Midgaard Paladin",
	                         "Midgaard Sorcerer"},0,25,"");
</pre>
<dl><dt>Anti-guild Restrict</dt>
<dd>This function restricts an object to players not in a certain guild or guilds.  Anyone not in the guild or guilds listed, will have the damage done as set in the 2nd and 3rd arguments unless none is set.  Even if no damage is set the object will be removed off of the players equipment and placed in their inventory.  The following is the definition of the DIL as found in</dd></dl>
<p>	<i>function.zon</i>.
</p>
<pre>	dilbegin anti_guild_restrict
	(guilds:stringlist,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first argument is a stringlist.  This
	means you can restrict this item from more than one guild.  All guilds in
	the string list will not be able to wear this object.  If we wanted to make
	an item that only Paladins and sorcerers could not wear it would look like
	this.
</p>
<pre>	dilcopy anti_guild_restrict@function ({"Midgaard Paladin",
	                              "Midgaard Sorcerer"},0,25,"");
</pre>
<dl><dt>Quest Restrict</dt>
<dd>This function restricts an object to players who have done a certain quest.  Any  player who has not done the quest,</dd></dl>
<p>	will have the damage done as set in the 2nd and 3rd arguments unless
	none is set.  Even if no damage is set the object will be removed off of
	the players equipment and placed in their inventory.  The following is
	the definition of the DIL as found in
	<i>function.zon</i>.
</p>
<pre>	dilbegin quest_restrict
	(qst:string,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first argument is a string.  The
	quest restrict is only made to restrict the by one quest at a time.  If
	you want the item to have multiple quests restrictions you just add
	another dilcopy to it.  The following Would be an object
	restricted to one quest.
</p>
<pre>	dilcopy quest_restrict@function ("Eagles quest complete",0,25,"");
</pre>
<dl><dt>Quests Restrict</dt>
<dd>This function restricts an object to players who have a certain quest or quests.  Anyone not having all quests in the list of quests, will have the damage done as set in the 2nd and 3rd arguments unless none is set.  Even if no damage is set the object will be removed off of the players equipment and placed in their inventory.  The following is the definition of the DIL as found in</dd></dl>
<p>	<i>function.zon</i>.
</p>
<pre>	dilbegin quests_restrict
	(qsts:stringlist,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first argument is a stringlist.  This
	means you can restrict this item to more than one quest.  Players that
	have not done every quest will not be able to use the object.
	If we wanted to make an item that only players that have finished both
	the 'Eagles quest complete' and the 'Feather fall quest complete' could
	wear.  It would look like this.
</p>
<pre>	dilcopy quests_restrict@function ({"Eagles quest complete",
	                          "Feather fall quest complete"},0,25,"");
</pre>
<dl><dt>Alignment Restrict</dt>
<dd>This function restricts an object to players with a certain alignment range.</dd></dl>
<p>	Anyone not in the alignment range,
	will have the damage done as set in the 3nd and 4th arguments unless
	none is set.  Even if no damage is set the object will be removed off of
	the players equipment and placed in their inventory.
</p><p>	We said at the beginning of this section that all restricts have
	only 4 arguments.  This was a bit of a lie since this restrict has five
	arguments.  The reason we didn't count this one is because the first and
	second argument in the alignment restrict function are used together and
	thus are only really one argument. The following is the definition of the DIL as found in
	<i>function.zon</i>.
</p>
<pre>	dilbegin ali_restrict
	(max:integer,min:integer,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first and second arguments are two
	integers.  the first is the max alignment that can wear or use this
	object and the second is the minimum alignment.  So if we wanted to
	restrict an item to only good players it would look like this.
</p>
<pre>	dilcopy ali_restrict@function (1000,350,0,25,"");
</pre>
<dl><dt>Level restrict</dt>
<dd>This function restricts an object to players above or equal to a certain level.  Any player not at least the level or higher, will have the damage done as set in the 2nd and 3rd arguments unless none is set.  Even if no damage is set the object will be removed off of the players equipment and placed in their inventory.  This restrict works in the old level system from one to fifty which means if the level restrict is set higher than fifty no player will be able to wear or use this object.  This is good if you have objects that only your administrators should be able to use.  If you want to restrict an object to greater than level fifty for players you need to use the 'vlevel' restrict.  The following is the definition of the DIL as found in <i>function.zon</i>.</dd></dl>
<pre>	dilbegin level_restrict
	(lvl:integer,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first argument is an integer.  The
	integer for the level restrict can range from 1 to 255.  Thus if we
	wanted to make an object that only administrator could wear or use it would
	look like this
</p>
<pre>	dilcopy level_restrict@function (51, 0,25,"");
</pre>
<dl><dt>Virtual Level Restrict</dt>
<dd>This function restricts an object to players above or equal to a certain level.  Any player not at least the level or higher, will have the damage done as set in the 2nd and 3rd arguments unless none is set.  Even if no damage is set the object will be removed off of the players equipment and placed in their inventory.  This restrict works in the new level system from one to infinity.</dd></dl>
<p>	The following is the definition of the DIL as found in <i>function.zon</i>.
</p>
<pre>	dilbegin vlevel_restrict
	(lvl:integer,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first argument is an integer.  The
	integer for the level restrict can range from 1 to infinite.  Thus if we
	wanted to make an object that only players that have reached the level
	of 5000 could wear or use, it would look like this.
</p>
<pre>	dilcopy vlevel_restrict@function (5000, 0,25,"");
</pre>
<dl><dt>Race restrict</dt>
<dd>This function restricts an object from players of a certain race. Any player not of the selected race, will have the damage done as set in the 2nd and 3rd arguments unless none is set.  Even if no damage is set the object will be removed off of the players equipment and placed in their inventory.  The following is the definition of the DIL as found in <i>function.zon</i>.</dd></dl>
<pre>	dilbegin race_restrict
	(rc:integer,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first argument is an integer.  The
	integer being passed in should be the race you want to restrict the
	object from.  You can pass in the defines as listed in (Link to app-c) or if you have added races you will find the list of
	races in <i>values.h</i>.  If we wanted to restrict an
	object from humans the following is what it would look like.
</p>
<pre>	dilcopy race_restrict@function (RACE_HUMAN,0,25,"");
</pre>
<dl><dt>Gender restrict</dt>
<dd>This function restricts an object to players of a certain gender.  Anyone not of the gender, will have the damage done as set in the 2nd and 3rd arguments unless none is set.  Even if no damage is set the object will be removed off of the players equipment and placed in their inventory.  The following is the definition of the DIL as found in</dd></dl>
<p>	<i>function.zon</i>.
</p>
<pre>	dilbegin sex_restrict
	(sx:integer,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first argument is an integer.  The
	integer you should pass in is one of the defines from
	<i>vme.h</i>.  The gender defines are as follows.
</p>
<pre>	#define SEX_NEUTRAL   0
	#define SEX_MALE      1
	#define SEX_FEMALE    2
</pre>
<p>If we wanted to make an item that could only be worn by a female
	player, it would look like this.
</p>
<pre>	dilcopy sex_restrict (SEX_FEMALE,0,25,"");
</pre>
<dl><dt>Player restrict</dt>
<dd>This function restricts an object to players who have a specific name. Any player of the wrong name, will have the damage done as set in the 2nd and 3rd arguments unless none is set.  Even if no damage is set the object will be removed off of the players equipment and placed in their inventory.  The following is the definition of the DIL as found in</dd></dl>
<p>	<i>function.zon</i>.
</p>
<pre>	dilbegin ply_restrict
	(pname:string,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first argument is a string.  The
	quest restrict is only made to restrict the quest to one person at a
	time.  While this DIL was designed to be put on when a player receives a
	quest item and thus was made to be dilcopied in a DIL you can still put
	it on when you first create the object if you are making special items
	for administrators or players that you know in advance.  If you want more
	information about copying a DIL from with in another DIL you will have
	to read the DIL manual If however you want to restrict this to a single
	player at compile time of your zone it would look something like
	this.
</p>
<pre>	dilcopy ply_restrict@function ("Whistler",0,25,"");
</pre>
<dl><dt>Ability restrict</dt>
<dd>This function restricts an object from a player with less than a certain amount of a certain ability. Any player not having the correct amount of a certain ability, will have the damage done as set in the 3nd and 4th arguments unless none is set.  Even if no damage is set the object will be removed off of the players equipment and placed in their inventory.</dd></dl>
<p>	We said at the beginning of this section that all restricts have
	only 4 arguments.  This was a bit of a lie since this restrict has five
	arguments.  The reason we didn't count this one is because the first and
	second argument in the ability restrict function are used together and
	thus are only really one argument. The following is the definition of the DIL as found in
	<i>function.zon</i>.
</p>
<pre>	dilbegin abi_restrict
	(abi:integer,min_abi:integer,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first and second arguments are two
	integers.  the first is the ability type and the second is the amount of
	that ability the player needs to have or greater to wear or use the
	item.  the ability types can be found in <i>vme.h</i> and
	are listed here for convenience.
</p>
<pre>	#define ABIL_MAG               0
	#define ABIL_DIV               1
	#define ABIL_STR               2
	#define ABIL_DEX               3
	#define ABIL_CON               4
	#define ABIL_CHA               5
	#define ABIL_BRA               6
	#define ABIL_HP                7
</pre>
<p>If you wanted to restrict an object to people having more than 50%
	strength it would look like this:
</p>
<pre>	dilcopy abi_restrict@function (ABIL_STR,50,0,25,"");
</pre>
<p>If you want to restrict an object to more than one ability you
	only need to add another restrict to the item.  For example if you
	wanted to restrict it to people having greater than or equal to 50%
	divine and 30% brain.  The item would have these two lines.
</p>
<pre>	dilcopy abi_restrict@function (ABIL_DIV,50,0,25,"");
	dilcopy abi_restrict@function (ABIL_BRA,30,0,25,"");
</pre>
<dl><dt>Skill restrict</dt>
<dd>This function restricts an object from a player with less than a certain amount of a certain skill. Any player not having the correct amount of a certain skill, will have the damage done as set in the 3nd and 4th arguments unless none is set.  Even if no damage is set the object will be removed off of the players equipment and placed in their inventory.</dd></dl>
<p>	We said at the beginning of this section that all restricts have
	only 4 arguments.  This was a bit of a lie since this restrict has five
	arguments.  The reason we didn't count this one is because the first and
	second argument in the skill restrict function are used together and
	thus are only really one argument. The following is the definition of the DIL as found in
	<i>function.zon</i>.
</p>
<pre>	dilbegin ski_restrict
	(ski:integer,min_ski:integer,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first and second arguments are two
	integers.  the first is the skill and the second is the amount of
	that skill the player needs to have or greater to wear or use the
	item.  the skills can be found in (Link to app-g) and
	<i>values.h</i>. We have also included the first five skills
	here for convenience in explaining how the function works.
</p>
<pre>	#define SKI_TURN_UNDEAD        0
	#define SKI_SCROLL_USE         1
	#define SKI_WAND_USE           2
	#define SKI_CONSIDER           3
	#define SKI_DIAGNOSTICS        4
</pre>
<p>If you wanted to restrict an object to people having more than 50%
	'turn undead' it would look like this:
</p>
<pre>	dilcopy ski_restrict@function (ASKI_TURN_UNDEAD,50,0,25,"");
</pre>
<p>If you want to restrict an object to more than one skill you
	only need to add another restrict to the item.  For example if you
	wanted to restrict it to people having greater than or equal to 50%
	 in 'turn undead' and 30% in 'scroll use'.  The item would have these two lines.
</p>
<pre>	dilcopy ski_restrict@function (SKI_TURN_UNDEAD,50,0,25,"");
	dilcopy ski_restrict@function (SKI_SCROLL_USE,30,0,25,"");
</pre>
<dl><dt>Spell restrict</dt>
<dd>This function restricts an object from a player with less than a certain amount of a certain spell. Any player not having the correct amount of a certain spell, will have the damage done as set in the 3nd and 4th arguments unless none is set.  Even if no damage is set the object will be removed off of the players equipment and placed in their inventory.</dd></dl>
<p>	We said at the beginning of this section that all restricts have
	only 4 arguments.  This was a bit of a lie since this restrict has five
	arguments.  The reason we didn't count this one is because the first and
	second argument in the spell restrict function are used together and
	thus are only really one argument. The following is the definition of the DIL as found in
	<i>function.zon</i>.
</p>
<pre>	dilbegin sp_restrict
	(spl:integer,min_sp:integer,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first and second arguments are two
	integers.  the first is the spell and the second is the amount of
	that spell the player needs to have or greater to wear or use the
	item.  the spells can be found in (Link to app-h) and
	<i>values.h</i>. We have also included the first five
	spells here for convenience in explaining how the function works.
</p>
<pre>	#define SPL_LOCK              52
	#define SPL_UNLOCK            53
	#define SPL_DROWSE            54
	#define SPL_SLOW              55
	#define SPL_DUST_DEVIL        56
</pre>
<p>If you wanted to restrict an object to people having more than 50%
	'lock' spell, it would look like this:
</p>
<pre>	dilcopy sp_restrict@function (ASPL_LOCK,50,0,25,"");
</pre>
<p>If you want to restrict an object to more than one spell you
	only need to add another restrict to the item.  For example if you
	wanted to restrict it to people having greater than or equal to 50%
	 in 'lock' and 30% in 'unlock' spells.  The item would have these two lines.
</p>
<pre>	dilcopy sp_restrict@function (SPL_LOCK,50,0,25,"");
	dilcopy SPL_restrict@function (SPL_LOCK,30,0,25,"");
</pre>
<dl><dt>Weapon restrict</dt>
<dd>This function restricts an object from a player with less than a certain amount of a certain weapon. Any player not having the correct amount of a certain weapon, will have the damage done as set in the 3nd and 4th arguments unless none is set.  Even if no damage is set the object will be removed off of the players equipment and placed in their inventory.</dd></dl>
<p>	We said at the beginning of this section that all restricts have
	only 4 arguments.  This was a bit of a lie since this restrict has five
	arguments.  The reason we didn't count this one is because the first and
	second argument in the weapon restrict function are used together and
	thus are only really one argument. The following is the definition of the DIL as found in
	<i>function.zon</i>.
</p>
<pre>	dilbegin weap_restrict
	(wpn:integer,min_wpn:integer,damage:integer,percent:integer,action:string);
</pre>
<p>As the definition indicates the first and second arguments are two
	integers.  the first is the weapon and the second is the amount of
	that weapon the player needs to have or greater to wear or use the
	item.  the weapons can be found in (Link to app-d) and
	<i>values.h</i>. We have also included the first five
	weapons here for convenience in explaining how the function works.
</p>
<pre>	#define WPN_BATTLE_AXE    7  /* Two Handed */
	#define WPN_HAND_AXE      8
	#define WPN_WAR_MATTOCK   9  /* Two Handed */
	#define WPN_WAR_HAMMER   10
	#define WPN_GREAT_SWORD  11  /* Two Handed */
</pre>
<p>If you wanted to restrict an object to people having more than 50%
	'battle axe', it would look like this:
</p>
<pre>	dilcopy weap_restrict@function (WPN_BATTLE_AXE,50,0,25,"");
</pre>
<p>If you want to restrict an object to more than one weapon you
	only need to add another restrict to the item.  For example if you
	wanted to restrict it to people having greater than or equal to 50%
	 in 'hand axe' and 30% in 'battle axe' spells.  The item would have these two lines.
</p>
<pre>	dilcopy weap_restrict@function (WPN_HAND_AXE,50,0,25,"");
	dilcopy weap_restrict@function (WPN_BATTLE_AXE,30,0,25,"");
</pre>
<h4><span class="mw-headline" id="Tuborg_function">Tuborg function</span></h4>
<p>	What game would be complete with out the Denmark water!  With that
	in mind the VME 2.0 has a tuborg function that makes a drink give
	endurance and health when drank.  The function is defined in
	<i>function.zon</i> as follows:
</p>
<pre>	dilbegin tuborg (s:string);
</pre>
<p>As the definition indicates the tuborg function only has one
	argument.  The real surprise is that the argument is not used yet in the
	DIL so no matter what you set it to it doesn't matter.  In the future
	this argument is going to allow different kinds of tuborgs to be made
	but for now its just a place holder and all that is needed is a set of
	double quotes.
</p><p>	To create a tuborg you just add the following line to your drink
	container.
</p>
<pre>	dilcopy tuborg@function ("");
</pre>
<h4><span class="mw-headline" id="Message_board">Message board</span></h4>
<p>	Every game needs a way for Administrators and players to exchange
	ideas.  The message boards have been designed for this purpose.  The
	boards function can be easy to use or more difficult depending on what
	all you want them to do.  The board function is defined in
	<i>boards.zon</i> as follows.
</p>
<pre>	dilbegin board
	(idxfile:string,l_res:string,r_res:string,p_res:string,bmax:integer);
</pre>
<p>This looks pretty hard I know but to make a normal board we have
	made it as simple as possible while allowing for the boards to be used
	in almost any situation.  After you make your first board it is pretty
	much block and copy and change the first argument.  The arguments are as
	follows:
</p>
<dl><dt>idxfile</dt>
<dd>The first argument is the board index filename.  It tells the board DIL what name to store the board under so if you create more boards with the same name they will all be pointing to the same messages.  You can put any legal symbolic name in this string and it will work with no problems.</dd>
<dt>l_res</dt>
<dd>the second argument is a DIL you pass in that does any checks to see if the player looking at the board is allowed to.  This requires some knowledge in DIL but we have given some example DIL functions in the</dd></dl>
<p>	<i>boards.zon</i>.
</p>
<pre>	//used to restrict players access to a board
	dilbegin string admin_res (u:unitptr,v:unitptr);

	//used to restrict non-admin from removing posts
	dilbegin string rem_res (u:unitptr, v:unitptr);
</pre>
<p>So with the 'admin_res' you could do something like
	this:
</p>
<pre>	dilcopy board@boards ("wizbrd","admin_res@boards"...);
</pre>
<p>Putting the 'admin_res' function in the second argument would make
	it so only administrators could look at the board.  If you put an empty
	string or two double quotes as the argument it will let anyone look at
	the board.
</p>
<dl><dt>r_res</dt>
<dd>the third argument is a DIL you pass in that does any checks to see if the player trying to remove a post at the board is allowed to.  This requires some knowledge in DIL but we have given some example DIL functions in the</dd></dl>
<p>	<i>boards.zon</i>
</p>
<pre>	//used to restrict players access to a board
	dilbegin string admin_res (u:unitptr,v:unitptr);

	//used to restrict non-admin from removing posts
	dilbegin string rem_res (u:unitptr, v:unitptr);
</pre>
<p>So with the 'rem_res' you could do something like
	this:
</p>
<pre>	dilcopy board@boards ("citizen","","rem_res@boards",...);
</pre>
<p>With the 'rem_res' in the third argument only administrators can
	now remove from this board but anyone can look at it because of the empty
	string in the second argument.  Putting an empty string in the third
	argument will make it so anyone can remove from this board.
</p>
<dl><dt>p_res</dt>
<dd>the forth argument is a DIL you pass in that does any checks to see if the player trying to post at the board is allowed to.  This requires some knowledge in DIL but we have given some example DIL functions in the</dd></dl>
<p>	<i>boards.zon</i>.
</p>
<pre>	//used to restrict players access to a board
	dilbegin string admin_res (u:unitptr,v:unitptr);

	//used to restrict non-admin from removing posts
	dilbegin string rem_res (u:unitptr, v:unitptr);
</pre>
<p>As you can see we haven't made a post restriction DIL because as of
	yet we haven't found a need for one.  If you have a need for one just
	look over the two restrict DIL functions we have already mentioned and you will
	find it is really easy to make.  We want to allow anyone to post so our
	dilcopy looks like this:
</p>
<pre>	dilcopy board@boards ("citizen","","rem_res@boards","",...);
</pre>
<p>With the 'rem_res' in the third argument only administrators can
	now remove from this board but anyone can post to it because of the empty
	string in the forth argument.  The empty string again in the second
	argument also allows everyone to look at the board.
</p>
<dl><dt>max</dt>
<dd>The fifth argument is simply the amount of posts that you want to allow to be posted before the board is full.</dd></dl>
<p>To make a free for all board where everyone can post, remove
	posts, look at what posts are on the board, and have a max of 50 posts it would simply be as
	follows:
</p>
<pre>	dilcopy board@boards("citizen","","","",50);
</pre>
<p>When making a board for players to post concerns to the
	administrators and only have the administrators be able to remove them,
	wile still allowing everyone to read them it would look like
	this.
</p>
<pre>	dilcopy board@boards("citizen","","rem_res@boards","",100);
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section-Compiling-and-Debugging-your-first-object" title="Manual:Zone Manual/The Objects Section/Compiling and Debugging your first object">Previous: Compiling and Debugging your first object</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section-More-complex-objects" title="Manual:Zone Manual/The Objects Section/More complex objects">Next: More complex objects</a></div></div>