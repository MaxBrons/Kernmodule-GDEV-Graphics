#version 450 core

layout(location = 0) out vec4 FragColor;

layout(binding = 0) uniform sampler2D u_HeightMap;
layout(binding = 1) uniform sampler2D u_NormalMap;
layout(binding = 2) uniform sampler2D u_Dirt;
layout(binding = 3) uniform sampler2D u_Grass;
layout(binding = 4) uniform sampler2D u_Rock;
layout(binding = 5) uniform sampler2D u_Sand;
layout(binding = 6) uniform sampler2D u_Snow;

in vec3 v_PixelCoords;
in vec2 v_UV;

uniform vec3 u_LightDirection;
uniform vec3 u_CameraPosition;
uniform float u_TextureSmoothing;
uniform vec3 u_FogColorTop;
uniform vec3 u_FogColorBottom;

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

	float distance = length(v_PixelCoords - u_CameraPosition);
	float uvLerp = clamp((distance - 5) / 10f, -1, 1) * 0.5f + 0.5f;

	vec3 dirtColorClose = texture(u_Dirt, v_UV * 100).rgb;
	vec3 sandColorClose = texture(u_Sand, v_UV * 100).rgb;
	vec3 grassColorClose = texture(u_Grass, v_UV * 100).rgb;
	vec3 rockColorClose = texture(u_Rock, v_UV * 100).rgb;
	vec3 snowColorClose = texture(u_Snow, v_UV * 100).rgb;

	vec3 dirtColorFar = texture(u_Dirt, v_UV * 10).rgb;
	vec3 sandColorFar = texture(u_Sand, v_UV * 10).rgb;
	vec3 grassColorFar = texture(u_Grass, v_UV * 10).rgb;
	vec3 rockColorFar = texture(u_Rock, v_UV * 10).rgb;
	vec3 snowColorFar = texture(u_Snow, v_UV * 10).rgb;

	vec3 dirtColor = lerp(dirtColorClose, dirtColorFar, uvLerp);
	vec3 sandColor = lerp(sandColorClose, sandColorFar, uvLerp);
	vec3 grassColor = lerp(grassColorClose, grassColorFar, uvLerp);
	vec3 rockColor = lerp(rockColorClose, rockColorFar, uvLerp);
	vec3 snowColor = lerp(snowColorClose, snowColorFar, uvLerp);

	vec3 diffuse = lerp(lerp(lerp(lerp(dirtColor, sandColor, ds), grassColor, sg), rockColor, gr), snowColor, rs);

	float fog = clamp((distance - 1) / 10, 0, 1);

	vec3 viewDir = normalize(v_PixelCoords - u_CameraPosition);
	vec3 fogColor = lerp(u_FogColorBottom, u_FogColorTop, max(viewDir.y, 0.0f));

	vec4 result = vec4(lerp(diffuse * min(lightValue + 0.f, 1.0f), fogColor, fog), 1.0f);
	FragColor = result;
}