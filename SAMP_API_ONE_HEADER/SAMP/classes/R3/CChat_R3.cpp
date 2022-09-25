/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CChat_R3.h"

SAMP::classes::CChat *&SAMP::classes::pChat = *(SAMP::classes::CChat **)SAMP_ADDROF(0x26E8C8);

SAMP::classes::CChat::CChat(IDirect3DDevice9 *pDevice, CFonts *pFontRenderer, const char *szLogPath) {
	((void(__thiscall *)(CChat *, IDirect3DDevice9 *, CFonts *, const char *))SAMP_ADDROF(0x67C00))(this, pDevice, pFontRenderer, szLogPath);
}

void SAMP::classes::CChat::RecalcFontSize() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x669A0))(this);
}

void SAMP::classes::CChat::OnLostDevice() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x66A20))(this);
}

void SAMP::classes::CChat::UpdateScrollbar() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x66A80))(this);
}

void SAMP::classes::CChat::SetPageSize(int nValue) {
	((void(__thiscall *)(CChat *, int))SAMP_ADDROF(0x66B20))(this, nValue);
}

void SAMP::classes::CChat::PageUp() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x66B50))(this);
}

void SAMP::classes::CChat::PageDown() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x66BB0))(this);
}

void SAMP::classes::CChat::ScrollToBottom() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x66C10))(this);
}

void SAMP::classes::CChat::Scroll(int nDelta) {
	((void(__thiscall *)(CChat *, int))SAMP_ADDROF(0x66C40))(this, nDelta);
}

void SAMP::classes::CChat::FilterOutInvalidChars(char *szString) {
	((void(__thiscall *)(CChat *, char *))SAMP_ADDROF(0x66CA0))(this, szString);
}

void SAMP::classes::CChat::PushBack() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x66CD0))(this);
}

void SAMP::classes::CChat::RenderEntry(const char *szText, CRect rect, D3DCOLOR color) {
	((void(__thiscall *)(CChat *, const char *, CRect, D3DCOLOR))SAMP_ADDROF(0x66CF0))(this, szText, rect, color);
}

void SAMP::classes::CChat::Log(int nType, const char *szText, const char *szPrefix) {
	((void(__thiscall *)(CChat *, int, const char *, const char *))SAMP_ADDROF(0x67050))(this, nType, szText, szPrefix);
}

void SAMP::classes::CChat::ResetDialogControls(CDXUTDialog *pGameUi) {
	((void(__thiscall *)(CChat *, CDXUTDialog *))SAMP_ADDROF(0x67120))(this, pGameUi);
}

void SAMP::classes::CChat::Render() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x671C0))(this);
}

void SAMP::classes::CChat::AddEntry(int nType, const char *szText, const char *szPrefix, D3DCOLOR textColor, D3DCOLOR prefixColor) {
	((void(__thiscall *)(CChat *, int, const char *, const char *, D3DCOLOR, D3DCOLOR))SAMP_ADDROF(0x67460))(this, nType, szText, szPrefix, textColor, prefixColor);
}

void SAMP::classes::CChat::Draw() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x67680))(this);
}

void SAMP::classes::CChat::RenderToSurface() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x67750))(this);
}

void SAMP::classes::CChat::AddChatMessage(const char *szPrefix, D3DCOLOR prefixColor, const char *szText) {
	((void(__thiscall *)(CChat *, const char *, D3DCOLOR, const char *))SAMP_ADDROF(0x678A0))(this, szPrefix, prefixColor, szText);
}

void SAMP::classes::CChat::AddMessage(D3DCOLOR color, const char *szText) {
	((void(__thiscall *)(CChat *, D3DCOLOR, const char *))SAMP_ADDROF(0x679F0))(this, color, szText);
}

void SAMP::classes::CChat::OnResetDevice() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x67A50))(this);
}

void SAMP::classes::CChat::SwitchMode() {
	((void(__thiscall *)(CChat *))SAMP_ADDROF(0x60B50))(this);
}

int SAMP::classes::CChat::GetMode() {
	return ((int(__thiscall *)(CChat *))SAMP_ADDROF(0x60B40))(this);
}

#endif