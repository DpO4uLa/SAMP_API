#ifndef MEMWRAPPER_H_
#define MEMWRAPPER_H_

#if defined(_WIN32) && !defined(_WIN64)
#    define MEMWRAPPER_WIN_X86
#endif   // defined(_WIN32) && !defined(_WIN64)

#if !defined(MEMWRAPPER_WIN_X86)
#    error "only win86 supported."
#endif

#if !((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#    error "only c++17 and newer."
#endif   // !((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >=
         // 201703L)

#if defined(MEMWRAPPER_WIN_X86)
#    include <Windows.h>
#endif   // defined(MEMWRAPPER_WIN_X86)

#include <cstdint>
#include <string>
#include <vector>

#if defined(MEMWRAPPER_WIN_X86)
#    include "hde/hde32.h"

#    include "x86/memwrapper_basic.hpp"
#    include "x86/memwrapper_llmo.hpp"
#    include "x86/memwrapper_detail.hpp"
#    include "x86/memwrapper_allocator.hpp"
#    include "x86/memwrapper_hook.hpp"
#endif   // defined(MEMWRAPPER_WIN_X86)

#endif   // !MEMWRAPPER_H_
