<div class="mw-parser-output"><div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1 tocsection-1"><a href="#Object-macros"><span class="tocnumber">1</span> <span class="toctext">Object macros</span></a>
<ul>
<li class="toclevel-2 tocsection-2"><a href="#Weapon-and-armour-craftsmanship"><span class="tocnumber">1.1</span> <span class="toctext">Weapon and armour craftsmanship</span></a></li>
<li class="toclevel-2 tocsection-3"><a href="#Magical-modifier"><span class="tocnumber">1.2</span> <span class="toctext">Magical modifier</span></a></li>
<li class="toclevel-2 tocsection-4"><a href="#Setting-weapon-fields"><span class="tocnumber">1.3</span> <span class="toctext">Setting weapon fields</span></a></li>
<li class="toclevel-2 tocsection-5"><a href="#Setting-armour-fields"><span class="tocnumber">1.4</span> <span class="toctext">Setting armour fields</span></a></li>
<li class="toclevel-2 tocsection-6"><a href="#Setting-shield-fields"><span class="tocnumber">1.5</span> <span class="toctext">Setting shield fields</span></a></li>
<li class="toclevel-2 tocsection-7"><a href="#Setting-material-types"><span class="tocnumber">1.6</span> <span class="toctext">Setting material types</span></a></li>
<li class="toclevel-2 tocsection-8"><a href="#Drink-container-macros"><span class="tocnumber">1.7</span> <span class="toctext">Drink container macros</span></a></li>
<li class="toclevel-2 tocsection-9"><a href="#The-food-macros"><span class="tocnumber">1.8</span> <span class="toctext">The food macros</span></a></li>
<li class="toclevel-2 tocsection-10"><a href="#Light-object-macro"><span class="tocnumber">1.9</span> <span class="toctext">Light object macro</span></a></li>
<li class="toclevel-2 tocsection-11"><a href="#Container-macro"><span class="tocnumber">1.10</span> <span class="toctext">Container macro</span></a></li>
<li class="toclevel-2 tocsection-12"><a href="#Money-macro"><span class="tocnumber">1.11</span> <span class="toctext">Money macro</span></a></li>
<li class="toclevel-2 tocsection-13"><a href="#Cursed-objects-macro"><span class="tocnumber">1.12</span> <span class="toctext">Cursed objects macro</span></a></li>
<li class="toclevel-2 tocsection-14"><a href="#Potion.2C-wand.2C-and-staff-macros"><span class="tocnumber">1.13</span> <span class="toctext">Potion, wand, and staff macros</span></a></li>
<li class="toclevel-2 tocsection-15"><a href="#Magical-transfer-macros"><span class="tocnumber">1.14</span> <span class="toctext">Magical transfer macros</span></a></li>
</ul>
</li>
</ul>
</div>

<h3><span class="mw-headline" id="Object_macros">Object macros</span></h3>
<p>	  To make the creation of some objects easier we have provided a
	set of Macros.  The macros range from general armour and weapons macros
	to macros that help you create special affects on all items.  We will
	first cover what craftsmanship and magical modifiers are in (Link to objcraft) and (Link to objmag) respectively.  After
	which we will show the use of craftsmanship and magical modifiers in
	(Link to objmacroweapon) and (Link to objmacroarmour).
</p>
<h4><span class="mw-headline" id="Weapon_and_armour_craftsmanship">Weapon and armour craftsmanship</span></h4>
<p>	The craftsmanship is a way of expressing the overall quality of  a
	piece of armour or weapon.  The quality on the VME servers currently
	means the amount of hit points given to an item.  The craftsmanship
	ranges from 25 to -25 and the hit points range from 125 to 6000.  The craftsmanship can be looked at as how tough or good the armour
	or weapon is.  The following table should help you in deciding how tough
	your armour or weapon should be.
