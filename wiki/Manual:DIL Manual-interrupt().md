<div class="mw-parser-output"><p><br />
<span id="bpinterr"></span>
</p>
<pre>integer interrupt( flags&#160;: integer, dilexp, label )
</pre>
<pre>   Set up interrupt matching message classes matching "flags",
   for example "SFB_COM" or "SFB_COM | SFB_MSG".
</pre>
<pre>   When the program is activated on either of the specified conditions
   the 'dilexp' is evaluated. If true, then execution continues at 'label',
   otherwise the next interrupt is checked (if any).
</pre>
<pre>   Interrupts are saved (restored), when 'recall' is set.
   Returns an integer which is used for clear() to clear an interrupt.
</pre>
<pre><b>Example:</b>
</pre>
<pre>The following program shows, that the owner (self) of the program keeps
snoring while sleeping. The on_activation ensures that the program
is only activated when the owner is sleeping. However, since the interrupt
precede the on_activation, these may still be intercepted before the
on_activation. The on_activation is just another type of interrupt that
reacts on all flags (without actually setting them so that the program
is activated).
</pre>
<pre>When the program receives the message "relief" the snoring stops briefly.
As used, "relief" may only be set once.
</pre>
<pre>When the program receives the message "cured", the snoring stops completely
(i.e. the program quits itself).
</pre>
<pre>

 dilbegin

 var
    i : integer;

 code
 {
   /* Notice that the sequence in which the interrupts (and the on_activation)
     are executed, is quite important: You can be cured at *any* time. The
     program will skip if you are not sleeping. If you are sleeping you can
     be relieved. */

    interrupt(SFB_MSG, argument == "cured", the_end);

    on_activation(self.position != POSITION_SLEEPING, skip);

    i1 := interrupt(SFB_MSG, argument == "relief", relief);

    :loop:
    exec("snore", self);
    pause;
    goto loop;

    :relief:
    /* Suppose you can only be relieved once, then we must clear interrupt */
    clear(i1);
    pause;
    pause;
    goto loop;

    :the_end:
    /* Person is cured... */
    quit;
 }
 dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>