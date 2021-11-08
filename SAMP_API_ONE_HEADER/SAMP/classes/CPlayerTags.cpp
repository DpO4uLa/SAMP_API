/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "CPlayerTags.h"

SAMP::classes::CPlayerTags *&SAMP::classes::pPlayerTags = *(SAMP::classes::CPlayerTags **)SAMP_ADDROF(0x21A0B0);

SAMP::classes::CPlayerTags::CPlayerTags(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CPlayerTags *, IDirect3DDevice9 *))SAMP_ADDROF(0x68610))(this, pDevice);
}

SAMP::classes::CPlayerTags::~CPlayerTags() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x68640))(this);
}

void SAMP::classes::CPlayerTags::BeginLabel() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x686A0))(this);
}

void SAMP::classes::CPlayerTags::DrawLabel(CVector *pPosition, const char *szText, D3DCOLOR color, float fDistanceToCamera, bool bDrawStatus, int nStatus) {
	((void(__thiscall *)(CPlayerTags *, CVector *, const char *, D3DCOLOR, float, bool, int))SAMP_ADDROF(0x686C0))(this, pPosition, szText, color, fDistanceToCamera, bDrawStatus, nStatus);
}

void SAMP::classes::CPlayerTags::EndLabel() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x686B0))(this);
}

void SAMP::classes::CPlayerTags::BeginHealthBar() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x68FD0))(this);
}

void SAMP::classes::CPlayerTags::DrawHealthBar(CVector *pPosition, float fHealth, float fArmour, float fDistanceToCamera) {
	((void(__thiscall *)(CPlayerTags *, CVector *, float, float, float))SAMP_ADDROF(0x689C0))(this, pPosition, fHealth, fArmour, fDistanceToCamera);
}

void SAMP::classes::CPlayerTags::EndHealthBar() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x68670))(this);
}

void SAMP::classes::CPlayerTags::OnLostDevice() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x68F70))(this);
}

void SAMP::classes::CPlayerTags::OnResetDevice() {
	((void(__thiscall *)(CPlayerTags *))SAMP_ADDROF(0x68FA0))(this);
}