/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "CPlayerPool.h"

SAMP::classes::CPlayerPool::CPlayerPool() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x10AD0))(this);
}

SAMP::classes::CPlayerPool::~CPlayerPool() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x10C20))(this);
}

void SAMP::classes::CPlayerPool::Process() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x10320))(this);
}

void SAMP::classes::CPlayerPool::SetAt(ID nIdx, CPlayerInfo *pPlayer) {
	((void(__thiscall *)(CPlayerPool *, ID, CPlayerInfo *))SAMP_ADDROF(0x10290))(this, nIdx, pPlayer);
}

BOOL SAMP::classes::CPlayerPool::Delete(ID nId, int nReason) {
	return ((int(__thiscall *)(CPlayerPool *, ID, int))SAMP_ADDROF(0x10B90))(this, nId, nReason);
}

void SAMP::classes::CPlayerPool::Deactivate() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x10650))(this);
}

BOOL SAMP::classes::CPlayerPool::Create(ID nId, const char *szName, BOOL bIsNPC) {
	return ((BOOL(__thiscall *)(CPlayerPool *, ID, const char *, BOOL))SAMP_ADDROF(0x10D50))(this, nId, szName, bIsNPC);
}

const char *SAMP::classes::CPlayerPool::GetName(ID nId) {
	return ((const char *(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x13CE0))(this, nId);
}

SAMP::classes::ID SAMP::classes::CPlayerPool::Find(CPed *pPed) {
	return ((ID(__thiscall *)(CPlayerPool *, CPed *))SAMP_ADDROF(0x10420))(this, pPed);
}

int SAMP::classes::CPlayerPool::GetCount(BOOL bIncludeNPC) {
	return ((int(__thiscall *)(CPlayerPool *, BOOL))SAMP_ADDROF(0x10520))(this, bIncludeNPC);
}

void SAMP::classes::CPlayerPool::ForceCollision() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x107B0))(this);
}

void SAMP::classes::CPlayerPool::RestoreCollision() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x10820))(this);
}

const char *SAMP::classes::CPlayerPool::GetLocalPlayerName() {
	return ((const char *(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x13CD0))(this);
}

SAMP::classes::CRemotePlayer *SAMP::classes::CPlayerPool::GetPlayer(ID nId) {
	return ((CRemotePlayer *(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x10F0))(this, nId);
}

SAMP::classes::CPlayerInfo *SAMP::classes::CPlayerPool::GetAt(ID nId) {
	return ((CPlayerInfo *(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x10D0))(this, nId);
}

BOOL SAMP::classes::CPlayerPool::IsConnected(ID nId) {
	return ((BOOL(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x10B0))(this, nId);
}

BOOL SAMP::classes::CPlayerPool::IsNPC(ID nId) {
	return ((BOOL(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0xB680))(this, nId);
}

void SAMP::classes::CPlayerPool::SetPing(ID nId, int nValue) {
	((void(__thiscall *)(CPlayerPool *, ID, int))SAMP_ADDROF(0xB705))(this, nId, nValue);
}

void SAMP::classes::CPlayerPool::SetScore(ID nId, int nValue) {
	((void(__thiscall *)(CPlayerPool *, ID, int))SAMP_ADDROF(0xB6C0))(this, nId, nValue);
}

SAMP::classes::CLocalPlayer *SAMP::classes::CPlayerPool::GetLocalPlayer() {
	return ((CLocalPlayer *(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x1A30))(this);
}

int SAMP::classes::CPlayerPool::GetScore(ID nPlayer) {
	return ((int(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x6A190))(this, nPlayer);
}

int SAMP::classes::CPlayerPool::GetPing(ID nPlayer) {
	return ((int(__thiscall *)(CPlayerPool *, ID))SAMP_ADDROF(0x6A1C0))(this, nPlayer);
}

void SAMP::classes::CPlayerPool::UpdateLargestId() {
	((void(__thiscall *)(CPlayerPool *))SAMP_ADDROF(0x102B0))(this);
}

SAMP::classes::CObject *SAMP::classes::CPlayerPool::FindAccessory(CObject *pGameObject) {
	return ((CObject *(__thiscall *)(CPlayerPool *, CObject *))SAMP_ADDROF(0x106A0))(this, pGameObject);
}

void SAMP::classes::CPlayerPool::SetLocalPlayerName(const char *szName) {
	((void(__thiscall *)(CPlayerPool *, const char *))SAMP_ADDROF(0xB3E0))(this, szName);
}

BOOL SAMP::classes::CPlayerPool::IsDisconnected(ID nId) {
	if (nId < 0 || nId >= SAMP_MAX_PLAYERS)
		return 0;
	return m_pObject[nId] == nullptr;
}