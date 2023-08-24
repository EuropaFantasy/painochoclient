#include "minecraft.hpp"

Forge189Minecraft::Forge189Minecraft(jobject obj, JNIEnv *env, jvmtiEnv *tiEnv) : Minecraft(obj, env, tiEnv) {
    m_rightClickDelayFID = env->GetFieldID(getClass(), "field_71467_ac", "I");
}