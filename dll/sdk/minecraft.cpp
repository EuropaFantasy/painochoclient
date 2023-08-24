#include "minecraft.hpp"

Minecraft::Minecraft(JNIEnv *env) : m_env(env)
{
  detectClient();
  detectVersion();
  setup();
}

void Minecraft::setup()
{
  if (getClient() == Client::Forge)
  {
    m_cls = getClass("net.minecraft.client.Minecraft");
    m_fID = m_env->GetStaticFieldID(m_cls, "field_71432_P", "Lnet/minecraft/client/Minecraft;");
    m_obj = m_env->GetStaticObjectField(m_cls, m_fID);

    m_rightClickDelayFID = m_env->GetFieldID(m_cls, "field_71467_ac", "I");
    m_startAttackMID = m_env->GetMethodID(m_cls, "func_147116_af", "()V");
    m_playerFID = m_env->GetFieldID(m_cls, "field_71439_g", "Lnet/minecraft/client/entity/EntityPlayerSP;");
    return;
  }
  if (getClient() == Client::Lunar)
  {
    m_cls = getClass("net.minecraft.client.Minecraft");
    m_fID = m_env->GetStaticFieldID(m_cls, "theMinecraft", "Lnet/minecraft/client/Minecraft;");
    m_obj = m_env->GetStaticObjectField(m_cls, m_fID);

    m_rightClickDelayFID = m_env->GetFieldID(m_cls, "rightClickDelayTimer", "I");
    m_startAttackMID = m_env->GetMethodID(m_cls, "clickMouse", "()V");
    m_playerFID = m_env->GetFieldID(m_cls, "thePlayer", "Lnet/minecraft/client/entity/EntityPlayerSP;");
    return;
  }
  if (getClient() == Client::Vanilla)
  {
    if (getVersion() == Version::v189)
    {
      m_cls = m_env->FindClass("ave");
      m_fID = m_env->GetStaticFieldID(m_cls, "S", "Lave;");
      m_obj = m_env->GetStaticObjectField(m_cls, m_fID);

      m_rightClickDelayFID = m_env->GetFieldID(m_cls, "ap", "I");
      m_startAttackMID = m_env->GetMethodID(m_cls, "aw", "()V");
      m_playerFID = m_env->GetFieldID(m_cls, "h", "Lbew;");
      return;
    }
    if (getVersion() == Version::v1201 || getVersion() == Version::v120)
    {
      m_cls = m_env->FindClass("enn");
      m_fID = m_env->GetStaticFieldID(m_cls, "F", "Lenn;");
      m_obj = m_env->GetStaticObjectField(m_cls, m_fID);

      m_rightClickDelayFID = m_env->GetFieldID(m_cls, "aQ", "I");
      m_startAttackMID = m_env->GetMethodID(m_cls, "bj", "()Z");
      m_playerFID = m_env->GetFieldID(m_cls, "t", "Lfiy;");
      m_levelFID = m_env->GetFieldID(m_cls, "s", "Lfew;");
      m_optionsFID = m_env->GetFieldID(m_cls, "m", "Lenr;");
    }
  }
}

void Minecraft::detectClient()
{
  jclass forgeClass = m_env->FindClass("net/minecraftforge/common/ForgeVersion");
  if (forgeClass != NULL)
  {
    m_env->DeleteLocalRef(forgeClass);
    m_client = Client::Forge;
    std::cout << "Forge" << std::endl;
    return;
  }
  if (m_env->FindClass("a"))
  {
    m_client = Client::Vanilla;
    std::cout << "Vanilla" << std::endl;
    return;
  }
  m_client = Client::Lunar;
  std::cout << "Lunar" << std::endl;
}

void Minecraft::setRightClickDelay(int delay)
{
  m_env->SetIntField(m_obj, m_rightClickDelayFID, delay);
}

void Minecraft::startAttack()
{
  if (getVersion() == Version::v189)
  {
    m_env->CallVoidMethod(m_obj, m_startAttackMID);
    return;
  }
  if (getVersion() == Version::v1201 || getVersion() == Version::v120)
  {
    m_env->CallBooleanMethod(m_obj, m_startAttackMID);
  }
}

LocalPlayer *Minecraft::getPlayer()
{
  return new LocalPlayer(m_env->GetObjectField(m_obj, m_playerFID), this);
}

ClientLevel *Minecraft::getLevel()
{
  return new ClientLevel(m_env->GetObjectField(m_obj, m_levelFID), this);
}

Options *Minecraft::getOptions()
{
  return new Options(m_env->GetObjectField(m_obj, m_optionsFID), this);
}

Client Minecraft::getClient() const
{
  return m_client;
}

Version Minecraft::getVersion() const
{
  return m_version;
}

JNIEnv *Minecraft::getEnv() const
{
  return m_env;
}

