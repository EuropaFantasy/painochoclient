#pragma once

#include <jni.h>

#include "player.hpp"
#include "netHandlerPlayClient.hpp"

class LocalPlayer : public Player {
    jfieldID m_sendQueueFID;

public:
    LocalPlayer(jobject obj, Minecraft *mc);

    void strafe(float speed);

    double getDirection();

    NetHandlerPlayClient *getSendQueue();
};