#pragma once

#include <GL/gl.h>

#if defined(GLFW) || defined(DLL)
#include <GLFW/glfw3.h>
#endif

#include "../inj/imgui/imgui.h"

#ifdef DLL
#define WDAPI extern "C" __declspec(dllexport)
#else
#define WDAPI extern "C" __declspec(dllimport)
#endif

namespace wd {
    WDAPI void start(void (*drawCallback)(), void (*init)(), int x, int y, int w, int h, bool mousePassthrough = true,
                     bool onTop = true);
    WDAPI void stop();
    WDAPI void setSize(int w, int h);
    WDAPI void getSize(int *w, int *h);
    WDAPI void setPos(int x, int y);
    WDAPI void getPos(int *w, int *h);
#if defined(GLFW) || defined(DLL)
    WDAPI GLFWwindow *getGLFWWindow();
#endif
    WDAPI ImGuiContext *getImGuiContext();

    void initContext() { ImGui::SetCurrentContext(wd::getImGuiContext()); }
}
