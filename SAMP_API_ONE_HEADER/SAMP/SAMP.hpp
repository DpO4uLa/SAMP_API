#pragma once

#include <Windows.h>
#include <process.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <functional>

#if defined (SAMP_R1_COMPILE)
#pragma message ("Target SA-MP version is 0.3.7-R1")
#elif defined (SAMP_R3_COMPILE)
#pragma message ("Target SA-MP version is 0.3.7-R3-1")
#endif

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
#include "classes/R1/AimStuff_R1.h"
#include "classes/R1/Animation_R1.h"
#include "classes/R1/CActor_R1.h"
#include "classes/R1/CActorPool_R1.h"
#include "classes/R1/CAudio_R1.h"
#include "classes/R1/CAudioStream_R1.h"
#include "classes/R1/CCamera_R1.h"
#include "classes/R1/CChat_R1.h"
#include "classes/R1/CConfig_R1.h"
#include "classes/R1/CDeathWindow_R1.h"
#include "classes/R1/CDialog_R1.h"
#include "classes/R1/CEntity_R1.h"
#include "classes/R1/CFonts_R1.h"
#include "classes/R1/CGame_R1.h"
#include "classes/R1/CGangZonePool_R1.h"
#include "classes/R1/CHttpClient_R1.h"
#include "classes/R1/CInput_R1.h"
#include "classes/R1/CLabel_R1.h"
#include "classes/R1/CLabelPool_R1.h"
#include "classes/R1/CLicensePlate_R1.h"
#include "classes/R1/CLocalPlayer_R1.h"
#include "classes/R1/CMatrix_R1.h"
#include "classes/R1/CMenu_R1.h"
#include "classes/R1/CMenuPool_R1.h"
#include "classes/R1/CNetGame_R1.h"
#include "classes/R1/CNetStats_R1.h"
#include "classes/R1/CObject_R1.h"
#include "classes/R1/CObjectPool_R1.h"
#include "classes/R1/CObjectSelection_R1.h"
#include "classes/R1/CPed_R1.h"
#include "classes/R1/CPickupPool_R1.h"
#include "classes/R1/CPlayerInfo_R1.h"
#include "classes/R1/CPlayerPool_R1.h"
#include "classes/R1/CPlayerTags_R1.h"
#include "classes/R1/CRect_R1.h"
#include "classes/R1/CRemotePlayer_R1.h"
#include "classes/R1/CScoreboard_R1.h"
#include "classes/R1/CSpawnScreen_R1.h"
#include "classes/R1/CTextDraw_R1.h"
#include "classes/R1/CTextDrawPool_R1.h"
#include "classes/R1/CTextDrawSelection_R1.h"
#include "classes/R1/CVector_R1.h"
#include "classes/R1/CVehicle_R1.h"
#include "classes/R1/CVehiclePool_R1.h"
#include "classes/R1/Commands_R1.h"
#include "classes/R1/ControllerState_R1.h"
#include "classes/R1/Debug_R1.h"
#include "classes/R1/DebugScript_R1.h"
#include "classes/R1/Exception_R1.h"
#include "classes/R1/GUI_R1.h"
#include "classes/R1/InputHandler_R1.h"
#include "classes/R1/KeyStuff_R1.h"
#include "classes/R1/RPC_R1.h"
#include "classes/R1/Scripting_R1.h"
#include "classes/R1/Settings_R1.h"
#include "classes/R1/SpecialAction_R1.h"
#include "classes/R1/VehicleSelection_R1.h"

#include "classes/R3/AimStuff_R3.h"
#include "classes/R3/Animation_R3.h"
#include "classes/R3/CActor_R3.h"
#include "classes/R3/CActorPool_R3.h"
#include "classes/R3/CAudio_R3.h"
#include "classes/R3/CAudioStream_R3.h"
#include "classes/R3/CCamera_R3.h"
#include "classes/R3/CChat_R3.h"
#include "classes/R3/CConfig_R3.h"
#include "classes/R3/CDeathWindow_R3.h"
#include "classes/R3/CDialog_R3.h"
#include "classes/R3/CEntity_R3.h"
#include "classes/R3/CFonts_R3.h"
#include "classes/R3/CGame_R3.h"
#include "classes/R3/CGangZonePool_R3.h"
#include "classes/R3/CHttpClient_R3.h"
#include "classes/R3/CInput_R3.h"
#include "classes/R3/CLabel_R3.h"
#include "classes/R3/CLabelPool_R3.h"
#include "classes/R3/CLicensePlate_R3.h"
#include "classes/R3/CLocalPlayer_R3.h"
#include "classes/R3/CMatrix_R3.h"
#include "classes/R3/CMenu_R3.h"
#include "classes/R3/CMenuPool_R3.h"
#include "classes/R3/CNetGame_R3.h"
#include "classes/R3/CNetStats_R3.h"
#include "classes/R3/CObject_R3.h"
#include "classes/R3/CObjectPool_R3.h"
#include "classes/R3/CObjectSelection_R3.h"
#include "classes/R3/CPed_R3.h"
#include "classes/R3/CPickupPool_R3.h"
#include "classes/R3/CPlayerInfo_R3.h"
#include "classes/R3/CPlayerPool_R3.h"
#include "classes/R3/CPlayerTags_R3.h"
#include "classes/R3/CRect_R3.h"
#include "classes/R3/CRemotePlayer_R3.h"
#include "classes/R3/CScoreboard_R3.h"
#include "classes/R3/CSpawnScreen_R3.h"
#include "classes/R3/CTextDraw_R3.h"
#include "classes/R3/CTextDrawPool_R3.h"
#include "classes/R3/CTextDrawSelection_R3.h"
#include "classes/R3/CVector_R3.h"
#include "classes/R3/CVehicle_R3.h"
#include "classes/R3/CVehiclePool_R3.h"
#include "classes/R3/Commands_R3.h"
#include "classes/R3/ControllerState_R3.h"
#include "classes/R3/DebugScript_R3.h"
#include "classes/R3/Exception_R3.h"
#include "classes/R3/GUI_R3.h"
#include "classes/R3/KeyStuff_R3.h"
#include "classes/R3/Scripting_R3.h"
#include "classes/R3/Settings_R3.h"
#include "classes/R3/SpecialAction_R3.h"

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
#include "CMessages.h"
#include "ePedBones.h"
#include "extensions/ScriptCommands.h"


