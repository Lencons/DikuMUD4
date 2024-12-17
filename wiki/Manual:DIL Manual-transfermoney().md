<div class="mw-parser-output"><p><br />
<span id="bftranmon"></span>
</p>
<pre>integer transfermoney( f&#160;: unitptr, t&#160;: unitptr, amount&#160;: integer)
   f&#160;: The char the money is taken from
   t&#160;: The char the money is given to
   amount&#160;: How much money.
   Returns: TRUE is money was transferred, FALSE if could not afford.
</pre>
<pre>   If 'f' is null and 't' isn't, then money is created and given to 't'.
   If 'f' isn't null but 't' is, then money is removed from 'f'.
</pre>
<pre>---~---~---~---~---~---~---~---~---
</pre></div>