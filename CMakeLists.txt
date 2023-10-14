cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Test_Render_Engine VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
include(CTest)
enable_testing()
if(APPLE)
     # for <GLFW/glfw3.h>
     include_directories(
        /usr/local/include
        /opt/local/include
        /opt/homebrew/include
    )
endif()
if(WIN32)
    file(GLOB PLATFORM_SRC
    "./src/init_windows.cpp"    
    "./src/vulkan_init.cpp"
    "./src/glfw_init.cpp"
    ${ImGUIDIR}/*.cpp
    ${ImGUIDIR}/backends/*.cpp
    )
elseif(UNIX)

endif()
add_executable(${PROJECT_NAME}
# "./src/init_windows.cpp"
# "./src/glfw_init.cpp"
# "./src/vulkan_init.cpp"
${SRC}
${PLATFORM_SRC}
)

set(ImGUIDIR "./imgui")
set(GLMDIR "./glm")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
target_include_directories(Test_Render_Engine 
    PRIVATE
    "./include/"
    "./GLFW/include/GLFW"
    ${ImGUIDIR}/backends()
    ${ImGUIDIR}/()
    ${GLMDIR}/()
)
find_package(Vulkan REQUIRED FATAL_ERROR)
include_directories(${Vulkan_INCLUDE_DIRS})
target_link_libraries(Test_Render_Engine PUBLIC ${Vulkan_LIBRARIES})
# add GLFW subdirectory
add_subdirectory(./GLFW)
# add IMGUI subdirectory
target_link_libraries(Test_Render_Engine PUBLIC glfw)