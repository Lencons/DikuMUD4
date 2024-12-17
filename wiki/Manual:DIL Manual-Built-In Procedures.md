<div class="mw-parser-output"><p><br />
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
</pre></div>