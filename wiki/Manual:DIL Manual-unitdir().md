<div class="mw-parser-output"><p><br />
<span id="bfunitdir"></span>
</p>
<pre><b>Function:</b>  <i>stringlist unitdir( match&#160;: string )&#160;;</i>
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
</i></pre><i><pre>dilbegin aware reload_corpse();
var
        corpselist:stringlist;
        u:unitptr;
        ln:integer;
        i:integer;
        x:extraptr;
code
{
        corpselist:=unitdir("corpse*");
        ln:=length(corpselist);
        i:=0;
        while (i&lt;ln)
        {
        u:=restore(corpselist.[i],null);
        x:=CORPSE_EXTRA in u.extra;
        if (u!=null)
                if (x!=null)
                        link (u,findroom(x.descr));
                else
                        link (u,findroom("temple@udgaard"));
        i:=i+1;
        }
</pre></i><i><pre>quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
The previous DIL example is the DIL used in restoring corpses to the game in
case of a crash.  For more information you can see how the death DIL'S work
by reading through the file death.zon in the vme2.0/zone.
directory.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>