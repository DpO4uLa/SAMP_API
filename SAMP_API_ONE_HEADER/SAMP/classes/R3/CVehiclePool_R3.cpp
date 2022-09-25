/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CVehiclePool_R3.h"

SAMP::classes::CVehiclePool::CVehiclePool() {
	((void(__thiscall *)(CVehiclePool *))SAMP_ADDROF(0x1E2C0))(this);
}

SAMP::classes::CVehiclePool::~CVehiclePool() {
	((void(__thiscall *)(CVehiclePool *))SAMP_ADDROF(0x1E910))(this);
}

void SAMP::classes::CVehiclePool::UpdateCount() {
	((void(__thiscall *)(CVehiclePool *))SAMP_ADDROF(0x1E260))(this);
}

BOOL SAMP::classes::CVehiclePool::Delete(ID nId) {
	return ((BOOL(__thiscall *)(CVehiclePool *, ID))SAMP_ADDROF(0x1E330))(this, nId);
}

void SAMP::classes::CVehiclePool::ChangeInterior(ID nId, int nInteriorId) {
	((void(__thiscall *)(CVehiclePool *, ID, int))SAMP_ADDROF(0x1E3B0))(this, nId, nInteriorId);
}

void SAMP::classes::CVehiclePool::SetParams(ID nId, bool bIsObjective, bool bIsLocked) {
	((void(__thiscall *)(CVehiclePool *, ID, bool, bool))SAMP_ADDROF(0x1E3E0))(this, nId, bIsObjective, bIsLocked);
}

SAMP::classes::ID SAMP::classes::CVehiclePool::Find(SAMP::classes::CVehicle *pGameObject) {
	return ((ID(__thiscall *)(CVehiclePool *, SAMP::classes::CVehicle *))SAMP_ADDROF(0x1E440))(this, pGameObject);
}

SAMP::classes::GTAREF SAMP::classes::CVehiclePool::GetRef(int nId) {
	return ((GTAREF(__thiscall *)(CVehiclePool *, int))SAMP_ADDROF(0x1E470))(this, nId);
}

SAMP::classes::GTAREF SAMP::classes::CVehiclePool::GetRef(SAMP::classes::CVehicle *pGameObject) {
	return ((GTAREF(__thiscall *)(CVehiclePool *, SAMP::classes::CVehicle *))SAMP_ADDROF(0x1E490))(this, pGameObject);
}

SAMP::classes::ID SAMP::classes::CVehiclePool::GetNearest() {
	return ((ID(__thiscall *)(CVehiclePool *))SAMP_ADDROF(0x1E4B0))(this);
}

SAMP::classes::ID SAMP::classes::CVehiclePool::GetNearest(CVector point) {
	return ((ID(__thiscall *)(CVehiclePool *, CVector))SAMP_ADDROF(0x1E520))(this, point);
}

void SAMP::classes::CVehiclePool::AddToWaitingList(const Info *pInfo) {
	((void(__thiscall *)(CVehiclePool *, const Info *))SAMP_ADDROF(0x1E5C0))(this, pInfo);
}

void SAMP::classes::CVehiclePool::ConstructLicensePlates() {
	((void(__thiscall *)(CVehiclePool *))SAMP_ADDROF(0x1E620))(this);
}

void SAMP::classes::CVehiclePool::ShutdownLicensePlates() {
	((void(__thiscall *)(CVehiclePool *))SAMP_ADDROF(0x1E690))(this);
}

BOOL SAMP::classes::CVehiclePool::Create(Info *pInfo) {
	return ((BOOL(__thiscall *)(CVehiclePool *, Info *))SAMP_ADDROF(0x1E930))(this, pInfo);
}

void SAMP::classes::CVehiclePool::SendDestroyNotification(ID nId) {
	((void(__thiscall *)(CVehiclePool *, ID))SAMP_ADDROF(0x1EAE0))(this, nId);
}

void SAMP::classes::CVehiclePool::ProcessWaitingList() {
	((void(__thiscall *)(CVehiclePool *))SAMP_ADDROF(0x1EBC0))(this);
}

void SAMP::classes::CVehiclePool::Process() {
	((void(__thiscall *)(CVehiclePool *))SAMP_ADDROF(0x1EC80))(this);
}

SAMP::classes::CVehicle *SAMP::classes::CVehiclePool::GetObject(ID nId) {
	return ((CVehicle *(__thiscall *)(CVehiclePool *, ID))SAMP_ADDROF(0x1110))(this, nId);
}

BOOL SAMP::classes::CVehiclePool::DoesExit(ID nId) {
	return ((BOOL(__thiscall *)(CVehiclePool *, ID))SAMP_ADDROF(0x1140))(this, nId);
}

#endif