</p>
<table class="wikitable">
<caption>Approximate hit points verses craftsmanship
</caption>
<tbody><tr>
<th>Craftsmanship
</th>
<th>Hit points
</th></tr>
<tr>
<td>25
</td>
<td>6000
</td></tr>
<tr>
<td>20
</td>
<td>5000
</td></tr>
<tr>
<td>15
</td>
<td>4000
</td></tr>
<tr>
<td>10
</td>
<td>3000
</td></tr>
<tr>
<td>5
</td>
<td>2000
</td></tr>
<tr>
<td>0
</td>
<td>1000
</td></tr>

<tr>
<td>875
</td></tr>

<tr>
<td>650
</td></tr>

<tr>
<td>425
</td></tr>

<tr>
<td>300
</td></tr>

<tr>
<td>125
</td></tr></tbody></table>
<p>It is suggested the higher the craftsmanship the higher the cost
	of the weapon should be.  This is not a must but it goes with out saying
	the quality of an item should be represented in the cost of it.  Of
	corse there is the time you would want to sell your players poor quality
	items at a high cost just to make them think they are getting something
	cool.
</p>
<h4><span class="mw-headline" id="Magical_modifier">Magical modifier</span></h4>
<p>	The magical modifier can be said to modify damage done to an
	opponent.  In a combat the damage is calculated and then the magical
	bonuses on armour or weapons is added in.  This is best explained by an
	example.
</p><p>	Lets say that you were about to give 25 hit points of damage to a
	person.  Your sword has a plus 25% in magical bonus.  The bonus is added to
	your damage to make it a total of 50 hit points of damage.  The player
	you are hitting however has a +25% magical bonus on his armour that you
	are about to hit him on.  That will reduce the damage back to its 25%
	hit points originally done.  This is just a nice way to add a bit of
	damage for a special weapon.
</p><p>	The magical modifier ranges from 25 to -25.  It affects both the
	damage being given to a player and the damage being given to a weapon or
	a piece of armour.
</p><p>	It is suggested that you modify the costs of your objects to fit
	the amount of magical bonus along with adding the magical flag tot he
	objects flag list so an identify spell can pick up that there is
	magic about the object.  This is not a must but your players will love
	you for it.
</p>
<h4><span class="mw-headline" id="Setting_weapon_fields">Setting weapon fields</span></h4>
<p>	   To create a weapon you only need three pieces of information.
	The weapons craftsmanship and magical modifiers defined in (Link to objcraft) and (Link to objmag) and the weapon type.
	You have seen the weapon types before when defining a NPCs natural
	attack type in (Link to npcmacroattarm).  The full list of weapon
	types that are released with the VME 2.0 can be found in (Link to app-d).  With craftsmanship, magical modifier and the weapon
	type all you need to do is pick from one of the following macros and
	insert your numbers.
</p>
<pre>	#define WEAPONSZ_DEF(weapon_category, craftsmanship, magic_bonus, hgt)  \
	  WEAPON_DEF(weapon_category, craftsmanship, magic_bonus)\
	  height hgt

	#define SHIELD_DEF(shield_type, craftsmanship, magic_bonus)  \
	  manipulate {MANIPULATE_TAKE, MANIPULATE_WEAR_SHIELD} \
	  type ITEM_SHIELD            \
	  value[0] shield_type        \
	  value[1] craftsmanship      \
	  value[2] magic_bonus
</pre>
<p>As you can see the first macro uses the second macro so the only
	difference between them is the first one sets the height field.  Using
	the first macro will force your weapon to be a certain size when loaded.
	While not setting the height field by using the second macro would let
	the VME server set the size of the weapon by what NPC it is loaded
	on.
</p><p>		 A  flail (two handed) of non-pure iron (-3%), a little better than
	average craftsmanship (5%) and no magic bonuses would have:
</p>
<pre>	     WEAPON_DEF(WPN_FLAIL, +2, 0)
</pre>
<p>A  rusty  (-5%) mean sacrificial dagger by a skilled smithy  (+5%)
	and magically enchanted might be:
</p>
<pre>	     flags {UNIT_FL_MAGIC}
	     WEAPON_DEF(WPN_DAGGER, 0, +5)
