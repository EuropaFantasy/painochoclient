#include "minecraft.hpp"
#include <string>
Minecraft::Minecraft(JNIEnv *env) : m_env(env)
{

  jclass forgeClass = m_env->FindClass("net/minecraftforge/common/ForgeVersion");
  if (forgeClass != NULL)
  {
    m_env->DeleteLocalRef(forgeClass);
    m_client = Client::Forge;
    detectVersion();
    m_cls = getClass("net.minecraft.client.Minecraft");
    m_fID = m_env->GetStaticFieldID(m_cls, "field_71432_P", "Lnet/minecraft/client/Minecraft;");
    m_obj = m_env->GetStaticObjectField(m_cls, m_fID);

    m_rightClickDelayFID = m_env->GetFieldID(m_cls, "field_71467_ac", "I");
    m_clickMouseMID = m_env->GetMethodID(m_cls, "func_147116_af", "()V");
    m_thePlayerFID = m_env->GetFieldID(m_cls, "field_71439_g", "Lnet/minecraft/client/entity/EntityPlayerSP;");
    m_theWorldFID = m_env->GetFieldID(m_cls, "field_71441_e", "Lnet/minecraft/client/multiplayer/WorldClient;");
    m_currentScreenFID = m_env->GetFieldID(m_cls, "field_71462_r", "Lnet/minecraft/client/gui/GuiScreen;");
  }
  else if (getClass("net.minecraft.client.Minecraft"))
  {
    m_client = Client::Lunar;
    detectVersion();
    m_cls = getClass("net.minecraft.client.Minecraft");
    m_fID = m_env->GetStaticFieldID(m_cls, "theMinecraft", "Lnet/minecraft/client/Minecraft;");
    m_obj = m_env->GetStaticObjectField(m_cls, m_fID);

    m_rightClickDelayFID = m_env->GetFieldID(m_cls, "rightClickDelayTimer", "I");
    m_clickMouseMID = m_env->GetMethodID(m_cls, "clickMouse", "()V");
    m_thePlayerFID = m_env->GetFieldID(m_cls, "thePlayer", "Lnet/minecraft/client/entity/EntityPlayerSP;");
    m_theWorldFID = m_env->GetFieldID(m_cls, "theWorld", "Lnet/minecraft/client/multiplayer/WorldClient;");
    m_currentScreenFID = m_env->GetFieldID(m_cls, "currentScreen", "Lnet/minecraft/client/gui/GuiScreen;");
    // m_guiMainMenuCls = m_env->FindClass("aya");
  }
  else
  {
    m_client = Client::Vanilla;

    detectVersion();

    std::cout << getVersion() << std::endl;

    if (getVersion() == Version::v189)
    {
      m_cls = m_env->FindClass("ave");
      m_fID = m_env->GetStaticFieldID(m_cls, "S", "Lave;");
      m_obj = m_env->GetStaticObjectField(m_cls, m_fID);

      m_rightClickDelayFID = m_env->GetFieldID(m_cls, "ap", "I");
      m_clickMouseMID = m_env->GetMethodID(m_cls, "aw", "()V");
      m_thePlayerFID = m_env->GetFieldID(m_cls, "h", "Lbew;");
      m_theWorldFID = m_env->GetFieldID(m_cls, "f", "Lbdb;");
      m_currentScreenFID = m_env->GetFieldID(m_cls, "m", "Laxu;");
    }
    else if (getVersion() == Version::v1201 || getVersion() == Version::v120)
    {
      m_cls = m_env->FindClass("enn");
      m_fID = m_env->GetStaticFieldID(m_cls, "F", "Lenn;");
      m_obj = m_env->GetStaticObjectField(m_cls, m_fID);

      m_rightClickDelayFID = m_env->GetFieldID(m_cls, "aQ", "I");
      m_clickMouseMID = m_env->GetMethodID(m_cls, "bj", "()Z");
      m_thePlayerFID = m_env->GetFieldID(m_cls, "t", "Lfiy;");
      m_theWorldFID = m_env->GetFieldID(m_cls, "s", "Lfew;");
      m_currentScreenFID = m_env->GetFieldID(m_cls, "l", "Leow;");
    }
  }
  /*m_cls = m_env->FindClass(isForge() ? "net/minecraft/client/Minecraft" : "ave");
  m_fID = isForge() ? m_env->GetStaticFieldID(m_cls, "field_71432_P", "Lnet/minecraft/client/Minecraft;") : m_env->GetStaticFieldID(m_cls, "S", "Lave;");
  m_obj = m_env->GetStaticObjectField(m_cls, m_fID);

  m_rightClickDelayFID = m_env->GetFieldID(m_cls, "ap", "I");
  m_clickMouseMID = m_env->GetMethodID(m_cls, "aw", "()V");
  m_thePlayerFID = m_env->GetFieldID(m_cls, "h", "Lbew;");
  m_theWorldFID = m_env->GetFieldID(m_cls, "f", "Lbdb;");
  m_currentScreenFID = m_env->GetFieldID(m_cls, "m", "Laxu;");
  m_guiMainMenuCls = m_env->FindClass("aya");

  m_getRenderManagerMID = m_env->GetMethodID(m_cls, "af", "Lbiu;");

  m_activeRenderInfoCls = m_env->FindClass("auz");
  m_viewportFID = m_env->GetStaticFieldID(m_activeRenderInfoCls, "a", "Ljava/nio/IntBuffer;");
  m_modelViewFID = m_env->GetStaticFieldID(m_activeRenderInfoCls, "b", "Ljava/nio/FloatBuffer;");
  m_projectionFID = m_env->GetStaticFieldID(m_activeRenderInfoCls, "c", "Ljava/nio/FloatBuffer;");
  /*m_intBufferCls = m_env->FindClass("java.nio.IntBuffer");
  m_floatBufferCls = m_env->FindClass("java.nio.FloatBuffer");
  m_intBufferGetMID = m_env->GetMethodID(m_intBufferCls, "get", "(I)I");
  m_floatBufferGetMID = m_env->GetMethodID(m_floatBufferCls, "get", "(I)F");

  m_timerFID = m_env->GetFieldID(m_cls, "Y", "Lavl;");*/
}

