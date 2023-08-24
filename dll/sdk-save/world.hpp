#pragma once

#include <jni.h>

#include <vector>

#include "entity.hpp"

class Minecraft;

class World {
protected:
    jclass m_cls;
    jobject m_obj;
    jfieldID m_fID;

    jfieldID m_loadedEntityListFID;

    Minecraft *m_mc;

public:
    World(jobject obj, Minecraft *mc);

    std::vector<Entity *> getLoadedEntityList();
};