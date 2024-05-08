#version 330 core
out vec4 FragColor;
  
in vec3 o_VertexColor;

void main()
{
    FragColor = vec4(o_VertexColor, 1.0f);
} 