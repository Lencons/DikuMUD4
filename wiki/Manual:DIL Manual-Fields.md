<div class="mw-parser-output"><p><br />
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
</pre></div>