void Minecraft::detectVersion()
{
  if (getClient() == Client::Forge)
  {
    m_version = Version::v189;
    std::cout << "1.8.9" << std::endl;
  }
  else if (getClient() == Client::Lunar)
  {
  }
  else if (getClient() == Client::Vanilla)
  {
    const char *found;
    jclass mc20Cls = m_env->FindClass("enn");
    if (mc20Cls != NULL)
    {
      jfieldID mc20FID = m_env->GetStaticFieldID(mc20Cls, "F", "Lenn;");
      jobject mc20Obj = m_env->GetStaticObjectField(mc20Cls, mc20FID);
      if (mc20Obj != NULL)
      {
        jmethodID getLaunchedVersionMID = m_env->GetMethodID(mc20Cls, "g", "()Ljava/lang/String;");
        jstring ret = (jstring)m_env->CallObjectMethod(mc20Obj, getLaunchedVersionMID);
        found = m_env->GetStringUTFChars(ret, 0);
        if (std::string(found).contains("1.20.1"))
        {
          m_version = Version::v1201;
          std::cout << "1.20.1" << std::endl;
          return;
        }

        if (std::string(found).contains("1.20"))
        {
          m_version = Version::v120;
          std::cout << "1.20" << std::endl;
        }
        return;
      }
    }
    jclass mc8Cls = m_env->FindClass("ave");
    if (mc8Cls != NULL)
    {
      jfieldID mc8FID = m_env->GetStaticFieldID(mc8Cls, "S", "Lave;");
      jobject mc8Obj = m_env->GetStaticObjectField(mc8Cls, mc8FID);
      if (mc8Obj != NULL)
      {
        jmethodID getLaunchedVersionMID = m_env->GetMethodID(mc8Cls, "c", "()Ljava/lang/String;");
        jstring ret = (jstring)m_env->CallObjectMethod(mc8Obj, getLaunchedVersionMID);
        found = m_env->GetStringUTFChars(ret, 0);
        if (std::string(found).contains("1.8.9"))
        {
          m_version = Version::v189;
          std::cout << "1.8.9" << std::endl;
        }
        return;
      }
    }
  }
}

jclass Minecraft::getClass(std::string path)
{
  if (getClient() == Client::Forge)
  {
    static jmethodID savedFindClassMethodID = nullptr;
    static jobject savedClassLoader = nullptr;

    if (!savedFindClassMethodID || !savedClassLoader)
    {
      jclass classLoader = m_env->FindClass("net/minecraft/launchwrapper/Launch");
      jclass LaunchClassLoaderClass = m_env->FindClass("net/minecraft/launchwrapper/LaunchClassLoader");
      if (!classLoader || !LaunchClassLoaderClass)
        return nullptr;
      jfieldID lclassLoader = m_env->GetStaticFieldID(
          classLoader,
          "classLoader",
          "Lnet/minecraft/launchwrapper/LaunchClassLoader;");
      jmethodID findClassMethodID = m_env->GetMethodID(
          LaunchClassLoaderClass,
          "findClass",
          "(Ljava/lang/String;)Ljava/lang/Class;");
      if (!lclassLoader || !findClassMethodID)
      {
        std::cerr << "[-] Failed to find load class id" << std::endl;
        return nullptr;
      }
      jobject oclassLoader = m_env->GetStaticObjectField(classLoader, lclassLoader);
      if (!oclassLoader)
        return nullptr;
      savedFindClassMethodID = findClassMethodID;
      savedClassLoader = oclassLoader;
    }

    jstring arg = m_env->NewStringUTF(path.c_str());
    jobject foundClass = m_env->CallObjectMethod(savedClassLoader, savedFindClassMethodID, arg);
    if (!foundClass)
    {
      std::cout << "[-] Failed to find class " + path << std::endl;
      return nullptr;
    }
    return (jclass)foundClass;
  }
  if (getClient() == Client::Lunar)
  {
    static jmethodID savedFindClassMethodID = nullptr;
    static jobject savedClassLoader = nullptr;
    if (!savedClassLoader || !savedFindClassMethodID)
    {
      jclass ThreadClass = m_env->FindClass("java/lang/Thread");
      /* Get current Thread */
      jmethodID currentThread_MethodID = m_env->GetStaticMethodID(ThreadClass, "currentThread", "()Ljava/lang/Thread;");
      jobject currentThread = m_env->CallStaticObjectMethod(ThreadClass, currentThread_MethodID);

      /*Get Thread Group*/
      jmethodID getThreadGroup_MethodID = m_env->GetMethodID(ThreadClass, "getThreadGroup", "()Ljava/lang/ThreadGroup;");
      jobject ThreadGroup = m_env->CallObjectMethod(currentThread, getThreadGroup_MethodID);

      /*Get a list of threads in this group*/
      jclass ThreadGroupClass = m_env->FindClass("java/lang/ThreadGroup");
      jmethodID activeCount_MethodID = m_env->GetMethodID(ThreadGroupClass, "activeCount", "()I");
      jint activeThreadCount = m_env->CallIntMethod(ThreadGroup, activeCount_MethodID);

      jobjectArray activeThreads = m_env->NewObjectArray(activeThreadCount, ThreadClass, nullptr);
      jmethodID enumerate_MethodID = m_env->GetMethodID(ThreadGroupClass, "enumerate", "([Ljava/lang/Thread;)I");
      jint copiedThreads = m_env->CallIntMethod(ThreadGroup, enumerate_MethodID, activeThreads);

      jobject firstThread = m_env->GetObjectArrayElement(activeThreads, 0);
      jmethodID getContextClassLoader_MethodID = m_env->GetMethodID(ThreadClass, "getContextClassLoader", "()Ljava/lang/ClassLoader;");
      jobject classLoader = m_env->CallObjectMethod(firstThread, getContextClassLoader_MethodID);

      jclass classLoaderClass = m_env->GetObjectClass(classLoader);
      jmethodID findClass_MethodID = m_env->GetMethodID(classLoaderClass, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
      if (!findClass_MethodID)
      {
        return nullptr;
      }
      savedClassLoader = classLoader;
      savedFindClassMethodID = findClass_MethodID;
    }
    jstring arg = m_env->NewStringUTF(path.c_str());
    jobject findedClass = m_env->CallObjectMethod(savedClassLoader, savedFindClassMethodID, arg);
    if (!findedClass)
    {
      std::cout << "[-] Failed to get class " + path << std::endl;
      return nullptr;
    }
    return (jclass)findedClass;
  }
  return nullptr;
}