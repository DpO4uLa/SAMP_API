/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CTextDraw_R3.h"

SAMP::classes::CTextDraw::CTextDraw(Transmit *pData, const char *szText) {
	((void(__thiscall *)(CTextDraw *, Transmit *, const char *))SAMP_ADDROF(0xB2E50))(this, pData, szText);
}

SAMP::classes::CTextDraw::~CTextDraw() {
	((void(__thiscall *)(CTextDraw *))SAMP_ADDROF(0xB26C0))(this);
}

void SAMP::classes::CTextDraw::SetText(const char *szText) {
	((void(__thiscall *)(CTextDraw *, const char *))SAMP_ADDROF(0xB26D0))(this, szText);
}

void SAMP::classes::CTextDraw::Draw() {
	((void(__thiscall *)(CTextDraw *))SAMP_ADDROF(0xB2BF0))(this);
}

#endif