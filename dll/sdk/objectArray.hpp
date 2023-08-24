#pragma once

#include "object.hpp"

class ObjectArray : public Object
{
  jobjectArray m_objArray;

public:
  ObjectArray(jobjectArray objArray, Minecraft *mc);
  jobjectArray getObjectArray() const;
  int length();
  Object *get(int index);
};