#if defined (SAMP_R1_COMPILE)
//pointers to structs
#define SAMP_INFO_OFFSET				0x21A0F8U
#define SAMP_CHAT_INFO_OFFSET 			0x21A0E4U
#define SAMP_CHAT_INPUT_INFO_OFFSET		0x21A0E8U
#define SAMP_KILL_INFO_OFFSET			0x21A0ECU
#define SAMP_DIALOG_INFO_OFFSET 		0x21A0B8U
#define SAMP_MISC_INFO_OFFSET			0x21A10CU
#define SAMP_SCOREBOARD_INFO_OFFSET		0x21A0B4U
//hooks addresses
#define SAMP_RAKCLIENT_SEND				0x00307F0U
#define SAMP_RAKCLIENT_RPC_SEND			0x0030B30U
#define SAMP_RAKPEER_HANDLE_RPC_PACKET	0x00372F0U
#define SAMP_RAKPEER_RECEIVE			0x0031180U
#elif defined (SAMP_R3_COMPILE)
//pointers to structs
#define SAMP_INFO_OFFSET				0x26E8DCU
#define SAMP_CHAT_INFO_OFFSET 			0x26E8C8U
#define SAMP_CHAT_INPUT_INFO_OFFSET		0x26E8CCU
#define SAMP_KILL_INFO_OFFSET			0x26E8D0U
#define SAMP_DIALOG_INFO_OFFSET 		0x26E898U
#define SAMP_MISC_INFO_OFFSET			0x26E8F4U
#define SAMP_SCOREBOARD_INFO_OFFSET		0x26E894U
//hooks address
#define SAMP_RAKCLIENT_SEND				0x0033BA0U
#define SAMP_RAKCLIENT_RPC_SEND			0x0033EE0U
#define SAMP_RAKPEER_HANDLE_RPC_PACKET	0x003A6A0U
#define SAMP_RAKPEER_RECEIVE			0x0034530U
#endif

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

