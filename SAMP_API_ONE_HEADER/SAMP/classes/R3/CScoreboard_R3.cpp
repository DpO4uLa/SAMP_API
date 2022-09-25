/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CScoreboard_R3.h"

SAMP::classes::CScoreboard *&SAMP::classes::pScoreboard = *(SAMP::classes::CScoreboard **)SAMP_ADDROF(0x26E894);

SAMP::classes::CScoreboard::CScoreboard(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CScoreboard *, IDirect3DDevice9 *))SAMP_ADDROF(0x6E2C0))(this, pDevice);
}

void SAMP::classes::CScoreboard::Recalc() {
	((void(__thiscall *)(CScoreboard *))SAMP_ADDROF(0x6E1C0))(this);
}

void SAMP::classes::CScoreboard::GetRect(CRect *pRect) {
	((void(__thiscall *)(CScoreboard *, CRect *))SAMP_ADDROF(0x6E220))(this, pRect);
}

void SAMP::classes::CScoreboard::Close(bool bHideCursor) {
	((void(__thiscall *)(CScoreboard *, bool))SAMP_ADDROF(0x6E270))(this, bHideCursor);
}

void SAMP::classes::CScoreboard::ResetDialogControls(CDXUTDialog *pDialog) {
	((void(__thiscall *)(CScoreboard *, CDXUTDialog *))SAMP_ADDROF(0x6E340))(this, pDialog);
}

void SAMP::classes::CScoreboard::SendNotification() {
	((void(__thiscall *)(CScoreboard *))SAMP_ADDROF(0x6E4A0))(this);
}

void SAMP::classes::CScoreboard::UpdateList() {
	((void(__thiscall *)(CScoreboard *))SAMP_ADDROF(0x6E5C0))(this);
}

void SAMP::classes::CScoreboard::Draw() {
	((void(__thiscall *)(CScoreboard *))SAMP_ADDROF(0x6E960))(this);
}

void SAMP::classes::CScoreboard::Enable() {
	((void(__thiscall *)(CScoreboard *))SAMP_ADDROF(0x6EC80))(this);
}

#endif