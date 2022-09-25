/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "CNetGame_R3.h"

SAMP::classes::CNetGame *&SAMP::classes::pNetGame = *(SAMP::classes::CNetGame **)SAMP_ADDROF(0x26E8DC);
TICK &SAMP::classes::CNetGame::lastPlayersUpdateRequest = *(TICK *)SAMP_ADDROF(0x1189F0);

SAMP::classes::CNetGame::CNetGame(const char *szHostAddress, int nPort, const char *szNick, const char *szPass) {
	((void(__thiscall *)(CNetGame *, const char *, int, const char *, const char *))SAMP_ADDROF(0xB5F0))(this, szHostAddress, nPort, szNick, szPass);
}

SAMP::classes::CNetGame::~CNetGame() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x9510))(this);
}

SAMP::classes::CPickupPool *SAMP::classes::CNetGame::GetPickupPool() {
	return ((CPickupPool *(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8170))(this);
}

SAMP::classes::CMenuPool *SAMP::classes::CNetGame::GetMenuPool() {
	return ((CMenuPool *(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8180))(this);
}

void SAMP::classes::CNetGame::SetState(int nValue) {
	((void(__thiscall *)(CNetGame *, int))SAMP_ADDROF(0x8190))(this, nValue);
}

void SAMP::classes::CNetGame::InitializePools() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x81D0))(this);
}

void SAMP::classes::CNetGame::InitialNotification() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x83F0))(this);
}

void SAMP::classes::CNetGame::InitializeGameLogic() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8580))(this);
}

void SAMP::classes::CNetGame::Connect() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x85D0))(this);
}

void SAMP::classes::CNetGame::SpawnScreen() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8640))(this);
}

void SAMP::classes::CNetGame::Packet_RSAPublicKeyMismatch(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x89E0))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_ConnectionBanned(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x8A00))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_ConnectionRequestAcepted(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x8A20))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_NoFreeIncomingConnections(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x8A40))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_DisconnectionNotification(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x8A70))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_InvalidPassword(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x8AB0))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_ConnectionAttemptFailed(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x8AF0))(this, pPacket);
}

void SAMP::classes::CNetGame::UpdatePlayers() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8BA0))(this);
}

void SAMP::classes::CNetGame::DeleteMarker(NUMBER nIndex) {
	((void(__thiscall *)(CNetGame *, NUMBER))SAMP_ADDROF(0x8C40))(this, nIndex);
}

void SAMP::classes::CNetGame::ResetPlayerPool() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8C70))(this);
}

void SAMP::classes::CNetGame::ResetVehiclePool() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8D10))(this);
}

void SAMP::classes::CNetGame::ResetTextDrawPool() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8DB0))(this);
}

void SAMP::classes::CNetGame::ResetObjectPool() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8E50))(this);
}

void SAMP::classes::CNetGame::ResetGangZonePool() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8EF0))(this);
}

void SAMP::classes::CNetGame::ResetPickupPool() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8F90))(this);
}

void SAMP::classes::CNetGame::ResetMenuPool() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8FF0))(this);
}

void SAMP::classes::CNetGame::ResetLabelPool() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x9080))(this);
}

void SAMP::classes::CNetGame::ResetActorPool() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x9120))(this);
}

void SAMP::classes::CNetGame::Packet_UnoccupiedSync(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x96D0))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_BulletSync(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x97D0))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_AimSync(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x98D0))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_PassengerSync(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x99C0))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_TrailerSync(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x9AB0))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_MarkersSync(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x9BA0))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_AuthKey(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0x9D90))(this, pPacket);
}

void SAMP::classes::CNetGame::ResetMarkers() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x9F50))(this);
}

void SAMP::classes::CNetGame::CreateMarker(NUMBER nIndex, CVector position, char nIcon, int nColor, int nType) {
	((void(__thiscall *)(CNetGame *, NUMBER, CVector, char, int, int))SAMP_ADDROF(0x9F90))(this, nIndex, position, nIcon, nColor, nType);
}

void SAMP::classes::CNetGame::ResetPools() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0xA190))(this);
}

void SAMP::classes::CNetGame::ShutdownForRestart() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0xA1E0))(this);
}

void SAMP::classes::CNetGame::Packet_PlayerSync(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0xA3E0))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_VehicleSync(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0xA6B0))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_ConnectionLost(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0xA990))(this, pPacket);
}

void SAMP::classes::CNetGame::Packet_ConnectionSucceeded(Packet *pPacket) {
	((void(__thiscall *)(CNetGame *, Packet *))SAMP_ADDROF(0xAA20))(this, pPacket);
}

void SAMP::classes::CNetGame::UpdateNetwork() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0xAF20))(this);
}

void SAMP::classes::CNetGame::Process() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0xB270))(this);
}

void SAMP::classes::CNetGame::ProcessGameStuff() {
	((void(__thiscall *)(CNetGame *))SAMP_ADDROF(0x87B0))(this);
}

SAMP::classes::CPlayerPool *SAMP::classes::CNetGame::GetPlayerPool() {
	return ((CPlayerPool *(__thiscall *)(CNetGame *))SAMP_ADDROF(0x1160))(this);
}

SAMP::classes::CObjectPool *SAMP::classes::CNetGame::GetObjectPool() {
	return ((CObjectPool *(__thiscall *)(CNetGame *))SAMP_ADDROF(0x2DF0))(this);
}

SAMP::classes::CActorPool *SAMP::classes::CNetGame::GetActorPool() {
	return ((CActorPool *(__thiscall *)(CNetGame *))SAMP_ADDROF(0x2E00))(this);
}

int SAMP::classes::CNetGame::GetState() {
	return ((int(__thiscall *)(CNetGame *))SAMP_ADDROF(0x2E10))(this);
}

BOOL SAMP::classes::CNetGame::LanMode() {
	return ((BOOL(__thiscall *)(CNetGame *))SAMP_ADDROF(0x2E20))(this);
}

SAMP::classes::CVehiclePool *SAMP::classes::CNetGame::GetVehiclePool() {
	return ((CVehiclePool *(__thiscall *)(CNetGame *))SAMP_ADDROF(0x1170))(this);
}

SAMP::classes::RakClientInterface *SAMP::classes::CNetGame::GetRakClient() {
	return ((RakClientInterface *(__thiscall *)(CNetGame *))SAMP_ADDROF(0x1A40))(this);
}

__int64 SAMP::classes::CNetGame::GetCounter() {
	return ((__int64(__thiscall *)(CNetGame *))SAMP_ADDROF(0x8570))(this);
}

#endif