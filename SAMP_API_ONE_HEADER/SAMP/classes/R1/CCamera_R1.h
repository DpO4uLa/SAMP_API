/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R1_COMPILE

#include "common_R1.h"
#include "CVector_R1.h"
#include "CMatrix_R1.h"
#include "CEntity_R1.h"

SAMP_BEGIN

class CEntity;

class SAMP_API CCamera {
public:
	CEntity *m_pAttachedTo;
	CMatrix *m_pMatrix;

	CCamera();
	~CCamera() { Detach(); }

	void Fade(BOOL bin);
	void GetMatrix(CMatrix *pMatrix);
	void SetMatrix(CMatrix matrix);
	void TakeControl(CEntity *pTarget, short nModeToGoTo, short nTypeOfSwitch);
	void SetMoveVector(CVector *pCamera, CVector *pPosition, int nTime, bool bSmoothTransmition);
	void SetTrackVector(CVector *pPointAt, CVector *pTransverseTo, int nTime, bool bSmooth);
	void Attach(CEntity *pOwner);
	void SetToOwner();
	float GetDistanceToPoint(CVector *pPoint);
	void Restore();
	void Set(CVector position, CVector rotation);
	void PointAt(CVector point, int nSwitchStyle);
	void Detach();
};

SAMP_END

#endif
