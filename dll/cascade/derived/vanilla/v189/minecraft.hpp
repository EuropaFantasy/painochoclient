#pragma once

#include "../../../base/minecraft.hpp"

#include "options.hpp"

class Vanilla189Minecraft : public Minecraft {
public:
    explicit Vanilla189Minecraft(Env env);
    std::unique_ptr<Options> getOptions() override;
};