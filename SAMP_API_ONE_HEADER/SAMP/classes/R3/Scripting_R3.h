/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R3_COMPILE

#include "common_R3.h"

SAMP_BEGIN_NP

class CRunningScript;

namespace Scripting {
	struct SAMP_API OpcodeInfo {
		unsigned short m_wOpCode;
		char m_szParams[16]; // i - int, f - float, v - var, s - string, z - zero terminating
	};

	typedef int(__thiscall *PROCESSOR)(CRunningScript *);

	extern CRunningScript *&pThread;
	extern unsigned char *aBuffer; // [256]
	extern unsigned long &nLastUsedOpcode;
	extern unsigned long *&apThreadLocals; // [18]
	extern BOOL &bLocalDebug;
	extern PROCESSOR &ProcessOneCommand;

	void Initialize();
	int ExecBuffer();
	template<typename... Args> 
	int ProcessCommand(const OpcodeInfo *pOpcodeInfo, Args... args) {
		return ((int(__cdecl *)(const OpcodeInfo *, Args...))SAMP_ADDROF(0xB1A80))(pOpcodeInfo, args...);
	}
}

SAMP_END_NP

#endif