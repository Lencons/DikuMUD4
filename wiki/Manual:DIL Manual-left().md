<div class="mw-parser-output"><p><br />
<span id="bfleft"></span>
</p>
<pre><b>Function:</b>  <i>string left ( o&#160;: string, l&#160;: integer );</i>
</pre>
<pre>  <b>o</b>
         the original string to be parsed
  <b>l</b>
         The amount of characters to parse out
  <b>return</b>
         the left portion of the string with length l
</pre>
<pre>This function parses the string passed to it and returns the number
of characters defined in its second argument.
</pre>
<pre><b>Example:</b>  <i>"short"&#160;:= left ("shorten me",5);</i>
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin aware describe (arg:string);
var
        side:string;
        oneword:stringlist;
        location:string;
        ln:integer;
        args:stringlist;
        temp:string;
        i:integer;
        x:extraptr;
code
{
        if (self.type!=UNIT_ST_PC)
                quit;
        if (self.position &lt;POSITION_SLEEPING)
        {
        act ("Recover first and then you can describe your body parts.",
        A_ALWAYS,self,null,null,TO_CHAR);
                quit;
        }
</pre></i><i><pre>        args:=getwords(arg);
        ln:=length(args);
        if ((ln&lt;1) or (ln&gt;2))
        {
        sendtext ("No such location to describe.",self);
        quit;
        }
        else if (ln&gt;1)
        goto two_word;
</pre></i><i><pre>        :one_word:
</pre></i><i><pre>        if ((arg==left("help",length(arg))) or
                (arg==""))
                goto hlp_dscr;
</pre></i><i><pre>        oneword&#160;:= {"arms","butt","ears","eyes","face","feet",
		            "general","hair","hands","head","legs",
					"mouth","neck","nose","nostrils","teeth",
					"toes","tongue"};
</pre></i><i><pre>        i&#160;:= 0;
        ln&#160;:= length(args.[0]);
        temp:="ERROR";
        while (i&lt;18)
        {
                if (args.[0]==left(oneword.[i],ln))
                {
                        temp&#160;:= oneword.[i];
                        break;
                }
                i&#160;:= i+1;
        }
</pre></i><i><pre>        if (temp=="ERROR")
        {
                sendtext ("No such location to describe.",self);
                quit;
        }
</pre></i><i><pre>        goto describe;
</pre></i><i><pre>        :two_word:
</pre></i><i><pre>        oneword&#160;:= {"arm","leg","foot","hand","eye","ear"};
        temp&#160;:= "ERROR";
        ln&#160;:= length(args.[0]);
        if (args.[0] == left("left",ln))
                side:="left";
        else if (args.[0] == left("right",ln))
                side:="right";
        else
        {
                sendtext ("No such location to describe.",self);
                quit;
        }
</pre></i><i><pre>        i&#160;:= 0;
        while (i&lt;6)
        {
                if (args.[1]==left(oneword.[i],ln))
                {
                        temp&#160;:= oneword.[i];
                        break;
                }
                i&#160;:= i+1;
        }
</pre></i><i><pre>        if (temp=="ERROR")
        {
                sendtext ("No such location to describe.",self);
                quit;
        }
</pre></i><i><pre>        temp&#160;:= side+" "+temp;
</pre></i><i><pre>        :describe:
        if (temp=="General")
                location&#160;:= "";
        else
                location&#160;:= temp;
</pre></i><i><pre>        x&#160;:= location in self.extra;
        if (x!=null)
          if (location=="")
sendtext("your Current description for your body is:  &amp;n"+x.descr+"&amp;n",self);
        else
sendtext("your Current description for your "+location+"is:  &amp;n"+x.descr+"&amp;n",self);
        if (location=="")
sendtext ("Enter a text you would like others to see when they look at your body.&amp;n",self);
        else
sendtext ("Enter a text you would like others to see when they look at your "+location+".&amp;n",self);
</pre></i><i><pre>        beginedit (self);
        wait(SFB_EDIT,self==activator)&#160;;
        temp&#160;:= textformat(argument);
        oneword:={""};
        subextra(self.extra,location);
        addstring (oneword, location);
        addextra (self.extra,oneword,temp);
        sendtext ("Description added.&amp;n",self);
        quit;
</pre></i><i><pre>        :hlp_dscr:
</pre></i><i><pre>        sendtext ("&amp;nCorrect usage of 'describe':&amp;n&amp;n",self);
        sendtext ("describe &lt;position&gt;&amp;n&amp;n",self);
        sendtext("&lt;position&gt; being one of the following:&amp;n&amp;n",self);
        sendtext( "arms        butt        ears        eyes&amp;n"+
                  "face        feet        General     hair&amp;n"+
                  "hands       head        left arm    left leg&amp;n"+
                  "left foot   left hand   left eye    left ear&amp;n"+
                  "legs        mouth       neck        nose&amp;n"+
                  "nostrils    right arm   right leg   right foot&amp;n"+
                  "right hand  right eye   right ear   teeth&amp;n"+
                  "toes        tongue&amp;n&amp;n",self);
        sendtext ("Example:  &amp;n&amp;n",self);
        sendtext ("describe left leg&amp;n",self);
        quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>