#pragma once

#include "minecraft.hpp"

std::shared_ptr<Lunar189Minecraft> lunar189(JNIEnv *env, jvmtiEnv *tiEnv) {
    jclass cls = findClass("net/minecraft/client/Minecraft", env, tiEnv);
    jfieldID fID = env->GetStaticFieldID(cls, "theMinecraft", "Lnet/minecraft/client/Minecraft;");

    Env objEnv{};

    objEnv.obj = env->GetStaticObjectField(cls, fID);
    objEnv.jni = env;
    objEnv.jvmti = tiEnv;

    return std::make_shared<Lunar189Minecraft>(objEnv);
}