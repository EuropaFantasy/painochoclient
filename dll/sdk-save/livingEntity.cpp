#include "livingEntity.hpp"
#include "minecraft.hpp"

LivingEntity::LivingEntity(jobject obj, Minecraft *mc) : Entity(obj, mc)
{
  if (mc->getClient() == Client::Forge)
  {
    m_swingItemMID = m_mc->getEnv()->GetMethodID(m_cls, "func_71038_i", "()V");
    m_moveForwardFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70701_bs", "F");
    m_moveStrafingFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70702_br", "F");
  }
  else if (mc->getClient() == Client::Lunar)
  {
    m_swingItemMID = m_mc->getEnv()->GetMethodID(m_cls, "swingItem", "()V");
    m_moveForwardFID = m_mc->getEnv()->GetFieldID(m_cls, "moveForward", "F");
    m_moveStrafingFID = m_mc->getEnv()->GetFieldID(m_cls, "moveStrafing", "F");
  }
  else if (mc->getClient() == Client::Vanilla)
  {
    m_swingItemMID = m_mc->getEnv()->GetMethodID(m_cls, "bw", "()V");
    m_moveForwardFID = m_mc->getEnv()->GetFieldID(m_cls, "ba", "F");
    m_moveStrafingFID = m_mc->getEnv()->GetFieldID(m_cls, "aZ", "F");
  }
}

void LivingEntity::swingItem()
{
  m_mc->getEnv()->CallVoidMethod(m_obj, m_swingItemMID);
}

float LivingEntity::getMoveForward()
{
  return m_mc->getEnv()->GetFloatField(m_obj, m_moveForwardFID);
}

float LivingEntity::getMoveStrafing()
{
  return m_mc->getEnv()->GetFloatField(m_obj, m_moveStrafingFID);
}

bool LivingEntity::isMoving()
{
  return (getMoveForward() != 0 || getMoveStrafing() != 0);
}