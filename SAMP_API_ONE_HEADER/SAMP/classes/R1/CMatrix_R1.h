/*
	This is a SAMP API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R1_COMPILE

#include "common_R1.h"
#include "CVector_R1.h"

SAMP_BEGIN

class SAMP_API CMatrix {
public:
	CVector right;
	unsigned long flags;
	CVector up;
	float pad_u;
	CVector at;
	float pad_a;
	CVector pos;
	float pad_p;
};

SAMP_END

#endif