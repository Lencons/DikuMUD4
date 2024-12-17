<div class="mw-parser-output"><div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1 tocsection-1"><a href="#Intro"><span class="tocnumber">1</span> <span class="toctext">Intro</span></a></li>
<li class="toclevel-1 tocsection-2"><a href="#Construction"><span class="tocnumber">2</span> <span class="toctext">Construction</span></a>
<ul>
<li class="toclevel-2 tocsection-3"><a href="#Dil-On-an-Object"><span class="tocnumber">2.1</span> <span class="toctext">Dil On an Object</span></a></li>
<li class="toclevel-2 tocsection-4"><a href="#DIL-on-an-NPC"><span class="tocnumber">2.2</span> <span class="toctext">DIL on an NPC</span></a></li>
<li class="toclevel-2 tocsection-5"><a href="#Dil-on-a-PC"><span class="tocnumber">2.3</span> <span class="toctext">Dil on a PC</span></a></li>
</ul>
</li>
</ul>
</div>

<h1><span class="mw-headline" id="Intro">Intro</span></h1>
<p>I put this section in here because while many programmers already know most of this inherently, many casual mudders have the curiosity and want to start building but don't know where to start with dil and the manual can be a bit overwhelming. 
So this is a compilation of the most frequently asked questions and overall stumbling blocks we've seen for new coders. Hopefully it helps.
</p>
<h1><span class="mw-headline" id="Construction">Construction</span></h1>
<p>Every DIL program has the following structure:<br />
</p>
<pre> dilbegin programname();
 var
 code
 {}
 dilend
<br />
</pre>
<p><br />
Every dil must run on an object. That object is always going to be 'self' to the program.
It will be running from one of the following things:<br />
</p>
<ul><li>A room</li>
<li>A mobile (npc)</li>
<li>A player</li>
<li>An object (thing)<br /></li></ul>
<p>Keeping this in mind will help with your program's construction. You can also use dot notation to reference objects relative to the dil or the objects it interacts with.
Take <code>self.outside</code> and we'll look at it from each of the object types.
</p>
<h3><span class="mw-headline" id="Dil_On_an_Object">Dil On an Object</span></h3>
<p>So let's say this particular DIL lives on a gem. The gem says nice things to you when it's held. 
Considerations:<br />
Does it speak when you're incapacitated? Meditating? Fighting? 
Does it speak when you're invisible? 
Can other people hear it? 
How often can it speak?
</p>
<pre>dilbegin gem_speak();
          var
          code 
          {
             heartbeat := 90*PULSE_SEC; //every 90 seconds. 
             :start:
             wait(SFB_TICK, TRUE and self.outside.type == UNIT_ST_PC and self.equip);
             act("$1n says 'You look lovely today!'", A_ALWAYS, self.outside, self, null, TO_CHAR);
             goto start;
          }
          dilend
</pre>
<p>In this example:<br />
</p>
<ul><li>self.outside varies by where the object is. If it's in a bag, self.outside = the bag.
<ul><li>self. outside could also be an NPC if it's inside a mob. It could be a player. Remember, people can go in containers too!</li></ul></li>
<li>self.outside.outside.inside is a even a possibility!</li></ul>
<p><br />
</p>
<h3><span class="mw-headline" id="DIL_on_an_NPC">DIL on an NPC</span></h3>
<p>So this particular DIL will live on a NPC or mobile. Perhaps it will say "Greetings" every time an actual player enters the room.
</p>
<pre>dilbegin hi();
         var
         code
         {
          :start: 
          wait(SFB_DONE, command(CMD_AUTO_ENTER) and activator.type == UNIT_ST_PC);
          exec("say Hello, "+ activator.name +"!", self);
          goto start;
         }
         dilend
</pre>
<p>In this example:<br />
</p>
<ul><li>self.outside = the room the NPC is in.</li>
<li>self.inside = the NPC's inventory.</li></ul>
<h3><span class="mw-headline" id="Dil_on_a_PC">Dil on a PC</span></h3>
<p>It's unlikely that you would begin anywhere near a dil on a player. Something to keep in mind if you are writing one is how it will react in a number of circumstances. ie:  When they die? What if it's a room with $no_spam? What if they're in nightmare? What if they're in a no-tele zone? What if they're fighting? Who are they fighting? Will it provoke an attack? These are just a few things to keep in mind.
</p></div>