#if defined (SAMP_R1_COMPILE)
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
	//SAMP_MAX_PLAYERS = 1004,
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
#elif defined (SAMP_R3_COMPILE)
enum
{
	DIALOG_STYLE_MSGBOX = 0,
	DIALOG_STYLE_INPUT = 1,
	DIALOG_STYLE_LIST = 2,
	DIALOG_STYLE_PASSWORD = 3,
	DIALOG_STYLE_TABLIST = 4,
	DIALOG_STYLE_TABLIST_HEADERS = 5
};
enum
{
	SAMP_MAX_ACTORS = 1000,
	//SAMP_MAX_PLAYERS = 1004,
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
	SAMP_MAX_ACCESSORIES = 10,
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
	GAMESTATE_NONE = 0,
	GAMESTATE_WAIT_CONNECT = 1,
	GAMESTATE_DISCONNECTED = 2,
	GAMESTATE_AWAIT_JOIN = 6,
	GAMESTATE_CONNECTED = 5,
	GAMESTATE_RESTARTING = 11,
};
enum
{
	PLAYER_STATE_NONE = 0,
	PLAYER_STATE_ONFOOT = 17,
	PLAYER_STATE_PASSENGER = 18,
	PLAYER_STATE_DRIVER = 19,
	PLAYER_STATE_WASTED = 32,
	PLAYER_STATE_SPAWNED = 33
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
#endif
#if defined (SAMP_R1_COMPILE)
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
#elif defined (SAMP_R3_COMPILE)
#pragma pack(push, 1)
struct stSAMP
{
public:
	RakPeerInterface* pRakPeerInterface;
private:
	char unk[40];
public:
	RakClientInterface* pRakClientInterface;
	char szIP[257];
	char szHostname[257];
	bool disableCollision;//r3 only
	bool updateCameraTarget;//r3 only
	bool nametagStatus;//r3 only
	uint32_t ulPort;
	BOOL iLanMode;
	uint32_t ulMapIcons[100];
	int iGameState;
	uint32_t ulConnectTick;
	struct stServerPresets* pSettings;
private:
	char unk2[5];
public:
	struct stSAMPPools* pPools;
};
struct stServerPresets
{
	uint8_t byteCJWalk;
	unsigned int deadDropsMoney;
	float fWorldBoundaries[4];
	bool allowWeapons;
	float fGravity;
	uint8_t byteDisableInteriorEnterExits;
	uint32_t ulVehicleFriendlyFire;
	bool holdTime;
	bool instagib;
	bool zoneNames;
	bool friendlyFire;
	BOOL iClassesAvailable;
	float fNameTagsDistance;
	bool manualVehicleEngineAndLight;
	uint8_t byteWorldTime_Hour;
	uint8_t byteWorldTime_Minute;
	uint8_t byteWeather;
	uint8_t byteNoNametagsBehindWalls;
	uint8_t bytePlayerMarkersMode;
private:
	uint8_t unkk[3];
public:
	float fGlobalChatRadiusLimit;
	uint8_t byteShowNameTags;
	//only 037-r3 ??
	bool ltdChatRadius;
};
struct stTextDrawTransmit
{
	union {
		struct {
			BYTE byteBox : 1;
			BYTE byteLeft : 1;
			BYTE byteRight : 1;
			BYTE byteCenter : 1;
			BYTE byteProportional : 1;
			BYTE bytePadding : 3;
		};
		BYTE byteFlags;
	};
	float fLetterWidth;
	float fLetterHeight;
	uint32_t dwLetterColor;
	float fBoxWidth;
	float fBoxHeight;
	uint32_t dwBoxColor;
	uint8_t byteShadow;
	uint8_t byteOutline;
	uint32_t dwBackgroundColor;
	uint8_t byteStyle;
	uint8_t byteUNK;
	float fX;
	float fY;
	uint16_t sModel;
	float fRot[3];
	float fZoom;
	uint16_t sColor[2];
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
	struct stTextdraw* textdraw[SAMP_MAX_TEXTDRAWS];
	struct stTextdraw* playerTextdraw[SAMP_MAX_PLAYERTEXTDRAWS];
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
	uint32_t MaxPlayerID;
	struct stRemotePlayer* pRemotePlayer[SAMP_MAX_PLAYERS];
	int iIsListed[SAMP_MAX_PLAYERS];
	uint32_t prevCollisionFlag[SAMP_MAX_PLAYERS];
	int iLocalPlayerPing;
	int iLocalPlayerScore;
	uint16_t sLocalPlayerID;
private:
	int __align;
public:
	//char	szLocalPlayerName[16];
	std::string LocalPlayerName;
	struct stLocalPlayer* pLocalPlayer;
#ifdef PSDK
	CPed* GetCPedFromPlayerID(uint32_t playerID);
	actor_info* GetActorInfoFromPlayerID(uint32_t playerID);
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
	uint16_t sSurfingVehicleID;
	uint32_t ulSurfTick;
	union {
		struct stSAMPVehicle* pSurfingVehicle;
		struct stObject* pSurfingObject;
	}SurfOn;
	BOOL stuck;
	BOOL isActive;
	float fSurfPosition[3];
	int iUnk0;
	int	iSurfMode;	//0 = not surfing, 1 = moving (unstable surf), 2 = fixed on vehicle
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
	struct stSAMPPed* pSAMP_Actor;
	struct stInCarData		inCarData;
	struct stAimData		aimData;
	struct stTrailerData	trailerData;
	struct stOnFootData		onFootData;
	struct stPassengerData	passengerData;
	int						iIsActive;
	int						iIsWasted;
	uint16_t				sCurrentVehicleID;
	uint16_t				sLastVehicleID;
	union {//animID and flags
		struct {
			unsigned short sCurrentAnimationID : 16;
			unsigned char framedelta : 8;
			unsigned char loopA : 1;
			unsigned char lockX : 1;
			unsigned char lockY : 1;
			unsigned char lockF : 1;
			unsigned char time : 2;
		};
		int value;
	}Animation;
	uint32_t				ulUnk0;
	int						iIsSpectating;
	uint8_t					byteTeamID;
	uint8_t					byteUnk1;
	uint32_t				ulSendTick;
	uint32_t				ulSpectateTick;
	uint32_t				ulAimTick;
	uint32_t				ulStatsUpdateTick;
	struct {
		uint16_t objectId;
		uint16_t vehicleId;
		uint16_t playerId;
		uint16_t actorId;
	} СameraTarget;
	uint32_t				ulHeadSyncTick;
	struct stHeadSync		headSyncData;
	uint32_t lastAnyTick;//?
	int						iSpawnClassLoaded;
	uint32_t				ulSpawnSelectionTick;
	uint32_t				ulSpawnSelectionStart;
	struct {
		uint8_t teamId;
		int skinId;
		uint8_t unk;
		float position[3];
		float rotation;
		int weapon[3];
		int ammo[3];
	} SpawnInfo;
	BOOL hasSpawnInfo;
	uint32_t lastWeaponUpdateTick;
	struct {
		uint16_t aimedPlayerId;
		uint16_t aimedActorId;
		uint8_t currentWeapon;
		uint8_t lastWeapon[13];
		int lastWeaponAmmo[13];
	} WeaponsData;
	int passengerDriveBy;
	uint8_t currentInteriorId;
	BOOL isInRCVehicle;
	char name[256];
	struct SurfData {
		uint16_t entityId;
		uint32_t lastUpdateTick;
		union {
			struct stSAMPVehicle* pVehicle;
			struct stObject* pObject;
		};
		BOOL stuck;
		BOOL isActive;
		float position[3];
		int unk;
		struct stSurfData		surfData;
	} surfData;
	struct {
		BOOL enableAfterDeath;
		int selectedSpawnClassId;
		BOOL waitingForRequestToSpawn;
		BOOL isActive;
	} ClassSelection;
	uint32_t zoneDisplayingEnded;

