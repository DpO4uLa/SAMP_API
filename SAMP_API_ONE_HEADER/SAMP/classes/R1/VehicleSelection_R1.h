/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R1_COMPILE

#include "common_R1.h"
#include "CVehicle_R1.h"
#include "CCamera_R1.h"
#include "KeyStuff_R1.h"

SAMP_BEGIN

namespace VehicleSelection {
	extern CCamera *&pCamera;
	extern CVehicle *&pVehicle;
	extern CPad *&pControls;
	extern BOOL &bInitialized;
	extern int &nSelectedModel;

	void ResetVehicle();
	void Process();
}

SAMP_END

#endif