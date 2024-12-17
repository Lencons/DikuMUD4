<div class="mw-parser-output"><p><br />
<span id="zptr"></span>
</p>
<pre><b>Type:  </b><i>zoneptr</i>
<b>Zone Pointer Fields</b>
</pre>
<p><br />
</p>
<pre>  <b>next</b>
         unitptr - pointer to next zoneptr
  <b>previous</b>
         unitptr - pointer to previous zone
  <b>creators</b>
         stringlist - list of creators
  <b>name</b>
         string - zone name (%zone)
  <b>title</b>
         string - zone title (title "")
  <b>rooms</b>
         unitptr - pointer to the base room
  <b>objs</b>
         unitptr - pointer to the base objects of the zone
  <b>npcs</b>
         unitptr - pointer to base NPCs of the zone
  <b>resetmode</b>
         integer- reset mode of zone in 'values.h'
  <b>resettime</b>
         integer - the reset time of the zone
  <b>access</b>
         integer - the access level of the zone
  <b>loadlevel</b>
         integer - the loadlevel of the zone
  <b>payonly</b>
         integer - the paystatus of the zone
  <b>roomcount</b>
         integer - the number of rooms in a zone
  <b>objcount</b>
         integer - the numbner of objects in a zone
  <b>npccount</b>
         integer - the number of npcs/mobiles in a zone
  <b>fname</b>
         string - the filename of a zone
  <b>notes</b>
         string - the Zone Notes
  <b>help</b>
         string - the Zone Help
</pre>
<p><br />
</p>
<pre>  The 'zoneptr' works like a unitptr.  To get the first zoneptr in the global
list of zones you use 'zhead'.
<b>Example: </b><i>zoneptr&#160;:= zhead();</i>
<b>Zone list command</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin zonelist (arg:string);
var
 z:zoneptr;
 buf:string;
code
{
          z:=zhead();
          while (z)
          {
          buf:="Name:  "+z.name+"&amp;n";
          buf:=buf+"Filename:  "+z.fname+"&amp;n";
          buf:=buf+"Creator:  "+z.creators.[0]+"&amp;n";
          buf:=buf+"Notes:  &amp;n"+z.notes+"&amp;n&amp;n";
          z:=z.next;
          }
</pre></i><i><pre>          pagestring (buf,self);
          quit;
}
dilend
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre></div>