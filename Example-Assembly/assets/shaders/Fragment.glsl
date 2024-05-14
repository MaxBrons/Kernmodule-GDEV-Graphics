#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;

in vec4 v_PixelCoords;
in vec4 v_VertexColor;
in vec2 v_TexCoords;
in vec3 v_PixelNormal;

void main()
{
	color = u_Color;
}