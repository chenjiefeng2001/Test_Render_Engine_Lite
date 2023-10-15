#include "glfwinit.hpp"
#include "imgui_impl_glfw.h"
void InitGLFWApp::framebufferResizeCallback(GLFWwindow *window, int width,
                                            int height) {
  auto app = reinterpret_cast<InitGLFWApp *>(glfwGetWindowUserPointer(window));
  app->framebufferResized = true;
}
void InitGLFWApp::initWindow() {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  window = glfwCreateWindow(INITGLFWWIDTH, INITGLFWHEIGHT, "Vulkan", nullptr,
                            nullptr);
  glfwSetWindowUserPointer(window, this);
  glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}
