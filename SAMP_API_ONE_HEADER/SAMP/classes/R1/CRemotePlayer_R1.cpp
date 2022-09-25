/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "CRemotePlayer_R1.h"

SAMP::classes::CRemotePlayer::CRemotePlayer() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x12E20))(this);
}

SAMP::classes::CRemotePlayer::~CRemotePlayer() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x12EA0))(this);
}

void SAMP::classes::CRemotePlayer::Process() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x12EF0))(this);
}

void SAMP::classes::CRemotePlayer::ProcessHead() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x10EA0))(this);
}

void SAMP::classes::CRemotePlayer::SetMarkerState(BOOL bState) {
	((void(__thiscall *)(CRemotePlayer *, BOOL))SAMP_ADDROF(0x10FF0))(this, bState);
}

void SAMP::classes::CRemotePlayer::SetMarkerPosition(int x, int y, int z) {
	((void(__thiscall *)(CRemotePlayer *, int, int, int))SAMP_ADDROF(0x11030))(this, x, y, z);
}

BOOL SAMP::classes::CRemotePlayer::Surfing() {
	return ((BOOL(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x110D0))(this);
}

BOOL SAMP::classes::CRemotePlayer::SurfingOnObject() {
	return ((BOOL(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x11100))(this);
}

void SAMP::classes::CRemotePlayer::ProcessSurfing() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x11130))(this);
}

void SAMP::classes::CRemotePlayer::OnEnterVehicle() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x112D0))(this);
}

void SAMP::classes::CRemotePlayer::OnExitVehicle() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x113A0))(this);
}

void SAMP::classes::CRemotePlayer::ProcessSpecialAction() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x113F0))(this);
}

void SAMP::classes::CRemotePlayer::Update(PACKET::AimData *pData) {
	((void(__thiscall *)(CRemotePlayer *, PACKET::AimData *))SAMP_ADDROF(0x12080))(this, pData);
}

void SAMP::classes::CRemotePlayer::Update(PACKET::UnoccupiedData *pData) {
	((void(__thiscall *)(CRemotePlayer *, PACKET::UnoccupiedData *))SAMP_ADDROF(0x121D0))(this, pData);
}

void SAMP::classes::CRemotePlayer::Update(PACKET::TrailerData *pData) {
	((void(__thiscall *)(CRemotePlayer *, PACKET::TrailerData *))SAMP_ADDROF(0x12520))(this, pData);
}

void SAMP::classes::CRemotePlayer::ResetData() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x12830))(this);
}

float SAMP::classes::CRemotePlayer::GetDistanceToPlayer(CRemotePlayer *pPlayer) {
	return ((float(__thiscall *)(CRemotePlayer *, CRemotePlayer *))SAMP_ADDROF(0x12930))(this, pPlayer);
}

void SAMP::classes::CRemotePlayer::ChangeState(char nOldState, char nNewState) {
	((void(__thiscall *)(CRemotePlayer *, char, char))SAMP_ADDROF(0x12AE0))(this, nOldState, nNewState);
}

int SAMP::classes::CRemotePlayer::GetStatus() {
	return ((int(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x12BA0))(this);
}

BOOL SAMP::classes::CRemotePlayer::Spawn(int a2, int nModel, CVector *pPosition, float fRotation, D3DCOLOR color, char nFightingStyle) {
	return ((BOOL(__thiscall *)(CRemotePlayer *, int, int, CVector *, float, D3DCOLOR, char))SAMP_ADDROF(0x13890))(this, a2, nModel, pPosition, fRotation, color, nFightingStyle);
}

void SAMP::classes::CRemotePlayer::Update(PACKET::OnfootData *pData, TICK timestamp) {
	((void(__thiscall *)(CRemotePlayer *, PACKET::OnfootData *, TICK))SAMP_ADDROF(0x139A0))(this, pData, timestamp);
}

void SAMP::classes::CRemotePlayer::Update(PACKET::IncarData *pData, TICK timestamp) {
	((void(__thiscall *)(CRemotePlayer *, PACKET::IncarData *, TICK))SAMP_ADDROF(0x13A80))(this, pData, timestamp);
}

void SAMP::classes::CRemotePlayer::Update(PACKET::PassengerData *pData, TICK timestamp) {
	((void(__thiscall *)(CRemotePlayer *, PACKET::PassengerData *, TICK))SAMP_ADDROF(0x13B70))(this, pData, timestamp);
}

void SAMP::classes::CRemotePlayer::Remove() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x13C60))(this);
}

