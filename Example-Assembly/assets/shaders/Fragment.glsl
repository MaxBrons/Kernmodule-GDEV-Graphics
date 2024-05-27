#version 330 core

layout(location = 0) out vec4 a_FragColor;

uniform sampler2D u_MainTexture;
uniform vec3 u_LightPosition;

in vec3 v_PixelCoords;
in vec3 v_PixelNormal;
in vec2 v_UV;
in vec3 v_VertexColor;

void main()
{
	vec3 lightDirection = normalize(v_PixelCoords - u_LightPosition);
	float lightValue = max(-dot( v_PixelNormal, lightDirection), 0.0f);
	
	a_FragColor = vec4(v_VertexColor, 1.0f) * texture(u_MainTexture, v_UV) * min(lightValue + 0.1f, 1.0f);
	a_FragColor.a = 1.0f;
}