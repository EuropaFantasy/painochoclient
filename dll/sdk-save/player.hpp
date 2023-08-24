#pragma once

#include <jni.h>

#include "livingEntity.hpp"
#include "playerCapabilities.hpp"

class Player : public LivingEntity {
    jmethodID m_isUsingItemMID;
    jfieldID m_capabilitiesFID;

public:
    Player(jobject obj, Minecraft *mc);

    bool isUsingItem();

    PlayerCapabilities *getCapabilities();
};