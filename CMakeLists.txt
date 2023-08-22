cmake_minimum_required(VERSION 3.0.0)
project(Test_Render_Engine VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Test_Render_Engine main.cpp "src/client.cpp" "src/client.h")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
target_include_directories(./include)
include(CPack)
include_directories(./include)
