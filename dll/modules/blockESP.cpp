#include "blockESP.hpp"

#include <GL/gl.h>
#include <iostream>

BlockESP::BlockESP(std::shared_ptr<Minecraft> mc) : Module(std::string_view("BlockESP"), mc) {
}

void BlockESP::onRender() {
    std::cout << "onRender" << std::endl;
    const float x = 100;
    const float y = 100;

    const float w = 90;
    const float h = 90;

    glColor3f(1.0f, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();
}