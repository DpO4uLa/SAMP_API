/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CLabel_R3.h"

SAMP::classes::CLabel *&SAMP::classes::pLabel = *(SAMP::classes::CLabel **)SAMP_ADDROF(0x26E8A4);

SAMP::classes::CLabel::CLabel(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CLabel *, IDirect3DDevice9 *))SAMP_ADDROF(0x6B440))(this, pDevice);
}

SAMP::classes::CLabel::~CLabel() {
	((void(__thiscall *)(CLabel *))SAMP_ADDROF(0x6B460))(this);
}

void SAMP::classes::CLabel::OnLostDevice() {
	((void(__thiscall *)(CLabel *))SAMP_ADDROF(0x6B480))(this);
}

void SAMP::classes::CLabel::OnResetDevice() {
	((void(__thiscall *)(CLabel *))SAMP_ADDROF(0x6B490))(this);
}

BOOL SAMP::classes::CLabel::HasNoObstacles(CVector position) {
	return ((BOOL(__thiscall *)(CLabel *, CVector))SAMP_ADDROF(0x6B4A0))(this, position);
}

void SAMP::classes::CLabel::Begin() {
	((void(__thiscall *)(CLabel *))SAMP_ADDROF(0x6B500))(this);
}

void SAMP::classes::CLabel::End() {
	((void(__thiscall *)(CLabel *))SAMP_ADDROF(0x6B510))(this);
}

void SAMP::classes::CLabel::Draw(CVector *pPosition, const char *szText, D3DCOLOR color, BOOL bShadow, bool bNoObstacles) {
	((void(__thiscall *)(CLabel *, CVector *, const char *, D3DCOLOR, BOOL, bool))SAMP_ADDROF(0x6B520))(this, pPosition, szText, color, bShadow, bNoObstacles);
}

#endif