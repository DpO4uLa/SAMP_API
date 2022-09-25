/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CObjectPool_R3.h"

SAMP::classes::CObjectPool::CObjectPool() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0x124B0))(this);
}

SAMP::classes::CObjectPool::~CObjectPool() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0x12E10))(this);
}

void SAMP::classes::CObjectPool::UpdateLargestId() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0x12450))(this);
}

int SAMP::classes::CObjectPool::GetCount() {
	return ((int(__thiscall *)(CObjectPool *))SAMP_ADDROF(0x124E0))(this);
}

BOOL SAMP::classes::CObjectPool::Delete(ID nId) {
	return ((BOOL(__thiscall *)(CObjectPool *, ID))SAMP_ADDROF(0x12500))(this, nId);
}

BOOL SAMP::classes::CObjectPool::Create(ID nId, int nModel, CVector position, CVector rotation, float fDrawDistance) {
	return ((BOOL(__thiscall *)(CObjectPool *, ID, int, CVector, CVector, float))SAMP_ADDROF(0x12580))(this, nId, nModel, position, rotation, fDrawDistance);
}

SAMP::classes::CObject *SAMP::classes::CObjectPool::Find(SAMP::classes::CObject *pGameObject) {
	return ((CObject *(__thiscall *)(CObjectPool *, SAMP::classes::CObject *))SAMP_ADDROF(0x12680))(this, pGameObject);
}

int SAMP::classes::CObjectPool::GetId(SAMP::classes::CObject *pGameObject) {
	return ((int(__thiscall *)(CObjectPool *, SAMP::classes::CObject *))SAMP_ADDROF(0x126C0))(this, pGameObject);
}

void SAMP::classes::CObjectPool::Process() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0x12700))(this);
}

void SAMP::classes::CObjectPool::ConstructMaterials() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0x127C0))(this);
}

void SAMP::classes::CObjectPool::ShutdownMaterials() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0x12800))(this);
}

void SAMP::classes::CObjectPool::Draw() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0x12840))(this);
}

void SAMP::classes::CObjectPool::DrawLast() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0x12880))(this);
}

SAMP::classes::CObject *SAMP::classes::CObjectPool::GetObject(ID nId) {
	return ((CObject *(__thiscall *)(CObjectPool *, ID))SAMP_ADDROF(0x2DC0))(this, nId);
}

#endif