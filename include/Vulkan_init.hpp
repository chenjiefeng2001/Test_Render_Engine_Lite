#pragma once
#include "vulkan/vulkan_core.h"
#ifndef VULKAN_INIT
#define VULKAN_INIT
#include "headers.hpp"

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif
const int MAX_FRAMES_IN_FLIGHT = 2;
// activate the validatonLayer
const std::vector<const char *> validationLayers = {
    "VK_LAYER_KHRONOS_validation"};
// set deviceExtension
const std::vector<const char *> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME};
VkResult CreateDebugUtilsMessengerEXT(
    VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
    const VkAllocationCallbacks *pAllocator,
    VkDebugUtilsMessengerEXT *pDebugMessenger);
void DestroyDebugUtilsMessengerEXT(VkInstance instance,
                                   VkDebugUtilsMessengerEXT debugMessenger,
                                   const VkAllocationCallbacks *pAllocator);
// the QueueFamilyIndecies
struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;
  std::optional<uint32_t> presentFamily;
  bool isComplete();
};
// Swap Chain Supports
struct SwapChainSupportDetails {
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};
struct Vertex {
  glm::vec2 pos;
  glm::vec3 color;

  static VkVertexInputBindingDescription getBindingDescription() {
    VkVertexInputBindingDescription bindingDescription{};
    bindingDescription.binding = 0;
    bindingDescription.stride = sizeof(Vertex);
    bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

    return bindingDescription;
  }

  static std::array<VkVertexInputAttributeDescription, 2>
  getAttributeDescriptions();
};

/**
 * @brief Class for initializing and running a Vulkan application.
 */
class InitVulkanApp : InitGLFWApp {
public:
  InitVulkanApp() = default;
  ~InitVulkanApp() {}

  /**
   * @brief Runs the Vulkan application.
   */
  void run();

private:
  // Vulkan data
  VkInstance instance;
  VkDebugUtilsMessengerEXT debugMessenger;
  VkSurfaceKHR surface;
  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VkDevice device;
  VkQueue graphicsQueue;
  VkQueue presentQueue;
  VkAllocationCallbacks pAllocator;
  VkSwapchainKHR swapChain;
  std::vector<VkImage> swapChainImages;
  VkFormat swapChainImageFormat;
  VkExtent2D swapChainExtent;
  std::vector<VkImageView> swapChainImageViews;
  std::vector<VkFramebuffer> swapChainFramebuffers;
  VkRenderPass renderPass;
  VkDescriptorSetLayout descriptorSetLayout;
  VkPipelineLayout pipelineLayout;
  VkPipeline graphicsPipeline;
  VkCommandPool commandPool;
  VkBuffer vertexBuffer;
  VkDeviceMemory vertexBufferMemory;
  VkBuffer indexBuffer;
  VkDeviceMemory indexBufferMemory;
  std::vector<VkBuffer> uniformBuffers;
  std::vector<VkDeviceMemory> uniformBuffersMemory;
  std::vector<void *> uniformBuffersMapped;
  VkDescriptorPool descriptorPool;
  std::vector<VkDescriptorSet> descriptorSets;
  std::vector<VkCommandBuffer> commandBuffers;
  std::vector<VkSemaphore> imageAvailableSemaphores;
  std::vector<VkSemaphore> renderFinishedSemaphores;
  std::vector<VkFence> inFlightFences;
  uint32_t currentFrame = 0;
  static ImGui_ImplVulkanH_Window MainWindowData;
  static int MinImageCout;
  bool framebufferResized = false;

  // create Imgui variant

  /**
   * @brief Initializes the Vulkan application.
   */
  void initVulkan();

  /**
   * @brief Runs the main loop of the Vulkan application.
   */
  void mainLoop();

  /**
   * @brief Draws the frame of the Vulkan application.
   */
  void drawFrame();

  /**
   * @brief Cleans up the swap chain of the Vulkan application.
   */
  void cleanupSwapChain();

  /**
   * @brief Cleans up the Vulkan application.
   */
  void cleanupVulkan();

  /**
   * @brief Recreates the swap chain of the Vulkan application.
   */
  void recreateSwapChain();

  /**
   * @brief Creates the Vulkan instance.
   */
  void createInstance();

  /**
   * @brief Sets up the debug messenger for the Vulkan application.
   */
  void setupDebugMessenger();

  /**
   * @brief Creates the surface for the Vulkan application.
   */
  void createSurface();

  /**
   * @brief Picks the physical device for the Vulkan application.
   */
  void pickPhysicalDevice();

  /**
   * @brief Creates the logical device for the Vulkan application.
   */
  void createLogicalDevice();

  /**
   * @brief Creates the swap chain for the Vulkan application.
   */
  void createSwapChain();

  /**
   * @brief Creates the image views for the Vulkan application.
   */
  void createImageViews();

  /**
   * @brief Creates the render pass for the Vulkan application.
   */
  void createRenderPass();

  /**
   * @brief Creates the descriptor set layout for the Vulkan application.
   */
  void createDescriptorSetLayout();

  /**
   * @brief Creates the graphics pipeline for the Vulkan application.
   */
  void createGraphicsPipeline();

