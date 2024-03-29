/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R1_COMPILE

#include "common_R1.h"

SAMP_BEGIN

struct SAMP_API Animation {
	union {
		struct {
			unsigned short	 m_nId : 16;
			unsigned char	 m_nFramedelta : 8;
			unsigned char   m_nLoopA : 1;
			unsigned char   m_nLockX : 1;
			unsigned char   m_nLockY : 1;
			unsigned char   m_nLockF : 1;
			unsigned char   m_nTime : 2;
		};
		int m_value;
	};
};

SAMP_END

#endif