#pragma once

#include <windows.h>

#ifdef DLL
#define WAUAPI extern "C" __declspec(dllexport)
#else
#define WAUAPI extern "C" __declspec(dllimport)
#endif

namespace wau
{
  WAUAPI HANDLE getHandle(const char *procName);
  WAUAPI bool injectDll(HANDLE proc, const char *dllPath);
}