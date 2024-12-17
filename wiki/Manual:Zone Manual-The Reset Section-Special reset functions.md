<div class="mw-parser-output"><div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1 tocsection-1"><a href="#Special-reset-functions"><span class="tocnumber">1</span> <span class="toctext">Special reset functions</span></a>
<ul>
<li class="toclevel-2 tocsection-2"><a href="#The-complete-directive."><span class="tocnumber">1.1</span> <span class="toctext">The complete directive.</span></a></li>
<li class="toclevel-2 tocsection-3"><a href="#The-follow-command"><span class="tocnumber">1.2</span> <span class="toctext">The follow command</span></a></li>
<li class="toclevel-2 tocsection-4"><a href="#The-purge-command"><span class="tocnumber">1.3</span> <span class="toctext">The purge command</span></a></li>
<li class="toclevel-2 tocsection-5"><a href="#The-random-command"><span class="tocnumber">1.4</span> <span class="toctext">The random command</span></a></li>
<li class="toclevel-2 tocsection-6"><a href="#The-remove-command"><span class="tocnumber">1.5</span> <span class="toctext">The remove command</span></a></li>
</ul>
</li>
</ul>
</div>

<h3><span class="mw-headline" id="Special_reset_functions">Special reset functions</span></h3>
<p>	Now that we have gone over the basic load and equip commands we
	have some special commands that you can add to them to make them do more
	interesting things.  Sometimes when doing resets you don't always want
	items or NPCs to load or sometimes you want them to load but only if a
	certain amount of other things correctly load.  There are also times you
	want to clear the rooms or reload an entire object after removing the
	old one.  All these things and more can be accomplished with the reset
	section.
</p>
<h4><span class="mw-headline" id="The_complete_directive.">The complete directive.</span></h4>
<p>	The 'load' and 'equip' commands have one more argument that can be
	placed at the end of them to make them act a bit different.the complete
	directive. In the case where this directive is placed at the end
	of a 'load or 'equip' command, the unit is only loaded in case all immediate commands inside
	its nesting are executed successfully.  For example:
</p>
<pre>	load captain into jail_room complete
	{
	   equip magic_sword position WEAR_WIELD max 1
	   load bag
	   {
	      load ruby_ring max 1
	   }
	}
</pre>
<p>In this case the captain is only loaded if the objects magic_sword
	and bag are successfully loaded. if the ruby_ring is not loaded,
	it will have no effect on the complete directive. To make the ruby_ring
	affect to captains complete directive, the bag must also have specified a
	complete directive (because the bag would then not be complete, and thus the
	captain would not be complete).
</p>
<h4><span class="mw-headline" id="The_follow_command">The follow command</span></h4>
<p>	Once you load a NPC you may want that NPC to follow another NPC.
	  That is what the 'follow' command is for.  The following is the format
	  of the 'follow' command
</p>
<pre>	   follow &lt;symbol&gt; &lt;load amount #&gt; &lt;complete&gt;
</pre>
<dl><dt>symbol</dt>
<dd>The first argument to the follow command is the symbolic name of the NPC to follow the NPC of the outer grouping.</dd>
<dt>load amount</dt>
<dd>the second argument is an optional argument that tells the reset how many of the NPC followers of this type  are allowed in the world, zone, or locally.  The possible values for this field are as follows:</dd></dl>
<dl><dt>max &lt;num&gt;</dt>
<dd>This  command  is  always  part  of  another reset command (load,</dd></dl>
<p>	equip, etc.).  At reset time the entire world is scanned for occurences
	of the loaded unit - only if the currently existing number is less than
	&lt;num&gt; will the command be executed.
</p>
<dl><dt>local &lt;num&gt;</dt>
<dd>This command is always  part  of  another  reset  command  (load,</dd></dl>
<p>	equip, etc.).  At reset time the location of which the unit is to
	be loaded into is scanned for occurences of the loaded unit - only  if  the currently existing number is less than &lt;num&gt; will the
	command be executed.
