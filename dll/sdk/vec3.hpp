#pragma once

#include <jni.h>

#include "object.hpp"

class Entity;

class Vec3 : public Object {
    jfieldID m_xFID,
            m_yFID,
            m_zFID;

    Entity *m_entity;

public:
    Vec3(jobject obj, Minecraft *mc);

    Vec3(Entity *entity, Minecraft *mc);

    double getX();

    double getY();

    double getZ();
};