</pre>
<p>An old shaky wooden stick made for a 400 cm tall person could
	     be:
</p>
<pre>		WEAPONSZ_DEF(WPN_CLUB, -5, 0,400)
</pre>
<p>A wooden bastard sword would have considerable less craftsmanship
	than listed since wood prevents the slashing effect, also it would be
	non-sense to apply better than average craftsmanship in this
	case.
</p>
<pre>	     WEAPON_DEF(WPN_BROAD_SWORD, -15, 0)
</pre>
<h4><span class="mw-headline" id="Setting_armour_fields">Setting armour fields</span></h4>
<p>	When designing armour it is no more difficult then when designing
	weapons.  There is five main armour types.  The types don't define the
	material type for example if you wanted to create a wooden pair of
	armour that protected like plate armour you could do this by defining
	the armour type as plate and then adding the material as defined in
	(Link to objmacromattype).  The five armour types are as
	follows:
</p>
<ul><li>Clothes</li>
<li>Leather</li>
<li>Hard leather</li>
<li>Chain</li>
<li>Plate</li></ul>
<p>The armours macros are almost the same as the weapons macro it looks
	as follows.
</p>
<pre>	#define ARMOUR_DEF(atype, craftsmanship, magic_bonus) \
	   manipulate {MANIPULATE_TAKE} \
	   type ITEM_ARMOR              \
	   value[0] atype
	      value[1] craftsmanship       \
	   value[2] magic_bonus

	#define ARMOURSZ_DEF(atype, craftsmanship, magic_bonus, hgt)\
	   ARMOUR_DEF(atype,craftsmanship, magic_bonus) \
	   height hgt
</pre>
<p>The craftsmanship and magical modifier fields have already been
	explained so the only thing new that you need to pass into these macros
	is the 'atype' which stands for armour type.  As we have mentioned there
	are five different armour types.  The following are the defines for
	each:
</p>
<ul><li>ARMOUR_CLOTHES</li>
<li>ARMOUR_LEATHER</li>
<li>ARMOUR_HLEATHER</li>
<li>ARMOUR_CHAIN</li>
<li>ARMOUR_PLATE</li></ul>
<p>The armour type defines how different weapons and spells are
	defended against for example plate would be better against acid maybe
	and worse against electricity.  You as a VME
	administrator will have to decide which armours are better at what by
	changing your <i>weapons.def</i> and
	<i>spells.def</i>
</p><p>	This explains the entire armour define but there is some more to
	it.  The rest will be covered in (Link to objarmour) For now an
	example use of the armour define would be as follows:
</p>
<pre>	flags {UNIT_FL_MAGIC}
	ARMOR_DEF(ARM_PLATE,+15,+5)
</pre>
<h4><span class="mw-headline" id="Setting_shield_fields">Setting shield fields</span></h4>
<p>	We have tried to keep the interface of making armours, weapons, and shields the same.  If you have already looked through the defines for weapons and armours you will find that there is very little difference here.  The following is the define for the macro that sets the shield values.
</p>
<pre>	#define SHIELD_DEF(shield_type, craftsmanship, magic_bonus)  \
	   manipulate {MANIPULATE_TAKE, MANIPULATE_WEAR_SHIELD} \
	   type ITEM_SHIELD            \
	   value[0] shield_type        \
	   value[1] craftsmanship      \
	   value[2] magic_bonus

	#define SHIELDSZ_DEF(shield_type, craftsmanship, magic_bonus, hgt)  \
	   SHIELD_DEF(shield_type, craftsmanship, magic_bonus)\
	   height hgt
</pre>
<p>You have already seen the craftsmanship and magical modifiers
	in (Link to objcraft) and (Link to objmag), so the only
	thing different here is the shield type.  There are three shield
	types available in the current combat system and they are categorized by
	size.  the three sizes are small, medium, and large.  to set the type
	you use the defines from <i>vme.h</i> which define the
	following:
</p>
<ul><li>SHIELD_SMALL</li>
<li>SHIELD_MEDIUM</li>
<li>SHIELD_LARGE</li></ul>
<p>the larger the shield the better chance of blocking an attack.
	You may want to remember to add weight as you add size to your shield so
	players are weighted down and can not carry the best of everything
	but that is up to the administrator of the VME server.
</p><p>	A small magical wooden shield could be assigned:
</p>
<pre>	     flags {UNIT_FL_MAGIC}
	     SHIELD_DEF(SHIELD_SMALL, 0, +5)
</pre>
<h4><span class="mw-headline" id="Setting_material_types">Setting material types</span></h4>
<p>	Currently Material types are not used greatly in spells or skills
	but in the future we hope to add more functionality for materials.  For
	example in the future if you are hit by an acid spell we want your
	armour to be damaged depending on the material it is.  The material
	doesn't have any affect on damage given or taken it is just a way you can
	check in DIL what the weapon is made out of.  The following is the list
	you would find in <i>wmacros.h</i> of in the VME 2.0
	release.
</p>
<pre>	#define MATERIAL_WOOD(DESCR)    extra {"$material", "$mat_wood"} DESCR
	#define MATERIAL_METAL(DESCR)   extra {"$material", "$mat_metal"} DESCR
	#define MATERIAL_STONE(DESCR)   extra {"$material", "$mat_stone"} DESCR
	#define MATERIAL_CLOTH(DESCR)   extra {"$material", "$mat_cloth"} DESCR
	#define MATERIAL_LEATHER(DESCR) extra {"$material", "$mat_leather"} DESCR
	#define MATERIAL_SKIN(DESCR) extra {"$material", "$mat_skin"} DESCR
	#define MATERIAL_ORGANIC(DESCR) extra {"$material", "$mat_organic"} DESCR
	#define MATERIAL_GLASS(DESCR)   extra {"$material", "$mat_glass"} DESCR
	#define MATERIAL_FIRE(DESCR)    extra {"$material", "$mat_fire"} DESCR
	#define MATERIAL_WATER(DESCR)   extra {"$material", "$mat_water"} DESCR
	#define MATERIAL_EARTH(DESCR)   extra {"$material", "$mat_earth"} DESCR
	#define MATERIAL_MAGIC(DESCR)   extra {"$material", "$mat_magic"} DESCR
</pre>
<p>Therefore if you had a wooden staff you could add the following to
	your weapon so spells would know what it was made out of.
</p>
<pre>	MATERIAL_WOOD("a hard oak")
</pre>
<h4><span class="mw-headline" id="Drink_container_macros">Drink container macros</span></h4>
<p>	There are two different kinds of macros for drink containers.  The
	one you use depends on the need at the time.  The harder macro is made
	so you can create a drink of any kind.  If however you want normal
	drinks like water, beer, or even lemonade there are more simple macros
	already defined for you to use in <i>liquid.h</i>.  The
	following is a couple of the macros from the
	<i>liquid.h</i> for a full listing see
	(Link to app-e).
</p>
<pre>	#define LIQ_WATER(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("clear", WEIGHT,CAPACITY,INSIDE,10,1,0,POISON)
	#define LIQ_BEER(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("brown", WEIGHT,CAPACITY,INSIDE,5,2,3,POISON)
	#define LIQ_WINE(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("red", WEIGHT,CAPACITY,INSIDE,5,2,5,POISON)
	#define LIQ_COFFEE(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("black", WEIGHT, CAPACITY, INSIDE, 6, 1, 0,POISON)
</pre>
<p>To use these macros the arguments are pretty simple.
</p>
<dl><dt>weight</dt>
<dd>The first argument just says how heavy your drink container is when empty.  Like a barrel might be 15 pounds and a glass might be 1 pound.</dd></dl>
<p>	You may be thinking there is no way the glasses in your kitchen are one
	pound.  The truth is if we had less than a pound then we would set the
	glass to less but currently all units are measured in pounds so the
	least we can make it is a pound.  In the future of the
	VME we will be converting to smaller measurements
	like grams or ounces.
