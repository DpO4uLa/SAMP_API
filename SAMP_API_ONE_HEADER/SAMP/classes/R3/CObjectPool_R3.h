/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R3_COMPILE

#include "common_R3.h"
#include "CVector_R3.h"
#include "CObject_R3.h"

#define MAX_OBJECTS 1000

SAMP_BEGIN

class CObject;

class SAMP_API CObjectPool {
public:
	int			m_nLargestId;
	BOOL			m_bNotEmpty[MAX_OBJECTS];
	CObject	  *m_pObject[MAX_OBJECTS];

	CObjectPool();
	~CObjectPool();

	void UpdateLargestId();
	int GetCount();
	BOOL Delete(ID nId);
	BOOL Create(ID nId, int nModel, CVector position, CVector rotation, float fDrawDistance);
	CObject *Find(CObject *pGameObject);
	int GetId(CObject *pGameObject);
	void Process();
	void ConstructMaterials();
	void ShutdownMaterials();
	void Draw();
	void DrawLast();
	CObject *GetObject(ID nId);
};

SAMP_END

#endif