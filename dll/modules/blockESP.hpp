#pragma once

#include "module.hpp"

class BlockESP : public Module
{
public:
  BlockESP(std::shared_ptr<Minecraft> mc);
  void onRender();
};