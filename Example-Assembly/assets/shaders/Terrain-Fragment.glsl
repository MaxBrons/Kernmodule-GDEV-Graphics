#version 450 core

layout(location = 0) out vec4 FragColor;

layout(binding = 0) uniform sampler2D u_HeightMap;
layout(binding = 1) uniform sampler2D u_NormalMap;

uniform vec3 u_LightDirection;
uniform vec3 u_CameraPosition;

in vec3 v_PixelCoords;
in vec2 v_UV;

void main()
{
	vec3 normal = texture(u_NormalMap, v_UV).rbg;
	normal = normalize(normal * 2.0 - 1.0f);
	normal.b *= -1;

	vec3 lightDirection = u_LightDirection * vec3(1, -1, 1);
	float lightValue = max(-dot(normal, lightDirection), 0.0f);

	vec4 fragOutput = texture(u_HeightMap, v_UV);
	fragOutput.rgb = vec3(min(lightValue + 0.f, 1.0f));

	FragColor = fragOutput;
}