</p>
<dl><dt>capacity</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>	 The second argument is what your container can carry weight wise.
	 So if your barrel is 15 pounds and your barrel can carry 35 pounds of a
	 liquid then the total weight when full would be 50 pounds, if my math
	 is working today.  To make a container with infinity liquid like a
	 fountain you just set capacity to '-1'.
</p>
	 <blockquote style="background-color: #E8E8E8; font-style: italic;"><p>Making capacities ridiculously large can cause weight bugs. If your going to allow ridiculous amounts you might just want to give them the infinite amount or really work on your drink and pour functions</p></blockquote>
<dl><dt>inside</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>	  The third argument is how much liquid by weight your container
	  has inside.  This value should not be greater than the capacity but if
	  you mess up it will be fixed when the player tries to drink from it.
	  The total weight of the drink container and the liquid it contains
	  will be the weight added to this value.
</p>
<dl><dt>poison</dt></dl>
<ul><li class="mw-empty-elt"></li></ul>
<p>	 the forth argument is the amount of poison in your drink.  There
	 is no limit on the amount of poison but understand that a value of ten
	 would be a very high poison value.
</p><p>So if you wanted to make a simple small glass of water you would
	use the water macro and it would look like this:
</p>
<pre>	LIQ_WATER(1,2,2,0)
</pre>
<p>You are probably wondering what it takes to fill a player from
	empty.  The players thirst ranges from -24 which is dieing of
	thirst all the way to positive 24 which is full.  So if you have a
	barrel that can hold 24 capacity one full barrel can take a person from
	zero thirst to full.
</p><p>	Now lets say you want to make something more exotic.  All the
	                           normal drinks are made or at least a great
	                           number of them are in the
	                           <i>liquid.h</i> but what if
	                           you had a race from outer space that drank
	                           nothing but silicone oil.  This obviously is
	                           not covered in our liquid file so you would
	                           have to make one yourself or use the more
	                           complex macro.
</p>
<pre>	#define LIQ_DEF(color, wgt, max_cap, inside,thirst,full,drunk,poison) \
	  type ITEM_DRINKCON           \
	  weight (wgt)+(inside) \
	  capacity max_cap \
	  value[0] inside        \
	  value[3] poison \
	  extra {"$drink_color"}color \
	  extra {"$drink_thirst"} #thirst \
	  extra {"$drink_full"} #full \
	  extra {"$drink_drunk"} #drunk
</pre>
<p>As you can see this define has much more information you need to
	pass it but it really is not that hard.  The following are the arguments
	and what they do.
</p>
<dl><dt>color</dt>
<dd>the first argument is the color of the liquid.  this color will be shown when you look at the liquid in the container.</dd>
<dt>wgt</dt>
<dd>The second argument is the weight of the container as in the last macros.  It is what the container would weigh empty.</dd>
<dt>max_cap</dt>
<dd>The third argument is the maximum capacity of the container.  If the value is set to 15 and the container is fulled it will contain 15 pounds of liquid which adds to the base weight to get the total weight of the container.  If you want a container to have unlimited contents then you set the capacity to '-1' and the weight will be that of the</dd></dl>
<p>	'wgt' field.
</p>
<dl><dt>inside</dt>
<dd>The forth argument is the amount of liquid the container starts with.  This amount should not be greater than the 'max_cap' field, but if it is it will be corrected when the player takes a drink or acts on the container.</dd>
<dt>thirst</dt>
<dd>The fifth field is how much thirst this gives per pound of liquid consumed.  For example if you have a glass of water and it only has a capacity of 1 with 1 inside.  this value will be added once to the players thirst field.</dd></dl>
<p>	this can be a bit confusing so lets first explain that the thirst
	field can be anything from 0 to 10 or even greater but we suggest only 10
	max.  With that in mind know that we set water at 10 because it is one
	of the best thirst quenchers known to man.  Therefore a glass with 1
	capacity and 1 quantity inside will give a player +10 to his thirst so if
	the player was down to zero thirst value one drink will give them 10.
	remember that a players thirst ranges from -24 to +24 so with three
	drinks of water a person could fill his thirst need entirely.