  /**
   * @brief Creates the framebuffers for the Vulkan application.
   */
  void createFramebuffers();

  /**
   * @brief Creates the command pool for the Vulkan application.
   */
  void createCommandPool();

  /**
   * @brief Creates the vertex buffer for the Vulkan application.
   */
  void createVertexBuffer();

  /**
   * @brief Creates the index buffer for the Vulkan application.
   */
  void createIndexBuffer();

  /**
   * @brief Creates the uniform buffers for the Vulkan application.
   */
  void createUniformBuffers();

  /**
   * @brief Creates the descriptor pool for the Vulkan application.
   */
  void createDescriptorPool();

  /**
   * @brief Creates the descriptor sets for the Vulkan application.
   */
  void createDescriptorSets();

  /**
   * @brief Creates the command buffers for the Vulkan application.
   */
  void createCommandBuffers();

  /**
   * @brief Creates the synchronization objects for the Vulkan application.
   */
  void createSyncObjects();

  /**
   * @brief Checks if the validation layers are supported for the Vulkan
   * application.
   * @return True if the validation layers are supported, false otherwise.
   */
  bool checkValidationLayerSupport();

  /**
   * @brief Checks if the physical device is suitable for the Vulkan
   * application.
   * @param device The physical device to check.
   * @return True if the physical device is suitable, false otherwise.
   */
  bool isDeviceSuitable(VkPhysicalDevice device);

  /**
   * @brief Checks if the device extensions are supported for the Vulkan
   * application.
   * @param device The physical device to check.
   * @return True if the device extensions are supported, false otherwise.
   */
  bool checkDeviceExtensionSupport(VkPhysicalDevice device);

  /**
   * @brief Finds the queue families for the physical device.
   * @param device The physical device to find the queue families for.
   * @return The queue families for the physical device.
   */
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

  /**
   * @brief Queries the swap chain support for the physical device.
   * @param device The physical device to query the swap chain support for.
   * @return The swap chain support for the physical device.
   */
  SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

  /**
   * @brief Chooses the swap surface format for the Vulkan application.
   * @param availableFormats The available surface formats.
   * @return The chosen surface format.
   */
  VkSurfaceFormatKHR chooseSwapSurfaceFormat(
      const std::vector<VkSurfaceFormatKHR> &availableFormats);

  /**
   * @brief Chooses the swap present mode for the Vulkan application.
   * @param availablePresentModes The available present modes.
   * @return The chosen present mode.
   */
  VkPresentModeKHR chooseSwapPresentMode(
      const std::vector<VkPresentModeKHR> &availablePresentModes);

