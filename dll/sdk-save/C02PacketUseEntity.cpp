#include "C02PacketUseEntity.hpp"
#include "minecraft.hpp"

C02PacketUseEntity::C02PacketUseEntity(Entity *entity, Minecraft *mc) : m_mc(mc)
{
  m_cls = m_mc->getEnv()->FindClass("in");
  m_initMID = m_mc->getEnv()->GetMethodID(m_cls, "<init>", "(pk,in$a)V");
  m_actionFID = m_mc->getEnv()->GetStaticFieldID(m_cls, "b", "in$a"); // field_149566_b
  m_actionObj = m_mc->getEnv()->GetStaticObjectField(m_cls, m_actionFID);
  m_actionCls = m_mc->getEnv()->GetObjectClass(m_actionObj);

  jmethodID midGetFields = m_mc->getEnv()->GetMethodID(m_actionCls, "getMethods", "()[Ljava/lang/reflect/Method;");
  jobjectArray jobjArray = (jobjectArray)m_mc->getEnv()->CallObjectMethod(m_actionCls, midGetFields);
  jsize len = m_mc->getEnv()->GetArrayLength(jobjArray);

  for (jsize i = 0; i < len; i++)
  {
    jobject _strMethod = m_mc->getEnv()->GetObjectArrayElement(jobjArray, i);
    jclass _methodClazz = m_mc->getEnv()->GetObjectClass(_strMethod);
    jmethodID mid = m_mc->getEnv()->GetMethodID(_methodClazz, "getName", "()Ljava/lang/String;");
    jstring _name = (jstring)m_mc->getEnv()->CallObjectMethod(_strMethod, mid);
    char buf[128];
    const char *str = m_mc->getEnv()->GetStringUTFChars(_name, 0);

    printf("\n%s", str);
    m_mc->getEnv()->ReleaseStringUTFChars(_name, str);
  }

  // m_mc->getEnv()->NewObject(m_cls, m_initMID, entity->getObj(), );
}

jobject C02PacketUseEntity::getObj()
{
  return m_obj;
}