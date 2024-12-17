<div class="mw-parser-output"><p><br />
<span id="bpcast_s"></span>
</p>
<pre>cast_spell( i&#160;: integer, caster&#160;: unitptr, medium&#160;: unitptr, target&#160;: unitptr )
</pre>
<pre>   WILL EVENTUALLY BE OBSOLETE AND REPLACED BY THE CAST_SPELL BELOW.
</pre>
<pre>   i&#160;: Spell index to cast. See SPL_* in values.h and/or vme.h.
   caster&#160;: The caster of the spell.
   medium&#160;: The medium, with which the spell is cast, might be caster.
   target&#160;: The target of the spell.
</pre>
<pre>   Use this to cast spells without performing all the usual mana stuff, etc.
   Very useful with for example rings / items possessing magical abilities.
</pre>
<pre>integer cast_spell( i&#160;: integer, caster&#160;: unitptr, medium&#160;: unitptr, target&#160;: unitptr, effect&#160;: string )
   i&#160;: Spell index to cast. See SPL_* in values.h and/or vme.h.
   caster&#160;: The caster of the spell.
   medium&#160;: The medium, with which the spell is cast, might be caster.
   target&#160;: The target of the spell.
   effect&#160;: A symbolic DIL program which takes no arguments. This will
            cause all effects to be suppressed and leave this to the program
            specified. A string of "" will cause the ordinary messages to
            appear.
   returns: The result of the spell.
</pre>
<pre>   Use this to cast spells without performing all the usual mana stuff, etc.
   Very useful with for example rings / items possessing magical abilities.
   Please note that in the two programs below the variable 'hm' represents
   the number of hitpoints that will be deducted from the target.
</pre>
<pre>   <b>Example:</b>
</pre>
<pre>   %dil
</pre>
<pre>

    dilbegin myeffect(medi : unitptr, targ : unitptr, hm : integer);
    code
    {
       act("The caster is $1N medium is $2N and target is $3N",
           A_ALWAYS, self, medi, targ, TO_ALL);
       act("The spell result is $2d", A_ALWAYS, self, hm, null, TO_ALL);
       quit;
    }
    dilend
</pre>
<pre>   .....
</pre>
<pre>   %...
</pre>
<pre>

    dilbegin test();
    var
      n : integer;
    code
    {
       wait(SFB_DONE, command("beg"));

       n := cast_spell(SPL_FIREBALL_1, self, self, activator, "myeffect@wiz");

       exec("say Result of spell was "+itoa(n), self);
    }
    dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>