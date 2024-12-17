<div class="mw-parser-output"><p><br />
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
</pre></div>