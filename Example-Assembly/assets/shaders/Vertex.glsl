#version 330 core
layout(location = 0) in vec3 a_Position;
layout(location = 0) in vec4 a_Color;
layout(location = 0) in vec2 a_UV;
layout(location = 0) in vec3 a_Normal;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec4 v_PixelCoords;
out vec4 v_VertexColor;
out vec2 v_TexCoords;
out vec3 v_PixelNormal;

void main()
{
	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);

	v_PixelCoords = u_Transform * vec4(a_Position, 1.0);
	v_PixelNormal = mat3(u_Transform) * a_Normal;
	v_VertexColor = a_Color;
	v_TexCoords = a_UV;
}
