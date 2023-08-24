#pragma once

#include <jni.h>

class Minecraft;

class AxisAlignedBB {
    jclass m_cls;
    jobject m_obj;

    jfieldID m_minXFID;
    jfieldID m_minYFID;
    jfieldID m_minZFID;
    jfieldID m_maxXFID;
    jfieldID m_maxYFID;
    jfieldID m_maxZFID;

    Minecraft *m_mc;

public:
    AxisAlignedBB(jobject obj, Minecraft *mc);

    double getMinX();

    double getMinY();

    double getMinZ();

    double getMaxX();

    double getMaxY();

    double getMaxZ();
};