	uint8_t					byteSpectateMode;		// 3 = vehicle, 4 = player, side = 14, fixed = 15
	uint8_t					byteSpectateType;		// 0 = none, 1 = player, 2 = vehicle
	int						iSpectateID;
	int						iInitiatedSpectating;
	struct stDamageData		vehicleDamageData;
};
struct stRemotePlayerData
{
	struct stSAMPPed* pSAMP_Actor;
	struct stSAMPVehicle* pSAMP_Vehicle;
	uint16_t playerId;
	uint16_t vehicleID;
	uint32_t unk;
	BOOL showNametag;
	BOOL hasJetPack;
	uint8_t	specialAction;
	struct stInCarData inCarData;
	struct stTrailerData trailerData;
	struct stAimData aimData;
	struct stPassengerData passengerData;
	struct stOnFootData onFootData;
	uint8_t teamId;
	uint8_t state;
	uint8_t seatId;
	uint32_t unk4;
	BOOL passengerDriveBy;
	float onFootPos[3];
	float onFootMoveSpeed[3];
	float vehiclePosition[3];
	float vehicleMoveSpeed[3];
	uint32_t unk5[76];
	float positionDifference[3];
	struct {
		float real;
		float imag[3];
	} VehicleTargetRotation;
	float armor;
	float health;
	char unk6[12];
	union {//animID and flags
		struct {
			unsigned short sCurrentAnimationID : 16;
			unsigned char framedelta : 8;
			unsigned char loopA : 1;
			unsigned char lockX : 1;
			unsigned char lockY : 1;
			unsigned char lockF : 1;
			unsigned char time : 2;
		};
		int value;
	}Animation;
	uint8_t updateType;
	uint32_t lastUpdateTick;
	uint32_t lastStreamedInTick;	// is 0 when currently streamed in
	BOOL performingCustomAnimation;
	int status;
	struct stHeadSync headSyncData;
	struct {
		int state;
		int position[3];
		uint32_t handle;
	} marker;
};
struct stRemotePlayer
{
	stRemotePlayerData* pPlayerData;
	int iPing;
private:
	int __align;
public:
	//char szPlayerName[16];
	std::string PlayerName;
	int iScore;
	BOOL iIsNPC;
};
template <typename T>
struct stSAMPEntity
{
	void* pVTBL;
	uint8_t		byteUnk0[60]; // game CEntity object maybe. always empty.
	T* pGTAEntity;
	uint32_t	ulGTAEntityHandle;
};
struct stSAMPPed : public stSAMPEntity < actor_info >
{
	BOOL usingCellPhone;
	uint8_t				byteUnk0[600];
	struct actor_info* pGTA_Ped;
private:
	unsigned int unk[2];
public:
	unsigned char playerNumber;
private:
	unsigned int unk2[2];
public:
	uint16_t parachuteObject;
	uint16_t urinateParticleId;
	struct {
		int iSurfType; //none, beer, dyn_beer, pint_glass, ciggi
		uint32_t m_object;
		int drunkLevel;
	} stuff;
private:
	uint8_t unk3[5];
public:
	struct {
		BOOL isDancing;
		int danceStyle;
		int danceMove;
	} DanceInfo;
private:
	uint8_t unk4[20];
public:
	BOOL isUrinating;
private:
	uint8_t unk5[55];
public:
	//???
};
struct stVehiclePool
{
	int iVehicleCount;
	struct {
		struct Info {
			uint16_t id;
			int type;
			float position[3];
			float rotation;
			uint8_t primaryColor;
			uint8_t	secondaryColor;
			float health;
			char interiorId;
			int doorDamageStatus;
			int panelDamageStatus;
			char lightDamageStatus;
			bool doorsLocked;
			bool hasSiren;
		} entry[100];
		BOOL isAvailable[100];
	} waiting;
	struct stSAMPVehicle* pSAMP_Vehicle[SAMP_MAX_VEHICLES];
	int										iIsListed[SAMP_MAX_VEHICLES];
	struct vehicle_info* pGTA_Vehicle[SAMP_MAX_VEHICLES];
private:
	int	unk[SAMP_MAX_VEHICLES];
public:
	uint16_t lastUndrivenId[SAMP_MAX_VEHICLES];
	int lastUndrivenProcessTick[SAMP_MAX_VEHICLES];
	int										iIsListed2[SAMP_MAX_VEHICLES];
	BOOL isDestroyed[SAMP_MAX_VEHICLES];
	int tickWhenDestroyed[SAMP_MAX_VEHICLES];
	float									fSpawnPos[SAMP_MAX_VEHICLES][3];
	BOOL iInitiated;
#ifdef PSDK
	bool IsVehicleStreamed(uint16_t vehicleID);
	CVehicle* GetCVehicleFromSAMPVehicleID(uint16_t vehicleID);
	vehicle_info* GetVehicleInfoFromSAMPVehicleID(uint16_t vehicleID);
#endif
};
struct stSAMPVehicle : public stSAMPEntity < vehicle_info >
{
	struct vehicle_info* pTrailer;
	struct vehicle_info* pGTA_Vehicle;
	uint8_t unk[8];
	BOOL bIsMotorOn;
	BOOL isLightsOn;
	BOOL isLocked;
	bool byteIsObjective;
	BOOL iObjectiveBlipCreated;
	int timeSinceLastDriven;
	BOOL m_bHasBeenDriven;
	char unk2[4];
	BOOL engineState;
	unsigned char primaryColor;
	unsigned char secondaryColor;
	BOOL needsToUpdateColor;
	BOOL unoccupiedSync;
	BOOL remoteUnocSync;
	BOOL keepModelLoaded;
	int hasSiren;
	IDirect3DTexture9* licensePlate;
	char licensePlateText[32 + 1];
	uint32_t marker;
};
struct stObject : public stSAMPEntity < object_info >
{
private:
	uint8_t unk[6];
public:
	int iModel;
private:
	uint8_t unk2;
public:
	bool dontCollideWithCamera;
	float fDrawDistance;
private:
	float unk3;
public:
	float fPos[3];
	float distanceToCamera;
	bool drawLast;
private:
	uint8_t unk4[64];
public:
	float fRot[3];
};
struct stObjectPool
{
	int				iObjectCount;
	int				iIsListed[SAMP_MAX_OBJECTS];
	struct stObject* object[SAMP_MAX_OBJECTS];
};
struct stGangzone
{
	float	fPosition[4];
	DWORD	dwColor;
	DWORD	dwAltColor;
};
struct stGangzonePool
{
	struct stGangzone* pGangzone[SAMP_MAX_GANGZONES];
	int					iIsListed[SAMP_MAX_GANGZONES];
};
struct stTextLabel
{
	char* pText;
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
	ID3DXFont* m_pChatFont;
	ID3DXFont* m_pLittleFont;
	ID3DXFont* m_pChatShadowFont;
	ID3DXFont* m_pLittleShadowFont;
	ID3DXFont* m_pCarNumberFont;
	ID3DXSprite* m_pTempSprite;
	int			field_18;
	char* m_pszTextBuffer;
};
struct stChatInfo
{
	int					pagesize;
	char* pLastMsgText;
	int					iChatWindowMode;
	uint8_t				bTimestamps;
	uint32_t			ulUnk0;
	char				logFilePathChatLog[MAX_PATH + 1];
	void* GameUI; // CDXUTDialog
	void* DditBackground; // CDXUTEditBox
	void* DxutScrollBar; // CDXUTScrollBar
	D3DCOLOR			clTextColor;
	D3DCOLOR			clInfoColor;
	D3DCOLOR			clDebugColor;
	DWORD				dwChatboxOffset;
	struct stChatEntry	chatEntry[100];
	stFontRenderer* m_pFontRenderer;
	ID3DXSprite* m_pChatTextSprite;
	ID3DXSprite* m_pSprite;
	IDirect3DDevice9* m_pD3DDevice;
	int renderMode; // 0 - Direct Mode (slow), 1 - Normal mode
	ID3DXRenderToSurface* m_pD3DRenderToSurface;
	IDirect3DTexture9* m_pTexture;
	IDirect3DSurface9* m_pSurface;
	D3DDISPLAYMODE* m_pD3DDisplayMode;
private:
	int unk[2];
public:
	int	m_iRedraw;
	int	m_nPrevScrollBarPosition;
	int	m_iFontSizeY;
	int	m_iTimestampWidth;
};
struct stInputBox
{
	void* pUnknown;
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
typedef void(__cdecl* CMDPROC) (PCHAR);
struct stInputInfo
{
	void* pD3DDevice;
	void* pDXUTDialog;
	stInputBox* pDXUTEditBox;
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
	BOOL Enabled;
	struct {
		char szKiller[25];
		char szVictim[25];
		D3DCOLOR clKillerColor;
		D3DCOLOR clVictimColor;
		uint8_t byteType;
	}KillEntry[5];
	int longestNickLength;
	int position[2];
	ID3DXFont* d3dFont;
	ID3DXFont* weaponFont1;
	ID3DXFont* weaponFont2;
	ID3DXSprite* sprite;
	IDirect3DDevice9* d3dDevice;
	int auxFontInited;
	ID3DXFont* auxFont1;
	ID3DXFont* auxFont2;
};
struct stKillInfo
{
	BOOL iEnabled;
	struct stKillEntry KillEntry[5];
	int longestNickLength;
	int iXOffset[2];
	ID3DXFont* pD3DFont;
	ID3DXFont* pWeaponFont;
	ID3DXFont* pWeaponFont2;
	ID3DXSprite* pSprite;
	IDirect3DDevice9* pD3DDevice;
	int auxFontInited;
	ID3DXFont* auxFont1;
	ID3DXFont* auxFont2;
};
struct stChatPlayer
{
	int		iCreated;
	char	probablyTheText[256];// text max length = 144
	DWORD	dwTickCreated;
	DWORD	dwLiveLength;
	DWORD	dwColor;
	float	fDrawDistance;
	DWORD	dwMaxLineLength;
};
struct stMiscInfo
{
	struct stAudio
	{
		int									iSoundState; // 0 - Finished, 1 - Loaded, 2 - Playing
	};
	struct stCamera
	{
		class CMatrix_Padded* matrix;
	};
	stAudio* pAudio;
	stCamera* pCamera;
	stSAMPPed* pLocalPlayerPed;
	struct {
		float position[3];
		float nextPosition[3];
		float size;
		char type;
		BOOL enabled;
		uint32_t marker;
		uint32_t handle;
	} racingCheckpoint;
	struct {
		float position[3];
		float size[3];
		BOOL enabled;
		uint32_t handle;
	} checkpoint;
	int unk;
	BOOL headIsMove;
	int frameLimiter;
	int	cursorMode;
	unsigned int inputEnableWaitFrames;
	BOOL clockEnabled;
	char unk2;
	bool keepLoadedVehicleModels[212];

};
struct stScoreboardInfo
{
	int					iIsEnabled;
	int					iPlayersCount;
	float				fTextOffset[2];
	float				fScalar;
	float				fSize[2];
	float				fUnk0[5];
	IDirect3DDevice9* pDirectDevice;
	class _CDXUTDialog* pDialog;
	class _CDXUTListBox* pList;
	int					iOffset;		// ?
	int					iIsSorted;		// ?
};
struct stActorPool
{
	int					iLastActorID;
	stSAMPEntity<void>* pActor[SAMP_MAX_ACTORS]; // ?
	int					iIsListed[SAMP_MAX_ACTORS];
	struct actor_info* pGTAPed[SAMP_MAX_ACTORS];
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
	//struct MenuPool* menuPool;
	void* pMenuPool;
	struct stActorPool* pActor;
	struct stPlayerPool* pPlayer;
	struct stVehiclePool* pVehicle;
	struct stPickupPool* pPickup;
	struct stObjectPool* pObject;
	struct stGangzonePool* pGangzone;
	struct stTextLabelPool* pText3D;
	struct stTextdrawPool* pTextdraw;
};
#pragma pack(pop)
#endif

#if defined (SAMP_R1_COMPILE)
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
#elif defined (SAMP_R3_COMPILE)
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
#endif

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

