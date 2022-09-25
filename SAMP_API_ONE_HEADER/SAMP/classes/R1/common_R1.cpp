/*
	This is a SAMP API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "common_R1.h"
#include <Windows.h>

unsigned long SAMP::classes::GetHandle() {
	static auto handle = reinterpret_cast<unsigned long>(GetModuleHandleA("samp.dll"));
	return handle;
}

#endif