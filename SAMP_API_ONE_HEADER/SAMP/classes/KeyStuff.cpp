/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "KeyStuff.h"

SAMP::classes::CPad *&SAMP::classes::KeyStuff::pInternalKeys = *(SAMP::classes::CPad **)SAMP_ADDROF(0x1016E8);
SAMP::classes::CPad *SAMP::classes::KeyStuff::pLocalPlayerKeys = (SAMP::classes::CPad *)SAMP_ADDROF(0x13D2C0);
SAMP::classes::CPad *SAMP::classes::KeyStuff::aPlayerKeys = (SAMP::classes::CPad *)SAMP_ADDROF(0x13D3F8);
bool *&SAMP::classes::KeyStuff::pDriveByLeft = *(bool **)SAMP_ADDROF(0x1016EC);
bool *&SAMP::classes::KeyStuff::pDriveByRight = *(bool **)SAMP_ADDROF(0x1016F0);
bool &SAMP::classes::KeyStuff::bSavedDriveByLeft = *(bool *)SAMP_ADDROF(0x14D0A0);
bool &SAMP::classes::KeyStuff::bSavedDriveByRight = *(bool *)SAMP_ADDROF(0x14D0A1);

void SAMP::classes::KeyStuff::Initialize() {
	((void(__cdecl *)())SAMP_ADDROF(0xA2240))();
}

void SAMP::classes::KeyStuff::ApplyKeys() {
	((void(__cdecl *)())SAMP_ADDROF(0xA2260))();
}

void SAMP::classes::KeyStuff::UpdateKeys() {
	((void(__cdecl *)())SAMP_ADDROF(0xA22A0))();
}

void SAMP::classes::KeyStuff::SetKeys(int nPlayerNumber, const CPad *pPad) {
	((void(__cdecl *)(int, const CPad *))SAMP_ADDROF(0xA22E0))(nPlayerNumber, pPad);
}

void SAMP::classes::KeyStuff::ApplyKeys(int nPlayerNumber) {
	((void(__cdecl *)(int))SAMP_ADDROF(0xA2300))(nPlayerNumber);
}

SAMP::classes::CPad *SAMP::classes::KeyStuff::GetInternalKeys() {
	return ((CPad *(__cdecl *)())SAMP_ADDROF(0xA2350))();
}

SAMP::classes::CPad *SAMP::classes::KeyStuff::GetKeys(int nPlayerNumber) {
	return ((CPad *(__cdecl *)(int))SAMP_ADDROF(0xA2370))(nPlayerNumber);
}

void SAMP::classes::KeyStuff::ResetKeys(int nPlayerNumber) {
	((void(__cdecl *)(int))SAMP_ADDROF(0xA2380))(nPlayerNumber);
}

void SAMP::classes::KeyStuff::ResetInternalKeys() {
	((void(__cdecl *)())SAMP_ADDROF(0xA23A0))();
}

SAMP::classes::CPad *SAMP::classes::KeyStuff::GetKeys() {
	return ((CPad *(__cdecl *)())SAMP_ADDROF(0xA2360))();
}
