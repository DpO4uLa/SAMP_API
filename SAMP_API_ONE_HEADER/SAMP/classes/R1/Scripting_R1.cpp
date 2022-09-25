/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "Scripting_R1.h"

SAMP::classes::CRunningScript *&SAMP::classes::Scripting::pThread = *(SAMP::classes::CRunningScript **)SAMP_ADDROF(0x216048);
unsigned char *SAMP::classes::Scripting::aBuffer = (unsigned char *)SAMP_ADDROF(0x215F48);
unsigned long &SAMP::classes::Scripting::nLastUsedOpcode = *(unsigned long *)SAMP_ADDROF(0x21604C);
unsigned long *&SAMP::classes::Scripting::apThreadLocals = *(unsigned long **)SAMP_ADDROF(0x215F00);
SAMP::classes::Scripting::PROCESSOR &SAMP::classes::Scripting::ProcessOneCommand = *(SAMP::classes::Scripting::PROCESSOR *)SAMP_ADDROF(0x1023C4);

void SAMP::classes::Scripting::Initialize() {
	((void(__cdecl *)())SAMP_ADDROF(0xABF10))();
}

int SAMP::classes::Scripting::ExecBuffer() {
	return ((int(__cdecl *)())SAMP_ADDROF(0xABC90))();
}

#endif