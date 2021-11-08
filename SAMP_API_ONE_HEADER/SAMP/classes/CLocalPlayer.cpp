/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "CLocalPlayer.h"

unsigned long &SAMP::classes::CLocalPlayer::dwTimeElapsedFromFPressed = *(unsigned long *)SAMP_ADDROF(0xEC0A4);
int &SAMP::classes::CLocalPlayer::nIncarSendrate = *(int *)SAMP_ADDROF(0xEC0AC);
int &SAMP::classes::CLocalPlayer::nOnfootSendrate = *(int *)SAMP_ADDROF(0xEC0A8);
int &SAMP::classes::CLocalPlayer::nFiringSendrate = *(int *)SAMP_ADDROF(0xEC0B0);
int &SAMP::classes::CLocalPlayer::nSendMultiplier = *(int *)SAMP_ADDROF(0xEC0B4);
bool &SAMP::classes::CLocalPlayer::bDrawCameraTargetLabel = *(bool *)SAMP_ADDROF(0x104908);

SAMP::classes::CLocalPlayer::CLocalPlayer() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x4A50))(this);
}

void SAMP::classes::CLocalPlayer::ResetData() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x2E80))(this);
}

void SAMP::classes::CLocalPlayer::ProcessHead() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x2F80))(this);
}

void SAMP::classes::CLocalPlayer::SetSpecialAction(char nAction) {
	((void(__thiscall *)(CLocalPlayer *, char))SAMP_ADDROF(0x30C0))(this, nAction);
}

char SAMP::classes::CLocalPlayer::GetSpecialAction() {
	return ((char(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x3340))(this);
}

void SAMP::classes::CLocalPlayer::SetSpawnInfo(const SpawnInfo *pInfo) {
	((void(__thiscall *)(CLocalPlayer *, const SpawnInfo *))SAMP_ADDROF(0x3AA0))(this, pInfo);
}

BOOL SAMP::classes::CLocalPlayer::Spawn() {
	return ((BOOL(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x3AD0))(this);
}

void SAMP::classes::CLocalPlayer::SetColor(D3DCOLOR dwColor) {
	((void(__thiscall *)(CLocalPlayer *, D3DCOLOR))SAMP_ADDROF(0x3D40))(this, dwColor);
}

D3DCOLOR SAMP::classes::CLocalPlayer::GetColorAsARGB() {
	return ((D3DCOLOR(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x3D90))(this);
}

void SAMP::classes::CLocalPlayer::ProcessOnfootWorldBounds() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x3DC0))(this);
}

void SAMP::classes::CLocalPlayer::ProcessIncarWorldBounds() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x3E20))(this);
}

void SAMP::classes::CLocalPlayer::RequestSpawn() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x3EC0))(this);
}

void SAMP::classes::CLocalPlayer::PrepareForClassSelection() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x3EE0))(this);
}

void SAMP::classes::CLocalPlayer::PrepareForClassSelection_Outcome(BOOL bOutcome) {
	((void(__thiscall *)(CLocalPlayer *, BOOL))SAMP_ADDROF(0x3F30))(this, bOutcome);
}

void SAMP::classes::CLocalPlayer::EnableSpectating(BOOL bEnable) {
	((void(__thiscall *)(CLocalPlayer *, BOOL))SAMP_ADDROF(0x4000))(this, bEnable);
}

void SAMP::classes::CLocalPlayer::SpectateForVehicle(ID nVehicle) {
	((void(__thiscall *)(CLocalPlayer *, ID))SAMP_ADDROF(0x4060))(this, nVehicle);
}

void SAMP::classes::CLocalPlayer::SpectateForPlayer(ID nPlayer) {
	((void(__thiscall *)(CLocalPlayer *, ID))SAMP_ADDROF(0x40B0))(this, nPlayer);
}

void SAMP::classes::CLocalPlayer::SendUnoccupiedData(ID nVehicle, char arg4) {
	((void(__thiscall *)(CLocalPlayer *, ID, int))SAMP_ADDROF(0x4B30))(this, nVehicle, arg4);
}

void SAMP::classes::CLocalPlayer::SendAimData() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x4FF0))(this);
}

void SAMP::classes::CLocalPlayer::WastedNotification() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x55E0))(this);
}

void SAMP::classes::CLocalPlayer::RequestClass(int nClass) {
	((void(__thiscall *)(CLocalPlayer *, int))SAMP_ADDROF(0x56A0))(this, nClass);
}

void SAMP::classes::CLocalPlayer::ChangeInterior(char nId) {
	((void(__thiscall *)(CLocalPlayer *, char))SAMP_ADDROF(0x5740))(this, nId);
}

void SAMP::classes::CLocalPlayer::Chat(const char *szText) {
	((void(__thiscall *)(CLocalPlayer *, const char *))SAMP_ADDROF(0x57F0))(this, szText);
}

void SAMP::classes::CLocalPlayer::EnterVehicle(int nVehicle, BOOL bPassenger) {
	((void(__thiscall *)(CLocalPlayer *, int, BOOL))SAMP_ADDROF(0x58C0))(this, nVehicle, bPassenger);
}

void SAMP::classes::CLocalPlayer::ExitVehicle(int nVehicle) {
	((void(__thiscall *)(CLocalPlayer *, int))SAMP_ADDROF(0x59E0))(this, nVehicle);
}

