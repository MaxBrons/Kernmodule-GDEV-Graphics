#version 450 core
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Normal;
layout(location = 2) in vec2 a_UV;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec4 v_PixelCoords;
out vec3 v_Normal;
out vec2 v_UV;

void main()
{
	v_PixelCoords = u_Transform * vec4(a_Position, 1.0f);
	v_UV = a_UV;

	gl_Position = u_ViewProjection * v_PixelCoords;

	v_Normal = normalize(mat3(inverse(transpose(u_Transform))) * a_Normal);
}