</p>
<dl><dt>zonemax &lt;num&gt;</dt>
<dd>This command is always  part  of  another  reset  command  (load,</dd></dl>
<p>	equip,  etc.).   At  reset  time  the  entire zone being reset is
	scanned for occurences of the loaded unit - only if the currently
	existing number is less than &lt;num&gt; will the command be
	executed.
</p>
<dl><dt>complete</dt>
<dd>This only makes the NPC follow if all the other things in the grouping finishes completely.  For a better description of how this directive works see (Link to resetcomplete).</dd></dl>
<p>The follow command is always used nested inside a loaded
	NPC to force the NPC &lt;symbol&gt; to follow the NPC of the outer
	grouping.  The following would be a correct use of the follow
	command.
</p>
<pre>	load captain into jail
	  {
	  follow guard max 4
	    {
		equip guard_helmet WEAR_HEAD
		equip guard_plate WEAR_BODY
		equip guard_legs WEAR_LEGS
		equip guard_boots WEAR_FEET
		}
		  follow guard max 4
	    {
		equip guard_helmet WEAR_HEAD
		equip guard_plate WEAR_BODY
		equip guard_legs WEAR_LEGS
		equip guard_boots WEAR_FEET
		}
	  }
</pre>
<p>This example would load two guards that are fully dressed and
	they would start following the captain which is also loaded.
</p>
<h4><span class="mw-headline" id="The_purge_command">The purge command</span></h4>
<p>	There are times when you want to clean up a room.  This can be
	done very easy by using the <b>purge</b>.  The following is
	the format of the purge command.
</p>
<pre>	purge &lt;symbol&gt;
</pre>
<p>This command doesn't take much description.  The symbol is the
	room you want to empty of all objects and NPCs.  If you wanted to get
	rid of all objects and NPCs from a room with the symbolic name of jail
	it would look like this.
</p>
<pre>	purge jail
</pre>
<h4><span class="mw-headline" id="The_random_command">The random command</span></h4>
<p>	If you ever want to load something only some of the time.  There
	is a built in <b>random</b> command that allows you to pick
	the percentage of the time that the item will load.  The random command
	has the following format.
</p>
<pre>	random &lt;num&gt;
	  {group or single set of resets}
</pre>
<p>It is important to point out this is done by a random percentage
	chance where as 1% of the time would be almost not at all and 100% of
	the time would be all the time.  If we wanted to load a group of things
	only 80% of the time it would look like this.
</p>
<pre>	random 80
	  {
	  load captain into jail_room complete
	    {
	    equip magic_sword position WEAR_WIELD max 1
	    load bag
	      {
	      load ruby_ring max 1
	      }
	    }
	}
</pre>
<h4><span class="mw-headline" id="The_remove_command">The remove command</span></h4>
<p>	Many times players take items out of containers like chests or
	steal items from your NPCs and leave them naked.  If the NPC is not dead
	the resets don't reload them therefore your NPCs will stand there empty
	and so will your chests.  This is fine if that is what you want but
	sometimes you want them to get dressed or refilled again at reset time.  that is
	what the <b>remove</b> command is for.  The following is the
	format of the remove command.
</p>
<pre>	remove &lt;symbol1&gt; in &lt;symbol2&gt;
</pre>
<p>Again the remove command is a simple command and it only has two
	arguments, the item and where it is to remove it from.  If you
	wanted to have a cabinet that at every reset it would have a knife and a
	bag of sugar in it would look like this.
</p>
<pre>	remove cabinet in kitchen
	load cabinet into kitchen
	 {
	 load sugarbag
	 load knife
	 }
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Reset-Section-Loading-objects-and-NPCs" title="Manual:Zone Manual/The Reset Section/Loading objects and NPCs">Previous: Loading objects and NPCs</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Reset-Section-Reset-walk-through" title="Manual:Zone Manual/The Reset Section/Reset walk through">Next: Reset walk through</a></div></div>