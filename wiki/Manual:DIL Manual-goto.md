<div class="mw-parser-output"><p><br />
<span id="dcgoto"></span>
</p>
<pre><b>goto:</b>
    The goto statement lets you jump about in the code.
    Labels in your DIL programs, for 'goto' or interrupts
    are defined within ':'. For an example, see the program below.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

 dilbegin foo();
   code
   {
     :mylabel:
     exec("say Hello world",self);
     pause;
     goto mylabel;
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>