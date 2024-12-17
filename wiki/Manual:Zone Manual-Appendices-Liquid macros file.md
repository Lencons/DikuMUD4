<div class="mw-parser-output"><h4><span class="mw-headline" id="Liquid_macros_file">Liquid macros file</span></h4>
<pre>	#define LIQ_WATER(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("clear", WEIGHT,CAPACITY,INSIDE,10,1,0,POISON)
	#define LIQ_BEER(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("brown", WEIGHT,CAPACITY,INSIDE,5,2,3,POISON)
	#define LIQ_WINE(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("clear", WEIGHT,CAPACITY,INSIDE,5,2,5,POISON)
	#define LIQ_ALE(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("brown", WEIGHT,CAPACITY,INSIDE,5,2,2,POISON)
	#define LIQ_DARK_ALE(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("dark brown", WEIGHT,CAPACITY,INSIDE,5,2,1,POISON)
	#define LIQ_WISKEY(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("golden",WEIGHT ,CAPACITY,INSIDE,4,1,6,POISON)
	#define LIQ_WHISKY(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("golden",WEIGHT ,CAPACITY,INSIDE,4,1,6,POISON)

	#define LIQ_LEMONADE(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("red", WEIGHT, CAPACITY, INSIDE, 8, 1, 0,POISON)
	#define LIQ_FIREBRT(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("green", WEIGHT,CAPACITY,INSIDE,0,0,10,POISON)
	#define LIQ_LOCALSPC(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("clear", WEIGHT, CAPACITY, INSIDE, 3, 3, 3,POISON)
	#define LIQ_SLIME(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("light green", WEIGHT,CAPACITY,INSIDE,8,4,0,POISON)
	#define LIQ_MILK(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("white", WEIGHT, CAPACITY, INSIDE, 6, 3, 0,POISON)
	#define LIQ_TEA(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("brown", WEIGHT, CAPACITY, INSIDE, 6, 1, 0,POISON)
	#define LIQ_COFFEE(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("black", WEIGHT, CAPACITY, INSIDE, 6, 1, 0,POISON)
	#define LIQ_COFFE(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("black", WEIGHT, CAPACITY, INSIDE, 6, 1, 0,POISON)

	#define LIQ_BLOOD(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("red", WEIGHT, CAPACITY, INSIDE, -1, 2, 0, POISON)
	#define LIQ_SALTWAT(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("clear", WEIGHT, CAPACITY, INSIDE, 2, 1, 0, POISON)
	#define LIQ_COKE(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("black", WEIGHT, CAPACITY, INSIDE, 5, 1, 0,POISON)
	#define LIQ_VODKA(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("clear", WEIGHT,CAPACITY,INSIDE,0,0,10,POISON)
	#define LIQ_BRANDY(WEIGHT,CAPACITY,INSIDE,POISON) \
			LIQ_DEF("golden", WEIGHT,CAPACITY,INSIDE,4,1,6,POISON)
</pre>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: left;float:left;width:50%;"><a href="./Manual:Zone-Manual-Appendices-weapon-definitions-in-values.h" title="Manual:Zone Manual/Appendices/weapon definitions in values.h">Previous: weapon definitions in values.h</a></div>
<div style="padding-top: 30px; padding-bottom: 20px; text-align: right;float:right;width:50%;"><a href="./Manual:Zone-Manual-Appendices-Complete-magical-transfers-macros-listing" title="Manual:Zone Manual/Appendices/Complete magical transfers macros listing">Next: Complete magical transfers macros listing</a></div></div>