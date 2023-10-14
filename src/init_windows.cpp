// #include "Vulkan_init.hpp"
#include "glfwinit.hpp"
#include "vulkan_init.hpp"

int main() {
  InitVulkanApp app;

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}