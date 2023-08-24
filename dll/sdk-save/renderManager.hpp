#pragma once

#include <jni.h>

class Minecraft;

class RenderManager {
protected:
    jclass m_cls;
    jobject m_obj;

    jfieldID m_renderPosXFID;
    jfieldID m_renderPosYFID;
    jfieldID m_renderPosZFID;

    Minecraft *m_mc;

public:
    RenderManager(jobject obj, Minecraft *mc);

    double getRenderPosX();

    double getRenderPosY();

    double getRenderPosZ();
};