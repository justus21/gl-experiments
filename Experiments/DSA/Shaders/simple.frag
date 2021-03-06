#version 450 core
layout (binding = 1) uniform sampler2D tex0;
layout (location = 0) uniform float time;

in vec2 texCoord;
in vec3 normal_World;

out vec4 color;

void main()
{
	vec3 lightDir = normalize(-vec3(-1.0f, -1.0f, 1.0f));
	float diff = max(dot(normal_World, lightDir), 0.0);
	vec4 texColor = vec4(texture(tex0, texCoord).rgb, 1.0f);
	float f = sin(time);
	color = 0.1 * texColor + diff * texColor + vec4(0.0f, 0.0f, 0.5f, 0.0f) * f;
} 