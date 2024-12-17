<div class="mw-parser-output"><h1><span id="integer_shell(str_:_string);"></span><span class="mw-headline" id="integer_shell.28str_:_string.29.3B">integer shell(str&#160;: string);</span></h1>
<pre> str     : The system command to execute and its parameters.
 result  : Will return 0 if a thread is successfully created. You won't know if the system command succeeded.
</pre>
<p><b>Examples</b>
</p>
<pre> rc&#160;:= shell("gh --subject hello");
</pre>
<p>This command would execute the vme/bin/allow/gh binary with the parameters shown above.
If rc is zero then the thread was created successfully. But you wont know if the binary
was executed (the server doesn't wait for it to finish).
</p><p>Using shell() you cannot directly execute any commands outside the allow/ directory.
</p></div>