#version 450 core

layout(location = 0) out vec4 FragColor;

layout(binding = 0) uniform sampler2D u_MainTex;
layout(binding = 1) uniform sampler2D u_Normal;

uniform vec3 u_LightDirection;
uniform vec3 u_CameraPosition;

in vec3 v_PixelCoords;
in vec3 v_Normal;
in vec2 v_UV;

void main()
{
	float lightValue = max(-dot(v_Normal, u_LightDirection), 0.0f);
	
	vec4 result = texture(u_MainTex, v_UV);
	result.rgb = result.rgb * min(lightValue + 0.1f, 1.0f);

	FragColor = result;
}