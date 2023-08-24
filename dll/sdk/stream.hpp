#pragma once

#include "object.hpp"

class Stream : public Object
{
  jmethodID m_filterMID,
      m_collectMID;

public:
  Stream(jobject obj, Minecraft *mc);
  Stream *filter();
  jobject *collect();
};