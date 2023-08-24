#include "player.hpp"
#include "minecraft.hpp"

Player::Player(jobject obj, Minecraft *mc) : LivingEntity(obj, mc)
{

  if (m_mc->getClient() == Client::Forge)
  {
    m_isUsingItemMID = m_mc->getEnv()->GetMethodID(m_cls, "func_71039_bw", "()Z");
    m_capabilitiesFID = m_mc->getEnv()->GetFieldID(m_cls, "field_71075_bZ", "Lwl;");
  }
  else if (m_mc->getClient() == Client::Lunar)
  {
    m_isUsingItemMID = m_mc->getEnv()->GetMethodID(m_cls, "isUsingItem", "()Z");
    m_capabilitiesFID = m_mc->getEnv()->GetFieldID(m_cls, "capabilities", "Lwl;");
  }
  else if (m_mc->getClient() == Client::Vanilla)
  {
    m_isUsingItemMID = m_mc->getEnv()->GetMethodID(m_cls, "bS", "()Z");
    m_capabilitiesFID = m_mc->getEnv()->GetFieldID(m_cls, "bA", "Lwl;");
  }
}

bool Player::isUsingItem()
{
  return m_mc->getEnv()->CallBooleanMethod(m_obj, m_isUsingItemMID);
}

PlayerCapabilities *Player::getCapabilities()
{
  return new PlayerCapabilities(m_mc->getEnv()->GetObjectField(m_obj, m_capabilitiesFID), m_mc);
}