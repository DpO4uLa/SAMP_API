/*
	This is a SAMP API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#ifdef SAMP_R1_COMPILE

#include "common_R1.h"

SAMP_BEGIN

class SAMP_API CRect {
public:
	long left, top;
	long right, bottom;

	CRect();
	CRect(long left, long top, long right, long bottom);

	long GetWidth();
	long GetHeight();
	void Move(long x, long y);
	void Resize(long x, long y);
	void SetSize(long w, long h);
	void GetCenter(long *x, long *y);
	bool IsPointInside(long x, long y);
};

SAMP_END

#endif