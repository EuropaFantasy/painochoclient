#pragma once

#include <windows.h>
#include <GL/gl.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <string>

#include <jni.h>

#include "client.hpp"
#include "version.hpp"

#include "localPlayer.hpp"
#include "clientLevel.hpp"
#include "options.hpp"

class Minecraft {
    jclass m_cls;
    jobject m_obj;
    jfieldID m_fID;

    jmethodID m_startAttackMID;
    jfieldID m_rightClickDelayFID,
            m_playerFID,
            m_levelFID,
            m_optionsFID;

    Client m_client;
    Version m_version;

    JNIEnv *m_env;

    void detectClient();

    void detectVersion();

    void setup();

public:
    Minecraft(JNIEnv *env);

    void setRightClickDelay(int delay);

    void startAttack();

    LocalPlayer *getPlayer();

    ClientLevel *getLevel();

    Options *getOptions();

    Client getClient() const;

    Version getVersion() const;

    JNIEnv *getEnv() const;

    jclass getClass(std::string path);
};