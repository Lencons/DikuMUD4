<div class="mw-parser-output"><h1><span id="secure_(_u_:_unitptr_,_label)"></span><span class="mw-headline" id="secure_.28_u_:_unitptr_.2C_label.29">secure ( u&#160;: unitptr , label)</span></h1>
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
</pre></div>