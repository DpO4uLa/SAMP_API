/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R3_COMPILE

#include "common_R3.h"

SAMP_BEGIN

class SAMP_API CChatBubble {
public:
	struct SAMP_API Player {
		BOOL		m_bExists;
		char		m_szText[256];
		int		m_creationTick;
		int		m_lifeSpan;
		D3DCOLOR m_color;
		float		m_fDrawDistance;
		int		m_nMaxLineLength;
	} m_player[1004];

	CChatBubble();

	void Add(ID nPlayer, const char *szText, D3DCOLOR color, float fDrawDistance, int lifeSpan);
	void Draw();
};

extern CChatBubble *&pChatBubble;

SAMP_END

#endif