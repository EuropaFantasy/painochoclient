#pragma once

#include <jni.h>

class Minecraft;

class NetHandlerPlayClient {
    jclass m_cls;
    jobject m_obj;

    jmethodID m_addToSendQueueFID;

    Minecraft *m_mc;

public:
    NetHandlerPlayClient(jobject obj, Minecraft *mc);

    void addToSendQueue();
};