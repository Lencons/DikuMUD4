<div class="mw-parser-output"><p><br />
<span id="bpstore"></span>
</p>
<pre><b>Function:</b>  <i>store( u&#160;: unitptr , filename&#160;: string , container&#160;: integer );</i>
</pre>
<pre>  <b>u</b>
         The Unit that has the contents to be stored or is to be stored
  <b>filename</b>
         The name of the file you want to store the Units to
  <b>container</b>
         Do you want to save the container 'TRUE' for yes, 'False' for no
</pre>
<p><br />
</p>
<pre>Store saves a copy of a unit or units.  If the container value is 'TRUE'
everything inside  including the container itself will be saved. If the container
argument is 'FALSE' only the contents of the object will be saved.  You will want
to use the 'TRUE' value when saving something like a Clan chest that has items
inside to store and has extras on the chest that you also wish to keep.  The
'FALSE' value for container would be good for temporary storage of PC inventory
or for storing room contents.
</pre>
<p><br />
</p>
<pre>The 'store' and 'restore' are perfect for operations such as
mud mailing objects from player to player, storage devices for players that will
keep inventory through a reboot.  Even the ability to save a players inventory
while they fight in an arena and restore it to them undamaged when finished.
Finally it could be used to save a donation room through reboots since it can be
used on a room to store the contents of a room any NPC or objects in the room
would be saved through reboot.
</pre>
<p><br />
</p>
<pre><b>Disk access is always slow</b>.
If you use store on a continues basis, it is essential that you do so ONLY if it
is needed and even then, only at amply spaced intervals.  Otherwise you might
cause serious delays on the server.  Remember that items saved in player's
inventories are automatically saved in their instance.
<b>Example 1:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin save_contents ();
code
{
</pre></i><i><pre>:start:
wait (SFB_CMD,command ("store")); wait for the store command*/
block;
store("chest."+self.zoneidx,self,FALSE);/*store everything inside self.*/
goto start;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>Example 2:</b>
<i>
</i></pre><i><p><br />
</p></i><i><pre>dilbegin save_container_n_contents ();
code
{
</pre></i><i><pre>:start:
wait (SFB_CMD,command ("store")); wait for the store command*/
block;
store("chest."+self.zoneidx,self,TRUE);/*store everything inside self and self.*/
goto start;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also</b>
<a href="#bfrestore">Store a Unit to a Unit file</a> and
<a href="#bfdelunit">Delete a Unit file</a>.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>