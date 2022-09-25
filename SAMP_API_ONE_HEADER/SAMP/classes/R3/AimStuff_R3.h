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

SAMP_BEGIN

namespace AimStuff {
	struct Aim {
		CVector front;
		CVector source;
		CVector sourceBeforeLookBehind;
		CVector up;
	};

	extern float &fLocalPlayerCameraExtZoom;
	extern float &fLocalPlayerAspectRatio;
	extern float *&pInternalCameraExtZoom;
	extern float *&pInternalAspectRatio;
	extern float *aCameraExtZoom;
	extern float *aAspectRatio;
	extern char *aCameraMode;
	extern char *&pInternalCameraMode;
	extern Aim &localPlayerAim;
	extern Aim *aPlayerAim;
	extern Aim *&pInternalAim;

	void UpdateCameraExtZoomAndAspectRatio();
	void ApplyCameraExtZoomAndAspectRatio();
	void SetCameraExtZoomAndAspectRatio(NUMBER nPlayer, float fCameraExtZoom, float fAspectRatio);
	float GetAspectRatio();
	float GetCameraExtZoom();
	void ApplyCameraExtZoomAndAspectRatio(NUMBER nPlayer);
	void SetCameraMode(char nMode, NUMBER nPlayer);
	char GetCameraMode(NUMBER nPlayer);
	char GetCameraMode();
	void Initialize();
	void UpdateAim();
	void ApplyAim();
	Aim *GetAim();
	void SetAim(int nPlayer, const Aim *pAim);
	void ApplyAim(int nPlayer);
	Aim *GetAim(int nPlayer);
}

SAMP_END

#endif