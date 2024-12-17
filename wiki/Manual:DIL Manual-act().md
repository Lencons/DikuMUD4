<div class="mw-parser-output"><h1><span id="act()"></span><span class="mw-headline" id="act.28.29">act()</span></h1>
<p>The purpose of act is to send a message to a number of players <b>present</b> in a room.  The room is defined as the room containing the aforementioned character (provided he himself is in the room, i.e. not in a closed container.)
</p>
<h2><span class="mw-headline" id="Syntax:">Syntax:</span></h2>
<pre> act(message, visibility, char, medium, victim, to_whom);
</pre>
<h2><span class="mw-headline" id="Parameters:">Parameters:</span></h2>
<p><b>message:</b> is a string that will be shown to other mobiles when the act is executed. To refer to the following arguments use the <a href="#formatters">formatters</a> listed below.
</p><p><b>visibility:</b> is an integer that defines what happens if the mobile that is about to receive the message can't see the activator.
</p>
<ul><li>A_SOMEONE</li></ul>
<p>If the receiver cannot see char, replace any reference to char with <i>someone</i>.
</p>
<ul><li>A_HIDEINV</li></ul>
<p>If the receiver cannot see char, don't send the message at all. Use this when missing vision should eliminate the perception of the action the message represent. One instance where it is used is in smile. You would need a ridiculously sensitive ear to hear, let alone percept that someone's smiling if you can't see them. Do not use it if 'sound' is inherent in the message.
</p>
<ul><li>A_ALWAYS</li></ul>
<p>Works exactly like A_SOMEONE, except that the receiver will see the message even when sleeping.
</p><p><b>char:</b> is a unitptr, and the most important argument in the act. If this is not valid the act will never show, leaving mobiles without the message.
</p><p><b>medium:</b> is a unit pointer, an integer or a string. Use this at your leisure.
</p><p><b>victim</b> is a unit pointer, an integer or a string. Certain flags in the next argument rely on the validity of victim.
</p><p><b>to_whom</b> is an integer that defines who gets the message.
</p>
<ul><li>TO_ROOM</li></ul>
<p>Sends the message to the entire room, excluding 'char'.
</p>
<ul><li>TO_VICT</li></ul>
<pre>                Sends to 'victim' only. 'victim' must be valid, naturally.
         <b>TO_NOTVICT</b>
                Sends the message to the entire room, excluding 'char' and 'victim'.  Perfect for bystanders in a melee.
         <b>TO_CHAR</b>
                Sends the message to 'char' and no one else.
         <b>TO_ALL</b>
                Sends the message to everybody in the room.
         <b>TO_REST</b>
                This is a bit different from the rest.  In sends the message to all other units in the local environment, excluding those inside 'char'.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<pre><span id="formatters"></span>
<b>Act Formatters</b>
</pre>
<pre>Just as the description formatters, act has its own set of formatters that
enable you to create generic messages that will be interpreted at run-time,
lessening the load on you.
</pre>
<pre>The format string is a normal message, containing some special characters:
</pre>
<pre> '$$'
         will be sent to the receiver as a single `$'
</pre>
<pre>'$', followed by a number and an extra character.
  <b>The numbers:</b>
</pre>
<pre> '1'
          means this formatter refers to the 'char' argument.
 '2'
         means this formatter refers to the 'medium' argument.
 '3'
          means this formatter refers to the 'victim' argument.
</pre>
<pre>   <b>The characters</b>
</pre>
<pre> 'N'
          the formatter will be replaced with the name of the unit, or (depending on the visibility) 'something' or 'someone'.
 'a'
         'a' or 'an' depending on the name of the unit referred by the number.
 'e'
         'it', 'he' or 'she' depending on the gender of the unit referred by the number.
 'm'
         'it', 'him' or 'her' depending on the gender of the unit referred by the number.
 'n'
          the formatter will be replaced with the title of the unit, or (depending on the visibility) 'something' or 'someone'.
 'p'
         'fighting', 'standing', 'sleeping', etc., depending on the positionof the unit referred by the number.
 's'
         'its', 'his' or 'her' depending on the gender of the unit referred by the number.
 't'
         the string in the argument referred by the number.
</pre>
<p><br />
</p>
<pre><b>Example:</b>
</pre>
<pre>

   act("You step over $2n.", A_SOMEONE, self, litter, null, TO_CHAR);
   act("$1n steps over $2n.", A_SOMEONE, self, litter, null, TO_REST);
</pre>
<p><br />
</p>
<pre><b>See Also:</b>
  <a href="#act.html">DIL Act() for Dummies</a>
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>