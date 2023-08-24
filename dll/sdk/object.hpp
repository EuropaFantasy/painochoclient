#pragma once

#include <jni.h>

class Minecraft;

class Object {
protected:
    jclass m_cls;
    jobject m_obj;
    Minecraft *m_mc;

public:
    Object(Object *obj);

    Object(Object &obj); // implicit conversion constructor
    Object(jobject obj, Minecraft *mc);

    Object(Minecraft *mc);

    jclass getClass() const;

    jobject getObject() const;

    Minecraft *getMinecraft() const;
};