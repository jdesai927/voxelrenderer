#pragma once

#include "boxfilter.h"
#include "WriteBMP.h"

Boxfilter::Boxfilter(int oct, float freq, float amp, int seed, float rad) : Primitive(oct, freq, amp, seed) {
	radius = new float(rad);
}

float* Boxfilter::getDensity(vec3* pos) {
	float r = per->Get(pos->x, pos->y, pos->z * -1.0f);
	return new float(r);
}

float* Boxfilter::splatPixel(vec3* pos) {
	float dens = 0;
	vec3 cur;
	cur.x = pos->x;
	cur.y = pos->y;
	cur.z = pos->z;
	int ind;
	for (float x = pos->x - *radius; x < pos->x + *radius; x += *WriteBMP::voxSize) {
		cur.x = x;
		ind = WriteBMP::getVoxelIndex(&cur);
		if (ind == -1) {
			continue;
		}
		dens += *WriteBMP::allVoxels[ind].density;
	}
	cur.x = pos->x;
	for (float y = pos->y - *radius; y < pos->y + *radius; y += *WriteBMP::voxSize) {
		cur.y = y;
		ind = WriteBMP::getVoxelIndex(&cur);
		if (ind == -1) {
			continue;
		}
		dens += *WriteBMP::allVoxels[ind].density;
	}
	cur.y = pos->y;
	for (float z = pos->z + *radius; z < pos->z + *radius; z += *WriteBMP::voxSize) {
		cur.z = z;
		ind = WriteBMP::getVoxelIndex(&cur);
		if (ind == -1) {
			continue;
		}
		dens += *WriteBMP::allVoxels[ind].density;
	}
	return new float(dens);
}