			//callbacks
			using tWndProc = std::function<LRESULT __stdcall(HookedStructs::stWndProcParams*)>;
			using tGameLoop = std::function<void __stdcall()>;
			using tPresent_ = std::function<HRESULT __stdcall(HookedStructs::stPresentParams*)>;
			using tReset_ = std::function<HRESULT __stdcall(HookedStructs::stResetParams*)>;
			using tRakClientSend_ = std::function<LRESULT __stdcall(HookedStructs::stRakClientSend*)>;
			using tRakClientRPC_ = std::function<LRESULT __stdcall(HookedStructs::stRakClientRPC*)>;
			using tRakClientRPCRecv_ = std::function<LRESULT __stdcall(HookedStructs::stRakClientRPCRecv*)>;
			using tRakPeerRecv_ = std::function<LRESULT __stdcall(HookedStructs::stRakClientRecv*)>;
		public:
			//typedef LRESULT(__stdcall* tWndProc)(HookedStructs::stWndProcParams*);
			//typedef void(__stdcall* tGameLoop)();
			//typedef HRESULT(__stdcall* tPresent_)(HookedStructs::stPresentParams*);
			//typedef HRESULT(__stdcall* tReset_)(HookedStructs::stResetParams*);
			//typedef bool(__stdcall* tRakClientSend_)(HookedStructs::stRakClientSend*);
			//typedef bool(__stdcall* tRakClientRPC_)(HookedStructs::stRakClientRPC*);
			//typedef bool(__stdcall* tRakClientRPCRecv_)(HookedStructs::stRakClientRPCRecv*);
			//typedef bool(__stdcall* tRakPeerRecv_)(HookedStructs::stRakClientRecv*);

