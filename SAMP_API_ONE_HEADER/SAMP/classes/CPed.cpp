/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#include "CPed.h"

SAMP::classes::CPed::CPed() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA6330))(this);
}

SAMP::classes::CPed::CPed(unsigned char nPlayerNumber, int nModel, CVector position, float fRotation) {
	((void(__thiscall *)(CPed *, unsigned char, int, CVector, float))SAMP_ADDROF(0xAB580))(this, nPlayerNumber, nModel, position, fRotation);
}

void SAMP::classes::CPed::ResetPointers() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA6470))(this);
}

void SAMP::classes::CPed::SetInitialState() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA6490))(this);
}

SAMP::classes::AimStuff::Aim *SAMP::classes::CPed::GetAim() {
	return ((AimStuff::Aim *(__thiscall *)(CPed *))SAMP_ADDROF(0xA64E0))(this);
}

void SAMP::classes::CPed::SetAim(const AimStuff::Aim *pAim) {
	((void(__thiscall *)(CPed *, const AimStuff::Aim *))SAMP_ADDROF(0xA64F0))(this, pAim);
}

char SAMP::classes::CPed::GetCurrentWeapon() {
	return ((char(__thiscall *)(CPed *))SAMP_ADDROF(0xA6510))(this);
}

SAMP::classes::GTAREF SAMP::classes::CPed::GetVehicleRef() {
	return ((GTAREF(__thiscall *)(CPed *))SAMP_ADDROF(0xA6550))(this);
}

void SAMP::classes::CPed::DeleteArrow() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA6570))(this);
}

BOOL SAMP::classes::CPed::IsOnScreen() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA65A0))(this);
}

void SAMP::classes::CPed::SetImmunities(int BP, int FP, int EP, int CP, int MP) {
	((void(__thiscall *)(CPed *, int, int, int, int, int))SAMP_ADDROF(0xA65C0))(this, BP, FP, EP, CP, MP);
}

float SAMP::classes::CPed::GetHealth() {
	return ((float(__thiscall *)(CPed *))SAMP_ADDROF(0xA6610))(this);
}

void SAMP::classes::CPed::SetHealth(float fValue) {
	((void(__thiscall *)(CPed *, float))SAMP_ADDROF(0xA6630))(this, fValue);
}

float SAMP::classes::CPed::GetArmour() {
	return ((float(__thiscall *)(CPed *))SAMP_ADDROF(0xA6650))(this);
}

void SAMP::classes::CPed::SetArmour(float fValue) {
	((void(__thiscall *)(CPed *, float))SAMP_ADDROF(0xA6670))(this, fValue);
}

int SAMP::classes::CPed::GetFlags() {
	return ((int(__thiscall *)(CPed *))SAMP_ADDROF(0xA6690))(this);
}

void SAMP::classes::CPed::SetFlags(int nValue) {
	((void(__thiscall *)(CPed *, int))SAMP_ADDROF(0xA66B0))(this, nValue);
}

BOOL SAMP::classes::CPed::IsDead() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA66D0))(this);
}

char SAMP::classes::CPed::GetState() {
	return ((char(__thiscall *)(CPed *))SAMP_ADDROF(0xA6700))(this);
}

void SAMP::classes::CPed::SetState(char nValue) {
	((void(__thiscall *)(CPed *, char))SAMP_ADDROF(0xA6710))(this, nValue);
}

void SAMP::classes::CPed::SetRotation(float fValue) {
	((void(__thiscall *)(CPed *, float))SAMP_ADDROF(0xA67D0))(this, fValue);
}

void SAMP::classes::CPed::ForceRotation(float fValue) {
	((void(__thiscall *)(CPed *, float))SAMP_ADDROF(0xA6820))(this, fValue);
}

BOOL SAMP::classes::CPed::IsPassenger() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA6880))(this);
}

CVehicle *SAMP::classes::CPed::GetVehicle() {
	return ((CVehicle *(__thiscall *)(CPed *))SAMP_ADDROF(0xA68C0))(this);
}

void SAMP::classes::CPed::ClearWeapons() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA68D0))(this);
}

void SAMP::classes::CPed::SetArmedWeapon(int nWeapon, bool bGameFunc) {
	((void(__thiscall *)(CPed *, int, bool))SAMP_ADDROF(0xA6920))(this, nWeapon, bGameFunc);
}

