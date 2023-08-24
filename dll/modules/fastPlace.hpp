#pragma once

#include "module.hpp"

class FastPlace : public Module {
public:
    explicit FastPlace(std::shared_ptr<Minecraft> mc);

    void onTick() override;
};

