#include "module.hpp"

Module::Module(std::string_view name, std::shared_ptr<Minecraft> mc) : m_name(name), m_toggled(false) {
    m_mc = std::move(mc);
}

Module::Module() : m_toggled(false) {}

void Module::onTick() {}

void Module::onEnable() {
}

void Module::onDisable() {
}

void Module::onRender() {}

void Module::toggle() {
    m_toggled = !m_toggled;
    if(m_toggled) onEnable();
    if(!m_toggled) onDisable();
}

void Module::setToggled(bool toggled) {
    m_toggled = toggled;
}

bool Module::isToggled() const {
    return m_toggled;
}

std::shared_ptr<Minecraft> Module::getMc() const {
    return std::move(m_mc);
}

std::string_view Module::getName() const {
    return m_name;
}