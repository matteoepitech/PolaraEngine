#version 330 core

out vec4 frag_color;
  
in vec2 tex_coord;

uniform sampler2D u_sampler_texture;

void main()
{
    vec4 tex_sample = texture(u_sampler_texture, tex_coord);

    frag_color = tex_sample * vec4(1.0f, 1.0f, 1.0f, 1.0f); // * is the color
} 
