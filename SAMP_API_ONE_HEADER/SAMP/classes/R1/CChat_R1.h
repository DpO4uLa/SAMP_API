/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R1_COMPILE

#include "common_R1.h"
#include "CFonts_R1.h"

SAMP_BEGIN

enum ChatEntry {
	CHAT_TYPE_NONE = 0,
	CHAT_TYPE_CHAT = 1 << 1,
	CHAT_TYPE_INFO = 1 << 2,
	CHAT_TYPE_DEBUG = 1 << 3
};

class SAMP_API CChat {
public:
	unsigned int			m_nPageSize;
	char					  *m_szLastMessage;
	int						m_nMode;
	bool						m_bTimestamps;
	BOOL						m_bDoesLogExist;
	char						m_szLogPath[261]; // MAX_PATH(+1)
	CDXUTDialog			  *m_pGameUi; 
	CDXUTEditBox        *m_pEditbox; 
	CDXUTScrollBar	     *m_pScrollbar; 
	D3DCOLOR					m_textColor;  // 0xFFFFFFFF
	D3DCOLOR					m_infoColor;  // 0xFF88AA62
	D3DCOLOR					m_debugColor; // 0xFFA9C4E4
	long						m_nWindowBottom;
	struct SAMP_API {
		__int32			m_timestamp;
		char				m_szPrefix[28];
		char				m_szText[144];
		char unused[64];
		int				m_nType;
		D3DCOLOR			m_textColor;
		D3DCOLOR			m_prefixColor;
	}							m_entry[100];
	CFonts				  *m_pFontRenderer;
	ID3DXSprite			  *m_pTextSprite;
	ID3DXSprite			  *m_pSprite;
	IDirect3DDevice9	  *m_pDevice;
	BOOL						m_bRenderToSurface;
	ID3DXRenderToSurface*m_pRenderToSurface;
	IDirect3DTexture9	  *m_pTexture;
	IDirect3DSurface9	  *m_pSurface;
#ifdef _d3d9TYPES_H_
	D3DDISPLAYMODE		   m_displayMode;
#else
	unsigned int			m_displayMode[4];
#endif
	int						pad_[2];
	BOOL						m_bRedraw;
	long						m_nScrollbarPos;
	long						m_nCharHeight; // this is the height of the "Y" 
	long						m_nTimestampWidth;

	enum { Off, NoShadow, Normal };

	CChat(IDirect3DDevice9 *pDevice, CFonts *pFontRenderer, const char *pChatLogPath);
	~CChat();

	int GetMode() { return m_nMode; }
	void SwitchMode();
	void RecalcFontSize();
	void OnLostDevice();
	void UpdateScrollbar();
	void SetPageSize(int nValue);
	void PageUp();
	void PageDown();
	void ScrollToBottom();
	void Scroll(int nDelta);
	void FilterOutInvalidChars(char *szString);
	void PushBack();
	void RenderEntry(const char *szText, CRect rect, D3DCOLOR color);
	void Log(int nType, const char *szText, const char *szPrefix);
	void ResetDialogControls(CDXUTDialog *pGameUi);
	void Render();
	void AddEntry(int nType, const char *szText, const char *szPrefix, D3DCOLOR textColor, D3DCOLOR prefixColor);
	void Draw();
	void RenderToSurface();
	void AddChatMessage(const char *szPrefix, D3DCOLOR prefixColor, const char *szText);
	void AddMessage(D3DCOLOR color, const char *szText);
	void OnResetDevice();

	static void Print(CChat *pChat, D3DCOLOR dwColor, const char *pFormat, ...);
};

extern CChat *&pChat;

SAMP_END

#endif