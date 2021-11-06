#include "main.h"

bool isPluginInitialized = false;

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

				ImGui::Button(u8"тестовая кнопка");

				ImGui::End();
			}
		}

		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	}

	return D3D_OK;
}

HRESULT __stdcall D3DResetHook(SAMP::CallBacks::HookedStructs::stResetParams *params) {

	if(isPluginInitialized)
		ImGui_ImplDX9_InvalidateDeviceObjects();

	return D3D_OK;
}

bool __stdcall RakClientSendHook(SAMP::CallBacks::HookedStructs::stRakClientSend *params) {

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

			//initialization
			SAMP::pSAMP->addClientCommand("menu1", cmd);
			SAMP::pSAMP->addMessageToChat(-1, "SAMP API By AdCKuY_DpO4uLa loaded. %s", SAMP::pSAMP->getInfo()->szIP);


			
			
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
			DWORD base = (DWORD)GetModuleHandleA("samp.dll");
			SAMP::pSAMP = new SAMP::CSAMP(base);
			SAMP::CallBacks::pCallBackRegister = new SAMP::CallBacks::CCallbackRegister(base);
			SAMP::CallBacks::pCallBackRegister->RegisterGameLoopCallback(GameLoop);//register gameloop hook
			SAMP::CallBacks::pCallBackRegister->RegisterWndProcCallback(WndProcCallBack);//register wnd proc hook
			SAMP::CallBacks::pCallBackRegister->RegisterD3DCallback(D3DPresentHook);//register D3D present hook
			SAMP::CallBacks::pCallBackRegister->RegisterD3DCallback(D3DResetHook);//register D3D reset hook
			SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientSendHook);//registed RakClient Send Hook
			SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientRecvHook);//registed RakClient Recv Hook
			SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientRPCHook);//registed RakClient RPC Hook
			SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientRPCRecvHook);//registed RakClient RPC recv Hook
			printf("\n -> Plugin loaded (%d)\n", GetTickCount());
			break; 
		}
		case DLL_PROCESS_DETACH: {
			SAMP::pSAMP->unregisterChatCommand(cmd);

			delete SAMP::CallBacks::pCallBackRegister;
			delete SAMP::pSAMP;
			SAMP::CallBacks::pCallBackRegister = nullptr;
			SAMP::pSAMP = nullptr;

			ImGui_ImplDX9_Shutdown();
			ImGui_ImplWin32_Shutdown();
			ImGui::DestroyContext();

			printf("\n -> Plugin unloaded (%d)\n", GetTickCount());
			break; 
		}
	}
	return true;
}