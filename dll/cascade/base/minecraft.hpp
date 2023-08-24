#pragma once

#include "object.hpp"
#include "options.hpp"

#include <memory>

class Minecraft : public Object {
protected:
    jfieldID m_rightClickDelayFID{};
    jfieldID m_optionsFID{};

public:
    explicit Minecraft(Env env);
    void setRightClickDelay(int delay);
    virtual std::unique_ptr<Options> getOptions() = 0;
};