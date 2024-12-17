<div class="mw-parser-output"><p><br />
<span id="bpdp"></span>
</p>
<pre><b>Function:</b>  <i>delete_player( s&#160;: string )&#160;;</i>
</pre>
<pre>  <b>s</b>
         the player name you want to delete
</pre>
<pre>This function deletes a player but it doesn't check to see if it
was deleted or if it even existed you will have to do that with 'isplayer'.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin aware do_delete (arg:string);
var
        temp:string;
        err:integer;
code
{
</pre></i><i><pre>if(self.type&#160;!= UNIT_ST_PC) quit;
</pre></i><i><pre>if (self.level&gt;200)
        goto admin_delete;
</pre></i><i><pre>:char_delete:
        if (arg!="self forever")
                {
                sendtext ("To delete your char type:  'delete self forever'&amp;n",self);
                quit;
                }
</pre></i><i><pre>err:=loadstr("delete.txt",temp);
</pre></i><i><pre>if (err&lt;1)
        goto no_insure;
</pre></i><i><pre>sendtext (temp,self);
</pre></i><i><pre>sendtext ("If your sure you still want to delete your character, 'say delete me'&amp;n",self);
sendtext ("Doing anything else will abort the deletion.&amp;n",self);
</pre></i><i><pre>wait (SFB_CMD, self==activator);
if (command ("say"))
</pre></i><i><pre>        if (argument=="delete me")
        if (self.extra.[CLAN_RANK]!=null)
                exec ("cdefect",self);
                delete_player(self.name);
</pre></i><i><pre>sendtext("Deletion aborted&amp;n",self);
</pre></i><i><pre>quit;
</pre></i><i><pre>        :no_insure:
                if (self.extra.[CLAN_RANK]!=null)
                exec ("cdefect",self);
                        delete_player(self.name);
</pre></i><i><pre>quit;
        :admin_delete:
        if (arg=="self forever")
                goto char_delete;
if (arg==""){
sendtext("You must supply a characters name to delete one.&amp;n",self);
quit;
}
</pre></i><i><pre>if (arg==self.name){
sendtext ("To delete self you need to type 'delete self forever'&amp;n",self);
quit;
}
</pre></i><i><pre>if (not isplayer(arg))
        {
        sendtext (arg+" is not a character.&amp;n",self);
        quit;
        }
dilcopy ("god_delete@clans("+arg+")",self);
</pre></i><i><pre>        sendtext (arg+" has been deleted.&amp;n",self);
quit;
}
dilend
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>