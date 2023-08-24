#include "list.hpp"
#include "minecraft.hpp"

List::List(jobject obj, Minecraft *mc) : Object(obj, mc)
{
  m_sizeMID = m_mc->getEnv()->GetMethodID(m_cls, "size", "()I");
  m_toArrayMID = m_mc->getEnv()->GetMethodID(m_cls, "toArray", "()[Ljava/lang/Object;");
  m_streamMID = m_mc->getEnv()->GetMethodID(m_cls, "stream", "()Ljava/util/stream/Stream;");
}

int List::size()
{
  return m_mc->getEnv()->CallIntMethod(m_obj, m_sizeMID);
}

Stream *List::stream()
{
  return new Stream(m_mc->getEnv()->CallObjectMethod(m_obj, m_streamMID), m_mc);
}

ObjectArray *List::toArray()
{
  return new ObjectArray((jobjectArray)m_mc->getEnv()->CallObjectMethod(m_obj, m_toArrayMID), m_mc);
}