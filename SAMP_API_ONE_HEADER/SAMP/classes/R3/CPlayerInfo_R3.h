/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R3_COMPILE

#include "common_R3.h"
#include "CRemotePlayer_R3.h"
#include <string>

SAMP_BEGIN

class SAMP_API CPlayerInfo {
public:
	CRemotePlayer		  *m_pPlayer;
	int						m_nPing;
#ifndef _DEBUG
private:
	int __aling;
public:
#endif
	std::string				m_szNick;
	int						m_nScore;
	BOOL						m_bIsNPC;

	CPlayerInfo(const char *szName, BOOL bIsNPC);
	~CPlayerInfo();
};

SAMP_END

#endif