#include "main.h"

bool isPluginInitialized = false;

std::unique_ptr<CD3DRender> pRender = nullptr;

LRESULT __stdcall WndProcCallBack(SAMP::CallBacks::HookedStructs::stWndProcParams *params) {
	
	if (isPluginInitialized) {
		if (ImGui_ImplWin32_WndProcHandler(params->hWnd, params->uMsg, params->wParam, params->lParam)) {
			return 1;
		}
	}

	return 0;//retn null if all good
}

static bool isOpen = false;

HRESULT __stdcall D3DPresentHook(SAMP::CallBacks::HookedStructs::stPresentParams *params) {

	if (isPluginInitialized) {
		ImGui_ImplDX9_NewFrame();//вызывалось до инициализации имгуи, поэтому крашило
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		if (isOpen) {
			if (ImGui::Begin(u8"Тестовое меню##1337", &isOpen, ImGuiWindowFlags_::ImGuiWindowFlags_NoSavedSettings)) {

				for (int i = 0; i != SAMP_MAX_PLAYERS; i++) {
					if (SAMP::pSAMP->getPlayers()->iIsListed[i] == 0 || 
						SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[i][0] == 0 ||
						SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[i][1] == 0 ||
						SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[i][2] == 0)
						continue;

					ImGui::Text(u8"PlayerID: %d, position: %0.f %0.f %0.f", i,
						SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[i][0],
						SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[i][1],
						SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[i][2]);
					

				}

				if (ImGui::Button(u8"Отправить пакет")) {
					stOnFootData data = SAMP::pSAMP->getPlayers()->pLocalPlayer->onFootData;
					data.fPosition[2] += 10.0f;

					BitStream bs;
					bs.Write<unsigned __int8>(ID_PLAYER_SYNC);
					bs.Write((PCHAR)&data, sizeof(stOnFootData));

					SAMP::pSAMP->getRakNet()->Send(&bs);
				}

				if (ImGui::Button(u8"Отправить RPC")) {
					std::string text = "Хуй залупный";

					BitStream bs;
					bs.Write((unsigned __int8)text.length());
					bs.Write(text.c_str(), text.length());
					
					SAMP::pSAMP->getRakNet()->SendRPC(RPCEnumeration::RPC_Chat, &bs);
				}

				if (ImGui::Button(u8"SAMP::classes::")) {
					SAMP::classes::pChat->AddMessage(-1, "Тестовое сообщение");
					SAMP::classes::pGame->SetCursorMode(SAMP::classes::CursorMode::CMODE_NONE, false);

				}

				if (ImGui::Button(u8"Plugin SDK Teleport")) {
					CVector dest = FindPlayerPed()->GetPosition();
					dest.z += 5.0f;
					FindPlayerPed()->Teleport(dest, false);
				}
				
				static int vehID = 0;
				ImGui::InputInt(u8"Vehicle ID", &vehID);
				if (ImGui::Button(u8"тп кар")) {
					if (SAMP::pSAMP->getVehicles()->IsVehicleStreamed(vehID)) {
						SAMP::pSAMP->getVehicles()->GetCVehicleFromSAMPVehicleID(vehID)->Teleport(FindPlayerPed()->GetPosition(), false);
					}
				}

				if (ImGui::Button(u8"emul pacet")) {
					stOnFootData data = SAMP::pSAMP->getPlayers()->pLocalPlayer->onFootData;
					BitStream bs;
					bs.Write<unsigned __int8>(ID_PLAYER_SYNC);
					bs.Write<unsigned __int16>(49);//playerID
					bs.Write((PCHAR)&data, sizeof(stOnFootData));
					SAMP::pSAMP->getRakNet()->EmulPacket(&bs);
				}

				if (ImGui::Button(u8"emul rpc")) {
					BitStream bs;
					bs.Write<float>(0.0f);
					bs.Write<float>(0.0f);
					bs.Write<float>(0.5f);
					SAMP::pSAMP->getRakNet()->EmulRPC(RPC_ScrSetPlayerVelocity, &bs);
				}

				ImGui::End();
			}
		}

		

		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		pRender->Initialize(params->pDevice);

		//render example
		//if (SUCCEEDED(pRender->BeginRender())) {
		//	pRender->D3DBox(100, 100, 100, 100, 0xFF00BECC);
		//	pRender->EndRender();
		//}
		
		
	}

	return D3D_OK;
}

