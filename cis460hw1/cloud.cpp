#include "cloud.h"

Cloud::Cloud(int oct, float freq, float amp, int seed, float rad, vec3 cen) : Primitive(oct, freq, amp, seed) {
	radius = new float(rad);
	center = new vec3(cen.x, cen.y, cen.z);
}

float* Cloud::getDensity(vec3* pos) {
	return new float(per->Get(pos->x, pos->y, -1.0f * pos->z) + ((1.0f - length(*pos - *center))/ *radius));
}