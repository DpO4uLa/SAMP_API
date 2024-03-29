/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R1_COMPILE

#include "common_R1.h"
#include "CPlayerInfo_R1.h"
#include "CLocalPlayer_R1.h"
#include <string>

#define SAMP_MAX_PLAYERS 1004

SAMP_BEGIN

class CObject;

class SAMP_API CPlayerPool {
public:
	int						m_nLargestId;
	struct {
		ID						m_nId;
#ifndef _DEBUG
	private:
		int __align;
	public:
#endif
		std::string			m_szName;
		CLocalPlayer	  *m_pObject;
		int					m_nPing;
		int					m_nScore;
	}							m_localInfo;
	CPlayerInfo			  *m_pObject[SAMP_MAX_PLAYERS];
	BOOL						m_bNotEmpty[SAMP_MAX_PLAYERS];
	BOOL						m_bPrevCollisionFlag[SAMP_MAX_PLAYERS];

	CPlayerPool();
	~CPlayerPool();

	void UpdateLargestId();
	void Process();
	ID Find(CPed *pGamePed);
	void Deactivate();
	void ForceCollision();
	void RestoreCollision();
	BOOL Delete(ID nId, int nReason = SAMP_UNUSED);
	BOOL Create(ID nId, const char *szName, BOOL bIsNPC);
	CRemotePlayer *GetPlayer(ID nId);
	const char *GetLocalPlayerName();
	BOOL IsDisconnected(ID nId);
	BOOL IsConnected(ID nId);
	void SetLocalPlayerName(const char *szName);
	void SetAt(ID nId, CPlayerInfo *pObject);
	int GetScore(ID nId);
	int GetPing(ID nId);
	const char *GetName(ID nId);
	int GetLocalPlayerPing() { return m_localInfo.m_nPing; }
	int GetLocalPlayerScore() { return m_localInfo.m_nScore; }
	int GetCount(BOOL bIncludeNPC = 0);
	CLocalPlayer *GetLocalPlayer();
   CObject *FindAccessory(CObject *pGameObject);
	CPlayerInfo *GetAt(ID nId);
	BOOL IsNPC(ID nId);
	void SetPing(ID nId, int nValue);
	void SetScore(ID nId, int nValue);
};

SAMP_END

#endif