#include "primitive.h"

class Sphere : public Primitive {

public:
	float* radius;
	vec3* center;

	Sphere(int,float,float,int,float,vec3);
	float* getDensity(vec3*);
};