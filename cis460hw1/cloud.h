#include "primitive.h"

class Cloud : public Primitive {

public:
	float* radius;
	vec3* center;

	Cloud(int,float,float,int,float,vec3);
	float* getDensity(vec3*);
};