#version 460 core

in vec3 IPosition;

uniform mat4 UProjection;
uniform mat4 UView;
uniform mat4 UModel;

void main()
{
    gl_Position = UProjection * UView * UModel * vec4(IPosition , 1.0);
}
