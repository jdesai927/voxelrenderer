#include "cylinder.h"

Cylinder::Cylinder(int oct, float freq, float amp, int seed, float rad, vec3 cen) : Primitive(oct, freq, amp, seed) {
	radius = new float(rad);
	center = new vec3(cen.x, cen.y, cen.z);
}

float* Cylinder::getDensity(vec3* pos) {
	vec2 pos2(pos->x, pos->z);
	vec2 cen2(center->x, center->z);
	float f = 1.0f - (length(cen2 - pos2)/ *radius);
	f += per->Get(pos->x, pos->y, -1.0f * pos->z);
	if (abs(pos->y - center->y) > 2 * *radius) {
		f = 0;
	}
	if (f < 0) {
		return new float(0.0f);
	}
	return new float(f);
}