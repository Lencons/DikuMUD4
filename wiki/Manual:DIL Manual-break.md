<div class="mw-parser-output"><p><br />
<span id="dcbreak"></span>
</p>
<pre><b>break:</b>
    The break statement makes you break out of any
    loop you're currently in.
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
       exec("say I own something", self);
       pause;
     }
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>