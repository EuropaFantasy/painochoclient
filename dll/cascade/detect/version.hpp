#pragma once

#include "../version.hpp"

namespace csc::detect {
    Version version(JNIEnv *env) {
        if (getClient() == Client::Forge) {
            return Version::v189;
        } else if (getClient() == Client::Lunar) {
            return Version::v189;
        } else if (getClient() == Client::Vanilla) {
            std::string found;
            jclass mc20Cls = env->FindClass("enn");
            if (mc20Cls != nullptr) {
                jfieldID mc20FID = env->GetStaticFieldID(mc20Cls, "F", "Lenn;");
                jobject mc20Obj = env->GetStaticObjectField(mc20Cls, mc20FID);
                if (mc20Obj != nullptr) {
                    jmethodID getLaunchedVersionMID = env->GetMethodID(mc20Cls, "g", "()Ljava/lang/String;");
                    auto ret = (jstring) env->CallObjectMethod(mc20Obj, getLaunchedVersionMID);
                    found = env->GetStringUTFChars(ret, nullptr);
                    if (found.contains("1.20.1")) {
                        return Version::v1201;
                    }
                }
            }
            jclass mc8Cls = env->FindClass("ave");
            if (mc8Cls != nullptr) {
                jfieldID mc8FID = env->GetStaticFieldID(mc8Cls, "S", "Lave;");
                jobject mc8Obj = env->GetStaticObjectField(mc8Cls, mc8FID);
                if (mc8Obj != nullptr) {
                    jmethodID getLaunchedVersionMID = env->GetMethodID(mc8Cls, "c", "()Ljava/lang/String;");
                    auto ret = (jstring) env->CallObjectMethod(mc8Obj, getLaunchedVersionMID);
                    found = env->GetStringUTFChars(ret, 0);
                    if (found.contains("1.8.9")) {
                        return Version::v189;
                    }
                }
            }
        }
    }
}
