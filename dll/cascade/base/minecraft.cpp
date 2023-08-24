#include "minecraft.hpp"

Minecraft::Minecraft(Env env) : Object(env) {
}

void Minecraft::setRightClickDelay(int delay) {
    getEnv().jni->SetIntField(getEnv().obj, m_rightClickDelayFID, delay);
}