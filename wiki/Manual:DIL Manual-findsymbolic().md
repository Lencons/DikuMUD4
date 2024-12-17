<div class="mw-parser-output"><pre>unitptr findsymbolic ( s&#160;: string )
   s&#160;: Symbolic name of the unit to find (player, room, object, NPC)
   return: A pointer to an instance of the unit, or null.
   Example: findsymbolic("bread@midgaard")
</pre>
<p>This routine supplements findunit() and findsymbolic(#,#,#). It comes in handy, if it is
important to get a unitptr to a unit in the world.  This is super fast
and a great routine if it doesn't matter where in the world the unit is.
Otherwise, look at the findsymbolic(u,s,i) below  If for example,
Mary needs to send a message to John the Lumberjack,  then she should NOT
use the findunit() since it may locate a different John - even a player!
If she instead locates him using findsymbolic("john@haon_dor") she will be
certain that it is in fact her husband, and not the player John Dow from
Norway. If there was two john@haon_dor in the game, she'd get a random one of
them (but there's only one John and if there was two it wouldn't really matter
which one she would activate). This function also will return rooms and players (which it did
not do in the past), making findroom somewhat superfluous.
</p>
<pre>unitptr findsymbolic ( u&#160;: unitptr, s&#160;: string, i&#160;: integer )
   u&#160;: Search is relative to this unit.
   s&#160;: Symbolic name of the NPC or Object to find.
   i&#160;: FIND_UNIT_XXX bit vector of places to search.
   return: A pointer to an instance of the unit, or null.
   Example: findsymbolic(self, "bread@midgaard", FIND_UNIT_INVEN)
</pre>
<p>This routine supplements findroom, findunit and findsymbolic(#).  
It will simply return the first unit matching the symbolic name. 
It comes in handy, if it is important to get a correct reference to a unit somewhere
relative to 'u'.  If for example, Mary needs to check if she has her own
cooking pot, then she should NOT use the findunit since it may locate a
different pot, not belonging to Haon-Dor but to some other zone.  If she
instead locates it using findsymbolic(self, "pot@haon_dor", FIND_UNIT_IN_ME)
she would be certain that it is in fact her own cooking pot that she is
carrying around, and not some other pot from a Joe Blow's zone.
</p><p><br />
</p>
<pre>unitptr findsymbolic ( s&#160;: string, idx&#160;: integer )
   s&#160;: Symbolic name of the unit to find (player, room, object, NPC)
   idx&#160;: is the index to match (find precisely the right city guard), see unitptr.idx
   return: A pointer to an instance of the unit, or null.
   Example: findsymbolic("guard@midgaard", 71262816721)
</pre>
<p>This routine helps you find a precise unique unit in the world. So imagine a
bounty hunter. Locks on a city guard that has committed a crime. Because you
cannot secure a unitptr not in your local environment how can you find the right
cityguard in a city of 100? So when you first catch the unit, store its symname and 
idx. The use this function to retrieve it again. For players it will find the online
player regardless of the idx.
</p><p>Example:
</p>
<pre> // Presume target is pointing to a particular cityguard
 s&#160;:= target.symname; // Save the symbolic name
 i&#160;:= target.idx;
 // Do stuff. Wake up 9 hours later. Find the target again like this:
 target&#160;:= findsymbolic(s, i);
 // and if the guard is still alive you'll get your pointer back.
</pre></div>