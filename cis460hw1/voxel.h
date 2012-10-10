#include "glm-0.9.3.4\glm\glm.hpp"

class Voxel {

public:
	float* lightVal;
	float* lightVal2;
	float* density;
	Voxel();
	Voxel(float rho, float light);

};