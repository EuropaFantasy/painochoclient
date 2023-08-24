#include "object.hpp"
#include "minecraft.hpp"

Object::Object(Env env) : m_env(env) {
    m_cls = getEnv().jni->GetObjectClass(getEnv().obj);
}

jclass Object::getClass() const {
    return m_cls;
}

Env Object::getEnv() const {
    return m_env;
}