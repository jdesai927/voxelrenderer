#include "cube.h"

Cube::Cube(int oct, float freq, float amp, int seed, float rad, vec3 cen) : Primitive(oct, freq, amp, seed) {
	edgeLength = new float(rad);
	center = new vec3(cen.x, cen.y, cen.z);
}

float* Cube::getDensity(vec3* pos) {
	//float f =  + ((1.0f - length(*pos - *center))/ *edgeLength);
	float f = per->Get(pos->x, pos->y, -1.0f * pos->z);
	f += (1.0f - (((abs(pos->x - center->x) / *edgeLength) + (abs(pos->y - center->y) / *edgeLength) + (abs(pos->z - center->z) / *edgeLength))/6.0f));
	if (f < 0) {
		return new float(0.0f);
	}
	return new float(f);
}