#pragma once

#include <jni.h>
#include <jvmti.h>

jclass findClass(const std::string& path, JNIEnv *env, jvmtiEnv *tiEnv)
{
    jint class_count = 0;
    jclass* classes = nullptr;
    jclass foundclass = nullptr;
    tiEnv->GetLoadedClasses(&class_count, &classes);
    for (int i = 0; i < class_count; ++i) {
        char* signature_buffer = nullptr;
        tiEnv->GetClassSignature(classes[i], &signature_buffer, nullptr);
        std::string signature = signature_buffer;
        tiEnv->Deallocate((unsigned char*)signature_buffer);
        signature = signature.substr(1);
        signature.pop_back();
        if (signature == path) {
            foundclass = classes[i];
            break;
        }
        env->DeleteLocalRef(classes[i]);
    }
    tiEnv->Deallocate((unsigned char*)classes);
    return foundclass;
}