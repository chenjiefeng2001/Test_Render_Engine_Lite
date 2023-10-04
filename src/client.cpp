#define GLFW_INCLUDE_VULKAN
#include <glfw3.h>
#include <iostream>

const uint32_t WIDTH=800;
const uint32_t HEIGHT=600;
class InitVulkanWindow {
public:
  void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }
	private:
    GLFWwindow* window;
    void initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    }

    void initVulkan() {

    }

    void mainLoop() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }

    void cleanup() {
        glfwDestroyWindow(window);

        glfwTerminate();
    }
};

using namespace std;

int main() {
    InitVulkanWindow app;
    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
