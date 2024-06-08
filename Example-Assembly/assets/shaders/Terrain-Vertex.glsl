#version 330 core
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Normal;
layout(location = 2) in vec2 a_UV;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec3 v_PixelCoords;
out vec3 v_Normal;
out vec2 v_UV;

void main()
{
	v_PixelCoords = mat3(u_Transform) * a_Position;
	v_UV = a_UV;
	v_Normal = a_Normal;

	gl_Position = u_ViewProjection * vec4(v_PixelCoords, 1.0f);
}
