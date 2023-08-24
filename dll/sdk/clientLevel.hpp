#pragma once

#include "level.hpp"

class ClientLevel : public Level
{
public:
  ClientLevel(jobject obj, Minecraft *mc);
};