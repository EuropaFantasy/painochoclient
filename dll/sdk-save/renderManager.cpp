#include "renderManager.hpp"
#include "minecraft.hpp"

RenderManager::RenderManager(jobject obj, Minecraft *mc) : m_obj(obj), m_mc(mc)
{
  m_cls = m_mc->getEnv()->GetObjectClass(m_obj);

  m_renderPosXFID = m_mc->getEnv()->GetFieldID(m_cls, "o", "D");
  m_renderPosYFID = m_mc->getEnv()->GetFieldID(m_cls, "p", "D");
  m_renderPosZFID = m_mc->getEnv()->GetFieldID(m_cls, "q", "D");
}

double RenderManager::getRenderPosX()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_renderPosXFID);
}

double RenderManager::getRenderPosY()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_renderPosYFID);
}

double RenderManager::getRenderPosZ()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_renderPosZFID);
}