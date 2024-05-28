#version 330 core

layout(location = 0) out vec4 gl_Color;

uniform vec3 u_Color;

void main()
{
	gl_Color = vec4(u_Color, 1.0f);
}