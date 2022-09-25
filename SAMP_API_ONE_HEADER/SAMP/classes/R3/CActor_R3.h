/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R3_COMPILE

#include "common_R3.h"
#include "CEntity_R3.h"

SAMP_BEGIN

class CPed;

class SAMP_API CActor : public CEntity {
public:
	// void **m_lpVtbl = 0xEC298;
	CPed  *m_pGamePed;
	GTAREF	m_marker;
	GTAREF 	m_arrow;
	bool		m_bNeedsToCreateMarker;
	bool		m_bInvulnerable;

	virtual ~CActor() SAMP_VIRTUAL

	CActor() { *(void **)this = (void *)SAMP_ADDROF(0xEC298); }
	CActor(int nModel, CVector position, float fRotation);

	void Destroy();
	void PerformAnimation(const char *szAnim, const char *szIFP, float fFramedelta, int bLockA, int bLockX, int bLockY, int bLockF, int nTime);
	void SetRotation(float fAngle);
	float GetHealth();
	void SetHealth(float fAngle);
	void SetInvulnerable(bool bEnable);
};

SAMP_END

#endif