/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "Exception_R3.h"

int &SAMP::classes::Exception::nCount = *(int *)SAMP_ADDROF(0x125930);
void *&SAMP::classes::Exception::pContextRecord = *(void **)SAMP_ADDROF(0x121928);
char *SAMP::classes::Exception::szCrashDialogText = (char *)SAMP_ADDROF(0x121930);

BOOL SAMP::classes::Exception::Print(int nCode, void *pExceptionPointers, const char *szWarning) {
	return ((BOOL(__stdcall *)(int, void *, const char *))SAMP_ADDROF(0x60270))(nCode, pExceptionPointers, szWarning);
}

void SAMP::classes::Exception::SendCrashReport() {
	((void(__cdecl *)())SAMP_ADDROF(0x60060))();
}

BOOL SAMP::classes::Exception::CrashDialogProc(void *hWnd, unsigned int uMsg, unsigned int wParam, long lParam) {
	return ((BOOL(__stdcall *)(void *, unsigned int, unsigned int, long))SAMP_ADDROF(0x60130))(hWnd, uMsg, wParam, lParam);
}

void SAMP::classes::Exception::ConstructCrashDialogText(BOOL bModules) {
	((void(__cdecl *)(BOOL))SAMP_ADDROF(0x5FE70))(bModules);
}

long SAMP::classes::Exception::Handler(void *pExceptionPointers) {
	return ((long(__stdcall *)(void *))SAMP_ADDROF(0x60230))(pExceptionPointers);
}

#endif