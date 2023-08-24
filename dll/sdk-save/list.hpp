#include <jni.h>

class Minecraft;

class List {
    jclass m_cls;
    jobject m_obj;

    jmethodID m_sizeMID;
    jmethodID m_getMID;

    Minecraft *m_mc;

public:
    List(jobject obj, Minecraft *mc);

    int size();

    jobject get(int index);
};