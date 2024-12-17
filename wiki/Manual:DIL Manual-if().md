<div class="mw-parser-output"><p><br />
<span id="dcif"></span>
</p>
<pre><b>if:</b>
    The if statement is much like C. It takes any type as
    argument. Non integers are considered 'TRUE' if they are
    not null.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     if (self.hp&gt;10)
     {
       exec("say Hehe!",self);
     }
     else
     {
       exec("say ouch!", self);
     }
   }
   dilend
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     if (self.loaded&gt;10)
     {
       exec("say its getting crowded!",self);
     }
   }
   dilend
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     if (self.loaded&lt;10)
       exec("say plenty of room!",self);
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>