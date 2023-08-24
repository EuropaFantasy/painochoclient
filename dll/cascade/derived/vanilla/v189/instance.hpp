#pragma once

#include "minecraft.hpp"

#include <memory>

std::shared_ptr<Vanilla189Minecraft> vanilla189(JNIEnv *env, jvmtiEnv *tiEnv) {
    jclass cls = env->FindClass("ave");
    jfieldID fID = env->GetStaticFieldID(cls, "S", "Lave;");

    Env objEnv{};

    objEnv.obj = env->GetStaticObjectField(cls, fID);
    objEnv.jni = env;
    objEnv.jvmti = tiEnv;

    return std::make_shared<Vanilla189Minecraft>(objEnv);
}