/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R3_COMPILE

#include "common_R3.h"
#include "CVector_R3.h"

SAMP_BEGIN

class SAMP_API CPlayerTags {
public:
	IDirect3DDevice9		*m_pDevice;
	IDirect3DStateBlock9 *m_pStates;
	ID3DXSprite				*m_pSprite;

	CPlayerTags(IDirect3DDevice9 *pDevice);
	~CPlayerTags();

	void EndHealthBar();
	void BeginLabel();
	void EndLabel();
	void DrawLabel(CVector *pPosition, const char *szText, D3DCOLOR color, float fDistanceToCamera, bool bDrawStatus, int nStatus);
	void DrawHealthBar(CVector *pPosition, float fHealth, float fArmour, float fDistanceToCamera);
	void OnLostDevice();
	void OnResetDevice();
	void BeginHealthBar();
};

extern CPlayerTags *&pPlayerTags;

SAMP_END

#endif