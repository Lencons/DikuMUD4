<div class="mw-parser-output"><div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1 tocsection-1"><a href="#Temp-list-of-changes.-Will-reorganize-once-I-see-what-all-we-have."><span class="tocnumber">1</span> <span class="toctext"><i>Temp list of changes. Will reorganize once I see what all we have.</i></span></a></li>
<li class="toclevel-1 tocsection-2"><a href="#Priority"><span class="tocnumber">2</span> <span class="toctext">Priority</span></a></li>
<li class="toclevel-1 tocsection-3"><a href="#The-.27Unique.27-DIL-Flag"><span class="tocnumber">3</span> <span class="toctext">The 'Unique' DIL Flag</span></a></li>
<li class="toclevel-1 tocsection-4"><a href="#Built-in-Player-DIL-Commands"><span class="tocnumber">4</span> <span class="toctext">Built-in Player DIL Commands</span></a>
<ul>
<li class="toclevel-2 tocsection-5"><a href="#Alias"><span class="tocnumber">4.1</span> <span class="toctext">Alias</span></a></li>
<li class="toclevel-2 tocsection-6"><a href="#Variable"><span class="tocnumber">4.2</span> <span class="toctext">Variable</span></a></li>
<li class="toclevel-2 tocsection-7"><a href="#Trigger"><span class="tocnumber">4.3</span> <span class="toctext">Trigger</span></a></li>
</ul>
</li>
</ul>
</div>

