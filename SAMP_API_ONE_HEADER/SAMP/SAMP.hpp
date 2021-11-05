#pragma once
#include <Windows.h>
#include <process.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

//DirectX
#include "../DirectX/d3d9.h"
#include "../DirectX/d3dx9.h"
#pragma comment(lib, "../DirectX/d3dx9.lib")

//new hooks
#include "injector/hde/hde32.h"
#include "injector/injector.hpp"
#include "injector/disassembler.hpp"
#include "injector/invoker.hpp"
#include "injector/hook.hpp"

//WinSock
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "WS2_32.lib")

//raknet
#include "samp_auth.h"
#include "samp_netencr.h"
#include "RakNet/PacketEnumerations.h"
#include "RakNet/SHA1.h"
#include "RakNet/RakNetworkFactory.h"
#include "RakNet/RakClientInterface.h"
#include "RakNet/NetworkTypes.h"
#include "RakNet/BitStream.h"
#include "RakNet/StringCompressor.h"
using namespace RakNet;

//samp structs ??
#include "Structs.h"

#define SAMP_INFO_OFFSET				0x21A0F8
#define SAMP_CHAT_INFO_OFFSET 			0x21A0E4
#define SAMP_CHAT_INPUT_INFO_OFFSET		0x21A0E8
#define SAMP_KILL_INFO_OFFSET			0x21A0EC
#define SAMP_DIALOG_INFO_OFFSET 		0x21A0B8
#define SAMP_MISC_INFO_OFFSET			0x21A10C
#define SAMP_SCOREBOARD_INFO_OFFSET		0x21A0B4

const float fWeaponDamage[55] =
{
	1.0f, // 0 - Fist
	1.0f, // 1 - Brass knuckles
	1.0f, // 2 - Golf club
	1.0f, // 3 - Nitestick
	1.0f, // 4 - Knife
	1.0f, // 5 - Bat
	1.0f, // 6 - Shovel
	1.0f, // 7 - Pool cue
	1.0f, // 8 - Katana
	1.0f, // 9 - Chainsaw
	1.0f, // 10 - Dildo
	1.0f, // 11 - Dildo 2
	1.0f, // 12 - Vibrator
	1.0f, // 13 - Vibrator 2
	1.0f, // 14 - Flowers
	1.0f, // 15 - Cane
	82.5f, // 16 - Grenade
	0.0f, // 17 - Teargas
	1.0f, // 18 - Molotov
	9.9f, // 19 - Vehicle M4 (custom)
	46.2f, // 20 - Vehicle minigun (custom)
	0.0f, // 21
	8.25f, // 22 - Colt 45
	13.200001f, // 23 - Silenced
	46.200001f, // 24 - Deagle
	49.500004f,//3.3, // 25 - Shotgun
	49.500004f,//3.3, // 26 - Sawed-off
	39.600002f,//4.95, // 27 - Spas
	6.6f, // 28 - UZI
	8.25f, // 29 - MP5
	9.900001f, // 30 - AK47
	9.900001f, // 31 - M4
	6.6f, // 32 - Tec9
	24.750002f, // 33 - Cuntgun
	41.25f, // 34 - Sniper
	82.5, // 35 - Rocket launcher
	82.5, // 36 - Heatseeker
	1.0, // 37 - Flamethrower
	46.200001f, // 38 - Minigun
	82.5f, // 39 - Satchel
	0.0f, // 40 - Detonator
	0.33f, // 41 - Spraycan
	0.33f, // 42 - Fire extinguisher
	0.0f, // 43 - Camera
	0.0f, // 44 - Night vision
	0.0f, // 45 - Infrared
	0.0f, // 46 - Parachute
	0.0f, // 47 - Fake pistol
	2.64f, // 48 - Pistol whip (custom)
	9.9f, // 49 - Vehicle
	330.0f, // 50 - Helicopter blades
	82.5f, // 51 - Explosion
	1.0f, // 52 - Car park (custom)
	1.0f, // 53 - Drowning
	165.0f // 54 - Splat
};
const float fWeaponRange[39] =
{
	0.0f, // 0 - Fist
	0.0f, // 1 - Brass knuckles
	0.0f, // 2 - Golf club
	0.0f, // 3 - Nitestick
	0.0f, // 4 - Knife
	0.0f, // 5 - Bat
	0.0f, // 6 - Shovel
	0.0f, // 7 - Pool cue
	0.0f, // 8 - Katana
	0.0f, // 9 - Chainsaw
	0.0f, // 10 - Dildo
	0.0f, // 11 - Dildo 2
	0.0f, // 12 - Vibrator
	0.0f, // 13 - Vibrator 2
	0.0f, // 14 - Flowers
	0.0f, // 15 - Cane
	0.0f, // 16 - Grenade
	0.0f, // 17 - Teargas
	0.0f, // 18 - Molotov
	90.0f, // 19 - Vehicle M4 (custom)
	75.0f, // 20 - Vehicle minigun (custom)
	0.0f, // 21
	35.0f, // 22 - Colt 45
	35.0f, // 23 - Silenced
	35.0f, // 24 - Deagle
	40.0f, // 25 - Shotgun
	35.0f, // 26 - Sawed-off
	40.0f, // 27 - Spas
	35.0f, // 28 - UZI
	45.0f, // 29 - MP5
	70.0f, // 30 - AK47
	90.0f, // 31 - M4
	35.0f, // 32 - Tec9
	100.0f, // 33 - Cuntgun
	320.0f, // 34 - Sniper
	0.0f, // 35 - Rocket launcher
	0.0f, // 36 - Heatseeker
	0.0f, // 37 - Flamethrower
	75.0f  // 38 - Minigun
};
enum
{
	DIALOG_STYLE_MSGBOX,
	DIALOG_STYLE_INPUT,
	DIALOG_STYLE_LIST,
	DIALOG_STYLE_PASSWORD,
};
enum
{
	SAMP_MAX_ACTORS = 1000,
	SAMP_MAX_PLAYERS = 1004,
	SAMP_MAX_VEHICLES = 2000,
	SAMP_MAX_PICKUPS = 4096,
	SAMP_MAX_OBJECTS = 1000,
	SAMP_MAX_GANGZONES = 1024,
	SAMP_MAX_3DTEXTS = 2048,
	SAMP_MAX_TEXTDRAWS = 2048,
	SAMP_MAX_PLAYERTEXTDRAWS = 256,
	SAMP_MAX_CLIENTCMDS = 144,
	SAMP_MAX_MENUS = 128,
	SAMP_MAX_PLAYER_NAME = 24,
	SAMP_ALLOWED_PLAYER_NAME_LENGTH = 20,
};
enum
{
	CHAT_TYPE_NONE = 0,
	CHAT_TYPE_CHAT = 2,
	CHAT_TYPE_INFO = 4,
	CHAT_TYPE_DEBUG = 8
};
enum
{
	CHAT_WINDOW_MODE_OFF = 0,
	CHAT_WINDOW_MODE_LIGHT = 1,
	CHAT_WINDOW_MODE_FULL = 2
};
enum
{
	GAMESTATE_WAIT_CONNECT = 9,
	GAMESTATE_CONNECTING = 13,
	GAMESTATE_AWAIT_JOIN = 15,
	GAMESTATE_CONNECTED = 14,
	GAMESTATE_RESTARTING = 18
};
enum
{
	PLAYER_STATE_NONE = 0,
	PLAYER_STATE_ONFOOT = 17,
	PLAYER_STATE_PASSENGER,
	PLAYER_STATE_DRIVER,
	PLAYER_STATE_WASTED = 32,
	PLAYER_STATE_SPAWNED
};
enum
{
	PLAYER_MARKERS_MODE_OFF,
	PLAYER_MARKERS_MODE_GLOBAL,
	PLAYER_MARKERS_MODE_STREAMED,
};
enum
{
	SPECIAL_ACTION_NONE,
	SPECIAL_ACTION_DUCK,
	SPECIAL_ACTION_USEJETPACK,
	SPECIAL_ACTION_ENTER_VEHICLE,
	SPECIAL_ACTION_EXIT_VEHICLE,
	SPECIAL_ACTION_DANCE1,
	SPECIAL_ACTION_DANCE2,
	SPECIAL_ACTION_DANCE3,
	SPECIAL_ACTION_DANCE4,
	SPECIAL_ACTION_HANDSUP,
	SPECIAL_ACTION_USECELLPHONE,
	SPECIAL_ACTION_SITTING,
	SPECIAL_ACTION_STOPUSECELLPHONE,
	SPECIAL_ACTION_DRINK_BEER = 20,
	SPECIAL_ACTION_SMOKE_CIGGY,
	SPECIAL_ACTION_DRINK_WINE,
	SPECIAL_ACTION_DRINK_SPRUNK,
	SPECIAL_ACTION_CUFFED,
	SPECIAL_ACTION_CARRY,
};


