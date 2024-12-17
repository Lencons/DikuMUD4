<div class="mw-parser-output"><h1><span id="senddone()"></span><span class="mw-headline" id="senddone.28.29">senddone()</span></h1>
<p><b>Function:</b>
</p>
<pre>send_done( c&#160;: string, a :unitptr, m&#160;: unitptr, t :unitptr, p&#160;: integer, arg&#160;: string, o&#160;: unitptr, i&#160;: integer);
</pre>
<pre>  <b>c</b>
         the command string that is sending the message
  <b>a</b>
         the unitptr (activator) that activated the message
  <b>m</b>
         the unitptr (medium) that the Dil is acting through
  <b>t</b>
         the unitptr (target) the Dil is acting on
  <b>p</b>
         the power of the message
  <b>arg</b>
         the argument sent with the message
  <b>o</b>
         the unitptr (other) you also want the message to go to
  <b>i</b>
         CMD_AUTO_XXX to send a CMD_AUTO or 0
</pre>
<p><br />
This sends the 'SFB_DONE' message to any dils that are waiting for it in the
surrounding area and to the other pointer if not null.  The following is just
one example you can find many more in <b>commands.zon</b>
</p><p><b>Built-in variables</b>:
</p>
<pre> activator&#160;: unitptr
 medium    : unitptr
 target    : unitptr
 argument  : string
 power     : integer
</pre>
<pre><b>Example:</b>
</pre>
<pre>dilbegin do_read (arg:string);
var
brdname:string;
        i:integer;
        u:unitptr;
        x:extraptr;
        ln:integer;
        temp:string;
        templist:stringlist;
        buff:string;
        f_name:string;
        act_str:string;
code
{
  i:=atoi (arg);
 if (i&lt;0)
        {
        exec ("look "+arg,self);
        goto read_quit;
        }

if (itoa (i)!=arg)
        {
        exec ("look "+arg,self);
        goto read_quit;
        }

u:=self.outside.inside;
while (u!=null)
        {
        if ((u.type==UNIT_ST_OBJ) and (u.objecttype==ITEM_BOARD))
                break;
        u:=u.next;
        }

if (u==null)
        {
        act ("You do not see that here.",A_ALWAYS,self,null,null,TO_CHAR);
        quit;
        }

                if (u.extra.["$BOARD_L_RES"].descr!="")
                {
                act_str:=u.extra.["$BOARD_L_RES"].descr(self,u);
                if (act_str!="")
                {
        act(act_str,
                        A_ALWAYS,self,null,null,TO_CHAR);
                quit;
                }
                }
</pre>
<pre>brdname:=u.names.[length (u.names)-1];
i:=loadstr (brdname+".idx",temp);
if (i&lt;=0)
        {
        act ("But the board is empty!",
                A_ALWAYS,self,null,null,TO_CHAR);
        goto read_quit;
        }
</pre>
<pre>templist:=split(temp,"&amp;x");
ln:=length (templist);
x:="$BOARD_MAX" in self.extra;
if ((atoi(arg)&gt;atoi(x.descr)) or
(atoi(arg)&gt;ln))
        {
        act("That message exists only within the boundaries of your mind.",
                A_ALWAYS,self,null,null,TO_CHAR);
        goto read_quit;
        }
</pre>
<pre>i:=atoi(arg);
temp:=templist.[i-1];
f_name:=getword(temp);
i:=loadstr (brdname+"."+f_name,buff);
if (i==0)
        {
        sendtext("You have to let the poster finish the post before reading it.",self);
        quit;
        }
if (i&lt;1)
        {
        log("05: Error when loading board info.");
        act ("This board is not working report to an Administrator",
                A_ALWAYS,self,null,null,TO_CHAR);
                quit;
                }
</pre>
<pre>templist:=split(f_name,".");
if (length(templist)&lt;2)
        act ("Message "+arg+":  "+temp,
                A_ALWAYS,self,null,null,TO_CHAR);
else
        act ("Message "+arg+":  Re:  "+temp,
                A_ALWAYS,self,null,null,TO_CHAR);
</pre>
<pre>pagestring(buff,self);
</pre>
<pre>:read_quit:
 send_done("read",self,null,u,0,arg,null,0);
quit;
}
dilend
</pre></div>