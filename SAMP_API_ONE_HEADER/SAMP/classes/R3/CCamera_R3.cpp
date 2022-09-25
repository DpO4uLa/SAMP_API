/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CCamera_R3.h"

SAMP::classes::CCamera::CCamera() {
	((void(__thiscall *)(CCamera *))SAMP_ADDROF(0x9F850))(this);
}

SAMP::classes::CCamera::~CCamera() {
	((void(__thiscall *)(CCamera *))SAMP_ADDROF(0x9F860))(this);
}

void SAMP::classes::CCamera::Fade(BOOL bIn) {
	((void(__thiscall *)(CCamera *, BOOL))SAMP_ADDROF(0x9CD30))(this, bIn);
}

void SAMP::classes::CCamera::GetMatrix(CMatrix *pMatrix) {
	((void(__thiscall *)(CCamera *, CMatrix *))SAMP_ADDROF(0x9CD50))(this, pMatrix);
}

void SAMP::classes::CCamera::SetMatrix(CMatrix matrix) {
	((void(__thiscall *)(CCamera *, CMatrix))SAMP_ADDROF(0x9CDD0))(this, matrix);
}

void SAMP::classes::CCamera::TakeControl(SAMP::classes::CEntity *pTarget, short nModeToGoTo, short nTypeOfSwitch) {
	((void(__thiscall *)(CCamera *, SAMP::classes::CEntity *, short, short))SAMP_ADDROF(0x9CE60))(this, pTarget, nModeToGoTo, nTypeOfSwitch);
}

void SAMP::classes::CCamera::SetMoveVector(CVector *pCamera, CVector *pPosition, int nTime, bool bSmoothTransmition) {
	((void(__thiscall *)(CCamera *, CVector *, CVector *, int, bool))SAMP_ADDROF(0x9CE80))(this, pCamera, pPosition, nTime, bSmoothTransmition);
}

void SAMP::classes::CCamera::SetTrackVector(CVector *pPointAt, CVector *pTransverseTo, int nTime, bool bSmooth) {
	((void(__thiscall *)(CCamera *, CVector *, CVector *, int, bool))SAMP_ADDROF(0x9CEF0))(this, pPointAt, pTransverseTo, nTime, bSmooth);
}

void SAMP::classes::CCamera::Attach(CEntity *pOwner) {
	((void(__thiscall *)(CCamera *, CEntity *))SAMP_ADDROF(0x9CF50))(this, pOwner);
}

void SAMP::classes::CCamera::SetToOwner() {
	((void(__thiscall *)(CCamera *))SAMP_ADDROF(0x9CFA0))(this);
}

float SAMP::classes::CCamera::GetDistanceToPoint(CVector *pPoint) {
	return ((float(__thiscall *)(CCamera *, CVector *))SAMP_ADDROF(0x9CFF0))(this, pPoint);
}

void SAMP::classes::CCamera::Restore() {
	((void(__thiscall *)(CCamera *))SAMP_ADDROF(0x9D030))(this);
}

void SAMP::classes::CCamera::Set(CVector position, CVector rotation) {
	((void(__thiscall *)(CCamera *, CVector, CVector))SAMP_ADDROF(0x9D070))(this, position, rotation);
}

void SAMP::classes::CCamera::PointAt(CVector point, int nSwitchStyle) {
	((void(__thiscall *)(CCamera *, CVector, int))SAMP_ADDROF(0x9D0D0))(this, point, nSwitchStyle);
}

void SAMP::classes::CCamera::Detach() {
	((void(__thiscall *)(CCamera *))SAMP_ADDROF(0x9D120))(this);
}

#endif