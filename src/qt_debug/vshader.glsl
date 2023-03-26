#version 330 core
// Positions/Coordinates
layout (location = 0) in vec3 aPos;

vec3 color = vec3(1,0,0);
out vec4 f_color;

uniform mat4 camMatrix;
vec4 mvp_vec;

void main()
{
    // Calculate vertex position in screen space
    mvp_vec = camMatrix * vec4(aPos, 10);
    gl_Position = mvp_vec;
    gl_PointSize = 10.0;
    f_color = vec4(color, 1.0);
}
