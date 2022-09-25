/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CLicensePlate_R3.h"

SAMP::classes::CLicensePlate *&SAMP::classes::pLicensePlateManager = *(SAMP::classes::CLicensePlate **)SAMP_ADDROF(0x26E8E8);

SAMP::classes::CLicensePlate::CLicensePlate(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CLicensePlate *, IDirect3DDevice9 *))SAMP_ADDROF(0x6D240))(this, pDevice);
}

SAMP::classes::CLicensePlate::~CLicensePlate() {
	((void(__thiscall *)(CLicensePlate *))SAMP_ADDROF(0x6D270))(this);
}

void SAMP::classes::CLicensePlate::OnLostDevice() {
	((void(__thiscall *)(CLicensePlate *))SAMP_ADDROF(0x6D040))(this);
}

void SAMP::classes::CLicensePlate::OnResetDevice() {
	((void(__thiscall *)(CLicensePlate *))SAMP_ADDROF(0x6D090))(this);
}

IDirect3DTexture9 *SAMP::classes::CLicensePlate::Create(const char *szText) {
	return ((IDirect3DTexture9 *(__thiscall *)(CLicensePlate *, const char *))SAMP_ADDROF(0x6D110))(this, szText);
}

#endif