#version 330 core
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Color;
layout(location = 2) in vec2 a_UV;
layout(location = 3) in vec3 a_Normal;
layout(location = 4) in vec3 a_Tangent;
layout(location = 5) in vec3 a_Bitangent;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec3 v_PixelCoords;
out mat3 m_TBN;
out vec2 v_UV;
out vec3 v_VertexColor;

void main()
{
	v_PixelCoords = mat3(u_Transform) * a_Position;
	vec3 normal = normalize(mat3(u_Transform) * a_Normal);
	vec3 tangent = normalize(mat3(u_Transform) * a_Tangent);
	vec3 bitangent = normalize(mat3(u_Transform) * a_Bitangent);
	
	m_TBN = mat3(tangent, bitangent, normal);

	v_UV = a_UV;
	v_VertexColor = a_Color;

	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
}
