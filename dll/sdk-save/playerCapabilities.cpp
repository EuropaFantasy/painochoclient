#include "playerCapabilities.hpp"

#include "minecraft.hpp"

PlayerCapabilities::PlayerCapabilities(jobject obj, Minecraft *mc) : m_obj(obj), m_mc(mc) {
  m_cls = m_mc->getEnv()->GetObjectClass(m_obj);
  m_isFlyingFID = m_mc->getEnv()->GetFieldID(m_cls, "b", "Z");
}

void PlayerCapabilities::setFlying(bool flying) {
  m_mc->getEnv()->SetBooleanField(m_obj, m_isFlyingFID, flying);
}