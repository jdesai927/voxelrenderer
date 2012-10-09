#include "pyroclastic.h"

Pyroclastic::Pyroclastic(int oct, float freq, float amp, int seed, float rad, vec3 cen) : Primitive(oct, freq, amp, seed) {
	radius = new float(rad);
	center = new vec3(cen.x, cen.y, cen.z);
}

float* Pyroclastic::getDensity(vec3* pos) {
	return new float(std::max( 0.0f,((1.0f - length(*pos - *center)/ *radius) + abs(per->Get(pos->x, pos->y, -1.0f * pos->z)))));
}