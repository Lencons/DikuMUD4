<div class="mw-parser-output"><p><br />
<span id="bpona"></span>
</p>
<pre>integer on_activation ( dilexp , label )
   dilexp  : A boolean DIL expression.
   label   : Label to jump to - OR the reserved keyword SKIP.
   returns&#160;: The index to the interrupt handing the on_activation.
</pre>
<pre>   result: Sets up an interrupt that is executed before every activation
           of the DIL program. This is for example useful to catch
           situations where your NPC has fallen asleep or is injured.
           If 'dilexp' evaluates to TRUE then the program jumps to 'label'.
           If 'label' is 'skip' then the program is simply not activated.
           When the on_activation evaluates to true, and jumps to a label
           other than skip, the condition is automatically cleared. If the
           dilexp evaluates to false, or if the label is skip, the activation
           remains active. Use the clear() to remove the on_activation.
</pre>
<pre>   <b>Example:</b>
           on_activation(self.position &lt;= POSITION_SLEEPING, skip);
             or
           on_activation(self.position &gt; POSITION_SLEEPING, let_me_sleep);
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>