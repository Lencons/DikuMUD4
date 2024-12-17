<div class="mw-parser-output"><h3><span class="mw-headline" id="Zone_information_section">Zone information section</span></h3>
<p>		The zone information section is the only section that must
		exist in the source file of your area.  With out this section the
		compiler is unable to create the zone because frankly it doesn't
		know what to call it.  It is also the easiest of the sections to
		learn because there is only a few possible fields. The  Zone-section  defines  the global parameters for the current
		zone. It is usually wise to place this section in the top of  the
		source file to make it easy to find the zone information when editing the file.
</p>
<table class="wikitable">
<caption>Zone section field descriptions
</caption>
<tbody><tr>
<th>Field
</th>
<th>Type
</th>
<th>Description
</th></tr>
<tr>
<td>creators
</td>
<td>Stringlist
</td>
<td>This field is where you place the creators of the zone.  With
<p>	this field filled out the Administrators and builders can easily find out who
	the zone was written by and be able to contact them if there are problems.
</p>
</td></tr>
<tr>
<td>lifespan
</td>
<td>Number
</td>
<td>This  defines  the interval between resets for this zone, in minutes.
<p>	Default is 60 if this field is left out of the information section.
</p>
</td></tr>
<tr>
<td>notes
</td>
<td>String
</td>
<td>This is a plain text description of the zone for administrators and builders.
<p>	It is often a good idea to
	include your e-mail address in the  notes so you can be
	reached easily by the administrators.
</p>
</td></tr>
<tr>
<td>reset
</td>
<td>Number
</td>
<td>This combined with 'lifespan' defines if the zone will be reset.  This
<p>	field gives the condition that must be met to reset the zones you
	should use the defines in the <i>vme.h</i>,	RESET_NOT,
	RESET_IFEMPTY, and RESET_ANYHOW.  Default is RESET_ANYHOW, which
	means, the zone will be reset even if players are present within it.
</p>
</td></tr>
<tr>
<td>title
</td>
<td>String
</td>
<td>This is the title of the zone, for example Dragons Nest, Dark
<p>	station, and
	creators hide out.  It is used mainly for the areas command so
	players can get a list of all the areas in the game.  It can
	however be accessed by the 'zoneptr' variable type in DIL.  If you
	have
	a zone that spans across multiple source files you only need to
	define the title once.  If you put the title in all source files it
	will show up multiple times in the area listing.  You would also
	leave this blank if the zone should not be on the areas list like an
	administration zone.
</p>
</td></tr>
<tr>
<td>weather
</td>
<td>Integer
</td>
<td>This field sets the humidity level of the zone.  If for example you want
<p>	a hot desert like zone you would want to set this to its highest value.
	The range of this field is 1000 to -1000.  This is an optional field and
	will not be covered else where because it is simple to use.
</p>
</td></tr>
<tr>
<td>%zone
</td>
<td>Symbol
</td>
<td>This entry defines the name of the
<p>	zone. Default is the preceding  component of the current filename,
	minus the trailing ".zon". Note, the symbol should be added
	after the %zone tag, which should always be put, even if you
	do not add a symbol after it.
</p>
</td></tr></tbody></table>
<p>The only field that must exist when you go to create the zone
		information section is the '%zone'.  Leaving the '%zone' field out
		will cause an error when you try to compile it.  We suggest you
		not only put the '%zone' field but you also add a symbol or as I
		call it a zone name.  The following are three legal examples of a Zone information header.  You be the judge of
		which is more informative.
</p>
<pre>	/*very bad*/
	%zone

	/*bad but better than nothing*/
	%zone bug_planet

	/*The way it should be done!*/
	%zone dragonst
	lifespan 20
	reset RESET_ANYHOW
	creators {"whistler"}

	notes
	"This is the dragon station I shortened it to dragonst for ease in
	loading.  If you have  any questions email me at whistler@valhalla.com"

	help
	"Not sure what could help you now.  You are stuck on one of the
	weirdest space stations you have ever seen and you smell burning
	sulfur."
</pre>
<p>If you felt like it you could add a '%end' to the proceeding
		examples and compile them.  They would create an empty zone so
		wouldn't be very exciting but at least its possible.  We will not go into any compiling until we have at least one unit
		type to compile because it is pretty useless to do.
		   the next chapters will
		define the basic unit building blocks you will use for rooms,
		objects, and NPCs and start you off on compiling.
</p>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-Zone-Source-File" title="Manual:Zone Manual/Zone Source File">Previous: Zone Source File</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-Unit-Building-Blocks" title="Manual:Zone Manual/Unit Building Blocks">Next: Unit Building Blocks</a></div></div>