#pragma pack(push, 1)
struct stSAMP
{
	RakPeerInterface		*pRakPeerInterface;
	void					*pUnk0;
	uint8_t					byteSpace[24];
	char					szIP[257];
	char					szHostname[259];
	uint8_t					byteUnk1;
	uint32_t				ulPort;
	uint32_t				ulMapIcons[100];
	int						iLanMode;
	int						iGameState;
	uint32_t				ulConnectTick;
	struct stServerPresets	*pSettings;
	RakClientInterface		*pRakClientInterface;
	struct stSAMPPools		*pPools;
};
struct stServerPresets
{
	uint8_t byteCJWalk;
	uint8_t byteUnk0[4];
	float	fWorldBoundaries[4];
	uint8_t byteUnk1;
	float	fGravity;
	uint8_t byteDisableInteriorEnterExits;
	uint32_t ulVehicleFriendlyFire;
	uint8_t byteUnk2[4];
	int		iClassesAvailable;
	float	fNameTagsDistance;
	uint8_t byteUnk3;
	uint8_t byteWorldTime_Hour;
	uint8_t byteWorldTime_Minute;
	uint8_t byteWeather;
	uint8_t byteNoNametagsBehindWalls;
	uint8_t bytePlayerMarkersMode;
	uint8_t byteUnk4[3];
	float	fGlobalChatRadiusLimit;
	uint8_t byteShowNameTags;
};
struct stTextDrawTransmit
{
	union
	{
		BYTE byteFlags;
		struct
		{
			BYTE byteBox : 1;
			BYTE byteLeft : 1;
			BYTE byteRight : 1;
			BYTE byteCenter : 1;
			BYTE byteProportional : 1;
			BYTE bytePadding : 3;
		};
	};
	float fLetterWidth;
	float fLetterHeight;
	DWORD dwLetterColor;
	float fBoxWidth;
	float fBoxHeight;
	DWORD dwBoxColor;
	BYTE byteShadow;
	BYTE byteOutline;
	DWORD dwBackgroundColor;
	BYTE byteStyle;
	BYTE byteUNK;
	float fX;
	float fY;
	uint16_t sModel;
	float fRot[3];
	float fZoom;
	WORD sColor[2];
};
struct stTextdraw
{
	char		szText[800 + 1];
	char		szString[1600 + 2];
	float		fLetterWidth;
	float		fLetterHeight;
	DWORD		dwLetterColor;
	uint8_t		byte_unk;	// always = 01 (?)
	BYTE		byteCenter;
	BYTE		byteBox;
	float		fBoxSizeX;
	float		fBoxSizeY;
	DWORD		dwBoxColor;
	BYTE		byteProportional;
	DWORD		dwShadowColor;
	BYTE		byteShadowSize;
	BYTE		byteOutline;
	BYTE		byteLeft;
	BYTE		byteRight;
	int			iStyle;		// font style/texture/model
	float		fX;
	float		fY;
	byte		unk[8];
	DWORD		dword99B;	// -1 by default
	DWORD		dword99F;	// -1 by default
	DWORD		index;		// -1 if bad
	BYTE		byte9A7;	// = 1; 0 by default
	uint16_t	sModel;
	float		fRot[3];
	float		fZoom;
	WORD		sColor[2];
	BYTE		f9BE;
	BYTE		byte9BF;
	BYTE		byte9C0;
	DWORD		dword9C1;
	DWORD		dword9C5;
	DWORD		dword9C9;
	DWORD		dword9CD;
	BYTE		byte9D1;
	DWORD		dword9D2;
};
struct stTextdrawPool
{
	int					iIsListed[SAMP_MAX_TEXTDRAWS];
	int					iPlayerTextDraw[SAMP_MAX_PLAYERTEXTDRAWS];
	struct stTextdraw	*textdraw[SAMP_MAX_TEXTDRAWS];
	struct stTextdraw	*playerTextdraw[SAMP_MAX_PLAYERTEXTDRAWS];
};
struct stPickup
{
	int		iModelID;
	int		iType;
	float	fPosition[3];
};
struct stPickupPool
{
	int				iPickupsCount;
	uint32_t		ul_GTA_PickupID[SAMP_MAX_PICKUPS];
	int				iPickupID[SAMP_MAX_PICKUPS];
	int				iTimePickup[SAMP_MAX_PICKUPS];
	uint8_t			unk[SAMP_MAX_PICKUPS * 3];
	struct stPickup pickup[SAMP_MAX_PICKUPS];
};
struct stPlayerPool
{
	uint32_t				ulUnk0;
	uint16_t				sLocalPlayerID;
	void					*pVTBL_txtHandler;
	union
	{
		char	szLocalPlayerName[16];
		char	*pszLocalPlayerName;
	};
	int						iLocalPlayerNameLen;
	int						iLocalPlayerNameAllocated;
	struct stLocalPlayer	*pLocalPlayer;
	int						iLocalPlayerPing;
	int						iLocalPlayerScore;
	struct stRemotePlayer	*pRemotePlayer[SAMP_MAX_PLAYERS];
	int						iIsListed[SAMP_MAX_PLAYERS];
	uint32_t				ulUnk1[SAMP_MAX_PLAYERS];
#ifdef PSDK
	CPed *GetCPedFromPlayerID(uint32_t playerID);
	actor_info *GetActorInfoFromPlayerID(uint32_t playerID);
	bool IsPlayerStreamed(uint16_t playerID);
	D3DCOLOR GetPlayerColor(uint16_t playerID);
	unsigned __int16 stPlayerPool::GetPlayerIDFromCPed(CPed *pPed);
#endif
};
struct stSAMPKeys
{
	unsigned __int8 keys_primaryFire : 1;
	unsigned __int8 keys_horn__crouch : 1;
	unsigned __int8 keys_secondaryFire__shoot : 1;
	unsigned __int8 keys_accel__zoomOut : 1;
	unsigned __int8 keys_enterExitCar : 1;
	unsigned __int8 keys_decel__jump : 1;			// on foot: jump or zoom in
	unsigned __int8 keys_circleRight : 1;
	unsigned __int8 keys_aim : 1;					// hydra auto aim or on foot aim
	unsigned __int8 keys_circleLeft : 1;
	unsigned __int8 keys_landingGear__lookback : 1;
	unsigned __int8 keys_unknown__walkSlow : 1;
	unsigned __int8 keys_specialCtrlUp : 1;
	unsigned __int8 keys_specialCtrlDown : 1;
	unsigned __int8 keys_specialCtrlLeft : 1;
	unsigned __int8 keys_specialCtrlRight : 1;
	unsigned __int8 keys__unused : 1;
};
struct stOnFootData
{
	unsigned __int16 sLeftRightKeys;
	unsigned __int16 sUpDownKeys;
	union
	{
		unsigned __int16 sKeys;
		struct stSAMPKeys stSampKeys;
	};
	float fPosition[3];
	float fQuaternion[4];
	unsigned __int8 byteHealth;
	unsigned __int8 byteArmor;
	unsigned __int8 byteCurrentWeapon;
	unsigned __int8 byteSpecialAction;
	float fMoveSpeed[3];
	float fSurfingOffsets[3];
	unsigned __int16 sSurfingVehicleID;
	short sCurrentAnimationID;
	short sAnimFlags;
};
struct stInCarData
{
	unsigned __int16 sVehicleID;
	unsigned __int16 sLeftRightKeys;
	unsigned __int16 sUpDownKeys;
	union
	{
		unsigned __int16 sKeys;
		struct stSAMPKeys stSampKeys;
	};
	float fQuaternion[4];
	float fPosition[3];
	float fMoveSpeed[3];
	float fVehicleHealth;
	unsigned __int8 bytePlayerHealth;
	unsigned __int8 byteArmor;
	unsigned __int8 byteCurrentWeapon;
	unsigned __int8 byteSiren;
	unsigned __int8 byteLandingGearState;
	unsigned __int16 sTrailerID;
	union
	{
		unsigned __int16 HydraThrustAngle[2];	//nearly same value
		float fTrainSpeed;
	};
};
struct stAimData
{
	unsigned __int8	byteCamMode;
	float vecAimf1[3];
	float vecAimPos[3];
	float fAimZ;
	unsigned __int8	byteCamExtZoom : 6;		// 0-63 normalized
	unsigned __int8	byteWeaponState : 2;	// see eWeaponState
	unsigned __int8	byteAspectRatio;
};
struct stTrailerData
{
	unsigned __int16 sTrailerID;
	float fPosition[3];
	float fQuaternion[4];
	float fSpeed[3];
	float fAngularSpeed[3];
};
struct stPassengerData
{
	unsigned __int16 sVehicleID;
	unsigned __int8	 byteSeatID;
	unsigned __int8 byteCurrentWeapon;
	unsigned __int8 byteHealth;
	unsigned __int8 byteArmor;
	unsigned __int16 sLeftRightKeys;
	unsigned __int16 sUpDownKeys;
	union
	{
		unsigned __int16 sKeys;
		struct stSAMPKeys stSampKeys;
	};
	float fPosition[3];
};
struct stUnoccupiedData
{
	__int16 sVehicleID;
	unsigned __int8 byteSeatID;
	float fRoll[3];
	float fDirection[3];
	float fPosition[3];
	float fMoveSpeed[3];
	float fTurnSpeed[3];
	float fHealth;
};
struct stBulletData
{
	unsigned __int8	 byteType;
	unsigned __int16 sTargetID;
	float fOrigin[3];
	float fTarget[3];
	float fCenter[3];
	unsigned __int8 byteWeaponID;
};
struct stSpectatorData
{
	unsigned __int16 sLeftRightKeys;
	unsigned __int16 sUpDownKeys;
	union
	{
		unsigned __int16 sKeys;
		struct stSAMPKeys stSampKeys;
	};
	float fPosition[3];
};
struct stDamageData
{
	uint16_t	sVehicleID_lastDamageProcessed;
	int			iBumperDamage;
	int			iDoorDamage;
	uint8_t		byteLightDamage;
	uint8_t		byteWheelDamage;
};
struct stSurfData
{
	int			iIsSurfing;
	float		fSurfPosition[3];
	int			iUnk0;
	uint16_t	sSurfingVehicleID;
	uint32_t	ulSurfTick;
	struct stSAMPVehicle *pSurfingVehicle;
	int			iUnk1;
	int			iSurfMode;	//0 = not surfing, 1 = moving (unstable surf), 2 = fixed on vehicle
};
struct stStatsData
{
	int iMoney;
	int iAmmo;	// ?
};
struct stHeadSync
{
	float	fHeadSync[3];
	int		iHeadSyncUpdateTick;
	int		iHeadSyncLookTick;
};
struct stLocalPlayer
{
	struct stSAMPPed		*pSAMP_Actor;
	uint16_t				sCurrentAnimID;
	uint16_t				sAnimFlags;
	uint32_t				ulUnk0;
	int						iIsActive;
	int						iIsWasted;
	uint16_t				sCurrentVehicleID;
	uint16_t				sLastVehicleID;
	struct stOnFootData		onFootData;
	struct stPassengerData	passengerData;
	struct stTrailerData	trailerData;
	struct stInCarData		inCarData;
	struct stAimData		aimData;
	uint8_t					byteTeamID;
	int						iSpawnSkin;
	uint8_t					byteUnk1;
	float					fSpawnPos[3];
	float					fSpawnRot;
	int						iSpawnWeapon[3];
	int						iSpawnAmmo[3];
	int						iIsActorAlive;
	int						iSpawnClassLoaded;
	uint32_t				ulSpawnSelectionTick;
	uint32_t				ulSpawnSelectionStart;
	int						iIsSpectating;
	uint8_t					byteTeamID2;
	uint16_t				usUnk2;
	uint32_t				ulSendTick;
	uint32_t				ulSpectateTick;
	uint32_t				ulAimTick;
	uint32_t				ulStatsUpdateTick;
	uint32_t				ulWeapUpdateTick;
	uint16_t				sAimingAtPid;
	uint16_t				usUnk3;
	uint8_t					byteCurrentWeapon;
	uint8_t					byteWeaponInventory[13];
	int						iWeaponAmmo[13];
	int						iPassengerDriveBy;
	uint8_t					byteCurrentInterior;
	int						iIsInRCVehicle;
	uint16_t				sTargetObjectID;
	uint16_t				sTargetVehicleID;
	uint16_t				sTargetPlayerID;
	struct stHeadSync		headSyncData;
	uint32_t				ulHeadSyncTick;
	BYTE					byteSpace3[260];
	struct stSurfData		surfData;
	int						iClassSelectionOnDeath;
	int						iSpawnClassID;
	int						iRequestToSpawn;
	int						iIsInSpawnScreen;
	uint32_t				ulUnk4;
	uint8_t					byteSpectateMode;		// 3 = vehicle, 4 = player, side = 14, fixed = 15
	uint8_t					byteSpectateType;		// 0 = none, 1 = player, 2 = vehicle
	int						iSpectateID;
	int						iInitiatedSpectating;
	struct stDamageData		vehicleDamageData;
};
struct stRemotePlayerData
{
	struct stSAMPPed		*pSAMP_Actor;
	struct stSAMPVehicle	*pSAMP_Vehicle;
	uint8_t					byteTeamID;
	uint8_t					bytePlayerState;
	uint8_t					byteSeatID;
	uint32_t				ulUnk3;
	int						iPassengerDriveBy;
	void					*pUnk0;
	uint8_t					byteUnk1[60];
	float					fSomething[3];
	float					fVehicleRoll[4];
	uint32_t				ulUnk2[3];
	float					fOnFootPos[3];
	float					fOnFootMoveSpeed[3];
	float					fVehiclePosition[3];
	float					fVehicleMoveSpeed[3];
	uint16_t				sPlayerID;
	uint16_t				sVehicleID;
	uint32_t				ulUnk5;
	uint8_t					byteUnk6[2];
	short					sShowNameTag;
	int						iHasJetPack;
	uint8_t					byteSpecialAction;
	struct stAimData		aimData;
	struct stInCarData		inCarData;
	struct stOnFootData		onFootData;
	struct stTrailerData	trailerData;
	struct stPassengerData	passengerData;
	uint32_t				ulUnk4[3];
	float					fActorArmor;
	float					fActorHealth;
	uint32_t				ulUnk10;
	uint8_t					byteUnk9;
	uint32_t				dwTick;
	uint32_t				dwLastStreamedInTick;	// is 0 when currently streamed in
	uint32_t				ulUnk7;
	int						iAFKState;
	struct stHeadSync		headSyncData;
	int						iGlobalMarkerLoaded;
	int						iGlobalMarkerLocation[3];
	uint32_t				ulGlobalMarker_GTAID;
};
struct stRemotePlayer
{
	stRemotePlayerData	*pPlayerData;
	int					iIsNPC;
	void				*pVTBL_txtHandler;
	union
	{
		char			szPlayerName[16];
		char			*pszPlayerName;
	};
	int					iNameLen;
	int					iNameAllocated;
	int					iScore;
	int					iPing;
};
template <typename T>
struct stSAMPEntity
{
	void		*pVTBL;
	uint8_t		byteUnk0[60]; // game CEntity object maybe. always empty.
	T			*pGTAEntity;
	uint32_t	ulGTAEntityHandle;
};
struct stSAMPPed : public stSAMPEntity < actor_info >
{
	int					usingCellPhone;
	uint8_t				byteUnk0[600];
	struct actor_info	*pGTA_Ped;
	uint8_t				byteUnk1[22];
	uint8_t				byteKeysId;
	uint16_t			ulGTA_UrinateParticle_ID;
	int					DrinkingOrSmoking;
	int					object_in_hand;
	int					drunkLevel;
	uint8_t				byteUnk2[5];
	int					isDancing;
	int					danceStyle;
	int					danceMove;
	uint8_t				byteUnk3[20];
	int					isUrinating;
};
struct stVehiclePool
{
	int						iVehicleCount;
	void					*pUnk0;
	uint8_t					byteSpace1[0x112C];
	struct stSAMPVehicle	*pSAMP_Vehicle[SAMP_MAX_VEHICLES];
	int						iIsListed[SAMP_MAX_VEHICLES];
	struct vehicle_info		*pGTA_Vehicle[SAMP_MAX_VEHICLES];
	uint8_t					byteSpace2[SAMP_MAX_VEHICLES * 6];
	uint32_t				ulShit[SAMP_MAX_VEHICLES];
	int						iIsListed2[SAMP_MAX_VEHICLES];
	uint32_t				byteSpace3[SAMP_MAX_VEHICLES * 2];
	float					fSpawnPos[SAMP_MAX_VEHICLES][3];
	int						iInitiated;
#ifdef PSDK
	bool IsVehicleStreamed(uint16_t vehicleID);
	CVehicle *GetCVehicleFromSAMPVehicleID(uint16_t vehicleID);
	vehicle_info *GetVehicleInfoFromSAMPVehicleID(uint16_t vehicleID);
#endif
};
struct stSAMPVehicle : public stSAMPEntity < vehicle_info >
{
	uint32_t			bUnk0;
	struct vehicle_info *pGTA_Vehicle;
	uint8_t				byteUnk1[8];
	int					bIsMotorOn;
	int					iIsLightsOn;
	int					iIsLocked;
	uint8_t				byteIsObjective;
	int					iObjectiveBlipCreated;
	uint8_t				byteUnk2[20];
	uint8_t				byteColor[2];
	int					iColorSync;
	int					iColor_something;
};
struct stObject// : public stSAMPEntity < object_info >
{
	uint8_t				byteUnk0[2];
	uint32_t			ulUnk1;
	int					iModel;
	uint8_t				byteUnk2;
	float				fDrawDistance;
	float				fUnk;
	float				fPos[3];
	// ...
};
struct stObjectPool
{
	int				iObjectCount;
	int				iIsListed[SAMP_MAX_OBJECTS];
	struct stObject *object[SAMP_MAX_OBJECTS];
};
struct stGangzone
{
	float	fPosition[4];
	DWORD	dwColor;
	DWORD	dwAltColor;
};
struct stGangzonePool
{
	struct stGangzone	*pGangzone[SAMP_MAX_GANGZONES];
	int					iIsListed[SAMP_MAX_GANGZONES];
};
struct stTextLabel
{
	char		*pText;
	DWORD		color;
	float		fPosition[3];
	float		fMaxViewDistance;
	uint8_t		byteShowBehindWalls;
	uint16_t	sAttachedToPlayerID;
	uint16_t	sAttachedToVehicleID;
};
struct stTextLabelPool
{
	struct stTextLabel	textLabel[SAMP_MAX_3DTEXTS];
	int					iIsListed[SAMP_MAX_3DTEXTS];
};
struct stChatEntry
{
	uint32_t	SystemTime;
	char		szPrefix[28];
	char		szText[144];
	uint8_t		unknown[64];
	int			iType;			// 2 - text + prefix, 4 - text (server msg), 8 - text (debug)
	D3DCOLOR	clTextColor;
	D3DCOLOR	clPrefixColor;	// or textOnly colour
};
struct stFontRenderer
{
	ID3DXFont	*m_pChatFont;
	ID3DXFont	*m_pLittleFont;
	ID3DXFont	*m_pChatShadowFont;
	ID3DXFont	*m_pLittleShadowFont;
	ID3DXFont	*m_pCarNumberFont;
	ID3DXSprite *m_pTempSprite;
	int			field_18;
	char		*m_pszTextBuffer;
};
struct stChatInfo
{
	int					pagesize;
	char				*pLastMsgText;
	int					iChatWindowMode;
	uint8_t				bTimestamps;
	uint32_t			ulUnk0;
	char				logFilePathChatLog[MAX_PATH + 1];
	void				*pChatbox_unknown[3];	// probably classes that handle fonts/sprites
	D3DCOLOR			clTextColor;
	D3DCOLOR			clInfoColor;
	D3DCOLOR			clDebugColor;
	DWORD				dwChatboxOffset;
	struct stChatEntry	chatEntry[100];
	stFontRenderer		*m_pFontRenderer;
	ID3DXSprite			*m_pChatTextSprite;
	ID3DXSprite			*m_pSprite;
	IDirect3DDevice9	*m_pD3DDevice;
	uint32_t			ulUnk1[2];
	IDirect3DTexture9	*m_pTexture;
	uint32_t			ulUnk2[7];
	int					m_iRedraw;
	int					m_nPrevScrollBarPosition;
	int					m_iDistanceAfterTimestamp;
	uint32_t			ulUnk3;
};
struct stInputBox
{
	void	*pUnknown;
	uint8_t	bIsChatboxOpen;
	uint8_t	bIsMouseInChatbox;
	uint8_t	bMouseClick_related;
	uint8_t	unk;
	DWORD	dwPosChatInput[2];
	uint8_t	unk2[263];
	int		iCursorPosition;
	uint8_t	unk3;
	int		iMarkedText_startPos; // Highlighted text between this and iCursorPosition
	uint8_t	unk4[20];
	int		iMouseLeftButton;
};
typedef void(__cdecl *CMDPROC) (PCHAR);
struct stInputInfo
{
	void				*pD3DDevice;
	void				*pDXUTDialog;
	stInputBox			*pDXUTEditBox;
	CMDPROC				pCMDs[SAMP_MAX_CLIENTCMDS];
	char				szCMDNames[SAMP_MAX_CLIENTCMDS][33];
	int					iCMDCount;
	int					iInputEnabled;
	char				szInputBuffer[129];
	char				szRecallBufffer[10][129];
	char				szCurrentBuffer[129];
	int					iCurrentRecall;
	int					iTotalRecalls;
	CMDPROC				pszDefaultCMD;
};
struct stKillEntry
{
	char		szKiller[25];
	char		szVictim[25];
	D3DCOLOR	clKillerColor;
	D3DCOLOR	clVictimColor;
	uint8_t		byteType;
};
struct stKillInfo
{
	int					iEnabled;
	struct stKillEntry	killEntry[5];
	int					iXOffset[2];
	int					iYSpacing;
	ID3DXFont		    *pD3DFont;
	ID3DXFont			*pWeaponFont;
	ID3DXSprite			*pSprite;
	IDirect3DDevice9	*pD3DDevice;
};
struct stChatPlayer
{
	int		iCreated;
	char	probablyTheText[256];
	DWORD	dwTickCreated;
	DWORD	dwLiveLength;
	DWORD	dwColor;
	float	fDrawDistance;
	DWORD	dwUnknown;
};
struct stMiscInfo
{
	void	*pUnk0[3];
	uint8_t	byteSpace1[73];
	int		iCursorMode;
	int		iSomething[5];
	// ...
};
struct stScoreboardInfo
{
	int					iIsEnabled;
	int					iPlayersCount;
	float				fTextOffset[2];
	float				fScalar;
	float				fSize[2];
	float				fUnk0[5];
	IDirect3DDevice9	*pDirectDevice;
	class _CDXUTDialog	*pDialog;
	class _CDXUTListBox *pList;
	int					iOffset;		// ?
	int					iIsSorted;		// ?
};
struct stActorPool
{
	int					iLastActorID;
	stSAMPEntity<void>	*pActor[SAMP_MAX_ACTORS]; // ?
	int					iIsListed[SAMP_MAX_ACTORS];
	struct actor_info	*pGTAPed[SAMP_MAX_ACTORS];
	uint32_t			ulUnk0[SAMP_MAX_ACTORS];
	uint32_t			ulUnk1[SAMP_MAX_ACTORS];
};
struct stChatBubbleInfo
{
	struct stChatPlayer	chatBubble[SAMP_MAX_PLAYERS];
};
struct stStreamedOutPlayerInfo
{
	int		iPlayerID[SAMP_MAX_PLAYERS];
	float	fPlayerPos[SAMP_MAX_PLAYERS][3];
};
struct stSAMPPools
{
	struct stActorPool		*pActor;
	struct stObjectPool		*pObject;
	struct stGangzonePool	*pGangzone;
	struct stTextLabelPool	*pText3D;
	struct stTextdrawPool	*pTextdraw;
	void					*pPlayerLabels;
	struct stPlayerPool		*pPlayer;
	struct stVehiclePool	*pVehicle;
	struct stPickupPool		*pPickup;
};
#pragma pack(pop)


