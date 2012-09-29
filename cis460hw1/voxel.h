#include "glm-0.9.3.4\glm\glm.hpp"

class Voxel {

public:
	float* lightVal;
	float* density;
	Voxel();
	Voxel(float rho, float light);

};