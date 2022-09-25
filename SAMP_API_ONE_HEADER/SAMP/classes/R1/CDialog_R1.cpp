/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "CDialog_R1.h"

SAMP::classes::CDialog *&SAMP::classes::pDialog = *(SAMP::classes::CDialog **)SAMP_ADDROF(0x21A0B8);

SAMP::classes::CDialog::CDialog(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CDialog *, IDirect3DDevice9 *))SAMP_ADDROF(0x6AE30))(this, pDevice);
}

void SAMP::classes::CDialog::Hide() {
	((void(__thiscall *)(CDialog *))SAMP_ADDROF(0x6B210))(this);
}

void SAMP::classes::CDialog::Close(char nProcessButton) {
	((void(__thiscall *)(CDialog *, char))SAMP_ADDROF(0x6C040))(this, nProcessButton);
}

void SAMP::classes::CDialog::Draw() {
	((void(__thiscall *)(CDialog *))SAMP_ADDROF(0x6B240))(this);
}

void SAMP::classes::CDialog::Show(int nId, int nType, const char *szCaption, const char *szText, const char *szLeftButton, const char *szRightButton, BOOL bServerside) {
	((void(__thiscall *)(CDialog *, int, int, const char *, const char *, const char *, const char *, BOOL))SAMP_ADDROF(0x6B9C0))(this, nId, nType, szCaption, szText, szLeftButton, szRightButton, bServerside);
}

void SAMP::classes::CDialog::GetScreenRect(CRect *pRect) {
	((void(__thiscall *)(CDialog *, CRect *))SAMP_ADDROF(0x6B060))(this, pRect);
}

void SAMP::classes::CDialog::UpdateRects() {
	((void(__thiscall *)(CDialog *))SAMP_ADDROF(0x6AEB0))(this);
}

int SAMP::classes::CDialog::GetTextScreenLength(const char *pText) {
	return ((int(__thiscall *)(CDialog *, const char *))SAMP_ADDROF(0x6B0D0))(this, pText);
}

void SAMP::classes::CDialog::ResetDialogControls(CDXUTDialog *pDialog) {
	return ((void(__thiscall *)(CDialog *, CDXUTDialog *))SAMP_ADDROF(0x6B3D0))(this, pDialog);
}

#endif