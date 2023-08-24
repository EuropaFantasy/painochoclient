#pragma once

#include "../client.hpp"

#include <jni.h>

namespace csc::detect {
    Client client(JNIEnv * env) {
        jclass forgeClass = env->FindClass("net/minecraftforge/common/ForgeVersion");
        if (forgeClass != nullptr) {
            env->DeleteLocalRef(forgeClass);
            return Client::Forge;
        }
        if (env->FindClass("a")) {
            return Client::Vanilla;
        }
        return Client::Lunar;
    }
}
