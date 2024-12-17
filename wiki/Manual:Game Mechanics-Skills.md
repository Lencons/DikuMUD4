<div class="mw-parser-output"><div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1 tocsection-1"><a href="#Skills"><span class="tocnumber">1</span> <span class="toctext">Skills</span></a>
<ul>
<li class="toclevel-2 tocsection-2"><a href="#Swim"><span class="tocnumber">1.1</span> <span class="toctext">Swim</span></a></li>
<li class="toclevel-2 tocsection-3"><a href="#Flee"><span class="tocnumber">1.2</span> <span class="toctext">Flee</span></a></li>
<li class="toclevel-2 tocsection-4"><a href="#Search"><span class="tocnumber">1.3</span> <span class="toctext">Search</span></a></li>
</ul>
</li>
</ul>
</div>

<h2><span class="mw-headline" id="Skills">Skills</span></h2>
<p>It seems skill (spells et. al) checks got kind of lost in the mists of time. Here is the general idea:
</p><p>Skills are all in [0..250]. Generally [0..100] for players.
</p><p>Players have a complete skill tree. NPCs have no skills, instead either an ability or their level is used based on the skill. As a rule of thumb a player's skill should roughly equal the player's level * 2 [??]. So a level 20 player should generally have a 40 [??] swim skill (some more, some less). An NPC would generally have a skill of 1 per level, often an ability is used in place of a skill.
</p><p>Skill checks are rolled open-ended 1d100.
</p><p>A general purpose table of the meaning of a skill level:
</p>
<pre>  0: You're completely incompetent. No idea how to perform this skill. You might even panic.
 40: An average person's skill (real world), for example an average swimmer
100: is the best (real world) human skill. 
200: is beyond what a human being could normally achieve, we're perhaps in the divine skill territory here.
</pre>
<p>Note that a char with a skill of N will fail half the time when the difficulty is N.
</p><p><br />
</p>
<h3><span class="mw-headline" id="Swim">Swim</span></h3>
<p>Let's use swim as an example. A characters proficiency in swim in 0..100. The table below is a rough translation of a swimming skill.
</p>
<pre>  0: You'll risk drowning in shallow water even if your feet can touch the bottom. 
 40: An average (real world) swimmer
100: is the best human swimmer in the (real) world. 
200: is the most divine swimmer.
</pre>
<p><br />
Now imaging having swim in average conditions. If your skill is average (50) then the skill check 
is to see the result of (1d100 + skill) - 100. If the result is above 0 the swim was a success.
Therefore if your skill is 0 you always fail an average swim roll is &gt; 100. If your skill is 75
for an average swim, you succeed 75% of the time. If your skill is 100 then you always
succeed. Remember that the open-ended roll can of course always offset even a sure success or
fail.
</p><p>A room's swim difficulty could be:
</p>
<pre>   0: Super easy. 
  30: Pretty easy for most characters, still rather challenging for newbies.
  70: Kinda hard - great for rapids in high-level areas.
 100: A super difficult swim. It would mean even the (real world's) best swimmer would fail half the time under these circumstances. Players with 200 skill succeed always (except OE).
 150: The world's best swimmer would probably fail a swim direction most of the time.
</pre>
<p>A character that fails a skill check might be swallowing water if the fail is [0..-20]. And might
take one hp damage per 10 failure if the result is worse than -20.
</p><p>The function skillcheck() captures precisely this setup.
</p><p>As above, the swim skill works much the same way. 
The player commands are swim on/off or swim &lt;direction&gt;. 
The room should have the <code> SECT_WATER_SAIL flag </code>.
</p><p>Notice in the example below, the difficulty for swimming east is 0. Because it's a very calm river in the light part of the forest. Swimming west is up-steam, but also into a dark cold part of the river. So it's set to 20. Swimming south to the toy zone is set to 5 because I figured you'd have to swim across the river.
In the following example notice how to denote a calm river, where the difficulty is 0. It's not a strong current and the area overall is a beginner's area. Swimming west from here is upstream so
you notice that the difficulty is higher whereas swimming south is kind of crossing the river and not as difficult. 
</p><p>There is also an optional dil for rooms with currents. It will move anything in the room downstream after time and replaces the legacy <code>force_move</code>. 
</p>
<pre>lightriver
title "On the River in Haon-Dor"
descr "The river slowly flows east towards the village of Udgaard. North you see a landing spot in the light part of the forest."

movement SECT_WATER_SAIL

north to rn_6018;
west  to darkriver2    difficulty 20 descr "Much further upstream the forest becomes more dense.";
east  to river@udgaard difficulty 0  descr "The river continues to the east.";
south to river1@toy    difficulty 5  descr "The river forks and bends south.";

dilcopy watercurrent@basemove(DIR_EAST,{
          "The river current gently takes you east.", 
          "$1n gently flows away to the east.", 
          "You gently flow a little further eastwards.", 
          "$1n flows in from the west."},
           5);
end
</pre>
<h3><span class="mw-headline" id="Flee">Flee</span></h3>
<p>For a skill like flee, the difficulty could be an expression of the character's and opponent levels compared.
</p>
<pre> +5: For each level better than the opponent
  0: Same level, no modifier
 -5; For each level worse than the opponent
</pre>
<p>So a level 5 PC fighting a level 1 rabbit gets a +40 bonus to flee. Since an NPC does not have skills, generally its level can be used as its skill. So a level 50 NPC
has a flee skill of 50.
</p>
<h3><span class="mw-headline" id="Search">Search</span></h3>
<p>On any hidden item is a 'difficulty' rating on a scale of 0-100. It could technically go from 0-250 but that's just crazy.
It is denoted in the zone file as below with X being a number between 0 and 100:<br />
</p>
<pre>open {EX_OPEN, EX_CLOSE, EX_HIDDEN} difficulty X; 
</pre>
<p><br />
Searching depends on the searcher's skill level in searching as well as their brain ability. Each search attempt costs 20 endurance so that the player knows something is there. 
The difficulty you choose for hidden exits is also the same difficulty the door would need to be if the lock were pick-able as there cannot be more than one difficulty per exit.
If a player's skill is average (50) then the skill check is to see the result of <code>(1d100 + skill) - 100 </code>. Another way to note it would be <code>rnd(1,100) + skill - 100</code> If the result is above 0 the search will be successful. Therefore if your skill is 0 you always fail an average swim roll is &gt; 100. If your skill is 75 for an average swim, you succeed 75% of the time. If your skill is 100 then you always succeed. Remember that the open-ended roll can of course always offset even a sure success or fail.
</p></div>