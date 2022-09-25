/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CSrvNetStats_R3.h"

SAMP::classes::CSrvNetStats *&SAMP::classes::pServerNetStatistics = *(SAMP::classes::CSrvNetStats **)SAMP_ADDROF(0x26E8B8);

SAMP::classes::CSrvNetStats::CSrvNetStats(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CSrvNetStats *, IDirect3DDevice9 *))SAMP_ADDROF(0x70B30))(this, pDevice);
}

void SAMP::classes::CSrvNetStats::Draw() {
	((void(__thiscall *)(CSrvNetStats *))SAMP_ADDROF(0x70B70))(this);
}

#endif