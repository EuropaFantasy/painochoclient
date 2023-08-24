#include "minecraft.hpp"

Vanilla189Minecraft::Vanilla189Minecraft(Env env) : Minecraft(env) {
    m_rightClickDelayFID = getEnv().jni->GetFieldID(getClass(), "ap", "I");
    m_optionsFID = getEnv().jni->GetFieldID(getClass(), "t", "Lavh;");
}

std::unique_ptr<Options> Vanilla189Minecraft::getOptions() {
    Env env = getEnv();
    env.obj = getEnv().jni->GetObjectField(getEnv().obj, m_optionsFID);
    return std::make_unique<Options>(env);
}