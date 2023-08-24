#include "moduleManager.hpp"
#include "fastPlace.hpp"
ModuleManager::ModuleManager(std::shared_ptr<Minecraft> mc) {
    modules["FastPlace"] = std::make_unique<FastPlace>(mc);
    modules["FastPlace"]->setToggled(true);
}

void ModuleManager::onTick() {
    for (auto & module : modules) {
        if(module.second->isToggled()) module.second->onTick();
    }
}

void ModuleManager::onRender() {
    for (auto & module : modules) {
        if(module.second->isToggled()) module.second->onRender();
    }
}

void ModuleManager::setToggled(std::string_view name, bool toggled) {
    modules[name]->setToggled(toggled);
}

void ModuleManager::toggle(std::string_view name) {
    modules[name]->toggle();
}
#include <iostream>
void ModuleManager::test() {
    std::cout << "test" << std::endl;

    modules["FastPlace"]->onTick();
}