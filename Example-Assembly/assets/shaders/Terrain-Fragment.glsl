#version 450 core

layout(location = 0) out vec4 FragColor;

layout(binding = 0) uniform sampler2D u_HeightMap;
layout(binding = 1) uniform sampler2D u_NormalMap;
layout(binding = 2) uniform sampler2D u_Dirt;
layout(binding = 3) uniform sampler2D u_Grass;
layout(binding = 4) uniform sampler2D u_Rock;
layout(binding = 5) uniform sampler2D u_Sand;
layout(binding = 6) uniform sampler2D u_Snow;

uniform vec3 u_LightDirection;
uniform vec3 u_CameraPosition;
uniform float u_TextureSmoothing;

in vec3 v_PixelCoords;
in vec2 v_UV;

vec3 lerp(vec3 a, vec3 b, float t)
{
	return a + (b - a) * t;
}

void main()
{
	vec3 normal = texture(u_NormalMap, v_UV).rbg;
	normal = normalize(normal * 2.0 - 1.0f);
	normal.b *= -1;

	vec3 lightDirection = u_LightDirection * vec3(1, -1, 1);
	float lightValue = max(-dot(normal, lightDirection), 0.0f);

	float y = v_PixelCoords.y * 100;

	float ds = clamp((y - 50) / u_TextureSmoothing, -1, 1) * 0.5f + 0.5f;
	float sg = clamp((y - 100) / u_TextureSmoothing, -1, 1) * 0.5f + 0.5f;
	float gr = clamp((y - 200) / u_TextureSmoothing, -1, 1) * 0.5f + 0.5f;
	float rs = clamp((y - 300) / u_TextureSmoothing, -1, 1) * 0.5f + 0.5f;

	vec3 dirtColor = texture(u_Dirt, v_UV * 10).rgb;
	vec3 sandColor = texture(u_Sand, v_UV * 10).rgb;
	vec3 grassColor = texture(u_Grass, v_UV * 10).rgb;
	vec3 rockColor = texture(u_Rock, v_UV * 10).rgb;
	vec3 snowColor = texture(u_Snow, v_UV * 10).rgb;

	vec3 diffuse = lerp(lerp(lerp(lerp(dirtColor, sandColor, ds), grassColor, sg), rockColor, gr), snowColor, rs);

	vec4 result = vec4(diffuse * min(lightValue + 0.f, 1.0f), 1.0f);
	FragColor = result;
}