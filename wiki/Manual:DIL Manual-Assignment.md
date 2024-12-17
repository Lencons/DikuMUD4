<div class="mw-parser-output"><p><br />
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
</pre></div>