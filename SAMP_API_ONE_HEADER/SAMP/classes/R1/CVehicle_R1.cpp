/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "CVehicle_R1.h"

SAMP::classes::CVehicle::CVehicle(int nModel, CVector position, float fRotation, BOOL bKeepModelLoaded, BOOL bHasSiren) {
	((void(__thiscall *)(CVehicle *, int, CVector, float, BOOL, BOOL))SAMP_ADDROF(0xB1E70))(this, nModel, position, fRotation, bKeepModelLoaded, bHasSiren);
}

void SAMP::classes::CVehicle::ResetPointers() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0B70))(this);
}

void SAMP::classes::CVehicle::ChangeInterior(int nInterior) {
	((void(__thiscall *)(CVehicle *, int))SAMP_ADDROF(0xB0B40))(this, nInterior);
}

BOOL SAMP::classes::CVehicle::IsOccupied() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0BE0))(this);
}

void SAMP::classes::CVehicle::SetInvulnerable(BOOL bInv) {
	((void(__thiscall *)(CVehicle *, BOOL))SAMP_ADDROF(0xB0C40))(this, bInv);
}

void SAMP::classes::CVehicle::SetLocked(BOOL bLocked) {
	((void(__thiscall *)(CVehicle *, BOOL))SAMP_ADDROF(0xB0CE0))(this, bLocked);
}

float SAMP::classes::CVehicle::GetHealth() {
	return ((float(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0D50))(this);
}

void SAMP::classes::CVehicle::SetHealth(float fValue) {
	((void(__thiscall *)(CVehicle *, float))SAMP_ADDROF(0xB0D70))(this, fValue);
}

void SAMP::classes::CVehicle::SetColor(NUMBER nPrimary, NUMBER nSecondary) {
	((void(__thiscall *)(CVehicle *, NUMBER, NUMBER))SAMP_ADDROF(0xB0D90))(this, nPrimary, nSecondary);
}

int SAMP::classes::CVehicle::GetSubtype() {
	return ((int(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0E40))(this);
}

BOOL SAMP::classes::CVehicle::IsSunk() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0E60))(this);
}

BOOL SAMP::classes::CVehicle::IsWrecked() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0E80))(this);
}

BOOL SAMP::classes::CVehicle::DriverIsPlayerPed() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0EA0))(this);
}

BOOL SAMP::classes::CVehicle::IsTrainPart() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0F10))(this);
}

void SAMP::classes::CVehicle::ProcessMarkers() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1190))(this);
}

void SAMP::classes::CVehicle::Lock(BOOL bLock) {
	((void(__thiscall *)(CVehicle *, BOOL))SAMP_ADDROF(0xB12F0))(this, bLock);
}

BOOL SAMP::classes::CVehicle::UpdateLastDrivenTime() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1320))(this);
}

char SAMP::classes::CVehicle::GetTires() {
	return ((char(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB14E0))(this);
}

void SAMP::classes::CVehicle::UpdateDamage(int nPanels, int nDoors, char nLights) {
	((void(__thiscall *)(CVehicle *, int, int, char))SAMP_ADDROF(0xB1570))(this, nPanels, nDoors, nLights);
}

int SAMP::classes::CVehicle::GetPanelsDamage() {
	return ((int(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1630))(this);
}

int SAMP::classes::CVehicle::GetDoorsDamage() {
	return ((int(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1660))(this);
}

char SAMP::classes::CVehicle::GetLightsDamage() {
	return ((char(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1690))(this);
}

void SAMP::classes::CVehicle::AttachTrailer() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB16C0))(this);
}

void SAMP::classes::CVehicle::DetachTrailer() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB16E0))(this);
}

void SAMP::classes::CVehicle::SetTrailer(CVehicle *pTrailer) {
	((void(__thiscall *)(CVehicle *, CVehicle *))SAMP_ADDROF(0xB1730))(this, pTrailer);
}

SAMP::classes::CVehicle *SAMP::classes::CVehicle::GetTrailer() {
	return ((CVehicle *(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1740))(this);
}

void SAMP::classes::CVehicle::SetLicensePlateText(const char *szText) {
	((void(__thiscall *)(CVehicle *, const char *))SAMP_ADDROF(0xB1BF0))(this, szText);
}

void SAMP::classes::CVehicle::SetRotation(float fValue) {
	((void(__thiscall *)(CVehicle *, float))SAMP_ADDROF(0xB1C10))(this, fValue);
}

void SAMP::classes::CVehicle::ConstructLicensePlate() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1C40))(this);
}

