#version 460 core

layout(location = 0) in vec3 IColor;

out vec4 OColor;

void main()
{
    OColor = vec4(IColor , 1.0);
}