namespace SAMP {
	class CSAMP {
	public:
		bool LoadAPI(void) {//init samp api
			g_SAMP = *reinterpret_cast<stSAMP**>(sampAddr + SAMP_INFO_OFFSET);

			if (g_SAMP == nullptr)
				return false;

			g_Chat = *reinterpret_cast<stChatInfo**>(sampAddr + SAMP_CHAT_INFO_OFFSET);

			if (g_Chat == nullptr)
				return false;

			g_Input = *reinterpret_cast<stInputInfo**>(sampAddr + SAMP_CHAT_INPUT_INFO_OFFSET);

			if (g_Input == nullptr)
				return false;

			
			g_KillInfo = *reinterpret_cast<stKillInfo**>(sampAddr + SAMP_KILL_INFO_OFFSET);

			if (g_KillInfo == nullptr)
				return false;

			g_ScoreboardInfo = *reinterpret_cast<stScoreboardInfo**>(sampAddr + SAMP_SCOREBOARD_INFO_OFFSET);

			if (g_ScoreboardInfo == nullptr)
				return false;

			g_MiscInfo = *reinterpret_cast<stMiscInfo**>(sampAddr + SAMP_MISC_INFO_OFFSET);

			if (g_MiscInfo == nullptr)
				return false;

			if (g_SAMP->pRakClientInterface == nullptr)
				return false;

			g_Vehicles = g_SAMP->pPools->pVehicle;
			g_Players = g_SAMP->pPools->pPlayer;


			return true;
		};
		
