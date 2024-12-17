<div class="mw-parser-output"><p><br />
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
</pre></div>