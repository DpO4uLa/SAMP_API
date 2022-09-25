/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "CObjectSelection_R1.h"

SAMP::classes::CObjectSelection *&SAMP::classes::pObjectSelection = *(SAMP::classes::CObjectSelection **)SAMP_ADDROF(0x21A0C8);

SAMP::classes::CObjectSelection::CObjectSelection() {
	((void(__thiscall *)(CObjectSelection *))SAMP_ADDROF(0x69320))(this);
}

SAMP::classes::ID SAMP::classes::CObjectSelection::DefineObject() {
	return ((ID(__thiscall *)(CObjectSelection *))SAMP_ADDROF(0x69330))(this);
}

void SAMP::classes::CObjectSelection::DrawLabels() {
	((void(__thiscall *)(CObjectSelection *))SAMP_ADDROF(0x69380))(this);
}

void SAMP::classes::CObjectSelection::Enable(BOOL bEnable) {
	((void(__thiscall *)(CObjectSelection *, BOOL))SAMP_ADDROF(0x694A0))(this, bEnable);
}

void SAMP::classes::CObjectSelection::Draw() {
	((void(__thiscall *)(CObjectSelection *))SAMP_ADDROF(0x69520))(this);
}

void SAMP::classes::CObjectSelection::SendNotification() {
	((void(__thiscall *)(CObjectSelection *))SAMP_ADDROF(0x695F0))(this);
}

BOOL SAMP::classes::CObjectSelection::MsgProc(int uMsg, int wParam, int lParam) {
	return ((BOOL(__thiscall *)(CObjectSelection *, int, int, int))SAMP_ADDROF(0x69760))(this, uMsg, wParam, lParam);
}

#endif