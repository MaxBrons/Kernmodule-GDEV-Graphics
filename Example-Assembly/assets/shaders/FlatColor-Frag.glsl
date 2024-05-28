#version 330 core

layout(location = 0) out vec4 a_Color;

uniform vec3 u_Color;

void main()
{
	a_Color = vec4(u_Color, 1.0f);
}