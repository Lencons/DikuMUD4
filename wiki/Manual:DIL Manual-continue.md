<div class="mw-parser-output"><p><br />
<span id="dccont"></span>
</p>
<pre><b>continue:</b>
    The continue statement makes you jump to the top
    of any loop you're currently in.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     while (self.inside) {
       if (self.position &amp;lt POSITION_SLEEPING)
         break;
       pause;
       if (self.hp&lt;0) continue;
       exec("say I own something", self);
       pause;
     }
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>