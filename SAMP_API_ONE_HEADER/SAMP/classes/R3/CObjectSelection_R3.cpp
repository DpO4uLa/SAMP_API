/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CObjectSelection_R3.h"

SAMP::classes::CObjectSelection *&SAMP::classes::pObjectSelection = *(SAMP::classes::CObjectSelection **)SAMP_ADDROF(0x26E8AC);

SAMP::classes::CObjectSelection::CObjectSelection() {
	((void(__thiscall *)(CObjectSelection *))SAMP_ADDROF(0x6D290))(this);
}

SAMP::classes::ID SAMP::classes::CObjectSelection::DefineObject() {
	return ((ID(__thiscall *)(CObjectSelection *))SAMP_ADDROF(0x6D2A0))(this);
}

void SAMP::classes::CObjectSelection::DrawLabels() {
	((void(__thiscall *)(CObjectSelection *))SAMP_ADDROF(0x6D2F0))(this);
}

void SAMP::classes::CObjectSelection::Enable(BOOL bEnable) {
	((void(__thiscall *)(CObjectSelection *, BOOL))SAMP_ADDROF(0x6D410))(this, bEnable);
}

void SAMP::classes::CObjectSelection::Draw() {
	((void(__thiscall *)(CObjectSelection *))SAMP_ADDROF(0x6D490))(this);
}

void SAMP::classes::CObjectSelection::SendNotification() {
	((void(__thiscall *)(CObjectSelection *))SAMP_ADDROF(0x6D560))(this);
}

BOOL SAMP::classes::CObjectSelection::MsgProc(int uMsg, int wParam, int lParam) {
	return ((BOOL(__thiscall *)(CObjectSelection *, int, int, int))SAMP_ADDROF(0x6D6D0))(this, uMsg, wParam, lParam);
}

#endif