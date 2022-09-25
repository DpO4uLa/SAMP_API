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

#define AUDIOSTREAM_MAX_STRING 256
#define AUDIOSTREAM_USERAGENT "SA-MP/0.3"

SAMP_BEGIN

class SAMP_API CAudioStream {
public:
	bool m_bInitialized;

	static int &hStream;
	static bool &bIsPlaying;
	static CVector &position;
	static bool &bIs3d;
	static char *szIcyUrl;
	static char *szInfo;
	static char *szUrl;
	static bool &bNeedsToDestroy;
	static float &fRadius;
	static char *szIcyName;

	static void ConstructInfo();
	static void SyncProc(int handle, int channel, int data, void *user);
	static void Process(void *arglist);

	BOOL Reset();
	BOOL Stop(bool bWait);
	BOOL Play(const char *szUrl, CVector position, float fRadius, bool bIs3d);
	void ControlGameRadio();
	void DrawInfo();
};

extern CAudioStream *&pAudioStream;

SAMP_END

#endif