#version 330 core
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_UV;
layout(location = 3) in vec3 a_Normal;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

uniform sampler2D u_MainTexture;

out vec4 v_PixelCoords;
out vec4 v_VertexColor;
out vec2 v_TexCoords;
out vec3 v_PixelNormal;

void main()
{
	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);

	v_PixelCoords = u_Transform * vec4(a_Position, 1.0);
	v_VertexColor = a_Color * texture(u_MainTexture, a_UV);
	v_TexCoords = a_UV;
	v_PixelNormal = mat3(u_Transform) * a_Normal;
}
