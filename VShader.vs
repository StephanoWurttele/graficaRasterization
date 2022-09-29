#version 330 core
layout (location = 0) in vec3 aPos;
uniform mat4 matrix_model;
out vec4 posicion;

void main() {
  posicion = matrix_model * vec4(aPos, 1.0);
  gl_Position = posicion;
}
