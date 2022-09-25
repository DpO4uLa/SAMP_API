/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "CActor_R1.h"

SAMP::classes::CActor::CActor(int nSkin, CVector vPos, float fRotation) {
	((void(__thiscall *)(CActor *, int, CVector, float))SAMP_ADDROF(0x97C60))(this, nSkin, vPos, fRotation);
}

void SAMP::classes::CActor::Destroy() {
	((void(__thiscall *)(CActor *))SAMP_ADDROF(0x97DA0))(this);
}

void SAMP::classes::CActor::PerformAnimation(const char *szAnim, const char *szIFP, float fFramedelta, int bLockA, int bLockX, int bLockY, int bLockF, int nTime) {
	((void(__thiscall *)(CActor *, const char *, const char *, float, int, int, int, int, int))SAMP_ADDROF(0x97E00))(this, szAnim, szIFP, fFramedelta, bLockA, bLockX, bLockY, bLockF, nTime);
}

void SAMP::classes::CActor::SetRotation(float fValue) {
	((void(__thiscall *)(CActor *, float))SAMP_ADDROF(0x97F10))(this, fValue);
}

void SAMP::classes::CActor::SetHealth(float fValue) {
	((void(__thiscall *)(CActor *, float))SAMP_ADDROF(0x97F70))(this, fValue);
}

float SAMP::classes::CActor::GetHealth() {
	return ((float(__thiscall *)(CActor *))SAMP_ADDROF(0x97F50))(this);
}

void SAMP::classes::CActor::SetInvulnerable(bool bInv) {
	((void(__thiscall *)(CActor *, bool))SAMP_ADDROF(0x980A0))(this, bInv);
}

void SAMP::classes::CActor::SetArmour(float fValue) {
	((void(__thiscall *)(CActor *, float))SAMP_ADDROF(0x97FD0))(this, fValue);
}

float SAMP::classes::CActor::GetArmour() {
	return ((float(__thiscall *)(CActor *))SAMP_ADDROF(0x97FB0))(this);
}

void SAMP::classes::CActor::SetState(int nValue) {
	((void(__thiscall *)(CActor *, int))SAMP_ADDROF(0x98000))(this, nValue);
}

int SAMP::classes::CActor::GetState() {
	return ((int(__thiscall *)(CActor *))SAMP_ADDROF(0x97FF0))(this);
}

BOOL SAMP::classes::CActor::IsDead() {
	return ((BOOL(__thiscall *)(CActor *))SAMP_ADDROF(0x98020))(this);
}

void SAMP::classes::CActor::SetStatus(int nValue) {
	((void(__thiscall *)(CActor *, int))SAMP_ADDROF(0x98060))(this, nValue);
}

int SAMP::classes::CActor::GetStatus() {
	return ((int(__thiscall *)(CActor *))SAMP_ADDROF(0x98050))(this);
}

#endif