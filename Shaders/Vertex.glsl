#version 460 core

in vec3 IPosition;
in vec3 IColor;

layout(location = 0) out vec3 OPosition;
layout(location = 1) out vec3 OColor;

uniform float UX;
uniform float UY;

void main()
{
    gl_Position = vec4(UX + IPosition.x , UY - IPosition.y , IPosition.z , 1.0);
    OPosition = IPosition;
    OColor = IColor;
}
