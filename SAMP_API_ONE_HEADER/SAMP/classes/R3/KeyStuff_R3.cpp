/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "KeyStuff_R3.h"

SAMP::classes::CPad *SAMP::classes::KeyStuff::pLocalPlayerKeys = (SAMP::classes::CPad *)SAMP_ADDROF(0x152518);
SAMP::classes::CPad *SAMP::classes::KeyStuff::aPlayerKeys = (SAMP::classes::CPad *)SAMP_ADDROF(0x152650);
SAMP::classes::CPad *&SAMP::classes::KeyStuff::pInternalKeys = *(SAMP::classes::CPad **)SAMP_ADDROF(0x114AD0);
bool *&SAMP::classes::KeyStuff::pDriveByLeft = *(bool **)SAMP_ADDROF(0x114AD4);
bool *&SAMP::classes::KeyStuff::pDriveByRight = *(bool **)SAMP_ADDROF(0x114AD8);
bool &SAMP::classes::KeyStuff::bSavedDriveByLeft = *(bool *)SAMP_ADDROF(0x1622F8);
bool &SAMP::classes::KeyStuff::bSavedDriveByRight = *(bool *)SAMP_ADDROF(0x1622F9);

void SAMP::classes::KeyStuff::Initialize() {
	((void(__cdecl *)())SAMP_ADDROF(0xA6B60))();
}

void SAMP::classes::KeyStuff::UpdateKeys() {
	((void(__cdecl *)())SAMP_ADDROF(0xA6B80))();
}

void SAMP::classes::KeyStuff::ApplyKeys() {
	((void(__cdecl *)())SAMP_ADDROF(0xA6BC0))();
}

void SAMP::classes::KeyStuff::SetKeys(int nPlayer, const CPad *pKeys) {
	((void(__cdecl *)(int, const CPad *))SAMP_ADDROF(0xA6C00))(nPlayer, pKeys);
}

void SAMP::classes::KeyStuff::ApplyKeys(int nPlayer) {
	((void(__cdecl *)(int))SAMP_ADDROF(0xA6C20))(nPlayer);
}

SAMP::classes::CPad *SAMP::classes::KeyStuff::GetInternalKeys() {
	return ((SAMP::classes::CPad *(__cdecl *)())SAMP_ADDROF(0xA6C70))();
}

SAMP::classes::CPad *SAMP::classes::KeyStuff::GetKeys() {
	return ((SAMP::classes::CPad *(__cdecl *)())SAMP_ADDROF(0xA6C80))();
}

SAMP::classes::CPad *SAMP::classes::KeyStuff::GetKeys(int nPlayer) {
	return ((SAMP::classes::CPad *(__cdecl *)(int))SAMP_ADDROF(0xA6C90))(nPlayer);
}

void SAMP::classes::KeyStuff::ResetKeys(int nPlayer) {
	((void(__cdecl *)(int))SAMP_ADDROF(0xA6CA0))(nPlayer);
}

void SAMP::classes::KeyStuff::ResetInternalKeys() {
	((void(__cdecl *)())SAMP_ADDROF(0xA6CC0))();
}

#endif