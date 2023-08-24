#pragma once

#include "object.hpp"

class KeyMapping : public Object
{
  jmethodID m_getNameMID;

public:
  KeyMapping(jobject obj, Minecraft *mc);
  const char *getName();
};