<div class="mw-parser-output"><p><br />
<span id="dcwhile"></span>
</p>
<pre><b>while:</b>
    The while statement lets you execute a series of
    statements while an expression evaluates to TRUE.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

 dilbegin foo();
   code
   {
     while (not self.inside) {
       exec("say I own nothing", self);
       pause;
     }
     exec("say ahh.. now i own something", self);
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>