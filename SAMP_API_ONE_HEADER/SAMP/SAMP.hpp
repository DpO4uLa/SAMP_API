#pragma once
#pragma warning(disable:26495)
#pragma warning(disable:26439)
#pragma warning(disable:26815)
#pragma warning(disable:26819)
#pragma warning(disable:26812)
#pragma warning(disable:28159)
#include <Windows.h>
#include <process.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

//DirectX
#include "../DirectX/d3d9.h"
#include "../DirectX/d3dx9.h"
#pragma comment(lib, "../DirectX/d3dx9.lib")

#include "../DirectX/d3drender.h"

//new hooks
#include "../memwrapper/memwrapper.h"

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

//samp classes
#include "classes/AimStuff.h"
#include "classes/Animation.h"
#include "classes/CActor.h"
#include "classes/CActorPool.h"
#include "classes/CAudio.h"
#include "classes/CAudioStream.h"
#include "classes/CCamera.h"
#include "classes/CChat.h"
#include "classes/CConfig.h"
#include "classes/CDeathWindow.h"
#include "classes/CDialog.h"
#include "classes/CEntity.h"
#include "classes/CFonts.h"
#include "classes/CGame.h"
#include "classes/CGangZonePool.h"
#include "classes/CHttpClient.h"
#include "classes/CInput.h"
#include "classes/CLabel.h"
#include "classes/CLabelPool.h"
#include "classes/CLicensePlate.h"
#include "classes/CLocalPlayer.h"
#include "classes/CMatrix.h"
#include "classes/CMenu.h"
#include "classes/CMenuPool.h"
#include "classes/CNetGame.h"
#include "classes/CNetStats.h"
#include "classes/CObject.h"
#include "classes/CObjectPool.h"
#include "classes/CObjectSelection.h"
#include "classes/CPed.h"
#include "classes/CPickupPool.h"
#include "classes/CPlayerInfo.h"
#include "classes/CPlayerPool.h"
#include "classes/CPlayerTags.h"
#include "classes/CRect.h"
#include "classes/CRemotePlayer.h"
#include "classes/CScoreboard.h"
#include "classes/CSpawnScreen.h"
#include "classes/CTextDraw.h"
#include "classes/CTextDrawPool.h"
#include "classes/CTextDrawSelection.h"
#include "classes/CVector.h"
#include "classes/CVehicle.h"
#include "classes/CVehiclePool.h"
#include "classes/Commands.h"
#include "classes/ControllerState.h"
#include "classes/Debug.h"
#include "classes/DebugScript.h"
#include "classes/Exception.h"
#include "classes/GUI.h"
#include "classes/InputHandler.h"
#include "classes/KeyStuff.h"
#include "classes/RPC.h"
#include "classes/Scripting.h"
#include "classes/Settings.h"
#include "classes/SpecialAction.h"
#include "classes/VehicleSelection.h"

//plugin sdk
#pragma comment(lib, "plugin.lib")
#include "plugin.h"

#include "CPed.h"
#include "CWorld.h"
#include "CPopulation.h"
#include "CCivilianPed.h"
#include "CStats.h"
#include "CClothes.h"
#include "CCamera.h"
#include "CAnimManager.h"
#include "CStreaming.h"
#include "CRunningScript.h"
#include "CPlayerPed.h"
#include "CModelInfo.h"
#include "CDraw.h"
#include "CMenuManager.h"
#include "CClock.h"
#include "CWeather.h"
#include "CTaskSimpleRunNamedAnim.h"
#include "CTrailer.h"
#include "CGame.h"
#include "CCam.h"
#include "CTrailer.h"
#include "C3dMarker.h"
#include "C3dMarkers.h"
#include "CCheckpoint.h"
#include "CCheckpoints.h"
#include "CTaskSimpleJump.h"
#include "ePedBones.h"
#include "extensions/ScriptCommands.h"

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
struct stObject : public stSAMPEntity < object_info >
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

