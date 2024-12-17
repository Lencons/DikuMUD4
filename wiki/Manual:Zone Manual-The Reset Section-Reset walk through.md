<div class="mw-parser-output"><h3><span class="mw-headline" id="Reset_walk_through">Reset walk through</span></h3>
<p>	The dragon station is almost finished.  All you have to do now is
	create the resets for it.  We don't have a lot of stuff in the zone but
	we have enough to make a decent example of how the resets work.  As I
	mentioned at the start of the chapter on resets I like to do the doors
	first, the objects in rooms second, then the NPCs.  again this is
	nothing we force you to do but I find it helps me keep track of my items
	and NPCs.
</p><p>	With that in mind we will start by resetting our doors.  In the
	zone there is two doors.  One is a regular door that is closed when the
	mud reboots and the other is a hidden and locked door when the mud
	reboots.  We will not block the rooms in and show you them again but
	if you want to you can see the rooms in (Link to finishedzone).
	the resets for these doors would look like this.
</p>
<pre>	//Office door reset
	door hallway EAST {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED}
	door office WEST {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED}

	//secret door reset
	door office SOUTH {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED,EX_HIDDEN}
	door portal_room   NORTH {EX_OPEN_CLOSE, EX_CLOSED,EX_LOCKED}
</pre>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>Both sides of the door don't have to have the exact same flags the door in the office is hidden but the one on the ship is not.</p></blockquote>
<p>	The next thing to build resets for is the two items we are loading
	directly into rooms and their contents if they have any.  The two items
	we are loading into rooms are the board and the weapons locker.  I am
	just going to stick the board in the main chamber and the weapons locker
	in the office.  The reset for these two items looks like this.
</p>
<pre>	load info_board into chamber

	load wpn_locker into office
	  {
	  load w_stiletto
	  }
</pre>
<p>Notice we also loaded a stiletto into the weapons locker and it will
	only load once a reboot since the cabinet will never be removed and
	unless the cabinet reloads the stiletto will not reload.
</p><p>	finally we get to the NPcs and their equipment.  We only have 3
	NPCs in our zone so it shouldn't be any problem especially since we don't
	have that much close.  I am going to load the dragon into the ship on a
	percentage chance basis and then load the Janitor into the station so he
	can get to cleaning it up.  Finally I will load Bob into the office so
	he can sit and count his money.
</p>
<pre>	load bob into office
	  {
	  equip pol_plate WEAR_BODY
	  }

	  load janitor into chamber
	    {
		equip pol_plate WEAR_BODY
		}

		random 50
		  {
		  load bldragon
		      {
		  load maskwa
		  }
	  }
</pre>
<p>Only a couple final things to point out.  It doesn't matter if you
	load the same type of plate or same type of clothing on every NPC.  It
	would look pretty silly if everyone was wearing the same clothes but I
	wanted to make sure you understood you didn't have to make one set for
	everyone.  Also you don't have to equip wearable things you can load
	them into the inventory like we did with the ring on the dragon.  That
	about covers it all.  The resets are now done and we can now put them
	all together with the zone and complete our dragon station.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-The-Reset-Section-Special-reset-functions" title="Manual:Zone Manual/The Reset Section/Special reset functions">Previous: Special reset functions</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-The-Reset-Section-The-complete-dragon-station" title="Manual:Zone Manual/The Reset Section/The complete dragon station">Next: The complete dragon station</a></div></div>