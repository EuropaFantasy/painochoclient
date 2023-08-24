#include "cascade.hpp"
#include "detect/client.hpp"
#include "detect/version.hpp"
#include "derived/vanilla/v189/instance.hpp"
#include "derived/forge/v189/instance.hpp"
#include "derived/lunar/v189/instance.hpp"

#include <iostream>

namespace csc {
    JNIEnv *n_env;
    jvmtiEnv *n_tiEnv;
    Client n_client;
    Version n_version;
    std::shared_ptr<Minecraft> n_mc;

    void test() {
        std::cout << getMc()->getOptions()->getObj() << std::endl;
        //std::cout << findClass("net/minecraft/client/Minecraft", n_env, n_tiEnv) << std::endl;
    }

    void init(JNIEnv *env, jvmtiEnv *tiEnv) {
        n_env = env;
        n_tiEnv = tiEnv;
        n_client = detect::client(n_env);
        n_version = detect::version(n_env);

        if (n_client == Client::Vanilla) {
            n_mc = vanilla189(n_env, n_tiEnv);
        } else if (n_client == Client::Forge) {
            n_mc = forge189(n_env, n_tiEnv);
        } else if(n_client == Client::Lunar) {
            n_mc = lunar189(n_env, n_tiEnv);
        }
    }

    Client getClient() {
        return n_client;
    }

    Version getVersion() {
        return n_version;
    }

    std::shared_ptr<Minecraft> getMc() {
        return n_mc;
    }
}