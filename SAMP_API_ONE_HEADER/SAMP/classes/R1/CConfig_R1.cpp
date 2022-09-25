/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "CConfig_R1.h"

SAMP::classes::CConfig *&SAMP::classes::pConfig = *(SAMP::classes::CConfig **)SAMP_ADDROF(0x21A0E0);

SAMP::classes::CConfig::CConfig(const char *szFile) {
	((void(__thiscall *)(CConfig *, const char *))SAMP_ADDROF(0x62820))(this, szFile);
}

SAMP::classes::CConfig::~CConfig() {
	((void(__thiscall *)(CConfig *))SAMP_ADDROF(0x62056))(this);
}

void SAMP::classes::CConfig::FindFirstFree() {
	((void(__thiscall *)(CConfig *))SAMP_ADDROF(0x62080))(this);
}

int SAMP::classes::CConfig::GetIndex(const char *szEntry) {
	return ((int(__thiscall *)(CConfig *, const char *))SAMP_ADDROF(0x620D0))(this, szEntry);
}

bool SAMP::classes::CConfig::DoesExist(const char *szEntry) {
	return ((BOOL(__thiscall *)(CConfig *, const char *))SAMP_ADDROF(0x62170))(this, szEntry);
}

int SAMP::classes::CConfig::CreateEntry(const char *szName) {
	return ((int(__thiscall *)(CConfig *, const char *))SAMP_ADDROF(0x62190))(this, szName);
}

int SAMP::classes::CConfig::GetIntValue(const char *szEntry) {
	return ((int(__thiscall *)(CConfig *, const char *))SAMP_ADDROF(0x62250))(this, szEntry);
}

const char *SAMP::classes::CConfig::GetStringValue(const char *szEntry) {
	return ((const char *(__thiscall *)(CConfig *, const char *))SAMP_ADDROF(0x62280))(this, szEntry);
}

float SAMP::classes::CConfig::GetFloatValue(const char *szEntry) {
	return ((float(__thiscall *)(CConfig *, const char *))SAMP_ADDROF(0x622B0))(this, szEntry);
}

BOOL SAMP::classes::CConfig::Free(const char *szEntry) {
	return ((BOOL(__thiscall *)(CConfig *, const char *))SAMP_ADDROF(0x622E0))(this, szEntry);
}

int SAMP::classes::CConfig::GetValueType(const char *szEntry) {
	return ((int(__thiscall *)(CConfig *, const char *))SAMP_ADDROF(0x62340))(this, szEntry);
}

SAMP::classes::CConfig::Entry *SAMP::classes::CConfig::GetEntry(int nIndex) {
	return ((Entry *(__thiscall *)(CConfig *, int))SAMP_ADDROF(0x62370))(this, nIndex);
}

BOOL SAMP::classes::CConfig::Save() {
	return ((BOOL(__thiscall *)(CConfig *))SAMP_ADDROF(0x62410))(this);
}

BOOL SAMP::classes::CConfig::WriteIntValue(const char *szEntry, int nValue, BOOL bReadOnly) {
	return ((BOOL(__thiscall *)(CConfig *, const char *, int, BOOL))SAMP_ADDROF(0x624C0))(this, szEntry, nValue, bReadOnly);
}

BOOL SAMP::classes::CConfig::WriteStringValue(const char *szEntry, const char *szValue, BOOL bReadOnly) {
	return ((BOOL(__thiscall *)(CConfig *, const char *, const char *, BOOL))SAMP_ADDROF(0x62520))(this, szEntry, szValue, bReadOnly);
}

BOOL SAMP::classes::CConfig::WriteFloatValue(const char *szEntry, float fValue, BOOL bReadOnly) {
	return ((BOOL(__thiscall *)(CConfig *, const char *, float, BOOL))SAMP_ADDROF(0x625C0))(this, szEntry, fValue, bReadOnly);
}

void SAMP::classes::CConfig::Write(const char *szEntry, char *szBuffer) {
	((void(__thiscall *)(CConfig *, const char *, const char *))SAMP_ADDROF(0x62620))(this, szEntry, szBuffer);
}

BOOL SAMP::classes::CConfig::Load() {
	return ((BOOL(__thiscall *)(CConfig *))SAMP_ADDROF(0x626B0))(this);
}

int SAMP::classes::CConfig::GetType(const char *szString) {
	return ((int(__thiscall *)(CConfig *, const char *))SAMP_ADDROF(0x623A0))(this, szString);
}

#endif