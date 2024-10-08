#ifndef GLFWGENERAL_H
#define GLFWGENERAL_H
#include "VKBase.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#pragma comment(lib, "glfw3.a")

// 窗口的指针
GLFWwindow* pWindow = nullptr;
// 显示器的指针
GLFWmonitor* pMonitor = nullptr;
// 窗口标题
const char* windowTitle = "ezVulkan";
void TerminateWindow();
bool InitializeWindow(VkExtent2D size, bool fullScreen = false, bool isResizable = true, bool limitFrameRate = true)
{
    if (!glfwInit())
    {
        std::cout << std::format("[InitializeWindow] ERROR:\tFailed to initialize GLFW") << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, isResizable);
    pMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);

    pWindow = fullScreen ?
        glfwCreateWindow(pMode->width, pMode->height, windowTitle, pMonitor, nullptr):
        glfwCreateWindow(size.width, size.height, windowTitle, nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << std::format("[InitializeWindow] ERROR:\tFailed to create GLFW window") << std::endl;
        TerminateWindow();
        return false;
    }
    // TODO
    return true;
}

void TerminateWindow()
{
    // TODO
    glfwTerminate();
}

void TitleFps()
{
    static double time0 = glfwGetTime();
    static double time1;
    static double dt;
    static int dframe = -1;
    static std::stringstream info;
    time1 = glfwGetTime();
    dframe++;
    if ((dt = time1 - time0) >= 1)
    {
        info.precision(1);
        info << windowTitle << " " << std::fixed << dframe/dt << " FPS" << std::endl;
        glfwSetWindowTitle(pWindow, info.str().c_str());
        info.str("");
        time0 = time1;
        dframe = 0;
    }
}

void MakeWindowFullscreen()
{
    const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);
    glfwSetWindowMonitor(pWindow, pMonitor, 0, 0, pMode->width, pMode->height, pMode->refreshRate);
}

void MakeWindowWindowed(VkOffset2D position, VkExtent2D size)
{
    const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);
    glfwSetWindowMonitor(pWindow, nullptr, position.x, position.y, size.width, size.height, pMode->refreshRate);
}
#endif //GLFWGENERAL_H
