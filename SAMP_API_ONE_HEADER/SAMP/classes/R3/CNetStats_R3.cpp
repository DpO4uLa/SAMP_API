/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CNetStats_R3.h"

SAMP::classes::CNetStats *&SAMP::classes::pNetStats = *(SAMP::classes::CNetStats **)SAMP_ADDROF(0x26E8B4);

SAMP::classes::CNetStats::CNetStats(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CNetStats *, IDirect3DDevice9 *))SAMP_ADDROF(0x605C0))(this, pDevice);
}

void SAMP::classes::CNetStats::Draw() {
	((void(__thiscall *)(CNetStats *))SAMP_ADDROF(0x605F0))(this);
}

#endif