/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R1_COMPILE

#include "common_R1.h"
#include "CEntity_R1.h"

SAMP_BEGIN

class CPed;

class SAMP_API CActor : public CEntity {
public:
	// void **lpVtbl = 0xD9EC8;
	CPed  *m_pGamePed;
	GTAREF	m_marker;
	GTAREF 	m_arrow;
	bool		m_bNeedsToCreateMarker;
	bool		m_bInvulnerable;

	CActor() { *(void **)this = (void *)SAMP_ADDROF(0xD9EC8); }
	CActor(int nSkin, CVector vPos, float fRotation);

	virtual ~CActor() {}

	void Destroy();
	void PerformAnimation(const char *szAnim, const char *szIFP, float fFramedelta, int bLockA, int bLockX, int bLockY, int bLockF, int nTime);
	void SetRotation(float fValue);
	void SetHealth(float fValue);
	float GetHealth();
	void SetInvulnerable(bool bInv);
	void SetArmour(float fValue);
	float GetArmour();
	// state/status is a flags
	void SetState(int nValue);
	int GetState();
	BOOL IsDead();
	void SetStatus(int nValue);
	int GetStatus();
};

SAMP_END

#endif