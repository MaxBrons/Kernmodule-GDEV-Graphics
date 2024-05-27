#version 330 core
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Color;
layout(location = 2) in vec2 a_UV;
layout(location = 3) in vec3 a_Normal;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec3 v_PixelCoords;
out vec3 v_PixelNormal;
out vec2 v_UV;
out vec3 v_VertexColor;

void main()
{
	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);

	v_PixelCoords = mat3(u_Transform) * a_Position;
	v_PixelNormal = mat3(u_Transform) * a_Normal;
	v_UV = a_UV;
	v_VertexColor = a_Color;
}
