#pragma once

#include <jni.h>

#include "object.hpp"
#include "objectArray.hpp"
#include "stream.hpp"

class List : public Object {
    jmethodID m_sizeMID,
            m_toArrayMID,
            m_streamMID;

public:
    List(jobject obj, Minecraft *mc);

    int size();

    Stream *stream();

    ObjectArray *toArray();
};