</p><p>	With that in mind when setting this field you have to think what
	kind of thirst quencher is my drink.  If for example it is vodka it would
	have little to know thirst quenching power so you would set this field
	to 0 or 1.
</p>
<dl><dt>full</dt>
<dd>The sixth field like the thirst field sets how the drink will affect the chars fullness.  The chars fullness field is normally set when a player is eating but as you know drinking some drinks will also give you the feeling of being full.  One drink like this would be milk.</dd></dl>
<p>	The chars fullness field ranges from -24 to 24 like the thirst field and
	the argument you are setting on this field should range from 0 to 10
	unless you have a pro teen drink that fills them like food.  Milk might
	have a fullness of something like 5.
</p>
<dl><dt>drunk</dt>
<dd>the seventh field like thirst and full deals with the Drunkenness of a character.  A character can range from 0 (not drunk) all the way up to 24 (smashed).  The drunk field on this macro sets how much drunk is added for each quantity of the liquid is consumed.  Therefore something like vodka should have a value of 10 while something like water should be down at 0 unless you have some weird race that gets drunk from water.</dd>
<dt>poison</dt>
<dd>The eighth and final field is again like the last macro we looked at it sets the poison factor of a liquid.  The value ranges from 0 (no poison) to whatever you want but understand that 10 is an extreme poison factor and a player drinking this will most likely die quickly.</dd></dl>
<p>So with the definitions of each arguments in mind lets return to
		the example of making a silicone oil based liquid.  We will first
		show what it would look like using the hard macro then what the new
		easy macro that you could create would look like.
</p>
<pre>		LIQ_DEF("blue",5,10,10,5,1,0,0)
</pre>
<p>Now if you want to make this a liquid your going to use a lot
	you would define your own easier macro like this.
</p>
<pre>	#define LIQ_SILICONE(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("blue", WEIGHT,CAPACITY,INSIDE,5,1,0,POISON)
</pre>
<p>That covers the use of the macros but for more information on the
	drink containers see (Link to objdrink).
</p>
<h4><span class="mw-headline" id="The_food_macros">The food macros</span></h4>
<p>	The food macro is much easier than that of the drink macro so if
	you have drink containers down you will have no problem making food to
	go with your beverage.  The players fullness value ranges from -24 to 24
	as we have already learned when making drink containers and in the
	current food system on the VME server we do not allow thirst to be
	modified by food.  Therefore the only thing you have to set is the
	amount of fullness and the poison factor if there is any.  The following
	is what the define for food looks like.
</p>
<pre>	#define FOOD_DEF(food_amount, poison_factor)  \
	   type ITEM_FOOD         \
	   value[0] food_amount   \
	   value[3] poison_factor
</pre>
<p>Therefore if you wanted to make sure that only one of your
	foods that you were creating would fill a player entirely in one bite
	you would set it like this:
</p>
<pre>	FOOD_DEF(50,0)
</pre>
<p>It is recommended that you only set the value between 1 and 10 so
	that players have to eat a bit as if they were eating in the real
	world.
</p>
<h4><span class="mw-headline" id="Light_object_macro">Light object macro</span></h4>
<p>	The light macro is very simply to use it only has two values
	duration and brightness of light.  The macro is defined as
	follows:
</p>
<pre>	#define LIGHT_DEF(hours, how_bright)   \
	   type ITEM_LIGHT     \
	   value[0] hours      \
	   value[1] how_bright
</pre>
<p>The first argument is the duration in mud hours which is about 5
	   minutes per mud hour.  The second argument is how bright the object
	   is 0 would be stupid cause it would give off no light but you never
	   know maybe you want to do something like that.  One, two, and three
	   would be small torch, large torch, and lantern respectively.  You
	   could set a brightness greater than 3 but you should be carefull not
	   to over light your characters or you may cause light bugs.
