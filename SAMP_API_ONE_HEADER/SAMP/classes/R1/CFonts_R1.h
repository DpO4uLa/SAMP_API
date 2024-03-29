/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R1_COMPILE

#include "common_R1.h"
#include "CRect_R1.h"

#undef DrawText

SAMP_BEGIN

class CFont;

class SAMP_API CFonts {
public:
	CFont					*m_pFont;
	CFont					*m_pLittleFont;
	CFont					*m_pShadow;
	CFont					*m_pLittleShadow;
	CFont					*m_pLicensePlateFont;
	ID3DXSprite			*m_pDefaultSprite;
	IDirect3DDevice9	*m_pDevice;
	char					*m_szTempBuffer;
	
	CFonts(IDirect3DDevice9 *pDevice);
	~CFonts();

	void OnLostDevice();
	void OnResetDevice();
	void GetTextScreenSize(void *pSize, const char *szText, int nFormat);
	void GetLittleTextScreenSize(void *pSize, const char *szText, int nFormat);
	void DrawText(ID3DXSprite *pSprite, const char *szText, CRect rect, D3DCOLOR color, BOOL bShadow);
	void DrawLittleText(ID3DXSprite *pSprite, const char *szText, CRect rect, int nFormat, D3DCOLOR color, BOOL bShadow);
	void DrawLicensePlateText(const char *szText, CRect rect, D3DCOLOR color);
	void Reset();
};

extern CFonts *&pFontRenderer;

SAMP_END

#endif