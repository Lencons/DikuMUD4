<div class="mw-parser-output"><div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1 tocsection-1"><a href="#NPC-macros"><span class="tocnumber">1</span> <span class="toctext">NPC macros</span></a>
<ul>
<li class="toclevel-2 tocsection-2"><a href="#The-attack-and-armour-macro"><span class="tocnumber">1.1</span> <span class="toctext">The attack and armour macro</span></a></li>
<li class="toclevel-2 tocsection-3"><a href="#The-defense-and-offense-bonus-macro"><span class="tocnumber">1.2</span> <span class="toctext">The defense and offense bonus macro</span></a></li>
<li class="toclevel-2 tocsection-4"><a href="#The-NPc-abilities-macro"><span class="tocnumber">1.3</span> <span class="toctext">The NPc abilities macro</span></a></li>
<li class="toclevel-2 tocsection-5"><a href="#The-NPc-weapon-and-spell-macros"><span class="tocnumber">1.4</span> <span class="toctext">The NPc weapon and spell macros</span></a></li>
<li class="toclevel-2 tocsection-6"><a href="#Using-the-composed.h"><span class="tocnumber">1.5</span> <span class="toctext">Using the composed.h</span></a></li>
</ul>
</li>
</ul>
</div>

<h3><span class="mw-headline" id="NPC_macros">NPC macros</span></h3>
<h4><span class="mw-headline" id="The_attack_and_armour_macro">The attack and armour macro</span></h4>
<p>	The natural attack and armour fields allow you to set the NPC to
	do damage like a certain type of weapons and to defend like a certain
	type of armour respectively.  Lets say you had a metal cougar it would
	have an attack type of claw and an armour type of plate while a normal
	dog would have an armour type of leather and an attack type of bite.
	The 'NATURAL_DEF' macro is what allows you to set these fields.  This
	macro is defined in <i>wmacros.h</i> and looks like
	this.
</p>
<pre>	#define NATURAL_DEF(weapon_category, armour_category) \
	   armour armour_category \
	   attack weapon_category
</pre>
<p>The word natural can sometimes be a little confusing since you can
	set any of the weapons types you like on the NPC.  It doesn't exactly
	make sense to have a dog that attacks as if it uses a long sword but if
	you wish it you can do it.  The following is a short list of just the
	natural weapon types but you can find a full list in
	(Link to app-d) or in the <i>values.h</i> of your mud
	just in case you have added some weapon types.
</p>
<pre>	#define WPN_FIST         34
	#define WPN_KICK         35
	#define WPN_BITE         36
	#define WPN_STING        37
	#define WPN_CLAW         38
	#define WPN_CRUSH        39
</pre>
<p>Again you don't have to use leather for dogs as we have already
	mentioned with our metal cat idea you could make a cloth dragon if you
	really want but its up to you to keep some sanity on your VME.  The
	following is the list of armour types that can be set.  You will see
	that the list is exactly the same as the list you will find later when
	making armour.
</p>
<pre>	#define ARM_CLOTHES  0  /*Same as a Human in jeans and a T-shirt*/
	#define ARM_LEATHER  1  /* A soft flexible leather base armour   */
	#define ARM_HLEATHER 2  /* A hard un flexible leather base armour */
	#define ARM_CHAIN    3  /* A flexible armour composed of interlocking rings */
	#define ARM_PLATE    4  /* An un flexible plate armour. */
</pre>
<p>Now that you have the defines to work with we will return to our
	metal cat and normal dog.  The definitions for them would look something
	like this.
</p>
<pre>	//Metal Cat
	NATURAL_DEF(WPN_CLAW, ARM_PLATE)

	//normal dog
	NATURAL_DEF(WPN_BITE, ARM_LEATHER)
</pre>
<p>You  should  know  that the weight of the monster  determines  the
	maximum  amount of damage it can give when using a natural attack.
	The weight is categorized as follows:
</p>
<table class="wikitable">
<caption>Weight size chart
</caption>
<tbody><tr>
<th>LBS
</th>
<th>Size
</th></tr>
<tr>
<td>0 - 5
</td>
<td>Tiny
</td></tr>
<tr>
<td>6 - 40
</td>
<td>Small
</td></tr>
<tr>
<td>41 - 160
</td>
<td>Medium
</td></tr>
<tr>
<td>161 - 500
</td>
<td>Large
</td></tr>
<tr>
<td>500 and up
</td>
<td>Huge
</td></tr></tbody></table>
<p>By default monsters are medium.  So make sure you take this into
	account when you are creating your NPC.
