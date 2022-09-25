/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CFont_R3.h"

SAMP::classes::CFont::CFont() {
	((void(__thiscall *)(CFont *))SAMP_ADDROF(0x6B160))(this);
}

SAMP::classes::CFont::CFont(ID3DXFont *pFont) {
	*(void **)this = (void *)SAMP_ADDROF(0xEA3B8);
	m_pFont = pFont;
}

#endif