enum RPCEnumeration
{
	RPC_ClickPlayer = 23,
	RPC_ClientJoin = 25,
	RPC_EnterVehicle = 26,
	RPC_EnterEditObject = 27,
	RPC_ScriptCash = 31,
	RPC_ServerCommand = 50,
	RPC_Spawn = 52,
	RPC_Death = 53,
	RPC_NPCJoin = 54,
	RPC_DialogResponse = 62,
	RPC_ClickTextDraw = 83,
	RPC_ScmEvent = 96,
	RPC_WeaponPickupDestroy = 97,
	RPC_Chat = 101,
	RPC_SrvNetStats = 102,
	RPC_ClientCheck = 103,
	RPC_DamageVehicle = 106,
	RPC_GiveTakeDamage = 115,
	RPC_EditAttachedObject = 116,
	RPC_EditObject = 117,
	RPC_SetInteriorId = 118,
	RPC_MapMarker = 119,
	RPC_RequestClass = 128,
	RPC_RequestSpawn = 129,
	RPC_PickedUpPickup = 131,
	RPC_MenuSelect = 132,
	RPC_VehicleDestroyed = 136,
	RPC_MenuQuit = 140,
	RPC_ExitVehicle = 154,
	RPC_UpdateScoresPingsIPs = 155
};
enum ScriptRPCEnumeration
{
	RPC_ScrSetPlayerName = 11,
	RPC_ScrSetPlayerPos = 12,
	RPC_ScrSetPlayerPosFindZ = 13,
	RPC_ScrSetPlayerHealth = 14,
	RPC_ScrTogglePlayerControllable = 15,
	RPC_ScrPlaySound = 16,
	RPC_ScrSetPlayerWorldBounds = 17,
	RPC_ScrGivePlayerMoney = 18,
	RPC_ScrSetPlayerFacingAngle = 19,
	RPC_ScrResetPlayerMoney = 20,
	RPC_ScrResetPlayerWeapons = 21,
	RPC_ScrGivePlayerWeapon = 22,
	RPC_ScrSetVehicleParamsEx = 24,
	RPC_ScrCancelEdit = 28,
	RPC_ScrSetPlayerTime = 29,
	RPC_ScrToggleClock = 30,
	RPC_ScrWorldPlayerAdd = 32,
	RPC_ScrSetPlayerShopName = 33,
	RPC_ScrSetPlayerSkillLevel = 34,
	RPC_ScrSetPlayerDrunkLevel = 35,
	RPC_ScrCreate3DTextLabel = 36,
	RPC_ScrDisableCheckpoint = 37,
	RPC_ScrSetRaceCheckpoint = 38,
	RPC_ScrDisableRaceCheckpoint = 39,
	RPC_ScrGameModeRestart = 40,
	RPC_ScrPlayAudioStream = 41,
	RPC_ScrStopAudioStream = 42,
	RPC_ScrRemoveBuildingForPlayer = 43,
	RPC_ScrCreateObject = 44,
	RPC_ScrSetObjectPos = 45,
	RPC_ScrSetObjectRot = 46,
	RPC_ScrDestroyObject = 47,
	RPC_ScrDeathMessage = 55,
	RPC_ScrSetPlayerMapIcon = 56,
	RPC_ScrRemoveVehicleComponent = 57,
	RPC_ScrUpdate3DTextLabel = 58,
	RPC_ScrChatBubble = 59,
	RPC_ScrSomeupdate = 60,
	RPC_ScrShowDialog = 61,
	RPC_ScrDestroyPickup = 63,
	RPC_ScrLinkVehicleToInterior = 65,
	RPC_ScrSetPlayerArmour = 66,
	RPC_ScrSetPlayerArmedWeapon = 67,
	RPC_ScrSetSpawnInfo = 68,
	RPC_ScrSetPlayerTeam = 69,
	RPC_ScrPutPlayerInVehicle = 70,
	RPC_ScrRemovePlayerFromVehicle = 71,
	RPC_ScrSetPlayerColor = 72,
	RPC_ScrDisplayGameText = 73,
	RPC_ScrForceClassSelection = 74,
	RPC_ScrAttachObjectToPlayer = 75,
	RPC_ScrInitMenu = 76,
	RPC_ScrShowMenu = 77,
	RPC_ScrHideMenu = 78,
	RPC_ScrCreateExplosion = 79,
	RPC_ScrShowPlayerNameTagForPlayer = 80,
	RPC_ScrAttachCameraToObject = 81,
	RPC_ScrInterpolateCamera = 82,
	RPC_ScrSetObjectMaterial = 84,
	RPC_ScrGangZoneStopFlash = 85,
	RPC_ScrApplyAnimation = 86,
	RPC_ScrClearAnimations = 87,
	RPC_ScrSetPlayerSpecialAction = 88,
	RPC_ScrSetPlayerFightingStyle = 89,
	RPC_ScrSetPlayerVelocity = 90,
	RPC_ScrSetVehicleVelocity = 91,
	RPC_ScrClientMessage = 93,
	RPC_ScrSetWorldTime = 94,
	RPC_ScrCreatePickup = 95,
	RPC_ScrMoveObject = 99,
	RPC_ScrEnableStuntBonusForPlayer = 104,
	RPC_ScrTextDrawSetString = 105,
	RPC_ScrSetCheckpoint = 107,
	RPC_ScrGangZoneCreate = 108,
	RPC_ScrPlayCrimeReport = 112,
	RPC_ScrSetPlayerAttachedObject = 113,
	RPC_ScrGangZoneDestroy = 120,
	RPC_ScrGangZoneFlash = 121,
	RPC_ScrStopObject = 122,
	RPC_ScrSetNumberPlate = 123,
	RPC_ScrTogglePlayerSpectating = 124,
	RPC_ScrPlayerSpectatePlayer = 126,
	RPC_ScrPlayerSpectateVehicle = 127,
	RPC_ScrSetPlayerWantedLevel = 133,
	RPC_ScrShowTextDraw = 134,
	RPC_ScrTextDrawHideForPlayer = 135,
	RPC_ScrServerJoin = 137,
	RPC_ScrServerQuit = 138,
	RPC_ScrInitGame = 139,
	RPC_ScrRemovePlayerMapIcon = 144,
	RPC_ScrSetPlayerAmmo = 145,
	RPC_ScrSetGravity = 146,
	RPC_ScrSetVehicleHealth = 147,
	RPC_ScrAttachTrailerToVehicle = 148,
	RPC_ScrDetachTrailerFromVehicle = 149,
	RPC_ScrSetWeather = 152,
	RPC_ScrSetPlayerSkin = 153,
	RPC_ScrSetPlayerInterior = 156,
	RPC_ScrSetPlayerCameraPos = 157,
	RPC_ScrSetPlayerCameraLookAt = 158,
	RPC_ScrSetVehiclePos = 159,
	RPC_ScrSetVehicleZAngle = 160,
	RPC_ScrSetVehicleParamsForPlayer = 161,
	RPC_ScrSetCameraBehindPlayer = 162,
	RPC_ScrWorldPlayerRemove = 163,
	RPC_ScrWorldVehicleAdd = 164,
	RPC_ScrWorldVehicleRemove = 165,
	RPC_ScrWorldPlayerDeath = 166
};

