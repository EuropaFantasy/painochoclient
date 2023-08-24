#pragma once

#include <jni.h>
#include <jvmti.h>


namespace jvm
{
    jsize n_count;
    JavaVM *n_jvm;
    JNIEnv *n_env;
    jvmtiEnv *n_tiEnv;
    jint n_res;

    bool init()
    {
        return (JNI_GetCreatedJavaVMs(&n_jvm, 1, &n_count) == JNI_OK && n_count > 0);
    }

    void attach()
    {
        n_res = n_jvm->GetEnv((void **)&n_env, JNI_VERSION_1_6);
        if (n_res == JNI_EDETACHED)
        {

            Sleep(50);
            n_res = n_jvm->AttachCurrentThread((void **)&n_env, nullptr);
        }
        n_jvm->GetEnv((void**)&n_tiEnv, JVMTI_VERSION_1_2);
    }

    JNIEnv *getEnv()
    {
        return n_env;
    }

    jvmtiEnv *getTiEnv() {
        return n_tiEnv;
    }

    bool ok()
    {
        return (n_res == JNI_OK);
    }
}