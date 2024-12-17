<div class="mw-parser-output"><p><br />
<span id="bfisplayer"></span>
</p>
<pre><b>Function:</b>  <i>integer isplayer( pcname&#160;: string )&#160;;</i>
</pre>
<pre>  <b>pcname</b>
         the name of the player being checked
  <b>Return</b>
         Returns an integer TRUE if pcname is a player FALSE if not
</pre>
<pre>This function is used to find out if a string you pass to it is a player or not.
This can be used and is used to find out if a player is truly a player that an
Administrator is deleting with out having that player on line.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>if (not isplayer(arg))
        {
        sendtext (arg+" is not a character.&amp;n",self);
        quit;
        }
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>