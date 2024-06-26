#if defined _INC_y_languages
	#endinput
#endif
#define _INC_y_languages

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

#include "..\..\YSI_Core\y_utils"

#define YSIM_U_DISABLE
#define MASTER 56
#include "..\..\YSI_Core\y_master"

#include "..\..\YSI_Coding\y_hooks"

#if !defined MAX_LANGUAGES
	#define MAX_LANGUAGES (4)
#endif

#if !defined YSI_MAX_LANGUAGES
	#define YSI_MAX_LANGUAGES (Language:MAX_LANGUAGES)
#endif

#define NO_LANGUAGE (Language:-1)

#define MAX_LANGUAGE_NAME (16)

#define Language_IsValid(%0) (Language:0 <= (%0) < YSI_MAX_LANGUAGES && YSI_g_sLanguages[(%0)][0])

//#define FOREIGN forward
//#define GLOBAL stock

static stock
	Language:YSI_g_sPlayerLanguage[MAX_PLAYERS] = {NO_LANGUAGE, ...},
	YSI_g_sLanguageCodes[YSI_MAX_STRING],
	YSI_g_sLanguages[YSI_MAX_LANGUAGES][MAX_LANGUAGE_NAME],
	Language:YSI_g_sLanguageCount = Language:0;

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

#define Langs_Add Langs_AddLanguage
#define Languages_Add Langs_AddLanguage
#define Languages_AddLanguage Langs_AddLanguage

FOREIGN__ Language:_Langs_AddLanguage(const string:code[], const string:name[]);

