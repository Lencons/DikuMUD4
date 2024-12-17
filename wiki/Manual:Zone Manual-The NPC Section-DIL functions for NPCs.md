<div class="mw-parser-output"><h3><span class="mw-headline" id="DIL_functions_for_NPCs">DIL functions for NPCs</span></h3>
<p>	The DIL language is the language a builder can use to make his own
	special functions on rooms, NPCs, objects, PCs, and much more.  This
	manual is for basic zone writing and therefore will not go into how to
	write your own DIL functions.  The VME however is released with many
	functions for you as an Administrator and your builders to use to make
	special rooms, NPCs, and objects.  The following is a list of all NPC
	functions released with the VME 2.0 server.
</p><p><br />
</p>
<dl><dt>Mercenary</dt>
<dd>This function allows you to make an NPC hireable by players in the game.  You simply dilcopy this unto a mob and the player can then type 'contract &lt;character name&gt;</dd></dl>
<p>	and the mob will hunt that char for a fee. This function takes no special
	arguments.  the following is the function definition found in
	<i>function.zon</i>:
</p>
<pre>	dilbegin mercenary_hire();
</pre>
<p>To use it you simply dilcopy it to your NPC as follows:
</p>
<pre>	dilcopy mercenary_hire@function();
</pre>
<dl><dt>Obey</dt>
<dd>This function when dilcopied on the NPC will make it obey there master.  And example mobile of this is the familiar. Upon completing a small quest a Mage receives a familiar that will obey that player and that player only. The player can simply type <b>Tell &lt;familiar name&gt; cast heal</b></dd></dl>
<p>	&lt;player name&gt;<b> and it will carry out the command.  This function takes</b>
	no arguments.  The following is the definition found in
	<i>function.zon</i>:
</p>
<pre>	dilbegin obey();
</pre>
<p>To use this function simply dilcopy it to the NPC you want to be a
	mercenary like so:
</p>
<pre>	dilcopy obey@function();
</pre>
<dl><dt>Evaluate</dt>
<dd>This function when placed on an NPC allows it to evaluate items for a fee.  The function definition looks as follows:</dd></dl>
<pre>	dilbegin evaluate (amt:integer);
</pre>
<p>The function has one argument 'amt' that lets you set the cost of
	the evaluation of items.  If you wanted to set the value to four gold it
	would work just like when setting the money field and look as
	follows:
</p>
<pre>	dilcopy evaluate@function(4*GOLD_PIECE);
</pre>
<dl><dt>Guard Direction</dt>
<dd>This is an enhanced version of the Guard Way Function. It will allow both certain players to enter as well as certain mobs. An optional stop DIL can be supplied if you wish to do something special. It takes two arguments, the activator and the direction.  The following is the function definition:</dd></dl>
<pre>	dilbegin guard_dir(direction : string, excludepc : stringlist,
	                   excludenpc : stringlist, stopdil : string);
</pre>
<p>This function is dilcopied onto the mob in the room that the mob is initially
	loaded. Thus is the mob is summoned or commanded away it will not block the
	directions until it is back to where it was first created. This DIL takes four
	arguments. The first is the direction to block. The second arguments is for those
	PC's you wish to allow to pass in that direction without being stopped.  The next
	for the NPCs you wish to allow to pass. The last is the 'act you wish the blocking
	mob to display to the PC's that are blocked from proceeding in the selected direction.
	The third and forth arguments may be 'null', this will pass the defaults to the
	dilcopy.  The third argument is a stringlist that tells which players
	or NPCs are excluded from the guard.  The forth is a DIL you can pass in
	to do something special to people who are stopped.  We will not show how
	to use the forth argument because it takes more DIL knowledge than this
	manual covers.  The following would be a valid dilcopy for this
	function:
