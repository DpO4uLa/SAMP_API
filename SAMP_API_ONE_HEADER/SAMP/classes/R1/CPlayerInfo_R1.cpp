/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "CPlayerInfo_R1.h"

SAMP::classes::CPlayerInfo::CPlayerInfo(const char *szName, BOOL bIsNPC) {
	((void(__thiscall *)(CPlayerInfo *, const char *, BOOL))SAMP_ADDROF(0x10CB0))(this, szName, bIsNPC);
}

SAMP::classes::CPlayerInfo::~CPlayerInfo() {
	((void(__thiscall *)(CPlayerInfo *))SAMP_ADDROF(0x10A50))(this);
}

#endif