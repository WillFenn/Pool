#version 450 core

layout (location = 0) out vec4 fragColor;

uniform ivec2 uResolution;
uniform float uRadius;
uniform vec2 uPosition;
uniform mat4 uRotationMatrix;
uniform vec2 uWorldScale;
uniform vec4 uColor;
uniform int uStriped;
uniform sampler2D uTexture;

const float PI = 3.14159265359;

void main() {
	vec2 uvBeforeRotation = (((gl_FragCoord.xy / uResolution - 0.5) * uWorldScale) - uPosition);

	if (length(uvBeforeRotation) <= uRadius) {
		float wBeforeRotation = sqrt(uRadius * uRadius - uvBeforeRotation.x * uvBeforeRotation.x - uvBeforeRotation.y * uvBeforeRotation.y);

		vec3 uvwBeforeRotation = vec3(uvBeforeRotation, wBeforeRotation);
		vec4 uvw = uRotationMatrix * vec4(uvwBeforeRotation, 1.0f);

		float phi = acos(uvw.z / uRadius);

		float theta;

		if ((uvw.x < 0 && uvw.y > 0) || (uvw.x < 0 && uvw.y < 0)) {
			theta = atan(uvw.y / uvw.x) + PI;
		}
		else if (uvw.x > 0 && uvw.y < 0) {
			theta = atan(uvw.y / uvw.x) + 2 * PI;
		}
		else {
			theta = atan(uvw.y / uvw.x);
		}

		float normTheta = theta / (2 * PI);
		float normPhi = phi / PI;

		fragColor = texture(uTexture, vec2(normTheta, normPhi));
	}
	else {
		discard;
	}
};