  /**
   * @brief Chooses the swap extent for the Vulkan application.
   * @param capabilities The surface capabilities.
   * @return The chosen swap extent.
   */
  VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);

  /**
   * @brief Creates a shader module for the Vulkan application.
   * @param code The code for the shader module.
   * @return The created shader module.
   */
  VkShaderModule createShaderModule(const std::vector<char> &code);

  /**
   * @brief Finds the memory type for the Vulkan application.
   * @param typeFilter The type filter.
   * @param properties The memory properties.
   * @return The found memory type.
   */
  uint32_t findMemoryType(uint32_t typeFilter,
                          VkMemoryPropertyFlags properties);

  /**
   * @brief Creates a buffer for the Vulkan application.
   * @param size The size of the buffer.
   * @param usage The usage of the buffer.
   * @param properties The memory properties of the buffer.
   * @param buffer The created buffer.
   * @param bufferMemory The memory for the created buffer.
   */
  void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage,
                    VkMemoryPropertyFlags properties, VkBuffer &buffer,
                    VkDeviceMemory &bufferMemory);

  /**
   * @brief Copies a buffer for the Vulkan application.
   * @param srcBuffer The source buffer.
   * @param dstBuffer The destination buffer.
   * @param size The size of the buffer.
   */
  void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

  /**
   * @brief Updates the uniform buffer for the Vulkan application.
   * @param currentImage The current image.
   */
  void updateUniformBuffer(uint32_t currentImage);

  /**
   * @brief Begins a single time command for the Vulkan application.
   * @return The command buffer for the single time command.
   */
  VkCommandBuffer beginSingleTimeCommands();

  /**
   * @brief Ends a single time command for the Vulkan application.
   * @param commandBuffer The command buffer for the single time command.
   */
  void endSingleTimeCommands(VkCommandBuffer commandBuffer);

  /**
   * @brief Transitions the image layout for the Vulkan application.
   * @param image The image to transition.
   * @param format The format of the image.
   * @param oldLayout The old layout of the image.
   * @param newLayout The new layout of the image.
   */
  void transitionImageLayout(VkImage image, VkFormat format,
                             VkImageLayout oldLayout, VkImageLayout newLayout);

  /**
   * @brief Copies a buffer to an image for the Vulkan application.
   * @param buffer The buffer to copy.
   * @param image The image to copy to.
   * @param width The width of the image.
   * @param height The height of the image.
   */
  void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width,
                         uint32_t height);

  /**
   * @brief Creates an image view for the Vulkan application.
   * @param image The image to create the view for.
   * @param format The format of the image.
   * @param aspectFlags The aspect flags of the image.
   * @return The created image view.
   */
  VkImageView createImageView(VkImage image, VkFormat format,
                              VkImageAspectFlags aspectFlags);

  /**
   * @brief Finds the supported format for the Vulkan application.
   * @param candidates The candidate formats.
   * @param tiling The tiling of the format.
   * @param features The features of the format.
   * @return The supported format.
   */
  VkFormat findSupportedFormat(const std::vector<VkFormat> &candidates,
                               VkImageTiling tiling,
                               VkFormatFeatureFlags features);

  /**
   * @brief Finds the depth format for the Vulkan application.
   * @return The depth format.
   */
  VkFormat findDepthFormat();

  /**
   * @brief Checks if the format has a stencil component for the Vulkan
   * application.
   * @param format The format to check.
   * @return True if the format has a stencil component, false otherwise.
   */
  bool hasStencilComponent(VkFormat format);

  /**
   * @brief Creates an image for the Vulkan application.
   * @param width The width of the image.
   * @param height The height of the image.
   * @param format The format of the image.
   * @param tiling The tiling of the image.
   * @param usage The usage of the image.
   * @param properties The memory properties of the image.
   * @param image The created image.
   * @param imageMemory The memory for the created image.
   */
  void createImage(uint32_t width, uint32_t height, VkFormat format,
                   VkImageTiling tiling, VkImageUsageFlags usage,
                   VkMemoryPropertyFlags properties, VkImage &image,
                   VkDeviceMemory &imageMemory);

  /**
   * @brief Gets the maximum usable sample count for the Vulkan application.
   * @return The maximum usable sample count.
   */
  VkSampleCountFlagBits getMaxUsableSampleCount();

  /**
   * @brief Creates the color resources for the Vulkan application.
   */
  void createColorResources();

  /**
   * @brief Creates the depth resources for the Vulkan application.
   */
  void createDepthResources();

  /**
   * @brief Begins a single time command for the Vulkan application.
   * @param commandPool The command pool for the single time command.
   * @return The command buffer for the single time command.
   */
  VkCommandBuffer beginSingleTimeCommands(VkCommandPool commandPool);

  /**
   * @brief Ends a single time command for the Vulkan application.
   * @param commandBuffer The command buffer for the single time command.
   * @param commandPool The command pool for the single time command.
   */
  void endSingleTimeCommands(VkCommandBuffer commandBuffer,
                             VkCommandPool commandPool);

  /**
   * @brief Transitions the image layout for the Vulkan application.
   * @param image The image to transition.
   * @param format The format of the image.
   * @param oldLayout The old layout of the image.
   * @param newLayout The new layout of the image.
   * @param commandPool The command pool for the transition.
   */
  void transitionImageLayout(VkImage image, VkFormat format,
                             VkImageLayout oldLayout, VkImageLayout newLayout,
                             VkCommandPool commandPool);

  /**
   * @brief Copies a buffer to an image for the Vulkan application.
   * @param buffer The buffer to copy.
   * @param image The image to copy to.
   * @param width The width of the image.
   * @param height The height of the image.
   * @param commandPool The command pool for the copy.
   */
  void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width,
                         uint32_t height, VkCommandPool commandPool);

  /**
   * @brief Gets the required extensions for the Vulkan application.
   * @return The required extensions.
   */
  std::vector<const char *> getRequiredExtensions();

  /**
   * @brief Populates the debug messenger create info for the Vulkan
   * application.
   * @param createInfo The create info to populate.
   */
  void populateDebugMessengerCreateInfo(
      VkDebugUtilsMessengerCreateInfoEXT &createInfo);

  /**
   * @brief Records the command buffer for the Vulkan application.
   * @param commandBuffer The command buffer to record.
   * @param imageIndex The index of the image.
   */
  void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

  /**
   * @brief Checks the Vulkan result for the Vulkan application.
   * @param err The Vulkan result to check.
   */
  static void check_vk_result(VkResult err);
  static VKAPI_ATTR VkBool32 VKAPI_CALL
  debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                VkDebugUtilsMessageTypeFlagsEXT messageType,
                const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
                void *pUserData) {
    std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
    return VK_FALSE;
  }
  static std::vector<char> readFile(const std::string &filename) {
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open()) {
      throw std::runtime_error("failed to open file!");
    }

    size_t fileSize = (size_t)file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();

    return buffer;
  }
  void InitImgui();

  static bool
  IsExtensionAvailable(const ImVector<VkExtensionProperties> &properties,
                       const char *extension) {
    for (const VkExtensionProperties &p : properties)
      if (strcmp(p.extensionName, extension) == 0)
        return true;
    return false;
  }
};
// Shader Data
const std::vector<Vertex> vertices = {{{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
                                      {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
                                      {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
                                      {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}};
const std::vector<uint16_t> indices = {0, 1, 2, 2, 3, 0};
struct UniformBufferObject {
  alignas(16) glm::mat4 model;
  alignas(16) glm::mat4 view;
  alignas(16) glm::mat4 proj;
};
#endif /* VULKAN_INIT */
