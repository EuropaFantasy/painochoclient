#pragma once

#include "minecraft.hpp"

#include "../../../findClass.hpp"

std::shared_ptr<Forge189Minecraft> forge189(JNIEnv *env, jvmtiEnv *tiEnv) {
    jclass cls = findClass("net/minecraft/client/Minecraft", env, tiEnv);
    jfieldID fID = env->GetStaticFieldID(cls, "field_71432_P", "Lnet/minecraft/client/Minecraft;");

    Env objEnv{};

    objEnv.obj = env->GetStaticObjectField(cls, fID);
    objEnv.jni = env;
    objEnv.jvmti = tiEnv;

    return std::make_shared<Forge189Minecraft>(objEnv);
}