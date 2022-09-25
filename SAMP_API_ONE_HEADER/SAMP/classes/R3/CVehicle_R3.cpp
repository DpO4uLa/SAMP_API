/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CVehicle_R3.h"

SAMP::classes::CVehicle::CVehicle(int nModel, CVector position, float fRotation, BOOL bKeepModelLoaded, BOOL bHasSiren) {
	((void(__thiscall *)(CVehicle *, int, CVector, float, BOOL, BOOL))SAMP_ADDROF(0xB7B30))(this, nModel, position, fRotation, bKeepModelLoaded, bHasSiren);
}

void SAMP::classes::CVehicle::ChangeInterior(int nId) {
	((void(__thiscall *)(CVehicle *, int))SAMP_ADDROF(0xB6800))(this, nId);
}

void SAMP::classes::CVehicle::ResetPointers() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6830))(this);
}

BOOL SAMP::classes::CVehicle::HasDriver() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6850))(this);
}

BOOL SAMP::classes::CVehicle::IsOccupied() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB68A0))(this);
}

void SAMP::classes::CVehicle::SetInvulnerable(BOOL bInv) {
	((void(__thiscall *)(CVehicle *, BOOL))SAMP_ADDROF(0xB6900))(this, bInv);
}

void SAMP::classes::CVehicle::SetLocked(BOOL bLock) {
	((void(__thiscall *)(CVehicle *, BOOL))SAMP_ADDROF(0xB69A0))(this, bLock);
}

float SAMP::classes::CVehicle::GetHealth() {
	return ((float(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6A10))(this);
}

void SAMP::classes::CVehicle::SetHealth(float fValue) {
	((void(__thiscall *)(CVehicle *, float))SAMP_ADDROF(0xB6A30))(this, fValue);
}

void SAMP::classes::CVehicle::SetColor(NUMBER nPrimary, NUMBER nSecondary) {
	((void(__thiscall *)(CVehicle *, NUMBER, NUMBER))SAMP_ADDROF(0xB6A50))(this, nPrimary, nSecondary);
}

void SAMP::classes::CVehicle::UpdateColor() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6AA0))(this);
}

int SAMP::classes::CVehicle::GetSubtype() {
	return ((int(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6B00))(this);
}

BOOL SAMP::classes::CVehicle::IsSunk() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6B20))(this);
}

BOOL SAMP::classes::CVehicle::IsWrecked() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6B40))(this);
}

BOOL SAMP::classes::CVehicle::DriverIsPlayerPed() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6B60))(this);
}

BOOL SAMP::classes::CVehicle::HasPlayerPed() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6B90))(this);
}

BOOL SAMP::classes::CVehicle::IsTrainPart() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6BD0))(this);
}

BOOL SAMP::classes::CVehicle::HasTurret() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6C10))(this);
}

void SAMP::classes::CVehicle::EnableSiren(bool bEnable) {
	((void(__thiscall *)(CVehicle *, bool))SAMP_ADDROF(0xB6CB0))(this, bEnable);
}

BOOL SAMP::classes::CVehicle::SirenEnabled() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6CD0))(this);
}

void SAMP::classes::CVehicle::SetLandingGearState(BOOL bHide) {
	((void(__thiscall *)(CVehicle *, BOOL))SAMP_ADDROF(0xB6D10))(this, bHide);
}

BOOL SAMP::classes::CVehicle::GetLandingGearState() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6DA0))(this);
}

void SAMP::classes::CVehicle::SetHydraThrusters(int nDirection) {
	((void(__thiscall *)(CVehicle *, int))SAMP_ADDROF(0xB6E10))(this, nDirection);
}

int SAMP::classes::CVehicle::GetHydraThrusters() {
	return ((int(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6E30))(this);
}

void SAMP::classes::CVehicle::ProcessMarkers() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6E50))(this);
}

void SAMP::classes::CVehicle::Lock(BOOL bLock) {
	((void(__thiscall *)(CVehicle *, BOOL))SAMP_ADDROF(0xB6FB0))(this, bLock);
}

BOOL SAMP::classes::CVehicle::UpdateLastDrivenTime() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB6FE0))(this);
}