float SAMP::classes::CPed::GetDistanceToEntity(const CEntity *pEntity) {
	return ((float(__thiscall *)(CPed *, const CEntity *))SAMP_ADDROF(0xA6A60))(this, pEntity);
}

int SAMP::classes::CPed::GetVehicleSeatIndex() {
	return ((int(__thiscall *)(CPed *))SAMP_ADDROF(0xA6AC0))(this);
}

void SAMP::classes::CPed::PutIntoVehicle(GTAREF vehicle, int nSeat) {
	((void(__thiscall *)(CPed *, unsigned long, int))SAMP_ADDROF(0xA6B50))(this, vehicle, nSeat);
}

void SAMP::classes::CPed::EnterVehicle(GTAREF vehicle, BOOL bAsPassenger) {
	((void(__thiscall *)(CPed *, unsigned long, bool))SAMP_ADDROF(0xA6CD0))(this, vehicle, bAsPassenger);
}

void SAMP::classes::CPed::ExitVehicle() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA6DA0))(this);
}

void SAMP::classes::CPed::WarpFromVehicle(CVector putAt) {
	((void(__thiscall *)(CPed *, CVector))SAMP_ADDROF(0xA6E30))(this, putAt);
}

void SAMP::classes::CPed::SetSpawnInfo(const CVector *pPosition, float fRotation) {
	((void(__thiscall *)(CPed *, const CVector *, float))SAMP_ADDROF(0xA7010))(this, pPosition, fRotation);
}

void SAMP::classes::CPed::SetControllable(BOOL bEnable) {
	((void(__thiscall *)(CPed *, BOOL))SAMP_ADDROF(0xA7050))(this, bEnable);
}

char SAMP::classes::CPed::GetDeathInfo(ID *pKiller) {
	return ((unsigned char(__thiscall *)(CPed *, ID *))SAMP_ADDROF(0xA7110))(this, pKiller);
}

void SAMP::classes::CPed::HandsUp() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA73D0))(this);
}

BOOL SAMP::classes::CPed::DoesHandsUp() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA7420))(this);
}

void SAMP::classes::CPed::HoldObject(int nModel) {
	((void(__thiscall *)(CPed *, int))SAMP_ADDROF(0xA7480))(this, nModel);
}

void SAMP::classes::CPed::EnableJetpack() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA75D0))(this);
}

void SAMP::classes::CPed::DisableJetpack() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA7620))(this);
}

BOOL SAMP::classes::CPed::HasJetpack() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA7680))(this);
}

BOOL SAMP::classes::CPed::EnablePassengerDrivebyMode() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA7850))(this);
}

void SAMP::classes::CPed::Extinguish() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA79B0))(this);
}

void SAMP::classes::CPed::SetWalkStyle(const char *szName) {
	((void(__thiscall *)(CPed *, const char *))SAMP_ADDROF(0xA7A90))(this, szName);
}

void SAMP::classes::CPed::PerformAnimation(const char *szName, const char *szFile, float fFramedelta, int nLoopA, int nLockX, int nLockY, int nLockF, int nTime) {
	((void(__thiscall *)(CPed *, const char*, const char *, float, int, int, int, int, int))SAMP_ADDROF(0xA7AF0))(this, szName, szFile, fFramedelta, nLoopA, nLockX, nLockY, nLockF, nTime);
}

void SAMP::classes::CPed::LinkToInterior(char nId, BOOL bRefresh) {
	((void(__thiscall *)(CPed *, char, BOOL))SAMP_ADDROF(0xA7C00))(this, nId, bRefresh);
}

void SAMP::classes::CPed::DestroyParachute() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA7CA0))(this);
}

BOOL SAMP::classes::CPed::IsOnGround() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA8120))(this);
}

void SAMP::classes::CPed::ResetDamageEntity() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA8140))(this);
}

void SAMP::classes::CPed::RemoveWeaponModel(int nModel) {
	((void(__thiscall *)(CPed *, int))SAMP_ADDROF(0xA817C))(this, nModel);
}

float SAMP::classes::CPed::GetAimZ() {
	return ((float(__thiscall *)(CPed *))SAMP_ADDROF(0xA81B0))(this);
}

void SAMP::classes::CPed::SetAimZ(float fValue) {
	((void(__thiscall *)(CPed *, float))SAMP_ADDROF(0xA81F0))(this, fValue);
}

