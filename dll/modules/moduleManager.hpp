#pragma once

#include "module.hpp"

#include <map>
#include <string_view>

class ModuleManager {
public:
    std::map<std::string_view, std::unique_ptr<Module>> modules;

    explicit ModuleManager(std::shared_ptr<Minecraft> mc);
    void onTick();
    void onRender();
    void setToggled(std::string_view name, bool toggled);
    void toggle(std::string_view name);
    void test();
};