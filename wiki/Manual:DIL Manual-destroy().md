<div class="mw-parser-output"><p><br />
<span id="bpdest"></span>
</p>
<pre><b>Function:</b>  <i>destroy ( u&#160;: unitptr );</i>
</pre>
<pre>  <b>u</b>
         :Unit to remove from game
</pre>
<pre>The destroy function works in two ways depending on the Unit being acted on.
If the Unit being acted on is a PC the player is saved and ejected from the game.
If the Unit being acted on is a NPC, or an Object. the purge function destroys
the Unit.  Currently destroy will not destroy rooms.
This is different from the old destroy function in that it removes the player
out of the game instead of leaving the player in the menu.
<b>Example</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin purge_all_pc();
var
        u:unitptr/*Unit used to purge each player*/
        n:unitptr;/*used to keep track of next player*/
code
{
u:=ghead();/*get first pc in game list*/
n:=u;
</pre></i><i><p><br />
</p></i><i><pre>while (n.type==UNIT_ST_PC)/*while unit is a pc*/
        {
        n:=u.gnext;
        destroy(u);
        }
</pre></i><i><pre>quit;/*done whiping out the players*/
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>