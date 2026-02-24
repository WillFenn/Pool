#version 450 core

layout (location = 0) out vec4 fragColor;

uniform ivec2 uResolution;
uniform float uRadius;
uniform vec2 uPosition;
uniform float uThetaRotation;
uniform float uPhiRotation;
uniform vec2 uWorldScale;
uniform vec4 uColor;
uniform int uStriped;
uniform sampler2D uTexture;

const float PI = 3.14159265359;

void main() {
	vec2 uv = (((gl_FragCoord.xy / uResolution - 0.5) * uWorldScale) - uPosition);

	if (length(uv) <= uRadius) {
		float w = sqrt(uRadius * uRadius - uv.x * uv.x - uv.y * uv.y);

		vec3 uvwBeforeRotation(uv, w);
		vec3 uvwAfterRotation = uvwBeforeRotation * cos(uPhiRotation);	// finish

		float phi = uPhiRotation + acos(w / uRadius);

		bool thetaShouldBeRotated = false;

		// set phi to be between 0 and PI
		while (phi < 0) {
			phi += 2 * PI;
			thetaShouldBeRotated = true;
		}
		phi = mod(phi, 2 * PI);
		if (phi > PI) {
		discard; // delete
			phi = 2 * PI - phi;
			thetaShouldBeRotated = true;
		}

		float theta;

		if (uv.x < 0) {
			theta = uThetaRotation + (atan(uv.y / uv.x) + PI);
		}
		else {
			theta = uThetaRotation + atan(uv.y / uv.x);
		}

		if (thetaShouldBeRotated) {
			theta += PI;
		}
		
		// set theta to be between 0 and 2PI
		while (theta < 0) {
			theta += 2 * PI;
		}
		theta = mod(theta, 2 * PI);

		float normTheta = theta / (2 * PI);
		float normPhi = phi / PI;

		fragColor = texture(uTexture, vec2(normTheta, normPhi));
	}
	else {
		discard;
	}
};