HRESULT __stdcall D3DResetHook(SAMP::CallBacks::HookedStructs::stResetParams *params) {

	if (isPluginInitialized) {
		ImGui_ImplDX9_InvalidateDeviceObjects();
		pRender->Invalidate();
	}

	return D3D_OK;
}

bool __stdcall RakClientSendHook(SAMP::CallBacks::HookedStructs::stRakClientSend *params) {

	if (params->bitStream->GetData()[0] == ID_PLAYER_SYNC) {
		params->bitStream->ResetReadPointer();
		params->bitStream->IgnoreBits(8);
		stOnFootData data = { 0 };
		params->bitStream->Read((PCHAR)&data, sizeof(stOnFootData));

		//data.fMoveSpeed[2] = 1.0f;

		params->bitStream->ResetWritePointer();
		params->bitStream->Write<unsigned __int8>(ID_PLAYER_SYNC);
		params->bitStream->Write((PCHAR)&data, sizeof(stOnFootData));
	}

	return true;
}

bool __stdcall RakClientRecvHook(SAMP::CallBacks::HookedStructs::stRakClientRecv *params) {

	return true;
}

bool __stdcall RakClientRPCHook(SAMP::CallBacks::HookedStructs::stRakClientRPC *params) {

	return true;
}

bool __stdcall RakClientRPCRecvHook(SAMP::CallBacks::HookedStructs::stRakClientRPCRecv *params) {

	return true;
}


void __cdecl cmd(char *params) {
	isOpen ^= true;
}

void __stdcall GameLoop() {
	static bool initialized = false;
	if (!initialized) {
		if (SAMP::pSAMP->LoadAPI()) {
			initialized = true;
			
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO();
			io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 16, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
			(void)io;
			ImGui_ImplWin32_Init(GetActiveWindow());
			ImGui_ImplDX9_Init(SAMP::CallBacks::pCallBackRegister->GetIDirect3DDevice9());
			ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
			//render
			pRender = std::make_unique<CD3DRender>(128);

			//initialization
			SAMP::pSAMP->addClientCommand("menu", cmd);
			SAMP::pSAMP->addMessageToChat(-1, "SAMP API By AdCKuY_DpO4uLa loaded. %s", SAMP::pSAMP->getInfo()->szIP);
			
			//init raknet callbacks
			SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientSendHook);//registed RakClient Send Hook
			SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientRecvHook);//registed RakClient Recv Hook
			SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientRPCHook);//registed RakClient RPC Hook
			SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientRPCRecvHook);//registed RakClient RPC recv Hook
			
			isPluginInitialized = true;
		}
	}
	if (initialized) {	//gameLoop


		

	}
}



int __stdcall DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
		case DLL_PROCESS_ATTACH: {
			SAMP::Init();
			SAMP::CallBacks::pCallBackRegister->RegisterGameLoopCallback(GameLoop);//register gameloop hook
			SAMP::CallBacks::pCallBackRegister->RegisterWndProcCallback(WndProcCallBack);//register wnd proc hook
			SAMP::CallBacks::pCallBackRegister->RegisterD3DCallback(D3DPresentHook);//register D3D present hook
			SAMP::CallBacks::pCallBackRegister->RegisterD3DCallback(D3DResetHook);//register D3D reset hook
			printf("\n -> Plugin loaded (%d)\n", GetTickCount());
			break; 
		}
		case DLL_PROCESS_DETACH: {
			SAMP::pSAMP->unregisterChatCommand(cmd);

			SAMP::ShutDown();

			ImGui_ImplDX9_Shutdown();
			ImGui_ImplWin32_Shutdown();
			ImGui::DestroyContext();

			printf("\n -> Plugin unloaded (%d)\n", GetTickCount());
			break; 
		}
	}
	return true;
}