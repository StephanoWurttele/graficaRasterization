cmake_minimum_required(VERSION 3.19)
project(lab7)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab7 main.cpp)

target_link_libraries(lab7 -lOpenGL32 -lfreeGLUT -lglew32)
