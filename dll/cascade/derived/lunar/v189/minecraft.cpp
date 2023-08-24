#include "minecraft.hpp"

Lunar189Minecraft::Lunar189Minecraft(Env env) : Minecraft(env) {
    m_rightClickDelayFID = getEnv().jni->GetFieldID(getClass(), "rightClickDelayTimer", "I");
}