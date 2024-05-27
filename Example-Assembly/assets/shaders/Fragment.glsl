#version 330 core

layout(location = 0) out vec4 a_FragColor;

uniform sampler2D u_AlbedoTexture;
uniform sampler2D u_NormalTexture;
uniform vec3 u_LightPosition;

in vec3 v_PixelCoords;
in mat3 m_TBN;
in vec2 v_UV;
in vec3 v_VertexColor;

void main()
{
	vec3 normal = texture(u_NormalTexture, v_UV).rgb;
	normal = normalize(normal * 2.0f - 1.0f);
	normal = m_TBN * normal;

	vec3 lightDirection = normalize(v_PixelCoords - u_LightPosition);
	float lightValue = max(dot(normal, lightDirection), 0.0f);

	a_FragColor = vec4(v_VertexColor, 1.0f) * texture(u_AlbedoTexture, v_UV) * min(lightValue + 0.1f, 1.0f);
	a_FragColor.a = 1.0f;
}