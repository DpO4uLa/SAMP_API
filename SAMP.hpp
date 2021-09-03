#pragma once
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <string>
#include <vector>
#include "BitStream.h"
#include "MinHook.h"
#pragma comment(lib, "libMinHook-x86-v141-mt.lib")

int dblSpace;
char buf[131072];



struct PlayerID
{
	///The peer address from inet_addr.
	unsigned int binaryAddress;
	///The port number
	unsigned short port;

	// Return the playerID as a string in the format <IP>:<Port>
	// Note - returns a static string.  Not thread-safe or safe for multiple calls per line.
	char *ToString(bool writePort = true) const;

	// Sets the binary address part from a string.  Doesn't set the port
	void SetBinaryAddress(const char *str);

	PlayerID& operator = (const PlayerID& input)
	{
		binaryAddress = input.binaryAddress;
		port = input.port;
		return *this;
	}

	bool operator==(const PlayerID& right) const;
	bool operator!=(const PlayerID& right) const;
	bool operator > (const PlayerID& right) const;
	bool operator < (const PlayerID& right) const;
};



TCHAR GetChar(TCHAR _char)
{
	if (_char < 32)
		return '.';

	return _char;
}

char *DumpMem(unsigned char *pAddr, int len)
{
	memset(buf, 0, 16384);

	char temp[256];
	BYTE fChar;
	int i = 0;
	long bytesRead = 0;
	TCHAR line[17];
	int nSpaces = 3 * 16 + 2;
	memset(&line, 0, sizeof(line));
	int dataidx = 0;

	if (dblSpace)
		strcat(buf, "\n\n");

	for (;;)
	{
		// print hex address
		sprintf(temp, "%08X  ", i);
		strcat(buf, temp);

		// print first 8 bytes
		for (int j = 0; j < 0x08; j++)
		{
			fChar = pAddr[dataidx];
			if (dataidx >= len) break;
			dataidx++;

			sprintf(temp, "%02X ", fChar);
			strcat(buf, temp);

			// add to the ASCII text
			line[bytesRead++] = GetChar(fChar);

			// this took three characters
			nSpaces -= 3;
		}

		// print last 8 bytes - change in the "xx " to " xx" provides
		// the double space in between the first 8 and the last 8 bytes.
		for (int j = 0x08; j < 0x10; j++)
		{
			fChar = pAddr[dataidx];
			if (dataidx >= len) break;
			dataidx++;

			sprintf(temp, " %02X", (unsigned char)fChar);
			strcat(buf, temp);

			// add to the ASCII text
			line[bytesRead++] = GetChar(fChar);

			// this took three characters
			nSpaces -= 3;
		}

		// fill in any leftover spaces.
		for (int j = 0; j <= nSpaces; j++)
		{
			strcat(buf, " ");
		}

		// print ASCII text
		sprintf(temp, "%s", line);
		strcat(buf, temp);

		// quit if the file is done
		if (dataidx >= len) break;

		// new line
		strcat(buf, "\n");

		if (dblSpace)
			strcat(buf, "\n");

		// reset everything
		bytesRead = 0;
		memset(&line, 0, sizeof(line));
		i += 16;
		//dataidx++;
		nSpaces = 3 * 16 + 2;
	}

	return buf;
}

enum PacketPriority
{
	SYSTEM_PRIORITY,   /// \internal Used by RakNet to send above-high priority messages.
	HIGH_PRIORITY,   /// High priority messages are send before medium priority messages.
	MEDIUM_PRIORITY,   /// Medium priority messages are send before low priority messages.
	LOW_PRIORITY,   /// Low priority messages are only sent when no other messages are waiting.
	NUMBER_OF_PRIORITIES
};
enum PacketReliability
{
	UNRELIABLE = 6,   /// Same as regular UDP, except that it will also discard duplicate datagrams.  RakNet adds (6 to 17) + 21 bits of overhead, 16 of which is used to detect duplicate packets and 6 to 17 of which is used for message length.
	UNRELIABLE_SEQUENCED,  /// Regular UDP with a sequence counter.  Out of order messages will be discarded.  This adds an additional 13 bits on top what is used for UNRELIABLE.
	RELIABLE,   /// The message is sent reliably, but not necessarily in any order.  Same overhead as UNRELIABLE.
	RELIABLE_ORDERED,   /// This message is reliable and will arrive in the order you sent it.  Messages will be delayed while waiting for out of order messages.  Same overhead as UNRELIABLE_SEQUENCED.
	RELIABLE_SEQUENCED /// This message is reliable and will arrive in the sequence you sent it.  Out or order messages will be dropped.  Same overhead as UNRELIABLE_SEQUENCED.
};


namespace SAMP {
	namespace SAMPStructs {
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
	}

	class CSAMP {
	public:
		void LoadAPI(void) {//init samp api
			sampAddr = (DWORD)GetModuleHandleA("samp.dll");

			

			printf("\nLoad sampAPI");
		};

