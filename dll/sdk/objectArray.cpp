#include "objectArray.hpp"
#include "minecraft.hpp"

ObjectArray::ObjectArray(jobjectArray objArray, Minecraft *mc) : Object(mc)
{
  m_objArray = objArray;
}

jobjectArray ObjectArray::getObjectArray() const
{
  return m_objArray;
}

int ObjectArray::length()
{
  return m_mc->getEnv()->GetArrayLength(m_objArray);
}

Object *ObjectArray::get(int index)
{
  return new Object(m_mc->getEnv()->GetObjectArrayElement(m_objArray, index), m_mc);
}