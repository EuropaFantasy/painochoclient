#pragma once

#include <jni.h>

class Minecraft;

class PlayerCapabilities {
    jclass m_cls;
    jobject m_obj;

    jfieldID m_isFlyingFID;

    Minecraft *m_mc;
public:
    PlayerCapabilities(jobject obj, Minecraft *mc);

    void setFlying(bool flying);
};