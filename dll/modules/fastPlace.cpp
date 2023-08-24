#include "fastPlace.hpp"

#include <utility>

FastPlace::FastPlace(std::shared_ptr<Minecraft> mc) : Module(std::string_view("FastPlace"), std::move(mc)) {
}

void FastPlace::onTick() {
    getMc()->setRightClickDelay(0);
}