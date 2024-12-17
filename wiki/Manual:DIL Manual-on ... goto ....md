<div class="mw-parser-output"><p><br />
<span id="ongoto"></span>
</p>
<pre><b>on <i>n</i> goto <i>la</i>, <i>lb</i>, ..., <i>ln</i>:</b>
</pre>
<pre>    This construct is an easy way of performing a goto operation
    based on the result of an integer. The integer value 'n' must
    be zero or positive and less than the number of labels specified
    in the label-list. If n is outside this range, the on-goto operation
    is skipped and execution continues at the next instruction.
</pre>
<pre>    Based on the value of 'n' execution continues at the label
    corresponding to number 'n' in the list. I.e. if n is 0, then
    execution continues at the first specified label, if n is 1
    then at the second, etc. etc.
</pre>
<p><br />
</p>
<pre><b>Example:</b>
</pre>
<pre>  Assume you have an integer 'i' larger than zero, which takes
  on 0, 1, 2, 3, 4 or 5. Based on each value you need to take a
  different action, this is how you can do it:
</pre>
<pre>

     on i goto grin, laugh, grin, nada, poke, laugh;
     log("Value was not in the range 0..5");
     quit;

       :laugh:
       exec("grin", self);
       goto ...;

       :grin:
       exec("cackle", self);
       goto ...;

       :blank:
       exec("cry", self);
       goto ...;

       :poke:
       exec("smirk", self);
       goto ...;
 
It is often used in this context
</pre>
<pre>

     on rnd(0,4) goto l1, l2, l3, l4, l5;

     :l1:
     bla;

     :l2:
     bla;

     ....

 
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>