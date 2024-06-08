#version 450 core
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Normal;
layout(location = 2) in vec2 a_UV;

layout(binding = 0) uniform sampler2D u_HeightMap;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;
uniform float u_TerrainHeight;

out vec3 v_PixelCoords;
out vec2 v_UV;

void main()
{
	v_PixelCoords = mat3(u_Transform) * a_Position;
	v_UV = a_UV;

	gl_Position = u_ViewProjection * vec4(v_PixelCoords, 1.0f);
}