float SAMP::classes::CVehicle::GetTrainSpeed() {
	return ((float(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7050))(this);
}

void SAMP::classes::CVehicle::SetTrainSpeed(float fValue) {
	((void(__thiscall *)(CVehicle *, float))SAMP_ADDROF(0xB7070))(this, fValue);
}

void SAMP::classes::CVehicle::SetTires(char nState) {
	((void(__thiscall *)(CVehicle *, char))SAMP_ADDROF(0xB70B0))(this, nState);
}

char SAMP::classes::CVehicle::GetTires() {
	return ((char(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB71A0))(this);
}

void SAMP::classes::CVehicle::UpdateDamage(int nPanels, int nDoors, char nLights) {
	((void(__thiscall *)(CVehicle *, int, int, char))SAMP_ADDROF(0xB7230))(this, nPanels, nDoors, nLights);
}

int SAMP::classes::CVehicle::GetPanelsDamage() {
	return ((int(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB72F0))(this);
}

int SAMP::classes::CVehicle::GetDoorsDamage() {
	return ((int(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7320))(this);
}

char SAMP::classes::CVehicle::GetLightsDamage() {
	return ((char(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7350))(this);
}

void SAMP::classes::CVehicle::AttachTrailer() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7380))(this);
}

void SAMP::classes::CVehicle::DetachTrailer() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB73A0))(this);
}

void SAMP::classes::CVehicle::SetTrailer(CVehicle *pVehicle) {
	((void(__thiscall *)(CVehicle *, CVehicle *))SAMP_ADDROF(0xB73F0))(this, pVehicle);
}

SAMP::classes::CVehicle *SAMP::classes::CVehicle::GetTrailer() {
	return ((CVehicle *(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7400))(this);
}

SAMP::classes::CVehicle *SAMP::classes::CVehicle::GetTractor() {
	return ((CVehicle *(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7460))(this);
}

BOOL SAMP::classes::CVehicle::IsTrailer() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB74E0))(this);
}

BOOL SAMP::classes::CVehicle::IsTowtruck() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7540))(this);
}

BOOL SAMP::classes::CVehicle::IsRC() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7570))(this);
}

void SAMP::classes::CVehicle::EnableLights(bool bEnable) {
	((void(__thiscall *)(CVehicle *, bool))SAMP_ADDROF(0xB75C0))(this, bEnable);
}

void SAMP::classes::CVehicle::RemovePassengers() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7650))(this);
}

BOOL SAMP::classes::CVehicle::AddComponent(unsigned short nId) {
	return ((BOOL(__thiscall *)(CVehicle *, unsigned short))SAMP_ADDROF(0xB7730))(this, nId);
}

BOOL SAMP::classes::CVehicle::RemoveComponent(unsigned short nId) {
	return ((BOOL(__thiscall *)(CVehicle *, unsigned short))SAMP_ADDROF(0xB7810))(this, nId);
}

void SAMP::classes::CVehicle::SetPaintjob(NUMBER nId) {
	((void(__thiscall *)(CVehicle *, NUMBER))SAMP_ADDROF(0xB7850))(this, nId);
}

BOOL SAMP::classes::CVehicle::DoesExist() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB78A0))(this);
}

void SAMP::classes::CVehicle::SetLicensePlateText(const char *szText) {
	((void(__thiscall *)(CVehicle *, const char *))SAMP_ADDROF(0xB78B0))(this, szText);
}

void SAMP::classes::CVehicle::SetRotation(float fValue) {
	((void(__thiscall *)(CVehicle *, float))SAMP_ADDROF(0xB78D0))(this, fValue);
}

void SAMP::classes::CVehicle::ConstructLicensePlate() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7900))(this);
}

void SAMP::classes::CVehicle::ShutdownLicensePlate() {
	((void(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7950))(this);
}

BOOL SAMP::classes::CVehicle::HasSiren() {
	return ((BOOL(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7A90))(this);
}

char SAMP::classes::CVehicle::GetMaxPassengers() {
	return ((char(__thiscall *)(CVehicle *))SAMP_ADDROF(0xB7AA0))(this);
}

void SAMP::classes::CVehicle::SetWindowOpenFlag(NUMBER nDoorId) {
	((void(__thiscall *)(CVehicle *, NUMBER))SAMP_ADDROF(0xB7AD0))(this, nDoorId);
}

void SAMP::classes::CVehicle::ClearWindowOpenFlag(NUMBER nDoorId) {
	((void(__thiscall *)(CVehicle *, NUMBER))SAMP_ADDROF(0xB7B00))(this, nDoorId);
}

void SAMP::classes::CVehicle::EnableEngine(BOOL bEnable) {
	((void(__thiscall *)(CVehicle *, BOOL))SAMP_ADDROF(0xB81D0))(this, bEnable);
}

#endif