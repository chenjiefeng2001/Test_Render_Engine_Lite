# FILEPATH: /c:/Users/14977/Documents/Git/TestRender_Lite/Test_Render_Engine_Lite/CMakeLists.txt
cmake_minimum_required(VERSION 3.5.0)
project(Test_Render_Engine VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard to 17
set(CMAKE_CXX_STANDARD 17)

# Include CTest
include(CTest)
enable_testing()

# Find Vulkan library
find_package(Vulkan REQUIRED FATAL_ERROR)

# Include Vulkan library directories
if(WIN32)
    include_directories(${Vulkan_INCLUDE_DIRS})
else()
    link_directories(${Vulkan_LIBRARY_DIRS})
endif()

# Include GLFW library directories
if(WIN32)
    set(GLFW_DIR ./GLFW)
    add_subdirectory(${GLFW_DIR})
    include_directories(${GLFW_DIR}/include)
elseif(APPLE)
    find_package(glfw3 REQUIRED)
    include_directories(${GLFW_INCLUDE_DIRS})
    link_directories(${GLFW_LIBRARY_DIRS})
else()
    find_package(glfw3 REQUIRED)
    include_directories(${GLFW_INCLUDE_DIRS})
endif()

# Include Dear ImGui library directories
set(IMGUI_DIR ./imgui)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends ..)

# Include GLM library directories
set(GLM_DIR ./glm)
include_directories(${GLM_DIR}/include)

# Set compile flags
set(CMAKE_C_FLAGES "${CMAKE_C_FLAGS} -DVK_PROTOTYPES")
set(CMAKE_CXX_FLAGES "${CMAKE_CXX_FLAGS} -DVK_PROTOTYPES")

# Set libraries to link
if(WIN32)
    set(LIBRARIES "glfw;Vulkan::Vulkan")
elseif(APPLE)
    set(LIBRARIES "glfw;${Vulkan_LIBRARIES}")
else()
    set(LIBRARIES "glfw;${Vulkan_LIBRARIES}")
endif()

# Set include directories
include_directories(
    ./include()
    ./include/algorithm()
)

# Add executable
add_executable(${PROJECT_NAME} 
    ./src/client.cpp
    ./src/glfw_init.cpp
    ./src/vulkan_init.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_vulkan.cpp
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC ${LIBRARIES})

# Set compile definitions
target_compile_definitions(${PROJECT_NAME} PUBLIC -DImTextureID=ImU64)

# Set CPack project name and version
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Include CPack
include(CPack)
