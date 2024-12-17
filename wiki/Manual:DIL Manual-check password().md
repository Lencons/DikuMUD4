<div class="mw-parser-output"><p><br />
<span id="bfcheckpassword"></span>
</p>
<pre><b>Function:</b>  <i>integer check_password( u&#160;: unitptr, s&#160;: string )&#160;;</i>
</pre>
<pre>  <b>u</b>
         the unit that you want to check the password of
  <b>s</b>
         the password you are using to check
  <b>Return</b>
         Returns an integer TRUE if pcname is the units password FALSE if not
</pre>
<pre>This function checks the string against the units password and returns TRUE
if they match.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>if (not check_password(pc,arg))
        {
        sendtext (arg+" is not "+pc.name"'s password.",self);
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