		void UnloadAPI(void) {//unload samp api
			MH_DisableHook((void*)(sampAddr + 0x005DB40));//delete wndproc hook

			printf("\nUnload sampAPI");
		};

		
		
		DWORD GetBase() { return sampAddr; };
	private:
		DWORD sampAddr = 0;

		
	};
	
	std::unique_ptr<CSAMP> pSAMP(new CSAMP);

	namespace CallBacks {
		enum eRakNetCallBacks
		{
			INCOMING_RAKPEER_PACKET_CALLBACK,
			OUTCOMING_RAKPEER_PACKET_CALLBACK,
			INCOMING_RPC_CALLBACK,
			OUTCOMING_RPC_CALLBACK
		};

		class CCallbackRegister {
		public:
			typedef bool(__stdcall *tRakPeerOutcomingPacket)(void *, BitStream*, const int, PacketPriority, PacketReliability, char, PlayerID, bool);
			typedef LRESULT(__stdcall *tWndProc)(HWND, UINT, WPARAM, LPARAM);

			CCallbackRegister() {
				DWORD sampBase = (DWORD)GetModuleHandleA("samp.dll");

				MH_Initialize();

				MH_CreateHook((void*)(sampBase + 0x005DB40), &HOOKED_WndProc, (void**)&origWndProc);//wndproc hook
				MH_EnableHook((void*)(sampBase + 0x005DB40));

				MH_CreateHook((void*)(sampBase + 0x00307F0), &HOOKED_RakPeerSend, (void**)&origRakPeerSend);//rakpeer send hook
				MH_EnableHook((void*)(sampBase + 0x00307F0));
			}

			//сделать перегрузки
			void RegisterRakNetCallBack(tRakPeerOutcomingPacket func, eRakNetCallBacks callback_type) {
				switch (callback_type)//допилить исключения, если ид коллбека неизвестен
				{
				case eRakNetCallBacks::INCOMING_RAKPEER_PACKET_CALLBACK: {

					break;
				}
				case eRakNetCallBacks::OUTCOMING_RAKPEER_PACKET_CALLBACK: {
					vecRakPeerOutcomingPacket.push_back(func);
					break;
				}
				case eRakNetCallBacks::INCOMING_RPC_CALLBACK: {

					break;
				}
				case eRakNetCallBacks::OUTCOMING_RPC_CALLBACK: {

					break;
				}
				}
			};
			void RegisterWnwProcCallback(tWndProc func) { vecWndProc.push_back(func); }
		private:
			std::vector<tRakPeerOutcomingPacket> vecRakPeerOutcomingPacket;

			std::vector<tWndProc> vecWndProc;


			typedef LRESULT(__stdcall *tWNDPROC)(HWND, UINT, WPARAM, LPARAM);
			typedef unsigned __int32(__thiscall* tRakPeerSend)(void *, BitStream *, const int, PacketPriority, PacketReliability, char, PlayerID, bool);

			tWNDPROC origWndProc = nullptr;
			tRakPeerSend origRakPeerSend = nullptr;

			static LRESULT __stdcall HOOKED_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
			static unsigned __int32 __fastcall HOOKED_RakPeerSend(void* _this, void* pUnk, BitStream *data, const int length, PacketPriority priority, PacketReliability reliability, char orderingChannel, PlayerID playerId, bool broadcast);

		};

		std::unique_ptr<CCallbackRegister> pCallBackRegister(new CCallbackRegister);
	}
}

LRESULT __stdcall SAMP::CallBacks::CCallbackRegister::HOOKED_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	for (unsigned __int32 i = 0; i != SAMP::CallBacks::pCallBackRegister->vecWndProc.size(); i++) {
		if (!SAMP::CallBacks::pCallBackRegister->vecWndProc.data()[i](hWnd, uMsg, wParam, lParam))
			return 0;
	}
	return SAMP::CallBacks::pCallBackRegister->origWndProc(hWnd, uMsg, wParam, lParam);
}

unsigned __int32 __fastcall SAMP::CallBacks::CCallbackRegister::HOOKED_RakPeerSend(void* _this, void *pUnk, BitStream *data, const int length, PacketPriority priority, PacketReliability reliability, char orderingChannel, PlayerID playerId, bool broadcast) {
	for (unsigned __int32 i = 0; i != SAMP::CallBacks::pCallBackRegister->vecRakPeerOutcomingPacket.size(); i++) {
		if (!SAMP::CallBacks::pCallBackRegister->vecRakPeerOutcomingPacket.data()[i](_this, data, length, priority, reliability, orderingChannel, playerId, broadcast))
			return 0;
	}
	return SAMP::CallBacks::pCallBackRegister->origRakPeerSend(_this, data, length, priority, reliability, orderingChannel, playerId, broadcast);
}