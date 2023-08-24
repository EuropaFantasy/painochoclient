#pragma once

#include <jni.h>
#include <jvmti.h>

struct Env {
    JNIEnv *jni;
    jvmtiEnv *jvmti;
    jobject obj;
};