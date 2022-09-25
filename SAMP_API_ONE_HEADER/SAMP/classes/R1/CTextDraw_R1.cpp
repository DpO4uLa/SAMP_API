/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "CTextDraw_R1.h"

SAMP::classes::CTextDraw::CTextDraw(Transmit *pTransmit, const char *szText) {
	((void(__thiscall *)(CTextDraw *, Transmit *, const char *))SAMP_ADDROF(0xACF10))(this, pTransmit, szText);
}

SAMP::classes::CTextDraw::~CTextDraw() {
	((void(__thiscall *)(CTextDraw *))SAMP_ADDROF(0xAC860))(this);
}

void SAMP::classes::CTextDraw::SetText(const char *szText) {
	((void(__thiscall *)(CTextDraw *, const char *))SAMP_ADDROF(0xAC870))(this, szText);
}

void SAMP::classes::CTextDraw::Draw() {
	((void(__thiscall *)(CTextDraw *))SAMP_ADDROF(0xACD90))(this);
}

#endif