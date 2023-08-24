#pragma once

#include "base/minecraft.hpp"

#include "client.hpp"
#include "version.hpp"

namespace csc {

    void init(JNIEnv *env, jvmtiEnv *tiEnv);
    std::shared_ptr<Minecraft> getMc();
    Client getClient();
    Version getVersion();

    void test();
}