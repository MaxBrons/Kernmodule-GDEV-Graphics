#version 450 core

layout(location = 0) out vec4 FragColor;

layout(binding = 0) uniform sampler2D texture_diffuse1;
layout(binding = 1) uniform sampler2D texture_specular1;
layout(binding = 2) uniform sampler2D texture_normal1;
layout(binding = 3) uniform sampler2D texture_roughness1;
layout(binding = 4) uniform sampler2D texture_ao1;

in vec4 v_PixelCoords;
in vec3 v_Normal;
in vec2 v_UV;

uniform vec3 u_LightDirection;
uniform vec3 u_CameraPosition;
uniform vec3 u_FogColorTop;
uniform vec3 u_FogColorBottom;

float lerp(float a, float b, float t)
{
	 return a + (b - a) * t;
}

vec3 lerp(vec3 a, vec3 b, float t)
{
	 return a + (b - a) * t;
}

vec4 lerp(vec4 a, vec4 b, float t)
{
	 return a + (b - a) * t;
}

void main()
{
	vec4 diffuse = texture(texture_diffuse1, v_UV);
	vec3 specularText = texture(texture_specular1, v_UV).rgb;

	float light = max(-dot(-u_LightDirection, v_Normal), 0.0f);

	vec3 viewDir = normalize(u_CameraPosition - v_PixelCoords.xyz);
	vec3 reflection = reflect(u_LightDirection, v_Normal);

	float ambientOcclusion = texture(texture_ao1, v_UV).r;

	float roughness = texture(texture_roughness1, v_UV).r;
	float spec = pow(max(-dot(viewDir, reflection), 0.0f), lerp(1, 128, roughness));
	vec3 specular = spec * specularText;

	float distance = length(v_PixelCoords.xyz - u_CameraPosition);
	float fog = clamp((distance - 1) / 10, 0, 1);
	vec3 fogColor = lerp(u_FogColorBottom, u_FogColorTop, max(viewDir.y, 0.0f));

	FragColor = lerp(diffuse * max(light * ambientOcclusion, 0.2f * ambientOcclusion) + vec4(specular, 0.0f), vec4(fogColor, 1.0f), fog);
	FragColor.a = 1.0f;
}