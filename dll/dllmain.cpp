#include "sockets.hpp"
//#include "hooks.hpp"
#include "jvm.hpp"
#include "cascade/cascade.hpp"
#include "modules/moduleManager.hpp"

#include <windows.h>

#include <jni.h>

void install() {
    // sock::startServer();
    //installHooks();
}

void quit(HMODULE hModule) {
    // sock::close();
    //removeHooks();
    FreeLibraryAndExitThread(hModule, 0);
}

void init(HMODULE hModule) {
    install();

    jvm::init();
    jvm::attach();

    csc::init(jvm::getEnv(), jvm::getTiEnv());

    csc::test();

    // JNIEnv *env = jvm::getEnv();

    // std::cout << (getClass(env, "net/minecraft/client/Minecraft") == NULL) << std::endl;

    // jclass mcCls = getClass(env, "net.minecraft.src.C_3391_"); // env->FindClass("emh"); // enn");
    // std::cout << (mcCls == NULL) << std::endl;

    /*jfieldID mcFID = env->GetStaticFieldID(mcCls, "f_90981_", "Lnet/minecraft/client/Minecraft;"); // Lenn;");

    jobject mcObj = env->GetStaticObjectField(mcCls, mcFID);

    jmethodID getLaunchedVersionMID = env->GetMethodID(mcCls, "m_91388_", "()Ljava/lang/String;");

    jstring ret = (jstring)env->CallObjectMethod(mcObj, getLaunchedVersionMID);

    std::cout << env->GetStringUTFChars(ret, 0) << std::endl;

    /*jfieldID playerFID = env->GetFieldID(mcCls, "t", "Lfiy;");

    jobject playerObj = env->GetObjectField(mcObj, playerFID);

    jclass playerCls = env->GetObjectClass(playerObj);

    jmethodID setSprintingMID = env->GetMethodID(playerCls, "g", "(Z)V");

    std::cout << (setSprintingMID == NULL) << std::endl;*/

    ModuleManager manager(csc::getMc());

    while (!GetAsyncKeyState(VK_END)) {
        if (GetAsyncKeyState(VK_SUBTRACT)) {
            manager.onTick();
            //manager->getModule("BlockESP")->onRender();
            //std::cout << manager->getModule("BlockESP")->isToggled() << std::endl;
        }
        /*if (sock::toggleAC)
        {
          mc->clickMouse();
        }
        if (sock::toggleFP)
        {
          mc->setRightClickDelay(0);
        }
        if (sock::toggleAS)
        {
          if (!(mc->getPlayer()->isUsingItem() || mc->getPlayer()->isSneaking()) && mc->getPlayer()->isMoving() && mc->getPlayer()->getMoveStrafing() > 0)
          {
            mc->getPlayer()->setSprinting(true);
          }
        }*/
    }
    quit(hModule);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD nReason, LPVOID lpReserved) {
    static FILE *buffer, *buffer2, *buffer3 = nullptr;
    // Perform actions based on the reason for calling.
    switch (nReason) {

        case DLL_PROCESS_ATTACH: {
            // Initialize once for each new process.
            // Return FALSE to fail DLL load.
            AllocConsole();
            freopen_s(&buffer, "CONOUT$", "w", stdout);
            freopen_s(&buffer2, "CONOUT$", "w", stderr);
            freopen_s(&buffer3, "CONIN$", "r", stdin);
            SetConsoleOutputCP(CP_UTF8);
            SetConsoleTitleA("painochoconsole");
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE) init, hModule, 0, 0);
            break;
        }

        case DLL_THREAD_ATTACH:
            // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
            // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
            if (lpReserved != nullptr) {
                break; // do not do cleanup if process termination scenario
            }
            fclose(buffer);
            fclose(buffer2);
            fclose(buffer3);
            FreeConsole();
            // Perform any necessary cleanup.
            break;
    }
    return TRUE; // Successful DLL_PROCESS_ATTACH.
}
