#version 450 core

layout(location = 0) out vec4 FragColor;

uniform vec3 u_LightDirection;
uniform vec3 u_CameraPosition;

in vec3 v_PixelCoords;

vec3 lerp(vec3 a, vec3 b, float t){
	return a + (b - a) * t;
}

void main()
{
	vec3 topColor = vec3(68.0f / 255.0f, 118.0f / 255.0f, 189.0f / 255.0f);
	vec3 botColor = vec3(188.0f / 255.0f, 214.0f / 255.0f, 231.0f / 255.0f);

	vec3 viewDir = normalize(v_PixelCoords - u_CameraPosition);
	
	FragColor = vec4(lerp(botColor, topColor, max(viewDir.y, 0.0)), 1);
}