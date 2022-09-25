/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CPlayerPool_R3.h"

SAMP::classes::CPlayerPool::CPlayerPool() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x13BE0))(this);
}

SAMP::classes::CPlayerPool::~CPlayerPool() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x13D40))(this);
}

void SAMP::classes::CPlayerPool::UpdateLargestId() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x13400))(this);
}

void SAMP::classes::CPlayerPool::Process() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x13470))(this);
}

SAMP::classes::ID SAMP::classes::CPlayerPool::Find(SAMP::classes::CPed *pGamePed) {
	return ((ID(__thiscall *)(CPlayerPool *, SAMP::classes::CPed *))SAMP_ADDROF(0x13570))(this, pGamePed);
}

void SAMP::classes::CPlayerPool::Deactivate() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x13790))(this);
}

void SAMP::classes::CPlayerPool::ForceCollision() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x138C0))(this);
}

void SAMP::classes::CPlayerPool::RestoreCollision() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x13930))(this);
}

BOOL SAMP::classes::CPlayerPool::Delete(ID nId, int nReason) {
	return ((BOOL(__thiscall *)(CPlayerPool *, ID, int))SAMP_ADDROF(0x13CB0))(this, nId, nReason);
}

BOOL SAMP::classes::CPlayerPool::Create(ID nId, const char *szName, BOOL bIsNPC) {
	return ((BOOL(__thiscall *)(CPlayerPool *, ID, const char *, BOOL))SAMP_ADDROF(0x13E80))(this, nId, szName, bIsNPC);
}

SAMP::classes::CRemotePlayer *SAMP::classes::CPlayerPool::GetPlayer(ID nId) {
	return ((CRemotePlayer *(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x10F0))(this, nId);
}

const char *SAMP::classes::CPlayerPool::GetLocalPlayerName() {
	return ((const char *(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0xA170))(this);
}

BOOL SAMP::classes::CPlayerPool::IsDisconnected(ID nId) {
	return ((BOOL(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x10D0))(this, nId);
}

BOOL SAMP::classes::CPlayerPool::IsConnected(ID nId) {
	return ((BOOL(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x10B0))(this, nId);
}

void SAMP::classes::CPlayerPool::SetLocalPlayerName(const char *szName) {
	((void(__thiscall *)(CPlayerPool *, const char *))SAMP_ADDROF(0xB5C0))(this, szName);
}

void SAMP::classes::CPlayerPool::SetAt(ID nId, CPlayerInfo *pObject) {
	((void(__thiscall *)(CPlayerPool *, ID, CPlayerInfo *))SAMP_ADDROF(0x133E0))(this, nId, pObject);
}

int SAMP::classes::CPlayerPool::GetScore(ID nId) {
	return ((int(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x6E0E0))(this, nId);
}

int SAMP::classes::CPlayerPool::GetPing(ID nId) {
	return ((int(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x6E110))(this, nId);
}

const char *SAMP::classes::CPlayerPool::GetName(ID nId) {
	return ((const char *(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x16F00))(this, nId);
}

int SAMP::classes::CPlayerPool::GetLocalPlayerPing() {
	return ((int(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x6E150))(this);
}

int SAMP::classes::CPlayerPool::GetLocalPlayerScore() {
	return ((int(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x6E140))(this);
}

int SAMP::classes::CPlayerPool::GetCount(BOOL bIncludeNPC) {
	return ((int(__thiscall *)(CPlayerPool *, BOOL))SAMP_ADDROF(0x13670))(this, bIncludeNPC);
}

SAMP::classes::CLocalPlayer *SAMP::classes::CPlayerPool::GetLocalPlayer() {
	return ((CLocalPlayer *(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x1A30))(this);
}

SAMP::classes::CObject *SAMP::classes::CPlayerPool::FindAccessory(SAMP::classes::CObject *pGameObject) {
	return ((CObject *(__thiscall *)(CPlayerPool *, SAMP::classes::CObject *))SAMP_ADDROF(0x137F0))(this, pGameObject);
}

#endif