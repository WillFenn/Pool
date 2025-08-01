#version 450 core

layout (location = 0) out vec4 fragColor;

uniform ivec2 uResolution;
uniform vec2 uPosition;
uniform vec2 uCameraScale;
uniform vec4 uColor;

void main()
{
	//fragColor = uColor;
	//fragColor = vec4(gl_FragCoord.x / uResolution.x, gl_FragCoord.y / uResolution.y, 0.0, 1.0);

	vec2 uv = (((gl_FragCoord.xy / uResolution - 0.5) * uCameraScale) - uPosition);

	if (length(uv) <= 0.5) {
		fragColor = vec4(0.0, 0.0, 0.0, 1.0);
	}
	else {
		discard;
	}
};