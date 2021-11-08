/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "CAudio.h"

void SAMP::classes::CAudio::Play(int nSound, CVector location) {
	((void(__thiscall *)(CAudio *, int, CVector))SAMP_ADDROF(0x9D730))(this, nSound, location);
}

void SAMP::classes::CAudio::StartRadio(unsigned char nStation) {
	((void(__thiscall *)(CAudio *, unsigned char))SAMP_ADDROF(0x9D860))(this, nStation);
}

float SAMP::classes::CAudio::GetRadioVolume() {
	return ((float(__thiscall *)(CAudio *))SAMP_ADDROF(0x9D8A0))(this);
}