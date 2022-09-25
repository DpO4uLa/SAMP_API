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

enum SpecialAction {
	None,
	Duck,
	Jetpack,
	EnterVehicle,
	ExitVehicle,
	Dance1,
	Dance2,
	Dance3,
	Dance4,
	HandsUp,
	Cellphone,
	Sitting,
	EndCellphone,
	DrinkBeer = 20,
	SmokeCiggi,
	PintGlass,
	DrinkDynBeer,
	Cuffed,
	Carry,
	Urinating = 68
};

SAMP_END

#endif