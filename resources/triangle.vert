#version 330 core

layout (location = 0) in vec3 l_pos;
  
out vec4 vertex_color;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
    gl_Position = u_projection * u_view * u_model * vec4(l_pos, 1.0);
    vertex_color = vec4(0.5, 0.0, 0.0, 1.0);
}
