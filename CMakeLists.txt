cmake_minimum_required(VERSION 3.29)
project(ezVulkan)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
        ${PROJECT_PATH}/deps
        ${PROJECT_PATH}/deps/GLFW/include
        ${PROJECT_PATH}/deps/GLM
        ${PROJECT_PATH}/deps/Vulkan/Include
)

link_directories(
        ${PROJECT_PATH}/deps/Vulkan/Lib
        ${PROJECT_PATH}/deps/GLFW/lib_win64
)
add_executable(ezVulkan main.cpp
        ezVulkanStart.h
        VKBase.h
        GlfwGeneral.h)

target_link_libraries(ezVulkan glfw3)