			CCallbackRegister(DWORD base) {
				sampBase = base;

				pWndProcHook = std::make_unique<memwrapper::memhook<WndProc_t>>(0x00747EB0U, WndProc_HOOKED);
				pGameLoopHook = std::make_unique<memwrapper::memhook<GameLoop_t>>(0x00748DA3U, GameLoop_HOOKED);
				pD3DPresentHook = std::make_unique<memwrapper::memhook<D3DPresent_t>>(GetDeviceAddress(17), D3DPresent_HOOKED);
				pD3DResetHook = std::make_unique<memwrapper::memhook<D3DReset_t>>(GetDeviceAddress(16), D3DReset_HOOKED);
				pRakClientSendHook = std::make_unique<memwrapper::memhook<RakClientSend_t>>(sampBase + SAMP_RAKCLIENT_SEND, RakClientSend_HOOKED);
				pRakClientRPCSendHook = std::make_unique<memwrapper::memhook<RakClientRPCSend_t>>(sampBase + SAMP_RAKCLIENT_RPC_SEND, RakClientRPCSend_HOOKED);
				pRakPeerHandleRPCPacketHook = std::make_unique<memwrapper::memhook<RakPeerHandleRPCPacket_t>>(sampBase + SAMP_RAKPEER_HANDLE_RPC_PACKET, RakPeerHandleRPCPacketHook_HOOKED);
				pRakPeerReceiveHook = std::make_unique<memwrapper::memhook<RakPeerReceive_t>>(sampBase + SAMP_RAKPEER_RECEIVE, RakPeerReceive_HOOKED);


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

			auto inline operator+=(tWndProc func) -> void {
				vecWndProcCallback.push_back(func);
			};
			auto inline operator+=(tGameLoop func) -> void {
				vecGameLoopCallback.push_back(func);
			};
			auto inline operator+=(tPresent_ func) -> void {
				vecPresentCallback.push_back(func);
			};
			auto inline operator+=(tReset_ func) -> void {
				vecResetCallback.push_back(func);
			};
			auto inline operator+=(tRakClientSend_ func) -> void {
				vecRakClientSendCallback.push_back(func);
			};
			auto inline operator+=(tRakClientRPC_ func) -> void {
				vecRakClientRPCCallback.push_back(func);
			};
			auto inline operator+=(tRakClientRPCRecv_ func) -> void {
				vecRakClientRPCRecvCallback.push_back(func);
			};
			auto inline operator+=(tRakPeerRecv_ func) -> void {
				vecRakPeerRecvCallback.push_back(func);
			};

			void inline RegisterWndProcCallback(tWndProc func) { vecWndProcCallback.push_back(func); };
			void inline RegisterGameLoopCallback(tGameLoop func) { vecGameLoopCallback.push_back(func); };

			void inline RegisterD3DCallback(tPresent_ func) { vecPresentCallback.push_back(func); };
			void inline RegisterD3DCallback(tReset_ func) { vecResetCallback.push_back(func); };

			void inline RegisterRakClientCallback(tRakClientSend_ func) { vecRakClientSendCallback.push_back(func); };
			void inline RegisterRakClientCallback(tRakClientRPC_ func) { vecRakClientRPCCallback.push_back(func); };
			void inline RegisterRakClientCallback(tRakClientRPCRecv_ func) { vecRakClientRPCRecvCallback.push_back(func); };
			void inline RegisterRakClientCallback(tRakPeerRecv_ func) { vecRakPeerRecvCallback.push_back(func); };

			IDirect3DDevice9 inline* GetIDirect3DDevice9(void) { return pD3DDevice; };

			auto inline GetHookObject(void) {
				return pRakPeerHandleRPCPacketHook.get();
			}
		private:
			std::unique_ptr<memwrapper::memhook<GameLoop_t>> pGameLoopHook = 0;
			std::unique_ptr<memwrapper::memhook<WndProc_t>> pWndProcHook = 0;

			std::unique_ptr<memwrapper::memhook<D3DPresent_t>> pD3DPresentHook = 0;
			std::unique_ptr<memwrapper::memhook<D3DReset_t>> pD3DResetHook = 0;

			std::unique_ptr<memwrapper::memhook<RakClientSend_t>> pRakClientSendHook = 0;
			std::unique_ptr<memwrapper::memhook<RakClientRPCSend_t>> pRakClientRPCSendHook = 0;
			std::unique_ptr<memwrapper::memhook<RakPeerHandleRPCPacket_t>> pRakPeerHandleRPCPacketHook = 0;
			std::unique_ptr<memwrapper::memhook<RakPeerReceive_t>> pRakPeerReceiveHook = 0;

			IDirect3DDevice9* pD3DDevice = nullptr;
			bool isD3DHookInit = false;

			DWORD sampBase = 0;

			//tWndProc callWndProc = 0;
			//tGameLoop callGameLoop = 0;
			//tPresent_ callPresent = 0;
			//tReset_ callReset = 0;
			//tRakClientSend_ callRakClientSend = 0;
			//tRakClientRPC_ callRakClientRPC = 0;
			//tRakClientRPCRecv_ callRakClientRPCRecv = 0;
			//tRakPeerRecv_ callRakPeerRecv = 0;
			std::vector<tWndProc> vecWndProcCallback;
			std::vector<tGameLoop> vecGameLoopCallback;
			std::vector<tPresent_> vecPresentCallback;
			std::vector<tReset_> vecResetCallback;
			std::vector<tRakClientSend_> vecRakClientSendCallback;
			std::vector<tRakClientRPC_> vecRakClientRPCCallback;
			std::vector<tRakClientRPCRecv_> vecRakClientRPCRecvCallback;
			std::vector<tRakPeerRecv_> vecRakPeerRecvCallback;

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
			return SAMP::CallBacks::pCallBackRegister->GetHookObject()->call<RakPeerInterface*, const char*, int, PlayerID__>(pRakPeerInterface1, reinterpret_cast<char*>(bs_.GetData()), bs_.GetNumberOfBytesUsed(), plID1);
		};
		bool EmulPacket(RakNet::BitStream* bitStream) {
#if defined (SAMP_R1_COMPILE)
			Packet__* send_packet = reinterpret_cast<Packet__ * (*)(size_t)>(sampBase + 0x347e0)(bitStream->GetNumberOfBytesUsed());
			memcpy(send_packet->data, bitStream->GetData(), send_packet->length);

			// RakPeer::AddPacketToProducer
			char* packets = reinterpret_cast<char*>(pRakPeerInterface) + 0xdb6;
			auto write_lock = reinterpret_cast<Packet__ * *(__thiscall*)(void*)>(sampBase + 0x35b10);
			auto write_unlock = reinterpret_cast<void(__thiscall*)(void*)>(sampBase + 0x35b50);

			*write_lock(packets) = send_packet;
			write_unlock(packets);

			return true;
#elif defined (SAMP_R3_COMPILE)
			Packet__* send_packet = reinterpret_cast<Packet__ * (*)(size_t)>(sampBase + 0x37b90)(bitStream->GetNumberOfBytesUsed());
			memcpy(send_packet->data, bitStream->GetData(), send_packet->length);

			// RakPeer::AddPacketToProducer
			char* packets = reinterpret_cast<char*>(pRakPeerInterface) + 0xdb6;
			auto write_lock = reinterpret_cast<Packet__ * *(__thiscall*)(void*)>(sampBase + 0x38ec0);
			auto write_unlock = reinterpret_cast<void(__thiscall*)(void*)>(sampBase + 0x38f00);

			*write_lock(packets) = send_packet;
			write_unlock(packets);

			return true;
#endif
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

			g_RakNet = new CRakNet(g_SAMP->pRakClientInterface, g_SAMP->pRakPeerInterface);//g_SAMP->pRakClientInterface, g_SAMP->pRakPeerInterface

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

#if defined (SAMP_R1_COMPILE)
			void(__thiscall *AddToChatWindowBuffer) (const void *_this, int iType, char *szText, char *szPrefix, DWORD cColor, DWORD cPrefixColor) =
				(void(__thiscall *) (const void *, int, char *, char *, DWORD, DWORD)) (sampAddr + 0x064010);//r3 0x67460 | r1 0x064010
#elif defined (SAMP_R3_COMPILE)
			void(__thiscall * AddToChatWindowBuffer) (const void* _this, int iType, char* szText, char* szPrefix, DWORD cColor, DWORD cPrefixColor) =
				(void(__thiscall*) (const void*, int, char*, char*, DWORD, DWORD)) (sampAddr + 0x067460);//r3 0x67460 | r1 0x064010
#endif

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

#if defined (SAMP_R1_COMPILE)
			void(__thiscall *AddClientCommand) (const void *_this, char *szCommand, CMDPROC pFunc) =
				(void(__thiscall *) (const void *, char *, CMDPROC)) (sampAddr + 0x065AD0);
#elif defined (SAMP_R3_COMPILE)
			void(__thiscall * AddClientCommand) (const void* _this, char* szCommand, CMDPROC pFunc) =
				(void(__thiscall*) (const void*, char*, CMDPROC)) (sampAddr + 0x069000);
#endif

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

		if (!SAMP::CallBacks::pCallBackRegister->vecRakPeerRecvCallback.empty()) {
			HookedStructs::stRakClientRecv params = { 0 };
			BitStream *bs = new BitStream(packet->data, packet->length, true);
			params.bitStream = bs;
			params.lenght = packet->length;
			params.pktID = packet->data[0];
			bool retn;
			for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecRakPeerRecvCallback.size(); i++) {
				retn = SAMP::CallBacks::pCallBackRegister->vecRakPeerRecvCallback[i](&params);
				if (!retn) {
					delete bs;
					//return nullptr;
					//_this->DeallocatePacket((Packet*)packet);
					memset(packet->data, 0, packet->length);
					packet->data[0] = 0xFF;
					return packet;
				}
			}
			//bool retn = SAMP::CallBacks::pCallBackRegister->callRakPeerRecv(&params);
			packet->data = bs->GetData();
			packet->bitSize = bs->GetNumberOfBitsUsed();
			packet->length = bs->GetNumberOfBytesUsed();
			delete bs;
			//if (!retn)
			//	return nullptr;
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

	if (!SAMP::CallBacks::pCallBackRegister->vecRakClientRPCRecvCallback.empty()) {
		HookedStructs::stRakClientRPCRecv params = { 0 };
		params.bitStream = callback_bs.get();
		params.rpc_id = id;
		bool retn;
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecRakClientRPCRecvCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecRakClientRPCRecvCallback[i](&params);
			if (!retn)
				return false;
		}
		//bool retn = SAMP::CallBacks::pCallBackRegister->callRakClientRPCRecv(&params);
		id = params.rpc_id;
		//if (!retn)
		//	return false;
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

	if (!SAMP::CallBacks::pCallBackRegister->vecRakClientRPCCallback.empty()) {
		HookedStructs::stRakClientRPC params = { 0 };
		params.bitStream = bitStream;
		params.orderingChannel = orderingChannel;
		params.priority = priority;
		params.reliability = reliability;
		params.shiftTimestamp = shiftTimestamp;
		params.uniqueID = uniqueID;
		params._this = _this;
		bool retn;
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecRakClientRPCCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecRakClientRPCCallback[i](&params);
			if (!retn)
				return false;
		}
		//bool retn = SAMP::CallBacks::pCallBackRegister->callRakClientRPC(&params);
		bitStream = params.bitStream;
		orderingChannel = params.orderingChannel;
		priority = params.priority;
		reliability = params.reliability;
		shiftTimestamp = params.shiftTimestamp;
		uniqueID = params.uniqueID;
		_this = params._this;
	}

