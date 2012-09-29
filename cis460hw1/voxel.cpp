#include "voxel.h"

using namespace glm;

Voxel::Voxel() {
	lightVal = new float(-1.0f);
	density = new float(0.0f);
}

Voxel::Voxel(float rho, float light) {
	density = new float(rho);
	lightVal = new float(light);
}