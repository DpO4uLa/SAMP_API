/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "CCamera.h"

SAMP::classes::CCamera::CCamera() {
	((void(__thiscall *)(CCamera *))SAMP_ADDROF(0x9B5A0))(this);
}

void SAMP::classes::CCamera::Detach() {
	((void(__thiscall *)(CCamera *))SAMP_ADDROF(0x990E0))(this);
}

void SAMP::classes::CCamera::Set(CVector position, CVector rotation) {
	((void(__thiscall *)(CCamera *, CVector, CVector))SAMP_ADDROF(0x99120))(this, position, rotation);
}

void SAMP::classes::CCamera::PointAt(CVector position, int nSwitchStyle) {
	((void(__thiscall *)(CCamera *, CVector, int))SAMP_ADDROF(0x99180))(this, position, nSwitchStyle);
}

void SAMP::classes::CCamera::Restore() {
	((void(__thiscall *)(CCamera *))SAMP_ADDROF(0x991D0))(this);
}

void SAMP::classes::CCamera::SetTrackVector(CVector *pPointAt, CVector *pTransverseTo, int nTime, bool bSmooth) {
	((void(__thiscall *)(CCamera *, CVector *, CVector *, unsigned int, bool))SAMP_ADDROF(0x98FA0))(this, pPointAt, pTransverseTo, nTime, bSmooth);
}

void SAMP::classes::CCamera::SetMoveVector(CVector *pCamera, CVector *pPosition, int nTime, bool bSmoothTransmition) {
	((void(__thiscall *)(CCamera *, CVector *, CVector *, unsigned int, bool))SAMP_ADDROF(0x98F30))(this, pCamera, pPosition, nTime, bSmoothTransmition);
}

void SAMP::classes::CCamera::SetToOwner() {
	((void(__thiscall *)(CCamera *))SAMP_ADDROF(0x99050))(this);
}

void SAMP::classes::CCamera::Attach(CEntity *pEntity) {
	((void(__thiscall *)(CCamera *, CEntity *))SAMP_ADDROF(0x99000))(this, pEntity);
}

void SAMP::classes::CCamera::GetMatrix(CMatrix *pMatrix) {
	((void(__thiscall *)(CCamera *, CMatrix *))SAMP_ADDROF(0x98E00))(this, pMatrix);
}

float SAMP::classes::CCamera::GetDistanceToPoint(CVector *pPosition) {
	return ((float(__thiscall *)(CCamera *, CVector *))SAMP_ADDROF(0x990A0))(this, pPosition);
}

void SAMP::classes::CCamera::Fade(BOOL bIn) {
	((void(__thiscall *)(CCamera *, bool))SAMP_ADDROF(0x98DE0))(this, bIn);
}

void SAMP::classes::CCamera::SetMatrix(CMatrix matrix) {
	((void(__thiscall *)(CCamera *, CMatrix))SAMP_ADDROF(0x98E80))(this, matrix);
}

void SAMP::classes::CCamera::TakeControl(CEntity *pTarget, short nModeToGoTo, short nTypeOfSwitch) {
	((void(__thiscall *)(CCamera *, CEntity *, short, short))SAMP_ADDROF(0x98F10))(this, pTarget, nModeToGoTo, nTypeOfSwitch);
}