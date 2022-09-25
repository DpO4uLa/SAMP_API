/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R3_COMPILE

#include "common_R3.h"
#include "CMenu_R3.h"

#define MAX_MENUS 128

SAMP_BEGIN

class SAMP_API CMenuPool {
public:
	CMenu			  *m_pObject[MAX_MENUS];
	BOOL				m_bNotEmpty[MAX_MENUS];
	NUMBER			m_nCurrent;
	bool				m_bCanceled;

	CMenuPool();
	~CMenuPool();

	CMenu *Create(NUMBER nId, const char *szTitle, float fX, float fY, char nColumns, float fFirstColumnWidth, float fSecondColumnWidth, const CMenu::Interaction *pInteraction);
	BOOL Delete(NUMBER nId);
	void Show(NUMBER nId);
	void Hide(NUMBER nId);
	char *GetTextPointer(const char *szName);
	void Process();
};

SAMP_END

#endif