#pragma once

#include <windows.h>
#include <GL/gl.h>
#include <string>
#include <unordered_map>
#include <iostream>

#include <jni.h>
#include <jvmti.h>

#include "localPlayer.hpp"
#include "worldClient.hpp"
#include "renderManager.hpp"
#include "timer.hpp"
#include "client.hpp"
#include "version.hpp"

class Minecraft {
    jclass m_cls;
    jobject m_obj;
    jfieldID m_fID;

    jfieldID m_rightClickDelayFID;
    jmethodID m_clickMouseMID;
    jfieldID m_thePlayerFID;
    jfieldID m_theWorldFID;
    jfieldID m_currentScreenFID;
    jclass m_guiMainMenuCls;
    jmethodID m_getRenderManagerMID;

    jclass m_activeRenderInfoCls;
    jfieldID m_viewportFID;
    jfieldID m_modelViewFID;
    jfieldID m_projectionFID;
    jclass m_intBufferCls;
    jclass m_floatBufferCls;
    jmethodID m_intBufferGetMID;
    jmethodID m_floatBufferGetMID;
    jfieldID m_timerFID;

    GLint *m_viewport;
    GLfloat *m_modelView;
    GLfloat *m_projection;

    Client m_client;
    Version m_version;

    JNIEnv *m_env;

    void detectVersion();

public:
    Minecraft(JNIEnv *env);

    void setRightClickDelay(int delay);

    void clickMouse();

    LocalPlayer *getPlayer();

    WorldClient *getTheWorld();

    bool isGuiScreen();

    RenderManager *getRenderManager();

    GLint *getViewport();

    GLfloat *getModelView();

    GLfloat *getProjection();

    Timer *getTimer();

    Client getClient();

    Version getVersion();

    JNIEnv *getEnv();

    jclass getClass(std::string path);
};