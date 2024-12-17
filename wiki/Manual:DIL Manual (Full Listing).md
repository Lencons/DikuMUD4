<div class="mw-parser-output"><p><br />
<span id="making"></span>
</p>
 <div id="toc" class="toc"><input type="checkbox" role="button" id="toctogglecheckbox" class="toctogglecheckbox" style="display:none" /><div class="toctitle" lang="en" dir="ltr"><h2>Contents</h2><span class="toctogglespan"><label class="toctogglelabel" for="toctogglecheckbox"></label></span></div>
<ul>
<li class="toclevel-1"><a href="#Making-a-program"><span class="tocnumber">1</span> <span class="toctext">Making a program:</span></a></li>
<li class="toclevel-1"><a href="#Data-Types"><span class="tocnumber">2</span> <span class="toctext">Data Types:</span></a></li>
<li class="toclevel-1"><a href="#unitptr"><span class="tocnumber">3</span> <span class="toctext">unitptr</span></a>
<ul>
<li class="toclevel-2"><a href="#Char"><span class="tocnumber">3.1</span> <span class="toctext">Char</span></a>
<ul>
<li class="toclevel-3"><a href="#Messages"><span class="tocnumber">3.1.1</span> <span class="toctext">Messages:</span></a></li>
</ul>
</li>
</ul>
</li>
<li class="toclevel-1"><a href="#SFB-COM"><span class="tocnumber">4</span> <span class="toctext">SFB_COM</span></a></li>
<li class="toclevel-1"><a href="#SFB-PRE"><span class="tocnumber">5</span> <span class="toctext">SFB_PRE</span></a>
<ul>
<li class="toclevel-2"><a href="#Built-in-Variables"><span class="tocnumber">5.1</span> <span class="toctext">Built-in Variables:</span></a></li>
</ul>
</li>
<li class="toclevel-1"><a href="#medium"><span class="tocnumber">6</span> <span class="toctext">medium</span></a>
<ul>
<li class="toclevel-2"><a href="#DIL-constructs"><span class="tocnumber">6.1</span> <span class="toctext">DIL constructs:</span></a></li>
<li class="toclevel-2"><a href="#Assignment"><span class="tocnumber">6.2</span> <span class="toctext">Assignment:</span></a></li>
<li class="toclevel-2"><a href="#Expressions"><span class="tocnumber">6.3</span> <span class="toctext">Expressions:</span></a></li>
<li class="toclevel-2"><a href="#Operators"><span class="tocnumber">6.4</span> <span class="toctext">Operators:</span></a></li>
<li class="toclevel-2"><a href="#Functions"><span class="tocnumber">6.5</span> <span class="toctext">Functions:</span></a></li>
<li class="toclevel-2"><a href="#Fields"><span class="tocnumber">6.6</span> <span class="toctext">Fields</span></a></li>
</ul>
</li>
<li class="toclevel-1"><a href="#unitptr-2"><span class="tocnumber">7</span> <span class="toctext">unitptr</span></a>
<ul>
<li class="toclevel-2"><a href="#Char-2"><span class="tocnumber">7.1</span> <span class="toctext">Char</span></a>
<ul>
<li class="toclevel-3"><a href="#Built-In-Functions"><span class="tocnumber">7.1.1</span> <span class="toctext">Built-In Functions:</span></a></li>
</ul>
</li>
</ul>
</li>
<li class="toclevel-1"><a href="#integer-isaff-.28-u-:-unitptr-.2C-i--integer-.29"><span class="tocnumber">8</span> <span class="toctext">integer isaff ( u&#160;: unitptr , i&#160;: integer )</span></a></li>
<li class="toclevel-1"><a href="#stringlist-split-.28-var-s-:-string.2C-var-t--string.29"><span class="tocnumber">9</span> <span class="toctext">stringlist split ( var s&#160;: string, var t&#160;: string)</span></a>
<ul>
<li class="toclevel-2"><a href="#Built-In-Procedures"><span class="tocnumber">9.1</span> <span class="toctext">Built-In Procedures:</span></a></li>
</ul>
</li>
<li class="toclevel-1"><a href="#follow.28.29"><span class="tocnumber">10</span> <span class="toctext">follow()</span></a></li>
<li class="toclevel-1"><a href="#senddone.28.29"><span class="tocnumber">11</span> <span class="toctext">senddone()</span></a></li>
<li class="toclevel-1"><a href="#subaff-.28-u-:-unitptr.2C-i--integer-.29"><span class="tocnumber">12</span> <span class="toctext">subaff ( u&#160;: unitptr, i&#160;: integer )</span></a></li>
<li class="toclevel-1"><a href="#addaff.28-u-:-unitptr.2C-id-:-integer.2C-duration-:-integer.2C-beat:-integer.2C-data0-:-integer.2C-data1:-integer.2C-data2:-integer.2C-tif-first-:-integer.2C-tif-tick-:-integer.2C-tif-last-:-integer.2C-apf--integer.29"><span class="tocnumber">13</span> <span class="toctext">addaff( u&#160;: unitptr, id&#160;: integer, duration&#160;: integer, beat: integer, data0&#160;: integer, data1: integer, data2: integer, tif_first&#160;: integer, tif_tick&#160;: integer, tif_last&#160;: integer, apf&#160;: integer)</span></a></li>
<li class="toclevel-1"><a href="#act.28.29"><span class="tocnumber">14</span> <span class="toctext">act()</span></a>
<ul>
<li class="toclevel-2"><a href="#Syntax"><span class="tocnumber">14.1</span> <span class="toctext">Syntax:</span></a></li>
<li class="toclevel-2"><a href="#Parameters"><span class="tocnumber">14.2</span> <span class="toctext">Parameters:</span></a></li>
</ul>
</li>
<li class="toclevel-1"><a href="#secure-.28-u--unitptr-.2C-label.29"><span class="tocnumber">15</span> <span class="toctext">secure ( u&#160;: unitptr , label)</span></a></li>
<li class="toclevel-1"><a href="#unsecure-.28u--unitptr.29"><span class="tocnumber">16</span> <span class="toctext">unsecure (u&#160;: unitptr)</span></a></li>
<li class="toclevel-1"><a href="#dilcopy.28-s-:-string.2C-u--unitptr-.29"><span class="tocnumber">17</span> <span class="toctext">dilcopy( s&#160;: string, u&#160;: unitptr )</span></a></li>
<li class="toclevel-1"><a href="#setweight.28-u-:-unitptr.2C-i--integer-.29"><span class="tocnumber">18</span> <span class="toctext">setweight( u&#160;: unitptr, i&#160;: integer )</span></a></li>
</ul>
</div>

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
</pre>
<p><br />
<span id="types"></span>
</p>
 <h3><span class="mw-headline" id="Data_Types:">Data Types:</span></h3>
<pre>DIL supports a fixed set of types you can use and manipulate. Through these, you
can get and manipulate information about almost anything in the game. The types
are listed below:
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="str"></span>
</p>
<pre><b>String:</b>
</pre>
<pre>   A string is some text. They are used for a lot of things such as command
arguments, room descriptions etc. String variables are automatically resized and
allocated when you assign them, so you do not have to worry about the string
length nor allocation in your DIL programs. Strings may be compared either with
'==' (equal to),
'!=' (not equal),
'&lt;=' (less than or equal to),
'&gt;=' (greater than or equal to)
'&lt;' (less than),
 '&gt;' (greater than.
</pre>
<pre>  Static strings are defined just as in the rest of the zone, within double
quotations.  Strings may be searched easily with the 'in' operator.  Variables
of type string are saved with DIL programs, if attached to a saved unit.
</pre>
<pre><b>Example:</b>
</pre>
<pre>  "This is a static string"
</pre>
<pre>Strings may also be added to each other, in an expression.
</pre>
<pre><b>Example:</b>
</pre>
<pre>  "say "+itoa(42)+" is the answer!"
</pre>
<pre><b>Example:</b>
</pre>
<pre>  if (self.name == self.names.[1]) ...
</pre>
<pre>  Elements of the string can also be accessed by referencing them by their position.
</pre>
<pre>  <b>Example</b>
  if (str.[3]==f])
  {
  exec ("say The 4th element is a F.",self);
  }
</pre>
<pre>  <b>Note</b>
  Currently you can only access the single elements of a string you can not set
them.  In the future this will be possible.  You can still accomplish this by
copying one string to the other one element at a time and changing any that you
want something like this.
</pre>
<pre><b>Example</b>
i:=0;
ln:=length (str);
while (str.[i]&lt;ln)
	{
	if (str.[i]=="f")
	newstr.[i]:="b";
	else
	newstr:=str.[i];
	i:=i+1;
	}
	str:=newstr;
</pre>
<pre>  This snip of Dil would replace any 'f' in a string with a 'b' remember dil is
not case sensitive so it will also replace an 'F'.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="strl"></span>
</p>
<pre><b>Stringlist:</b>
</pre>
<pre>  A stringlist is a list of separate strings. This is used for things such as
(multiple) names or keywords. You may request a specified word in a stringlist
by its number.
<b>Example:</b>
</pre>
<pre>  mystring&#160;:= self.names.[2];
</pre>
<pre>  Returning null if out of bounds of the stringlist (see 'length()'). Static
stringlists are defined just as in the rest of the zonefile, as a comma separated
list of static strings within curly brackets.
</pre>
<pre><b>Example:</b>
</pre>
<pre>  mysrtringlist&#160;:= {"Some string","another string","the last string"}
</pre>
<pre>  Stringlists are modified through the 'addstring()' and 'substring()' procedures.
Stringlists are searched easily by the 'in' operator. See documentation below.
They can also be set directly (see example above).  Variables of type string are
saved with DIL programs, if attached to a saved unit.
</pre>
<pre>  Elements of each separate string in a stringlist can be accessed by appending
a separate position at the end of the request for a string as follows:
</pre>
<pre><b>Example</b>
if (strlist.[5].[3]=="b"){
do something
}
</pre>
<pre><b>Note</b>
  See the strings for more information on accessing a single element.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="int"></span>
</p>
<pre><b>Integer:</b>
</pre>
<pre>  Non-fraction numbers can be used throughout your DIL programs.  They are given
normally, or in normal C style hexadecimal, preceded with '0x'. Integers are
signed 32-bit integers.  Variables of type string are saved with DIL programs,
if attached to a saved unit.
</pre>
<pre><b>Example:</b>
</pre>
<pre>  0x10
</pre>
<pre><b>Example:</b>
</pre>
<pre>  2
</pre>
<pre>  Integers are used within expressions as both number value and boolean(true/false)
values. You may use comparison between integers through the comparison operators:
'==' (equality),
'&lt;' (less than),
'&gt;' (greater than),
'&lt;=' (less or equal),
'&gt;=' (greater or equal)
'!=' (not equal).
</pre>
<p><br />
</p>
<pre><b>Example:</b>
</pre>
<pre>  if (42&lt;12) ...
</pre>
<pre>  Returning the boolean value (true/false) depending on the comparison between
integers. The result may be stored in an integer variable, and tested later, or
used directly in an 'if' or 'while', etc.  You may also operate on boolean
expression themselves, using LOGICAL operators 'and','not','or', which allows
you to combine the expressions.
</pre>
<pre><b>Example:</b>
</pre>
<pre>  if ( not ( (self.hp&lt;42) or (self.level&gt;10) ) ) ..
</pre>
<pre>Integer expressions may also use a number of other operators:
'+' (addition)
'-' (subtraction/negation),
'*' (multiplication),
'/' (division),
'|' (bitwise or, for flags),
'&amp;' (bitwise and, for flags)
</pre>
<pre>Precedence rules for using these operators are still somewhat messed up.  You'd
better use parenthesis where ever possible.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="intlist"></span>
</p>
<pre><b>Intlist:</b>
</pre>
<pre>  Intlists are an array of integer types.  They can be set directly as follows:
</pre>
<pre><b>Example</b>
</pre>
<pre>wpn:={5,3,6,9,3,9};
</pre>
<pre>The intlists can be accessed in the same way stringlist are accessed as follows.
</pre>
<pre><b>Example</b>
</pre>
<pre>if (wpn.[5]==5)
{
do something
}
</pre>
<pre>The intlists are saved on savable units.
</pre>
<pre><b>Type:  </b><i>intlist</i>
</pre>
<pre>  This variable type allows you to keep an ordered list of integers with out
having to create a variable for each integer.
<b>Example:</b>  <i>Setting an intlist</i>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>myintlist:={1,5,9,2,8,5};
myintlist.[10]:=50;
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<pre>  If you set a index that is higher then the highest index, every index in
between will be set to zero.  For example if you only have two values in the
intlist and you set index value 10 to 50 all indexes between 2 and 10 will be
set to 0.
<b>Example:</b>  <i>Using intlists</i>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>if (myintlist.[5]==5){
stuff
}
</pre></i><i><pre>if (myintlist&lt;myint){
stuff
}
</pre></i><i><pre>i:=0;
ln:=length(myintlist);
while (i&lt;ln){
myintlist.[i]:=i;
i:=i+1;
}
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also:</b>
<a href="#bpinsert">Insert</a>
<a href="#bpremove">Remove</a>
<a href="#eptr">Extraptr</a>
</pre>
<p><br />
<span id="eptr"></span>
</p>
<pre><b>Extraptr:</b>
</pre>
<pre>  Extra descriptions, quests structures, etc can be searched and manipulated
using variables of this type. There is no way to declare static structures of
this type in DIL programs. Lists of extra descriptions are easily searched with
the 'in' operator (See below).  Extraptr variables are 'volatile', and thus
cleared whenever there is a possibility that they are rendered unusable.
</pre>
<p>Members:
</p>
<table class="wikitable">

<tbody><tr>
<th>member</th>
<th>type</th>
<th>description
</th></tr>
<tr>
<td>next</td>
<td>extraptr</td>
<td>Points to the next linked extra description. NULL if none
</td></tr>
<tr>
<td>names</td>
<td><a href="./Manual:DIL-Manual-stringlist" title="Manual:DIL Manual/stringlist">stringlist</a></td>
<td>Array of names on the extra description. NULL if none
</td></tr>
<tr>
<td>vals</td>
<td><a href="./Manual:DIL-Manual-integerlist" title="Manual:DIL Manual/integerlist">intlist</a></td>
<td>Array of integers on the extra description. NULL if none
</td></tr>
<tr>
<td>descr</td>
<td><a href="./Manual:DIL-Manual-string" title="Manual:DIL Manual/string">string</a></td>
<td>string of text
</td></tr></tbody></table>
<p><br />
<span id="cptr"></span>
</p>
<pre><b>Type:  </b><i>cmdptr</i>
<b>cmdptr fields</b>
</pre>
<p><br />
</p>
<pre><b>name</b>
            string - command name
<b>type</b>
            integer - command type like social or skill or just command
<b>level</b>
            integer - minimum level to use command
<b>loglevel</b>
            integer - level of character that can see the log 0 for no logs
<b>position</b>
            integer - minimum position to use command
<b>next</b>
            cmdptr - pointer to the next cmdptr
<b>previous</b>
            cmdptr - pointer to the previous cmdptr
</pre>
<p><br />
</p>
<pre>  The cmdptr can be used to search the command list or display all the commands.
I0t is also now possible to sort the commands by type by defining your own command
types and using the type field to sort on.
</pre>
<pre>  In order to get the first command in the list you use the following function:
<b>Function:  </b><i>chead();</i>
If you want to get a specific command then you use the following function:
<b>Function:  </b><i>cmdptr&#160;:= getcommand (s&#160;: string );</i>
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin cmdtst(arg&#160;: string);
var
  cmd&#160;: cmdptr;
  st&#160;: string;
</pre></i><i><pre>code
{
   cmd&#160;:= chead();
</pre></i><i><pre>	  while (cmd)
        {
        st&#160;:= cmd.name + " " + itoa(cmd.level) + " " + itoa(cmd.type) + " " +
        itoa(cmd.loglevel) + " " + itoa(cmd.position);
        act("CMD: $2t", A_ALWAYS, self, st, null, TO_CHAR);
        cmd&#160;:= cmd.next;
        }
</pre></i><i><pre>        cmd:=getcommand("kick");
        sendtext ("You must be "+itoa(cmd.level+" to use kick&amp;n",self);
</pre></i><i><pre>           quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span class="mw-headline" id="unitptr">unitptr</span></h1>
<pre><b>The unitptr has the following fields:</b>
</pre>
<pre>   unitptr:
      'names'        :stringlist (RW)
         A list of names that matches the unit.
      'name'         :string (RW)
         The first name in the namelist in 'names'
      'outside_descr' :string (RW)
         The description of the unit from the 'outside'. f.inst.
         the description of a boat, seen from the outside.
      'inside_descr' :string (RW)
         The description of the unit from the 'inside'. f.inst.
         the description of a boat, seen from the inside.
      'next'         :unitptr (RO)
         The next unit in the local list of units. For instance, the
         units in the inventory of a PC, is linked with this field.
      'title'        :string (RW)
         The title of the unit.
      'extra'        :extraptr (RW)
         Extra descriptions of the unit (identify, look at, read etc.).
      'outside'      :unitptr (RO)
         The outside of the unit hierarchy (carried by, contained by).
         For instance, the contents of a bag have their 'outside'
         field pointing to the bag.
      'inside'       :unitptr (RO)
         The inside of the unit hierarchy (carry, contains).
         For instance the first unit in a PC's inventory is referenced
         by the 'inside' field.
      'key'       :string (RO)
         The key that will open this unitptr
         For instance "big_key@blackzon"
		          by the 'inside' field.
      'gnext'        :unitptr (RO)
         Next unit in the global list of units.
      'gprevious'    :unitptr (RO)
         Previous unit in the global list of units.
      'hasfunc'      :integer (RO)
         Returns TRUE if unit has special functions attached to it.
      'max_hp'       :integer (RO/RW)
         The maximum hitpoints of unit, RO for players, RW for mobiles.
      'max_mana'       :integer (RO)
         The maximum mana of the character (player or mobile).
      'max_endurance'  :integer (RO)
         The maximum endurance of the character (player or mobile).
      'lifespan'       :integer (RW)
         The lifespan of a character, write permission only on root access.
      'hp'           :integer (RW)
         The current hitpoints of unit. For objects, this can render
         it 'broken' by being set low. If an unit has -1 hitpoints
         its considered unbreakable.
      'manipulate'   :integer (RW)
         Bits that specify how unit can be handled, see MANIPULATE_*
         flags in values.h and/or vme.h
      'flags'        :integer (RW)
         Bits that specify different properties of a unit, see
         UNIT_FL_* in values.h and/or vme.h
      'baseweight'   :integer (RO)
         The empty weight of the unit. This can be set with the
         procedure 'setweight()'
      'weight'       :integer (RO)
         The current weight of the unit (and its contents).
      'capacity'     :integer (RW)
         The amount of weight the unit can contain.
      'height'       :integer (RW)
         The height of a PC/NPC, the length of a rope, the size of weapons,
         armours, and shields.
      'alignment'    :integer (RW)
         The alignment of the unit. [1000..-1000],
         1000 is good, 0 is neutral, -1000 is evil.
      'openflags'    :integer (RW)
         Bits thats specify how a unit may be opened, locked, etc,
         see EX_* in values.
      'light'        :integer (RO)
         How much light is inside the unit.
      'bright'       :integer (RO)
         How much the unit lights up. This can be set with the
         procedure 'setbright()'
      'illum'        :integer (RO)
         How much light units inside a transparent unit create
      'minv'         :integer (RW)
         The 'wizard invisibility' level.
      'spells'[]     :integer (RO)
         The defence/skill of the different spell spheres/spells
         The index should be one of the SPL_* in values.h and/or vme.h
      'zoneidx'      :string (RO)
         The unique database name (in the zone) for this unit.
      'nameidx'      :string (RO)
         The unique database zone name for this unit.
      'symname'      : string (RO)
         The concatenated nameidx@zoneidx to make it easier to use IRL
      'idx'      :integer (RO)
         Constant ID for players and for non-PCs it is the memory pointer
         converted to an integer. If there are 50 cityguards, you can use
         the idx to figure out which one you're looking for. Use 
         findsymbolic(#,#) to quickly find precisely a unit matching a 
         symbolic name and an idx. 
         Be warned, this value change between each reboot, except for players, so do not
         count on it for purposes of persistence across reboots.
      'zone'         :string (RO)
         The name of the zone the unit is in.
      'type'         :integer (RO)
         The type of the unit, see UNIT_ST_* in values.h and/or vme.h
      'loadcount'    :integer (RO)
         Returns the number of units loaded in the game
         of this definition (zoneidx,nameidx / idx)
</pre>
<h2><span class="mw-headline" id="Char">Char</span></h2>
<p>If the unitptr.type == UNIT_ST_PC or UNIT_ST_NPC then you can use these flags:
</p>
<pre>      'master'         :unitptr (RW)
         The unitptr to the master that this CHAR is following. See also <a href="./Manual:DIL-Manual-follow()" title="Manual:DIL Manual/follow()">follow()</a>
</pre>
<pre>      ... And a whole slew of other fields.
</pre>
<p><br />
<span id="zptr"></span>
</p>
<pre><b>Type:  </b><i>zoneptr</i>
<b>Zone Pointer Fields</b>
</pre>
<p><br />
</p>
<pre>  <b>next</b>
         unitptr - pointer to next zoneptr
  <b>previous</b>
         unitptr - pointer to previous zone
  <b>creators</b>
         stringlist - list of creators
  <b>name</b>
         string - zone name (%zone)
  <b>title</b>
         string - zone title (title "")
  <b>rooms</b>
         unitptr - pointer to the base room
  <b>objs</b>
         unitptr - pointer to the base objects of the zone
  <b>npcs</b>
         unitptr - pointer to base NPCs of the zone
  <b>resetmode</b>
         integer- reset mode of zone in 'values.h'
  <b>resettime</b>
         integer - the reset time of the zone
  <b>access</b>
         integer - the access level of the zone
  <b>loadlevel</b>
         integer - the loadlevel of the zone
  <b>payonly</b>
         integer - the paystatus of the zone
  <b>roomcount</b>
         integer - the number of rooms in a zone
  <b>objcount</b>
         integer - the numbner of objects in a zone
  <b>npccount</b>
         integer - the number of npcs/mobiles in a zone
  <b>fname</b>
         string - the filename of a zone
  <b>notes</b>
         string - the Zone Notes
  <b>help</b>
         string - the Zone Help
</pre>
<p><br />
</p>
<pre>  The 'zoneptr' works like a unitptr.  To get the first zoneptr in the global
list of zones you use 'zhead'.
<b>Example: </b><i>zoneptr&#160;:= zhead();</i>
<b>Zone list command</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin zonelist (arg:string);
var
 z:zoneptr;
 buf:string;
code
{
          z:=zhead();
          while (z)
          {
          buf:="Name:  "+z.name+"&amp;n";
          buf:=buf+"Filename:  "+z.fname+"&amp;n";
          buf:=buf+"Creator:  "+z.creators.[0]+"&amp;n";
          buf:=buf+"Notes:  &amp;n"+z.notes+"&amp;n&amp;n";
          z:=z.next;
          }
</pre></i><i><pre>          pagestring (buf,self);
          quit;
}
dilend
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
<span id="messies"></span>
</p>
 <h3><span class="mw-headline" id="Messages:">Messages:</span></h3>
<pre>  In DIL, a program attached to a unit gets activated when the program receives
a message. In order to save CPU usage, there are a number of different message
categories which can cause activation of a program.  The 'wait()' commands first
parameter is an integer, telling what message categories the program should
reactivate on.  The second parameter is an expression, which also must evaluate
to TRUE. 'pause' is just special instances of the 'wait()' command.
</pre>
<p><br />
</p>
<pre><strong>Caveat Builder: </strong>
</pre>
<pre>  Whenever you construct the arguments for the wait command, bear in mind that
ALL your tests will be executed EVERYTIME a message of the relevant kind comes
through.  Thus you should keep the length of the activation expression to a
reasonable minimum, and you should NEVER use the time-consuming findxxx-functions.
</pre>
<pre>Valid example (That prohibits a player from removing an object):
</pre>
<pre>:glue:
</pre>
<p><br />
</p>
<pre>	wait(SFB_CMD,command(CMD_REMOVE));
	u&#160;:= findunit(activator,argument,FIND_UNIT_IN_ME,null );
	if (u&#160;!= self)
	 {
		goto glue;
	 }
	act("You can't remove $2n, it's sticky.",
	   A_SOMEONE,activator,self,null,TO_CHAR););
	block;
	goto glue;
</pre>
<pre><b>See Also:</b>
<a href="#findunit.html">Dil and Findunit()</a>
</pre>
<pre>The message categories are as follows:
---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="sfbcmd"></span>
</p>
<pre>SFB_CMD            Command message
</pre>
<pre>  When this flag is set, the program gets activated by all commands (legal
  or illegal) issued by PC's or NPC's. Moving around is also considered a
  command.
</pre>
<pre>  Assume a janitor executes the command '
  Ge all from corpse',
  And Ge interprets to 'get'
</pre>
<pre>  then this will occur in the DIL program:
</pre>
<pre>     'activator'... is a unitptr to the janitor.
     'cmdstr'...... is a string which contains 'get'
     'excmdstr'...... is a string which contains 'ge'
     'excmdstr_case'...... is a string which contains 'Ge'
     'argument'.... will contain 'all from corpse'
</pre>
<pre>     command(CMD_GET) will evaluate to TRUE.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="sfbdone"></span>
</p>
<pre>SFB_DONE           'Command has now been executed' message
</pre>
<pre>  When this flag is set, the program gets activated by all successful commands
  issued by PC's or NPC's. The 'activator', 'medium' and 'target' special
  values are used as follows:
</pre>
<pre>     'activator'... The PC / NPC which executed the command
     'medium'...... The unit which is operated upon.
     'target'...... The target of the operation.
</pre>
<pre>  For example, assume the player John gives a garlic to Mary the Lumberjack
  wife. The following values are set:
</pre>
<pre>     activator == John (unitptr)
     medium    == Mushroom (unitptr)
     target    == Mary (unitptr)
</pre>
<pre>  command(CMD_GIVE) will evaluate to true.
</pre>
<pre>  You thus know that Mary has in fact received the mushroom. It is NOT possible
  to block (using the 'block' command) these commands since they have already
  been executed at the time of notification.  In a 'get' command, medium would
  be a unitptr to where the unit was taken from, and target would be the object
  which was taken.
</pre>
<pre>  See the file commands.txt for a description of how the arguments are set for
  each command. If you can not find a command in there, just ask to get it
  implemented. Especially you should pay attention to the non-obvious SFB_DONE
  command(CMD_AUTO_ENTER).
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="sfbtick"></span>
</p>
<pre>SFB_TICK           Timer message
</pre>
<pre>  When this flag is set, the routine gets activated by a "clock". The clock
  ticks (in 1/4th of a second) are determined by the 'heartbeat' variable.
</pre>
<pre>     'activator'... is null.
     'argument'.... will be empty.
</pre>
<pre>      command(CMD_AUTO_TICK) will evaluate to TRUE.
---~---~---~---~---~---~---~---~---
</pre>
<h1><span class="mw-headline" id="SFB_COM">SFB_COM</span></h1>
<p>SFB_COM is a combat message that is sent during combat.
</p><p>When this flag is used in a wait() statement, it will trigger on combat messages.
The unit containing the DIL program needs not be involved in the combat itself,
it will react to any combat in it's local environment. The combat message is sent
just prior to the hit.
</p><p>Only the following global value is set in a SFB_COM combat message:
</p>
<pre> 'activator'&#160;: is a unitptr to the PC/NPC about to hit someone else.
</pre>
<p>Note that:
</p>
<pre> command(CMD_AUTO_COMBAT) 
</pre>
<p>will evaluate to TRUE.
</p><p>Example:
</p>
<pre> wait(SFB_COM, activator == self);
</pre>
<p>Example:
</p>
<pre> wait(SFB_COM, activator == self.fighting);
</pre>
<p>Example:
</p>
<pre> wait(SFB_ALL, TRUE);
 if (command(CMD_AUTO_COMBAT))
   exec("flee", self);
</pre>
<p>You may want to take a look at the DIL vorpalweapon() in one of the distribution zones.
</p><p>See also:
</p>
<pre> &gt; wait
 &gt; SFB_PRE
 &gt; CMD_AUTO_DAMAGE
</pre>
<p><br />
<span id="sfbdead"></span>
</p>
<pre>SFB_DEAD           Death message
</pre>
<pre>  When this flag is set, the routine gets activated when a PC or NPC dies:
</pre>
<pre>     'activator'... will point to the PC/NPC that is about to die.
     'argument'.... is empty.
</pre>
<pre>      command(CMD_AUTO_DEATH) will evaluate to TRUE
</pre>
<pre>  The SFB_DEAD message is sent, just as the character dies, while his items are
  still equipped, just before the corpse is created.  The character's '.fighting'
  field points to his primary opponent, although this person does not necessarily
  have to be the one that killed him.
</pre>
<pre>  This can be exploited by making items wiz invisible (the .minv field) just as
  the message is received, causing them to stay inside the player rather than
  being transferred to the corpse. This does both give the ultimate crash
  protection, as well as a means of letting items, such as bribe items, forever
  be a part of the player (remember to make it un-wizinvis when the player
  returns from heaven - players should not have access to items while in heaven).
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="sfbmsg"></span>
</p>
<pre>SFB_MSG            User message
</pre>
<pre>  When this flag is set, the routine gets activated when a message is passed
  to it. Messages can be passed with the DIL commands 'sendto' and 'send':
</pre>
<pre>     'activator'... is a unitptr to the unit sending the message.
     'argument'.... is a string containing possible data from the sender.
</pre>
<pre>      command(CMD_AUTO_MSG) will evaluate to true.
</pre>
<p><br />
</p>
<pre>  Messages are normally not generated by actions performed by the owner of the
  program. For a program to be able to be aware of messages from the owner, a
  keyword 'aware' should be listed just after 'dilbegin'.
</pre>
<pre>  When a unit is saved, normally, the DIL programs in it would restart when the
  program is loaded. However it is possible to let DIL programs recall their
  execution from where they left off when they where saved.  This is done by
  listing the keyword 'recall' after the 'dilbegin'.  This is however a bit
  limited.  Only the status of the original template are saved. Not the state
  inside a template called as a function or procedure from inside the original
  template. 'secure' and interrupts are not recalled upon loading the template.
</pre>
<p><br />
</p>
<pre><b>Example:</b>
</pre>
<pre>

 dilbegin recall aware mute();
 var
    i : integer;

 code
 {
    i:=10;
    while (i&gt;0)
    {
       wait(SFB_CMD,command(CMD_SAY) or command(CMD_SHOUT));
       exec("emote tries to make a sound, but only blood spurts through"+
            "the lips",self);
       block;
       i := i - 1;
    }

    i:=10;
    while (i&gt;0)
    {
       wait(SFB_CMD,command(CMD_SAY) or command(CMD_SHOUT));
       exec("emote tries to make a sound, but can't",self);
       block;
       i := i - 1;
    }

    i:=10;
    while (i&gt;0)
    {
       wait(SFB_CMD,command(CMD_SAY) or command(CMD_SHOUT));
       exec("emote tries to make a loud sound, but can't",self);
       block;
       i := i - 1;
    }
    quit;
 }
 dilend
</pre>
<pre>/* When attached to a PC, the pc will be unable to utter a sound the first 10
   sound command, and blood will spurt out.
   The next 10 sound commands, the victim just can't shout.
   The last 10 sound commands only say will work.
   In the end, 'quit' removes the program all together.
   The smart thing is that the 'aware' keyword lets the program receive messages
   from the owner (player) commands. Secondly, the keyword 'recall' makes sure
   that the program does not start over, if the victim quits in the middle, but
   restart at the position it had attained.
   Do not put in the 'aware' if it is not needed. It saves some interpretation
   time not having to pass the extra messages.
*/
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span class="mw-headline" id="SFB_PRE">SFB_PRE</span></h1>
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
</pre>
<p><br />
<span id="built_in"></span>
</p>
 <h3><span class="mw-headline" id="Built-in_Variables:">Built-in Variables:</span></h3>
<p><br />
<span id="cmdstr"></span>
</p>
<pre>'cmdstr'
   This variable is a string which contains the "command" which was entered
   by a player. The result of adding:
</pre>
<pre>      cmdstr + " " + argument
</pre>
<pre>   is the entire string as entered by the player.
   The 'cmdstr' is EXPANDED by the interpreter, so assume a player
   types 's' then the string is expanded to 'south'.
</pre>
<p><br />
<span id="excmdstr"></span>
</p>
<pre>'excmdstr'
   This variable is a string which contains the "first string" which was entered
   by a player. The result of adding:
</pre>
<pre>      excmdstr + " " + argument
</pre>
<pre>   is the entire string as entered by the player. The 'excmdstr' is not
   EXPANDED by the interpreter, but it is converted to lower case. So
   assume a player types 'S' then the string is returned as 's'.  The
   'excmdstr' is however changed to all lower case if you don't want
   this see 'excmdstr_case'.
</pre>
<p><br />
<span id="excmdstr_case"></span>
</p>
<pre>'excmdstr_case'
   This variable is a string which contains the "first string" which was entered
   by a player. The result of adding:
</pre>
<pre>      excmdstr_case + " " + argument
</pre>
<pre>   is the entire string as entered by the player.
   The 'excmdstr' is not changed in anyway from how a player types it.
   If a player types 'S' then the 'excmdstr_case' will have 'S' in it.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="self"></span>
</p>
<pre>'self'
   This variable is a unitptr to the unit owning the DIL program.
   For C++ people, this is like the 'this' pointer.
   For example, if Mary has a program, then self.title equals
   "Mary the Lumberjack wife"
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="activator"></span>
</p>
<pre>'activator'
   This variable is a unit pointer to the unit which activated the DIL
   program. It is set if 'activator' issued a command or unknown command
   and the program was setup to catch it, with&#160;: wait (SFB_CMD...).
   See description of messages for more information.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="targ"></span>
</p>
<pre>'target'
   This variable is a unit pointer to the unit which is the target of the
   current operation. For 'done' messages this could for example be the
   destination in a give command.
   See description of messages for more information.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span class="mw-headline" id="medium">medium</span></h1>
<p>This built-in variable is a unit pointer to the unit which was used during an operation. For 'done' messages this could for example be a bag which  the medium in a get operation. See description of messages for more information.
</p><p><br />
<span id="power"></span>
</p>
<pre>'power'
   This variable is an integer which can be reassigned. It is used in
   permission messages and in a few done messages. For example a permission
   request to damage a person with 100 damage would have power equal 100.
   This could then be reduced to 50 by assigning a new number.
   See description of messages for more information.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="argu"></span>
</p>
<pre>'argument'
   This variable is a string, showing the argument of a command resulting
   in the activation of the DIL program. See SFB_CMD for example.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="hb"></span>
</p>
<pre>'heartbeat'
   This is the DIL programs heartbeat. It can be assigned runtime to
   change the rate with which SFB_TICK is activated. Do not set it
   too low, and remember that it is specified in 1/4th of a second.
   use the constant PULSE_SEC to multiply your wanted delay, for
   Example:
      heartbeat&#160;:= PULSE_SEC*25; /* Tick every 25 seconds */
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="null"></span>
</p>
<pre>'null'
   This is a null pointer.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="weather"></span>
</p>
<pre>'weather'
   This is the state of the mud-weather. It will equal one of the
   SKY_XXX values in values.h and/or vme.h.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bvrealtime"></span>
</p>
<pre>'realtime'
   This variable returns the number of seconds passed since 1970 something.
   For C buffs this is equivalent to time(NULL).
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="mmmm"></span>
</p>
<pre>'mudday'
'mudhour'
'mudmonth'
'mudyear'
   These variables lets your program keep track of the time in the mud.
   They all have integer types.
</pre>
<p><br />
<span id="const"></span>
</p>
 <h3><span class="mw-headline" id="DIL_constructs:">DIL constructs:</span></h3>
<pre>DIL offers a set of construct for you to program with.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="dcif"></span>
</p>
<pre><b>if:</b>
    The if statement is much like C. It takes any type as
    argument. Non integers are considered 'TRUE' if they are
    not null.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     if (self.hp&gt;10)
     {
       exec("say Hehe!",self);
     }
     else
     {
       exec("say ouch!", self);
     }
   }
   dilend
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     if (self.loaded&gt;10)
     {
       exec("say its getting crowded!",self);
     }
   }
   dilend
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     if (self.loaded&lt;10)
       exec("say plenty of room!",self);
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="dcgoto"></span>
</p>
<pre><b>goto:</b>
    The goto statement lets you jump about in the code.
    Labels in your DIL programs, for 'goto' or interrupts
    are defined within ':'. For an example, see the program below.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

 dilbegin foo();
   code
   {
     :mylabel:
     exec("say Hello world",self);
     pause;
     goto mylabel;
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="dcwhile"></span>
</p>
<pre><b>while:</b>
    The while statement lets you execute a series of
    statements while an expression evaluates to TRUE.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

 dilbegin foo();
   code
   {
     while (not self.inside) {
       exec("say I own nothing", self);
       pause;
     }
     exec("say ahh.. now i own something", self);
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="dcbreak"></span>
</p>
<pre><b>break:</b>
    The break statement makes you break out of any
    loop you're currently in.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

 dilbegin foo();
   code
   {
     while (self.inside) {
       if (self.position &amp;lt POSITION_SLEEPING)
         break;
       exec("say I own something", self);
       pause;
     }
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="dccont"></span>
</p>
<pre><b>continue:</b>
    The continue statement makes you jump to the top
    of any loop you're currently in.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     while (self.inside) {
       if (self.position &amp;lt POSITION_SLEEPING)
         break;
       pause;
       if (self.hp&lt;0) continue;
       exec("say I own something", self);
       pause;
     }
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
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
</pre>
<p><br />
<span id="forea"></span>
</p>
<pre><b>foreach:</b>
  Foreach is an easy way to process all the units in the
  local environment relative to the 'self' executing the
  foreach. Foreach takes care of creating a list of local
  units, and of securing them. You can use both break and
  continue in a foreach statement. The unit executing the
  foreach ('self') is always a part of the foreach.
</pre>
<pre>      It is important to understand that the units in the local
      environment are relative to the 'self' executing the foreach.
</pre>
<pre><b>Example:</b>
    This foreach is copied onto the spell caster, and hence all units
    relative to the spell caster (i.e. self) are processed in the foreach.
    Assume that it was executed on the spell caster's staff, then all units
    found would be relative to the staff, i.e. the spell caster's inventory.
</pre>
<pre>

 ...
    foreach (UNIT_ST_PC|UNIT_ST_NPC, u)
    {
       if (u.hp &lt; u.max_hp)
       {
          act("Warm raindrops fall upon you, cleaning your wounds.",
              A_ALWAYS, u, null, null, TO_CHAR);
          u.hp := u.hp + 6;
          if (u.hp &gt; u.max_hp)
            u.hp := u.max_hp;
       }
       else
         act("Warm raindrops fall upon you.",
             A_ALWAYS, u, null, null, TO_CHAR);
       pause;
    }
 ...
</pre>
<p><br />
<span id="assgn"></span>
</p>
 <h3><span class="mw-headline" id="Assignment:">Assignment:</span></h3>
<pre>    You can assign values to the variables you declare
    in your 'var' section, and some of the built-in
    variables. This is  done by the ':=' operator.
    Note that you can also assign a variable the result
    of an expression
    (the addition of strings below as an example)
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   var
     myvarsl : stringlist;
     myvars : string;
   code
   {
     :start:
     myvarsl := {"a string","another","the first"};
     myvars := self.name+" XX ";
     myvarsl.[2] := "the last";
     myvarsl.[3] := "illegal";  /* Will not work since [3] is not defined */
     pause;
     goto start:
   }
   dilend
</pre>
<p><br />
<span id="express"></span>
</p>
 <h3><span class="mw-headline" id="Expressions:">Expressions:</span></h3>
<pre>  The expressions used in assignment can return any
  of the types you can declare variables. Also they might return
  fail or null. An expression returning fail will not result
  in any action being taken. Fail is returned when you
  request a field from a null pointer, or the like.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   var
     myvarsl : stringlist;
     myvars : string;
     myvarint : integer;
     myvaredp : extraptr;
     myvarunit : unitptr;
   code
   {
     :start:
     myvarunit := self.inside.next;
     myvarsl := {"a string","another","the last"};
     myvars := self.name+" XX "+itoa(self.hp);
     myvarint := activator.hp;
     myvaredp := "Rabbit Stew Complete" in activator.quests;
     pause;
     goto start:
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="ops"></span>
</p>
 <h3><span class="mw-headline" id="Operators:">Operators:</span></h3>
<pre>  DIL features many other operators. For integers,
  '&lt;', '&gt;', '&lt;=', '&gt;=', '!=' '==' signify less than,
  greater than, less or equal, greater or equal, not equal,
  and equality operators. Furthermore, you can compare
  strings with '==' or '$=' for equality test, and '!='
  for non equality. Pointers may also use '==' and '!='
  and you may force DIL to compare pointers, even for
  strings with the '#=' pointer-equality operator.
  The '$=' and '#=' is considered obsolete, and only
  used for backward compatibility.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="ein"></span>
</p>
<pre><b>in:</b>
	The special operator 'in' is a multipurpose operator for
	a lot of things. It allows you to search through
	quests and extra descriptions, stringlists and search
	for words in strings.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="esins"></span>
</p>
<pre>string 'in' string
   Argument 1: A string to find.
   Argument 2: A string to search.
   Return: TRUE, if first string is found in second string.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     if ("guard" in activator.title)
       exec("say hello guard",self);
     pause;
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="esinsl"></span>
</p>
<pre>string 'in' stringlist
   Argument 1: A string to find.
   Argument 2: A stringlist to search.
   Returns: 1.. if first string is found in stringlist, or 0 if it is
            non existent. If found the number equals the index of the
            string found plus one.
</pre>
<pre>Example 1:
  s&#160;:= "c";
  sl&#160;:= {"a","b","c","d"};
  i&#160;:= s in sl;
</pre>
<pre>  The result of 'i' is 3, and sl.[i-1] equals "c" (s).
</pre>
<pre>Example 2:
</pre>
<pre>

   dilbegin foo();
   code
   {
     if ("james" in activator.names)
       exec("say hello james.",self);
     pause;
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="esine"></span>
</p>
<pre>string in extraptr
   Argument 1: A string to find.
   Argument 2: An extra description list to search.
   Return: Extraptr to first entry with string matching .names or
           null if none. (names must be exact letter by letter
           match, although case is ignored).
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     if ("Rabbit Stew Complete" in activator.quests) {
       exec("say wow!, you helped Mary get her stew!", self);
       exec("app ", self);
     }
     pause;
   }
   dilend
</pre>
<p><br />
<span id="funcs"></span>
</p>
 <h3><span class="mw-headline" id="Functions:">Functions:</span></h3>
<pre>  DIL features an extended set of built-in functions
  for extended program control. Built-in functions can be part of
  any expression in DIL. The built-in functions are
  listed later.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin foo();
   code
   {
     exec("say I exist in "+itoa(self.loaded)+"copies", self);
     pause;
   }
   dilend
</pre>
<pre>  DIL also lets you use templates as functions, but in a
  limited way. Using templates as functions, you may only
  use the return value to assign it to one of the variables
  declared in the 'var' section. No fields.
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin integer bar(s:string);
   code
   {
     exec("say "+s,self);
     return rnd(1,10);
   }
   dilend
</pre>
<pre>

   dilbegin foo();
   external
     integer bar(s:string);
   var
     myint:integer;
   code
   {
     myint := bar("rolling the dice.");
     exec("say I rolled a "+itoa(myint));
     pause;
   }
   dilend
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="fquit"></span>
</p>
<pre>quit:
  This simple command quits the entire DIL program, even if
  called while inside a procedure or function.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="fret"></span>
</p>
<pre>return:
  Return from a call to a procedure template (no return type
  declared). The execution continues from where the procedure
  was called.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="fret2"></span>
</p>
<pre>return():
  Return from a call to a function (return type declared).
  The expression inside the parenthesis evaluates to the value
  returned.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<pre>  DIL also allows for game-time *symbolic* resolving of
  function/procedure names. This allows you to pass template names
  as string arguments and call them in your program. This kind of
  function call requires taxing look ups and type check runtime, so
  use the normal kind of procedures if possible.
</pre>
<pre>  In effect, the syntax of a symbolic call is similar to that of
  a normal, except you use a string variable as function name
  instead of the real function name. If the string variable contains
  a valid reference to a procedure/function, and all the argument
  types matches the found templates argument types, the call
  is made. Otherwise, the call is skipped. Note that you will get no
  type check by the compiler when using symbolic references.
</pre>
<p><br />
<span id="fields"></span>
</p>
 <h3><span class="mw-headline" id="Fields">Fields</span></h3>
<pre>The 'extraptr' and 'unitptr' types contain information which is available to
you by using fields. For example (self is a unitptr), self.inside is a
unitptr to what is inside the 'self' unit. (Hence '.inside' is the field).
And self.inside.outside is a unitptr to self (assuming that something is
actually inside self, otherwise self.inside would evaluate to null).
Some fields may not be changed by DIL programs directly but must be modified
indirectly using certain procedure calls in DIL. Others may not be changed
at all. All are readable for DIL programs.
</pre>
<pre>The extraptr structure is used for several things. The primary is
extra descriptions for units, and quest data. Keywords in the 'names'
field and the actual description/data in the 'descr' field.
</pre>
<pre>In the following (RW) means the value may be assigned new values by DIL,
while (RO) means the the value only can be read. A (RO) value might be
possible to change through built-in functions/procedures
---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="eptr"></span>
</p>
<pre><b>Extraptr:</b>
</pre>
<pre>  Extra descriptions, quests structures, etc can be searched and manipulated
using variables of this type. There is no way to declare static structures of
this type in DIL programs. Lists of extra descriptions are easily searched with
the 'in' operator (See below).  Extraptr variables are 'volatile', and thus
cleared whenever there is a possibility that they are rendered unusable.
</pre>
<p>Members:
</p>
<table class="wikitable">

<tbody><tr>
<th>member</th>
<th>type</th>
<th>description
</th></tr>
<tr>
<td>next</td>
<td>extraptr</td>
<td>Points to the next linked extra description. NULL if none
</td></tr>
<tr>
<td>names</td>
<td><a href="./Manual:DIL-Manual-stringlist" title="Manual:DIL Manual/stringlist">stringlist</a></td>
<td>Array of names on the extra description. NULL if none
</td></tr>
<tr>
<td>vals</td>
<td><a href="./Manual:DIL-Manual-integerlist" title="Manual:DIL Manual/integerlist">intlist</a></td>
<td>Array of integers on the extra description. NULL if none
</td></tr>
<tr>
<td>descr</td>
<td><a href="./Manual:DIL-Manual-string" title="Manual:DIL Manual/string">string</a></td>
<td>string of text
</td></tr></tbody></table>
<h1><span class="mw-headline" id="unitptr_2">unitptr</span></h1>
<pre><b>The unitptr has the following fields:</b>
</pre>
<pre>   unitptr:
      'names'        :stringlist (RW)
         A list of names that matches the unit.
      'name'         :string (RW)
         The first name in the namelist in 'names'
      'outside_descr' :string (RW)
         The description of the unit from the 'outside'. f.inst.
         the description of a boat, seen from the outside.
      'inside_descr' :string (RW)
         The description of the unit from the 'inside'. f.inst.
         the description of a boat, seen from the inside.
      'next'         :unitptr (RO)
         The next unit in the local list of units. For instance, the
         units in the inventory of a PC, is linked with this field.
      'title'        :string (RW)
         The title of the unit.
      'extra'        :extraptr (RW)
         Extra descriptions of the unit (identify, look at, read etc.).
      'outside'      :unitptr (RO)
         The outside of the unit hierarchy (carried by, contained by).
         For instance, the contents of a bag have their 'outside'
         field pointing to the bag.
      'inside'       :unitptr (RO)
         The inside of the unit hierarchy (carry, contains).
         For instance the first unit in a PC's inventory is referenced
         by the 'inside' field.
      'key'       :string (RO)
         The key that will open this unitptr
         For instance "big_key@blackzon"
		          by the 'inside' field.
      'gnext'        :unitptr (RO)
         Next unit in the global list of units.
      'gprevious'    :unitptr (RO)
         Previous unit in the global list of units.
      'hasfunc'      :integer (RO)
         Returns TRUE if unit has special functions attached to it.
      'max_hp'       :integer (RO/RW)
         The maximum hitpoints of unit, RO for players, RW for mobiles.
      'max_mana'       :integer (RO)
         The maximum mana of the character (player or mobile).
      'max_endurance'  :integer (RO)
         The maximum endurance of the character (player or mobile).
      'lifespan'       :integer (RW)
         The lifespan of a character, write permission only on root access.
      'hp'           :integer (RW)
         The current hitpoints of unit. For objects, this can render
         it 'broken' by being set low. If an unit has -1 hitpoints
         its considered unbreakable.
      'manipulate'   :integer (RW)
         Bits that specify how unit can be handled, see MANIPULATE_*
         flags in values.h and/or vme.h
      'flags'        :integer (RW)
         Bits that specify different properties of a unit, see
         UNIT_FL_* in values.h and/or vme.h
      'baseweight'   :integer (RO)
         The empty weight of the unit. This can be set with the
         procedure 'setweight()'
      'weight'       :integer (RO)
         The current weight of the unit (and its contents).
      'capacity'     :integer (RW)
         The amount of weight the unit can contain.
      'height'       :integer (RW)
         The height of a PC/NPC, the length of a rope, the size of weapons,
         armours, and shields.
      'alignment'    :integer (RW)
         The alignment of the unit. [1000..-1000],
         1000 is good, 0 is neutral, -1000 is evil.
      'openflags'    :integer (RW)
         Bits thats specify how a unit may be opened, locked, etc,
         see EX_* in values.
      'light'        :integer (RO)
         How much light is inside the unit.
      'bright'       :integer (RO)
         How much the unit lights up. This can be set with the
         procedure 'setbright()'
      'illum'        :integer (RO)
         How much light units inside a transparent unit create
      'minv'         :integer (RW)
         The 'wizard invisibility' level.
      'spells'[]     :integer (RO)
         The defence/skill of the different spell spheres/spells
         The index should be one of the SPL_* in values.h and/or vme.h
      'zoneidx'      :string (RO)
         The unique database name (in the zone) for this unit.
      'nameidx'      :string (RO)
         The unique database zone name for this unit.
      'symname'      : string (RO)
         The concatenated nameidx@zoneidx to make it easier to use IRL
      'idx'      :integer (RO)
         Constant ID for players and for non-PCs it is the memory pointer
         converted to an integer. If there are 50 cityguards, you can use
         the idx to figure out which one you're looking for. Use 
         findsymbolic(#,#) to quickly find precisely a unit matching a 
         symbolic name and an idx. 
         Be warned, this value change between each reboot, except for players, so do not
         count on it for purposes of persistence across reboots.
      'zone'         :string (RO)
         The name of the zone the unit is in.
      'type'         :integer (RO)
         The type of the unit, see UNIT_ST_* in values.h and/or vme.h
      'loadcount'    :integer (RO)
         Returns the number of units loaded in the game
         of this definition (zoneidx,nameidx / idx)
</pre>
<h2><span class="mw-headline" id="Char_2">Char</span></h2>
<p>If the unitptr.type == UNIT_ST_PC or UNIT_ST_NPC then you can use these flags:
</p>
<pre>      'master'         :unitptr (RW)
         The unitptr to the master that this CHAR is following. See also <a href="./Manual:DIL-Manual-follow()" title="Manual:DIL Manual/follow()">follow()</a>
</pre>
<pre>      ... And a whole slew of other fields.
</pre>
<p><br />
<span id="uobj"></span>
</p>
<pre><b>if the type is UNIT_ST_OBJ</b>
</pre>
<pre>      'objecttype'   :integer (RW)
         The type of an object, see ITEM_* in values.h and/or vme.h for types.
      'value'[]      :integer (RW)
         Values for an object. The meaning of the values differ
         from object type to object type. Index should be [0..4].
         These values are used differently for each object type.
      'objectflags'  :integer (RW)
         Bits specifying special properties for an object. Some
         combinations may not be logical, see OBJ_* in values.h and/or vme.h
      'cost'         :integer (RW)
         The basic cost of an object. (old gold value)
      'rent'         :integer (RW)
         The basic cost of renting an object. Mostly used on very
         special objects. (old gold value)
      'equip'        :integer (RO)
         The position in equipment. This is used by units in a PC/NPC's
         inventory to tell if they are equipped by that PC/NPC.
         use the 'addequip()' and 'unequip()' procedures.
</pre>
<p><br />
<span id="uroom"></span>
</p>
<pre><b>if the type is UNIT_ST_ROOM</b>
</pre>
<pre>      Note: the descr fields of exits are available as standard extra
         keywords, ie. 'north' ,'east',...,'down'.
         Example:
           ex&#160;:= 'north' in self.extra;
</pre>
<pre>      'exit_names'[]  :stringlist (RW)
         The names matching the exit name 'open grate' The index should
         be one of NORTH EAST SOUTH WEST UP DOWN in values.h and/or vme.h
         Example:
           sl&#160;:= self.exit_names[SOUTH];
           act("The $2t slides open as you press the button.",
                A_ALWAYS, activator, sl.[0], null, TO_CHAR);
      'exit_info'[]  :integer (RW)
         Bits specifying the conditions of the exits, see EX_* in
         values.h and/or vme.h The index should be one of NORTH EAST SOUTH WEST
         UP DOWN in values.h and/or vme.h
      'exit_to'[]    :unitptr (RO)
         The unit, the direction exits to. The index should
         be one of NORTH EAST SOUTH WEST UP DOWN in values.h and/or vme.h
         You may not change the directions through DIL programs.
      'roomflags'    :integer (RW)
         Bits specifying properties of the room, see ROOM_FL_* in
         values.h and/or vme.h
      'movement'     :integer (RW)
         The type of movement in the room, see SECT_* in values.h and/or vme.h
</pre>
<p><br />
<span id="upcnpc"></span>
</p>
<pre><b>if the type is UNIT_ST_PC or UNIT_ST_NPC </b>
</pre>
<pre>      'speed'        :integer (RO)
         The current default combat-speed (as seen by wstat)
      'fighting'     :unitptr (RO)
         The unit the PC/NPC is fighting.
      'master'       :unitptr (RO)
         The unit the PC/NPC is following.
      'follower'     :unitptr (RO)
         The first follower of a PC/NPC. There is currently no way
         of finding other followers, except using a foreach loop in
         the local environment.
      'exp'          :integer (RO)
         The number of experience points for PC, or experience
         quality of monster. The exp can be set by the function
         'experience()'
      'charflags'     :integer (RW)
         Bits specifying by spells affects and other PC/NPC affects,
         and many other things, see CHAR_* in values.h and/or vme.h
      'lastroom'     :unitptr (RO)
         The room the player just left.
      'mana'         :integer (RW)
         The amount of mana a PC/CHAR has left.
      'dex_red'      :integer (RO)
         The amount of DEX reduction the PC/NPC suffers due to
         encumbrance or otherwise.
      'endurance'    :integer (RW)
         The amount of endurance a PC/NPC has left.
      'attack_type'  :integer (RW)
         The non-weapon attack type of a PC/NPC.
      'race'         :integer (RW)
         The race of a PC/NPC, see RACE_* in values.h and/or vme.h
      'sex'          :integer (RW)
         The sex of a PC/NPC, see SEX_* in values.h and/or vme.h
      'level'        :integer (RO)
         The level of a PC/NPC.
      'position'     :integer (RW)
         The position of a PC/NPC, see POSITION_* in values.h and/or vme.h
         affected by the 'position_update()' procedure
      'abilities'[]  :integer (RO)
         The abilities of a PC/NPC. Index should be ABIL_* in values.h and/or vme.h
      'weapons'[]    :integer (RO)
         The weapon skills of a PC/NPC. Index should be WPN_* in values.h and/or vme.h
      'opponentcount' :integer (RO)
         The number of opponents the player is fighting.
</pre>
<p><br />
<span id="unpc"></span>
</p>
<pre><b>if the type is UNIT_ST_NPC </b>
</pre>
<pre>      'defaultpos'   :integer (RW)
         The default position of an NPC, see POSITION_* in values.h and/or vme.h
	  'natural_armour'   :integer (RW)
	     The natural armour of the NPC when naked.
      'npcflags'     :integer (RW)
         Some small options for NPC's see NPC_* in values.h and/or vme.h
		       'switched'   :unitptr (RW)
			      Character that is switched into this NPC.
</pre>
<p><br />
<span id="upc"></span>
</p>
<pre><b>if the type is UNIT_ST_PC</b>
</pre>
<pre>      'birth'         :integer (RO)
         The time a PC was created.
	  'editing'         :integer (RO)
	     Is the PC editing?  TRUE for yes FALSE for no.
      'hometown'      :integer (RO)
         The hometown of a PC.
      'pcflags'       :integer (RW)
         The setup of player options. See PC_* in values.h and/or vme.h
      'playtime'      :integer (RO)
         The time a PC has played.
      'skill_points'   :integer (RW)
         The amount of unused skill points the PC has.
      'ability_points' :integer (RW)
         The amount of unused ability points the PC has.
	        'exptol' :integer (RW)
         The amount of experience player needs to level
      'skills'[]     :integer (RO)
         The skills of a PC. Index should be SKI_* in values.h and/or vme.h
      'guild'        :string (RW)
         The guild the PC belongs to.
      'prompt'        :string (RW)
         The players prompt string..
      'crimes'       :integer (RW)
         The number of crimes the PC has.
      'full'         :integer (RW)
         How hungry the PC is.
      'thirst'       :integer (RW)
         How thirsty the PC is.
      'drunk'        :integer (RW)
         How drunk the PC is.
      'quests'       :extraptr (RW)
         The quests a PC is finishing/has finished.
      'info'         :extraptr (RW)
         The info structure of a PC.
      'acc_balance'  : integer (RO)
         If the game is in accounting mode, then this returns the balance
         of the player, what would be shown on balance in wstat &lt;player&gt; acc.
      'acc_total'  : integer (RO)
         If the game is in accounting mode, then this returns the total
         credit of the player, what would be shown on total in wstat
         &amp;ltplayer&amp;gt acc.
</pre>
<p><br />
<span id="built_func"></span>
</p>
 <h3><span class="mw-headline" id="Built-In_Functions:">Built-In Functions:</span></h3>
<pre>    The following are definitions and documentation for the
  built-in functions in DIL. The definitions are not
  definitions 'as such', but serve to distinguish arguments
  in the documentation below.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfasctime"></span>
</p>
<pre>string asctime(i&#160;: integer)
   i&#160;: the time to convert in seconds (<a href="#bvrealtime">realtime</a> variable)
</pre>
<pre>   Returns: The seconds converted into an ascii format date of the following
            form  "Mon Nov 18 18:49:08 1996"
</pre>
<pre>   Example:
      log(asctime(realtime));
</pre>
<pre>&lt;/PRE
</pre>
<p><br />
<span id="bfstrcmp"></span>
</p>
<pre><b>Function:</b>  <i>integer strcmp( s1:string, s2:string)&#160;;</i>
</pre>
<pre>  <b>s1</b>
         first string
  <b>s2</b>
         second string
</pre>
<pre> <b>returns</b>
  <b>-1</b>
         if s1 &lt; s2
  <b>0</b>
         if s1 = s2
  <b>1</b>
         if s1 &gt; s2
</pre>
<p><br />
</p>
<pre>This allows you to compare strings with case sensitivity in place.  If
you don't care about the case of the string use the normal '==' '&gt;',
'&lt;', '&lt;=', '&gt;=', symbols.
<b>example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>if (strcmp("I Care about Capitals",s2)==0))
        {
        sendtext ("You care I can see.&amp;n",self);
        quit;
        }
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
<span id="bfstrncmp"></span>
</p>
<pre><b>Function:</b>  <i>integer strcmp( s1:string, s2:string l :integer)&#160;;</i>
</pre>
<pre>  <b>s1</b>
         first string
  <b>s2</b>
         second string
  <b>l</b>
         amount of significant digits to compare
</pre>
<pre> <b>returns</b>
  <b>-1</b>
         if s1 &lt; s2
  <b>0</b>
         if s1 = s2
  <b>1</b>
         if s1 &gt; s2
</pre>
<p><br />
</p>
<pre>This allows you to compare strings with case sensitivity in place and it
allows you to choose how much of the strings are compared.
<b>example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>if (strcmp("Mark Carper",s2,4)==0))
        {
        sendtext ("Hi Mark how is it going?&amp;n",self);
                quit;
        }
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bftextformat"></span>
</p>
<pre>string textformat(s&#160;: string)
   s&#160;: The text string to format. The string is formatted according to
       the escape format codes as defined in one of the other documents.
</pre>
<pre>   Returns: The formatted string which will automatically adapt to each
            individual player's settings.
</pre>
<pre>   Example:
      ts&#160;:= note.extra.descr;
      rs&#160;:= textformat(ts);
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfsplind"></span>
</p>
<pre>integer spellindex(s&#160;: string)
   s  : The abbreviated or full spell name
</pre>
<pre>   Returns: -1 if no such spell, otherwise it returns the spell index
            for that spell.
</pre>
<pre>   Example:
      s&#160;:= "cu li wo"; /* cure light wounds */
      i&#160;:= spellindex(s);
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfsplinf"></span>
</p>
<pre>string spellinfo(idx&#160;: integer, i1&#160;: integer, i2&#160;: integer, i3&#160;: integer,
                 i4&#160;: integer, i5&#160;: integer, i6&#160;: integer, i7&#160;: integer, )
</pre>
<pre>    idx&#160;: The spell index (SPL_XXX). You might want to use spellindex
          to find this value.
</pre>
<pre>    Returns:
      The full name of the spell, or the empty string if no such spell.
</pre>
<pre>    All the integer parameters are set to the following values:
      i1  : Spell realm (MAG / DIC)
      i2  : Spell sphere (SPL_XXX)
      i3  : Mana usage
      i4  : 0 if a non-offensive spell, non-zero otherwise
      i5  : Resistance required (SPLCST_XXX)
      i6  : Mediums (MEDIA_XXX)
      i7  : Targets (FIND_UNIT_XXX &amp; TAR_XXX)
</pre>
<pre>  Example:
    s&#160;:= "cu li wo"; /* cure light wounds */
    i&#160;:= spellindex(s);
    s&#160;:= spellinfo(i, i1, i2, i3, i4, i5, i6, i7);
    /* s &amp; i1 - i7 now set */
</pre>
<p><br />
<span id="bpbeginedit"></span>
</p>
<pre><b>Function:</b>  <i>beginedit ( u&#160;: unitptr);</i>
</pre>
<pre>  <b>u</b>
         the PC unit doing the editing
  <b>return</b>
         When done  editing it returns SFB_EDIT and activator is set to PC
</pre>
<pre>The 'BEGINEDIT' function sets a PC into editing mode.  while in edit mode
the PC field 'editing is set to true.  Once the PC is done editing a 'SFB_EDIT'
message is sent to the unit editing to continue on with the DIL.
If for some reason the PC needs to break
out of the editor before it is done editing then the Dil needs to call
the 'killedit' function
<a href="#sect-beginedit">interrupt editing before done</a>
</pre>
<pre><b>example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin edextra ();
var
        temp:string;
code
{
        beginedit (self);
        wait(SFB_EDIT,self==activator)&#160;;
        temp:=textformat(argument);
        addextra (self.extra,"general",temp);
        quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
The previous DIL is an example of how you could make a command to set the
general extra which is the characters description when you do 'look player'
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfcancarry"></span>
</p>
<pre>integer can_carry(ch&#160;: unitptr, u&#160;: unitptr, n&#160;: integer)
   ch&#160;: The character to check
   u  : The unit to check if he can carry.
   n  : How many copies of that unit.
</pre>
<pre>   Returns: 0 if 'ch' can carry 'n' times 'u'.
            1 if 'n' items are too many (his hands are full)
            2 if 'n' times 'u' are too heavy
</pre>
<pre>   Example:
</pre>
<pre>      i&#160;:= can_carry(activator, item, 1);
</pre>
<pre>      if (i == 1)
        exec("say Your hands are full!", self);
      else if (i == 2)
        exec("say You cant carry that much weight.", self);
      else
        exec("give "+item.name+" to "+activator.name, self);
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bffits"></span>
</p>
<pre>string fits( char&#160;: unitptr, obj&#160;: unitptr, pos&#160;: integer );
   char: Character which we want to test if obj can be fitted upon
   obj:  The object we want to see if fits char.
   pos:  -1 or WEAR_XXX
   Returns: Empty string if ok, or a textual description of the size problem.
</pre>
<pre>   Fits tests if "obj" can be worn by "char" in position "pos". If
   pos is -1, then fits automatically figures out the default worn
   position for "obj".
</pre>
<pre>   Example:
</pre>
<pre>      s&#160;:= fits(self, obj, -1);
      if (s&#160;!= "")
        exec("say Don't buy it, its "+s, self);
</pre>
<p><br />
<span id="bfreplace"></span>
</p>
<pre><b>Function:</b>  <i>string replace( t :string, n&#160;: string, o&#160;: string);</i>
</pre>
<pre>  <b>t</b>
         the target string you want to replace
  <b>n</b>
         what you want to replace the target with
  <b>o</b>
         the original string
  <b>return</b>
         the string with the old string replaced by the new string
</pre>
<pre>This function replaces all occurences of a string in another string with a
new string.
<b>Example:</b>
<i>"Jafar %t% %l%"&#160;:= replace(%n%,pc.name,"%n% %t% %l%");</i>
<i>"Jafar the human %l%"&#160;:= replace(%t%,pc.title,"Jafar %t% %l%");</i>
<i>"Jafar the human 1"&#160;:= replace(%l%,itoa(pc.vlevel),"Jafar the human %l%");</i>
</pre>
<p><br />
<span id="bfrestore"></span>
</p>
<pre><b>Function:</b>  <i>unitptr restore( filename&#160;: string , u&#160;: unitptr );</i>
</pre>
<pre>  <b>filename</b>
         The name of the Unit file
  <b>u</b>
         The Unit you want to restore into or null if none
  <b>Return</b>
         if 'u' null returns a pointer to the Unit loaded, if 'u' not null returns null and loads Units from the specified file into the unit 'u'
</pre>
<pre>restore loads a copy of a unit or units which were previously saved with the
'store' command. Just as with "load", the unit is put inside the unit which
executes the restore command unless the 'u' argument is not null.  If the 'u'
argument is an unitptr like room, object, npc, or pc the items restored will be
placed inside the 'u' Unit..
<b>Note</b>, It is only possible to restore items as long as the main-database
contains a reference for the unit 'name@zone'.  Use 'Store' and 'Restore'
sparingly, remember that items saved in player's inventories are automatically
saved in this instance.
The 'store' and 'restore' are perfect for operations such as mud mailing
objects from player to player, storage devices for players that will keep
inventory through a reboot.  Even the ability to save a players inventory while
they fight in an arena and restore it to them undamaged when finished.  Finally
it could be used to save a donation room through reboots since it can be used on
a room to store the contents of a room any NPC or objects in the room would be
saved through reboot.
<b>Disk access is always slow</b>.
If you use 'Restore' on a continuous basis always attempt to keep file sizes to
a minimum for quick loading.  Otherwise you might cause serious delays on the
server.  If the Dil that uses Restore saves at certain times try to make it so
the saves are spread out over as large amounts of time as possible.
</pre>
<pre><b>Example 1:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin chest_load ();
var
        waist:unitptr;/*to hold the null returned in this example*/
        chest:unitptr;/*pointer to the storage chest*/
code
{
chest:=load ("chest@myzone");/*get the container*/
if (chest==null)
        {
        log ("Error");/*log an error*/
        quit;
        }
</pre></i><i><pre>waist:=restore("chest."+self.zoneidx,chest);
/*
restore given filename into chest
waist can be ignored in this dil since it is not used.
*/
link (chest, self);/*link chest into room*/
quit;/*dil load routine done destroy self.*/
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>Example 2:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin chest_load ();
var
        chest:unitptr;/*item to be loaded*/
code
{
chest:=restore("chest."+self.zoneidx,null);/*restore into chest*/
if (chest== null)/*see if something was restored*/
        chest:=load("donate_chest@"+self.zoneidx);
        /*load a new one if there is nothing restored*/
</pre></i><i><pre>link (chest, self);/*link item into room*/
quit;/*destroy the load dil.*/
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>Note:</b>  Example 1 is to be used if 'storall' was used not storing a container.
Example 2 is for items stored with 'store' with the container saved as
well.
<b>See Also</b>
<a href="#bpstore">Store a Unit to a Unit file</a> and
<a href="#bfdelunit">Delete a Unit file</a>.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
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
</pre>
<p><br />
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
</pre>
<p><br />
<span id="bfmid"></span>
</p>
<pre><b>Function:</b>  <i>string mid ( o&#160;: string, s&#160;: integer, e&#160;: integer );</i>
</pre>
<pre>  <b>o</b>
         the original string to be parsed
  <b>s</b>
         The starting point of the string to be parsed out
  <b>e</b>
         the ending point of the string to be parsed out
  <b>return</b>
         the portion of the string defined by the 's' and 'e' values
</pre>
<pre>This function parses the string passed to it and returns the portion of the string
 defined by the start value and the end value that is also passed to the function.
<b>Example:</b>  <i>"rock"&#160;:= mid ("sprocket",3,6);</i>
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfmonstr"></span>
</p>
<pre>string moneystring(amt&#160;: integer, verbose&#160;: integer)
   amt    : The amount of money
   verbose: True if an expanded string (copper pieces) or false
            if abbreviated money types (cp).
   result&#160;: The moneystring for the given currency.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfeq"></span>
</p>
<pre>unitptr equipment ( u&#160;: unitptr , i&#160;: integer )
   u&#160;: The character to search.
   i&#160;: What equipment to find, any of the WEAR_XXX macros.
   result: Returns the unit on 'u' which is equipped on position 'i'.
           See WEAR_* in values.h and/or vme.h
</pre>
<p><br />
<span id="bftolower"></span>
</p><p><br />
</p>
<pre><b>Function:</b> <i>string tolower ( s&#160;: string );</i>
   <b>s</b>
         String to lower case
  <b>return</b>
         the string passed in lower cased
</pre>
<pre>This function returns a copy of the string passed in but with out capitals.
 <b>Example:</b> <i>"hello!"&#160;:=  tolower("HELLO!");</i>
</pre>
<p><br />
<span id="bftoupper"></span>
</p>
<pre><b>Function:</b>  <i>string toupper ( s&#160;: string );</i>
</pre>
<pre>  <b>s</b>
         String to lower case
  <b>return</b>
         the string passed in lower cased
</pre>
<pre>This function returns a copy of the string passed in with all characters changed
to be capitalized.
<b>Example:</b>  <i>"HELLO!"&#160;:= toupper ("hello!");</i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfvis"></span>
</p>
<pre>integer visible(u1&#160;: unitptr, u2&#160;: unitptr)
   u1: The character who is looking at u2
   u2: The unit which the character u1 is trying to see.
   return: TRUE if u1 can see u2, FALSE otherwise.
   Example: if (visible(self, victim)) ...
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfop"></span>
</p>
<pre>integer opponent(u1&#160;: unitptr, u2&#160;: unitptr)
   u1, u2: Two characters
   return: TRUE if u1 is in combat with u2, FALSE otherwise.
   Example: if (opponent(self, victim)) ...
</pre>
<pre>   When in a combat, you are usually only melee-attacking one opponent,
   although you may have many other opponents. This function lets you
   check if you are directly / indirectly an opponent to another unit.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfpurse"></span>
</p>
<pre>integer purse(u&#160;: unitptr, coinage&#160;: integer)
   u&#160;: The unit to check
   coinage: The money type (e.g. gold, silver), one of IRON_PIECE, etc.
   Returns: The number of such units found.
   Example: if (purse(self, PLATINUM_PIECE) &gt; 10)
              exec("say I am loaded with platinum!", self);
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfatoi"></span>
</p>
<pre>integer atoi ( s&#160;: string )
   s&#160;: A string with a number.
   return: The number in the string.
   Example: i&#160;:= atoi("42");
</pre>
<p><br />
<span id="bfcheckpassword"></span>
</p>
<pre><b>Function:</b>  <i>integer check_password( u&#160;: unitptr, s&#160;: string )&#160;;</i>
</pre>
<pre>  <b>u</b>
         the unit that you want to check the password of
  <b>s</b>
         the password you are using to check
  <b>Return</b>
         Returns an integer TRUE if pcname is the units password FALSE if not
</pre>
<pre>This function checks the string against the units password and returns TRUE
if they match.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>if (not check_password(pc,arg))
        {
        sendtext (arg+" is not "+pc.name"'s password.",self);
                quit;
        }
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfcomm"></span>
</p>
<pre>integer command ( cmd&#160;: string or integer )
   cmd&#160;: A string of the full typed command, e.g. "push" or "say".
         Alternatively you can specify one of the macros defined in
         values.h and/or vme.h, e.g. CMD_SAY
 return: Whether the command specified by the activator is the one of
         the argument.
</pre>
<pre>It is noteworthy, that unlike simple compares like this;
</pre>
<pre>	if ("spook" in cmdstr) {
	...
	...
	}
or
	if (cmdstr == "spook") {
	...
	...
	}
</pre>
<pre>where the first will activate even if the cmdstr is "nospook", and the
second only if cmdstr equals the word "spook" to the letter, the
following construct will activate as long as the contents
of cmdstr doesn't conflict with cmd;
</pre>
<pre>	if (command("spook")) {
	...
	...
	}
</pre>
<pre>ie, it will receive the same kind of treatment as a 'regular' command.
That means that you provide ease of use to the user (allowing shorthand
notation), while securing that you're doing what the user wants.
<strong>CAVEAT</strong> Builder:
If you use a string argument as cmd, be sure that
there are no white-space in it, ie, that the argument does only
consist of letters.
</pre>
<pre>Example:
    command("spook");
</pre>
<pre>    is a valid string, while this construct;
</pre>
<pre>    command("spook him");
</pre>
<pre>    is NOT valid. The reason of that is that cmdstr only contains the
    FIRST word of the input from the player, and thus the latter
    construct could never evaluate to true. This should be evident
    taking the above information into account, as "spook him" could
    never equal "spook" (which would indeed be the text in cmdstr
    if the player entered the string "spook him".)
</pre>
<p><br />
<span id="bfdelstr"></span>
</p>
<pre><b>Function:</b>  <i>integer delstr( filename&#160;: string )&#160;;</i>
</pre>
<pre>  <b>filename</b>
         The name of the String file to be deleted
  <b>Return</b>
         Returns an integer TRUE if deleted FALSE if not
</pre>
<pre>The delstr is used to delete files that are used with the 'loadstr' and
'savestr'       functions.  The delstr function will only delete files that
each individual Zone has access to which is set up in the Zonelist file in the
VME etc directory.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin news|del ("arg&#160;: string /*filename to be deleted);
var
        ret:integer;/*to hold the return value if deleted or not*/
code
{
ret:= delstr("news.txt");
if (!ret)
        {
        log ("File not deleted.");
        quit;
        }
</pre></i><i><pre>sendtext ("News file deleted[&amp;]n",self);
quit;/*dil delete routine done
}
dilend
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also</b> <i>
<a href="#bfloadstr">Load String file</a> and
<a href="#bfsavestr">Save String file</a></i>
</pre>
<p><br />
<span id="bfdelunit"></span>
</p>
<pre><b>Function:</b>  <i>integer delunit( filename&#160;: string )&#160;;</i>
</pre>
<pre>  <b>filename</b>
         The name of the Unit file to be deleted.
  <b>Return</b>
         Returns an integer TRUE if deleted FALSE if not delunit is used to delete files that are used with the 'Restore' and 'store' functions.
</pre>
<pre><b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin chest_del ("arg&#160;: string /*filename to be deleted*/);
var
        ret:integer;/*to hold the return value if deleted or not*/
code
{
ret:= delstr("chest.file");
if (!ret)
        {
        log ("File not deleted.");
        quit;
        }
</pre></i><i><pre>sendtext("Chest file deleted[&amp;]n",self);
quit;/*dil delete routine done
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also</b>
<a href="#bfrestore">Restore a Unit from a Unit file</a> and
<a href="#bpstore">Store Units to a Unit file</a>.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfdd"></span>
</p>
<pre>integer dildestroy( s&#160;: string, u&#160;: unitptr )
   s&#160;: name of dil template to delete.
   u&#160;: unit to remove program from.
   return: Whether a program using a template with same name as in 's'
           attached to unit 'u' was deleted.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfdf"></span>
</p>
<pre>integer dilfind( s&#160;: string, u&#160;: unitptr )
   s&#160;: name of dil template to find.
   u&#160;: unit to find program in.
   return: Whether a program using a template with same name as in 's'
           attached to unit 'u' was found.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfitoa"></span>
</p>
<pre>string itoa ( i&#160;: integer )
   i&#160;: A number.
   return: A string with the number.
   Example: s&#160;:= itoa(42);
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span id="integer_isaff_(_u_:_unitptr_,_i_:_integer_)"></span><span class="mw-headline" id="integer_isaff_.28_u_:_unitptr_.2C_i_:_integer_.29">integer isaff ( u&#160;: unitptr , i&#160;: integer )</span></h1>
<pre> u&#160;: A unit to be examined.
 i&#160;: An id of an affect, see ID_* in values.h and/or vme.h
 result: TRUE, if unit 'u' is affected by affect id 'i'
</pre>
<p><b>Examples:</b>
</p>
<pre> if (isaff(self, ID_BLIND_CHAR))
   sendtext("You're blinded", self);
</pre>
<p>This command scans the unit 'u' for any affect matching the id 'i'
and returns TRUE if one is found.
</p><p>See also:
</p>
<pre> &gt; <a href="./Manual:DIL-Manual-subaff()" title="Manual:DIL Manual/subaff()">subaff()</a>
 &gt; <a href="./Manual:DIL-Manual-addaff()" title="Manual:DIL Manual/addaff()">addaff()</a>
 &gt; <a href="./Manual:DIL-Manual-getaffects()" title="Manual:DIL Manual/getaffects()">getaffects()</a>
</pre>
<p><br />
<span id="bfislight"></span>
</p>
<pre><b>Function:  </b><i>integer islight ( u&#160;: unitptr )</i>
</pre>
<pre>  <b>u</b>
         Unit that you are checking
  <b>returns</b>
         <i>TRUE' if item is a light, 'FALSE' if it is notway to small', 'to small', 'way to large', 'to large', or null if fits</i>
</pre>
<pre>Simply checks the item to see if it is a light.
</pre>
<p><br />
<span id="bfisplayer"></span>
</p>
<pre><b>Function:</b>  <i>integer isplayer( pcname&#160;: string )&#160;;</i>
</pre>
<pre>  <b>pcname</b>
         the name of the player being checked
  <b>Return</b>
         Returns an integer TRUE if pcname is a player FALSE if not
</pre>
<pre>This function is used to find out if a string you pass to it is a player or not.
This can be used and is used to find out if a player is truly a player that an
Administrator is deleting with out having that player on line.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>if (not isplayer(arg))
        {
        sendtext (arg+" is not a character.&amp;n",self);
        quit;
        }
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfisset"></span>
</p>
<pre>integer isset ( i&#160;: integer , bit&#160;: integer )
   i&#160;: An integer to examine.
   bit&#160;: A set of bits to match.
   return: TRUE, if bits in 'bit' is set in 'i'.
   Example: if (isset(self.manipulate, MANIPULATE_TAKE)) ...
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfpaychk"></span>
</p>
<pre>integer paycheck( u1&#160;: unitptr, u2:unitptr)
   u1&#160;: unit to check against
   u2&#160;: player to check access for
   return: TRUE if the player u2 has pay access to the location
	in which the unit u1 is located. FALSE if the player does not
	have access. Using non-players as u2 will return TRUE. The
	function checks if the player has pay-access (if needed) to
	the zone in which u1 is located.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bffindu"></span>
</p>
<pre>unitptr findunit ( u&#160;: unitptr , s&#160;: string , i&#160;: integer , l&#160;: unitptr )
     u&#160;: The unit the local environment is relative to.
     s&#160;: A string with name of the unit to find.
     i&#160;: The environment, where to look for it, see FIND_UNIT_*
         in values.h and/or vme.h.
     l&#160;: An optional list of units to search.
 return: If the unit is found, the function returns that unit.
          Returns null if nothing found.
</pre>
<pre>  The first argument is typically the char that's looking for something,
  i.e. if Mary needs a spoon to stir the pot, she'll be the first argument.
</pre>
<pre>  The second argument is what you're looking for, represented by a string.
  In the above mentioned example, that'd be "spoon".
</pre>
<pre>  For the second or third argument, you have a choice, as you'll only need to
  use one of them, and let the other be 0 or null.  For instance, if you have
  a pointer to Mary's kitchen utensil pot, you can use the line:
</pre>
<pre>     findunit(mary, "spoon", 0, pot);
</pre>
<pre>  Or you can just let her look around for it with:
</pre>
<pre>     findunit(mary, "spoon", FIND_UNIT_INVEN or FIND_UNIT_SURRO, null);
</pre>
<pre>  You can use all the FIND_UNIT_ values defined in values.h and/or vme.h, if you
  want to look for something for example within the zone (FIND_UNIT_ZONE), the
  entire world (FIND_UNIT_WORLD) (you rarely need to do that, it's mainly for
  tell etc.), or just the inventory or equipment of the char in question
  (FIND_UNIT_INVEN and FIND_UNIT_EQUIP).  Finally, as in the example above,
  you can look in the room of the char (FIND_UNIT_SURRO).
</pre>
<pre>  Using FIND_UNIT_PAY or FIND_UNIT_NOPAY in this function will be ignored.
</pre>
<pre>The flags for findunit, intuitively:
</pre>
<p><br />
</p>
<pre>FIND_UNIT_EQUIP:
  The objects you will see with `equipment'
  Assumes first argument to findunit is a char.
</pre>
<p><br />
</p>
<pre>FIND_UNIT_INVEN:
  The objects you will see with `inventory' or `look in bag'
</pre>
<p><br />
</p>
<pre>FIND_UNIT_SURRO:
  The objects you can see, and get with `get',
  or the characters you can `poke'&#160;:-)
</pre>
<p><br />
</p>
<pre>FIND_UNIT_ZONE:
  As FIND_UNIT_WORLD, only more local.
</pre>
<p><br />
</p>
<pre>FIND_UNIT_WORLD:
  Any object in the entire world.  Does NOT start looking close to the
  object of findunit's first argument, but rather somewhat randomly.
</pre>
<p><br />
</p>
<pre>On top of these, the following (new) values are defined:
</pre>
<p><br />
</p>
<pre>FIND_UNIT_IN_ME:
  Anything inside of the object of the first argument.
</pre>
<p><br />
</p>
<pre>FIND_UNIT_HERE:
  Anything `here', i.e. in object or around it (same as IN_ME + SURRO)
</pre>
<p><br />
</p>
<pre>FIND_UNIT_GLOBAL:
  ANYTHING, starting close to object and working out.
</pre>
<p><br />
</p><p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bffindru"></span>
</p>
<pre>unitptr findrndunit( u&#160;: unitptr, sv&#160;: integer, uf&#160;: integer)
   Returns: A pointer to a random unit, or null
   u  : The unit pointer which the search is relative to.
   sv&#160;: The search-location, a value (not bit vector) of FIND_UNIT_XXX
   uf&#160;: Bit vector. The unit flags which can match of UNIT_ST_XXX
</pre>
<pre>   Example: u&#160;:= findrndunit(self, FIND_UNIT_ZONE, UNIT_ST_PC|UNIT_ST_NPC);
</pre>
<pre>   This routine returns a random unit. Notice how the 'uf' lets you
   specify exactly what unit types to look for. The 'sv' is not a
   bit vector, although FIND_UNIT_XXX is usually used as such. If
   you need to search multiple environments, then call the routine
   once for each.
</pre>
<pre>   Using FIND_UNIT_PAY or FIND_UNIT_NOPAY in this function will
   pick a random player which in addition to being in the search
   environment also is registered as valid payer (or not). Asking
   for a room would yield a random room registered to be accessible
   for paying players only (or not). Asking for objects would
   return no unit (null).
</pre>
<p><br />
<span id="bffilesize"></span>
</p>
<pre><b>Function:</b>  <i>integer filesize ( filename :string);</i>
</pre>
<pre>  <b>file</b>
         The file name you want to check
  <b>return</b>
         a file size in bites 0 if no file
</pre>
<p><br />
</p><p><br />
</p>
<pre>This function does exactly what it says it does it checks a files size.
</pre>
<pre><b>Example DIL:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin notebook ();
code
{
        ns&#160;:= filesize (self.name+"notebook");
        if ( ns &gt;500000)
        {
                sendtext ("Your notebook is full.&amp;n",self);
                quit;
        }
        else if ( ns &gt; 250000)
        {
                sendtext ("Your notebook is more than half full.&amp;n",self);
                quit;
        }
        else if (ns &gt;125000)
        {
                sendtext ("Your Notebook is only 1/4 full.&amp;n",self);
                quit;
        }
        else if (ns &gt;0)
        {
                sendtext ("Your notebook is less than 1/4 full.&amp;n",self);
                quit;
        }
        else
        {
                sendtext ("You don't have anything in your Notebook.&amp;n",self);
                quit;
        }
</pre></i><i><pre>}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
The previous DIL example shows how you could use the 'filesize' instruction to
check the size of a player stored notebook.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
unitptr findroom ( s&#160;: string )
   s&#160;: Symbolic name of room.
   return: A pointer to the room, or null
   Example: findroom("inn@udgaard")
</pre>
<p>Will return the unitptr to the room. If the symbolic name is not a room then NULL will
be returned.  Using findsymbolic(#) is equally efficient and does the same except it
returns any type. This function is really mostly here for historical reasons.
</p>
<pre>unitptr findsymbolic ( s&#160;: string )
   s&#160;: Symbolic name of the unit to find (player, room, object, NPC)
   return: A pointer to an instance of the unit, or null.
   Example: findsymbolic("bread@midgaard")
</pre>
<p>This routine supplements findunit() and findsymbolic(#,#,#). It comes in handy, if it is
important to get a unitptr to a unit in the world.  This is super fast
and a great routine if it doesn't matter where in the world the unit is.
Otherwise, look at the findsymbolic(u,s,i) below  If for example,
Mary needs to send a message to John the Lumberjack,  then she should NOT
use the findunit() since it may locate a different John - even a player!
If she instead locates him using findsymbolic("john@haon_dor") she will be
certain that it is in fact her husband, and not the player John Dow from
Norway. If there was two john@haon_dor in the game, she'd get a random one of
them (but there's only one John and if there was two it wouldn't really matter
which one she would activate). This function also will return rooms and players (which it did
not do in the past), making findroom somewhat superfluous.
</p>
<pre>unitptr findsymbolic ( u&#160;: unitptr, s&#160;: string, i&#160;: integer )
   u&#160;: Search is relative to this unit.
   s&#160;: Symbolic name of the NPC or Object to find.
   i&#160;: FIND_UNIT_XXX bit vector of places to search.
   return: A pointer to an instance of the unit, or null.
   Example: findsymbolic(self, "bread@midgaard", FIND_UNIT_INVEN)
</pre>
<p>This routine supplements findroom, findunit and findsymbolic(#).  
It will simply return the first unit matching the symbolic name. 
It comes in handy, if it is important to get a correct reference to a unit somewhere
relative to 'u'.  If for example, Mary needs to check if she has her own
cooking pot, then she should NOT use the findunit since it may locate a
different pot, not belonging to Haon-Dor but to some other zone.  If she
instead locates it using findsymbolic(self, "pot@haon_dor", FIND_UNIT_IN_ME)
she would be certain that it is in fact her own cooking pot that she is
carrying around, and not some other pot from a Joe Blow's zone.
</p><p><br />
</p>
<pre>unitptr findsymbolic ( s&#160;: string, idx&#160;: integer )
   s&#160;: Symbolic name of the unit to find (player, room, object, NPC)
   idx&#160;: is the index to match (find precisely the right city guard), see unitptr.idx
   return: A pointer to an instance of the unit, or null.
   Example: findsymbolic("guard@midgaard", 71262816721)
</pre>
<p>This routine helps you find a precise unique unit in the world. So imagine a
bounty hunter. Locks on a city guard that has committed a crime. Because you
cannot secure a unitptr not in your local environment how can you find the right
cityguard in a city of 100? So when you first catch the unit, store its symname and 
idx. The use this function to retrieve it again. For players it will find the online
player regardless of the idx.
</p><p>Example:
</p>
<pre> // Presume target is pointing to a particular cityguard
 s&#160;:= target.symname; // Save the symbolic name
 i&#160;:= target.idx;
 // Do stuff. Wake up 9 hours later. Find the target again like this:
 target&#160;:= findsymbolic(s, i);
 // and if the guard is still alive you'll get your pointer back.
</pre>
<p><br />
<span id="bfgword"></span>
</p>
<pre>string getword ( var s&#160;: string )
   s&#160;: A string with zero or more words separated by space.
   return: The first word of the string.
</pre>
<pre>   NB: The argument string has the returned word removed.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfgwords"></span>
</p>
<pre>stringlist getwords ( var s&#160;: string )
       s&#160;: A string with zero or more words separated by space.
   return: A stringlist where each string was a word in 's'.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfghead"></span>
</p>
<pre>unitptr ghead ( )
</pre>
<pre>return the first unit in the global list which will be the last
char to have logged on.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span id="stringlist_split_(_var_s_:_string,_var_t_:_string)"></span><span class="mw-headline" id="stringlist_split_.28_var_s_:_string.2C_var_t_:_string.29">stringlist split ( var s&#160;: string, var t&#160;: string)</span></h1>
<pre> s&#160;: A string with zero or more words separated by var t.
 return: A stringlist where each string was a word in 's' separated by string 't'.
</pre>
<p>You can use '&amp;x' to split a string by line.  This is very useful when reading in files with 'loadstr'.
</p><p><br />
<span id="bfleft"></span>
</p>
<pre><b>Function:</b>  <i>string left ( o&#160;: string, l&#160;: integer );</i>
</pre>
<pre>  <b>o</b>
         the original string to be parsed
  <b>l</b>
         The amount of characters to parse out
  <b>return</b>
         the left portion of the string with length l
</pre>
<pre>This function parses the string passed to it and returns the number
of characters defined in its second argument.
</pre>
<pre><b>Example:</b>  <i>"short"&#160;:= left ("shorten me",5);</i>
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin aware describe (arg:string);
var
        side:string;
        oneword:stringlist;
        location:string;
        ln:integer;
        args:stringlist;
        temp:string;
        i:integer;
        x:extraptr;
code
{
        if (self.type!=UNIT_ST_PC)
                quit;
        if (self.position &lt;POSITION_SLEEPING)
        {
        act ("Recover first and then you can describe your body parts.",
        A_ALWAYS,self,null,null,TO_CHAR);
                quit;
        }
</pre></i><i><pre>        args:=getwords(arg);
        ln:=length(args);
        if ((ln&lt;1) or (ln&gt;2))
        {
        sendtext ("No such location to describe.",self);
        quit;
        }
        else if (ln&gt;1)
        goto two_word;
</pre></i><i><pre>        :one_word:
</pre></i><i><pre>        if ((arg==left("help",length(arg))) or
                (arg==""))
                goto hlp_dscr;
</pre></i><i><pre>        oneword&#160;:= {"arms","butt","ears","eyes","face","feet",
		            "general","hair","hands","head","legs",
					"mouth","neck","nose","nostrils","teeth",
					"toes","tongue"};
</pre></i><i><pre>        i&#160;:= 0;
        ln&#160;:= length(args.[0]);
        temp:="ERROR";
        while (i&lt;18)
        {
                if (args.[0]==left(oneword.[i],ln))
                {
                        temp&#160;:= oneword.[i];
                        break;
                }
                i&#160;:= i+1;
        }
</pre></i><i><pre>        if (temp=="ERROR")
        {
                sendtext ("No such location to describe.",self);
                quit;
        }
</pre></i><i><pre>        goto describe;
</pre></i><i><pre>        :two_word:
</pre></i><i><pre>        oneword&#160;:= {"arm","leg","foot","hand","eye","ear"};
        temp&#160;:= "ERROR";
        ln&#160;:= length(args.[0]);
        if (args.[0] == left("left",ln))
                side:="left";
        else if (args.[0] == left("right",ln))
                side:="right";
        else
        {
                sendtext ("No such location to describe.",self);
                quit;
        }
</pre></i><i><pre>        i&#160;:= 0;
        while (i&lt;6)
        {
                if (args.[1]==left(oneword.[i],ln))
                {
                        temp&#160;:= oneword.[i];
                        break;
                }
                i&#160;:= i+1;
        }
</pre></i><i><pre>        if (temp=="ERROR")
        {
                sendtext ("No such location to describe.",self);
                quit;
        }
</pre></i><i><pre>        temp&#160;:= side+" "+temp;
</pre></i><i><pre>        :describe:
        if (temp=="General")
                location&#160;:= "";
        else
                location&#160;:= temp;
</pre></i><i><pre>        x&#160;:= location in self.extra;
        if (x!=null)
          if (location=="")
sendtext("your Current description for your body is:  &amp;n"+x.descr+"&amp;n",self);
        else
sendtext("your Current description for your "+location+"is:  &amp;n"+x.descr+"&amp;n",self);
        if (location=="")
sendtext ("Enter a text you would like others to see when they look at your body.&amp;n",self);
        else
sendtext ("Enter a text you would like others to see when they look at your "+location+".&amp;n",self);
</pre></i><i><pre>        beginedit (self);
        wait(SFB_EDIT,self==activator)&#160;;
        temp&#160;:= textformat(argument);
        oneword:={""};
        subextra(self.extra,location);
        addstring (oneword, location);
        addextra (self.extra,oneword,temp);
        sendtext ("Description added.&amp;n",self);
        quit;
</pre></i><i><pre>        :hlp_dscr:
</pre></i><i><pre>        sendtext ("&amp;nCorrect usage of 'describe':&amp;n&amp;n",self);
        sendtext ("describe &lt;position&gt;&amp;n&amp;n",self);
        sendtext("&lt;position&gt; being one of the following:&amp;n&amp;n",self);
        sendtext( "arms        butt        ears        eyes&amp;n"+
                  "face        feet        General     hair&amp;n"+
                  "hands       head        left arm    left leg&amp;n"+
                  "left foot   left hand   left eye    left ear&amp;n"+
                  "legs        mouth       neck        nose&amp;n"+
                  "nostrils    right arm   right leg   right foot&amp;n"+
                  "right hand  right eye   right ear   teeth&amp;n"+
                  "toes        tongue&amp;n&amp;n",self);
        sendtext ("Example:  &amp;n&amp;n",self);
        sendtext ("describe left leg&amp;n",self);
        quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bflen"></span>
</p>
<pre>integer length ( a&#160;: string or stringlist )
       a&#160;: a string or stringlist to examine.
   return: The length of the string in characters, or the number
           of strings in a list.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfload"></span>
</p>
<pre>unitptr load ( s&#160;: string )
   s&#160;: Symbolic name of unit.
   return: A pointer to the unit, or null
   Example: load("garlic@midgaard")
   The loaded unit is automatically placed inside the object
   which loaded it.  Use for example the link command to move
   it into other units.
</pre>
<p><br />
<span id="bfloadstr"></span>
</p>
<pre><b>Function:</b>
<i>integer loadstr( filename&#160;: string , buff&#160;: string );</i>
</pre>
<pre>  <b>filename</b>
         The name of the string file to be loaded
  <b>buff</b>
         The string that you wish to read the file contents into
  <b>Return</b>
         <i>FILE_LOADED, FILE_NOT_FOUND, FILE_OUT_OF_MEMORY,or FILE_TO_LARGE</i>
</pre>
<pre>Loadstr is used to load strings from disk that were saved either by savestr
or any text editor.
The 'loadstr' is perfect for operations such as
on-line edited newspaper, a lottery where the tickets are sold to players,
creating smarter NPC's that can remember through reboots who they are hunting,
Dil based teachers, message boards, mail system, news command., zone or
room based help,  competition boards, and much much more.
<b>Disk access is always slow</b>.
attempt to keep file sizes to a minimum for quick loading.  Otherwise you
might cause serious delays on the server.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin news_load ();
var
        ret:integer;/*to hold the return value if loaded or not*/
        buff:string;/*to hold the loaded string*/
code
{
ret:= loadstr("news.txt",buff);
if (!ret)
        {
        log ("File not read.");
        quit;
        }
</pre></i><i><pre>sendtext(buff+"[&amp;]n",self);
quit;/*dil load routine done destroy self.*/
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also</b> <i>
<a href="#bfdelstr">Delete a String file</a> and
<a href="#bfsavestr">Save String file</a></i>
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bforoll"></span>
</p>
<pre>integer openroll( dice&#160;: integer , end&#160;: integer )
   dice&#160;: The size of the dice being rolled.
   end  : The margin for the open-ended roll.
   return: A random integer in approximately +/- 2^31 in worst case.
   Example: i&#160;:= openroll(100,5); The "100" roll continues on values
            96 - 100 and on values 1 - 5.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bfpathto"></span>
</p>
<pre>integer pathto( from&#160;: unitptr, to&#160;: unitptr )
   from   : The unit which the path is taken from
   to     : The unit which the path is taken to
   returns: DIR_XXX from values.h and/or vme.h.
   Example: i&#160;:= pathto(self, findroom("inn@midgaard"));
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bppagestring"></span>
</p>
<pre>pathto(buff&#160;: string, u&#160;: unitptr )
   buff   : The string that is to be paged to the player.
	 u			: The unitptr the buff is to be paged for.
   returns: nothing
	 example:
	 pagestring (buff,self);
	 would format the buff string to the player so the buff text doesn't scroll
	 off the screen until after the player presses enter.
</pre>
<p><br />
<span id="bfright"></span>
</p>
<pre><b>Function:</b>  <i>string right ( o&#160;: string, r&#160;: integer );</i>
</pre>
<pre>  <b>o</b>
         the original string to be parsed
  <b>r</b>
         The amount of characters to parse out
  <b>return</b>
         the right portion of the string with length r
</pre>
<pre>This function parses the string passed to it and returns the number of characters
from the right defined in its second argument.
<b>Example:</b>  <i>"Easy"&#160;:= right ("This is Easy",4);</i>
</pre>
<pre>---~---~---~---~---~---~---~---~---
integer rnd ( i1&#160;: integer , i2&#160;: integer )
   i1&#160;: Start of range.
   i2&#160;: End of range.
   return: A random integer in an interval from 'i1' to 'i2'.
   Example: i&#160;:= rnd(1,10);
</pre>
<p>See also:
</p>
<pre> &gt; openroll()
</pre>
<p><br />
<span id="biproc"></span>
</p>
 <h3><span class="mw-headline" id="Built-In_Procedures:">Built-In Procedures:</span></h3>
<pre>    DIL features some built-in procedures that allows you increased control over
  in-game data structures and event handling. Once such procedure (used above)is
  'exec()'. The inline procedures are used as any other procedure by typing its
  name, followed by a list of argument expression enclosed in parentheses. The
  return types of the expressions used for built-in procedure calls are checked
  by the compiler.
</pre>
<pre>    DIL also lets you call templates defined in the current or other zones.  The
  naming of templates follows the normal naming convention for zone, using the
  'name@zone' as a symbolic name for a procedure.  Before being able to use
  external procedures, you must define their name and type in a separate
  'external' section in the template.  The declaration in the 'external' section
  should match the original declaration of the referenced program. You can define
  the number and type of arguments the template take, by listing them inside the
  declaration parenthesis (as well as in the original declaration of that template)
  (see example below)
</pre>
<pre><b>Example:</b>
</pre>
<pre>

   dilbegin bar(s:string);
   code
   {
     exec("say "+s,self);
     return;
   }
   dilend
</pre>
<pre>

   dilbegin foo();
   external
     someproc@hades1();
     bar(s:string);
   code
   {
     someproc@hades1();
     bar("Hello "+activator.name);
     pause;
   }
   dilend
</pre>
<pre>    When the procedure is called, the argument expressions are calculated, and
   passed to the template.  Built-in procedures, their arguments and function
   are listed later.
</pre>
<pre>    The following are definitions and documentation for the built-in procedures
   in DIL. The definitions are not definitions 'as such', but serve to distinguish
   arguments in the documentation below.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span id="follow()"></span><span class="mw-headline" id="follow.28.29">follow()</span></h1>
<pre>follow( f&#160;: unitptr, m&#160;: unitptr )
   f&#160;: The character to follow
   m&#160;: The character to be 
</pre>
<p>Unconditionally makes 'f' follow 'm', even if 'f' is mortally wounded, sleeping, fighting or whatever. See also the unitptr field <a href="./Manual:DIL-Manual-unitptr#Char" title="Manual:DIL Manual/unitptr">master</a> for CHARs.
</p><p><br />
<span id="bpflog"></span>
</p>
<pre><b>Function:</b>  <i>flog (filename&#160;: string,  s&#160;: string, wa&#160;: string );</i>
</pre>
<pre>  <b>filename</b>
         The Filename of the file to appear in the log directory.
  <b>s</b>
         The string to be logged.
  <b>wa</b>
         Write or Append
</pre>
<pre>The 'flog' function allows you to split up your logs in the log directory
so that you don't end up with everything in the main vme.log.
<b>Note:</b>The append/write argument must be in lower case and can only be a
'w' or a 'a' surrounded by '"'.  If the argument is a 'w' it will over write
any log file by that name.  If the argument is 'a' it will append to the
file by that name.
<b>Example:</b>
<i>
</i></pre><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i><pre>dilbegin zonelog (s:string);
code
{
flog (self.zonidx+".log",s,"a");
return;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
The previous DIL function will work in any zone to log to a file with that
zones name each zone could use it to keep zone logs separate.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bplogcrime"></span>
</p>
<pre>logcrime( c&#160;: unitptr, v&#160;: unitptr, t&#160;: integer )
   c&#160;: The criminal (main suspect)
   v&#160;: The victim
   t&#160;: The crime type (CRIME_XXX)
</pre>
<pre>      Registers a crime committed against 'v' by 'c'. Use the
    CRIME_XXX values from values.h and/or vme.h as the 't' argument.
    The logcrime routine automatically registers group members
    of the criminal, etc. In stuff like steal, remember to make
    the criminal visible if he fails his attempts.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpacc_mod"></span>
</p>
<pre>acc_modify( u&#160;: unitptr, i&#160;: integer )
   u&#160;: A player
   i&#160;: An amount in 1/100s, for example 100 would equal $1.00, and
       -100 would equal -$1.00.
</pre>
<pre>      Access only allowed with 'root' access and all transactions are
    registered in the specially encrypted account log file. Use with
    great caution, and always test thoroughly before using.
    Use without prior permission may cause deletion of god / zone.
</pre>
<p><br />
<span id="bfstrdir"></span>
</p>
<pre><b>Function:</b>  <i>stringlist strdir( match&#160;: string )&#160;;</i>
</pre>
<pre>  <b>match</b>
         The wild card file you want to match or '*' for all.
  <b>return</b>
         a Stringlist with all the filenames that match the 'match' argument.
</pre>
<pre>The 'match' argument uses the same wild cards as the Linux 'ls' command
so the following will work.
</pre>
<pre>  <b>&amp;ast;</b>
         Match any character or group of characters
  <b>&amp;quest;</b>
         Match one of any character
  <b>[...]</b>
         Match one of a set of characters
</pre>
<pre><b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>"corpse*" matches:  corpse.10938 corpse.whistler corpseofwhistler ...
"corpse?" matches corpse1 corpses corpse5 ...
"[abc]*" matches ability about cost back ...
"[a-z]*" about zoo man father ...
"start[nm]end" matches startnend startmend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>Example DIL:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin wanted ();
var
        wantedlist:stringlist;
        templist:stringlist;
        i:integer;
        ln:integer;
code
{
</pre></i><i><pre>        wantedlist&#160;:= strdir ("dead*");
</pre></i><i><pre>                i&#160;:= 0;
                ln&#160;:= length (wantedlist);
</pre></i><i><pre>        while (i &lt; ln )
                {
                templist&#160;:= split (wantedlist.[i],".");
                sendtext (templist.[1]+" wanted dead!&amp;n",self);
                i:=i+1;
                }
</pre></i><i><pre>quit;
}
dilend
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
The previous DIL would be an example of a command to check the wanted dead
players on the VME if you saved the files with the first word being
'dead' and separated it with a '.' and the players name. For example if
'whistler' was wanted dead  the file name would be 'dead.whistler'
</pre>
<p><br />
<span id="bpsetpassword"></span>
</p>
<pre><b>Function:</b>  <i>set_password( u&#160;: unitptr, s&#160;: string )&#160;;</i>
</pre>
<pre>  <b>u</b>
         the unit that you want to set the password of
  <b>s</b>
         the password you are using to set
</pre>
<pre>This function sets a unit password it only works on Players characters of corse.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin aware do_password (arg:string);
var
        prmt:string;
 firstpwd:string;
</pre></i><i><pre> i:integer;
 tlist:stringlist;
</pre></i><i><pre>code
{
</pre></i><i><pre>if(self.type&#160;!= UNIT_ST_PC) quit;
arg:="";
prmt:=self.prompt;
self.prompt:="Enter new password:  ";
wait (SFB_CMD,self==activator);
block;
tlist:=getwords (excmdstr);
if (length(tlist)&gt;1){
sendtext ("Password must be only one word.  Try again.&amp;n",self);
self.prompt:=prmt;
quit;
}
if (length(excmdstr)&lt;5){
        sendtext ("Password to short. Password must be 5 characters or longer.\
		Try again.&amp;n",self);
        self.prompt:=prmt;
        quit;
        }
</pre></i><i><pre>if (length(excmdstr)&gt;16){
        sendtext ("Password to long. Try again.&amp;n",self);
        self.prompt:=prmt;
        quit;
        }
</pre></i><i><pre>        firstpwd:=excmdstr;
        self.prompt:="Enter password again:  ";
</pre></i><i><pre>wait (SFB_CMD,self==activator);
block;
if (excmdstr!=firstpwd){
sendtext ("Passwords do not match try again.&amp;n",self);
self.prompt:=prmt;
quit;
}
set_password(self,excmdstr);
sendtext("Changed your Password to '"+excmdstr+"' Please write it down!&amp;n",self);
self.prompt:=prmt;
</pre></i><i><pre>quit;
}
dilend
</pre></i><i><p><br />
</p><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
<span id="bpstore"></span>
</p>
<pre><b>Function:</b>  <i>store( u&#160;: unitptr , filename&#160;: string , container&#160;: integer );</i>
</pre>
<pre>  <b>u</b>
         The Unit that has the contents to be stored or is to be stored
  <b>filename</b>
         The name of the file you want to store the Units to
  <b>container</b>
         Do you want to save the container 'TRUE' for yes, 'False' for no
</pre>
<p><br />
</p>
<pre>Store saves a copy of a unit or units.  If the container value is 'TRUE'
everything inside  including the container itself will be saved. If the container
argument is 'FALSE' only the contents of the object will be saved.  You will want
to use the 'TRUE' value when saving something like a Clan chest that has items
inside to store and has extras on the chest that you also wish to keep.  The
'FALSE' value for container would be good for temporary storage of PC inventory
or for storing room contents.
</pre>
<p><br />
</p>
<pre>The 'store' and 'restore' are perfect for operations such as
mud mailing objects from player to player, storage devices for players that will
keep inventory through a reboot.  Even the ability to save a players inventory
while they fight in an arena and restore it to them undamaged when finished.
Finally it could be used to save a donation room through reboots since it can be
used on a room to store the contents of a room any NPC or objects in the room
would be saved through reboot.
</pre>
<p><br />
</p>
<pre><b>Disk access is always slow</b>.
If you use store on a continues basis, it is essential that you do so ONLY if it
is needed and even then, only at amply spaced intervals.  Otherwise you might
cause serious delays on the server.  Remember that items saved in player's
inventories are automatically saved in their instance.
<b>Example 1:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin save_contents ();
code
{
</pre></i><i><pre>:start:
wait (SFB_CMD,command ("store")); wait for the store command*/
block;
store("chest."+self.zoneidx,self,FALSE);/*store everything inside self.*/
goto start;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>Example 2:</b>
<i>
</i></pre><i><p><br />
</p></i><i><pre>dilbegin save_container_n_contents ();
code
{
</pre></i><i><pre>:start:
wait (SFB_CMD,command ("store")); wait for the store command*/
block;
store("chest."+self.zoneidx,self,TRUE);/*store everything inside self and self.*/
goto start;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also</b>
<a href="#bfrestore">Store a Unit to a Unit file</a> and
<a href="#bfdelunit">Delete a Unit file</a>.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpp_u"></span>
</p>
<pre>position_update ( u&#160;: unitptr )
   u&#160;: A pointer to a player or a monster. The character will be
       updated and perhaps killed, incapacitated, mortally
       wounded, revived, etc. depending on current hitpoints.
       Useful when tampering with the 'hp' field. Example:
</pre>
<pre>       pc.hp&#160;:= pc.hp - 100;
       position_update(pc);
</pre>
<h1><span id="senddone()"></span><span class="mw-headline" id="senddone.28.29">senddone()</span></h1>
<p><b>Function:</b>
</p>
<pre>send_done( c&#160;: string, a :unitptr, m&#160;: unitptr, t :unitptr, p&#160;: integer, arg&#160;: string, o&#160;: unitptr, i&#160;: integer);
</pre>
<pre>  <b>c</b>
         the command string that is sending the message
  <b>a</b>
         the unitptr (activator) that activated the message
  <b>m</b>
         the unitptr (medium) that the Dil is acting through
  <b>t</b>
         the unitptr (target) the Dil is acting on
  <b>p</b>
         the power of the message
  <b>arg</b>
         the argument sent with the message
  <b>o</b>
         the unitptr (other) you also want the message to go to
  <b>i</b>
         CMD_AUTO_XXX to send a CMD_AUTO or 0
</pre>
<p><br />
This sends the 'SFB_DONE' message to any dils that are waiting for it in the
surrounding area and to the other pointer if not null.  The following is just
one example you can find many more in <b>commands.zon</b>
</p><p><b>Built-in variables</b>:
</p>
<pre> activator&#160;: unitptr
 medium    : unitptr
 target    : unitptr
 argument  : string
 power     : integer
</pre>
<pre><b>Example:</b>
</pre>
<pre>dilbegin do_read (arg:string);
var
brdname:string;
        i:integer;
        u:unitptr;
        x:extraptr;
        ln:integer;
        temp:string;
        templist:stringlist;
        buff:string;
        f_name:string;
        act_str:string;
code
{
  i:=atoi (arg);
 if (i&lt;0)
        {
        exec ("look "+arg,self);
        goto read_quit;
        }

if (itoa (i)!=arg)
        {
        exec ("look "+arg,self);
        goto read_quit;
        }

u:=self.outside.inside;
while (u!=null)
        {
        if ((u.type==UNIT_ST_OBJ) and (u.objecttype==ITEM_BOARD))
                break;
        u:=u.next;
        }

if (u==null)
        {
        act ("You do not see that here.",A_ALWAYS,self,null,null,TO_CHAR);
        quit;
        }

                if (u.extra.["$BOARD_L_RES"].descr!="")
                {
                act_str:=u.extra.["$BOARD_L_RES"].descr(self,u);
                if (act_str!="")
                {
        act(act_str,
                        A_ALWAYS,self,null,null,TO_CHAR);
                quit;
                }
                }
</pre>
<pre>brdname:=u.names.[length (u.names)-1];
i:=loadstr (brdname+".idx",temp);
if (i&lt;=0)
        {
        act ("But the board is empty!",
                A_ALWAYS,self,null,null,TO_CHAR);
        goto read_quit;
        }
</pre>
<pre>templist:=split(temp,"&amp;x");
ln:=length (templist);
x:="$BOARD_MAX" in self.extra;
if ((atoi(arg)&gt;atoi(x.descr)) or
(atoi(arg)&gt;ln))
        {
        act("That message exists only within the boundaries of your mind.",
                A_ALWAYS,self,null,null,TO_CHAR);
        goto read_quit;
        }
</pre>
<pre>i:=atoi(arg);
temp:=templist.[i-1];
f_name:=getword(temp);
i:=loadstr (brdname+"."+f_name,buff);
if (i==0)
        {
        sendtext("You have to let the poster finish the post before reading it.",self);
        quit;
        }
if (i&lt;1)
        {
        log("05: Error when loading board info.");
        act ("This board is not working report to an Administrator",
                A_ALWAYS,self,null,null,TO_CHAR);
                quit;
                }
</pre>
<pre>templist:=split(f_name,".");
if (length(templist)&lt;2)
        act ("Message "+arg+":  "+temp,
                A_ALWAYS,self,null,null,TO_CHAR);
else
        act ("Message "+arg+":  Re:  "+temp,
                A_ALWAYS,self,null,null,TO_CHAR);
</pre>
<pre>pagestring(buff,self);
</pre>
<pre>:read_quit:
 send_done("read",self,null,u,0,arg,null,0);
quit;
}
dilend
</pre>
<p><br />
<span id="bfsend_pre"></span>
</p>
<pre><b>Function:</b>send_pre( c&#160;: string, a :unitptr, m&#160;: unitptr, t :unitptr, p&#160;: integer, arg&#160;: string, o&#160;: unitptr);
</pre>
<pre>  <b>c</b>
         the command string that is sending the message
  <b>a</b>
         the unitptr (activator) that activated the message
  <b>m</b>
         the unitptr (medium) that the Dil is acting through
  <b>t</b>
         the unitptr (target) the Dil is acting on
  <b>p</b>
         the power of the message
  <b>arg</b>
         the argument sent with the message
  <b>o</b>
         the unitptr (other) you also want the message to go to
</pre>
<p><br />
</p>
<pre>New Function send_pre() takes same arguments as send_done but returns either
 SFR_SHARE or SFR_BLOCK.
If the command is blocked by another special or dil, then SFB_BLOCK will be returned,
 and you should quit your dil.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin cmdtst(arg&#160;: string);
var
  i&#160;: integer;
code
{
   i:=send_pre("cmdtest",self,null,null,0,argument,null);
</pre></i><i><pre>if (i == SFR_BLOCK)
  quit;
</pre></i><i><pre>          sendtext ("No one blocked me!&amp;n",self);
          quit;
          }
          dilend
</pre></i><i><p><br />
</p></i><i><pre>dilbegin pretest();
code
{
   :loop:
   wait(SFB_PRE, command("cmdtest"));
   block;
        act("hahahaha I blocked your cmdtest command",
       A_SOMEONE, activator, medium, null, TO_ALL);
        goto loop;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpset"></span>
</p>
<pre>set ( var i&#160;: integer , bit&#160;: integer )
   i&#160;: Integer variable to alter.
   bit&#160;: Bits to set in integer variable.
   result: Sets bits in 'i'
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpunset"></span>
</p>
<pre>unset ( var i&#160;: integer , bit&#160;: integer )
   i&#160;: Integer variable to alter.
   bit&#160;: Bits to unset in integer variable.
   result: unset bits in 'i'.
</pre>
<p><br />
<span id="bpaddcolor"></span>
</p>
<pre><b>Function:  </b><i>addcolor (ch&#160;: unitptr, ks&#160;: string, cstr&#160;: string )&#160;;</i>
</pre>
<pre>  <b>ch</b>
         character you are adding the color to
  <b>ks</b>
         key string for the color
  <b>cstr</b>
         color string
</pre>
<pre>This function allows your Dils to create and add their own personal colors to a players
color list.  That way you can actually make an act in a color that the player chooses or
you yourself choose.
<b>Function:  </b><i>addcolor(pc, "clan_who","&amp;c+w&amp;bn");</i>
</pre>
<p><br />
<span id="bpdelcolor"></span>
</p>
<pre><b>Function:  </b><i>delcolor (ch&#160;: unitptr, ks&#160;: string)&#160;;</i>
</pre>
<pre>  <b>ch</b>
         character you are deleting the color from
  <b>ks</b>
         key string for the color
</pre>
<pre>This function is used to delete any colors from a players personal color list.
<b>Function:  </b><i>delcolor(pc, "clan_who");</i>
</pre>
<p><br />
<span id="bfgcolor"></span>
</p>
<pre><b>Function:  </b><i> string getcolor (ch&#160;: unitptr, ks&#160;: string)&#160;;</i>
</pre>
<pre>  <b>ch</b>
         character you are deleting the color from
  <b>ks</b>
         key string for the color
  <b>returns</b>
         returns the color in a string
</pre>
<pre>This function returns what color a player has for a key in the players list.
<b>Function:  </b><i>string&#160;:= getcolor(pc, "clan_who");</i>
</pre>
<p><br />
<span id="bpchangecolor"></span>
</p>
<pre><b>Function:  </b><i>changecolor (ch&#160;: unitptr, ks&#160;: string, cstr&#160;: string )&#160;;</i>
</pre>
<pre>  <b>ch</b>
         character you are changing the color on
  <b>ks</b>
         key string for the color
  <b>cstr</b>
         color string
</pre>
<pre>This will change a color in a players personal list.
<b>Function:  </b><i>changecolor(pc, "clan_who","&amp;c+w&amp;bn");</i>
</pre>
<p><br />
<span id="bpgamestate"></span>
</p>
<pre><b>Function:  </b><i>  gamestate( u&#160;: unitptr, gs&#160;: integer ); </i>
Change the gamestate of a unitptr, uses the GS_ defines from the
<b>vme.h</b>. This is used on the log on menu of the VME 2.0 release. Which is
shown here as an example but it can also be used in a command.  When used it
removes the char from playing so be aware that players could use this to hide
if you run a player killing style mud.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin informer();
var
tgt&#160;: unitptr;
code
{
heartbeat&#160;:= PULSE_SEC;
</pre></i><i><pre>tgt&#160;:= ghead();
</pre></i><i><pre>while(tgt.type == UNIT_ST_PC)
{
</pre></i><i><pre> if((isset(tgt.pcflags,PC_INFORM)) and (tgt&#160;!= self))
 {
     if(visible(tgt,self))
        {
        if(self.outside == tgt.outside)
        sendtext(self.name+" has arrived.&amp;n", tgt);
     else
        sendtext(self.name+" has entered the world.&amp;n", tgt);
        }
 }
</pre></i><i><pre>tgt&#160;:= tgt.gnext;
}
</pre></i><i><pre>return;
}
dilend
</pre></i><i><pre>dilbegin aware on_connect();
external
        informer();
        login_modify(tgt&#160;: unitptr);
</pre></i><i><pre>var
  wizlvl&#160;: integer;
        i:integer;
     err&#160;: integer;
    motd&#160;: string;
 welcome&#160;: string;
 goodbye&#160;: string;
code
{
heartbeat&#160;:= PULSE_SEC;
</pre></i><i><pre>if(dilfind("do_quit@commands",self))
        i&#160;:= dildestroy("do_quit@commands", self);
</pre></i><i><pre>err&#160;:= loadstr("motd",motd);
</pre></i><i><pre>if(err &gt; 0)
{
        motd&#160;:= textformat(motd);
        sendtext(motd+"&amp;n&amp;n", self);
</pre></i><i><pre>}
</pre></i><i><pre>err&#160;:= loadstr("welcome",welcome);
if(welcome)
        welcome&#160;:= textformat(welcome);
</pre></i><i><pre>if (self.level &lt; 200)
{
</pre></i><i><pre>login_modify(self);
dilcopy ("clan_delete@clans",self);
dilcopy ("clan_clear@clans",self);
</pre></i><i><p><br />
</p></i><i><pre>if(err &gt; 0)
        sendtext("&amp;n"+welcome+"&amp;n&amp;n", self);
  informer();
  exec("look", self);
  quit;
}
gamestate(self, GS_MENU);
</pre></i><i><pre>:wiz_menu:
sendtext("Welcome to Valhalla&amp;n&amp;n", self);
sendtext("1) Enter Valhalla&amp;n", self);
sendtext("W) Change Wizinv level&amp;n [&amp;c+g"+itoa(self.minv)+"&amp;[default]]&amp;n",self);
sendtext("0) Exit Valhalla&amp;n&amp;n", self);
sendtext("Make your choice: ", self);
wait(SFB_CMD, TRUE);
</pre></i><i><pre>if (command("1") )
{
  gamestate(self, GS_PLAY);
  if(err &gt; 0)
        sendtext("&amp;n"+welcome+"&amp;n&amp;n", self);
  informer();
  exec("look", self);
  quit;
} else if (command("0") ) {
  err&#160;:= loadstr("goodbye",goodbye);
  if(err &gt; 0)
  {
  goodbye&#160;:= textformat(goodbye);
  sendtext(goodbye, self);
  }
  destroy(self);
  quit;
} else if (command("w") ) {
  sendtext("Enter new WizInv Level: ", self);
  wait(SFB_CMD, TRUE);
  wizlvl&#160;:= atoi(cmdstr);
  if (wizlvl &gt; self.level)
    wizlvl&#160;:= self.level;
  self.minv&#160;:= wizlvl;
} else {
  sendtext("Invalid Selection&amp;n&amp;n", self);
  goto wiz_menu;
}
</pre></i><i><pre>}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
Look in <b>vme.h</b> for the possible values you can send to the menu
function.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpaddex"></span>
</p>
<pre>addextra ( var e&#160;: extraptr, l&#160;: stringlist , s&#160;: string )
   e&#160;: Extra description list to add element to.
   l&#160;: Stringlist for the .names field.
   s&#160;: String for the .descr field.
   result: Adds an extra description to a list of extra descriptions.
</pre>
<pre><strong>CAVEAT</strong> builder: You cannot use an extraptr variable as the e
argument, but you may continue to use the following form:
</pre>
<pre>   ...
   ...
   addextra (self.quests, "Bozo's Quest");
   ...
   ...
</pre>
<p>See also:
</p>
<pre> subextra
</pre>
<p><br />
</p>
<pre>addstring ( var l&#160;: stringlist, s&#160;: string )
   l&#160;: Stringlist to add string to.
   s&#160;: String to add.
   result&#160;: Adds a string 's' to a stringlist 'l'.
</pre>
<p><br />
See also:
</p>
<pre>  <a href="./Manual:DIL-Manual-substring()" title="Manual:DIL Manual/substring()">substring()</a>
</pre>
<p><br />
<span id="bpsubex"></span>
</p>
<pre>subextra ( var e&#160;: extraptr, s&#160;: string )
   e&#160;: Extra description list to remove element from.
   s&#160;: String matching .names field in element
   result: Removes first extra description from list with matching name.
</pre>
<pre>&lt;emp&gt;CAVEAT&lt;/EMP&gt; builder: You cannot use an extraptr variable as the e
argument, but you may continue to use the following form:
</pre>
<pre>   ...
   ...
   subextra (self.quests, "Bozo's Quest");
   ...
   ...
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpsubs"></span>
</p>
<pre>substring ( var l&#160;: stringlist, s&#160;: string )
   l&#160;: Stringlist to remove string from.
   s&#160;: String to remove
   result: Removes string 's' from stringlist 'l'.
</pre>
<p><br />
<span id="bpstopfighting"></span>
</p>
<pre><b>Function:</b>  <i>stop_fighting( ch: unitptr, vict&#160;: unitptr )&#160;;</i>
</pre>
<pre>  <b>ch</b>
         unitptr - person you are stoping the fighting for
  <b>vict</b>
         unitptr - person you are removing from the fighting or null for everyone
</pre>
<pre>This function can be used to cancel combat in a room or with two people.
The following example copied to a player will stop any fight the player is in.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin stop_combat();
code
{
stop_fighting(self,null);
quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span id="subaff_(_u_:_unitptr,_i_:_integer_)"></span><span class="mw-headline" id="subaff_.28_u_:_unitptr.2C_i_:_integer_.29">subaff ( u&#160;: unitptr, i&#160;: integer )</span></h1>
<pre> u&#160;: Unit remove affect from.
 i&#160;: Affect id to remove, see ID_* in values.h and/or vme.h
 result: Removes first affect at 'u' with matching id 'i'.
</pre>
<p>See also:
</p>
<pre> &gt; <a href="./Manual:DIL-Manual-isaff()" title="Manual:DIL Manual/isaff()">isaff()</a>
 &gt; <a href="./Manual:DIL-Manual-addaff()" title="Manual:DIL Manual/addaff()">addaff()</a>
 &gt; <a href="./Manual:DIL-Manual-getaffects()" title="Manual:DIL Manual/getaffects()">getaffects()</a>
</pre>
<h1><span id="addaff(_u_:_unitptr,_id_:_integer,_duration_:_integer,_beat:_integer,_data0_:_integer,_data1:_integer,_data2:_integer,_tif_first_:_integer,_tif_tick_:_integer,_tif_last_:_integer,_apf_:_integer)"></span><span class="mw-headline" id="addaff.28_u_:_unitptr.2C_id_:_integer.2C_duration_:_integer.2C_beat:_integer.2C_data0_:_integer.2C_data1:_integer.2C_data2:_integer.2C_tif_first_:_integer.2C_tif_tick_:_integer.2C_tif_last_:_integer.2C_apf_:_integer.29">addaff( u&#160;: unitptr, id&#160;: integer, duration&#160;: integer, beat: integer, data0&#160;: integer, data1: integer, data2: integer, tif_first&#160;: integer, tif_tick&#160;: integer, tif_last&#160;: integer, apf&#160;: integer)</span></h1>
<pre> u  : Unit to add affect to.
 id&#160;: Affect id to add, see ID_* in values.h and/or vme.h
 duration&#160;: Number of triggers
 beat&#160;: How often the pulse runs (4 = 1 second)
 data0-2&#160;: Data values for the ID_
 tif  : The message ID 
 apf  : The modification function
 result: Adds affect 'id' at 'u' with first, tick, and last TIF_XXX's, etc.
</pre>
<p>See also:
</p>
<pre> &gt; <a href="./Manual:DIL-Manual-subaff()" title="Manual:DIL Manual/subaff()">subaff()</a>
 &gt; <a href="./Manual:DIL-Manual-isaff()" title="Manual:DIL Manual/isaff()">isaff()</a>
 &gt; <a href="./Manual:DIL-Manual-getaffects()" title="Manual:DIL Manual/getaffects()">getaffects()</a>
</pre>
<p><br />
<span id="bpdest"></span>
</p>
<pre><b>Function:</b>  <i>destroy ( u&#160;: unitptr );</i>
</pre>
<pre>  <b>u</b>
         :Unit to remove from game
</pre>
<pre>The destroy function works in two ways depending on the Unit being acted on.
If the Unit being acted on is a PC the player is saved and ejected from the game.
If the Unit being acted on is a NPC, or an Object. the purge function destroys
the Unit.  Currently destroy will not destroy rooms.
This is different from the old destroy function in that it removes the player
out of the game instead of leaving the player in the menu.
<b>Example</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin purge_all_pc();
var
        u:unitptr/*Unit used to purge each player*/
        n:unitptr;/*used to keep track of next player*/
code
{
u:=ghead();/*get first pc in game list*/
n:=u;
</pre></i><i><p><br />
</p></i><i><pre>while (n.type==UNIT_ST_PC)/*while unit is a pc*/
        {
        n:=u.gnext;
        destroy(u);
        }
</pre></i><i><pre>quit;/*done whiping out the players*/
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpwalkto"></span>
</p>
<pre>walkto ( u&#160;: unitptr )
   u&#160;: Room to walk to.
   result: Makes unit (self) walk to room, taking a 'step' at each 'tick'.
</pre>
<pre><b>Example:</b>
</pre>
<pre>   walkto(findroom("inn@udgaard"));
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bplink"></span>
</p>
<pre>link ( u&#160;: unitptr, t&#160;: unitptr )
   u&#160;: Unit to link.
   t&#160;: Unit to link into.
   result: Link a unit into another unit hierarchy. (Automatically
           unequipps if equipped).
</pre>
<p><br />
<span id="bfweapon_name"></span>
</p>
<pre><b>Function:</b>  <i>string weapon_name( i&#160;: integer )&#160;;</i>
</pre>
<pre>  <b>i</b>
         Weapon to get the name of ass defined in 'values.h' and 'weapons.def'
  <b>returns</b>
         The name of the weapon that corresponds with the integer value
</pre>
<pre><b>example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>myweap:=weapon_name(5);
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
<span id="bfweapon_info"></span>
</p>
<pre><b>Function:</b>  <i>intlist weapon_info( i&#160;: integer )&#160;;</i>
</pre>
<pre>  <b>i</b>
         Weapon to get the info of ass defined in 'values.h' and 'weapons.def'
  <b>returns</b>
         Intlist containing 4 values:
</pre>
<pre>  <b>0</b>
         Number of hands
  <b>1</b>
         weapon speed
  <b>2</b>
         weapon type
  <b>3</b>
         shield block value
</pre>
<p><br />
</p>
<pre>This function gives you access to the values in the weapons.def file.
With this things like 'wear' equipment' and 'look' are much easier to
write in Dil.
<b>Example</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilcopy id_weap (arg:string);
var
  i:integer;
  il:intlist;
code
{
il:=weapon_info(atoi(arg));
</pre></i><i><pre>if (il!=null)
{
sendtext ("Number of hands:  "+itoa(il.[0])+"&amp;n";
             sendtext ("Speed:  " +itoa(il.[1])+"&amp;n",self);
                         sendtext ("Type:  "+itoa(il.[0])+"&amp;n",self);
                         sendtext ("Shield value:  "+itoa(il.[0])+"&amp;n",self);
                         }
else
{
sendtext ("No such weapon.&amp;n",self);
}
</pre></i><i><pre>quit;
}
dilend
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
<span id="bfskill_name"></span>
</p>
<pre><b>Function:</b>  <i>string skill_name( i&#160;: integer )&#160;;</i>
</pre>
<pre>  <b>i</b>
         Skill to get the name of ass defined in 'values.h' and 'commands.def'
  <b>returns</b>
         The name of the skill that corresponds with the integer value
</pre>
<pre><b>example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>myski:=skill_name(5);
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
<span id="bpreboot"></span>
</p>
<pre><b>Function:  </b><i>reboot&#160;;</i>
This function works like a quit command.  Anything after the reboot function in a Dil will not be
executed the mud will reboot instantly.  The zone must have root privileges in
the zonelist in order to use this function.
<b>Simple reboot command</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin cmd_reboot (arg:string);
code
{
sendtext ("Rebooting the mud.&amp;n",self);
reboot;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
<span id="bpkilledit"></span>
</p>
<pre><b>Function:  </b><i>killedit&#160;;</i>
This function is used to kill the editor on a PC if it needs to
stop editing before the PC is done editing.  An example of when this is needed
is when a player is killed while editing or is transfered away from a place where he was editing.
You can let them finish but it may be wierd for a person to finish
posting in one room while in another.
<b>Example</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin editextra (arg:string);
code
{
interrupt (SFB_DEAD,self==activator,int_quit);
        beginedit (self);
        wait(SFB_EDIT,self==activator)&#160;;
        temp&#160;:= textformat(argument);
addextra (self.outside.extra ,{"graphitee"},temp);
quit;
:int_quit:
killedit;
quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpexp"></span>
</p>
<pre>experience ( i&#160;: integer, u&#160;: unitptr )
   i&#160;: A integer number of experience to gain or loose.
   u&#160;: The player to receive the experience.
   result: The integer amount of experience is added to the players
           total amount of experience (thus causing more or less
           experience). USE WITH CARE! SUGGEST THAT YOU ONLY USE
           INTEGER CONSTANTS AS THE EXPRESSION TO AVOID ERRORS.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span id="act()"></span><span class="mw-headline" id="act.28.29">act()</span></h1>
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
</pre>
<p><br />
<span id="bpexec"></span>
</p>
<pre>exec ( s&#160;: string , u&#160;: unitptr )
   s&#160;: Command and arguments to perform.
   u&#160;: Unit to perform command.
   result: Unit (PC/NPC) executes command. The argument is treated just as
           if a normal PC entered a command at the command prompt in the
           game. It is not directly possible to detect whether the command
           was a success or fail. For example, you might force a PC to
           "get key". If there is no 'key' available, the PC will get
           notified the normal way. Plenty of examples are given above.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpwait"></span>
</p>
<pre>wait ( i&#160;: integer , dilexp )
   i&#160;: Message class to accept, see SFB_* in values.h and/or vme.h
   dilexp&#160;: Expression that has to be TRUE or not null to accept message.
   result: Waits for a command, matching the flagset, and satisfies the
           expression. When using the 'wait()' command, the first argument
           is an integer, that tells what classes of messages to wait for.
           Each message class is represented by a bit named as described in
           the chapter on messages.
<b>Example:</b>
</pre>
<pre>   wait (SFB_TICK|SFB_MSG, TRUE)
   /* Will accept a message, either from another DIL program or a
      timer message. As the second argument is always TRUE, any
      such message will reactivate the DIL program.
    */
</pre>
<pre><b>Example:</b>
</pre>
<pre>  wait (SFB_CMD, command("transmutate"))
  /* waits for an command entered named 'transmutate'.
     Activates the DIL program, that then can block the command, or
     let it pass (and then let the game produce the normal error
     message for unknown commands).
  */
</pre>
<p><br />
<span id="bfsavestr"></span>
</p>
<pre><b>Function:</b>  <i>integer savestr( filename&#160;: string , buff&#160;: string , wa :string);</i>
</pre>
<pre>  <b>filename</b>
         The name of the String file to save the String to
  <b>buff</b>
         The String you wish to save into the file
  <b>wa</b>
         Write or append
  <b>Return</b>
         <i>FILE_SAVED, FILE_NOT_SAVED, FILE_NOT_CREATED, or FILE_ILEGAL_OPP</i>
</pre>
<pre>Savestr is used to save strings to disk to be loaded later by the 'load' function.
The 'savestr' and 'Loadstr' is perfect for operations such as
on-line edited newspaper, a lottery where the tickets are sold to players,
creating smarter NPC's that can remember through reboots who they are hunting,
Dil based teachers, message boards, mail system, news command., zone or
room based help,  competition boards, and much much more.
<b>Note:</b>The append/write argument must be in lower case and can only be a
'w' or a 'a' surrounded by '"'.  If the argument is a 'w' it will over write
any string file by that name.  If the argument is 'a' it will append to the
file by that name.
<b>Disk access is always slow</b>.
If you use loadstr on a continuous basis always
attempt to keep file sizes to a minimum for quick loading.  Otherwise you
might cause serious delays on the server.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin news_save (arg:string  /*for saving*/);
var
        ret:integer;/*to hold the return value if saved or not*/
code
{
ret:= savestr("news.txt",arg,"w");
if (!ret)
        {
        log ("File not wrote");
        quit;
        }
</pre></i><i><pre>sendtext("New news file wrote.[&amp;]n",self);
quit;/*dil save routine done destroy self.*/
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>See Also</b> <i>
<a href="#bfdelstr">Delete a String file</a> and
<a href="#bfloadstr">Load a String file</a></i>
</pre>
<p><br />
<span id="bpremove"></span>
</p>
<pre><b>Function:</b>  <i>remove( sl&#160;: stringlist, i&#160;: integer )&#160;;</i>
</pre>
<pre>  <b>sl</b>
         the stringlist you are removing from
  <b>i</b>
         the index you want to remove
</pre>
<pre>This function allows you to remove a string from a stringlist with out
leaving a blank spot in the stringlist.
<b>Example:  </b><i>remove (sl, i);</i>
</pre>
<p><br />
<span id="bpresetlevel"></span>
</p>
<pre><b>Function:</b>  <i>reset_level( u&#160;: unitptr )&#160;;</i>
</pre>
<pre>  <b>u</b>
         player your resetting
</pre>
<pre>This function simply resets a players level.  Can be used in functions
like reroll where you set the players back to the way he first logged on.
<b>Example:  </b><i>reset_level (u);</i>
<b>See Also</b>
<i>
<a href="#bpresetvlevel">reset a players virtual level</a> and
<a href="#bpresetrace">reset a players race information</a></i>
</pre>
<p><br />
<span id="bpresetvlevel"></span>
</p>
<pre><b>Function:</b>  <i>reset_vlevel( u&#160;: unitptr )&#160;;</i>
</pre>
<pre>  <b>u</b>
         player your resetting
</pre>
<pre>This function simply resets a players virtual level.  Can be used in functions
like reroll where you set the players back to the way he first logged on.
<b>Example:  </b><i>reset_vlevel (u);</i>
<b>See Also</b>
<i>
<a href="#bpresetlevel">reset a players level</a> and
<a href="#bpresetrace">reset a players race information</a></i>
</pre>
<p><br />
<span id="bpresetrace"></span>
</p>
<pre><b>Function:</b>  <i>reset_race( u&#160;: unitptr )&#160;;</i>
</pre>
<pre>  <b>u</b>
         player your resetting
</pre>
<pre>Reset a characters race, weight, height, age, lifespan, and costs for training.
As if you first log on the character.  Great for reroll along with 'reset_level' and 'reset_vlevel'.
<b>Example:  </b><i>reset_race (u);</i>
<b>See Also</b>
<i>
<a href="#bpresetlevel">reset a players level</a> and
<a href="#bpresetvlevel">reset a players virtual level</a></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span id="secure_(_u_:_unitptr_,_label)"></span><span class="mw-headline" id="secure_.28_u_:_unitptr_.2C_label.29">secure ( u&#160;: unitptr , label)</span></h1>
<p>Secures the unitptr 'u' and jumps to 'label' when the secure is broken.
</p>
<pre> u&#160;: Unit to secure.
 label&#160;: Label to jump to, on removal.
</pre>
<p>Secures a unitptr, so that the program will go to 'label' if unit leaves local environment.
The unit leaves the local environment when it is destroyed or e.g. moved to a different location
such as an adjacent room. A transparent room in a room would not count as leaving the local environment.
</p><p>A DIL program is tested for secures in the follow circumstances:
</p>
<ul><li>When the DIL program is activated (e.g. after a pause / wait())</li>
<li>When the DIL program has performed a send(), sendto(), sendtoall(), sendtoalldil().</li>
<li>When the DIL program calls updateposition() (because it might kill the unit)</li>
<li>When the DIL program calls cast(), cast2() or attackspell(), meleeattack(), meleedamage().</li>
<li>Returning from a DIL sub-function that has triggered a secure() scan.</li>
<li>In every foreach-next step</li></ul>
<p>A DIL program will test a specific unit for secure in the follow circumstances:
</p>
<ul><li>DIL destroy(u) will test if 'u' was a secured() variable and if so will trigger it if destroyed.</li>
<li>DIL exec(str, u) will test if 'u' was a secured() variable and if so will trigger it if destroyed.</li></ul>
<p>A specific test will also cascade down through frames.
</p><p>If a secure() is triggered during execution in a sub-function/procedure, then once execution returns to
the parent frame, then the parent frame will test for secure() violations before continuing execution. 
</p><p>Should several secured units leave local environment, the last such event will determine the point of execution upon return.
</p><p>See also:
</p>
<pre> &gt; unsecure
</pre>
<p><br />
<span id="bfunitdir"></span>
</p>
<pre><b>Function:</b>  <i>stringlist unitdir( match&#160;: string )&#160;;</i>
</pre>
<pre>  <b>match</b>
         The wild card file you want to match or '*' for all.
  <b>return</b>
         a Stringlist with all the filenames that match the 'match' argument.
</pre>
<pre>The 'match' argument uses the same wild cards as the Linux 'ls' command
so the following will work.
</pre>
<pre>  <b>&amp;ast;</b>
         Match any character or group of characters
  <b>&amp;quest;</b>
         Match one of any character
  <b>[...]</b>
         Match one of a set of characters
</pre>
<pre><b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>"corpse*" matches:  corpse.10938 corpse.whistler corpseofwhistler ...
"corpse?" matches corpse1 corpses corpse5 ...
"[abc]*" matches ability about cost back ...
"[a-z]*" about zoo man father ...
"start[nm]end" matches startnend startmend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
<b>Example DIL:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin aware reload_corpse();
var
        corpselist:stringlist;
        u:unitptr;
        ln:integer;
        i:integer;
        x:extraptr;
code
{
        corpselist:=unitdir("corpse*");
        ln:=length(corpselist);
        i:=0;
        while (i&lt;ln)
        {
        u:=restore(corpselist.[i],null);
        x:=CORPSE_EXTRA in u.extra;
        if (u!=null)
                if (x!=null)
                        link (u,findroom(x.descr));
                else
                        link (u,findroom("temple@udgaard"));
        i:=i+1;
        }
</pre></i><i><pre>quit;
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
The previous DIL example is the DIL used in restoring corpses to the game in
case of a crash.  For more information you can see how the death DIL'S work
by reading through the file death.zon in the vme2.0/zone.
directory.
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span id="unsecure_(u_:_unitptr)"></span><span class="mw-headline" id="unsecure_.28u_:_unitptr.29">unsecure (u&#160;: unitptr)</span></h1>
<p>A unit 'u' that has been secured in a DIL program can have the secure removed
by calling unsecure on the unit'u'
</p>
<pre> u&#160;: Secured unit.
 result: Drop secure on a given unit.
</pre>
<p>See also:
</p>
<pre> &gt; secure
</pre>
<p><br />
<span id="bpblock"></span>
</p>
<pre>block
   result: Blocks any command issued by a player or mobile. Blocking a
           command prevents the command from being parsed by the
           interpreter. This is ideal if you need to make a routine
           which intercepts a command, reacts on it in a special way,
           and does not need the standard way of reacting.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bppri"></span>
</p>
<pre>priority
   result: Set until nopriority command. When set, no special routines
           "below" the current DIL program will be executed. This is used
           to make other special routines idle. See haon-dor.zon for an
           example.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpnopri"></span>
</p>
<pre>nopriority
   result: Cancels the priority procedure.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpaddeq"></span>
</p>
<pre>addequip ( u&#160;: unitptr , i&#160;: integer )
   u&#160;: Unit to equip.
   i&#160;: Where to equip unit.
   result: Equips unit, presumed to be in inventory PC/NPC at
           given position. See WEAR_* in values.h and/or vme.h
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpuneq"></span>
</p>
<pre>unequip ( u&#160;: unitptr )
   u&#160;: Unit to unequip.
   result: Unequipes unit presumed to be in equipment of PC/NPC.
</pre>
<p><br />
<span id="bpdp"></span>
</p>
<pre><b>Function:</b>  <i>delete_player( s&#160;: string )&#160;;</i>
</pre>
<pre>  <b>s</b>
         the player name you want to delete
</pre>
<pre>This function deletes a player but it doesn't check to see if it
was deleted or if it even existed you will have to do that with 'isplayer'.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin aware do_delete (arg:string);
var
        temp:string;
        err:integer;
code
{
</pre></i><i><pre>if(self.type&#160;!= UNIT_ST_PC) quit;
</pre></i><i><pre>if (self.level&gt;200)
        goto admin_delete;
</pre></i><i><pre>:char_delete:
        if (arg!="self forever")
                {
                sendtext ("To delete your char type:  'delete self forever'&amp;n",self);
                quit;
                }
</pre></i><i><pre>err:=loadstr("delete.txt",temp);
</pre></i><i><pre>if (err&lt;1)
        goto no_insure;
</pre></i><i><pre>sendtext (temp,self);
</pre></i><i><pre>sendtext ("If your sure you still want to delete your character, 'say delete me'&amp;n",self);
sendtext ("Doing anything else will abort the deletion.&amp;n",self);
</pre></i><i><pre>wait (SFB_CMD, self==activator);
if (command ("say"))
</pre></i><i><pre>        if (argument=="delete me")
        if (self.extra.[CLAN_RANK]!=null)
                exec ("cdefect",self);
                delete_player(self.name);
</pre></i><i><pre>sendtext("Deletion aborted&amp;n",self);
</pre></i><i><pre>quit;
</pre></i><i><pre>        :no_insure:
                if (self.extra.[CLAN_RANK]!=null)
                exec ("cdefect",self);
                        delete_player(self.name);
</pre></i><i><pre>quit;
        :admin_delete:
        if (arg=="self forever")
                goto char_delete;
if (arg==""){
sendtext("You must supply a characters name to delete one.&amp;n",self);
quit;
}
</pre></i><i><pre>if (arg==self.name){
sendtext ("To delete self you need to type 'delete self forever'&amp;n",self);
quit;
}
</pre></i><i><pre>if (not isplayer(arg))
        {
        sendtext (arg+" is not a character.&amp;n",self);
        quit;
        }
dilcopy ("god_delete@clans("+arg+")",self);
</pre></i><i><pre>        sendtext (arg+" has been deleted.&amp;n",self);
quit;
}
dilend
</pre></i><i><p><br />
</p></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span id="dilcopy(_s_:_string,_u_:_unitptr_)"></span><span class="mw-headline" id="dilcopy.28_s_:_string.2C_u_:_unitptr_.29">dilcopy( s&#160;: string, u&#160;: unitptr )</span></h1>
<pre>   s&#160;: Name template to attach to unit.
   u&#160;: Unit to attach a dil program to.
   result: Attaches a DIL program to a unit 'u', which uses a template named by 's'.
</pre>
<p>Examples:
</p>
<pre>  dilcopy("master_servant@spells()", u);
  dilcopy("spl_sleep@spells(7)", tgt);
  dilcopy("sendmsg@spells(teleport)", targ);
</pre>
<p><br />
<span id="bpsendt"></span>
</p>
<pre>sendtext( s&#160;: string, u&#160;: unitptr )
   s&#160;: text to send
   u&#160;: Unit to send the text to
   result: Sends the string 's' to 'u'. Useful only for nanny stuff,
           because no new line appended.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpchngs"></span>
</p>
<pre>change_speed( u&#160;: unitptr, i&#160;: integer )
  u&#160;: the unit on which you wish to alter the current combat speed.
  i&#160;: the amount to add to the speed.
</pre>
<pre>  Beware, this is not the 'speed' as in the speed field, rather this is
  the speed which is calculated during combat. It is used for spells like
  'stun' which effectively puts the character out of combat for one
  round. Such a spell would be implemented like:
</pre>
<pre>   change_speed(u, 12)
</pre>
<pre>  and would only cause any effect if 'u' was fighting already (if not,
  use setfighting).
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bftranmon"></span>
</p>
<pre>integer transfermoney( f&#160;: unitptr, t&#160;: unitptr, amount&#160;: integer)
   f&#160;: The char the money is taken from
   t&#160;: The char the money is given to
   amount&#160;: How much money.
   Returns: TRUE is money was transferred, FALSE if could not afford.
</pre>
<pre>   If 'f' is null and 't' isn't, then money is created and given to 't'.
   If 'f' isn't null but 't' is, then money is removed from 'f'.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpsetfight"></span>
</p>
<pre>set_fighting( u&#160;: unitptr, t&#160;: unitptr )
   u&#160;: the unit on which attacks.
   t&#160;: the unit being attacked.
</pre>
<pre>   This is used to set two characters fighting. If the attacker is
   fighting already, the target will simply be inserted into the
   opponent list and perhaps killed a little later.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<h1><span id="setweight(_u_:_unitptr,_i_:_integer_)"></span><span class="mw-headline" id="setweight.28_u_:_unitptr.2C_i_:_integer_.29">setweight( u&#160;: unitptr, i&#160;: integer )</span></h1>
<p>OBSOLETE.
</p><p>Superseeded by
</p>
<pre> set_weight_base
 set_weight
</pre>
<p><b> Parameters </b>
</p>
<pre> u&#160;: the unit on which you wish to alter the weight.
 i&#160;: the new total weight
</pre>
<p><b> Description </b>
Use this procedure on for example drink-containers if you wish to
remove or add some liquid. This function will ensure the base-weight
is unchanged, and that the weight of the unit is altered according to
the integer i (positive or negative). To ensure weight consistency this
procedure also adjusts the weight of all units outside the altered unit.
</p><p>For example in this hierarchy
</p>
<pre> room
   npc
   pc
     bottle (b:1)
</pre>
<p>Setting the bottle to 5 will add 4 liquid weight to the bottle and
keep the base weight at 1. The pc and the room as well (npc remains unchanged)
</p><p>IMPORTANT: Code review needed here. It looks like its a mess and we need one
function to change the base weight, and one function to change the contents
weight (e.g. adding liquids to a bottle).
</p><p><br />
<span id="bpsetbright"></span>
</p>
<pre>setbright( u&#160;: unitptr, i&#160;: integer )
   u&#160;: the unit on which you want to change the brightness.
   i&#160;: the new brightness
</pre>
<pre>   When you want to increase / decrease the amount of light shed by a
   unit, use this function. Units with "bright" light up rooms so that
   people can see.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bplog"></span>
</p>
<pre>log( s&#160;: string )
   s&#160;: Text to put in the log.
   result: Puts text in the log for debugging purposes.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpsend"></span>
</p>
<pre>send ( s&#160;: string )
   s&#160;: Message to send.
   result: Send a message to all DIL programs in current local environment,
           matching the message class SFB_MSG. The message is not received
           by those DIL programs in the local environment that is not set up
           to wait for that message class.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpsendto"></span>
</p>
<pre>sendto ( s&#160;: string , u&#160;: unitptr )
   s&#160;: Message to send.
   u&#160;: Unit to send it to.
   result: The message is passed to all DIL programs in unit, matching the
           message class SFB_MSG. The message is not
           received by those DIL programs in the local environment that is
           not set up to wait for that message class.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpsendall"></span>
</p>
<pre>sendtoall( m&#160;: string, s&#160;: string )
   m&#160;: Message to send.
   s&#160;: Name idx to send message to.
   result: Send a message to all units matching a given database name.
</pre>
<pre><b>Example:</b>
</pre>
<pre>   sendtoall ( "some message", "rabbit@haon-dor");
</pre>
<pre>   The message "some message" is sent to all units in the world matching the
   data base name "rabbit@haon-dor". Like 'send()' and 'sendto()', the
   message received matches the SFB_MSG message class.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
<span id="bpsendalld"></span>
</p>
<pre>sendtoalldil( m&#160;: string, s&#160;: string )
   m&#160;: Message to send.
   s&#160;: Name idx to a DIL program to send message to.
   result: Send a message to all DIL programs matching a given database name.
</pre>
<pre><b>Example:</b>
</pre>
<pre>   sendtoalldil ( "some message", "intercomm@cemetery");
</pre>
<pre>   The message "some message" is sent to all DIL program in the world
   matching the data base name "intercomm@cemetery".
   Like 'send()' and 'sendto()', the
   message received matches the SFB_MSG message class.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
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
</pre>
<p><br />
<span id="bpatt_s"></span>
</p>
<pre>integer attack_spell( n&#160;: integer, caster&#160;: unitptr, medium&#160;: unitptr,
                      target&#160;: unitptr, bonus&#160;: integer)
   Returns&#160;: The amount of damage given.
   n&#160;: The spell index of the offensive spell (SPL_XXX)
   caster&#160;: The caster of the spell.
   medium&#160;: The medium, with which the spell is cast, might be caster.
   target&#160;: The target of the spell.
   bonus  : Possible (+) advantage or (-) penalty.
</pre>
<pre>   This is low-level internal spell stuff used to develop new spells. Do not
   use unless you know what you are doing and have been allowed to do so by
   your Admin.
</pre>
<p><br />
<span id="bpinsert"></span>
</p>
<pre><b>Function:  </b><i>insert( sl&#160;: &lt;stringlist or intlist&gt;, i&#160;: integer, s&#160;: string )&#160;;</i>
</pre>
<pre>  <b>sl</b>
         the stringlist or intlist you are inserting to
  <b>i</b>
         the index where you want to insert the string
  <b>s</b>
         the string you want to insert
</pre>
<pre>This function allows you to insert a string in a stringlist or intlist
with out re-writing the entire stringlist or intlist to do it.  The
following Dil will add a string in order to a stringlist.
<b>Example:</b>
<i>
---~---~---~---~---~---~---~---~---
</i></pre><i><pre>dilbegin stringlist add_in_order (sl:stringlist,s:string);
var
 i:integer;
 ln:integer;
code
{
if (length(sl)==0)
 {
 addstring (sl,s);
 return (sl);
 }
</pre></i><i><pre>ln:=length(s);
i:=0;
while (i&lt;ln)
 {
 if (length(sl.[i]) &lt;=ln)
  {
  insert (sl,i,s);
 return(sl);
 }
 i:=i+1;
 }
</pre></i><i><pre>addstring (sl,s);
return (sl);
}
dilend
</pre></i><i><pre>---~---~---~---~---~---~---~---~---
</pre></i><i></i><pre><i></i>
</pre>
<p><br />
</p>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
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
</pre>
<p><br />
<span id="bpclear"></span>
</p>
<pre>clear( i&#160;: integer )
</pre>
<pre>   Clears the interrupt number "i". If i is invalid, this will either
   clear an wrong interrupt or do nothing.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre>
<p><br />
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
</pre>
<p><br />
<span id="note"></span>
</p>
<pre>How 'Done' messages (SFB_DONE) are treated. Note that not all commands are
implemented, if you are missing one, let Papi know and it will be created.
See <a href="#docs.2Fcommand.txt">commands.txt</a> for details.
</pre></div>