</p>
<h4><span class="mw-headline" id="Container_macro">Container macro</span></h4>
<p>	 The container macro is a simple macro that just sets two fields.
	The only information you have to give it is the capacity of the
	container.  Remember that capacity of an item is in weight not size.
	Therefore if some ones corpse weighs 230 pounds you will need a container
	that has a capacity of 230 to fit the corpse in it.  The following is
	the macros definition as found in <i>wmacros.h</i>:
</p>
<pre>	#define CONTAINER_DEF(max_capacity)  \
	   type ITEM_CONTAINER               \
	   capacity max_capacity
</pre>
<p>If you wanted to create a coffin that could carry any normal human
	   corpse you could set it something like this:
</p>
<pre>	container_def(300)
</pre>
<h4><span class="mw-headline" id="Money_macro">Money macro</span></h4>
<p>	Money is one of the simplest objects you can make on the VME
	server.  With this macro all you need is the symbolic before the macro
	and the end keyword after the macro and you have 1 piece of money or a whole pile.  The macro is defined in the <i>wmacros.h</i> and looks exactly as follows:
</p>
<pre>	#define MONEY(coin_type, coins) \
	  type ITEM_MONEY \
	  manipulate MANIPULATE_TAKE \
	  title coin_type \
	  value[0] coins
</pre>
<p>The arguments are simple the first argument is the type of money the five possible values are:
</p>
<ul><li>IRON_PIECE</li>
<li>COPPER_PIECE</li>
<li>SILVER_PIECE</li>
<li>GOLD_PIECE</li>
<li>PLATINUM_PIECE</li></ul>
<p>The second argument is the amount of coins.  If you set it to
	zero then it will still make exactly 1 of the coins.  The following
	would be what one platinum piece would be like in a zone file.
</p>
<pre>	platinum_piece

	MONEY(PLATINUM_PIECE, 0)
	/* Rest of values are inserted at runtime */

	end
</pre>
<p>Now if you want to make a whole pile of money it would look like this:
</p>
<pre>	platinum_pile

	MONEY(PLATINUM_PIECE, 80)
	/* Rest of values are inserted at runtime */
	extra {}
	"Holy cow thats a stash."

	end
</pre>
<h4><span class="mw-headline" id="Cursed_objects_macro">Cursed objects macro</span></h4>
<p>	Sometimes when making special objects you want to make an item
	that a person can wear but can't remove.  With the cursed object macro
	this is a simple thing.  The cursed object macro is defined in
	<i>wmacros.h</i> and looks as follows:
</p>
<pre>	#define CURSED_OBJECT \
	affect \
	   id ID_CURSE \
	   duration -1 \
	   firstf TIF_NONE \
	   tickf  TIF_NONE \
	   lastf  TIF_NONE \
	   applyf APF_MOD_OBJ_FLAGS \
	   data[0] OBJ_NO_UNEQUIP;
</pre>
<p>to use this macro it is simply a matter of putting the define
	in your object like this:
</p>
<pre>	CURSED_OBJECT
</pre>
<p>When you set this macro on an object it adds an affect that can
	only be removed by the 'set' command or by the 'remove curse
	spell'.
</p>
<h4><span id="Potion,_wand,_and_staff_macros"></span><span class="mw-headline" id="Potion.2C_wand.2C_and_staff_macros">Potion, wand, and staff macros</span></h4>
<p>	The macros for potions, scrolls, wands, and staffs are almost the
	same.  In fact there is only two differences. The first  is the potions and scrolls can cast three
	spells while wands can only cast two, The second is wands and staffs
	have multiple charges possible while scrolls and potions only can be
	used once.  The following are the macros
	for all four as found in <i>wmacros.h</i>.
