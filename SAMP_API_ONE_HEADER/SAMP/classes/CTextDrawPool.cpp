/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "CTextDrawPool.h"

SAMP::classes::CTextDrawPool::CTextDrawPool() {
	((void(__thiscall *)(CTextDrawPool *))SAMP_ADDROF(0x1ACB0))(this);
}

SAMP::classes::CTextDrawPool::~CTextDrawPool() {
	((void(__thiscall *)(CTextDrawPool *))SAMP_ADDROF(0x1ADE0))(this);
}

SAMP::classes::CTextDraw *SAMP::classes::CTextDrawPool::Create(int nId, CTextDraw::Transmit *pTransmit, const char *szText) {
	return ((CTextDraw *(__thiscall *)(CTextDrawPool *, int, CTextDraw::Transmit *, const char *))SAMP_ADDROF(0x1AE20))(this, nId, pTransmit, szText);
}

void SAMP::classes::CTextDrawPool::Delete(ID nId) {
	((void(__thiscall *)(CTextDrawPool *, ID))SAMP_ADDROF(0x1AD00))(this, nId);
}

void SAMP::classes::CTextDrawPool::Draw() {
	((void(__thiscall *)(CTextDrawPool *))SAMP_ADDROF(0x1AD40))(this);
}
