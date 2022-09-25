/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CGangZonePool_R3.h"

SAMP::classes::CGangZonePool::CGangZonePool() {
	((void(__thiscall *)(CGangZonePool *))SAMP_ADDROF(0x2100))(this);
}

SAMP::classes::CGangZonePool::~CGangZonePool() {
	((void(__thiscall *)(CGangZonePool *))SAMP_ADDROF(0x2130))(this);
}

void SAMP::classes::CGangZonePool::Create(ID nId, float left, float top, float right, float bottom, D3DCOLOR color) {
	((void(__thiscall *)(CGangZonePool *, ID, float, float, float, float, D3DCOLOR))SAMP_ADDROF(0x2160))(this, nId, left, top, right, bottom, color);
}

void SAMP::classes::CGangZonePool::StartFlashing(ID nId, D3DCOLOR color) {
	((void(__thiscall *)(CGangZonePool *, ID, D3DCOLOR))SAMP_ADDROF(0x21E0))(this, nId, color);
}

void SAMP::classes::CGangZonePool::StopFlashing(ID nId) {
	((void(__thiscall *)(CGangZonePool *, ID))SAMP_ADDROF(0x2200))(this, nId);
}

void SAMP::classes::CGangZonePool::Delete(ID nId) {
	((void(__thiscall *)(CGangZonePool *, ID))SAMP_ADDROF(0x2220))(this, nId);
}

void SAMP::classes::CGangZonePool::Draw() {
	((void(__thiscall *)(CGangZonePool *))SAMP_ADDROF(0x2250))(this);
}

#endif