CEntity *SAMP::classes::CPed::GetContactEntity() {
	return ((::CEntity *(__thiscall *)(CPed *))SAMP_ADDROF(0xA8240))(this);
}

CVehicle *SAMP::classes::CPed::GetContactVehicle() {
	return ((::CVehicle *(__thiscall *)(CPed *))SAMP_ADDROF(0xA8250))(this);
}

int SAMP::classes::CPed::GetStat() {
	return ((int(__thiscall *)(CPed *))SAMP_ADDROF(0xA8260))(this);
}

BOOL SAMP::classes::CPed::PerformingCustomAnimation() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA82A0))(this);
}

void SAMP::classes::CPed::StartDancing(int nStyle) {
	((void(__thiscall *)(CPed *, int))SAMP_ADDROF(0xA8370))(this, nStyle);
}

void SAMP::classes::CPed::StopDancing() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA83C0))(this);
}

BOOL SAMP::classes::CPed::DoesDancing() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA8400))(this);
}

const char *SAMP::classes::CPed::GetAnimationForDance(int nMove) {
	return ((const char *(__thiscall *)(CPed *, int))SAMP_ADDROF(0xA8410))(this, nMove);
}

void SAMP::classes::CPed::DropStuff() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA84A0))(this);
}

void SAMP::classes::CPed::ProcessDrunk() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA8690))(this);
}

int SAMP::classes::CPed::GetDrunkLevel() {
	return ((int(__thiscall *)(CPed *))SAMP_ADDROF(0xA8840))(this);
}

void SAMP::classes::CPed::SetDrunkLevel(int nLevel) {
	((void(__thiscall *)(CPed *, int))SAMP_ADDROF(0xA8850))(this, nLevel);
}

void SAMP::classes::CPed::EnableCellphone(BOOL bEnable) {
	((void(__thiscall *)(CPed *, BOOL))SAMP_ADDROF(0xA8910))(this, bEnable);
}

BOOL SAMP::classes::CPed::UsingCellphone() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA8940))(this);
}

void SAMP::classes::CPed::SetFightingStyle(int nStyle) {
	((void(__thiscall *)(CPed *, int))SAMP_ADDROF(0xA8970))(this, nStyle);
}

void SAMP::classes::CPed::StartUrinating() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA89A0))(this);
}

void SAMP::classes::CPed::StopUrinating() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA8A80))(this);
}

BOOL SAMP::classes::CPed::DoesUrinating() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA8B00))(this);
}

void SAMP::classes::CPed::GetBonePosition(int nBone, CVector *pPosition) {
	((void(__thiscall *)(CPed *, int, CVector *))SAMP_ADDROF(0xA8D70))(this, nBone, pPosition);
}

void SAMP::classes::CPed::SetKeys(short controllerState, short sLeftStickX, short sLeftStickY) {
	((void(__thiscall *)(CPed *, short, short, short))SAMP_ADDROF(0xA9BE0))(this, controllerState, sLeftStickX, sLeftStickY);
}

void SAMP::classes::CPed::CreateArrow(int nColor) {
	((void(__thiscall *)(CPed *, int))SAMP_ADDROF(0xAA000))(this, nColor);
}

void SAMP::classes::CPed::GiveWeapon(int nWeapon, int nAmmo) {
	((void(__thiscall *)(CPed *, int, int))SAMP_ADDROF(0xAA060))(this, nWeapon, nAmmo);
}

void SAMP::classes::CPed::Kill() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xAA8A0))(this);
}

void SAMP::classes::CPed::GiveStuff(int nType) {
	((void(__thiscall *)(CPed *, int))SAMP_ADDROF(0xAABA0))(this, nType);
}

short SAMP::classes::CPed::GetKeys(short *pLeftStickX, short *pLeftStickY) {
	return ((short(__thiscall *)(CPed *, short *, short *))SAMP_ADDROF(0xA9E70))(this, pLeftStickX, pLeftStickY);
}

BOOL SAMP::classes::CPed::IsInVehicle() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA6730))(this);
}

void SAMP::classes::CPed::Destroy() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xAB840))(this);
}

void SAMP::classes::CPed::ApplyCommandTask(const char *szName, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) {
	((void(__thiscall *)(CPed *, const char *, int, int, int, int, int, int, int, int, int))SAMP_ADDROF(0xA8870))(this, szName, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

CWeapon *SAMP::classes::CPed::GetCurrentWeaponSlot() {
	return ((CWeapon *(__thiscall *)(CPed *))SAMP_ADDROF(0xA6A00))(this);
}

BOOL SAMP::classes::CPed::HasAccessory() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA96D0))(this);
}

