<div class="mw-parser-output"><p><br />
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
</pre></div>