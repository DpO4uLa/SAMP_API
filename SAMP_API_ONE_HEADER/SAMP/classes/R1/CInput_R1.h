/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R1_COMPILE

#include "common_R1.h"
#include "CRect_R1.h"
#include "Commands_R1.h"

#define MAX_CLIENT_CMDS 144
#define MAX_CMD_LENGTH 32

SAMP_BEGIN

class SAMP_API CInput {
public:
	IDirect3DDevice9 *m_pDevice;
	CDXUTDialog		  *m_pGameUi;
	CDXUTEditBox	  *m_pEditbox;
	CMDPROC				m_pCommandProc[MAX_CLIENT_CMDS];
	char					m_szCommandName[MAX_CLIENT_CMDS][MAX_CMD_LENGTH + 1];
	int					m_nCommandCount;
	BOOL					m_bEnabled;
	char					m_szInput[129];
	char					m_szRecallBufffer[10][129];
	char					m_szCurrentBuffer[129];
	int					m_nCurrentRecall;
	int					m_nTotalRecall;
	CMDPROC				m_pDefaultCommand;

	CInput(IDirect3DDevice9 *pDevice);

	void GetRect(CRect *pRect);
	void Open();
	void Close();
	void AddRecall(const char *szString);
	void RecallUp();
	void RecallDown();
	void EnableCursor();
	CMDPROC GetCommandHandler(const char *szName);
	void SetDefaultCommand(CMDPROC handler);
	void AddCommand(const char *szName, CMDPROC handler);
	BOOL MsgProc(int uMsg, int wParam, int lParam);
	void ResetDialogControls(CDXUTDialog *pGameUi);
	void Send(const char *szString);
	void ProcessInput();
};

extern CInput *&pInputBox;

SAMP_END

#endif