GLOBAL__ Language:_Langs_AddLanguage(const string:code[], const string:name[])
{
	// Get the 2 character language short code.
	P:2("_Langs_AddLanguage called: %s %s", code, name);
	static
		ins[4] = "XX|";
	if ('a' <= code[0] <= 'z')
	{
		ins[0] = code[0] & ~0x20;
	}
	else
	{
		if (!(ins[0] = code[0]))
		{
			if (strlen(name) == 2)
			{
				return _Langs_AddLanguage(name, code);
			}
			else
			{
				P:E("Langs_AddLanguage must have a 2 letter code");
				return NO_LANGUAGE;
			}
		}
	}
	if ('a' <= code[1] <= 'z')
	{
		ins[1] = code[1] & ~0x20;
	}
	else
	{
		if (!(ins[1] = code[1]))
		{
			if (strlen(name) == 2)
			{
				return _Langs_AddLanguage(name, code);
			}
			else
			{
				P:E("Langs_AddLanguage must have a 2 letter code");
				return NO_LANGUAGE;
			}
		}
	}
	if (code[2])
	{
		if (strlen(name) == 2)
		{
			return _Langs_AddLanguage(name, code);
		}
		else
		{
			P:E("Langs_AddLanguage must have a 2 letter code");
			return NO_LANGUAGE;
		}
	}
	new
		Language:add = YSI_g_sLanguageCount;
	for (new Language:i = Language:0; i != YSI_g_sLanguageCount; ++i)
	{
		if (!YSI_g_sLanguages[i][0])
		{
			// Add the new language here.
			add = i;
		}
		else if (!strcmp(YSI_g_sLanguages[i], name))
		{
			// Already exists.
			return i;
		}
	}
	if (add < YSI_MAX_LANGUAGES)
	{
		strins(YSI_g_sLanguageCodes, ins, _:add * 3);
		P:5("Langs_AddLanguage: Codes = %s", YSI_g_sLanguageCodes);
		StrCpy(YSI_g_sLanguages[add], name, MAX_LANGUAGE_NAME);
		P:5("Langs_AddLanguage: New = %s (%d, %d)", YSI_g_sLanguages[add], _:add, Language_IsValid(add));
		++YSI_g_sLanguageCount;
		return add;
	}
	return NO_LANGUAGE;
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

#if _YSIM_IS_CLIENT
	// Don't give a warning if this is a client script.  Note that stubs are
	// disabled for this script so this is the only state that makes sense.
	stock
#endif
		Language:Langs_AddLanguage(const string:code[], const string:name[])
		{
			// This is done this way to give a compiler warning when it's not used.
			return _Langs_AddLanguage(code, name);
		}
#pragma tabsize 4

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

FOREIGN__ Language:Langs_GetLanguageAt(id);

GLOBAL__ Language:Langs_GetLanguageAt(id)
{
	for (new Language:x = Language:0; x != YSI_MAX_LANGUAGES; ++x)
	{
		if (YSI_g_sLanguages[x][0])
		{
			if (!id--)
			{
				return x;
			}
		}
	}
	return NO_LANGUAGE;
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

FOREIGN__ void:Langs_RemoveLanguage(Language:l);

GLOBAL__ void:Langs_RemoveLanguage(Language:l)
{
	if (Language_IsValid(l))
	{
		// Interestingly, this library is one of the few times I have used
		// native string functions rather than hand-rolled ones (except for
		// strcat used in StrCpy).  It just so happens that they map well here.
		strdel(YSI_g_sLanguageCodes, _:l * 3, _:l * 3 + 3);
		YSI_g_sLanguages[l][0] = '\0';
		//return 1;
	}
	//return 0;
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

FOREIGN__ Language:Langs_GetLanguage(const string:identifier[]);

GLOBAL__ Language:Langs_GetLanguage(const string:identifier[])
{
	if (strlen(identifier) > 2)
	{
		// Search for the language by full name.
		for (new Language:i = Language:0; i != YSI_g_sLanguageCount; ++i)
		{
			if (YSI_g_sLanguages[i][0] && !strcmp(YSI_g_sLanguages[i], identifier, true))
			{
				return i;
			}
		}
	}
	else
	{
		// Search for the language by short name.
		new
			pos = strfind(YSI_g_sLanguageCodes, identifier, true);
		if (pos != -1)
		{
			return Language:(pos / 3);
		}
	}
	return NO_LANGUAGE;
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

FOREIGN__ Language:Langs_GetLanguageCount();

GLOBAL__ Language:Langs_GetLanguageCount()
{
	return YSI_g_sLanguageCount;
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

FOREIGN__ string:Langs_GetLanguageCodes();

GLOBAL__ string:Langs_GetLanguageCodes()
{
	// I don't quite know what this will do yet, as in how it will work...
	return YSI_g_sLanguageCodes;
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

FOREIGN__ string:Langs_GetName(Language:l);

GLOBAL__ string:Langs_GetName(Language:l)
{
	// I don't quite know what this will do yet, as in how it will work...
	new
		ret[YSI_MAX_STRING];
	if (Language_IsValid(l))
	{
		StrCpy(ret, YSI_g_sLanguages[l]);
	}
	return ret;
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

FOREIGN__ string:Langs_GetCode(Language:l);

GLOBAL__ string:Langs_GetCode(Language:l)
{
	new
		ret[YSI_MAX_STRING];
	if (Language_IsValid(l))
	{
		StrCpy(ret, YSI_g_sLanguageCodes[_:l * 3], 3);
	}
	return ret;
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

FOREIGN__ bool:Langs_IsValid(Language:l);

GLOBAL__ bool:Langs_IsValid(Language:l)
{
	return Language_IsValid(l);
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

FOREIGN__ Language:Langs_GetPlayerLanguage(playerid);

GLOBAL__ Language:Langs_GetPlayerLanguage(playerid)
{
	#if defined _YSI_SPECIAL_DEBUG
		#pragma unused playerid
		return Language:0;
	#else
		return YSI_g_sPlayerLanguage[playerid];
	#endif
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

FOREIGN__ Language:Langs_SetPlayerLanguage(playerid, Language:l);

GLOBAL__ Language:Langs_SetPlayerLanguage(playerid, Language:l)
{
	if (Language_IsValid(l))
	{
		return YSI_g_sPlayerLanguage[playerid] = l;
	}
	return NO_LANGUAGE;
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

FOREIGN__ Language:Langs_SetPlayerCode(playerid, const string:code[]);

GLOBAL__ Language:Langs_SetPlayerCode(playerid, const string:code[])
{
	return Langs_SetPlayerLanguage(playerid, Langs_GetLanguage(code));
}

/*-------------------------------------------------------------------------*//**
 * <summary>-</summary>
 *//*------------------------------------------------------------------------**/

MASTER_HOOK__ OnPlayerConnect(playerid)
{
	for (new Language:i = Language:0; i != YSI_g_sLanguageCount; ++i)
	{
		//printf("%s", YSI_g_sLanguages[i]);
		if (YSI_g_sLanguages[i][0])
		{
			// They have to default to some language, may as well be the first
			// valid one.
			YSI_g_sPlayerLanguage[playerid] = i;
			// May also add some special functions here to display the language
			// messages to a player in all languages, but I think that would be
			// better left to the mode writer, then they can integrate it in to
			// their own mode introduction.
			return 1;
		}
	}
	P:E("No languages set");
	return 0;
}

#include "..\..\YSI_Core\y_master"

