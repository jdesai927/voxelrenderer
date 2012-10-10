#include "primitive.h"

class Cube : public Primitive {
	public:
	float* edgeLength;
	vec3* center;

	Cube(int,float,float,int,float,vec3);
	float* getDensity(vec3*);
};