<div class="mw-parser-output"><p><br />
<span id="bpgamestate"></span>
</p>
<pre><b>Function:  </b><i>  gamestate( u&#160;: unitptr, gs&#160;: integer ); </i>
Change the gamestate of a unitptr, uses the GS_ defines from the
<b>vme.h</b>. This is used on the log on menu of the VME 2.0 release. Which is
shown here as an example but it can also be used in a command.  When used it
removes the char from playing so be aware that players could use this to hide
if you run a player killing style mud.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin informer();
var
tgt&#160;: unitptr;
code
{
heartbeat&#160;:= PULSE_SEC;
</pre></i><i><pre>tgt&#160;:= ghead();
</pre></i><i><pre>while(tgt.type == UNIT_ST_PC)
{
</pre></i><i><pre> if((isset(tgt.pcflags,PC_INFORM)) and (tgt&#160;!= self))
 {
     if(visible(tgt,self))
        {
        if(self.outside == tgt.outside)
        sendtext(self.name+" has arrived.&amp;n", tgt);
     else
        sendtext(self.name+" has entered the world.&amp;n", tgt);
        }
 }
</pre></i><i><pre>tgt&#160;:= tgt.gnext;
}
</pre></i><i><pre>return;
}
dilend
</pre></i><i><pre>dilbegin aware on_connect();
external
        informer();
        login_modify(tgt&#160;: unitptr);
</pre></i><i><pre>var
  wizlvl&#160;: integer;
        i:integer;
     err&#160;: integer;
    motd&#160;: string;
 welcome&#160;: string;
 goodbye&#160;: string;
code
{
heartbeat&#160;:= PULSE_SEC;
</pre></i><i><pre>if(dilfind("do_quit@commands",self))
        i&#160;:= dildestroy("do_quit@commands", self);
</pre></i><i><pre>err&#160;:= loadstr("motd",motd);
</pre></i><i><pre>if(err &gt; 0)
{
        motd&#160;:= textformat(motd);
        sendtext(motd+"&amp;n&amp;n", self);
</pre></i><i><pre>}
</pre></i><i><pre>err&#160;:= loadstr("welcome",welcome);
if(welcome)
        welcome&#160;:= textformat(welcome);
</pre></i><i><pre>if (self.level &lt; 200)
{
</pre></i><i><pre>login_modify(self);
dilcopy ("clan_delete@clans",self);
dilcopy ("clan_clear@clans",self);
</pre></i><i><p><br />
</p></i><i><pre>if(err &gt; 0)
        sendtext("&amp;n"+welcome+"&amp;n&amp;n", self);
  informer();
  exec("look", self);
  quit;
}
gamestate(self, GS_MENU);
</pre></i><i><pre>:wiz_menu:
sendtext("Welcome to Valhalla&amp;n&amp;n", self);
sendtext("1) Enter Valhalla&amp;n", self);
sendtext("W) Change Wizinv level&amp;n [&amp;c+g"+itoa(self.minv)+"&amp;[default]]&amp;n",self);
sendtext("0) Exit Valhalla&amp;n&amp;n", self);
sendtext("Make your choice: ", self);
wait(SFB_CMD, TRUE);
</pre></i><i><pre>if (command("1") )
{
  gamestate(self, GS_PLAY);
  if(err &gt; 0)
        sendtext("&amp;n"+welcome+"&amp;n&amp;n", self);
  informer();
  exec("look", self);
  quit;
} else if (command("0") ) {
  err&#160;:= loadstr("goodbye",goodbye);
  if(err &gt; 0)
  {
  goodbye&#160;:= textformat(goodbye);
  sendtext(goodbye, self);
  }
  destroy(self);
  quit;
} else if (command("w") ) {
  sendtext("Enter new WizInv Level: ", self);
  wait(SFB_CMD, TRUE);
  wizlvl&#160;:= atoi(cmdstr);
  if (wizlvl &gt; self.level)
    wizlvl&#160;:= self.level;
  self.minv&#160;:= wizlvl;
} else {
  sendtext("Invalid Selection&amp;n&amp;n", self);
  goto wiz_menu;
}
</pre></i><i><pre>}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
Look in <b>vme.h</b> for the possible values you can send to the menu
function.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>