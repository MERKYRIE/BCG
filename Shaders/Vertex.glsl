#version 460 core

in vec3 IPosititon;

void main()
{
    gl_Position = vec4(IPosititon , 1.0);
}
