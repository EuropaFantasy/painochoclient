#include "netHandlerPlayClient.hpp"
#include "minecraft.hpp"

NetHandlerPlayClient::NetHandlerPlayClient(jobject obj, Minecraft *mc) : m_obj(obj), m_mc(mc)
{
  m_cls = m_mc->getEnv()->GetObjectClass(m_obj);

  m_addToSendQueueFID = m_mc->getEnv()->GetMethodID(m_cls, "a", "(Lff;)V");
}

void NetHandlerPlayClient::addToSendQueue()
{
}