<div class="mw-parser-output"><h1><span class="mw-headline" id="Climbing">Climbing</span></h1>
<p>This section describes how to implement the climbing skill in a room.
</p><p>Firstly, if you want a direction to be climbable, set the EX_CLIMB flag on the exist in question.
</p>
<pre> down open {EX_CLIMB} difficulty 0 to sew_ent@udsewer;
</pre>
<p>Also note that you can specify how difficult a skill check is needed for the climb. 
</p><p>You can also define which way you fall if you fail your climb. You do this by adding the EX_FALL_THIS_WAY:
</p>
<pre> down open {EX_CLIMB, EX_FALL_THIS_WAY} difficulty 0 to sew_ent@udsewer;
</pre>
<p>This means that if you try to climb down and fail your skill check, then you will fall down. You could of course also have a room like this:
</p>
<pre> east open {EX_CLIMB} difficulty 10 to rope-east;
 west open {EX_CLIMB} difficulty 10 to rope-west;
 down open {EX_CLIMB, EX_FALL_THIS_WAY} difficulty 0 to thepit;
</pre>
<p>Which means if you fail climbing east or west, then you'll "fall this way" which is down.
</p><p>When you fall it keeps checking if there are more fall_this_way bits. So you can keep falling through many rooms.
</p><p>The amount of damage you get is a function of how badly you miss your climb skill combined with the damage for climbing which defaults to 10.
You can adjust the damage offset like this:
</p>
<pre> extra {"$climb_down"} {1} "" // Do only 1 damage, adjusted for skill failure
</pre>
<p>Only needed if you need to define a damage different from the default of 10.
</p></div>