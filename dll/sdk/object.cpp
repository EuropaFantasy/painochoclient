#include "object.hpp"
#include "minecraft.hpp"

Object::Object(Object *obj)
{
  m_obj = obj->getObject();
  m_cls = obj->getClass();
  m_mc = obj->getMinecraft();
}

Object::Object(Object &obj)
{
  m_obj = obj.getObject();
  m_cls = obj.getClass();
  m_mc = obj.getMinecraft();
}

Object::Object(jobject obj, Minecraft *mc) : m_obj(obj), m_mc(mc)
{
  m_cls = m_mc->getEnv()->GetObjectClass(m_obj);
}

Object::Object(Minecraft *mc) : m_mc(mc)
{
}

jclass Object::getClass() const
{
  return m_cls;
}

jobject Object::getObject() const
{
  return m_obj;
}

Minecraft *Object::getMinecraft() const
{
  return m_mc;
}