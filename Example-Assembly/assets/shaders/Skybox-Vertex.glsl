#version 330 core
layout(location = 0) in vec3 a_Position;
layout(location = 3) in vec3 a_Normal;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec3 v_PixelCoords;

void main()
{
	v_PixelCoords = mat3(u_Transform) * a_Position;

	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
}
