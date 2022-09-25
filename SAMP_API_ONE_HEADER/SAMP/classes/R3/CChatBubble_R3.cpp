/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CChatBubble_R3.h"

SAMP::classes::CChatBubble *&SAMP::classes::pChatBubble = *(SAMP::classes::CChatBubble **)SAMP_ADDROF(0x26E8C0);

SAMP::classes::CChatBubble::CChatBubble() {
	((void(__thiscall *)(CChatBubble *))SAMP_ADDROF(0x66670))(this);
}

void SAMP::classes::CChatBubble::Add(ID nPlayer, const char *szText, D3DCOLOR color, float fDrawDistance, int lifeSpan) {
	((void(__thiscall *)(CChatBubble *, ID, const char *, D3DCOLOR, float, int))SAMP_ADDROF(0x666A0))(this, nPlayer, szText, color, fDrawDistance, lifeSpan);
}

void SAMP::classes::CChatBubble::Draw() {
	((void(__thiscall *)(CChatBubble *))SAMP_ADDROF(0x66760))(this);
}

#endif