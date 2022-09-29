cmake_minimum_required(VERSION 3.19)
project(lab7)

include_directories(src, include)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab7 main.cpp src/Mat4.cpp include/Mat4.h)

target_link_libraries(lab7 -lOpenGL32 -lfreeGLUT -lglew32)