void Minecraft::setRightClickDelay(int delay)
{
  m_env->SetIntField(m_obj, m_rightClickDelayFID, delay);
}

void Minecraft::clickMouse()
{
  if (getVersion() == Version::v189)
  {
    m_env->CallVoidMethod(m_obj, m_clickMouseMID);
  }
  else if (getVersion() == Version::v1201 || getVersion() == Version::v120)
  {
    m_env->CallBooleanMethod(m_obj, m_clickMouseMID);
  }
}

LocalPlayer *Minecraft::getPlayer()
{
  return new LocalPlayer(m_env->GetObjectField(m_obj, m_thePlayerFID), this);
}

WorldClient *Minecraft::getTheWorld()
{
  return new WorldClient(m_env->GetObjectField(m_obj, m_theWorldFID), this);
}

bool Minecraft::isGuiScreen()
{
  bool isGuiMainMenu = m_env->IsInstanceOf(m_env->GetObjectField(m_obj, m_currentScreenFID), m_guiMainMenuCls);
  bool doesAWorldExist = !(m_env->GetObjectField(m_obj, m_theWorldFID) == NULL);
  bool doesAPlayerExist = !(m_env->GetObjectField(m_obj, m_thePlayerFID) == NULL);
  return (isGuiMainMenu && !doesAWorldExist && !doesAPlayerExist);
}

RenderManager *Minecraft::getRenderManager()
{
  return new RenderManager(m_env->CallObjectMethod(m_obj, m_getRenderManagerMID), this);
}

GLint *Minecraft::getViewport()
{
  jobject viewportObj = m_env->GetStaticObjectField(m_activeRenderInfoCls, m_viewportFID);
  for (int i = 0; i < 16; i++)
  {
    m_viewport[i] = m_env->CallIntMethod(viewportObj, m_intBufferGetMID, i);
  }
  m_env->DeleteLocalRef(viewportObj);
  return m_viewport;
}

GLfloat *Minecraft::getModelView()
{
  jobject modelViewObj = m_env->GetStaticObjectField(m_activeRenderInfoCls, m_modelViewFID);
  for (int i = 0; i < 16; i++)
  {
    m_modelView[i] = m_env->CallFloatMethod(modelViewObj, m_floatBufferGetMID, i);
  }
  m_env->DeleteLocalRef(modelViewObj);
  return m_modelView;
}

GLfloat *Minecraft::getProjection()
{
  jobject projectionObj = m_env->GetStaticObjectField(m_activeRenderInfoCls, m_projectionFID);
  for (int i = 0; i < 16; i++)
  {
    m_projection[i] = m_env->CallFloatMethod(projectionObj, m_floatBufferGetMID, i);
  }
  m_env->DeleteLocalRef(projectionObj);
  return m_modelView;
}

Timer *Minecraft::getTimer()
{
  return new Timer(m_env->GetObjectField(m_obj, m_timerFID), this);
}

JNIEnv *Minecraft::getEnv()
{
  return m_env;
}

Client Minecraft::getClient()
{
  return m_client;
}

Version Minecraft::getVersion()
{
  return m_version;
}

void Minecraft::detectVersion()
{
  if (getClient() == Client::Forge)
  {
  }
  else if (getClient() == Client::Lunar)
  {
  }
  else if (getClient() == Client::Vanilla)
  {
    const char *found;
    jclass mc20Cls = m_env->FindClass("enn");
    std::cout << "mc20Cls => " << (mc20Cls == NULL) << std::endl;
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
          return;
        }

        if (std::string(found).contains("1.20"))
          m_version = Version::v120;
        return;
      }
    }
    jclass mc8Cls = m_env->FindClass("ave");
    std::cout << (mc8Cls == NULL) << std::endl;
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
        }
        return;
      }
    }
  }
}

jclass Minecraft::getClass(std::string path)
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