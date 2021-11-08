/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "CInput.h"

SAMP::classes::CInput *&SAMP::classes::pInputBox = *(SAMP::classes::CInput **)SAMP_ADDROF(0x21A0E8);

SAMP::classes::CInput::CInput(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CInput *, IDirect3DDevice9 *))SAMP_ADDROF(0x65730))(this, pDevice);
}

void SAMP::classes::CInput::GetRect(CRect *pRect) {
	((void(__thiscall *)(CInput *, CRect *))SAMP_ADDROF(0x657A0))(this, pRect);
}

void SAMP::classes::CInput::Open() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x657E0))(this);
}

void SAMP::classes::CInput::Close() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x658E0))(this);
}

void SAMP::classes::CInput::AddRecall(const char *pText) {
	((void(__thiscall *)(CInput *, const char *))SAMP_ADDROF(0x65930))(this, pText);
}

void SAMP::classes::CInput::RecallUp() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x65990))(this);
}

void SAMP::classes::CInput::RecallDown() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x65A00))(this);
}

void SAMP::classes::CInput::EnableCursor() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x65A50))(this);
}

SAMP::classes::CMDPROC SAMP::classes::CInput::GetCommandHandler(const char *pName) {
	return ((CMDPROC(__thiscall *)(CInput *, const char *))SAMP_ADDROF(0x65A70))(this, pName);
}

void SAMP::classes::CInput::SetDefaultCommand(CMDPROC pProc) {
	((void(__thiscall *)(CInput *, CMDPROC))SAMP_ADDROF(0x65AC0))(this, pProc);
}

void SAMP::classes::CInput::AddCommand(const char *pName, CMDPROC pProc) {
	((void(__thiscall *)(CInput *, const char *, CMDPROC))SAMP_ADDROF(0x65AD0))(this, pName, pProc);
}

int SAMP::classes::CInput::MsgProc(int uMsg, int wParam, int lParam) {
	return ((int(__thiscall *)(CInput *, int, int, int))SAMP_ADDROF(0x65B30))(this, uMsg, wParam, lParam);
}

void SAMP::classes::CInput::ResetDialogControls(CDXUTDialog *pGameUI) {
	((void(__thiscall *)(CInput *, CDXUTDialog *))SAMP_ADDROF(0x65BA0))(this, pGameUI);
}

void SAMP::classes::CInput::Send(const char *szString) {
	((void(__thiscall *)(CInput *, const char *))SAMP_ADDROF(0x65C60))(this, szString);
}

void SAMP::classes::CInput::ProcessInput() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x65D30))(this);
}