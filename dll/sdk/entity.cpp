#include "entity.hpp"
#include "minecraft.hpp"

Entity::Entity(jobject obj, Minecraft *mc) : Object(obj, mc)
{
  if (m_mc->getClient() == Client::Forge)
  {
    if (m_mc->getVersion() == Version::v189)
    {
      m_setSprintingMID = m_mc->getEnv()->GetMethodID(m_cls, "func_70031_b", "(Z)V");
      m_posXFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70165_t", "D");
      m_posYFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70163_u", "D");
      m_posZFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70161_v", "D");
      return;
    }
    /*if (m_mc->getVersion() == Version::v1201 || m_mc->getVersion() == Version::v120)
    {
      m_setSprintingMID = m_mc->getEnv()->GetMethodID(m_cls, "m_6858_", "(Z)V");
      return;
    }*/
  }
  if (m_mc->getClient() == Client::Lunar)
  {
    m_setSprintingMID = m_mc->getEnv()->GetMethodID(m_cls, "setSprinting", "(Z)V");
    return;
  }
  if (m_mc->getClient() == Client::Vanilla)
  {
    if (m_mc->getVersion() == Version::v189)
    {
      m_setSprintingMID = m_mc->getEnv()->GetMethodID(m_cls, "d", "(Z)V");
      m_posXFID = m_mc->getEnv()->GetFieldID(m_cls, "s", "D");
      m_posYFID = m_mc->getEnv()->GetFieldID(m_cls, "t", "D");
      m_posZFID = m_mc->getEnv()->GetFieldID(m_cls, "u", "D");
    }
    if (m_mc->getVersion() == Version::v1201 || m_mc->getVersion() == Version::v120)
    {
      m_setSprintingMID = m_mc->getEnv()->GetMethodID(m_cls, "g", "(Z)V");
      m_positionMID = m_mc->getEnv()->GetMethodID(m_cls, "dg", "()Leei;");
    }
  }
}

void Entity::setSprinting(bool value)
{
  // std::cout << (m_setSprintingMID == NULL) << std::endl;
  m_mc->getEnv()->CallVoidMethod(m_obj, m_setSprintingMID, value);
}

double Entity::getPosX189()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_posXFID);
}
double Entity::getPosY189()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_posYFID);
}
double Entity::getPosZ189()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_posZFID);
}

Vec3 *Entity::position()
{
  if (m_mc->getClient() == Client::Vanilla)
  {
    if (m_mc->getVersion() == Version::v1201 || m_mc->getVersion() == Version::v120)
      return new Vec3(m_mc->getEnv()->CallObjectMethod(m_obj, m_positionMID), m_mc);

    if (m_mc->getVersion() == Version::v189)
      return new Vec3(this, m_mc);
  }
  return nullptr;
}