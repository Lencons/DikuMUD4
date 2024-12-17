<div class="mw-parser-output"><p><br />
<span id="bpsetpassword"></span>
</p>
<pre><b>Function:</b>  <i>set_password( u&#160;: unitptr, s&#160;: string )&#160;;</i>
</pre>
<pre>  <b>u</b>
         the unit that you want to set the password of
  <b>s</b>
         the password you are using to set
</pre>
<pre>This function sets a unit password it only works on Players characters of corse.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin aware do_password (arg:string);
var
        prmt:string;
 firstpwd:string;
</pre></i><i><pre> i:integer;
 tlist:stringlist;
</pre></i><i><pre>code
{
</pre></i><i><pre>if(self.type&#160;!= UNIT_ST_PC) quit;
arg:="";
prmt:=self.prompt;
self.prompt:="Enter new password:  ";
wait (SFB_CMD,self==activator);
block;
tlist:=getwords (excmdstr);
if (length(tlist)&gt;1){
sendtext ("Password must be only one word.  Try again.&amp;n",self);
self.prompt:=prmt;
quit;
}
if (length(excmdstr)&lt;5){
        sendtext ("Password to short. Password must be 5 characters or longer.\
		Try again.&amp;n",self);
        self.prompt:=prmt;
        quit;
        }
</pre></i><i><pre>if (length(excmdstr)&gt;16){
        sendtext ("Password to long. Try again.&amp;n",self);
        self.prompt:=prmt;
        quit;
        }
</pre></i><i><pre>        firstpwd:=excmdstr;
        self.prompt:="Enter password again:  ";
</pre></i><i><pre>wait (SFB_CMD,self==activator);
block;
if (excmdstr!=firstpwd){
sendtext ("Passwords do not match try again.&amp;n",self);
self.prompt:=prmt;
quit;
}
set_password(self,excmdstr);
sendtext("Changed your Password to '"+excmdstr+"' Please write it down!&amp;n",self);
self.prompt:=prmt;
</pre></i><i><pre>quit;
}
dilend
</pre></i><i><p><br />
</p><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre></div>