		struct stSAMP *getInfo(void) { return g_SAMP; };
		struct stPlayerPool *getPlayers(void) { return g_Players; };
		struct stVehiclePool *getVehicles(void) { return g_Vehicles; };
		struct stChatInfo *getChat(void) { return g_Chat; };
		struct stInputInfo *getInput(void) { return g_Input; };
		struct stKillInfo *getKillInfo(void) { return g_KillInfo; };
		struct stScoreboardInfo *getScoreboardInfo(void) { return g_ScoreboardInfo; };
		struct stMiscInfo *getMiscInfo(void) { return g_MiscInfo; };
		
		void addMessageToChat(D3DCOLOR cColor, char *szMsg, ...) {
			if (g_Chat == nullptr)
				return;

			void(__thiscall *AddToChatWindowBuffer) (const void *_this, int iType, char *szText, char *szPrefix, DWORD cColor, DWORD cPrefixColor) =
				(void(__thiscall *) (const void *, int, char *, char *, DWORD, DWORD)) (sampAddr + 0x064010);

			if (szMsg == NULL)
				return;

			va_list ap;
			char tmp[512];
			memset(tmp, 0, 512);
			va_start(ap, szMsg);
			vsnprintf(tmp, sizeof(tmp) - 1, szMsg, ap);
			va_end(ap);

			return AddToChatWindowBuffer((void *)g_Chat, 8, tmp, NULL, cColor, 0x00);
		};

