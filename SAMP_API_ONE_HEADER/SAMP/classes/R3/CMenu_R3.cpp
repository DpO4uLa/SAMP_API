/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CMenu_R3.h"

SAMP::classes::CMenu::CMenu(const char *szTitle, float fX, float fY, char nColumns, float fFirstColumnWidth, float fSecondColumnWidth, const Interaction *pInteraction) {
	((void(__thiscall *)(CMenu *, const char *, float, float, char, float, float, const Interaction *))SAMP_ADDROF(0xA6CE0))(this, szTitle, fX, fY, nColumns, fFirstColumnWidth, fSecondColumnWidth, pInteraction);
}

void SAMP::classes::CMenu::AddItem(NUMBER nColumn, NUMBER nRow, const char *szText) {
	((void(__thiscall *)(CMenu *, NUMBER, NUMBER, const char *))SAMP_ADDROF(0xA6D80))(this, nColumn, nRow, szText);
}

void SAMP::classes::CMenu::SetColumnTitle(NUMBER nColumn, const char *szText) {
	((void(__thiscall *)(CMenu *, NUMBER, const char *))SAMP_ADDROF(0xA6DB0))(this, nColumn, szText);
}

void SAMP::classes::CMenu::Hide() {
	((void(__thiscall *)(CMenu *))SAMP_ADDROF(0xA6DE0))(this);
}

char *SAMP::classes::CMenu::GetItem(NUMBER nColumn, NUMBER nRow) {
	return ((char *(__thiscall *)(CMenu *, NUMBER, NUMBER))SAMP_ADDROF(0xA6E00))(this, nColumn, nRow);
}

char *SAMP::classes::CMenu::GetTitle() {
	return ((char *(__thiscall *)(CMenu *))SAMP_ADDROF(0xA6E20))(this);
}

char *SAMP::classes::CMenu::MS(NUMBER nColumn, NUMBER nRow) {
	return ((char *(__thiscall *)(CMenu *, NUMBER, NUMBER))SAMP_ADDROF(0xA6E50))(this, nColumn, nRow);
}

char SAMP::classes::CMenu::GetActiveRow() {
	return ((char(__thiscall *)(CMenu *))SAMP_ADDROF(0xA6E80))(this);
}

void SAMP::classes::CMenu::Show() {
	((void(__thiscall *)(CMenu *))SAMP_ADDROF(0xA6EB0))(this);
}

#endif