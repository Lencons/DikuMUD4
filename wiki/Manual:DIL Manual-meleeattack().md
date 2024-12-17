<div class="mw-parser-output"><p><br />
<span id="bfmelee"></span>
</p>
<pre>integer meleeattack ( ch&#160;: unitptr, vict&#160;: unitptr,
                     bonus&#160;: integer, wtype&#160;: integer )
   ch    : The character which should make an additional attack.
   vict  : The victim of the attack.
   bonus&#160;: Any penalty or bonus added to the attack.
   wtype&#160;: The weapon type of the attack, if a valid type then that is
           used for the attack purpose, otherwise the default weapon/hand
           attack is used.
</pre>
<pre>   result: 'ch' performs a melee attack (using whatever weapon is wielded
           or his bare hands) against 'vict'. Returns the amount of damage
           given (-1 is failed).
</pre>
<pre>   If wtype is within a valid weapon range (WPN_XXX) any weapon will
   be bypassed, and the value will be used as the attacktype. Good
   for things like "meleeattack(ch, vict, bonus, WPN_CIRCLE_KICK)"
   if you want person to be able to perform an extra attack even
   though wielding a weapon or something. Note that this will require
   BOTH a weapon type WPN_CIRCLE_KICK and a skill "kick" in order for
   it to work.
</pre></div>