#include <iostream>
#include "GlfwGeneral.h"
int main() {
    if (!InitializeWindow({1280, 720}))
    {
        return -1;
    }
    while (!glfwWindowShouldClose(pWindow))
    {
        glfwPollEvents();
        TitleFps();
    }
    TerminateWindow();
    return 0;
}
