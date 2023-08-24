#include "axisAlignedBB.hpp"
#include "minecraft.hpp"

AxisAlignedBB::AxisAlignedBB(jobject obj, Minecraft *mc) : m_obj(obj), m_mc(mc)
{
  m_cls = m_mc->getEnv()->GetObjectClass(m_obj);

  m_minXFID = m_mc->getEnv()->GetFieldID(m_cls, "a", "D");
  m_minYFID = m_mc->getEnv()->GetFieldID(m_cls, "b", "D");
  m_minZFID = m_mc->getEnv()->GetFieldID(m_cls, "c", "D");
  m_maxXFID = m_mc->getEnv()->GetFieldID(m_cls, "d", "D");
  m_maxYFID = m_mc->getEnv()->GetFieldID(m_cls, "e", "D");
  m_maxZFID = m_mc->getEnv()->GetFieldID(m_cls, "f", "D");
}

double AxisAlignedBB::getMinX()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_minXFID);
}
double AxisAlignedBB::getMinY()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_minYFID);
}
double AxisAlignedBB::getMinZ()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_minZFID);
}
double AxisAlignedBB::getMaxX()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_maxXFID);
}
double AxisAlignedBB::getMaxY()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_maxYFID);
}
double AxisAlignedBB::getMaxZ()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_maxZFID);
}