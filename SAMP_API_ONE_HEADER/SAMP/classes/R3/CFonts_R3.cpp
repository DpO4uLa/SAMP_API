/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CFonts_R3.h"

SAMP::classes::CFonts *&SAMP::classes::pFontRenderer = *(SAMP::classes::CFonts **)SAMP_ADDROF(0x26E8E4);

SAMP::classes::CFonts::CFonts(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CFonts *, IDirect3DDevice9 *))SAMP_ADDROF(0x6B380))(this, pDevice);
}

SAMP::classes::CFonts::~CFonts() {
	((void(__thiscall *)(CFonts *))SAMP_ADDROF(0x6A990))(this);
}

void SAMP::classes::CFonts::OnLostDevice() {
	((void(__thiscall *)(CFonts *))SAMP_ADDROF(0x6AA10))(this);
}

void SAMP::classes::CFonts::OnResetDevice() {
	((void(__thiscall *)(CFonts *))SAMP_ADDROF(0x6AA50))(this);
}

void SAMP::classes::CFonts::GetTextScreenSize(void *pSize, const char *szText, int nFormat) {
	((void(__thiscall *)(CFonts *, void *, const char *, int))SAMP_ADDROF(0x6AA90))(this, pSize, szText, nFormat);
}

void SAMP::classes::CFonts::GetLittleTextScreenSize(void *pSize, const char *szText, int nFormat) {
	((void(__thiscall *)(CFonts *, void *, const char *, int))SAMP_ADDROF(0x6AB40))(this, pSize, szText, nFormat);
}

void SAMP::classes::CFonts::DrawText(ID3DXSprite *pSprite, const char *szText, CRect rect, D3DCOLOR color, BOOL bShadow) {
	((void(__thiscall *)(CFonts *, ID3DXSprite *, const char *, CRect, D3DCOLOR, BOOL))SAMP_ADDROF(0x6ABF0))(this, pSprite, szText, rect, color, bShadow);
}

void SAMP::classes::CFonts::DrawLittleText(ID3DXSprite *pSprite, const char *szText, CRect rect, int nFormat, D3DCOLOR color, BOOL bShadow) {
	((void(__thiscall *)(CFonts *, ID3DXSprite *, const char *, CRect, int, D3DCOLOR, BOOL))SAMP_ADDROF(0x6AD70))(this, pSprite, szText, rect, nFormat, color, bShadow);
}

void SAMP::classes::CFonts::DrawLicensePlateText(const char *szText, CRect rect, D3DCOLOR color) {
	((void(__thiscall *)(CFonts *, const char *, CRect, D3DCOLOR))SAMP_ADDROF(0x6AEE0))(this, szText, rect, color);
}

void SAMP::classes::CFonts::Reset() {
	((void(__thiscall *)(CFonts *))SAMP_ADDROF(0x6B170))(this);
}

#endif