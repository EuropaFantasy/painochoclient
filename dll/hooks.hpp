#pragma once

#include "minhook/MinHook.h"
#include <GL/gl.h>
#include "modules/moduleManager.hpp"

std::unique_ptr<ModuleManager> manager;

static bool __stdcall wglSwapBuffers(HDC hDc);
void *swapBuffers;
typedef BOOL(__stdcall *twglSwapBuffers)(HDC hDc);
twglSwapBuffers owglSwapBuffers;

void installHooks()
{
  swapBuffers = (void *)GetProcAddress(GetModuleHandle("opengl32.dll"), "wglSwapBuffers");

  MH_Initialize();
  MH_CreateHook(swapBuffers, (LPVOID *)&wglSwapBuffers, (LPVOID *)&owglSwapBuffers);
  MH_EnableHook(swapBuffers);
}

void removeHooks()
{
  MH_RemoveHook(swapBuffers);
}

bool __stdcall wglSwapBuffers(HDC hDc)
{
  static HGLRC oContext = wglGetCurrentContext();
  static HGLRC newContext = wglCreateContext(hDc);

  static bool init = false;
  if (!init)
  {
    wglMakeCurrent(hDc, newContext);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, 640, 480, 0.0, 1.0, -1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0, 0, 0, 1.0);

    init = true;
  }
  else
  {
    wglMakeCurrent(hDc, newContext);

    manager->onRender();
  }

  wglMakeCurrent(hDc, oContext);

  return owglSwapBuffers(hDc);
}