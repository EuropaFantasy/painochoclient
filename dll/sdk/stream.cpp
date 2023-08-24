#include "stream.hpp"
#include "minecraft.hpp"

Stream::Stream(jobject obj, Minecraft *mc) : Object(obj, mc)
{
  m_filterMID = m_mc->getEnv()->GetMethodID(m_cls, "filter", "(Ljava/util/function/Predicate;)Ljava/util/stream/Stream;");
  m_collectMID = m_mc->getEnv()->GetMethodID(m_cls, "collect", "(Ljava/util/stream/Collectors;)Ljava/util/List;");
}

Stream *Stream::filter()
{
  m_mc->getPlayer()->getClass();
  std::cout << m_filterMID << std::endl;
}

jobject *Stream::collect()
{
  std::cout << m_collectMID << std::endl;
}