<div class="mw-parser-output"><p><br />
<span id="bfrestore"></span>
</p>
<pre><b>Function:</b>  <i>unitptr restore( filename&#160;: string , u&#160;: unitptr );</i>
</pre>
<pre>  <b>filename</b>
         The name of the Unit file
  <b>u</b>
         The Unit you want to restore into or null if none
  <b>Return</b>
         if 'u' null returns a pointer to the Unit loaded, if 'u' not null returns null and loads Units from the specified file into the unit 'u'
</pre>
<pre>restore loads a copy of a unit or units which were previously saved with the
'store' command. Just as with "load", the unit is put inside the unit which
executes the restore command unless the 'u' argument is not null.  If the 'u'
argument is an unitptr like room, object, npc, or pc the items restored will be
placed inside the 'u' Unit..
<b>Note</b>, It is only possible to restore items as long as the main-database
contains a reference for the unit 'name@zone'.  Use 'Store' and 'Restore'
sparingly, remember that items saved in player's inventories are automatically
saved in this instance.
The 'store' and 'restore' are perfect for operations such as mud mailing
objects from player to player, storage devices for players that will keep
inventory through a reboot.  Even the ability to save a players inventory while
they fight in an arena and restore it to them undamaged when finished.  Finally
it could be used to save a donation room through reboots since it can be used on
a room to store the contents of a room any NPC or objects in the room would be
saved through reboot.
<b>Disk access is always slow</b>.
If you use 'Restore' on a continuous basis always attempt to keep file sizes to
a minimum for quick loading.  Otherwise you might cause serious delays on the
server.  If the Dil that uses Restore saves at certain times try to make it so
the saves are spread out over as large amounts of time as possible.
</pre>
<pre><b>Example 1:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin chest_load ();
var
        waist:unitptr;/*to hold the null returned in this example*/
        chest:unitptr;/*pointer to the storage chest*/
code
{
chest:=load ("chest@myzone");/*get the container*/
if (chest==null)
        {
        log ("Error");/*log an error*/
        quit;
        }
</pre></i><i><pre>waist:=restore("chest."+self.zoneidx,chest);
/*
restore given filename into chest
waist can be ignored in this dil since it is not used.
*/
link (chest, self);/*link chest into room*/
quit;/*dil load routine done destroy self.*/
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>Example 2:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin chest_load ();
var
        chest:unitptr;/*item to be loaded*/
code
{
chest:=restore("chest."+self.zoneidx,null);/*restore into chest*/
if (chest== null)/*see if something was restored*/
        chest:=load("donate_chest@"+self.zoneidx);
        /*load a new one if there is nothing restored*/
</pre></i><i><pre>link (chest, self);/*link item into room*/
quit;/*destroy the load dil.*/
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>Note:</b>  Example 1 is to be used if 'storall' was used not storing a container.
Example 2 is for items stored with 'store' with the container saved as
well.
<b>See Also</b>
<a href="#bpstore">Store a Unit to a Unit file</a> and
<a href="#bfdelunit">Delete a Unit file</a>.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>