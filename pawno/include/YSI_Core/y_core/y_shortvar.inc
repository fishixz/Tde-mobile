/*+
 * <library name="y_shortvar">
 * <section>
 *  Description
 * </section>
 *  Declares a few variables with very short names, used all over YSI.
 * <section>
 *  Version
 * </section>
 *  0.2
 * </library>
 *//** *//*
Legal:
	Version: MPL 1.1
	
	The contents of this file are subject to the Mozilla Public License Version 
	1.1 the "License"; you may not use this file except in compliance with 
	the License. You may obtain a copy of the License at 
	http://www.mozilla.org/MPL/
	
	Software distributed under the License is distributed on an "AS IS" basis,
	WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
	for the specific language governing rights and limitations under the
	License.
	
	The Original Code is the YSI framework.
	
	The Initial Developer of the Original Code is Alex "Y_Less" Cole.
	Portions created by the Initial Developer are Copyright C 2011
	the Initial Developer. All Rights Reserved.

Contributors:
	Y_Less
	koolk
	JoeBullet/Google63
	g_aSlice/Slice
	Misiur
	samphunter
	tianmeta
	maddinat0r
	spacemud
	Crayder
	Dayvison
	Ahmad45123
	Zeex
	irinel1996
	Yiin-
	Chaprnks
	Konstantinos
	Masterchen09
	Southclaws
	PatchwerkQWER
	m0k1
	paulommu
	udan111
	Cheaterman

Thanks:
	JoeBullet/Google63 - Handy arbitrary ASM jump code using SCTRL.
	ZeeX - Very productive conversations.
	koolk - IsPlayerinAreaEx code.
	TheAlpha - Danish translation.
	breadfish - German translation.
	Fireburn - Dutch translation.
	yom - French translation.
	50p - Polish translation.
	Zamaroht - Spanish translation.
	Los - Portuguese translation.
	Dracoblue, sintax, mabako, Xtreme, other coders - Producing other modes for
		me to strive to better.
	Pixels^ - Running XScripters where the idea was born.
	Matite - Pestering me to release it and using it.

Very special thanks to:
	Thiadmer - PAWN, whose limits continue to amaze me!
	Kye/Kalcor - SA:MP.
	SA:MP Team past, present and future - SA:MP.

Optional plugins:
	Gamer_Z - GPS.
	Incognito - Streamer.
	Me - sscanf2, fixes2, Whirlpool.
*/

// VERY VERY VERY IMPORTANT!!! y_text uses "144" explicitly.  Change it too.
#define YSI_MAX_STRING (144)
#if YSI_MAX_STRING != 144
	#error Please update all explicit YSI_MAX_STRING uses.
#endif

#if !defined YSIM_STRING
	#define YSIM_STRING (1000)
#endif

new
	Q@[YSI_MAX_STRING];

// J@ is a "nul" target - send things there if they need ignoring or if a
// parameter needs using.  I@ is too now.
stock
	I@ = 0,
	J@ = 0;

#if !defined MAX_LANGUAGES
	#define MAX_LANGUAGES (4)
#endif

stock
	YSI_gUnsafeHugeString[MAX_LANGUAGES][2048];

#define YSI_UNSAFE_HUGE_STRING (YSI_gUnsafeHugeString[0])
#define YSI_UNSAFE_HUGE_LENGTH (MAX_LANGUAGES * sizeof (YSI_gUnsafeHugeString[]))

// Used by y_master and y_remote.  Re-evaluate after rewrites.
native U@(id = 0, const name[] = "", value = cellmin, const string[] = "") = setproperty;
native V@(GLOBAL_TAG_TYPES:id = 0, const name[] = "", value = cellmin, string[] = "") = getproperty;

#if defined OPENMP
	native R@(const function[], const format[], GLOBAL_TAG_TYPES:...) = Script_Call;
	native W@(const function[], const format[], GLOBAL_TAG_TYPES:...) = Script_CallAll;
	native O@(const function[], time, repeat, const format[] = "", GLOBAL_TAG_TYPES:...) = SetTimerEx;
#else
	// Define this command with basically every strong tag in existence to avoid
	// tag mismatch warnings with remote functions with strong tag parameters.
	native R@(const function[], const format[], GLOBAL_TAG_TYPES:...) = CallLocalFunction;
	native W@(const function[], const format[], GLOBAL_TAG_TYPES:...) = CallRemoteFunction;
	native O@(const function[], time, repeat, const format[] = "", GLOBAL_TAG_TYPES:...) = SetTimerEx;
#endif

#if !__COMPILER_MODIFIED
	forward _@_y_shortvar_@_();

	public _@_y_shortvar_@_()
	{
		new tmp[2];
		// This function calls any functions used in assembly code in YSI to ensure
		// that they are included in the native function table.
		R@(tmp, tmp);
		W@(tmp, tmp);
		O@(tmp, 0, false);
	}
#endif
#define DONT_USE(%9);}%9(){} }

#if !defined TRUE
stock const
	bool:TRUE = true;
#endif

#if !defined FALSE
stock const
	bool:FALSE = false;
#endif

#if !defined NULL
stock const
	NULL[2] = "\1";
#endif

stock const
	YSI_SPACE[] = " ",
	YSI_EMPTY[] = "";

