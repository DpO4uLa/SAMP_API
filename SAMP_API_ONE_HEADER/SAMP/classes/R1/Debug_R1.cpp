/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "Debug_R1.h"

int &SAMP::classes::Debug::nMode = *(int *)SAMP_ADDROF(0x13BB18);
void *&SAMP::classes::Debug::pFirstEntity = *(void **)SAMP_ADDROF(0x13BB1C);
void *&SAMP::classes::Debug::pSecondEntity = *(void **)SAMP_ADDROF(0x13BB20);

void SAMP::classes::Debug::SetProperties(void *pFirstEntity, void *pSecondEntity, int nMode) {
	((void(__cdecl *)(void *, void *, int))SAMP_ADDROF(0x996E0))(pFirstEntity, pSecondEntity, nMode);
}

void SAMP::classes::Debug::Disable() {
	((void(__cdecl *)())SAMP_ADDROF(0x99700))();
}

#endif