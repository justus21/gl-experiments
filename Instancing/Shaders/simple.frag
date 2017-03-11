#version 440 core

layout (location = 1) uniform float time;
layout (location = 2) uniform sampler2D tex0;

in vec2 texCoord;

out vec4 color;

void main()
{
	color = vec4(texture(tex0, texCoord).rgb, 1.0f);
} 