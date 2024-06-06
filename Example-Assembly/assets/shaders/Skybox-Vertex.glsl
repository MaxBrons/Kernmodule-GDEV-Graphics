#version 330 core
layout(location = 0) in vec3 a_Position;
layout(location = 3) in vec3 a_Normal;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec4 v_PixelCoords;

void main()
{
	v_PixelCoords = u_Transform * vec4(a_Position, 1.0);

	gl_Position = u_ViewProjection * v_PixelCoords;
}
