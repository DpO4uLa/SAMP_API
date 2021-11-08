/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "CLabel.h"

SAMP::classes::CLabel *&SAMP::classes::pLabel = *(SAMP::classes::CLabel **)SAMP_ADDROF(0x21A0C0);

SAMP::classes::CLabel::CLabel(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CLabel *, IDirect3DDevice9 *))SAMP_ADDROF(0x674D0))(this, pDevice);
}

SAMP::classes::CLabel::~CLabel() {
	((void(__thiscall *)(CLabel *))SAMP_ADDROF(0x674F0))(this);
}

void SAMP::classes::CLabel::Begin() {
	((void(__thiscall *)(CLabel *))SAMP_ADDROF(0x67590))(this);
}

void SAMP::classes::CLabel::End() {
	((void(__thiscall *)(CLabel *))SAMP_ADDROF(0x675A0))(this);
}

void SAMP::classes::CLabel::OnLostDevice() {
	((void(__thiscall *)(CLabel *))SAMP_ADDROF(0x67510))(this);
}

void SAMP::classes::CLabel::OnResetDevice() {
	((void(__thiscall *)(CLabel *))SAMP_ADDROF(0x67520))(this);
}

void SAMP::classes::CLabel::Draw(CVector *pPosition, const char *szText, D3DCOLOR color, BOOL bShadow, bool bNoObstacles) {
	((void(__thiscall *)(CLabel *, CVector *, const char *, D3DCOLOR, bool, bool))SAMP_ADDROF(0x675B0))(this, pPosition, szText, color, bShadow, bNoObstacles);
}

BOOL SAMP::classes::CLabel::HasNoObstacles(CVector position) {
	return ((BOOL(__thiscall *)(CLabel *, CVector))SAMP_ADDROF(0x67530))(this, position);
}