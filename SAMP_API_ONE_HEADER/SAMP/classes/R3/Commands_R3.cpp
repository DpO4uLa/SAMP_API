/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#ifdef SAMP_R3_COMPILE

#include "Commands_R3.h"

SAMP::classes::CMDPROC SAMP::classes::Commands::Default = SAMP::classes::CMDPROC(SAMP_ADDROF(0x67D60));
SAMP::classes::CMDPROC SAMP::classes::Commands::TestDeathWindow = SAMP::classes::CMDPROC(SAMP_ADDROF(0x67D90));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleCameraTargetLabels = SAMP::classes::CMDPROC(SAMP_ADDROF(0x67E70));
SAMP::classes::CMDPROC SAMP::classes::Commands::SetChatPageSize = SAMP::classes::CMDPROC(SAMP_ADDROF(0x67E80));
SAMP::classes::CMDPROC SAMP::classes::Commands::SetChatFontSize = SAMP::classes::CMDPROC(SAMP_ADDROF(0x67F00));
SAMP::classes::CMDPROC SAMP::classes::Commands::DrawNameTagStatus = SAMP::classes::CMDPROC(SAMP_ADDROF(0x67FB0));
SAMP::classes::CMDPROC SAMP::classes::Commands::DrawChatTimestamps = SAMP::classes::CMDPROC(SAMP_ADDROF(0x67FC0));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleAudioStreamMessages = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68020));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleURLMessages = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68090));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleHUDScaleFix = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68100));
SAMP::classes::CMDPROC SAMP::classes::Commands::PrintMemory = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68140));
SAMP::classes::CMDPROC SAMP::classes::Commands::SetFrameLimiter = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68160));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleHeadMoves = SAMP::classes::CMDPROC(SAMP_ADDROF(0x681F0));
SAMP::classes::CMDPROC SAMP::classes::Commands::Quit = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68270));
SAMP::classes::CMDPROC SAMP::classes::Commands::CmpStat = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68280));
SAMP::classes::CMDPROC SAMP::classes::Commands::SavePosition = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68290));
SAMP::classes::CMDPROC SAMP::classes::Commands::SavePositionOnly = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68410));
SAMP::classes::CMDPROC SAMP::classes::Commands::PrintCurrentInterior = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68860));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleObjectsLight = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68890));
SAMP::classes::CMDPROC SAMP::classes::Commands::ToggleDebugLabels = SAMP::classes::CMDPROC(SAMP_ADDROF(0x688B0));
SAMP::classes::CMDPROC SAMP::classes::Commands::SendRconCommand = SAMP::classes::CMDPROC(SAMP_ADDROF(0x688C0));
SAMP::classes::CMDPROC SAMP::classes::Commands::Debug::SetPlayerSkin = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68590));
SAMP::classes::CMDPROC SAMP::classes::Commands::Debug::CreateVehicle = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68600));
SAMP::classes::CMDPROC SAMP::classes::Commands::Debug::EnableVehicleSelection = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68740));
SAMP::classes::CMDPROC SAMP::classes::Commands::Debug::SetWorldWeather = SAMP::classes::CMDPROC(SAMP_ADDROF(0x68760));
SAMP::classes::CMDPROC SAMP::classes::Commands::Debug::SetWorldTime = SAMP::classes::CMDPROC(SAMP_ADDROF(0x687B0));

void SAMP::classes::Commands::Setup() {
	((void(__cdecl *)())SAMP_ADDROF(0x689A0))();
}

#endif