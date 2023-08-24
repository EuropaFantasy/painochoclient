#include "vec3.hpp"
#include "minecraft.hpp"
#include "entity.hpp"

Vec3::Vec3(jobject obj, Minecraft *mc) : Object(obj, mc)
{
  if (m_mc->getClient() == Client::Forge)
  {
  }
  if (m_mc->getClient() == Client::Lunar)
  {
  }
  if (m_mc->getClient() == Client::Vanilla)
  {
    if (m_mc->getVersion() == Version::v189)
    {
      std::cout << "Constructor for 1.20.1/1.20 called when client is 1.8.9. Undefined behavior may happen." << std::endl;
      return;
    }
    if (m_mc->getVersion() == Version::v1201 || m_mc->getVersion() == Version::v120)
    {
      m_xFID = m_mc->getEnv()->GetFieldID(m_cls, "c", "D");
      m_yFID = m_mc->getEnv()->GetFieldID(m_cls, "d", "D");
      m_zFID = m_mc->getEnv()->GetFieldID(m_cls, "e", "D");
    }
  }
}

Vec3::Vec3(Entity *entity, Minecraft *mc) : Object(mc)
{
  m_entity = entity;
}

double Vec3::getX()
{
  if (m_mc->getVersion() == Version::v189)
    return m_entity->getPosX189();
  return m_mc->getEnv()->GetDoubleField(m_obj, m_xFID);
}
double Vec3::getY()
{
  if (m_mc->getVersion() == Version::v189)
    return m_entity->getPosY189();

  return m_mc->getEnv()->GetDoubleField(m_obj, m_yFID);
}
double Vec3::getZ()
{

  if (m_mc->getVersion() == Version::v189)
    return m_entity->getPosZ189();

  return m_mc->getEnv()->GetDoubleField(m_obj, m_zFID);
}