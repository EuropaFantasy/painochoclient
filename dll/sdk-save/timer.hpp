#pragma once

#include <jni.h>

class Minecraft;

class Timer {
    jclass m_cls;
    jobject m_obj;

    jfieldID m_renderPartialTicksFID;

    Minecraft *m_mc;

public:
    Timer(jobject obj, Minecraft *mc);

    float getRenderPartialTicks();
};