void SAMP::classes::CLocalPlayer::SendStats() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x5AF0))(this);
}

void SAMP::classes::CLocalPlayer::UpdateVehicleDamage(ID nVehicle) {
	((void(__thiscall *)(CLocalPlayer *, ID))SAMP_ADDROF(0x5BD0))(this, nVehicle);
}

void SAMP::classes::CLocalPlayer::NextClass() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x5DE0))(this);
}

void SAMP::classes::CLocalPlayer::PrevClass() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x5E70))(this);
}

void SAMP::classes::CLocalPlayer::UpdateWeapons() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x6080))(this);
}

void SAMP::classes::CLocalPlayer::EnterVehicleAsPassenger() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x6D90))(this);
}

void SAMP::classes::CLocalPlayer::SendIncarData() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x6E30))(this);
}

void SAMP::classes::CLocalPlayer::Process() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x7280))(this);
}

void SAMP::classes::CLocalPlayer::EndSurfing() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0xB630))(this);
}

void SAMP::classes::CLocalPlayer::SendOnfootData() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x4D10))(this);
}

void SAMP::classes::CLocalPlayer::SendTrailerData(ID nTrailer) {
	((void(__thiscall *)(CLocalPlayer *, ID))SAMP_ADDROF(0x51B0))(this, nTrailer);
}

void SAMP::classes::CLocalPlayer::SendPassengerData() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x5380))(this);
}

void SAMP::classes::CLocalPlayer::SendSpawnRequest() {
	((void(__cdecl *)())SAMP_ADDROF(0x3A20))();
}

int SAMP::classes::CLocalPlayer::GetIncarSendRate() {
	return ((int(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x3970))(this);
}

int SAMP::classes::CLocalPlayer::GetOnfootSendRate() {
	return ((int(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x39B0))(this);
}

int SAMP::classes::CLocalPlayer::GetUnoccupiedSendRate() {
	return ((int(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x39F0))(this);
}

SAMP::classes::CPed *SAMP::classes::CLocalPlayer::GetPed() {
	return ((CPed *(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x2D60))(this);
}

D3DCOLOR SAMP::classes::CLocalPlayer::GetColorAsRGBA() {
	return ((D3DCOLOR(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x3D70))(this);
}

void SAMP::classes::CLocalPlayer::DrawCameraTargetLabel() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x4670))(this);
}

void SAMP::classes::CLocalPlayer::ProcessSpectating() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x6310))(this);
}

void SAMP::classes::CLocalPlayer::SendGiveDamage(int nId, float fDamage, int nWeapon, int nBodyPart) {
	((void(__thiscall *)(CLocalPlayer *, int, float, int, int))SAMP_ADDROF(0x6770))(this, nId, fDamage, nWeapon, nBodyPart);
}

void SAMP::classes::CLocalPlayer::SendTakeDamage(int nId, float fDamage, int nWeapon, int nBodyPart) {
	((void(__thiscall *)(CLocalPlayer *, int, float, int, int))SAMP_ADDROF(0x6660))(this, nId, fDamage, nWeapon, nBodyPart);
}

void SAMP::classes::CLocalPlayer::UpdateSurfing() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x3460))(this);
}

BOOL SAMP::classes::CLocalPlayer::NeedsToUpdate(const void *pOld, const void *pNew, unsigned int nLen) {
	return ((BOOL(__thiscall *)(CLocalPlayer *, const void *, const void *, unsigned int))SAMP_ADDROF(0x3920))(this, pOld, pNew, nLen);
}

void SAMP::classes::CLocalPlayer::SetSurfing(CVehicle *pVehicle, BOOL bStuck) {
	((void(__thiscall *)(CLocalPlayer *, CVehicle *, BOOL))SAMP_ADDROF(0x35E0))(this, pVehicle, bStuck);
}

void SAMP::classes::CLocalPlayer::ProcessSurfing() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x3600))(this);
}

void SAMP::classes::CLocalPlayer::ProcessClassSelection() {
	((void(__thiscall *)(CLocalPlayer *))SAMP_ADDROF(0x5EF0))(this);
}

BOOL SAMP::classes::CLocalPlayer::NeedsToSendOnfootData(short controllerState, short sLeftStickX, short sLeftStickY) {
	return ((BOOL(__thiscall *)(CLocalPlayer *, short, short, short))SAMP_ADDROF(0x4120))(this, controllerState, sLeftStickX, sLeftStickY);
}

BOOL SAMP::classes::CLocalPlayer::NeedsToSendIncarData(short controllerState, short sLeftStickX, short sLeftStickY) {
	return ((BOOL(__thiscall *)(CLocalPlayer *, short, short, short))SAMP_ADDROF(0x4150))(this, controllerState, sLeftStickX, sLeftStickY);
}

bool SAMP::classes::CLocalPlayer::DefineCameraTarget(CameraTarget *pInfo) {
	return ((bool(__thiscall *)(CLocalPlayer *, CameraTarget *))SAMP_ADDROF(0x4260))(this, pInfo);
}

bool SAMP::classes::CLocalPlayer::ProcessUnoccupiedSync(ID nVehicle, CVehicle *pVehicle) {
	return ((bool(__thiscall *)(CLocalPlayer *, ID, CVehicle *))SAMP_ADDROF(0x6BC0))(this, nVehicle, pVehicle);
}