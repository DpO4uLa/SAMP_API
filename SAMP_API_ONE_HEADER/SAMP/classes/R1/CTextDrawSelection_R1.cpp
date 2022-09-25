/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "CTextDrawSelection_R1.h"

SAMP::classes::CTextDrawSelection *&SAMP::classes::pTextdrawSelection = *(SAMP::classes::CTextDrawSelection **)SAMP_ADDROF(0x21A0CC);

BOOL SAMP::classes::CTextDrawSelection::MsgProc(int uMsg, int wParam, int lParam) {
	return ((BOOL(__thiscall *)(CTextDrawSelection *, int, int, int))SAMP_ADDROF(0x6CF90))(this, uMsg, wParam, lParam);
}

void SAMP::classes::CTextDrawSelection::Disable() {
	((void(__thiscall *)(CTextDrawSelection *))SAMP_ADDROF(0x6CF40))(this);
}

void SAMP::classes::CTextDrawSelection::SendNotification() {
	((void(__thiscall *)(CTextDrawSelection *))SAMP_ADDROF(0x6CEA0))(this);
}

void SAMP::classes::CTextDrawSelection::Enable(D3DCOLOR hoveredColor) {
	((void(__thiscall *)(CTextDrawSelection *, D3DCOLOR))SAMP_ADDROF(0x6CE60))(this, hoveredColor);
}

void SAMP::classes::CTextDrawSelection::ResetTextDraws() {
	((void(__thiscall *)(CTextDrawSelection *))SAMP_ADDROF(0x6CCD0))(this);
}

void SAMP::classes::CTextDrawSelection::RawProcess() {
	((void(__thiscall *)(CTextDrawSelection *))SAMP_ADDROF(0x6CD30))(this);
}

void SAMP::classes::CTextDrawSelection::Process() {
	((void(__thiscall *)(CTextDrawSelection *))SAMP_ADDROF(0x6CE30))(this);
}

#endif