#version 450 core

layout (location = 0) out vec4 fragColor;

uniform ivec2 uResolution;
uniform vec2 uPosition;
uniform float uScale;
uniform vec2 uZoom;
uniform vec4 uColor;

void main()
{
	//fragColor = uColor;
	//fragColor = vec4(gl_FragCoord.x / uResolution.x, gl_FragCoord.y / uResolution.y, 0.0, 1.0);

	vec2 uv = (((gl_FragCoord.xy / uResolution - 0.5) * uZoom) - uPosition) / uScale;

	if (length(uv) <= 0.5) {
		fragColor = uColor;
	}
	else {
		discard;
	}
};