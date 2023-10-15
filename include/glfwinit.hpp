#pragma once
#ifndef GLFWINIT
#define GLFWINIT
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#define INITGLFWHEIGHT 600
#define INITGLFWWIDTH 800
#include <GLFW/glfw3.h>
#include "imgui_impl_glfw.h"
class InitGLFWApp {
public:
  void initWindow();
  void mainLoop();
  void cleanup();
  InitGLFWApp() = default;
  ~InitGLFWApp() {}

protected:
  GLFWwindow *window;

private:
  bool framebufferResized = false;
  static void framebufferResizeCallback(GLFWwindow *window, int width,
                                        int height);
};
#endif /* GLFWINIT */