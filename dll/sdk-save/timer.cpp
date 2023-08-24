#include "timer.hpp"
#include "minecraft.hpp"

Timer::Timer(jobject obj, Minecraft *mc) : m_obj(obj), m_mc(mc)
{
  m_cls = m_mc->getEnv()->GetObjectClass(obj);

  m_renderPartialTicksFID = m_mc->getEnv()->GetFieldID(m_cls, "c", "F");
}

float Timer::getRenderPartialTicks()
{
  return m_mc->getEnv()->GetFloatField(m_obj, m_renderPartialTicksFID);
}