</p>
<h4><span class="mw-headline" id="The_defense_and_offense_bonus_macro">The defense and offense bonus macro</span></h4>
<p>	There comes a time when you may want to make your NPC super
	naturally powerful.  It is for those times that the offense and defense
	fields are available for you to set.  Normally they default to 0 but you
	can set them from 0 to 5000.  The higher you set the offense number the
	harder you will hit people you a re in combat with.  The higher you set
	the defense the harder it will be for people to hit your NPC.  The
	following macro allows you to set both the offense and defense.
</p>
<pre>	#define ATTACK_DEFENSE(attack, defense) \
	offensive attack \
	defensive defense
</pre>
<p>Using this macro is rather easy you just put the value you want
	for each and your all done
</p>
<pre>	//a really hard hitting hard to kill NPC
	ATTACK_DEFENSE( 1000, 1000)
</pre>
<h4><span class="mw-headline" id="The_NPc_abilities_macro">The NPc abilities macro</span></h4>
<p>	All  abilities are in the range [1..200]. Players usually  have  a
	maximum of 150, modified by magic... 200 is considered divine.
	When  creating a monster you can not directly specify the size  of
	the  abilities,  instead you specify a percentage distribution  of
	points.  The amount of points are then distributed by the computer
	according  to  the  specified level.  The  'MSET_ABILITY'  macro  is
	available for this purpose, and is defined as:
</p>
<pre>	#define MSET_ABILITY(str,dex,con,hpp,bra,cha,mag,div)   \
		ability[ABIL_STR]  str   \
	  ability[ABIL_DEX]  dex   \
	  ability[ABIL_CON]  con   \
	  ability[ABIL_HP]   hpp   \
	  ability[ABIL_BRA]  bra   \
	  ability[ABIL_MAG]  mag   \
	  ability[ABIL_DIV]  div   \
	  ability[ABIL_CHA]  cha
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;">
<p>	Note the sum of the ability values must be 100%. This is thus
	an example of an ability distribution:
 
	     MSET_ABILITY(25,15,10,15,10,5,10,0)  /* Sum is 100% */
</p>
</blockquote>
<p>	The  amount of points distributed depends directly upon the  level
	of the monster and the percentage.  If the percentage is too high and the
	level is also set High some ability points may be lost since a NPC gets
	all abilities over 255 cut off.  For example a level 199 monster with an  ability
	percentage  a  bit above 20% will make an ability  above  the  255
	points maximum.  In the current combat system in the VME 2.0 it is not
	necessary to spend points on both 'mag' and 'div' on the NPC since only
	one or the other is ever used depending on which is higher.
</p>
<h4><span class="mw-headline" id="The_NPc_weapon_and_spell_macros">The NPc weapon and spell macros</span></h4>
<p>	NPCs know about weapons and spells but not at the same detailed
	level as the player.  For NPCs the spell and weapon group are used.
	Thus the Axe hammer category defines all defence and all attack for all
	kinds of axes and hammers, whereas the player would have to train
	individually in each axe and hammer type. The same is true for spells.
	Thus if a monster has 25 points in the weapon sword category it will
	fight (and defend) with all sword-like weapons at skill 25. When you
	define weapon and spell skills (monsters have no skill skills) you also
	define these as percentages, and the program automatically distributes
	the points. Use the pre-defined macros:
</p>
<pre>	#define MSET_WEAPON(axe_ham, sword, club_mace, pole, unarmed, special)  \
	weapon[WPN_AXE_HAM]    axe_ham   \
	weapon[WPN_SWORD]      sword      \
	weapon[WPN_CLUB_MACE]  club_mace  \
	weapon[WPN_POLEARM]    pole \
	weapon[WPN_UNARMED]    unarmed    \
	weapon[WPN_SPECIAL]    special
