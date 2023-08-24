#include "keyMapping.hpp"
#include "minecraft.hpp"

KeyMapping::KeyMapping(jobject obj, Minecraft *mc) : Object(obj, mc)
{
  m_getNameMID = m_mc->getEnv()->GetMethodID(m_cls, "h", "Ljava/lang/String;");
}

const char *KeyMapping::getName()
{
  jstring ret = (jstring)m_mc->getEnv()->CallObjectMethod(m_obj, m_getNameMID);
  return m_mc->getEnv()->GetStringUTFChars(ret, 0);
}