		void addClientCommand(char *szCmd, CMDPROC pFunc)
		{
			if (g_Input == nullptr)
				return;

			void(__thiscall *AddClientCommand) (const void *_this, char *szCommand, CMDPROC pFunc) =
				(void(__thiscall *) (const void *, char *, CMDPROC)) (sampAddr + 0x065AD0);

			if (szCmd == NULL)
				return;

			return AddClientCommand(g_Input, szCmd, pFunc);
		}

		void unregisterChatCommand(void *func) {
			for (int i = 0; i < 144; i++) {
				if (g_Input->pCMDs[i] == func) {
					memset(&g_Input->pCMDs[i], 0, 4);
					memset(g_Input->szCMDNames[i], 0, 33);
					memset(&g_Input->szCMDNames[i], 0, 4);
				}
			}
		}

		~CSAMP() {
			g_SAMP = nullptr;
			g_Players = nullptr;
			g_Vehicles = nullptr;
			g_Chat = nullptr;
			g_Input = nullptr;
			g_KillInfo = nullptr;
			g_ScoreboardInfo = nullptr;
			g_MiscInfo = nullptr;
		};
		CSAMP(DWORD base) { sampAddr = base; };
		DWORD GetBase() { return sampAddr; };
	private:
		DWORD sampAddr = 0;
		struct stSAMP *g_SAMP = 0;
		struct stPlayerPool *g_Players = 0;
		struct stVehiclePool *g_Vehicles = 0;
		struct stChatInfo *g_Chat = 0;
		struct stInputInfo *g_Input = 0;
		struct stKillInfo *g_KillInfo = 0;
		struct stScoreboardInfo *g_ScoreboardInfo = 0;
		struct stMiscInfo *g_MiscInfo = 0;
	};
	
