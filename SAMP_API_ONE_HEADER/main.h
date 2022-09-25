#pragma once
#include <Windows.h>
#include <string>


//юзать онли в определениях препроцессора
//#define SAMP_R1_COMPILE
//#define SAMP_R3_COMPILE

#include "SAMP/SAMP.hpp"

#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_dx9.h"
#include "ImGUI/imgui_impl_win32.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);