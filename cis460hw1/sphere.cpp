#include "sphere.h"

Sphere::Sphere(int oct, float freq, float amp, int seed, float rad, vec3 cen) : Primitive(oct, freq, amp, seed) {
	radius = new float(rad);
	center = new vec3(cen.x, cen.y, cen.z);
}

float* Sphere::getDensity(vec3* pos) {
	float dist = length(*pos - *center);
	if (dist >= *radius) {
		return new float(0.0f);
	}
	return new float((*radius - dist)/ *radius);
}