	CSAMP *pSAMP = nullptr;

	namespace CallBacks {

		namespace HookedStructs {
			struct stWndProcParams {
				HWND hWnd;
				UINT uMsg;
				WPARAM wParam;
				LPARAM lParam;
			};
			struct stPresentParams {
				IDirect3DDevice9* pDevice;
				CONST RECT* pSrcRect;
				CONST RECT* pDestRect;
				HWND hDestWindow;
				CONST RGNDATA* pDirtyRegion;
			};
			struct stResetParams {
				IDirect3DDevice9* pDevice;
				D3DPRESENT_PARAMETERS* pPresentParams;
			};
		}

		class CCallbackRegister {
		public:			
			typedef LRESULT(__stdcall *tWndProc)(HookedStructs::stWndProcParams*);
			typedef void(__stdcall *tGameLoop)();
			typedef HRESULT(__stdcall* tPresent_)(HookedStructs::stPresentParams*);
			typedef HRESULT(__stdcall* tReset_)(HookedStructs::stResetParams*);

			CCallbackRegister(DWORD base) {
				sampBase = base;

				gHookWndProc = std::make_unique<injector::Hook>(0x00747EB0U, HOOKED_WndProc);
				gHookGameLoop = std::make_unique<injector::Hook>(0x00748DA3U, HOOKED_GameLoop);
				gHookD3DPresent = std::make_unique<injector::Hook>(GetDeviceAddress(17), HOOKED_Present);
				gHookD3DReset = std::make_unique<injector::Hook>(GetDeviceAddress(16), HOOKED_Reset);

				gHookWndProc->Install();
				gHookGameLoop->Install();
				gHookD3DPresent->Install();
				gHookD3DReset->Install();
			}

