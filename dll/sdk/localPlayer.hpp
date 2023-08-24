#pragma once

#include "entity.hpp"

class Minecraft;

class LocalPlayer : public Entity
{

public:
  LocalPlayer(jobject obj, Minecraft *mc);
};