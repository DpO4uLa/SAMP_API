/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CHttpClient_R3.h"

SAMP::classes::CHttpClient::CHttpClient() {
	((void(__thiscall *)(CHttpClient *))SAMP_ADDROF(0x22C0))(this);
}

SAMP::classes::CHttpClient::~CHttpClient() {
	((void(__thiscall *)(CHttpClient *))SAMP_ADDROF(0x2320))(this);
}

bool SAMP::classes::CHttpClient::GetHeaderValue(const char *szHeaderName, char *szBuffer, int nBufferLen) {
	return ((bool(__thiscall *)(CHttpClient *, const char *, char *, int))SAMP_ADDROF(0x2390))(this, szHeaderName, szBuffer, nBufferLen);
}

void SAMP::classes::CHttpClient::InitializeRequest(int nType, const char *szUrl, const char *szPostData, const char *szReferer) {
	((void(__thiscall *)(CHttpClient *, int, const char *, const char *, const char *))SAMP_ADDROF(0x2490))(this, nType, szUrl, szPostData, szReferer);
}

void SAMP::classes::CHttpClient::HandleEntity() {
	((void(__thiscall *)(CHttpClient *))SAMP_ADDROF(0x2660))(this);
}

bool SAMP::classes::CHttpClient::Connect(const char *szHost, int nPort) {
	return ((bool(__thiscall *)(CHttpClient *, const char *, int))SAMP_ADDROF(0x2980))(this, szHost, nPort);
}

void SAMP::classes::CHttpClient::Process() {
	((void(__thiscall *)(CHttpClient *))SAMP_ADDROF(0x2A40))(this);
}

void SAMP::classes::CHttpClient::Disconnect() {
	((void(__thiscall *)(CHttpClient *))SAMP_ADDROF(0x2420))(this);
}

SAMP::classes::CHttpClient::Error SAMP::classes::CHttpClient::ProcessUrl(int nType, const char *szUrl, const char *szPostData, const char *szReferer) {
	return ((Error(__thiscall *)(CHttpClient *, int, const char *, const char *, const char *))SAMP_ADDROF(0))(this, nType, szUrl, szPostData, szReferer);
}

bool SAMP::classes::CHttpClient::Send(const char *szBuffer) {
	return ((bool(__thiscall *)(CHttpClient *, const char *))SAMP_ADDROF(0x2430))(this, szBuffer);
}

int SAMP::classes::CHttpClient::Receive(char *szBuffer, int nBufferLen) {
	return ((int(__thiscall *)(CHttpClient *, char *, int))SAMP_ADDROF(0x2470))(this, szBuffer, nBufferLen);
}

#endif