namespace SAMP {

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
			struct stRakClientSend {
				RakClientInterface* _this;
				BitStream* bitStream;
				PacketPriority priority;
				PacketReliability reliability;
				char orderingChannel;
			};
			struct stRakClientRPC {
				RakClientInterface* _this;
				int* uniqueID;
				BitStream* bitStream;
				PacketPriority priority;
				PacketReliability reliability;
				char orderingChannel;
				bool shiftTimestamp;
			};
			struct stRakClientRPCRecv {
				unsigned __int32 rpc_id;
				BitStream* bitStream;
				//std::shared_ptr<RakNet::BitStream> bitStream;
			};
			struct stRakClientRecv {
				unsigned __int8 pktID;
				BitStream* bitStream;
				unsigned __int32 lenght;
			};
		}

		class CCallbackRegister {
		private:
#pragma pack(push, 1)
			struct PlayerID__
			{
				unsigned int binaryAddress;
				unsigned short port;
				PlayerID__& operator = (const PlayerID__& input)
				{
					binaryAddress = input.binaryAddress;
					port = input.port;
					return *this;
				}
				bool operator==(const PlayerID__& right) const;
				bool operator!=(const PlayerID__& right) const;
				bool operator > (const PlayerID__& right) const;
				bool operator < (const PlayerID__& right) const;
			};
			struct NetworkID__
			{
				bool peerToPeer;
				PlayerID__ playerId;
				unsigned short localSystemId;
			};
			struct Packet__
			{
				unsigned __int16 playerIndex;
				PlayerID__ playerId;
				unsigned int length;
				unsigned int bitSize;
				unsigned char* data;
				bool deleteData;
			};
#pragma pack(pop)

			using GameLoop_t = void(__cdecl*)();
			using WndProc_t = LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM);

			using D3DPresent_t = HRESULT(__stdcall*)(IDirect3DDevice9*, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
			using D3DReset_t = HRESULT(__stdcall*)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);

			using RakClientSend_t = bool(__thiscall*)(RakClientInterface*, BitStream*, PacketPriority, PacketReliability, char);
			using RakClientRPCSend_t = bool(__thiscall*)(RakClientInterface*, int*, BitStream*, PacketPriority, PacketReliability, char, bool);
			using RakPeerHandleRPCPacket_t = bool(__thiscall*)(RakPeerInterface*, const char*, int, PlayerID__);
			using RakPeerReceive_t = Packet__ * (__thiscall*)(RakPeerInterface*);
		public:
			typedef LRESULT(__stdcall* tWndProc)(HookedStructs::stWndProcParams*);
			typedef void(__stdcall* tGameLoop)();
			typedef HRESULT(__stdcall* tPresent_)(HookedStructs::stPresentParams*);
			typedef HRESULT(__stdcall* tReset_)(HookedStructs::stResetParams*);
			typedef bool(__stdcall* tRakClientSend_)(HookedStructs::stRakClientSend*);
			typedef bool(__stdcall* tRakClientRPC_)(HookedStructs::stRakClientRPC*);
			typedef bool(__stdcall* tRakClientRPCRecv_)(HookedStructs::stRakClientRPCRecv*);
			typedef bool(__stdcall* tRakPeerRecv_)(HookedStructs::stRakClientRecv*);

			CCallbackRegister(DWORD base) {
				sampBase = base;

				pWndProcHook = std::make_unique<memwrapper::memhook<WndProc_t>>(0x00747EB0U, WndProc_HOOKED);
				pGameLoopHook = std::make_unique<memwrapper::memhook<GameLoop_t>>(0x00748DA3U, GameLoop_HOOKED);
				pD3DPresentHook = std::make_unique<memwrapper::memhook<D3DPresent_t>>(GetDeviceAddress(17), D3DPresent_HOOKED);
				pD3DResetHook = std::make_unique<memwrapper::memhook<D3DReset_t>>(GetDeviceAddress(16), D3DReset_HOOKED);
				pRakClientSendHook = std::make_unique<memwrapper::memhook<RakClientSend_t>>(sampBase + 0x00307F0U, RakClientSend_HOOKED);
				pRakClientRPCSendHook = std::make_unique<memwrapper::memhook<RakClientRPCSend_t>>(sampBase + 0x0030B30U, RakClientRPCSend_HOOKED);
				pRakPeerHandleRPCPacketHook = std::make_unique<memwrapper::memhook<RakPeerHandleRPCPacket_t>>(sampBase + 0x00372F0U, RakPeerHandleRPCPacketHook_HOOKED);
				pRakPeerReceiveHook = std::make_unique<memwrapper::memhook<RakPeerReceive_t>>(sampBase + 0x0031180U, RakPeerReceive_HOOKED);


				pWndProcHook->install();
				pGameLoopHook->install();
				pD3DPresentHook->install();
				pD3DResetHook->install();
				pRakClientSendHook->install();
				pRakPeerReceiveHook->install();
				pRakClientRPCSendHook->install();
				pRakPeerHandleRPCPacketHook->install();
			}

			~CCallbackRegister() {
				pWndProcHook->remove();
				pGameLoopHook->remove();
				pD3DPresentHook->remove();
				pD3DResetHook->remove();
				pRakClientSendHook->remove();
				pRakPeerReceiveHook->remove();
				pRakClientRPCSendHook->remove();
				pRakPeerHandleRPCPacketHook->remove();
			}

			//сделать перегрузки

			void inline RegisterWndProcCallback(tWndProc func) { callWndProc = func; };
			void inline RegisterGameLoopCallback(tGameLoop func) { callGameLoop = func; };

			void inline RegisterD3DCallback(tPresent_ func) { callPresent = func; };
			void inline RegisterD3DCallback(tReset_ func) { callReset = func; };

			void inline RegisterRakClientCallback(tRakClientSend_ func) { callRakClientSend = func; };
			void inline RegisterRakClientCallback(tRakClientRPC_ func) { callRakClientRPC = func; };
			void inline RegisterRakClientCallback(tRakClientRPCRecv_ func) { callRakClientRPCRecv = func; };
			void inline RegisterRakClientCallback(tRakPeerRecv_ func) { callRakPeerRecv = func; };

			IDirect3DDevice9 inline* GetIDirect3DDevice9(void) { return pD3DDevice; };


			std::unique_ptr<memwrapper::memhook<GameLoop_t>> pGameLoopHook = 0;
			std::unique_ptr<memwrapper::memhook<WndProc_t>> pWndProcHook = 0;

			std::unique_ptr<memwrapper::memhook<D3DPresent_t>> pD3DPresentHook = 0;
			std::unique_ptr<memwrapper::memhook<D3DReset_t>> pD3DResetHook = 0;

			std::unique_ptr<memwrapper::memhook<RakClientSend_t>> pRakClientSendHook = 0;
			std::unique_ptr<memwrapper::memhook<RakClientRPCSend_t>> pRakClientRPCSendHook = 0;
			std::unique_ptr<memwrapper::memhook<RakPeerHandleRPCPacket_t>> pRakPeerHandleRPCPacketHook = 0;
			std::unique_ptr<memwrapper::memhook<RakPeerReceive_t>> pRakPeerReceiveHook = 0;
		private:

			IDirect3DDevice9* pD3DDevice = nullptr;
			bool isD3DHookInit = false;

			DWORD sampBase = 0;

			tWndProc callWndProc = 0;
			tGameLoop callGameLoop = 0;
			tPresent_ callPresent = 0;
			tReset_ callReset = 0;
			tRakClientSend_ callRakClientSend = 0;
			tRakClientRPC_ callRakClientRPC = 0;
			tRakClientRPCRecv_ callRakClientRPCRecv = 0;
			tRakPeerRecv_ callRakPeerRecv = 0;

			static LRESULT __stdcall WndProc_HOOKED(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
			static void __cdecl GameLoop_HOOKED();
			static HRESULT __stdcall D3DPresent_HOOKED(IDirect3DDevice9* pDevice, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion);
			static HRESULT __stdcall D3DReset_HOOKED(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentParams);
			static bool __fastcall RakClientSend_HOOKED(RakClientInterface* _this, void* Unknown, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel);
			static bool __fastcall RakClientRPCSend_HOOKED(RakClientInterface* _this, void* Unknown, int* uniqueID, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp);
			static bool __fastcall RakPeerHandleRPCPacketHook_HOOKED(RakPeerInterface* _this, void* Unknown, const char* data, int length, SAMP::CallBacks::CCallbackRegister::PlayerID__ playerid);
			static SAMP::CallBacks::CCallbackRegister::Packet__* __fastcall RakPeerReceive_HOOKED(RakPeerInterface* _this, void* Unknown);

			template<typename result, typename source>
			result pointer_cast(source* v)
			{
				return static_cast<result>(static_cast<void*>(v));
			}
			template<typename result, typename source>
			result pointer_cast(const source* v)
			{
				return static_cast<result>(static_cast<const void*>(v));
			}

			DWORD FindDevice(DWORD dwLen)
			{
				DWORD dwObjBase = 0;
				char infoBuf[MAX_PATH];
				GetSystemDirectoryA(infoBuf, MAX_PATH);
				strcat_s(infoBuf, MAX_PATH, "\\d3d9.dll");
				dwObjBase = (DWORD)LoadLibraryA(infoBuf);
				while (dwObjBase++ < dwObjBase + dwLen)
				{
					if (
						(*(WORD*)(dwObjBase + 0x00)) == 0x06C7 &&
						(*(WORD*)(dwObjBase + 0x06)) == 0x8689 &&
						(*(WORD*)(dwObjBase + 0x0C)) == 0x8689
						)
					{
						dwObjBase += 2; break;
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

		CCallbackRegister* pCallBackRegister = nullptr;
	}

	class CRakNet
	{
	private:
		RakClientInterface* pRakClientInterface = nullptr;
		RakPeerInterface* pRakPeerInterface = nullptr;
#pragma pack(push, 1)
		struct PlayerID__
		{
			unsigned int binaryAddress;
			unsigned short port;
			PlayerID__& operator = (const PlayerID__& input)
			{
				binaryAddress = input.binaryAddress;
				port = input.port;
				return *this;
			}
			bool operator==(const PlayerID__& right) const;
			bool operator!=(const PlayerID__& right) const;
			bool operator > (const PlayerID__& right) const;
			bool operator < (const PlayerID__& right) const;
		};
		struct NetworkID__
		{
			bool peerToPeer;
			PlayerID__ playerId;
			unsigned short localSystemId;
		};
		struct Packet__
		{
			unsigned __int16 playerIndex;
			PlayerID__ playerId;
			unsigned int length;
			unsigned int bitSize;
			unsigned char* data;
			bool deleteData;
		};
#pragma pack(pop)
		unsigned __int32 sampBase = 0;
		RakPeerInterface* pRakPeerInterface1;
		PlayerID__ plID1;
	public:

		CRakNet(RakClientInterface *_interface, RakPeerInterface* _rinterface) {
			this->pRakClientInterface = _interface;
			this->pRakPeerInterface = _rinterface;
			sampBase = (unsigned __int32)GetModuleHandleA("samp.dll");
		}
		~CRakNet() {
			this->pRakClientInterface = nullptr;
			this->pRakPeerInterface = nullptr;
			this->pRakPeerInterface1 = nullptr;
		}
		//DONT CALL THIS FUNCTION!!!
		void InitAPIRakNet(RakPeerInterface* pRak, void* plID) {
			pRakPeerInterface1 = pRak;
			plID1 = *(PlayerID__*)plID;
		};
		RakClientInterface *GetRakClientInterface(void) {
			return this->pRakClientInterface;
		}
		RakPeerInterface *GetRakPeerInterface(void) {
			return this->pRakPeerInterface;
		}
		bool Send(RakNet::BitStream *bitStream, PacketPriority priority = HIGH_PRIORITY, PacketReliability reliability = PacketReliability::RELIABLE_ORDERED, char orderingChannel = '\0') {
			return this->pRakClientInterface->Send(bitStream, priority, reliability, orderingChannel);
		};
		bool Send(const char *data, const int length, PacketPriority priority = HIGH_PRIORITY, PacketReliability reliability = PacketReliability::RELIABLE_ORDERED, char orderingChannel = '\0') {
			return this->pRakClientInterface->Send(data, length, priority, reliability, orderingChannel);
		};
		bool SendRPC(int RPC_ID, RakNet::BitStream *bitStream, PacketPriority priority = HIGH_PRIORITY, PacketReliability reliability = PacketReliability::RELIABLE_ORDERED, char orderingChannel = '\0', bool shiftTimestamp = false, NetworkID networkID = UNASSIGNED_NETWORK_ID, RakNet::BitStream *replyFromTarget = 0) {
			return this->pRakClientInterface->RPC(&RPC_ID, bitStream, priority, reliability, orderingChannel, shiftTimestamp, networkID, replyFromTarget);
		}
		bool SendRPC(int RPC_ID, const char* data, unsigned int bitLength, PacketPriority priority = HIGH_PRIORITY, PacketReliability reliability = PacketReliability::RELIABLE_ORDERED, char orderingChannel = '\0', bool shiftTimestamp = false, NetworkID networkID = UNASSIGNED_NETWORK_ID, RakNet::BitStream* replyFromTarget = 0) {
			return this->pRakClientInterface->RPC(&RPC_ID, data, bitLength, priority, reliability, orderingChannel, shiftTimestamp, networkID, replyFromTarget);
		};
		bool EmulRPC(unsigned __int8 rpcID, RakNet::BitStream* bitStream) {
			RakNet::BitStream bs_;
			bs_.Write<unsigned char>(ID_RPC);
			bs_.Write(rpcID);
			bs_.WriteCompressed<unsigned int>(BYTES_TO_BITS(bitStream->GetNumberOfBytesUsed()));
			bs_.WriteBits(bitStream->GetData(), BYTES_TO_BITS(bitStream->GetNumberOfBytesUsed()), false);
			//<RakPeerInterface*, const char*, int, PlayerID__>(_this, reinterpret_cast<char*>(incoming.GetData()), incoming.GetNumberOfBytesUsed(), playerid);
			return SAMP::CallBacks::pCallBackRegister->pRakPeerHandleRPCPacketHook->call<RakPeerInterface*, const char*, int, PlayerID__>(pRakPeerInterface1, reinterpret_cast<char*>(bs_.GetData()), bs_.GetNumberOfBytesUsed(), plID1);
		};
		bool EmulPacket(RakNet::BitStream* bitStream) {
			Packet__* send_packet = reinterpret_cast<Packet__ * (*)(size_t)>(sampBase + 0x347e0)(bitStream->GetNumberOfBytesUsed());
			memcpy(send_packet->data, bitStream->GetData(), send_packet->length);

			// RakPeer::AddPacketToProducer
			char* packets = reinterpret_cast<char*>(pRakPeerInterface) + 0xdb6;
			auto write_lock = reinterpret_cast<Packet__ * *(__thiscall*)(void*)>(sampBase + 0x35b10);
			auto write_unlock = reinterpret_cast<void(__thiscall*)(void*)>(sampBase + 0x35b50);

			*write_lock(packets) = send_packet;
			write_unlock(packets);

			return true;
		};
	};

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

			g_RakNet = new CRakNet(g_SAMP->pRakClientInterface, g_SAMP->pRakPeerInterface);

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
		struct stStreamedOutPlayerInfo *getStreamedOutPlayerInfo(void) { return g_StreamedOutPlayerInfo; };
		class CRakNet *getRakNet(void) { return g_RakNet; };
		
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
			delete g_StreamedOutPlayerInfo;
			g_StreamedOutPlayerInfo = nullptr;
			delete g_RakNet;
			g_RakNet = nullptr;
		};
		CSAMP(DWORD base) { sampAddr = base; g_StreamedOutPlayerInfo = new stStreamedOutPlayerInfo; };
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
		struct stStreamedOutPlayerInfo *g_StreamedOutPlayerInfo = 0;
		class CRakNet *g_RakNet = 0;
		
	};
	
	CSAMP *pSAMP = nullptr;

	

	void ShutDown(void) {
		delete SAMP::CallBacks::pCallBackRegister;
		delete SAMP::pSAMP;
		SAMP::CallBacks::pCallBackRegister = nullptr;
		SAMP::pSAMP = nullptr;
	}
	
	void Init(void) {
		DWORD base = (DWORD)GetModuleHandleA("samp.dll");
		SAMP::pSAMP = new SAMP::CSAMP(base);
		SAMP::CallBacks::pCallBackRegister = new SAMP::CallBacks::CCallbackRegister(base);
	}

	bool bKeyTable[256];
#pragma warning(disable:6282)
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
#pragma warning(default:6282)
}
#pragma pack(push, 1)
CPed* stPlayerPool::GetCPedFromPlayerID(uint32_t playerID) {
	if (playerID < 0 || playerID > 1000)
		return 0;
	if (playerID == SAMP::pSAMP->getPlayers()->sLocalPlayerID)
		return CPools::GetPed(SAMP::pSAMP->getPlayers()->pLocalPlayer->pSAMP_Actor->ulGTAEntityHandle);
	else return CPools::GetPed(SAMP::pSAMP->getPlayers()->pRemotePlayer[playerID]->pPlayerData->pSAMP_Actor->ulGTAEntityHandle);
	return 0;
}
actor_info* stPlayerPool::GetActorInfoFromPlayerID(uint32_t playerID) {
	if (playerID < 0 || playerID > 1000)
		return 0;
	if (playerID == SAMP::pSAMP->getPlayers()->sLocalPlayerID)
		return SAMP::pSAMP->getPlayers()->pLocalPlayer->pSAMP_Actor->pGTA_Ped;
	else return SAMP::pSAMP->getPlayers()->pRemotePlayer[playerID]->pPlayerData->pSAMP_Actor->pGTA_Ped;
	return 0;
}
bool stPlayerPool::IsPlayerStreamed(uint16_t playerID) {
	if (SAMP::pSAMP->getPlayers() == NULL)
		return false;
	if (SAMP::pSAMP->getPlayers()->iIsListed[playerID] != 1)
		return false;
	if (SAMP::pSAMP->getPlayers()->pRemotePlayer[playerID] == NULL)
		return false;
	if (SAMP::pSAMP->getPlayers()->pRemotePlayer[playerID]->pPlayerData == NULL)
		return false;
	if (SAMP::pSAMP->getPlayers()->pRemotePlayer[playerID]->pPlayerData->pSAMP_Actor == NULL)
		return false;

	return true;
}
D3DCOLOR stPlayerPool::GetPlayerColor(uint16_t playerID) {
	D3DCOLOR* dwColor;
	if (playerID < 0 || playerID >= (SAMP_MAX_PLAYERS + 3))
		return D3DCOLOR_ARGB(0xFF, 0x99, 0x99, 0x99);

	switch (playerID)
	{
	case (SAMP_MAX_PLAYERS):
		return 0xFF888888;

	case (SAMP_MAX_PLAYERS + 1):
		return 0xFF0000AA;

	case (SAMP_MAX_PLAYERS + 2):
		return 0xFF63C0E2;
	}

	dwColor = (D3DCOLOR*)((uint8_t*)SAMP::pSAMP->GetBase() + 0x216378);
	return D3DCOLOR_RGBA(dwColor[playerID] >> 8, dwColor[playerID] >> 16, dwColor[playerID] >> 24, 255);
}
bool stVehiclePool::IsVehicleStreamed(uint16_t vehicleID) {
	if (SAMP::pSAMP->getVehicles()->iIsListed[vehicleID] != 1)
		return false;
	if (SAMP::pSAMP->getVehicles()->pSAMP_Vehicle[vehicleID] == NULL)
		return false;
	if (SAMP::pSAMP->getVehicles()->pSAMP_Vehicle[vehicleID]->pGTA_Vehicle == NULL)
		return false;
	return true;
}
#pragma warning(disable:6385)
CVehicle* stVehiclePool::GetCVehicleFromSAMPVehicleID(uint16_t vehicleID) {
	if (vehicleID < 0 || vehicleID > 2000)
		return 0;
	else return CPools::GetVehicle(SAMP::pSAMP->getVehicles()->pSAMP_Vehicle[vehicleID]->ulGTAEntityHandle);
	return nullptr;
}
vehicle_info* stVehiclePool::GetVehicleInfoFromSAMPVehicleID(uint16_t vehicleID) {
	if (vehicleID < 0 || vehicleID > 2000)
		return 0;
	else return SAMP::pSAMP->getVehicles()->pSAMP_Vehicle[vehicleID]->pGTA_Vehicle;
	return nullptr;
}
#pragma warning(default:6385)
#pragma pack(pop)

