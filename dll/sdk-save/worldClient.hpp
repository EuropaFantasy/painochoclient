#pragma once

#include "world.hpp"

class WorldClient : public World
{
  jclass m_cls;
  jobject m_obj;
  jfieldID m_fID;

  jfieldID m_loadedEntityListFID;

  Minecraft *m_mc;

public:
  WorldClient(jobject obj, Minecraft *mc);
};