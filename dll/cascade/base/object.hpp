#pragma once

#include "../env.hpp"

#include <string>

#include <jni.h>
#include <jvmti.h>

class Minecraft;

class Object {
    jclass m_cls;
    Env m_env;

public:
    Object(Env env);

    [[nodiscard]] jclass getClass() const;

    [[nodiscard]] Env getEnv() const;
};