void SAMP::classes::CPed::DeleteAccessory(int nSlot) {
	((void(__thiscall *)(CPed *, int))SAMP_ADDROF(0xA96F0))(this, nSlot);
}

BOOL SAMP::classes::CPed::GetAccessoryState(int nSlot) {
	return ((BOOL(__thiscall *)(CPed *, int))SAMP_ADDROF(0xA9750))(this, nSlot);
}

void SAMP::classes::CPed::DeleteAllAccessories() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xAB380))(this);
}

void SAMP::classes::CPed::AddAccessory(int nSlot, const Accessory *pInfo) {
	((void(__thiscall *)(CPed *, int, const Accessory *))SAMP_ADDROF(0xAB3E0))(this, nSlot, pInfo);
}

SAMP::classes::CObject *SAMP::classes::CPed::GetAccessory(int nSlot) {
	return ((CObject *(__thiscall *)(CPed *, int))SAMP_ADDROF(0x101E0))(this, nSlot);
}

void SAMP::classes::CPed::SetModelIndex(int nModel) {
	((void(__thiscall *)(CPed *, int))SAMP_ADDROF(0xAA820))(this, nModel);
}

CPed *SAMP::classes::CPed::GetAimedPed() {
	return ((::CPed *(__thiscall *)(CPed *))SAMP_ADDROF(0xA9800))(this);
}

void SAMP::classes::CPed::DestroyCommandTask() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA88C0))(this);
}

int SAMP::classes::CPed::GetStuff() {
	return ((int(__thiscall *)(CPed *))SAMP_ADDROF(0xA8530))(this);
}

BOOL SAMP::classes::CPed::ApplyStuff() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA8540))(this);
}

float SAMP::classes::CPed::GetRotation() {
	return ((float(__thiscall *)(CPed *))SAMP_ADDROF(0xA6750))(this);
}

void SAMP::classes::CPed::RemoveWeaponWhenEnteringVehicle() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xA69D0))(this);
}

BOOL SAMP::classes::CPed::CurrentWeaponHasAmmo() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA6A20))(this);
}

CEntity *SAMP::classes::CPed::GetFloor() {
	return ((::CEntity *(__thiscall *)(CPed *))SAMP_ADDROF(0xA72D0))(this);
}

CWeaponInfo *SAMP::classes::CPed::GetCurrentWeaponInfo() {
	return ((::CWeaponInfo *(__thiscall *)(CPed *))SAMP_ADDROF(0xA7380))(this);
}

unsigned short SAMP::classes::CPed::GetCurrentWeaponAmmo() {
	return ((unsigned short(__thiscall *)(CPed *))SAMP_ADDROF(0xA7A10))(this);
}

CWeapon *SAMP::classes::CPed::GetWeaponSlot(int nWeapon) {
	return ((::CWeapon *(__thiscall *)(CPed *, int))SAMP_ADDROF(0xA7A50))(this, nWeapon);
}

BOOL SAMP::classes::CPed::OpenParachute() {
	return ((BOOL(__thiscall *)(CPed *))SAMP_ADDROF(0xA7D90))(this);
}

void SAMP::classes::CPed::ProcessParachuteEvent(const char *szName) {
	((void(__thiscall *)(CPed *, const char *))SAMP_ADDROF(0xA7EE0))(this, szName);
}

const char *SAMP::classes::CPed::GetLoadedShoppingDataSubsection() {
	return ((const char *(__thiscall *)(CPed *))SAMP_ADDROF(0xA8B80))(this);
}

void SAMP::classes::CPed::LoadShoppingDataSubsection(const char *szName) {
	((void(__thiscall *)(CPed *, const char *))SAMP_ADDROF(0xA8BA0))(this, szName);
}

void SAMP::classes::CPed::SetWeaponAmmo(unsigned char nWeapon, unsigned short nAmmo) {
	((void(__thiscall *)(CPed *, unsigned char, unsigned short))SAMP_ADDROF(0xAA950))(this, nWeapon, nAmmo);
}

void SAMP::classes::CPed::ProcessDancing() {
	((void(__thiscall *)(CPed *))SAMP_ADDROF(0xAA980))(this);
}