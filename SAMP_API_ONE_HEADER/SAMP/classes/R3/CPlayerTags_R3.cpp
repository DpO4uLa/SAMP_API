/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CPlayerTags_R3.h"

SAMP::classes::CPlayerTags *&SAMP::classes::pPlayerTags = *(SAMP::classes::CPlayerTags **)SAMP_ADDROF(0x26E890);

SAMP::classes::CPlayerTags::CPlayerTags(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CPlayerTags *, IDirect3DDevice9 *))SAMP_ADDROF(0x6C580))(this, pDevice);
}

SAMP::classes::CPlayerTags::~CPlayerTags() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x6C5B0))(this);
}

void SAMP::classes::CPlayerTags::EndHealthBar() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x6C5E0))(this);
}

void SAMP::classes::CPlayerTags::BeginLabel() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x6C610))(this);
}

void SAMP::classes::CPlayerTags::EndLabel() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x6C620))(this);
}

void SAMP::classes::CPlayerTags::DrawLabel(CVector *pPosition, const char *szText, D3DCOLOR color, float fDistanceToCamera, bool bDrawStatus, int nStatus) {
	((void(__thiscall *)(CPlayerTags *, CVector *, const char *, D3DCOLOR, float, bool, int))SAMP_ADDROF(0x6C630))(this, pPosition, szText, color, fDistanceToCamera, bDrawStatus, nStatus);
}

void SAMP::classes::CPlayerTags::DrawHealthBar(CVector *pPosition, float fHealth, float fArmour, float fDistanceToCamera) {
	((void(__thiscall *)(CPlayerTags *, CVector *, float, float, float))SAMP_ADDROF(0x6C930))(this, pPosition, fHealth, fArmour, fDistanceToCamera);
}

void SAMP::classes::CPlayerTags::OnLostDevice() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x6CEE0))(this);
}

void SAMP::classes::CPlayerTags::OnResetDevice() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x6CF10))(this);
}

void SAMP::classes::CPlayerTags::BeginHealthBar() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x6CF40))(this);
}

#endif