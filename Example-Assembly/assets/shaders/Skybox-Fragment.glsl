#version 450 core

layout(location = 0) out vec4 FragColor;

uniform vec3 u_LightDirection;
uniform vec3 u_CameraPosition;

in vec4 v_PixelCoords;

vec3 lerp(vec3 a, vec3 b, float t){
	return a + (b - a) * t;
}

void main()
{
	vec3 topColor = vec3(68.0f / 255.0f, 118.0f / 255.0f, 189.0f / 255.0f);
	vec3 botColor = vec3(188.0f / 255.0f, 214.0f / 255.0f, 231.0f / 255.0f);

	vec3 sunColor = vec3(1.0f, 200.0f / 255.0f, 50.0f / 255.0f);

	vec3 viewDir = normalize(v_PixelCoords.rgb - u_CameraPosition);
	float sun = pow(min(max(dot(viewDir, u_LightDirection), 0.0f), 1.0f), 128);
	
	FragColor = vec4(lerp(botColor, topColor, abs(viewDir.y)) + sun * sunColor, 1);
}