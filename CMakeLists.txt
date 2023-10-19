cmake_minimum_required(VERSION 3.5.0)
project(Test_Render_Engine VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package(Vulkan REQUIRED FATAL_ERROR)
include_directories(${Vulkan_INCLUDE_DIRS})
#use this to link vulkan library
include_directories(${GLFW_DIR}/deps)
#set(LIBRARIES "glfw;${VULKAN_LIBRARY}")
set(LIBRARIES "glfw;Vulkan::Vulkan")

#match the source file
# file(GLOB sources *.cpp)
#include dear imgui
set(IMGUI_DIR ./imgui)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends ..)
set(GLM_DIR ./glm)
include_directories(${GLM_DIR}/include)
# add GLFW subdirectory
set(GLFW_DIR ./GLFW)
add_subdirectory(${GLFW_DIR})
include_directories(${GLFW_DIR}/include)

set(CMAKE_C_FLAGES "${CMAKE_C_FLAGS} -DVK_PROTOTYPES")
set(CMAKE_CXX_FLAGES "${CMAKE_CXX_FLAGS} -DVK_PROTOTYPES")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# target_include_directories(./include)
include(CPack)

include_directories(
    ./include()
    ./include/algorithm()
    )





# target_link_libraries(Test_Render_Engine PUBLIC ${Vulkan_LIBRARIES})
add_executable(${PROJECT_NAME} 
    # ./src/test.cpp
    ./src/QS.cpp
    ./src/algorithms/numericaL.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_vulkan.cpp
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${LIBRARIES})
target_compile_definitions(${PROJECT_NAME} PUBLIC -DImTextureID=ImU64)