</pre>
<table class="wikitable">
<caption>MSET_WEAPON arguments
</caption>
<tbody><tr>
<th>Argument
</th>
<th>Description
</th></tr>
<tr>
<td>axe_ham
</td>
<td>any hammer or axe
</td></tr>
<tr>
<td>sword
</td>
<td>any sword like weapon, including dagger and rapier, etc.
</td></tr>
<tr>
<td>club_mace
</td>
<td>any club or mace like weapon, flails,  morning star, etc.
</td></tr>
<tr>
<td>polearm
</td>
<td>any spear or pole like weapon:  spear, trident, sickle, scythe etc.
</td></tr>
<tr>
<td>unarmed
</td>
<td>Is any bite, claw, sting or other natural attack.
</td></tr>
<tr>
<td>special
</td>
<td>any very peculiar weapon, currently only whip.
</td></tr></tbody></table>
<pre>	#define MSET_SPELL(div, pro, det, sum, cre, min, hea, col, cel, int, ext)  \
	spell[SPL_DIVINE]      div  \
	spell[SPL_PROTECTION]  pro  \
	spell[SPL_DETECTION]   det  \
	spell[SPL_SUMMONING]   sum  \
	spell[SPL_CREATION]    cre  \
	spell[SPL_MIND]        min  \
	spell[SPL_HEAT]        hea  \
	spell[SPL_COLD]        col  \
	spell[SPL_CELL]        cel  \
	spell[SPL_INTERNAL]    int  \
	spell[SPL_EXTERNAL]    ext
</pre>
<table class="wikitable">
<caption>MSET_SPELL arguments
</caption>
<tbody><tr>
<th>Argument
</th>
<th>Description
</th></tr>
<tr>
<td>div
</td>
<td>Covers all divine sphere spell.
</td></tr>
<tr>
<td>pro
</td>
<td>Covers all protection sphere spells.
</td></tr>
<tr>
<td>det
</td>
<td>Covers all detection sphere spells.
</td></tr>
<tr>
<td>sum
</td>
<td>Covers all summoning spells.
</td></tr>
<tr>
<td>Cre
</td>
<td>Covers all creation spells.
</td></tr>
<tr>
<td>min
</td>
<td>Covers all mind spells.
</td></tr>
<tr>
<td>hea
</td>
<td>Covers all heat spells (fireball, etc.)
</td></tr>
<tr>
<td>col
</td>
<td>Covers all cold spells (frostball, etc.)
</td></tr>
<tr>
<td>cel
</td>
<td>Covers all cell (electricity) spells (lightning bolt, etc.)
</td></tr>
<tr>
<td>int
</td>
<td>Covers all internal (poison) spells (toxicate, etc.)
</td></tr>
<tr>
<td>ext
</td>
<td>Covers all external (acid) spells (acid ball etc).
</td></tr></tbody></table>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>If your not sure what your weapon or spell is categorized as you can look in the <i>weapons.def</i> or the <i>spells.def</i> for that you are using for your VME server.</p></blockquote>
<p>	 The sum of all spell and weapon
	 skills must be 100%. For example, the following would be a legal
	 setting of weapons and spells.
</p>
<pre>	//  75%  Total,  Club/Mace  is primary
	      MSET_WEAPON(10,10,20,5,15,5)

	//  25%  Total,  Fire  is primary
	      MSET_SPELL(8,0,0,3,0,3,2,3,3,3,3)
</pre>
<p>Remember that the groups define both attack and defence.  Thus  if
	you  make  an Orc which has 0% in the flail group it can only  use
	its  dexterity to defend itself. Likewise with spell  groups.  For
	this  reason  the groups are both "resistance" as well  as  attack
	groups.
</p>
<h4><span class="mw-headline" id="Using_the_composed.h">Using the composed.h</span></h4>
<p>	The  file composed.h contains many standard monsters. It is a good
	idea  to  study these definitions, as they form the basis of  many
	different  monsters. Note that the definitions  by  no  means  are
	perfect,  but  we  are hoping to make a more  or  less  complete
	monster  compendium.  If  you create certain  (general)  monsters,
	please design it as a macro so it can be incorporated in  the
	file. The more monsters created by using these macros the easier it will
	be for your builders to create NPCs.  If you think you have a really
	all inclusive Composed.h and want to share it with the rest of the VME
	servers running out there on the internet.  Feel free to submit it to
	the VME staff and we will put it in the contribution directories on our
	release site.
</p>
	<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>For more information on how to use the composed.h when building your NPC see (Link to npcbasic).</p></blockquote>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section" title="Manual:Zone Manual/The NPC Section">Previous: The NPC Section</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-NPC-Section-Building-your-first-NPC" title="Manual:Zone Manual/The NPC Section/Building your first NPC">Next: Building your first NPC</a></div></div>