void SAMP::classes::CRemotePlayer::Kill() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x13CA0))(this);
}

void SAMP::classes::CRemotePlayer::Chat(const char *szText) {
	((void(__thiscall *)(CRemotePlayer *, const char *))SAMP_ADDROF(0x13D30))(this, szText);
}

float SAMP::classes::CRemotePlayer::GetDistanceToLocalPlayer() {
	return ((float(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x129A0))(this);
}

void SAMP::classes::CRemotePlayer::ExitVehicle() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x12AB0))(this);
}

void SAMP::classes::CRemotePlayer::EnterVehicle(ID nVehicle, BOOL bPassenger) {
	((void(__thiscall *)(CRemotePlayer *, ID, BOOL))SAMP_ADDROF(0x12A20))(this, nVehicle, bPassenger);
}

D3DCOLOR SAMP::classes::CRemotePlayer::GetColorAsARGB() {
	return ((D3DCOLOR(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x12A00))(this);
}

D3DCOLOR SAMP::classes::CRemotePlayer::GetColorAsRGBA() {
	return ((D3DCOLOR(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x129F0))(this);
}

void SAMP::classes::CRemotePlayer::SetColor(D3DCOLOR color) {
	((void(__thiscall *)(CRemotePlayer *, D3DCOLOR))SAMP_ADDROF(0x129D0))(this, color);
}

void SAMP::classes::CRemotePlayer::SetOnfootTargetSpeedAndPosition(CVector *pPosition, CVector *pSpeed) {
	((void(__thiscall *)(CRemotePlayer *, CVector *, CVector *))SAMP_ADDROF(0x11A60))(this, pPosition, pSpeed);
}

void SAMP::classes::CRemotePlayer::Update(PACKET::BulletData *pData) {
	((void(__thiscall *)(CRemotePlayer *, PACKET::BulletData *))SAMP_ADDROF(0x12BE0))(this, pData);
}

BOOL SAMP::classes::CRemotePlayer::DoesExist() {
	return ((BOOL(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x1080))(this);
}

void SAMP::classes::CRemotePlayer::UpdateOnfootRotation() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x11990))(this);
}

void SAMP::classes::CRemotePlayer::UpdateOnfootSpeedAndPosition() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x11840))(this);
}

void SAMP::classes::CRemotePlayer::UpdateIncarSpeedAndPosition() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x11AC0))(this);
}

void SAMP::classes::CRemotePlayer::UpdateIncarRotation() {
	((void(__thiscall *)(CRemotePlayer *))SAMP_ADDROF(0x11DA0))(this);
}

void SAMP::classes::CRemotePlayer::SetIncarTargetSpeedAndPosition(CMatrix *pMatrix, CVector *pPosition, CVector *pSpeed) {
	((void(__thiscall *)(CRemotePlayer *, CMatrix *, CVector *, CVector *))SAMP_ADDROF(0x11F10))(this, pMatrix, pPosition, pSpeed);
}

void SAMP::classes::CRemotePlayer::UpdateTrain(CMatrix *pMatrix, CVector *pSpeed, float fSpeed) {
	((void(__thiscall *)(CRemotePlayer *, CMatrix *, CVector *, float))SAMP_ADDROF(0x11F80))(this, pMatrix, pSpeed, fSpeed);
}

#endif