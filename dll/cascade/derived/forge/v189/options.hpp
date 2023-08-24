#pragma once

#include "../../../base/options.hpp"

class Forge189Options : Options {
public:
    explicit Forge189Options(jobject obj, JNIEnv *env, jvmtiEnv *tiEnv);
};