	return SAMP::CallBacks::pCallBackRegister->pRakClientRPCSendHook->call<RakClientInterface*, int*, BitStream*, PacketPriority, PacketReliability, char, bool>(_this, uniqueID, bitStream, priority, reliability, orderingChannel, shiftTimestamp);
}
bool __fastcall SAMP::CallBacks::CCallbackRegister::RakClientSend_HOOKED(RakClientInterface* _this, void* Unknown, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel) {
	if(_this == nullptr || bitStream == nullptr)
		return SAMP::CallBacks::pCallBackRegister->pRakClientSendHook->call<RakClientInterface*, BitStream*, PacketPriority, PacketReliability, char>(_this, bitStream, priority, reliability, orderingChannel);

	if (!SAMP::CallBacks::pCallBackRegister->vecRakClientSendCallback.empty()) {
		HookedStructs::stRakClientSend params = { 0 };
		params.bitStream = bitStream;
		params.orderingChannel = orderingChannel;
		params.priority = priority;
		params.reliability = reliability;
		params._this = _this;
		bool retn;
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecRakClientSendCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecRakClientSendCallback[i](&params);
			if (!retn)
				return false;
		}
		//bool retn = SAMP::CallBacks::pCallBackRegister->callRakClientSend(&params);
		bitStream = params.bitStream;
		orderingChannel = params.orderingChannel;
		priority = params.priority;
		reliability = params.reliability;
		_this = params._this;
		//if (!retn)
		//	return false;
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

	if (!SAMP::CallBacks::pCallBackRegister->vecPresentCallback.empty()) {
		HookedStructs::stPresentParams params = { 0 };
		params.hDestWindow = hDestWindow;
		params.pDestRect = pDestRect;
		params.pDevice = pDevice;
		params.pDirtyRegion = pDirtyRegion;
		params.pSrcRect = pSrcRect;
		HRESULT retn;
		//for (auto i : SAMP::CallBacks::pCallBackRegister->vecPresentCallback) { //поебота, которая переполняет стек и кидает исключение на копирование объекта в std::function
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecPresentCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecPresentCallback[i](&params);
			if (retn != D3D_OK)
				return retn;
		}
		//}
		//LRESULT retn = SAMP::CallBacks::pCallBackRegister->callPresent(&params);
		hDestWindow = params.hDestWindow;
		pDestRect = params.pDestRect;
		pDevice = params.pDevice;
		pDirtyRegion = params.pDirtyRegion;
		pSrcRect = params.pSrcRect;
		//if (retn != D3D_OK)
		//	return retn;
	}