</p>
<pre>	dilcopy guard_dir@function("south", {"papi",
	{"rejji"}, null, null);
</pre>
<dl><dt>Combat magic</dt>
<dd>This function when placed on a mobile allows it to use any of the combat spells.  The function definition is as follows: It also allows the NPC to cast heal during combat on itself.</dd></dl>
<pre>	dilbegin combat_mag(atk_spl : string, def_spl : string,
	                    def_pct:integer, spd: integer);
</pre>
<table class="wikitable">
<caption>Combat magic arguments
</caption>
<tbody><tr>
<th>argument
</th>
<th>Type
</th>
<th>description
</th></tr>
<tr>
<td>atk_spl
</td>
<td>string
</td>
<td>Attack spell ie "fireball" or "" for none
</td></tr>
<tr>
<td>def_spl
</td>
<td>string
</td>
<td>Defense Spell ie "heal" or "" for none
</td></tr>
<tr>
<td>def_pct
</td>
<td>integer
</td>
<td>At what&#160;% of hitpoints defense spell will be cast
</td></tr>
<tr>
<td>spd
</td>
<td>integer
</td>
<td>speed at which mob will uses its attack magic, 1 for all
<p>	at once (every round) to 5 for every 5 rounds. I suggest 2.
</p>
</td></tr></tbody></table>
<p>Defense spells take priority when the hit points fall below the&#160;% specified,
	after (if) the hits have been restored above that number attack magic will
	resume.  If def_spl is used, function automatically makes sure that it retains
	enough mana for at least one healing, ie it will attack 4 times if it don't
	need a healing.  The following would be an example of what you would put
	on your NPC:
</p>
<pre>	dilcopy combat_mag@function ("harm", "heal", 25, 2);
</pre>
<dl><dt>Fido</dt>
<dd>This function turns the NPC into a corpse eating mobile.  The following is the functions definition:</dd></dl>
<pre>	dilbegin fido(txt1:string,txt2:string);
</pre>
<table class="wikitable">
<caption>Fido arguments
</caption>
<tbody><tr>
<th>Argument
</th>
<th>Type
</th>
<th>description
</th></tr>
<tr>
<td>txt1
</td>
<td>string
</td>
<td>The text shown when mob finds and eats corpses, default:
<p>	                        'XXX savagely devours a corpse.'
	                  will be shown if txt1 is set to "".
	                  If txt1 is set to "stop", the mob will NOT devour corpses
	                  (convenient if you want your dogs to only eat food leftovers
	                  but not corpses).
</p>
</td></tr>
<tr>
<td>txt2
</td>
<td>string
</td>
<td>The text shown when mob finds and eats ITEM_FOOD, default:
<p>	                        'XXX hungrily devours YYY.'
	                  will be shown if txt2 is set to "".
	                  If txt2 is set to "stop", the mob will NOT devour
	                  ITEM_FOOD (convenient if you want to make a corpse-eating
	                  ghoul, who'd choke on normal food, etc).
</p>
</td></tr></tbody></table>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>In both cases $1n is the mob itself, $2n is the title of the item devoured.</p></blockquote>
<p>	An example of the 'fido' function on an NPC would look as
	follows:
</p>
<pre>	dilcopy fido@function("$1n slowly devours $2n, crunching the bones.",
	                      "$1n grabs $2n and hungrily munches it.");
</pre>
<dl><dt>Wander zone</dt>
<dd>This function allows a mob to wander around more than one zone, but not all zones.</dd></dl>
<p>	You specify what zones the mob can wander.  Has optional intelligence which allows
	the opening and closing of doors.  The following is the function
	definition:
</p>
<pre>	dilbegin wander_zones(zones : string, spd : integer, doors : integer,
	                      lckd_doors : integer);
</pre>
<table class="wikitable">
<caption>Zone wander arguments
</caption>
<tbody><tr>
<th>argument
</th>
<th>Type
</th>
<th>description
</th></tr>
<tr>
<td>zones
</td>
<td>string
</td>
<td>A string of zone names separated by spaces.
</td></tr>
<tr>
<td>spd
</td>
<td>integer
</td>
<td>The speed (in seconds) at which the mob wanders.
<p>	                              Minimum = 5 secs (for process time).
</p>
</td></tr>
<tr>
<td>doors
</td>
<td>integer
</td>
<td>Can open/close doors (0 = false, 1 = true)
</td></tr>
<tr>
<td>lckd_doors
</td>
<td>integer
</td>
<td>Can open/closed locked doors (0=false, 1=true)
</td></tr></tbody></table>
<p>The options are not too hard so we will show how to use it and
	leave it at that
</p>
<pre>	dilcopy wander_zones@function ("halfzon haon_dor", 5, 1);
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>@loadzone option which is used by inputting @loadzone somewhere in the zones string will replace it by the zone the mob is loaded in like this:
</p><p> 
	dilcopy wander_zones@function ("halfzon haon_dor @loadzone", 5, 1);
</p>
</blockquote>
<dl><dt>Global wander</dt>
<dd>This is similar to wander_zones because it's just a modified version of it,</dd></dl>
<p>	which requires no zones argument since it moves in all zones.  The
	following is the function definition:
</p>
<pre>	dilbegin global_wander(spd : integer, doors : integer,
	                       lckd_doors :integer);
</pre>
<table class="wikitable">
<caption>Global wander arguments
</caption>
<tbody><tr>
<th>Argument
</th>
<th>Type
</th>
<th>Description
</th></tr>
<tr>
<td>spd
</td>
<td>integer
</td>
<td>The speed (in seconds) at which the mob wanders. Minimum = 5 seconds (for process time).
</td></tr>
<tr>
<td>doors
</td>
<td>integer
</td>
<td>Can open/close doors (0 = false, 1 = true)
</td></tr>
<tr>
<td>lckd_doors
</td>
<td>integer
</td>
<td>Can open/closed locked doors (0=false, 1=true)
</td></tr></tbody></table>
<p>	The options are not to hard so we will show how to use it and
	leave it at that
</p>
<pre>	dilcopy global_wander@function (60, 1, 1);
</pre>
<dl><dt>Team work</dt>
<dd>This function when placed on a mob, located in the same room as another mob,</dd></dl>
<p>	will allow the mobile to assist the other in combat.  The following is
	the function definition:
</p>
<pre>	dilbegin aware teamwork(lst: string);
</pre>
<p>This function takes one argument which is a string of the mobiles it is
	to protect. So if we wanted a NPC to protect both Jesper and Enver the
	dilcopy would look as follows:
</p>
<pre>	dilcopy teamwork@function("jesper/enver");
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>For this to work both mobs must be in the same room or following each other.</p></blockquote>
<dl><dt>Rescue</dt>
<dd>This function when placed on a mob, located in the same room as another mob,</dd></dl>
<p>	will allow the mobile to rescue the other mob if it is attacked.  The
	function is as follows:
</p>
<pre>	dilbegin aware rescue(lst: string);
</pre>
<p>This function takes one argument, a string of those mobiles
	you wish this NPC to assist should they be attacked.
</p>
	<blockquote style="background-color: #E8E8E8; font-style: italic;"><p> For this to work both NPCs must be in the same room or following each other.</p></blockquote>
<p>		  Again we will use our test subjects Jesper and Enver and if
	we wanted an NPC to protect them and come to their aid the following
	would be the dilcopy:
</p>
<pre>	dilcopy teamwork@function("jesper/enver");
</pre>
<dl><dt>Agressive</dt>
<dd>This function makes a Mob hostile to person(s) in the room with it, under certain conditions which are provided as arguments.</dd></dl>
<p>	In short, the all-singing, all-dancing aggression DIL.  The following is
	this functions definition:
</p>
<pre>	dilbegin aggressive (sx : integer, rce : integer, opp : integer,
	                     levl : integer, sanc : integer, tme : integer,
	                     tar : integer, align : string, attack :
	                     stringlist);
</pre>
<table class="wikitable">
<caption>Agressive arguments
</caption>
<tbody><tr>
<th>argument
</th>
<th>Type
</th>
<th>description
</th></tr>
<tr>
<td>sx
</td>
<td>integer
</td>
<td>NOTE: not the sex values in values.h.
<p>	                                 This decides the sex of your mob's
	                                 victim.
	                                 0 - Sex doesn't matter,
	                                 1 - Attack opposite sex to self (if not
	                                     neutral!),
	                                 2 - Attack SEX_MALE,
	                                 3 - Attack SEX_FEMALE,
	                                 4 - Attack SEX_NEUTRAL.
</p>
</td></tr>
<tr>
<td>rce
</td>
<td>integer
</td>
<td>Any of the PC races from 0 to 14. A value
<p>	                                 of -1 means we don't care about the
	                                 victim's race.
</p>
</td></tr>
<tr>
<td>opp
</td>
<td>integer
</td>
<td>0 - Non race specific (same as rce&#160;:= -1)
<p>	                                 1 - Attack the specified rce,
	2 - Attack any pc race _but_ the specified rce.
</p>
</td></tr>
<tr>
<td>levl
</td>
<td>integer
</td>
<td>Allow level specific aggression.
<p>	                                 A value of 30 would make the mob hostile
	                                 to all pcs level 30 and above.
	                                 A value of -30 (note the -) would make the
	                                 mob hostile to all pcs level 30 or below.
	                                 A value of 0 means level doesn't matter.
</p>
</td></tr>
<tr>
<td>sanc
</td>
<td>integer
</td>
<td>Does this mob obey the sanc/soothe rules?
<p>	                                 (ie, if someone has cast sanctuary on
	                                 themselves, will this mob recognize it, and
	                                 not attack, or attack anyway).
	                                 0 - Doesn't obey sanc or soothe
	                                 1 - Obeys only sanc
	                                 2 - Obeys only soothe
	                                 3 - Obeys both sanc and soothe
	                                 (SOOTHE is a new spell for ranger's guild)
</p>
</td></tr>
<tr>
<td>tme
</td>
<td>integer
</td>
<td>Time in ticks to wait before attacking (is
<p>	                                 automatically put to RANTIME, ie, time
	                                 variance of time-time/2 to time+time/2).
	                                 Values accepted are from 0 to 400 (that's
	                                 0 - 100 seconds. Can be specified using
	                                 PULSE_SEC).
</p>
</td></tr>
<tr>
<td>tar
</td>
<td>integer
</td>
<td>This is a special value which determines
<p>	                                 which of the eligible victims we pick.
	                                 -2 - Last eligible victim to into the room.
	                                 -1 - Weakest eligible victim in room.
	                                 0  - Random eligible victim.
	                                 +1 - Strongest eligible victim in room.
	+2 - First eligible victim into the room.
</p>
</td></tr>
<tr>
<td>align
</td>
<td>string
</td>
<td>The desired alignment of the victim.
<p>	                                 "ANY"      - We don't care about the alignment.
	                                 "GOOD"     - Attack only good alignment.
	                                 "EVIL"     - Attack only evil alignment.
	                                 "NEUTRAL " - Attack only neutral alignment.
	                                 "OPPOSITE" - Attack opposite alignment to self
	                                 (provided self isn't neutral).
					 "SALIGN" - Attack same alignment as self.
	                                 "DALIGN" - Attack any alignment
	                                 different to self.
</p>
</td></tr>
<tr>
<td>attack
</td>
<td>stringlist
</td>
<td>This is a 2 string stringlist. These are
<p>	                                    the messages sent to the people in the room
	                                    except the victim, and the victim itself,
	                                    in that order.
	                                    If the second (victim) string is "", the
	                                    first string will be shown to the victim,
	                                    as if they were anyone else in the room.
	                                    You can leave both blank if you wish.
	                                    $1n is the mob name (self), $3n is the
	                                    victim's name.
	                                    NOTE: the $ values only apply if you supply
	                                    BOTH string 1 and 2.
</p>
</td></tr></tbody></table>
<p>The argument descriptions pretty much explain everything there is
	to know about the agressive function and what it was so we will finish
	off by giving an example of a dilcopy that will create a NPC that fits
	the following description
</p><p>	Let's say our mob is a level 40 Goblin who doesn't like
	dwarves. He's very particular in that he doesn't like evil female
	dwarves who are level 20 and above. He does recognize the sanctuary
	spell, but he doesn't recognize soothe, and he'll wait 10 seconds on
	average before he attacks. The 2 messages sent are: "$1n savagely
	attacks $3n with his big axe!" and "$1n attacks you!"
</p><p>	Here's what the function call would look like:
</p>
<pre>	dilcopy aggressive (3, 2, 1, 20, 2, PULSE_SEC*10, 0, "EVIL",
	                    {"$1n savagely attacks $3n with his big axe!",
	                     "$1n attacks you!"});
</pre>
<p>In this example, 3 (attack females), 2 (attack dwarves), 1 (just dwarves),
	  20 (Level 20+ victims), 2 (obey only soothe), PULSE_SEC*10
	 (wait around 10 seconds before attacking), EVIL (attack only
	 evil), and the strings in the stringlist are displayed to
	 the victim and the room, in that order.
</p>
<dl><dt>Janitors</dt>
<dd>This function turns the NPC into a janitor that will pick up items left lying around and will also tell new  players. those under level 20,</dd></dl>
<p>	where there corpse is if they come across it in there wanderings.
	You must also supply the wander_zone DIL for this to work correctly.
	The definition for the janitor function is as follows:
</p>
<pre>	dilbegin janitors(rate: integer);
</pre>
<p>The Janitor function only takes one argument and that determines
	how fast the janitor will pick up stuff in seconds.
</p><p>	To make a Janitor that will pick up stuff every thirty seconds the
	following would be the dilcopy:
</p>
<pre>	dilcopy janitor@function(30);
</pre>
<dl><dt>Shop Keeper</dt>
<dd>This is one of the more complex dilcopies and considered by some to be confusing. Below I will step you through the creation of the mobile,</dd></dl>
<p>	and the application of this DIL using defines to hopefully simplify the
	use of this function.  The function is defined as:
</p>
<pre>	dilbegin aware shopkeeper(prod: stringlist, custom_acts : stringlist,
	                            opentimes : stringlist, itemtype: string,
					sellprofit : integer,buyprofit: integer,
					maxcash : integer,closedil : string,
					dilparams : string );
</pre>
<dl><dt>Step 1</dt>
<dd>First, figure out what you want your shopkeeper to sell.  He can sell pretty much any item from any zone, as long as you know its symbolic name.</dd></dl>
<p>	For Hogan (our example shopkeeper), he is a bartender, so he sells things
	you would commonly find in a pub, tavern, or bar.
	His list of items (their symbolic names at which zone) are:
</p>
<pre>	grain_alcohol@gobtown1
	pretzels@gobtown1
	beer_nuts@gobtown1
	rum_coke@gobtown1
	tuborg@udgaard
</pre>
<p>Now, since I use defines, I make a define for Hogan's products.  I called
	it TAVERN_PROD (for tavern's products).  And use the following setup
	and just stick the names of your items in where his items are.
	Each item will have a setup like this:
</p>
<pre>	 "tuborg@udgaard 15 20"
</pre>
<p>A symbolic name followed by two numbers, with the entire thing in
	quotes.  Where&#160;:
</p>
<ul><li>The "tuborg@udgaard" is your item's symbolic name</li>
<li>The 15 (our first number in the string) is the number of that item that</li></ul>
<p>	  will load into your shop daily
</p>
<ul><li>The 20 (our second number in the string) is the limit available of that</li></ul>
<p>	  item in the shop ever
So this shop would sell tuborgs.. and every mudday, 15 tuborgs will load
	into our shop to replenish our stock.. and the maximum tuborgs we can have
	at any given time is 20.
</p><p>	Next we place all this info into the define we created above, which would look
	like this:
</p>
<pre>	#define TAVERN_PROD \
	{"grain_alcohol@gobtown1 15 20", \
	 "pretzels@gobtown1 10 15", \
	 "beer_nuts@gobtown1 15 20", \
	 "rum_coke@gobtown1 10 15", \
	 "tuborg@udgaard 15 20"}
</pre>
<p>The above is my define for Hogan's products that he sells.  Each one is in
	quotes and they have commas separating them.  If you put each item on its
	own separate line, you need to put a space and then a back slash after the
	comma which separates the items, like it shows above.  The entire define
	is enclosed in curly brackets, {}.
	Now we are finished with the items he sells.
</p>
<dl><dt>Step 2</dt>
<dd>Now you must decide what kind of dialogue you would like your shopkeeper to say.  There are ten separate responses you can make for your shopkeeper.  They do go in a specific order and I will list what each do.</dd></dl>
<dl><dt>Response 1</dt>
<dd>The first response will be used if the shopkeeper doesn't have the particular item you're trying to buy in stock, or if he doesn't sell that item at all.</dd>
<dt>Response 2</dt>
<dd>The second response is used when the player is trying to sell the shopkeeper something which the player does not have in his inventory. Items worn by the player can not be sold until removed from there worn position.</dd>
<dt>Response 3</dt>
<dd>The third response is used when the player is trying to sell the shopkeeper something that is not one of those of his trade types. (This will be more clear when we get to the trade type part below. Such as a player trying to sell our bartender a canoe. =)</dd>
<dt>Response 4</dt>
<dd>The fourth response is used when the player tries to buy something from the shopkeeper, but doesn't have enough money to buy it.</dd>
<dt>Response 5</dt>
<dd>The fifth response is used when the sale was successful and the player buys something from the shopkeeper.</dd>
<dt>Response 6</dt>
<dd>The sixth response is again used when the sale was successful, but this time it's for when the player successfully sells something to the shopkeeper.</dd>
<dt>Response 7</dt>
<dd>The seventh response is used when the shopkeeper doesn't have enough of the item to sell as the player requests. Such as someone trying to buy 10 tuborgs, but our bartender only has 9.</dd>
<dt>Response 8</dt>
<dd>The eighth response is Used when the shop is closed and a player tries to buy something from or sell something to the shopkeeper.</dd>
<dt>Response 9</dt>
<dd>The ninth response is used when the player tries to sell an item to the shopkeeper that the shopkeeper doesn't trade that item.</dd>
<dt>Response 10</dt>
<dd>The tenth (and last!) response is for when the shopkeeper has run out of money and can't afford to buy what the player is trying to sell him.</dd></dl>
<p>Now. again, I made a define called TAVERN_MSG (for tavern messages) and I
	placed all my responses in it.  Don't forget, they do go in that specific
	order!  And below is our setup with responses in it.
</p>
	<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>In the responses below, $1n refers to the shopkeeper, $2n refers to the item being sold, bought, etc.. and $3n refers to the person dealing with the shopkeeper.</p></blockquote>
<pre>	#define TAVERN_MSG \
	{"$1n says, 'This is a tavern, I don't sell such an item as that!'", \
	 "$1n says, '$3n, you don't even have that!'", \
	 "$1n says, 'I don't trade with things such as $2n! Just buy a beer!'", \
	 "$1n says, '$3n, you can't afford $2n.'", \
	 "$1n says, 'Thank you, $3n, here are %s for $2n.'", \
	 "$1n says, 'Thank you, $3n.'", \
	 "$1n says, 'I don't have that many $2ns in stock.'", \
	 "$1n says, 'I'm on break, come back later.'", \
	 "$1n says, 'I haven't got a use for $2n.'", \
	 "$1n says, 'I'd like to buy it, but I can't afford it, sorry.'"} \
</pre>
<p>Just like with the items, the responses are in quotes, and are separated
	with commas.  Since I put each on their own separate lines (for neatness
	sake), I put a space and a back slash, \, after each.  The entire define is
	enclosed in curly braces,{}.
	And then you're done with your shopkeeper's messages!
	Don't worry, it gets simpler from here.
</p>
<dl><dt>Step 3</dt>
<dd>Now we get to decide when we want our shop to be open.  We get to use military time, so 1 refers to 1am, 6 refers to 6am, 12 refers to 12pm</dd></dl>
<p>	(noon), 18 refers to 6pm, and both 0 and 24 refer to 12am (midnight)..
	etc.. =)
	And my define for this I named TAVERN_OPEN_TIMES (for when the tavern is
	open) and I used the following setup:
</p>
<pre>	#define TAVERN_OPEN_TIMES {"12","18"}
</pre>
<p>You just have to make your define and stick your times in quotes and
	enclose them in curly braces.  So Hogan will be opened from 1am ("1")
	until 11pm ("23").  He will close after 11pm and reopen again at 1am.
	You may also add multiple open and close times as per the following
	example:
</p>
<pre>	#define TAVERN_OPEN_TIMES {"1","12","16","20"}
</pre>
<dl><dt>Step 4</dt>
<dd>For this step you get to choose your shopkeeper's trade types.  And what you pick all depends on what kinds of things you want your shopkeeper to sell and buy.  You can find the item types in <i>values.h</i>, but I'll also list them below.</dd></dl>
<table class="wikitable">
<caption>Sale types
</caption>
<tbody><tr>
<th>Value
</th>
<th>Type
</th>
<th>Value
</th>
<th>Type
</th></tr>
<tr>
<td>1
</td>
<td>ITEM_LIGHT
</td>
<td>14
</td>
<td>ITEM_TRAP
</td></tr>
<tr>
<td>2
</td>
<td>ITEM_SCROLL
</td>
<td>15
</td>
<td>ITEM_CONTAINER
</td></tr>
<tr>
<td>3
</td>
<td>ITEM_WAND
</td>
<td>16
</td>
<td>ITEM_NOTE
</td></tr>
<tr>
<td>4
</td>
<td>ITEM_STAFF
</td>
<td>17
</td>
<td>ITEM_DRINKCON
</td></tr>
<tr>
<td>5
</td>
<td>ITEM_WEAPON
</td>
<td>18
</td>
<td>ITEM_KEY
</td></tr>
<tr>
<td>6
</td>
<td>ITEM_FIREWEAPON
</td>
<td>19
</td>
<td>ITEM_FOOD
</td></tr>
<tr>
<td>7
</td>
<td>ITEM_MISSILE
</td>
<td>20
</td>
<td>ITEM_MONEY
</td></tr>
<tr>
<td>8
</td>
<td>ITEM_TREASURE
</td>
<td>21
</td>
<td>ITEM_PEN
</td></tr>
<tr>
<td>9
</td>
<td>ITEM_ARMOR
</td>
<td>22
</td>
<td>ITEM_BOAT
</td></tr>
<tr>
<td>10
</td>
<td>ITEM_POTION
</td>
<td>23
</td>
<td>ITEM_SPELL
</td></tr>
<tr>
<td>11
</td>
<td>ITEM_WORN
</td>
<td>24
</td>
<td>ITEM_BOOK
</td></tr>
<tr>
<td>12
</td>
<td>ITEM_OTHER
</td>
<td>25
</td>
<td>ITEM_SHIELD
</td></tr>
<tr>
<td>13
</td>
<td>ITEM_TRASH
</td>
<td>
</td>
<td>
</td></tr></tbody></table>
<p>We are making a bartender, so he should sell food and drinks.  So I
	selected ITEM_FOOD, and it's corresponding number is 19.  So I made my
	define TAVERN_ITEM_TYPE (for our tavern's type of items) using the
	following setup:
</p>
<pre>	#define TAVERN_ITEM_TYPE "19"
</pre>
<p>Now, if we had a magic shop, and wanted to sell potions and scrolls, I
	would make a define called for example MAGIC_ITEM_TYPE and make it like
	this:
</p>
<pre>	#define MAGIC_ITEM_TYPE "2 10"
</pre>
<p>The 2 was our number corresponding to the scrolls, and the 10
	corresponded to the potions.  That is how you make your shopkeeper
	sell more than one item type, just stick the corresponding numbers inside
	quotes with a space separating them.
</p>
<dl><dt>Step 5</dt>
<dd>Now you get to decide how much money your shopkeeper gets to have to buy things with.  One platinum piece is equal to 40960.  So if I wanted him to have two platinum pieces to spend on buying things from players, I would make a define called TAVERN_MAX_CASH (for the maximum amount of money our shopkeeper gets) and use the following setup:</dd></dl>
<pre>	#define TAVERN_MAX_CASH 81920
</pre>
<p>I got 81920 by multiplying the 40960 (one platinum) by 2
</p>
<dl><dt>Step 6</dt>
<dd>The sixth thing we get to do is to decide how much profit does our shopkeeper get when he sells his items.  Items should have a cost to them already tagged on them, so their whatever their cost is, that is equal to 100%. Now, if your shopkeeper wants to take an extra 10% on the items he's selling so he can support his family, then you would make his selling profit 110.  So I made a define called TAVERN_SELL_PROFIT (for his profit when he sells things) and gave him 110% selling profit, and used the following setup:</dd></dl>
<pre>	#define TAVERN_SELL_PROFIT 110
</pre>
<dl><dt>Step 7</dt>
<dd>This last define is almost exactly like our selling profit, but now, we're doing our buying profit... when a player sells an item to the shopkeeper,</dd></dl>
<p>	he doesn't want to pay full price because it must be used since a player
	has it.  Now the item's cost is 100%, and maybe the shopkeeper only wants
	to buy items for half its cost.  So I would make his buying profit 50,
	and use the following setup.
</p>
<pre>	#define TAVERN_BUY_PROFIT 50
</pre>
<p>All of the previous  defines you can place anywhere in the zone.  I like
	to place mine before the %DIL section just to keep them somewhere where
	I know they all are.  You can place each one on the mob itself, but I
	think that looks cluttered so's why I put them where I put
	them.  And you're going to have a dilcopy placed on your mob also, which
	I'll explain in step 8.
</p>
<dl><dt>Step 8</dt>
<dd>Okay one last step.  Now you get to place the DIL on your shopkeeper mob using all of those cute little defines you just made.  The syntax for the DIL is:</dd></dl>
<pre>	  dilcopy shopkeeper@function(products, responses, opentimes,
	                             tradetypes, sellprofit, buyprofit,
	                             maxcash, closedil, dilparams);
</pre>
<p>Take your defines from above the defines that you made are
	called:
</p>
<pre>	TAVERN_PROD, TAVERN_MSG, TAVERN_OPEN_TIMES, TAVERN_ITEM_TYPE,
	TAVERN_SELL_PROFIT, TAVERN_BUY_PROFIT, and TAVERN_MAX_CASH.
</pre>
<p>Now all you have to do is place them in the syntax where they belong like
	in the below example.
</p>
<pre>	dilcopy shopkeeper@function(TAVERN_PROD, TAVERN_MSG, TAVERN_OPEN_TIMES,
	                            TAVERN_ITEM_TYPE, TAVERN_SELL_PROFIT,
	                            TAVERN_BUY_PROFIT, TAVERN_MAX_CASH, "", "");
</pre>
<p>For the last two fields, I just put "", "" because I don't make my own
	unique DIL for those.  By just putting and empty set of quotes for each,
	it makes it go to the default.
	And make sure you don't forget that semicolon at the end either.
</p><p>	You are pretty much done now.  All you have to do is place your
	defines either up before %DIL or somewhere in %mob if you'd like, and
	place the dilcopy onto your mob.
</p><p>Just to make sure I've completely beaten a very dead horse, this is
	what it would look like in the end.
</p>
<pre>	%zone sample_zon

	#define TAVERN_PROD \
	{"grain_alcohol@gobtown1 15 20", \
	 "pretzels@gobtown1 10 15", \
	 "beer_nuts@gobtown1 15 20", \
	 "rum_coke@gobtown1 10 15", \
	 "tuborg@udgaard 15 20"}

	#define TAVERN_MSG \
	{"$1n says, 'This is a tavern, I don't sell such an item as that!'", \
	 "$1n says, '$3n, you don't even have that!'", \
	 "$1n says, 'I don't trade with things such as $2n! Just buy a beer!'", \
	 "$1n says, '$3n, you can't afford $2n.'", \
	 "$1n says, 'Thank you, $3n, here are %s for $2n.'", \
	 "$1n says, 'Thank you, $3n.'", \
	 "$1n says, 'I don't have that many $2ns in stock.'", \
	 "$1n says, 'I'm on break, come back later.'", \
	 "$1n says, 'I haven't got a use for $2n.'", \
	 "$1n says, 'I'd like to buy it, but I can't afford it, sorry.'"} \

	#define TAVERN_OPEN_TIMES {"1","23"}
	#define TAVERN_ITEM_TYPE "19"
	#define TAVERN_MAX_CASH 81920
	#define TAVERN_SELL_PROFIT 110
	#define TAVERN_BUY_PROFIT 50

	%mobiles

	bartender
	names {"hogan","goblin","bartender"}
	title "Hogan"
	descr "Hogan stands behind the bar waiting to take your order."
	extra {}
	"He looks back at you, patiently waiting for your order."
	M_AVG_GOBLIN(76,SEX_MALE)
	alignment -1000
	exp 100
	money 2 SILVER_PIECE, 2 COPPER_PIECE

	dilcopy shopkeeper@function(TAVERN_PROD, TAVERN_MSG, TAVERN_OPEN_TIMES,
	                            TAVERN_ITEM_TYPE,TAVERN_SELL_PROFIT,
	                            TAVERN_BUY_PROFIT, TAVERN_MAX_CASH, "", "");
	end
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section-Compiling-and-debugging-your-first-NPC" title="Manual:Zone Manual/The NPC Section/Compiling and debugging your first NPC">Previous: Compiling and debugging your first NPC</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section-A-more-complex-set-of-NPCs" title="Manual:Zone Manual/The NPC Section/A more complex set of NPCs">Next: A more complex set of NPCs</a></div></div>