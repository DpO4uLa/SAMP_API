/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "DebugScript_R3.h"

SAMP::classes::CObjectPool *&SAMP::classes::DebugScript::pPrivateObjectPool = *(SAMP::classes::CObjectPool **)SAMP_ADDROF(0x14FCFC);
unsigned short &SAMP::classes::DebugScript::nObjectCount = *(unsigned short *)SAMP_ADDROF(0x14FD00);
SAMP::classes::CVector &SAMP::classes::DebugScript::vNewCameraPos = *(SAMP::classes::CVector *)SAMP_ADDROF(0x14FCF0);

void SAMP::classes::DebugScript::Initialize(const char *szFile) {
	((void(__cdecl *)(const char *))SAMP_ADDROF(0x9E2A0))(szFile);
}

void SAMP::classes::DebugScript::ProcessLine(const char *szLine) {
	((void(__cdecl *)(const char *))SAMP_ADDROF(0x9E190))(szLine);
}

char *SAMP::classes::DebugScript::GetCommandParams(char *szLine) {
	return ((char *(__cdecl *)(char *))SAMP_ADDROF(0x9DDA0))(szLine);
}

void SAMP::classes::DebugScript::CreateVehicle(const char *szParams) {
	((void(__cdecl *)(const char *))SAMP_ADDROF(0x9DF00))(szParams);
}

#endif