#version 450 core

layout (location = 0) out vec4 fragColor;

uniform ivec2 uResolution;
uniform float uRadius;
uniform vec2 uPosition;
uniform vec2 uWorldScale;
uniform vec4 uColor;
uniform int uStriped;

void main() {
	vec2 uv = (((gl_FragCoord.xy / uResolution - 0.5) * uWorldScale) - uPosition);

	if (length(uv) <= uRadius) {
		fragColor = uColor;
		
		if (uStriped != 0 && abs(uv.y) > 0.3) {
			fragColor = vec4(1.0, 1.0, 1.0, 1.0);
		}
	}
	else {
		discard;
	}
};