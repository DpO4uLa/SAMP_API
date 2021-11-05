#include <Windows.h>
#include <string>

#include "SAMP/SAMP.hpp"


LRESULT __stdcall WndProcCallBack(SAMP::CallBacks::HookedStructs::stWndProcParams *params) {
	
	return 0;//retn null if all good
}

HRESULT __stdcall D3DPresentHook(SAMP::CallBacks::HookedStructs::stPresentParams *params) {
	
	return D3D_OK;
}

HRESULT __stdcall D3DResetHook(SAMP::CallBacks::HookedStructs::stResetParams *params) {

	return D3D_OK;
}

bool __stdcall RakClientSendHook(SAMP::CallBacks::HookedStructs::stRakClientSend *params) {

	return true;
}

bool __stdcall RakClientRPCHook(SAMP::CallBacks::HookedStructs::stRakClientRPC *params) {

	return true;
}

void __stdcall GameLoop() {
	static bool initialized = false;
	if (!initialized) {
		if (SAMP::pSAMP->LoadAPI()) {
			initialized = true;


			//initialization
			SAMP::pSAMP->addMessageToChat(-1, "SAMP API By AdCKuY_DpO4uLa loaded. %s", SAMP::pSAMP->getInfo()->szIP);

		
			

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
			SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientRPCHook);//registed RakClient RPC Hook
			printf("\n -> Plugin loaded (%d)\n", GetTickCount());
			break; 
		}
		case DLL_PROCESS_DETACH: {
			delete SAMP::CallBacks::pCallBackRegister;
			delete SAMP::pSAMP;
			SAMP::CallBacks::pCallBackRegister = nullptr;
			SAMP::pSAMP = nullptr;
			printf("\n -> Plugin unloaded (%d)\n", GetTickCount());
			break; 
		}
	}
	return true;
}