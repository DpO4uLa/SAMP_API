/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "Scripting_R3.h"

SAMP::classes::CRunningScript *&SAMP::classes::Scripting::pThread = *(SAMP::classes::CRunningScript **)SAMP_ADDROF(0x26B2A8);
unsigned char *SAMP::classes::Scripting::aBuffer = (unsigned char *)SAMP_ADDROF(0x26B1A8);
unsigned long &SAMP::classes::Scripting::nLastUsedOpcode = *(unsigned long *)SAMP_ADDROF(0x26B2AC);
unsigned long *&SAMP::classes::Scripting::apThreadLocals = *(unsigned long **)SAMP_ADDROF(0x26B160);
SAMP::classes::Scripting::PROCESSOR &SAMP::classes::Scripting::ProcessOneCommand = *(SAMP::classes::Scripting::PROCESSOR *)SAMP_ADDROF(0x1173A0);
BOOL &SAMP::classes::Scripting::bLocalDebug = *(BOOL *)SAMP_ADDROF(0x26B2B0);

void SAMP::classes::Scripting::Initialize() {
	((void(__cdecl *)())SAMP_ADDROF(0xB1CC0))();
}

int SAMP::classes::Scripting::ExecBuffer() {
	return ((int(__cdecl *)())SAMP_ADDROF(0xB1A40))();
}

#endif