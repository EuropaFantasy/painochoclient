#pragma once

#include <jni.h>

#include "entity.hpp"

class LivingEntity : public Entity {
    jmethodID m_swingItemMID;
    jfieldID m_moveForwardFID;
    jfieldID m_moveStrafingFID;

public:
    LivingEntity(jobject obj, Minecraft *mc);

    void swingItem();

    float getMoveForward();

    float getMoveStrafing();

    bool isMoving();
};