</p>
<pre>	#define POTION_DEF(power,spell1,spell2,spell3)  \
	  manipulate {MANIPULATE_TAKE, MANIPULATE_HOLD} \
	  flags {UNIT_FL_MAGIC} \
	  spell power      \
	  type ITEM_POTION \
	  value[0] power   \
	  value[1] spell1  \
	  value[2] spell2  \
	  value[3] spell3

	#define SCROLL_DEF(power,spell1,spell2,spell3)  \
	  manipulate {MANIPULATE_TAKE, MANIPULATE_HOLD} \
	  flags {UNIT_FL_MAGIC} \
	  spell power      \
	  type ITEM_SCROLL \
	  value[0] power   \
	  value[1] spell1  \
	  value[2] spell2  \
	  value[3] spell3

	#define WAND_DEF(power,charge,spell1,spell2)  \
	  manipulate {MANIPULATE_TAKE, MANIPULATE_HOLD} \
	  flags {UNIT_FL_MAGIC} \
	  spell power      \
	  type ITEM_WAND \
	  value[0] power   \
	  value[1] charge  \
	  value[2] spell1  \
	  value[3] spell2  \
	  value[4] charge  /* The max charge */

	#define STAFF_DEF(power,charge,spell1,spell2)  \
	  manipulate {MANIPULATE_TAKE, MANIPULATE_HOLD} \
	  flags {UNIT_FL_MAGIC} \
	  spell power      \
	  type ITEM_STAFF  \
	  value[0] power   \
	  value[1] charge  \
	  value[2] spell1  \
	  value[3] spell2  \
	  value[4] charge  /* The max charge */
</pre>
<p>The arguments are as follows for the macros.
</p>
<dl><dt>power</dt>
<dd>The first argument on potions, scrolls, wands, and staff is the power the spell will be cast at.  You can have the power set in the range 1-200.  The spell power works the same as a player training in the spell.  The higher the number the more powerfull the cast.</dd>
<dt>charge</dt>
<dd>The second argument on the staffs and wands is how many charges it has.</dd>
<dt>spell#</dt>
<dd>On potions and scrolls you can set up to 2 spells you do not have to set them both the one you don't want set to 0.  On staffs and wands you can set three spells.  Again if you want only one or two you can leave the one you do not want set to 0.</dd></dl>
<h4><span class="mw-headline" id="Magical_transfer_macros">Magical transfer macros</span></h4>
<p>	There are times when you want to give a player a bonus in a
	ability, weapon, skill, and or weapon.  There is even times when you
	want to adjust a characters speed or add a flag to a player when they
	wear an item.  The following macros are what you would use to do any of
	those when a person uses an item.
</p>
<ul><li>CHAR_FLAG_TRANSFER(_MFLAGS)</li>
<li>SKILL_TRANSFER(skill, amount)</li>
<li>WEAPON_TRANSFER(weapon, amount)</li>
<li>SPELL_TRANSFER(spell, amount)</li>
<li>STR_TRANSFER(amount)</li>
<li>DEX_TRANSFER(amount)</li>
<li>CON_TRANSFER(amount)</li>
<li>CHA_TRANSFER(amount)</li>
<li>BRA_TRANSFER(amount)</li>
<li>MAG_TRANSFER(amount)</li>
<li>DIV_TRANSFER(amount)</li>
<li>HIT_TRANSFER(amount)</li>
<li>SPEED_TRANSFER(newspeed)</li>
<li>SLOW_TRANSFER(amount)</li></ul>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>For the full definitions of the transfer macros see (Link to app-f) or the header file <i>wmacros.h</i>.</p></blockquote>
<p>	The transfer macros can be broken down into three groups those
	which transfer percentage, flags, and speed.  The skill, weapons,
	spells, and ability macros transfer the amount of percentage you put.
	If you give a negative percentage it will take that much away from the
	player or NPC in that catagory.  The character flag transfer actually
	adds the flag to the player while the player is using the item.  The
	speed transfer macros add or subtract the amount of speed you give them.
	The range for speed is from zero to twelve with twelve being the
	slowest.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section" title="Manual:Zone Manual/The Objects Section">Previous: The Objects Section</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Objects-Section-Building-your-first-object" title="Manual:Zone Manual/The Objects Section/Building your first object">Next: Building your first object</a></div></div>