#version 450 core

layout(location = 0) out vec4 FragColor;

layout(binding = 0) uniform sampler2D u_AlbedoTexture;
layout(binding = 1) uniform sampler2D u_NormalTexture;

uniform vec3 u_LightDirection;
uniform vec3 u_CameraPosition;
uniform vec3 u_LightColor;

in vec3 v_PixelCoords;
in mat3 m_TBN;
in vec2 v_UV;
in vec3 v_VertexColor;

void main()
{
	vec3 normal = texture(u_NormalTexture, v_UV).rgb;
	normal = normalize(normal * 2.0f - 1.0f);
	normal.rg = normal.rg * 0.1f;
	normal = normalize(normal);
	normal = m_TBN * normal;
	
	vec3 viewDir = normalize(v_PixelCoords - u_CameraPosition);
	vec3 reflDirection = normalize(reflect(u_LightDirection, normal));
	
	float lightValue = max(dot(normal, u_LightDirection), 0.0f);
	float specular = pow(max(dot(reflDirection, viewDir), 0.0f), 64);
	
	vec3 vertColor = v_VertexColor.rgb * texture(u_AlbedoTexture, v_UV).rgb;
	vertColor = vertColor * min(lightValue, 1.0f) + specular;

	vec3 lightColor = u_LightColor * texture(u_AlbedoTexture, v_UV).rgb;
	lightColor = lightColor * min(lightValue, 1.0f) + specular * u_LightColor;

	FragColor = vec4(vertColor + lightColor, 1.0f);
}