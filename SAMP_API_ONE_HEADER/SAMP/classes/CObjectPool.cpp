/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "CObjectPool.h"

TICK &SAMP::classes::CObjectPool::lastProcess = *(TICK *)SAMP_ADDROF(0x1049B0);

SAMP::classes::CObjectPool::CObjectPool() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0xF3A0))(this);
}

SAMP::classes::CObjectPool::~CObjectPool() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0xFCB0))(this);
}

void SAMP::classes::CObjectPool::UpdateLargestId() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0xF340))(this);
}

int SAMP::classes::CObjectPool::GetCount() {
	return ((int(__thiscall *)(CObjectPool *))SAMP_ADDROF(0xF3D0))(this);
}

BOOL SAMP::classes::CObjectPool::Delete(ID nId) {
	return ((BOOL(__thiscall *)(CObjectPool *, ID))SAMP_ADDROF(0xF3F0))(this, nId);
}

BOOL SAMP::classes::CObjectPool::Create(ID nId, int nModel, CVector position, CVector rotation, float fDrawDistance) {
	return ((BOOL(__thiscall *)(CObjectPool *, ID, int, CVector, CVector, float))SAMP_ADDROF(0xF470))(this, nId, nModel, position, rotation, fDrawDistance);
}

SAMP::classes::CObject *SAMP::classes::CObjectPool::Find(::CObject *pGameObject) {
	return ((CObject *(__thiscall *)(CObjectPool *, ::CObject *))SAMP_ADDROF(0xF520))(this, pGameObject);
}

int SAMP::classes::CObjectPool::GetId(::CObject *pObject) {
	return ((int(__thiscall *)(CObjectPool *, ::CObject *))SAMP_ADDROF(0xF560))(this, pObject);
}

void SAMP::classes::CObjectPool::Process() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0xF5A0))(this);
}

void SAMP::classes::CObjectPool::ConstructMaterials() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0xF660))(this);
}

void SAMP::classes::CObjectPool::ShutdownMaterials() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0xF6A0))(this);
}

void SAMP::classes::CObjectPool::Draw() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0xF6E0))(this);
}

void SAMP::classes::CObjectPool::DrawLast() {
	((void(__thiscall *)(CObjectPool *))SAMP_ADDROF(0xF720))(this);
}