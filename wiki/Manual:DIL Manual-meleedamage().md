<div class="mw-parser-output"><p><br />
<span id="bfmeleedamage"></span>
</p>
<pre><b>Function:  </b>
<i>meleedamage ( c&#160;: unitptr, v&#160;: unitptr, b&#160;: integer, wt&#160;: integer );</i>
</pre>
<pre>  <b>c</b>
         the character that should make an additional attack
  <b>v</b>
         the character being attacked
  <b>b</b>
         any penalty or bonus added to the attack.
  <b>wt</b>
         the weapon type of the attack, if a valid type then that is used for the attack purpose, otherwise the default weapon/hand attack is used.
  <b>returns</b>
         The amount of damage done or -1 for failed
</pre>
<pre>ch' performs an attack (using whatever weapon is wielded or his bare hands) against 'vict'.
If wtype is within a valid weapon range (WPN_XXX) any weapon will be bypassed,
and the value will be used as the attacktype.  Good for things like "meleeattack
(ch, vict, bonus, WPN_CIRCLE_KICK)"  If you want person to be able to perform an
extra attack even though wielding a weapon or something.  Note that this will
require BOTH a weapon type WPN_CIRCLE_KICK and a skill "kick" in order for it to
work.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin kick(arg&#160;: string);
external
   provoked_attack (victim&#160;: unitptr, ch&#160;: unitptr);
</pre></i><i><pre>var
   bonus&#160;: integer;
   targ  : unitptr;
</pre></i><i><pre>code
{
   if ((self.type == UNIT_ST_PC) and (self.weapons[WPN_KICK] &lt;= 0))
   {
      act("You must practice first.", A_ALWAYS, self, null, null, TO_CHAR);
      quit;
   }
</pre></i><i><pre>   if (arg == "")
   {
      if (self.fighting)
      {
         targ&#160;:= self.fighting;
         goto kick;
      }
</pre></i><i><pre>      act("Kick who?", A_SOMEONE, self, null, null, TO_CHAR);
      quit;
   }
</pre></i><i><pre>   targ&#160;:= findunit(self, arg, FIND_UNIT_SURRO, null);
</pre></i><i><pre>   if ((targ == null) or not visible(self, targ))
   {
      act("That person is not here!", A_SOMEONE, self, null, null, TO_CHAR);
      quit;
   }
</pre></i><i><pre>   if (not (targ.type &amp; (UNIT_ST_PC | UNIT_ST_NPC)))
   {
      act("You can't kick that, silly!", A_SOMEONE, self, null, null,
          TO_CHAR);
      quit;
   }
</pre></i><i><pre>   if (targ == self)
   {
      act("You kick yourself.", A_HIDEINV, self, null, null,
          TO_CHAR);
      act("$1n kicks $1mself.", A_HIDEINV, self, null, null,
          TO_ROOM);
      quit;
   }
</pre></i><i><pre>   if ((targ.type==UNIT_ST_PC) and
   (self.type==UNIT_ST_PC))
  {
if (not(isset (self.pcflags, PC_PK_RELAXED)))
  {
  act ("You are not allowed to do this unless you sign the book of blood.",
  A_ALWAYS,self,null,null,TO_CHAR);
  quit;
  }
</pre></i><i><pre>if (not(isset (targ.pcflags, PC_PK_RELAXED)))
  {
  act ("You are not allowed to do this unless $2e signs the book of blood.",
  A_ALWAYS,self,targ,null,TO_CHAR);
  quit;
  }
  }
</pre></i><i><p><br />
</p></i><i><pre>   :kick:
   /* Penalty for wielding a weapon while kicking! */
   if (equipment(self, WEAR_WIELD))
     bonus&#160;:= -25;
   else
     bonus&#160;:= +25;
   if (self.endurance &lt; 2)
     act("You are too exhausted to attempt that.", A_ALWAYS, self, null,
         null, TO_CHAR);
   else self.endurance&#160;:= self.endurance - 2;
   provoked_attack (targ, self);
   bonus&#160;:= meleeattack(self, targ, (bonus+self.level), WPN_KICK);
   quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre></div>