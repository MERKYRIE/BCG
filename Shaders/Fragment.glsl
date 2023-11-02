#version 460 core

layout(location = 0) in vec3 IPosition;
layout(location = 1) in vec3 IColor;

out vec4 OColor;

void main()
{
    OColor = vec4(IPosition , 1.0);
}
