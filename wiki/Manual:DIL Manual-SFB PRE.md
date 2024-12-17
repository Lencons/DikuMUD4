<div class="mw-parser-output"><h1><span class="mw-headline" id="SFB_PRE">SFB_PRE</span></h1>
<p>Command preprocessing
</p><p>When this flag is set, the program is activated by a few special events
which can then be blocked or changed. Currently, this event is triggered
just prior to a spell being cast, and just prior to any sort of damage
being given to a target.
</p><p>Examples:
</p>
<pre>  wait(SFB_PRE, command(CMD_AUTO_DAMAGE));
  wait(SFB_PRE, command("cast"));
</pre>
<p>Assume a a spell is cast from player A on player B with a scroll C.
</p>
<pre>     'activator'... is a unitptr to A.
     'medium'   ... is a unitptr to C.
     'target'   ... is a unitptr to B.
</pre>
<pre>     command("cast") will evaluate to TRUE.
</pre>
<pre>     'argument'.... will contain a number followed by any
                    argument to the spell itself. You should
                    parse this number, it equals the spell number SPL_XXX.
     'power' ....   is set to 'HM', i.e. how powerful the spell cast
                    is going to be. YOu can change this number at will.
                    If you decide to block the spell, you ought to set it
                    to -1.
</pre>
<pre>Example:
   wait(SFB_PRE, command("cast"));
</pre>
<pre>   s&#160;:= getword(argument);
   splno&#160;:= atoi(s);
</pre>
<pre>   if (splno == SPL_FIREBALL_3)
     power&#160;:= 0; /* No damage */
   ...
</pre>
<p><br />
</p>
<pre>  SFB_PRE "command(CMD_AUTO_DAMAGE)"
</pre>
<pre>  Assume that damage is given from player A to player B with a sword C.
</pre>
<pre>     'activator'... is a unitptr to A.
     'medium'   ... is a unitptr to C.
     'target'   ... is a unitptr to B.
</pre>
<pre>     command(CMD_AUTO_DAMAGE) will evaluate to TRUE.
</pre>
<pre>     'power' ....   is set to how much damage will be given. You can change
                    this number at will, but you should not set it to less
                    than zero.
</pre>
<pre>     'argument'.... will contain three numbers that you must parse to
                    determine what kind of damage we're talking about.
</pre>
<pre>                    First number is the attack group, this can be one of
                    MSG_TYPE_XXX from values.h and/or vme.h.
</pre>
<pre>                    Second number is dependant on the attack group and
                    identifies what damage compared to the group. For
                    example WPN_XXX for weapon group.
</pre>
<pre>                    Third number is the body hit location, one of WEAR_XXX,
                    (but not all of them, just hands, feet, legs, body, head,
                     arms, i.e. the armour positions, not positions like finger
                     or ear).
</pre>
<p><br />
</p>
<pre>Example:
   wait(SFB_PRE, command(CMD_AUTO_DAMAGE));
</pre>
<pre>   s1&#160;:= getword(argument);
   grpno&#160;:= atoi(s1);
</pre>
<pre>   s2&#160;:= getword(argument);
   atkno&#160;:= atoi(s2);
</pre>
<pre>   s3&#160;:= getword(argument);
   hitloc&#160;:= atoi(s3);
</pre>
<pre>   if (grpno == MSG_TYPE_SPELL)
   {
      if ((s2 == SPL_FINGER_DEATH))
      {
          act("Your scarabaeus lights up as it protects your life force.");
          power&#160;:= -1;
          block;
      }
   }
   ...
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<pre><b><i>A note upon activating a DIL program</i></b>
</pre>
<pre>This is what you can't do:
</pre>
<pre>  If a DIL program is already active, e.g. it is sending a message or
  perhaps using "exec" to perform an action, then it can not be activated.
  Thus, any active DIL program is unable to catch further messages.
  Imagine this setting:
</pre>
<pre>  You have five program P1..P5. P1 sends a message, which is intercepted
  by P2. P2 now sends a message, but since P1 is busy it can not process
  the message. P3..P5 are however possible candidates.
  Assume P3 sends a message, and P4 acts upon it. P4 now sends a message
  and the ONLY program which can catch it is P5, since all the other programs
  are "busy". If P5 sends a message no-one can act upon it. When P5
  returns, so does P4, P3, P2 and finally P1.
</pre></div>