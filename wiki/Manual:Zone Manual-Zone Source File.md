<div class="mw-parser-output"><h2><span class="mw-headline" id="Zone_source_file">Zone source file</span></h2>
<p>		In this chapter we will define all the sections of a zone file
		and go in-depth on the zone info section.  Once complete with this
		chapter you should be able to create an empty yet compilable zone.
</p><p>		A zone source file is split up into 6 sections.  A
		zone-declaration section, a mobile (NPC) section, an object
		section, a room section, a reset section, and the DIL
		section.  The zone section is the only section that  has to be in the file, and
		they may appear in any order.
</p><p>		Each section is preceded by a section header. These are the  six
		possible headers:
</p>
<ul><li>%zone</li>
<li>%rooms</li>
<li>%mobiles</li>
<li>%objects</li>
<li>%reset</li>
<li>%DIL</li></ul>
<p>The  first  four sections may be considered lists of definitions.
	The reset section can be considered a program in a simple  programming
	language. And the DIL section is a bit special - it
	includes the zone templates (DIL functions that can be used from any
	zone, on anything, as opposed to "specialized" DIL functions placed
	inside a unit's
	definitions).  After all sections you are using are defined you
	must tell the compiler you are done the special symbol '%end'
	must be placed at the end of the zone for this reason.
</p>
<h3><span class="mw-headline" id="Definition_types">Definition types</span></h3>
<p>		When creating your zone there are six main building blocks.
		We call these definition types.  Each type represents some kind of
		data you want the compiler to be able to recognize.  These data
		definitions take the basic form:
</p>
<pre>	field value
</pre>
<p>Where field is the name of a data field, and value is some value.
		Values are of one of 6 types:
</p>
<dl><dt>integer</dt>
<dd>A whole number or if you are in practice of using Hex you can use the C style hex numbers in either upper or lower case (i.e 0X0f3 0x0f3)</dd>
<dt>string</dt>
<dd>Text enclosed in Double Quotes.  The string can span more than one line as it would in a description.</dd></dl>
<pre>	title "The dark dragon altar"
	descr
	"There are many things you can see and there are many things that
	can't be seen but this is still a description none the less."
</pre>
<dl><dt>stringlist</dt>
<dd>A set of strings, it can be a single string or multiple depending on your needs.</dd></dl>
<p>		These are used in names, extras, creators, and special keywords all to be
		defined later in their respective places.  These are defined in the following
		manor.
</p>
<pre>	&lt;fieldname&gt;    {"string1","string2","string3", ...}
</pre>
<dl><dt>intlist</dt>
<dd>A list of numbers which can be used with an extra.  This type works like the stringlist but doesn't need the quotes.</dd></dl>
<pre>	extra {"mynumberlist"} {1,2,3,4,5,6,7,...}
	"This is a number list attached to an extra"
</pre>
<dl><dt>flags</dt>
<dd>Like the Intlist the flag is defined with a list of numbers.  The list of numbers is not taken literally however it is combined to create one number by binary ORing the number list together.  If that confuses you don't worry, it takes some getting used to.  These types are used for Manipulation, flags, and positions.</dd></dl>
<pre>	flags {2,8}
	manipulate {8}
</pre>
<p>In the previous example the 'flags' value after this zone compiles
		would be 10 because binary oring the two flags together is a lot
		like adding.  The two numbers probably make no sense so most flags
		you use will have defines if I used the defines found in
		<i>vme.h</i> the previous example would look like this:
</p>
<pre>	flags {UNIT_FL_INVISIBILE,UNIT_FL_BURIED}
	manipulate {WEAR_BODY}
</pre>
<p>We will cover this more in-depth later but it was necessary to give
		a good overview so you understand this field type enough to recognize
		what it is when you see it.
</p>
<dl><dt>symbol</dt>
<dd>A label you reference from other parts in your zones.  Every unit (room,object,room) and even the zone itself has a unique label that can be referenced.  It is important to make symbol names that are clear so the Administrators of the mud know what each item is when using the online administration commands.</dd></dl>
<pre>	dark_sword /*good symbol*/
	rm_5892 /*Bad symbol*/
</pre>
<p>When loading items online the zone symbol and the item symbol are
		combined to create a reference to the item.  For example if our zone
		name was 'dragon' and our item was 'dark_sword' the symbolic name for
		this item would be 'dark_sword@dragon'.  Using symbols will be
		covered more in the DIL manual and in the administration manuals for
		loading objects online.  For now it is enough to understand
		symbols must follow the following rules when being defined.
</p>
<ul><li>The first letter of the</li></ul>
<p>		symbol must be a letter of the alphabet or a '_' character
</p>
<ul><li>Characters following the first can be numbers, alphabet</li></ul>
<p>		letters, and '_' characters
</p>
<ul><li>The name can be no longer than</li></ul>
<p>		15 characters
</p>
<ul><li>No reserved keywords can be used as a name</li></ul>
<p>		(Link to app-b)
</p>
<blockquote style="background-color: #E8E8E8; font-style: italic;"><p>the end tag that ends all unit definitions is also considered a symbol it is just a symbol that must be included</p></blockquote>
<p>There are two other field types that can not be defined as a
		regular field type.  These are the function reference and the
		Structure.  The function reference can be either a reference to a
		DIL function or a special function called from the
		base code.
</p>
		 <blockquote style="background-color: #E8E8E8; font-style: italic;"><p>Special functions are being replaced with DIL for better performance and should only be used when no DIL functions exist to replace them</p></blockquote>
<p>		The Structure field types are  a combination of other field types
		to make a special field type for the unit being defined.  A good example
		of this is a 'exit' for a room.  The exit has everything from flag,
		string, stringlist, and even description fields.  The exit field will be
		defined much more in-depth in the chapter on rooms but it is important
		to know some fields are considered Structure fields because they can have
		many values.  The only two Structure fields are the exit and extra
		fields which will both be defined more later because they can be used
		differently depending on what you are using them for.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-General-Compiler-Information-The-VMC-pre-processor" title="Manual:Zone Manual/General Compiler Information/The VMC pre-processor">Previous: The VMC pre-processor</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-Zone-Source-File-Zone-information-section" title="Manual:Zone Manual/Zone Source File/Zone information section">Next: Zone information section</a></div></div>