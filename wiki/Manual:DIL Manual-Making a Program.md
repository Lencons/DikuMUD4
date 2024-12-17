<div class="mw-parser-output"><p><br />
<span id="making"></span>
</p>
 <h3><span class="mw-headline" id="Making_a_program:">Making a program:</span></h3>
<pre>  You define your DIL programs within your zone file. Each program you make is a
*template*. Such a template must be equipped with a unique name (for that zone).
Templates can either be defined in a new %dil section, just below the %zone
section in the zone file, or directly attached to units defined in your zonefile.
</pre>
<pre>  If you define your DIL templates inside a unit definition, that unit is
automatically assigned a program using that template. If you want to use an
already designed template, either in your own, or another zone, you use a
special function named "dilcopy", that takes the name of a template, and any
optional parameters in parenthesis. The parameters of a template called with
'dilcopy' may only be of types integer, strings and stringlists.
</pre>
<pre><b>Example:</b>
</pre>
<pre>dilcopy myfunc@myzone("say Hello, my friend!", 1, CMD_SAY, {"name1", "name2"});
</pre>
<pre>  DIL templates can always be reused. In fact, with version 2.0 of DIL, programs
are no longer saved with equipment, but only a symbolic reference is used. That
way, if you make a change in your zone, ALL units using that program are changed.
This however requires you keep the name. Upon loading, if a template is not
found, the program is halted and rendered useless until such a reference can be
found during loading.
</pre>
<pre>Technical note:
</pre>
<pre>  When you use several 'dilcopy' in your zonefile, only one instance is present
game-time, thus saving tremendous amounts of memory.  It is similar to a shared
library, in which code is shared  but variables are not.
</pre>
<pre>You may use your templates to define both procedure and functions for your other
templates to call.
</pre>
<pre>A template is defined by beginning with 'dilbegin' and ending with 'dilend'.
Inside the template your program section is defined, marked by the keyword 'code',
followed by the program itself;
</pre>
<pre>

 dilbegin myprogram();
 var
   i : integer;
   j : integer;

 code
 {
   heartbeat:=PULSE_SEC*5;
   :start:
   exec("say Hello world", self);
   pause;
   goto start;
 }
 dilend
</pre>
<pre>  This simple template does nothing but making its owner say 'Hello world' once
every 5 seconds. The template is called 'myprogram' and takes no arguments. The
'pause' command waits for the program to receive a timer message, whose interval
is set by the 'inline' variable 'heartbeat'. The 'self' variable is a unitptr
referring to the unit owning the DIL program. Other inline variables will be
explained later.
</pre>
<pre>  For a DIL program to work, it must be part of a *unit*: a room, player, non-player
or object. The program uses *messages* to operate.  Your program gets activated
when it receives a message that some command is being executed, or a certain amount
of time has passed. You decide yourself in the program, what to wait for, before
the program continues executing.
</pre>
<pre>  Supposing you want your program to contain variables, you have to put them in a
section before the 'code' section marked 'var'. The variables are declared by
their type and their name, separated by a ':' and ended by a ';'
</pre>
<pre>  For an example, see the program above. Variables of type 'string', 'stringlist'
and 'integer' are saved, if the unit the program is attached to is saved with
player inventory. Variables of type 'unitpr' and 'extraptr' are 'volatile'. This
means that they are cleared whenever there is a chance that their contents may
have been rendered non usable.  This ensures that you do not have any 'loose'
pointers. However it is possible to 'secure' the contents of a 'unitptr' type
variable of a unit located in your local environment (the units directly 'visible'
to the unit who owns the DIL program) (see the secure / unsecure functions).
</pre></div>