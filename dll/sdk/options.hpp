#pragma once

#include "object.hpp"
#include "keyMapping.hpp"

class Options : public Object
{
  jfieldID m_keyAttackFID;

public:
  Options(jobject obj, Minecraft *mc);
  KeyMapping *getKeyAttack();
};