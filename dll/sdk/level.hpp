#pragma once

#include "object.hpp"
#include "list.hpp"

class Level : public Object
{
  jmethodID m_playersMID,
      m_getLoadedEntityListMID;

public:
  Level(jobject obj, Minecraft *mc);
  List *players();
};