/*
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

#if defined _inc__stack_push_003
	#undef _inc__stack_push_003
#endif

#undef _YSIM_PUSH_INDEX
#define _YSIM_PUSH_INDEX 4
#if defined _YSIM_STACK_SLOT_3
	#undef _YSIM_STACK_SLOT_3
#endif
#if     _MASTER == 0
	#define _YSIM_STACK_SLOT_3 0
	#endinput
#elseif _MASTER == 1
	#define _YSIM_STACK_SLOT_3 1
	#endinput
#elseif _MASTER == 2
	#define _YSIM_STACK_SLOT_3 2
	#endinput
#elseif _MASTER == 3
	#define _YSIM_STACK_SLOT_3 3
	#endinput
#elseif _MASTER == 4
	#define _YSIM_STACK_SLOT_3 4
	#endinput
#elseif _MASTER == 5
	#define _YSIM_STACK_SLOT_3 5
	#endinput
#elseif _MASTER == 6
	#define _YSIM_STACK_SLOT_3 6
	#endinput
#elseif _MASTER == 7
	#define _YSIM_STACK_SLOT_3 7
	#endinput
#elseif _MASTER == 8
	#define _YSIM_STACK_SLOT_3 8
	#endinput
#elseif _MASTER == 9
	#define _YSIM_STACK_SLOT_3 9
	#endinput
#elseif _MASTER == 10
	#define _YSIM_STACK_SLOT_3 10
	#endinput
#elseif _MASTER == 11
	#define _YSIM_STACK_SLOT_3 11
	#endinput
#elseif _MASTER == 12
	#define _YSIM_STACK_SLOT_3 12
	#endinput
#elseif _MASTER == 13
	#define _YSIM_STACK_SLOT_3 13
	#endinput
#elseif _MASTER == 14
	#define _YSIM_STACK_SLOT_3 14
	#endinput
#elseif _MASTER == 15
	#define _YSIM_STACK_SLOT_3 15
	#endinput
#elseif _MASTER == 16
	#define _YSIM_STACK_SLOT_3 16
	#endinput
#elseif _MASTER == 17
	#define _YSIM_STACK_SLOT_3 17
	#endinput
#elseif _MASTER == 18
	#define _YSIM_STACK_SLOT_3 18
	#endinput
#elseif _MASTER == 19
	#define _YSIM_STACK_SLOT_3 19
	#endinput
#elseif _MASTER == 20
	#define _YSIM_STACK_SLOT_3 20
	#endinput
#elseif _MASTER == 21
	#define _YSIM_STACK_SLOT_3 21
	#endinput
#elseif _MASTER == 22
	#define _YSIM_STACK_SLOT_3 22
	#endinput
#elseif _MASTER == 23
	#define _YSIM_STACK_SLOT_3 23
	#endinput
#elseif _MASTER == 24
	#define _YSIM_STACK_SLOT_3 24
	#endinput
#elseif _MASTER == 25
	#define _YSIM_STACK_SLOT_3 25
	#endinput
#elseif _MASTER == 26
	#define _YSIM_STACK_SLOT_3 26
	#endinput
#elseif _MASTER == 27
	#define _YSIM_STACK_SLOT_3 27
	#endinput
#elseif _MASTER == 28
	#define _YSIM_STACK_SLOT_3 28
	#endinput
#elseif _MASTER == 29
	#define _YSIM_STACK_SLOT_3 29
	#endinput
#elseif _MASTER == 30
	#define _YSIM_STACK_SLOT_3 30
	#endinput
#elseif _MASTER == 31
	#define _YSIM_STACK_SLOT_3 31
	#endinput
#elseif _MASTER == 32
	#define _YSIM_STACK_SLOT_3 32
	#endinput
#elseif _MASTER == 33
	#define _YSIM_STACK_SLOT_3 33
	#endinput
#elseif _MASTER == 34
	#define _YSIM_STACK_SLOT_3 34
	#endinput
#elseif _MASTER == 35
	#define _YSIM_STACK_SLOT_3 35
	#endinput
#elseif _MASTER == 36
	#define _YSIM_STACK_SLOT_3 36
	#endinput
#elseif _MASTER == 37
	#define _YSIM_STACK_SLOT_3 37
	#endinput
#elseif _MASTER == 38
	#define _YSIM_STACK_SLOT_3 38
	#endinput
#elseif _MASTER == 39
	#define _YSIM_STACK_SLOT_3 39
	#endinput
#elseif _MASTER == 40
	#define _YSIM_STACK_SLOT_3 40
	#endinput
#elseif _MASTER == 41
	#define _YSIM_STACK_SLOT_3 41
	#endinput
#elseif _MASTER == 42
	#define _YSIM_STACK_SLOT_3 42
	#endinput
#elseif _MASTER == 43
	#define _YSIM_STACK_SLOT_3 43
	#endinput
#elseif _MASTER == 44
	#define _YSIM_STACK_SLOT_3 44
	#endinput
#elseif _MASTER == 45
	#define _YSIM_STACK_SLOT_3 45
	#endinput
#elseif _MASTER == 46
	#define _YSIM_STACK_SLOT_3 46
	#endinput
#elseif _MASTER == 47
	#define _YSIM_STACK_SLOT_3 47
	#endinput
#elseif _MASTER == 48
	#define _YSIM_STACK_SLOT_3 48
	#endinput
#elseif _MASTER == 49
	#define _YSIM_STACK_SLOT_3 49
	#endinput
#elseif _MASTER == 50
	#define _YSIM_STACK_SLOT_3 50
	#endinput
#elseif _MASTER == 51
	#define _YSIM_STACK_SLOT_3 51
	#endinput
#elseif _MASTER == 52
	#define _YSIM_STACK_SLOT_3 52
	#endinput
#elseif _MASTER == 53
	#define _YSIM_STACK_SLOT_3 53
	#endinput
#elseif _MASTER == 54
	#define _YSIM_STACK_SLOT_3 54
	#endinput
#elseif _MASTER == 55
	#define _YSIM_STACK_SLOT_3 55
	#endinput
#elseif _MASTER == 56
	#define _YSIM_STACK_SLOT_3 56
	#endinput
#elseif _MASTER == 57
	#define _YSIM_STACK_SLOT_3 57
	#endinput
#elseif _MASTER == 58
	#define _YSIM_STACK_SLOT_3 58
	#endinput
#elseif _MASTER == 59
	#define _YSIM_STACK_SLOT_3 59
	#endinput
#elseif _MASTER == 60
	#define _YSIM_STACK_SLOT_3 60
	#endinput
#elseif _MASTER == 61
	#define _YSIM_STACK_SLOT_3 61
	#endinput
#elseif _MASTER == 62
	#define _YSIM_STACK_SLOT_3 62
	#endinput
#elseif _MASTER == 63
	#define _YSIM_STACK_SLOT_3 63
	#endinput
#endif

