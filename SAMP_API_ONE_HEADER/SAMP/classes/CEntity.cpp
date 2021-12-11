/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "CEntity.h"

void SAMP::classes::CEntity::GetMatrix(CMatrix *pMatrix) {
	((void(__thiscall *)(CEntity *, CMatrix *))SAMP_ADDROF(0x9A150))(this, pMatrix);
}

void SAMP::classes::CEntity::SetMatrix(CMatrix matrix) {
	((void(__thiscall *)(CEntity *, CMatrix))SAMP_ADDROF(0x9A200))(this, matrix);
}

void SAMP::classes::CEntity::UpdateRwFrame() {
	((void(__thiscall *)(CEntity *))SAMP_ADDROF(0x9A2C0))(this);
}

void SAMP::classes::CEntity::GetSpeed(CVector *pVec) {
	((void(__thiscall *)(CEntity *, CVector *))SAMP_ADDROF(0x9A320))(this, pVec);
}

void SAMP::classes::CEntity::SetSpeed(CVector vec) {
	((void(__thiscall *)(CEntity *, CVector))SAMP_ADDROF(0x9A350))(this, vec);
}

void SAMP::classes::CEntity::GetTurnSpeed(CVector *pSpeed) {
	((void(__thiscall *)(CEntity *, CVector *))SAMP_ADDROF(0x9A470))(this, pSpeed);
}

void SAMP::classes::CEntity::SetTurnSpeed(CVector speed) {
	((void(__thiscall *)(CEntity *, CVector))SAMP_ADDROF(0x9A4A0))(this, speed);
}

void SAMP::classes::CEntity::ApplyTurnSpeed() {
	((void(__thiscall *)(CEntity *))SAMP_ADDROF(0x9A4D0))(this);
}

float SAMP::classes::CEntity::GetDistanceFromCentreOfMassToBaseOfModel() {
	return ((float(__thiscall *)(CEntity *))SAMP_ADDROF(0x9A4F0))(this);
}

void SAMP::classes::CEntity::GetBoundCentre(CVector *pCentre) {
	((void(__thiscall *)(CEntity *, CVector *))SAMP_ADDROF(0x9A530))(this, pCentre);
}

void SAMP::classes::CEntity::SetModelIndex(int nModel) {
	((void(__thiscall *)(CEntity *, int))SAMP_ADDROF(0x9A590))(this, nModel);
}

int SAMP::classes::CEntity::GetModelIndex() {
	return ((int(__thiscall *)(CEntity *))SAMP_ADDROF(0x9A670))(this);
}

void SAMP::classes::CEntity::Teleport(CVector position) {
	((void(__thiscall *)(CEntity *, CVector))SAMP_ADDROF(0x9A680))(this, position);
}

float SAMP::classes::CEntity::GetDistanceToLocalPlayer() {
	return ((float(__thiscall *)(CEntity *))SAMP_ADDROF(0x9A700))(this);
}

float SAMP::classes::CEntity::GetDistanceToCamera() {
	return ((float(__thiscall *)(CEntity *))SAMP_ADDROF(0x9A7D0))(this);
}

float SAMP::classes::CEntity::GetDistanceToLocalPlayerNoHeight() {
	return ((float(__thiscall *)(CEntity *))SAMP_ADDROF(0x9A830))(this);
}

float SAMP::classes::CEntity::GetDistanceToPoint(CVector position) {
	return ((float(__thiscall *)(CEntity *, CVector))SAMP_ADDROF(0x9A8F0))(this, position);
}

BOOL SAMP::classes::CEntity::DoesExist() {
	return ((int(__thiscall *)(CEntity *))SAMP_ADDROF(0x9AA10))(this);
}

int SAMP::classes::CEntity::EnforceWorldBoundries(float fPX, float fZX, float fPY, float fNY) {
	return ((int(__thiscall *)(CEntity *, float, float, float, float))SAMP_ADDROF(0x9AA60))(this, fPX, fZX, fPY, fNY);
}

int SAMP::classes::CEntity::HasExceededWorldBoundries(float fPX, float fZX, float fPY, float fNY) {
	return ((int(__thiscall *)(CEntity *, float, float, float, float))SAMP_ADDROF(0x9AC00))(this, fPX, fZX, fPY, fNY);
}

void SAMP::classes::CEntity::SetClumpAlpha(int nValue) {
	((void(__thiscall *)(CEntity *, int))SAMP_ADDROF(0x9ADD0))(this, nValue);
}

void SAMP::classes::CEntity::SetFromEuler(CVector angles) {
	((void(__thiscall *)(CEntity *, CVector))SAMP_ADDROF(0x9AE30))(this, angles);
}

void SAMP::classes::CEntity::GetEulerInverted(float *pX, float *pY, float *pZ) {
	((void(__thiscall *)(CEntity *, float *, float *, float *))SAMP_ADDROF(0x9AF30))(this, pX, pY, pZ);
}

void SAMP::classes::CEntity::ApplyTurnForce(CVector direction, CVector velocity) {
	((void(__thiscall *)(CEntity *, CVector, CVector))SAMP_ADDROF(0x9B010))(this, direction, velocity);
}

SAMP::classes::CEntity::CEntity() {
	((void(__thiscall *)(CEntity *))SAMP_ADDROF(0x97C10))(this);
}

BOOL SAMP::classes::CEntity::IsStationary() {
	return ((BOOL(__thiscall *)(CEntity *))SAMP_ADDROF(0x9B420))(this);
}

SAMP::classes::RwObject *SAMP::classes::CEntity::GetRwObject() {
	return ((RwObject *(__thiscall *)(CEntity *))SAMP_ADDROF(0x9B0A0))(this);
}

BOOL SAMP::classes::CEntity::IsIgnored() {
	return ((BOOL(__thiscall *)(CEntity *))SAMP_ADDROF(0x9B320))(this);
}

BOOL SAMP::classes::CEntity::GetCollisionFlag() {
	return ((BOOL(__thiscall *)(CEntity *))SAMP_ADDROF(0x9ACA0))(this);
}

void SAMP::classes::CEntity::SetCollisionFlag(BOOL bEnable) {
	((void(__thiscall *)(CEntity *, BOOL))SAMP_ADDROF(0x9AC70))(this, bEnable);
}

void SAMP::classes::CEntity::SetCollisionProcessed(BOOL bProcessed) {
	((void(__thiscall *)(CEntity *, BOOL))SAMP_ADDROF(0x9ACC0))(this, bProcessed);
}

void SAMP::classes::CEntity::DeleteRwObject() {
	((void(__thiscall *)(CEntity *))SAMP_ADDROF(0x9B1F0))(this);
}