<h5><span class="mw-headline" id="Temp_list_of_changes._Will_reorganize_once_I_see_what_all_we_have."><i>Temp list of changes. Will reorganize once I see what all we have.</i></span></h5>
<h2><span class="mw-headline" id="Priority">Priority</span></h2>
<p>How does a program determine it should run and pause others? 
When performing a wstat &lt;unit&gt; func command on an object, the dil functions will display in order of priority; top to bottom with most important dils at the top. If a dil program is executing the priority command, it will block all programs below it. Many of the stock game functions call on the priority or FN_PRI to function properly.   
A few examples of dils that should/do take priority:   
</p>
<ul><li>Death ~ dilbegin recall fnpri(FN_PRI_DEATH) death_seq();</li>
<li>Rescue</li>
<li>Under Arrest ~ (dilbegin fnpri(FN_PRI_RESCUE-1)arrest_check(office:string);</li></ul>
<p>We'll refer to this concept as 'fnpri'.   
</p><p>Let's look at a Midgaard town guard, a quick wstat guard func shows:    
</p>
<ol><li>dilcopy rescue@function("guard/captain/mayor");</li>
<li>dilcopy arrest_check@midgaard("accus_room@midgaard");</li>
<li>dilbegin SFUN_PROTECT_LAWFUL time PULSE_SEC*60 bits SFB_RANTIME</li>
<li>dilbegin guard2();</li></ol>
<p>In this example, the priority belongs to rescue. Therefore the expected behavior is that this guard will prioritize rescuing someone they see being attacked before rushing off to enforce peace or arrest someone. Secondarily, if rescuing is not an active option, the guard will arrest someone before trying to keep the peace. 
If the guard is interrupted in the middle of the execution of guard2(); above, the guard2(); program will simply pause until the higher priority dils are completed.
In prior DIKU versions, there was no way to determine the dil insertion point on an object and therefore no way to predictably control execution order. So we introduce the following: 
</p>
<table class="wikitable">

<tbody><tr>
<th>vme.h#define</th>
<th>Integer</th>
<th>Comment
</th></tr>
<tr>
<td>FN_PRI_RES</td>
<td>0</td>
<td>Don't use
</td></tr>
<tr>
<td>FN_PRI_SYS</td>
<td>1</td>
<td>functions dealing with death
</td></tr>
<tr>
<td>FN_PRI_DEATH</td>
<td>2</td>
<td>functions dealing with death
</td></tr>
<tr>
<td>FN_PRI_BODY</td>
<td>5</td>
<td>gaining hits, etc
</td></tr>
<tr>
<td>FN_PRI_COMBAT</td>
<td>10</td>
<td>in-combat moves
</td></tr>
<tr>
<td>FN_PRI_RESCUE</td>
<td>20</td>
<td>Rescue someone rather than passing by
</td></tr>
<tr>
<td>FN_PRI_BLOCK</td>
<td>25</td>
<td>Blocking things like commands
</td></tr>
<tr>
<td>FN_PRI_MISSION</td>
<td>30</td>
<td>Sent on an important mission
</td></tr>
<tr>
<td>FN_PRI_CHORES</td>
<td>40</td>
<td>Picking up garbage or eating rabbits.
</td></tr></tbody></table>
<h2><span id="The_'Unique'_DIL_Flag"></span><span class="mw-headline" id="The_.27Unique.27_DIL_Flag">The 'Unique' DIL Flag</span></h2>
<p>In DIKU III, we introduce the unique flag in a dil program.   
dilbegin unique programName();
</p><p>This unique flag or keyword works to ensure that a unit will never have more than one of that function available on the object at any given time. This is a great way to cut down on the length of new dils because instead of having to do an if(dilfind) every time, you can simply use the unique flag. For example, if you create an entangle spell, and want to have a DIL that can be copied onto char's affected by entanglement, then the unique flag makes sure that even if the spell was cast twice on the same char, there would be only one instance of the entangle DIL running on that char.   
</p>
<h2><span class="mw-headline" id="Built-in_Player_DIL_Commands">Built-in Player DIL Commands</span></h2>
<p>Three are three new commands implemented for players (in DIL).    
</p>
<ul><li>alias</li>
<li>trigger</li>
<li>variable</li></ul>
<p>Many of you will recognize these as components of mud clients like zmud/cmud/mudlet etc.   
This change makes muds a little more accessible by presenting the mud in a web form while still allowing for some of the basic automations found in clients.
</p>
<h3><span class="mw-headline" id="Alias">Alias</span></h3>
<table class="wikitable">

<tbody><tr>
<th>alias</th>
<th>arbitrary name</th>
<th>commands</th>
<th>result
</th></tr>
<tr>
<td>alias</td>
<td>fido</td>
<td>goto fido;tell fido hello;pet fido</td>
<td>travel to fido. You tell Fido Hello. You pet Fido
</td></tr>
<tr>
<td>alias</td>
<td>tf</td>
<td>tell fido $1</td>
<td>You tell Fido Hi
</td></tr>
<tr>
<td>alias</td>
<td>tf</td>
<td>tell fido $0</td>
<td>You tell Fido a whole string of stuff.
</td></tr></tbody></table>
<table class="wikitable">

<tbody><tr>
<th>pointer</th>
<th>use
</th></tr>
<tr>
<td>$0</td>
<td>Entire string
</td></tr>
<tr>
<td>$1</td>
<td>1st Word
</td></tr>
<tr>
<td>$2</td>
<td>2nd Word
</td></tr></tbody></table>
<h3><span class="mw-headline" id="Variable">Variable</span></h3>
<p>Variables are basically stringlists and can be defined as such:
variable friends papi|john|aja|bruce|cityguard|the janitor
To recall a variable for use in a trigger, you will notate it as (@variablename) or in this example (@friends). This is recalled in the example below. 
</p>
<h3><span class="mw-headline" id="Trigger">Trigger</span></h3>
<p>If you want to do whatever the beastly Fido tells you to do:  
</p><p>$trigger obey /^the Beastly Fido tells you '(.+?)'/ $1   
</p><p>Or maybe you'd like to    
</p><p>$trigger smarmy /^(@friends)\sleaves (.+?)\.$/ say I love $1. Especially when $1 leaves $2. 
</p><p>You may notice this is written with Regular Expressions. If you're not familiar or want to learn more: <a rel="nofollow" class="external text" href="https://regexr.com/">RegEx Reference</a>
</p></div>