/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "CMenu_R1.h"

SAMP::classes::CMenu::CMenu(const char *szTitle, float fX, float fY, float fFirstColumnWidth, float fSecondColumnWidth, const Interaction *pInteraction) {
	((void(__thiscall *)(CMenu *, const char *, float, float, float, float, const Interaction *))SAMP_ADDROF(0xA23C0))(this, szTitle, fX, fY, fFirstColumnWidth, fSecondColumnWidth, pInteraction);
}

void SAMP::classes::CMenu::Show() {
	((void(__thiscall *)(CMenu *))SAMP_ADDROF(0xA2590))(this);
}

void SAMP::classes::CMenu::Hide() {
	((void(__thiscall *)(CMenu *))SAMP_ADDROF(0xA24C0))(this);
}

void SAMP::classes::CMenu::AddItem(NUMBER nColumn, NUMBER nRow, const char *szText) {
	((void(__thiscall *)(CMenu *, NUMBER, NUMBER, const char *))SAMP_ADDROF(0xA2460))(this, nColumn, nRow, szText);
}

void SAMP::classes::CMenu::SetColumnTitle(NUMBER nColumn, const char *szText) {
	((void(__thiscall *)(CMenu *, NUMBER, const char *))SAMP_ADDROF(0xA2490))(this, nColumn, szText);
}

char *SAMP::classes::CMenu::GetItem(NUMBER nColumn, NUMBER nRow) {
	return ((char *(__thiscall *)(CMenu *, NUMBER, NUMBER))SAMP_ADDROF(0xA24E0))(this, nColumn, nRow);
}

char *SAMP::classes::CMenu::GetTitle() {
	return ((char *(__thiscall *)(CMenu *))SAMP_ADDROF(0xA2500))(this);
}

char *SAMP::classes::CMenu::MS(NUMBER nColumn, NUMBER nRow) {
	return ((char *(__thiscall *)(CMenu *, NUMBER, NUMBER))SAMP_ADDROF(0xA2530))(this, nColumn, nRow);
}

char SAMP::classes::CMenu::GetActiveRow() {
	return ((char(__thiscall *)(CMenu *))SAMP_ADDROF(0xA2560))(this);
}

#endif