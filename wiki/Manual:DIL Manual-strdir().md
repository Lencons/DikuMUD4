<div class="mw-parser-output"><p><br />
<span id="bfstrdir"></span>
</p>
<pre><b>Function:</b>  <i>stringlist strdir( match&#160;: string )&#160;;</i>
</pre>
<pre>  <b>match</b>
         The wild card file you want to match or '*' for all.
  <b>return</b>
         a Stringlist with all the filenames that match the 'match' argument.
</pre>
<pre>The 'match' argument uses the same wild cards as the Linux 'ls' command
so the following will work.
</pre>
<pre>  <b>&amp;ast;</b>
         Match any character or group of characters
  <b>&amp;quest;</b>
         Match one of any character
  <b>[...]</b>
         Match one of a set of characters
</pre>
<pre><b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>"corpse*" matches:  corpse.10938 corpse.whistler corpseofwhistler ...
"corpse?" matches corpse1 corpses corpse5 ...
"[abc]*" matches ability about cost back ...
"[a-z]*" about zoo man father ...
"start[nm]end" matches startnend startmend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>Example DIL:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin wanted ();
var
        wantedlist:stringlist;
        templist:stringlist;
        i:integer;
        ln:integer;
code
{
</pre></i><i><pre>        wantedlist&#160;:= strdir ("dead*");
</pre></i><i><pre>                i&#160;:= 0;
                ln&#160;:= length (wantedlist);
</pre></i><i><pre>        while (i &lt; ln )
                {
                templist&#160;:= split (wantedlist.[i],".");
                sendtext (templist.[1]+" wanted dead!&amp;n",self);
                i:=i+1;
                }
</pre></i><i><pre>quit;
}
dilend
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
The previous DIL would be an example of a command to check the wanted dead
players on the VME if you saved the files with the first word being
'dead' and separated it with a '.' and the players name. For example if
'whistler' was wanted dead  the file name would be 'dead.whistler'
</pre></div>