<div class="mw-parser-output"><p><br />
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
</pre></div>