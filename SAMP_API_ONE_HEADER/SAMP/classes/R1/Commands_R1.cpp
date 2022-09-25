/*
	This is a SAMP (0.3.7-R1) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R1_COMPILE

#include "Commands_R1.h"

SAMP::classes::CMDPROC SAMP::classes::Commands::Default = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64910));
SAMP::classes::CMDPROC SAMP::classes::Commands::TestDeathWindow = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64930));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleCameraTargetLabels = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64A10));
SAMP::classes::CMDPROC SAMP::classes::Commands::SetChatPageSize = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64A20));
SAMP::classes::CMDPROC SAMP::classes::Commands::SetChatFontSize = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64AA0));
SAMP::classes::CMDPROC SAMP::classes::Commands::DrawNameTagStatus = SAMP::classes::CMDPROC(SAMP_ADDROF(0x65B50));
SAMP::classes::CMDPROC SAMP::classes::Commands::DrawChatTimestamps = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64B60));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleAudioStreamMessages = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64BC0));
SAMP::classes::CMDPROC SAMP::classes::Commands::PrintMemory = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64C40));
SAMP::classes::CMDPROC SAMP::classes::Commands::SetFrameLimiter = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64C60));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleHeadMoves = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64CF0));
SAMP::classes::CMDPROC SAMP::classes::Commands::Quit = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64D70));
SAMP::classes::CMDPROC SAMP::classes::Commands::CmpStat = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64D80));
SAMP::classes::CMDPROC SAMP::classes::Commands::SavePosition = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64D90));
SAMP::classes::CMDPROC SAMP::classes::Commands::SavePositionOnly = SAMP::classes::CMDPROC(SAMP_ADDROF(0x64F10));
SAMP::classes::CMDPROC SAMP::classes::Commands::PrintCurrentInterior = SAMP::classes::CMDPROC(SAMP_ADDROF(0x65360));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleObjectsLight = SAMP::classes::CMDPROC(SAMP_ADDROF(0x65390));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleDebugLabels = SAMP::classes::CMDPROC(SAMP_ADDROF(0x653B0));
SAMP::classes::CMDPROC SAMP::classes::Commands::SendRconCommand = SAMP::classes::CMDPROC(SAMP_ADDROF(0x653C0));
SAMP::classes::CMDPROC SAMP::classes::Commands::Debug::SetPlayerSkin = SAMP::classes::CMDPROC(SAMP_ADDROF(0x65090));
SAMP::classes::CMDPROC SAMP::classes::Commands::Debug::CreateVehicle = SAMP::classes::CMDPROC(SAMP_ADDROF(0x65100));
SAMP::classes::CMDPROC SAMP::classes::Commands::Debug::EnableVehicleSelection = SAMP::classes::CMDPROC(SAMP_ADDROF(0x65240));
SAMP::classes::CMDPROC SAMP::classes::Commands::Debug::SetWorldWeather = SAMP::classes::CMDPROC(SAMP_ADDROF(0x65260));
SAMP::classes::CMDPROC SAMP::classes::Commands::Debug::SetWorldTime = SAMP::classes::CMDPROC(SAMP_ADDROF(0x652B0));

void SAMP::classes::Commands::Setup() {
	((void(__cdecl *)())SAMP_ADDROF(0x654A0))();
}

#endif