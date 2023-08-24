#pragma once

#include <jni.h>

#include "axisAlignedBB.hpp"

class Minecraft;

class Entity {
protected:
    jclass m_cls;
    jobject m_obj;

    jmethodID m_setSprintingMID;
    jmethodID m_isSneakingMID;
    jfieldID m_ticksExistedFID;
    jfieldID m_isDeadFID;
    jfieldID m_motionXFID;
    jfieldID m_motionYFID;
    jfieldID m_motionZFID;
    jfieldID m_fallDistanceFID;
    jfieldID m_rotationYawFID;
    jfieldID m_rotationPitchFID;
    jmethodID m_getDistanceToEntityMID;
    jfieldID m_lastTickPosXFID;
    jfieldID m_lastTickPosYFID;
    jfieldID m_lastTickPosZFID;
    jfieldID m_posXFID;
    jfieldID m_posYFID;
    jfieldID m_posZFID;
    jmethodID m_getEntityBoundingBoxMID;

    Minecraft *m_mc;

public:
    Entity(jobject obj, Minecraft *mc);

    void setSprinting(bool sprinting);

    bool isSneaking();

    int getTicksExisted();

    bool isDead();

    double getMotionX();

    void setMotionX(double x);

    double getMotionY();

    void setMotionY(double y);

    double getMotionZ();

    void setMotionZ(double z);

    float getFallDistance();

    void setFallDistance(float fallDistance);

    float getRotationYaw();

    void setRotationYaw(float yaw);

    float getRotationPitch();

    void setRotationPitch(float pitch);

    float getDistanceToEntity(Entity *entity);

    double getLastTickPosX();

    double getLastTickPosY();

    double getLastTickPosZ();

    double getPosX();

    double getPosY();

    double getPosZ();

    AxisAlignedBB *getEntityBoundingBox();

    jobject getObj();
};