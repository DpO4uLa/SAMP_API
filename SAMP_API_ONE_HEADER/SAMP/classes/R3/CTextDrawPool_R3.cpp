/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CTextDrawPool_R3.h"

SAMP::classes::CTextDrawPool::CTextDrawPool() {
	((void(__thiscall *)(CTextDrawPool *))SAMP_ADDROF(0x1E050))(this);
}

SAMP::classes::CTextDrawPool::~CTextDrawPool() {
	((void(__thiscall *)(CTextDrawPool *))SAMP_ADDROF(0x1E180))(this);
}

void SAMP::classes::CTextDrawPool::Delete(ID nId) {
	((void(__thiscall *)(CTextDrawPool *, ID))SAMP_ADDROF(0x1E0A0))(this, nId);
}

void SAMP::classes::CTextDrawPool::Draw() {
	((void(__thiscall *)(CTextDrawPool *))SAMP_ADDROF(0x1E0E0))(this);
}

SAMP::classes::CTextDraw *SAMP::classes::CTextDrawPool::Create(int nId, CTextDraw::Transmit *pData, const char *szText) {
	return ((CTextDraw *(__thiscall *)(CTextDrawPool *, int, CTextDraw::Transmit *, const char *))SAMP_ADDROF(0x1E1C0))(this, nId, pData, szText);
}

#endif