<div class="mw-parser-output"><p>This might belong better in a builder's tutorial
</p>
<h2><span class="mw-headline" id="Room_Creation">Room Creation</span></h2>
<p>This belongs better in a builder's tutorial.
</p><p>Document Name:     room.doc
Version:           1.10
Author:            Michael Seifert (seifert@diku.dk)
Questions to:      seifert@diku.dk
Document intended for:   World Creators
</p><p>Short Description:
This document describes special interesting tricks and macros  for use with rooms.
</p><p>1. Secret Doors
To  make  a  secret door, you must set the EX_HIDDEN flag  on  the
exits open flags, for example:
</p><p>east  to  treasure_room keywords {"secret door",  "door",  "wall", "crack"} open {EX_OPEN_CLOSE, EX_HIDDEN}
descr "You notice a small crack in the wall!"
</p><p>Notice  that  it  is  important to specify  the  possible  "search
keywords" as well as the "door keywords". If you for example  omit
"wall"  or  "crack"  then a command of "search wall"  will  always
fail!
</p><p>You  must  specify how difficult it is to find the door  with  the
search  skill. The difficulty is specified in&#160;% and when it equals
the players skill level, he has a 50% chance of spotting the door.
Roughly the difficulty percentage should equal the intended player
level.   Combined with the above example, lets say  you  intend  a
level 35 to be the average searcher, you would type:
</p><p>SECRET_DOOR_DIFFICULTY(EAST, 35)
</p><p>I  can  recommend that you make room descriptions hinting  to  the
presence of the door since it will otherwise be near impossible to
find  it.  And  as  above  it is a good  idea  to  make  direction
descriptions  and also apply extra descriptions for keywords  like
"wall", "crack", etc.
</p><p>2. Rooms in rooms
A  room  can  be placed inside another room with the "in"  keyword
(see VMC.txt document).
</p><p>3. Force move
The  special function SFUN_FORCE_MOVE can be used to make  persons
automatically move to another room at specified time intervals. It
is  perfect for situations like a teleporting closet (a room in  a
room  with a force move), a river that makes you drift along  with
the stream (and perhaps down a waterfall), etc.
</p><p>4. Death rooms
We  do  discourage the use of rooms with certain-death. There  may
however be situations in which it is reasonable to give an  amount
of  damage  to  characters.  For this purpose  we  have  made  the
SFUN_DEATH_ROOM  ["&lt;damage number&gt;"] function. The  function  will
damage  players at every specified interval with the damage amount
specified, for example:
</p>
<pre>    special SFUN_DEATH_ROOM "100" time PULSE_SEC*10 [OBSOLETE]
</pre>
<p>will  give 10.0 damage points to players inside the room.  If  the
character  has no means of escaping he is almost certainly  doomed
(unless  he  possesses  means of teleporting).  Make  damage  rooms
reasonable,   escapable   and   avoidable.   Nothing   discourages
exploration of a zone more than a certain death damage room.
</p><p>5. Sacred rooms
Remember that it can often be a good idea to insert a sacred  room
in  your  zone,  especially in beginner areas. A  sacred  room  is
specified by the:
</p>
<pre> flags {UNIT_FL_SACRED}
</pre>
<p>6. "Buffer rooms"
In  the  case that you have two dangerous monsters in two adjacent
rooms,  it is often a good idea to insert a buffer room  to  avoid
players  fleeing from one monster into the certain  death  of  the
other monster. This of course depends completely on the situation.
A  good  example  of such a design is the tiamat zone  where  when
players  fight  one dragon the have 50% risk of fleeing  into  the
arms of another dragon.
</p></div>