			~CCallbackRegister() {
				gHookWndProc->Remove();
				gHookGameLoop->Remove();
				gHookD3DPresent->Remove();
				gHookD3DReset->Remove();
			}

			//сделать перегрузки
			
			void inline RegisterWndProcCallback(tWndProc func) { callWndProc = func; };
			void inline RegisterGameLoopCallback(tGameLoop func) { callGameLoop = func; };

			void inline RegisterD3DCallback(tPresent_ func) { callPresent = func; };
			void inline RegisterD3DCallback(tReset_ func) { callReset = func; };

			IDirect3DDevice9 inline *GetIDirect3DDevice9(void) { return pD3DDevice; };
		private:
			std::unique_ptr<injector::Hook> gHookGameLoop;
			std::unique_ptr<injector::Hook> gHookWndProc;

			std::unique_ptr<injector::Hook> gHookD3DPresent;
			std::unique_ptr<injector::Hook> gHookD3DReset;


			IDirect3DDevice9* pD3DDevice = nullptr;
			bool isD3DHookInit = false;

			DWORD sampBase = 0;

			tWndProc callWndProc = 0;
			tGameLoop callGameLoop = 0;
			tPresent_ callPresent = 0;
			tReset_ callReset = 0;

			static LRESULT __stdcall HOOKED_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
			static void __stdcall HOOKED_GameLoop();
			static HRESULT __stdcall HOOKED_Present(IDirect3DDevice9* pDevice, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion);
			static HRESULT __stdcall HOOKED_Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentParams);

			DWORD FindDevice(DWORD dwLen)
			{
				DWORD dwObjBase = 0;
				char infoBuf[MAX_PATH];
				GetSystemDirectoryA(infoBuf, MAX_PATH);
				strcat_s(infoBuf, MAX_PATH, "\\d3d9.dll");
				dwObjBase = (DWORD)LoadLibraryA(infoBuf);
				while (dwObjBase++ < dwObjBase + dwLen)
				{
					if ((*(WORD*)(dwObjBase + 0x00)) == 0x06C7 &&
						(*(WORD*)(dwObjBase + 0x06)) == 0x8689 &&
						(*(WORD*)(dwObjBase + 0x0C)) == 0x8689)
					{
						dwObjBase += 2;
						break;
					}
				}
				return(dwObjBase);
			};
			DWORD GetDeviceAddress(int VTableIndex)
			{
				PDWORD VTable;
				*(DWORD*)&VTable = *(DWORD*)FindDevice(0x128000);
				return VTable[VTableIndex];
			};
		};
		
