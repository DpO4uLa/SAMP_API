/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CInput_R3.h"

SAMP::classes::CInput *&SAMP::classes::pInputBox = *(SAMP::classes::CInput **)SAMP_ADDROF(0x26E8CC);

SAMP::classes::CInput::CInput(IDirect3DDevice9 *pDevice) {
	((void(__thiscall *)(CInput *, IDirect3DDevice9 *))SAMP_ADDROF(0x68C60))(this, pDevice);
}

void SAMP::classes::CInput::GetRect(CRect *pRect) {
	((void(__thiscall *)(CInput *, CRect *))SAMP_ADDROF(0x68CD0))(this, pRect);
}

void SAMP::classes::CInput::Open() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x68D10))(this);
}

void SAMP::classes::CInput::Close() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x68E10))(this);
}

void SAMP::classes::CInput::AddRecall(const char *szString) {
	((void(__thiscall *)(CInput *, const char *))SAMP_ADDROF(0x68E60))(this, szString);
}

void SAMP::classes::CInput::RecallUp() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x68EC0))(this);
}

void SAMP::classes::CInput::RecallDown() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x68F30))(this);
}

void SAMP::classes::CInput::EnableCursor() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x68F80))(this);
}

SAMP::classes::CMDPROC SAMP::classes::CInput::GetCommandHandler(const char *szName) {
	return ((CMDPROC(__thiscall *)(CInput *, const char *))SAMP_ADDROF(0x68FA0))(this, szName);
}

void SAMP::classes::CInput::SetDefaultCommand(CMDPROC proc) {
	((void(__thiscall *)(CInput *, CMDPROC))SAMP_ADDROF(0x68FF0))(this, proc);
}

void SAMP::classes::CInput::AddCommand(const char *szName, CMDPROC handler) {
	((void(__thiscall *)(CInput *, const char *, CMDPROC))SAMP_ADDROF(0x69000))(this, szName, handler);
}

BOOL SAMP::classes::CInput::MsgProc(int uMsg, int wParam, int lParam) {
	return ((BOOL(__thiscall *)(CInput *, int, int, int))SAMP_ADDROF(0x69060))(this, uMsg, wParam, lParam);
}

void SAMP::classes::CInput::ResetDialogControls(CDXUTDialog *pGameUi) {
	((void(__thiscall *)(CInput *, CDXUTDialog *))SAMP_ADDROF(0x690D0))(this, pGameUi);
}

void SAMP::classes::CInput::Send(const char *szString) {
	((void(__thiscall *)(CInput *, const char *))SAMP_ADDROF(0x69190))(this, szString);
}

void SAMP::classes::CInput::ProcessInput() {
	((void(__thiscall *)(CInput *))SAMP_ADDROF(0x69260))(this);
}

#endif