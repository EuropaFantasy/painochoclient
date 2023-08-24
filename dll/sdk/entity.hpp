#pragma once

#include <jni.h>

#include "object.hpp"
#include "vec3.hpp"

class Entity : public Object {
    jmethodID m_setSprintingMID;
    jmethodID m_positionMID;
    jfieldID m_posXFID, m_posYFID, m_posZFID;

    double getPosX189();

    double getPosY189();

    double getPosZ189();

    friend class Vec3;

public:
    Entity(jobject obj, Minecraft *mc);

    void setSprinting(bool value);

    Vec3 *position();
};