/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "InputHandler_R1.h"

void *&SAMP::classes::InputHandler::prevWindowProc = *(void **)SAMP_ADDROF(0x119CB8);

int SAMP::classes::InputHandler::WindowProc(unsigned int uMsg, unsigned int wParam, long lParam) {
	return ((int(__stdcall *)(unsigned int, unsigned int, long))SAMP_ADDROF(0x5DB40))(uMsg, wParam, lParam);
}

BOOL SAMP::classes::InputHandler::KeyPressHandler(unsigned int nKey) {
	return ((BOOL(__cdecl *)(unsigned int))SAMP_ADDROF(0x5D850))(nKey);
}

BOOL SAMP::classes::InputHandler::CharInputHandler(unsigned int nChar) {
	return ((BOOL(__cdecl *)(unsigned int))SAMP_ADDROF(0x5DA80))(nChar);
}

BOOL SAMP::classes::InputHandler::Initialize() {
	return ((BOOL(__cdecl *)())SAMP_ADDROF(0x5E3B0))();
}

void SAMP::classes::SwitchWindowedMode() {
	((void(__cdecl *)())SAMP_ADDROF(0x5D800))();
}

#endif