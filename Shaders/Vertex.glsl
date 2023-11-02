#version 460 core

in vec3 IPosititon;
in vec3 IColor;

layout(location = 0) out vec3 OColor;

void main()
{
    gl_Position = vec4(IPosititon , 1.0);
    OColor = IColor;
}
