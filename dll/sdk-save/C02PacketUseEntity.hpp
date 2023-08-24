#pragma once

#include <jni.h>

#include "entity.hpp"

class Minecraft;

class C02PacketUseEntity {
protected:
    jclass m_cls;
    jobject m_obj;

    jmethodID m_initMID;
    jfieldID m_actionFID;
    jobject m_actionObj;
    jclass m_actionCls;

    Minecraft *m_mc;

public:
    C02PacketUseEntity(Entity *entity, Minecraft *mc);

    jobject getObj();
};