<div class="mw-parser-output"><pre>unitptr findroom ( s&#160;: string )
   s&#160;: Symbolic name of room.
   return: A pointer to the room, or null
   Example: findroom("inn@udgaard")
</pre>
<p>Will return the unitptr to the room. If the symbolic name is not a room then NULL will
be returned.  Using findsymbolic(#) is equally efficient and does the same except it
returns any type. This function is really mostly here for historical reasons.
</p></div>