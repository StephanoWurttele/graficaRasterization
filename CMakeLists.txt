cmake_minimum_required(VERSION 3.19)
project(lab7)

include_directories(src, include)
set(CMAKE_CXX_STANDARD 20)

add_executable(lab7 main.cpp src/Mat4.cpp include/Mat4.h)

if(UNIX AND NOT APPLE)
    find_package(GLEW REQUIRED)
    find_package(GLUT REQUIRED)
    find_package(OpenGL REQUIRED)
    target_link_libraries(lab7 OpenGL::GL GLUT::GLUT GLEW::GLEW)
else()
    target_link_libraries(lab7 -lOpenGL32 -lfreeGLUT -lglew32)
endif()