<div class="mw-parser-output"><p><br />
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
</pre></div>