		CCallbackRegister *pCallBackRegister = nullptr;
	}

	bool bKeyTable[256];
	bool isKeyDown(uint8_t key) {
		return bKeyTable[key];
	}
	bool isKeyPressed(uint8_t key) {
		static bool bPressed[0xFF];
		if (bKeyTable[key]) {
			if (!bPressed[key])
				return bPressed[key] = true;
		}
		else bPressed[key] = false;

		return false;
	}
	bool isKeyReleased(uint8_t vkey) {
		static bool bPressed[0xFF];
		if (!bKeyTable[vkey]) {
			if (bPressed[vkey])
				return !(bPressed[vkey] = false);
		}
		else bPressed[vkey] = true;

		return false;
	}
}


HRESULT __stdcall SAMP::CallBacks::CCallbackRegister::HOOKED_Present(IDirect3DDevice9* pDevice, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion) {
	if(pDevice == nullptr)
		return SAMP::CallBacks::pCallBackRegister->gHookD3DPresent->Call<HRESULT, EConvention::kStdcall>(pDevice, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
	if (!SAMP::CallBacks::pCallBackRegister->isD3DHookInit) {
		SAMP::CallBacks::pCallBackRegister->isD3DHookInit = true;
		SAMP::CallBacks::pCallBackRegister->pD3DDevice = pDevice;
	}

	if (SAMP::CallBacks::pCallBackRegister->callPresent != 0) {
		HookedStructs::stPresentParams params = { 0 };
		params.hDestWindow = hDestWindow;
		params.pDestRect = pDestRect;
		params.pDevice = pDevice;
		params.pDirtyRegion = pDirtyRegion;
		params.pSrcRect = pSrcRect;
		LRESULT retn = SAMP::CallBacks::pCallBackRegister->callPresent(&params);
		hDestWindow = params.hDestWindow;
		pDestRect = params.pDestRect;
		pDevice = params.pDevice;
		pDirtyRegion = params.pDirtyRegion;
		pSrcRect = params.pSrcRect;
		if (retn != D3D_OK)
			return retn;
	}

	return SAMP::CallBacks::pCallBackRegister->gHookD3DPresent->Call<HRESULT, EConvention::kStdcall>(pDevice, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
}
HRESULT __stdcall SAMP::CallBacks::CCallbackRegister::HOOKED_Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentParams) {
	if (pDevice == nullptr)
		return SAMP::CallBacks::pCallBackRegister->gHookD3DReset->Call<HRESULT, EConvention::kStdcall>(pDevice, pPresentParams);
	
	if (SAMP::CallBacks::pCallBackRegister->callReset != 0) {
		HookedStructs::stResetParams params = { 0 };
		params.pDevice = pDevice;
		params.pPresentParams = pPresentParams;
		LRESULT retn = SAMP::CallBacks::pCallBackRegister->callReset(&params);
		pDevice = params.pDevice;
		pPresentParams = params.pPresentParams;
		if (retn != D3D_OK)
			return retn;
	}

	return SAMP::CallBacks::pCallBackRegister->gHookD3DReset->Call<HRESULT, EConvention::kStdcall>(pDevice, pPresentParams);
}
void SAMP::CallBacks::CCallbackRegister::HOOKED_GameLoop() {
	if (SAMP::CallBacks::pCallBackRegister->callGameLoop != 0) {
		SAMP::CallBacks::pCallBackRegister->callGameLoop();
	}
	return SAMP::CallBacks::pCallBackRegister->gHookGameLoop->Call<void, EConvention::kCdeclcall>();
}
LRESULT __stdcall SAMP::CallBacks::CCallbackRegister::HOOKED_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
		SAMP::bKeyTable[VK_LBUTTON] = (uMsg == WM_LBUTTONDOWN);
		break;

	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
		SAMP::bKeyTable[VK_RBUTTON] = (uMsg == WM_RBUTTONDOWN);
		break;

	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP:
		SAMP::bKeyTable[VK_MBUTTON] = (uMsg == WM_MBUTTONDOWN);
		break;

	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
	case WM_KEYDOWN:
	case WM_KEYUP:
	{
		bool bDown = (uMsg == WM_SYSKEYDOWN || uMsg == WM_KEYDOWN);
		int	iKey = (int)wParam;
		uint32_t ScanCode = LOBYTE(HIWORD(lParam));

		SAMP::bKeyTable[iKey] = bDown;

		switch (iKey)
		{
		case VK_SHIFT:
			if (ScanCode == MapVirtualKey(VK_LSHIFT, 0)) SAMP::bKeyTable[VK_LSHIFT] = bDown;
			if (ScanCode == MapVirtualKey(VK_RSHIFT, 0)) SAMP::bKeyTable[VK_RSHIFT] = bDown;
			break;

		case VK_CONTROL:
			if (ScanCode == MapVirtualKey(VK_LCONTROL, 0)) SAMP::bKeyTable[VK_LCONTROL] = bDown;
			if (ScanCode == MapVirtualKey(VK_RCONTROL, 0)) SAMP::bKeyTable[VK_RCONTROL] = bDown;
			break;

		case VK_MENU:
			if (ScanCode == MapVirtualKey(VK_LMENU, 0)) SAMP::bKeyTable[VK_LMENU] = bDown;
			if (ScanCode == MapVirtualKey(VK_RMENU, 0)) SAMP::bKeyTable[VK_RMENU] = bDown;
			break;
		}
		break;
	}
	}

	if (SAMP::CallBacks::pCallBackRegister->callWndProc != 0) {//maybe error if null?
		HookedStructs::stWndProcParams params = { 0 };
		params.hWnd = hWnd;
		params.uMsg = uMsg;
		params.wParam = wParam;
		params.lParam = lParam;
		LRESULT retn = SAMP::CallBacks::pCallBackRegister->callWndProc(&params);
		hWnd = params.hWnd;
		uMsg = params.uMsg;
		wParam = params.wParam;
		lParam = params.lParam;
		if (retn != 0)
			return retn;
	}
	return SAMP::CallBacks::pCallBackRegister->gHookWndProc->Call<HRESULT, EConvention::kStdcall>(hWnd, uMsg, wParam, lParam);
}

