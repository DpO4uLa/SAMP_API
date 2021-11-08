/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "VehicleSelection.h"

SAMP::classes::CCamera *&SAMP::classes::VehicleSelection::pCamera = *(SAMP::classes::CCamera **)SAMP_ADDROF(0x13BA7C);
SAMP::classes::CVehicle *&SAMP::classes::VehicleSelection::pVehicle = *(SAMP::classes::CVehicle **)SAMP_ADDROF(0x13BB64);
CPad *&SAMP::classes::VehicleSelection::pControls = *(CPad **)SAMP_ADDROF(0x13BA78);
BOOL &SAMP::classes::VehicleSelection::bInitialized = *(BOOL *)SAMP_ADDROF(0x13BB60);
int &SAMP::classes::VehicleSelection::nSelectedModel = *(int *)SAMP_ADDROF(0x1014B4);

void SAMP::classes::VehicleSelection::ResetVehicle() {
	((void(__cdecl *)())SAMP_ADDROF(0x99710))();
}

void SAMP::classes::VehicleSelection::Process() {
	((void(__cdecl *)())SAMP_ADDROF(0x99AD0))();
}