	return SAMP::CallBacks::pCallBackRegister->pD3DPresentHook->call<IDirect3DDevice9*, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*>(pDevice, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
}
HRESULT __stdcall SAMP::CallBacks::CCallbackRegister::D3DReset_HOOKED(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentParams) {
	if (pDevice == nullptr)
		return SAMP::CallBacks::pCallBackRegister->pD3DResetHook->call<IDirect3DDevice9*, D3DPRESENT_PARAMETERS*>(pDevice, pPresentParams);
	
	if (!SAMP::CallBacks::pCallBackRegister->vecResetCallback.empty()) {
		HookedStructs::stResetParams params = { 0 };
		params.pDevice = pDevice;
		params.pPresentParams = pPresentParams;
		HRESULT retn;
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecResetCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecResetCallback[i](&params);
			if (retn != D3D_OK)
				return retn;
		}
		//HRESULT retn = SAMP::CallBacks::pCallBackRegister->callReset(&params);
		pDevice = params.pDevice;
		pPresentParams = params.pPresentParams;
		//if (retn != D3D_OK)
		//	return retn;
	}

	return SAMP::CallBacks::pCallBackRegister->pD3DResetHook->call<IDirect3DDevice9*, D3DPRESENT_PARAMETERS*>(pDevice, pPresentParams);
}
void __cdecl SAMP::CallBacks::CCallbackRegister::GameLoop_HOOKED() {
	if (!SAMP::CallBacks::pCallBackRegister->vecGameLoopCallback.empty()) {
		//SAMP::CallBacks::pCallBackRegister->callGameLoop();
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecGameLoopCallback.size(); i++) {
			SAMP::CallBacks::pCallBackRegister->vecGameLoopCallback[i]();
		}
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

	if (!SAMP::CallBacks::pCallBackRegister->vecWndProcCallback.empty()) {//maybe error if null?
		HookedStructs::stWndProcParams params = { 0 };
		params.hWnd = hWnd;
		params.uMsg = uMsg;
		params.wParam = wParam;
		params.lParam = lParam;
		LRESULT retn;
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecWndProcCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecWndProcCallback[i](&params);
			if (retn != 0)
				retn;
		}
		//LRESULT retn = SAMP::CallBacks::pCallBackRegister->callWndProc(&params);
		hWnd = params.hWnd;
		uMsg = params.uMsg;
		wParam = params.wParam;
		lParam = params.lParam;
		//if (retn != 0)
		//	return retn;
	}
	return SAMP::CallBacks::pCallBackRegister->pWndProcHook->call<HWND, UINT, WPARAM, LPARAM>(hWnd, uMsg, wParam, lParam);
}

