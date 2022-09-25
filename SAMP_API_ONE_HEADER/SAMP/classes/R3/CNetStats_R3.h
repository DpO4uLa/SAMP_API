/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R3_COMPILE

#include "common_R3.h"

SAMP_BEGIN

class SAMP_API CNetStats {
public:
	unsigned long		m_dwLastTotalBytesSent;
	unsigned long		m_dwLastTotalBytesRecv;
	unsigned long		m_dwLastUpdateTick;
	unsigned long		m_dwBPSUpload;
	unsigned long		m_dwBPSDownload;
	IDirect3DDevice9 *m_pDevice;

	CNetStats(IDirect3DDevice9 *pDevice);

	void Draw();
};

extern CNetStats *&pNetStats;

SAMP_END

#endif