#include "level.hpp"
#include "minecraft.hpp"

Level::Level(jobject obj, Minecraft *mc) : Object(obj, mc)
{
  if (m_mc->getClient() == Client::Forge)
  {
  }
  if (m_mc->getClient() == Client::Lunar)
  {
  }
  if (m_mc->getClient() == Client::Vanilla)
  {
    if (m_mc->getVersion() == Version::v1201 || m_mc->getVersion() == Version::v120)
    {
      m_playersMID = m_mc->getEnv()->GetMethodID(m_cls, "v", "()Ljava/util/List;");
    }
    if (m_mc->getVersion() == Version::v189)
    {
      m_getLoadedEntityListMID = m_mc->getEnv()->GetMethodID(m_cls, "E", "Ljava/util/List;");
    }
  }
}

List *Level::players()
{
  if (m_mc->getVersion() == Version::v1201 || m_mc->getVersion() == Version::v120)
    return new List(m_mc->getEnv()->CallObjectMethod(m_obj, m_playersMID), m_mc);

  if (m_mc->getVersion() == Version::v189)
  {

    List *loadedEntityList = new List(m_mc->getEnv()->CallObjectMethod(m_obj, m_getLoadedEntityListMID), m_mc);

    delete loadedEntityList;
  }
  return nullptr;
}