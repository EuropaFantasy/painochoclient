#pragma once

#include "../../../base/minecraft.hpp"

class Forge189Minecraft : public Minecraft {
public:
    explicit Forge189Minecraft(jobject obj, JNIEnv *env, jvmtiEnv *tiEnv);
    std::unique_ptr<Options> getOptions();
};