void SAMP::classes::CVehicle::ShutdownLicensePlate() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1C90))(this);
}

BOOL SAMP::classes::CVehicle::HasDriver() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0B90))(this);
}

void SAMP::classes::CVehicle::UpdateColor() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0DE0))(this);
}

BOOL SAMP::classes::CVehicle::HasPlayerPed() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0ED0))(this);
}

BOOL SAMP::classes::CVehicle::HasTurret() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB0F50))(this);
}

void SAMP::classes::CVehicle::EnableSiren(bool bEnable) {
	((void(__thiscall *)(CVehicle *, bool))SAMP_ADDROF(0xB0FF0))(this, bEnable);
}

BOOL SAMP::classes::CVehicle::SirenEnabled() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1010))(this);
}

void SAMP::classes::CVehicle::SetLandingGearState(BOOL bHide) {
	((void(__thiscall *)(CVehicle *, BOOL))SAMP_ADDROF(0xB1050))(this, bHide);
}

BOOL SAMP::classes::CVehicle::GetLandingGearState() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB10E0))(this);
}

void SAMP::classes::CVehicle::SetHydraThrusters(int nDirection) {
	((void(__thiscall *)(CVehicle *, int))SAMP_ADDROF(0xB1150))(this, nDirection);
}

int SAMP::classes::CVehicle::GetHydraThrusters() {
	return ((int(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1170))(this);
}

float SAMP::classes::CVehicle::GetTrainSpeed() {
	return ((float(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1390))(this);
}

void SAMP::classes::CVehicle::SetTrainSpeed(float fValue) {
	((void(__thiscall *)(CVehicle *, float))SAMP_ADDROF(0xB13B0))(this, fValue);
}

void SAMP::classes::CVehicle::SetTires(char nState) {
	((void(__thiscall *)(CVehicle *, char))SAMP_ADDROF(0xB13F0))(this, nState);
}

SAMP::classes::CVehicle *SAMP::classes::CVehicle::GetTractor() {
	return ((CVehicle *(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB17A0))(this);
}

BOOL SAMP::classes::CVehicle::IsTrailer() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1820))(this);
}

BOOL SAMP::classes::CVehicle::IsTowtruck() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1880))(this);
}

BOOL SAMP::classes::CVehicle::IsRC() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB18B0))(this);
}

void SAMP::classes::CVehicle::EnableLights(bool bEnable) {
	((void(__thiscall *)(CVehicle *, bool))SAMP_ADDROF(0xB1900))(this, bEnable);
}

void SAMP::classes::CVehicle::RemovePassengers() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1990))(this);
}

BOOL SAMP::classes::CVehicle::AddComponent(unsigned short nId) {
	return ((BOOL(__thiscall *)(CVehicle *, unsigned short))SAMP_ADDROF(0xB1A70))(this, nId);
}

BOOL SAMP::classes::CVehicle::RemoveComponent(unsigned short nId) {
	return ((BOOL(__thiscall *)(CVehicle *, unsigned short))SAMP_ADDROF(0xB1B50))(this, nId);
}

void SAMP::classes::CVehicle::SetPaintjob(NUMBER nId) {
	((void(__thiscall *)(CVehicle *, NUMBER))SAMP_ADDROF(0xB1B90))(this, nId);
}

BOOL SAMP::classes::CVehicle::DoesExist() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1BE0))(this);
}

BOOL SAMP::classes::CVehicle::HasSiren() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1DD0))(this);
}

char SAMP::classes::CVehicle::GetMaxPassengers() {
	return ((char(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB1DE0))(this);
}

void SAMP::classes::CVehicle::SetWindowOpenFlag(NUMBER nDoorId) {
	((void(__thiscall *)(CVehicle *, NUMBER))SAMP_ADDROF(0xB1E10))(this, nDoorId);
}

void SAMP::classes::CVehicle::ClearWindowOpenFlag(NUMBER nDoorId) {
	((void(__thiscall *)(CVehicle *, NUMBER))SAMP_ADDROF(0xB1E40))(this, nDoorId);
}

void SAMP::classes::CVehicle::EnableEngine(BOOL bEnable) {
	((void(__thiscall *)(CVehicle *, BOOL))SAMP_ADDROF(0xB2510))(this, bEnable);
}

#endif