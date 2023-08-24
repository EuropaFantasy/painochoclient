#include "list.hpp"
#include "minecraft.hpp"

List::List(jobject obj, Minecraft *mc) : m_obj(obj), m_mc(mc)
{
  m_cls = m_mc->getEnv()->GetObjectClass(m_obj);

  m_sizeMID = m_mc->getEnv()->GetMethodID(m_cls, "size", "()I");
  m_getMID = m_mc->getEnv()->GetMethodID(m_cls, "get", "(I)Lpk;");
}

int List::size()
{
  return m_mc->getEnv()->CallIntMethod(m_obj, m_sizeMID);
}

jobject List::get(int index)
{
  return m_mc->getEnv()->CallObjectMethod(m_obj, m_getMID, index);
}