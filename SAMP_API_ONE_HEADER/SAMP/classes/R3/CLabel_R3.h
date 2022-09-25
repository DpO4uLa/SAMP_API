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

class SAMP_API CLabel {
public:
	IDirect3DDevice9 *m_pDevice;
	ID3DXSprite		  *m_pSprite;

	CLabel(IDirect3DDevice9 *pDevice);
	~CLabel();

	void OnLostDevice();
	void OnResetDevice();
	BOOL HasNoObstacles(CVector position);
	void Begin();
	void End();
	void Draw(CVector *pPosition, const char *szText, D3DCOLOR color, BOOL bShadow, bool bNoObstacles);
};

extern CLabel *&pLabel;

SAMP_END

#endif