SAMP::CallBacks::CCallbackRegister::Packet__* __fastcall SAMP::CallBacks::CCallbackRegister::RakPeerReceive_HOOKED(RakPeerInterface *_this, void *Unknown) {
	SAMP::CallBacks::CCallbackRegister::Packet__ *packet = SAMP::CallBacks::pCallBackRegister->pRakPeerReceiveHook->call<RakPeerInterface*>(_this);

	if (packet != nullptr && packet->data != nullptr && packet->bitSize != 0 && packet->length != 0)
	{
		if (packet->data[0] == ID_MARKERS_SYNC) // packetId
		{
			BitStream	bs(packet->data, packet->length, true);
			int			iNumberOfPlayers = 0;
			uint16_t	playerID = uint16_t(-1);
			short		sPos[3] = { 0, 0, 0 };
			bool		bIsPlayerActive = false;

			bs.IgnoreBits(8);
			bs.Read(iNumberOfPlayers);
			if (iNumberOfPlayers >= 0 || iNumberOfPlayers <= SAMP_MAX_PLAYERS) {
				for (int i = 0; i < iNumberOfPlayers; i++)
				{
					bs.Read(playerID);
					bs.ReadCompressed(bIsPlayerActive);
					if (bIsPlayerActive == 0)
						continue;
					
					bs.Read(sPos);
					SAMP::pSAMP->getStreamedOutPlayerInfo()->iPlayerID[playerID] = playerID;
					SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[playerID][0] = sPos[0];
					SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[playerID][1] = sPos[1];
					SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[playerID][2] = sPos[2];
				}
			}
		}

		if (SAMP::CallBacks::pCallBackRegister->callRakPeerRecv != 0) {
			HookedStructs::stRakClientRecv params = { 0 };
			BitStream *bs = new BitStream(packet->data, packet->length, true);
			params.bitStream = bs;
			params.lenght = packet->length;
			params.pktID = packet->data[0];
			bool retn = SAMP::CallBacks::pCallBackRegister->callRakPeerRecv(&params);
			packet->data = bs->GetData();
			packet->bitSize = bs->GetNumberOfBitsUsed();
			packet->length = bs->GetNumberOfBytesUsed();
			delete bs;
			if (!retn)
				return nullptr;
		}
	}

	return packet;
}
bool __fastcall SAMP::CallBacks::CCallbackRegister::RakPeerHandleRPCPacketHook_HOOKED(RakPeerInterface *_this, void *Unknown, const char *data, int length, SAMP::CallBacks::CCallbackRegister::PlayerID__ playerid) {
	RakNet::BitStream incoming(SAMP::CallBacks::pCallBackRegister->pointer_cast<unsigned char*>(const_cast<char*>(data)), length, true);//from rakhook by imring
	unsigned char id = 0;
	unsigned char* input = nullptr;
	unsigned int bits_data = 0;
	std::unique_ptr<RakNet::BitStream> callback_bs = std::make_unique<RakNet::BitStream>();

	static bool isInitInterface = false;
	if (!isInitInterface) {
		isInitInterface = true;
		SAMP::pSAMP->getRakNet()->InitAPIRakNet(_this, (void*)&playerid);
	}


	incoming.IgnoreBits(8);
	if (data[0] == ID_TIMESTAMP)
		incoming.IgnoreBits(8 * (sizeof(RakNetTime) + sizeof(unsigned char)));

	int offset = incoming.GetReadOffset();
	incoming.Read(id);

	if (!incoming.ReadCompressed(bits_data))
		return false;

	if (bits_data) {
		bool used_alloca = false;
		if (BITS_TO_BYTES(incoming.GetNumberOfUnreadBits()) < MAX_ALLOCA_STACK_ALLOCATION) {
			input = SAMP::CallBacks::pCallBackRegister->pointer_cast<unsigned char*>(_malloca(BITS_TO_BYTES(incoming.GetNumberOfUnreadBits())));
			used_alloca = true;
		}
		else input = new unsigned char[BITS_TO_BYTES(incoming.GetNumberOfUnreadBits())];

		if (!incoming.ReadBits(input, bits_data, false))
			return false;

		callback_bs = std::make_unique<RakNet::BitStream>(input, BITS_TO_BYTES(bits_data), true);

		if (!used_alloca)
			delete[] input;
	}

	if (SAMP::CallBacks::pCallBackRegister->callRakClientRPCRecv != 0) {
		HookedStructs::stRakClientRPCRecv params = { 0 };
		params.bitStream = callback_bs.get();
		params.rpc_id = id;
		bool retn = SAMP::CallBacks::pCallBackRegister->callRakClientRPCRecv(&params);
		id = params.rpc_id;
		if (!retn)
			return false;
	}
	
	incoming.SetWriteOffset(offset);
	incoming.Write(id);
	bits_data = BYTES_TO_BITS(callback_bs->GetNumberOfBytesUsed());
	incoming.WriteCompressed(bits_data);
	if (bits_data)
		incoming.WriteBits(callback_bs->GetData(), bits_data, false);

	return SAMP::CallBacks::pCallBackRegister->pRakPeerHandleRPCPacketHook->call<RakPeerInterface*, const char*, int, PlayerID__>(_this, reinterpret_cast<char*>(incoming.GetData()), incoming.GetNumberOfBytesUsed(), playerid);
}
bool __fastcall SAMP::CallBacks::CCallbackRegister::RakClientRPCSend_HOOKED(RakClientInterface* _this, void* Unknown, int* uniqueID, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp) {
	if (_this == nullptr || uniqueID == nullptr || bitStream == nullptr)
		return SAMP::CallBacks::pCallBackRegister->pRakClientRPCSendHook->call<RakClientInterface*, int*, BitStream*, PacketPriority, PacketReliability, char, bool>(_this, uniqueID, bitStream, priority, reliability, orderingChannel, shiftTimestamp);

	if (SAMP::CallBacks::pCallBackRegister->callRakClientRPC != 0) {
		HookedStructs::stRakClientRPC params = { 0 };
		params.bitStream = bitStream;
		params.orderingChannel = orderingChannel;
		params.priority = priority;
		params.reliability = reliability;
		params.shiftTimestamp = shiftTimestamp;
		params.uniqueID = uniqueID;
		params._this = _this;
		bool retn = SAMP::CallBacks::pCallBackRegister->callRakClientRPC(&params);
		bitStream = params.bitStream;
		orderingChannel = params.orderingChannel;
		priority = params.priority;
		reliability = params.reliability;
		shiftTimestamp = params.shiftTimestamp;
		uniqueID = params.uniqueID;
		_this = params._this;
		if (!retn)
			return false;
	}

	return SAMP::CallBacks::pCallBackRegister->pRakClientRPCSendHook->call<RakClientInterface*, int*, BitStream*, PacketPriority, PacketReliability, char, bool>(_this, uniqueID, bitStream, priority, reliability, orderingChannel, shiftTimestamp);
}
bool __fastcall SAMP::CallBacks::CCallbackRegister::RakClientSend_HOOKED(RakClientInterface* _this, void* Unknown, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel) {
	if(_this == nullptr || bitStream == nullptr)
		return SAMP::CallBacks::pCallBackRegister->pRakClientSendHook->call<RakClientInterface*, BitStream*, PacketPriority, PacketReliability, char>(_this, bitStream, priority, reliability, orderingChannel);

	if (SAMP::CallBacks::pCallBackRegister->callRakClientSend != 0) {
		HookedStructs::stRakClientSend params = { 0 };
		params.bitStream = bitStream;
		params.orderingChannel = orderingChannel;
		params.priority = priority;
		params.reliability = reliability;
		params._this = _this;
		bool retn = SAMP::CallBacks::pCallBackRegister->callRakClientSend(&params);
		bitStream = params.bitStream;
		orderingChannel = params.orderingChannel;
		priority = params.priority;
		reliability = params.reliability;
		_this = params._this;
		if (!retn)
			return false;
	}

	return SAMP::CallBacks::pCallBackRegister->pRakClientSendHook->call<RakClientInterface*, BitStream*, PacketPriority, PacketReliability, char>(_this, bitStream, priority, reliability, orderingChannel);
}
HRESULT __stdcall SAMP::CallBacks::CCallbackRegister::D3DPresent_HOOKED(IDirect3DDevice9* pDevice, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion) {
	if(pDevice == nullptr)
		return SAMP::CallBacks::pCallBackRegister->pD3DPresentHook->call<IDirect3DDevice9*, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*>(pDevice, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
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

	return SAMP::CallBacks::pCallBackRegister->pD3DPresentHook->call<IDirect3DDevice9*, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*>(pDevice, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
}
HRESULT __stdcall SAMP::CallBacks::CCallbackRegister::D3DReset_HOOKED(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentParams) {
	if (pDevice == nullptr)
		return SAMP::CallBacks::pCallBackRegister->pD3DResetHook->call<IDirect3DDevice9*, D3DPRESENT_PARAMETERS*>(pDevice, pPresentParams);
	
	if (SAMP::CallBacks::pCallBackRegister->callReset != 0) {
		HookedStructs::stResetParams params = { 0 };
		params.pDevice = pDevice;
		params.pPresentParams = pPresentParams;
		HRESULT retn = SAMP::CallBacks::pCallBackRegister->callReset(&params);
		pDevice = params.pDevice;
		pPresentParams = params.pPresentParams;
		if (retn != D3D_OK)
			return retn;
	}

	return SAMP::CallBacks::pCallBackRegister->pD3DResetHook->call<IDirect3DDevice9*, D3DPRESENT_PARAMETERS*>(pDevice, pPresentParams);
}
void __cdecl SAMP::CallBacks::CCallbackRegister::GameLoop_HOOKED() {
	if (SAMP::CallBacks::pCallBackRegister->callGameLoop != 0) {
		SAMP::CallBacks::pCallBackRegister->callGameLoop();
	}
	return SAMP::CallBacks::pCallBackRegister->pGameLoopHook->call<>();
}
LRESULT __stdcall SAMP::CallBacks::CCallbackRegister::WndProc_HOOKED(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
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
	return SAMP::CallBacks::pCallBackRegister->pWndProcHook->call<HWND, UINT, WPARAM, LPARAM>(hWnd, uMsg, wParam, lParam);
}

