#pragma once

#include <string_view>

#include "../cascade/base/minecraft.hpp"

class Module {
    std::string_view m_name;
    bool m_toggled{};
    std::shared_ptr<Minecraft> m_mc;

protected:

    [[nodiscard]] std::shared_ptr<Minecraft> getMc() const;
public:
    Module(std::string_view name, std::shared_ptr<Minecraft> mc);
    Module();

    virtual void onTick();

    virtual void onRender();

    virtual void onEnable();

    virtual void onDisable();

    void toggle();

    void setToggled(bool toggled);

    [[nodiscard]] bool isToggled() const;

    [[nodiscard]] std::string_view getName() const;
};