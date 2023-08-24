#include "options.hpp"
#include "minecraft.hpp"

Options::Options(jobject obj, Minecraft *mc) : Object(obj, mc)
{
  m_keyAttackFID = m_mc->getEnv()->GetFieldID(m_cls, "I", "Lenl;");
}

KeyMapping *Options::getKeyAttack()
{
  return new KeyMapping(m_mc->getEnv()->GetObjectField(m_obj, m_keyAttackFID), m_mc);
}