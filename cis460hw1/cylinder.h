#include "primitive.h"

class Cylinder : public Primitive {
public:
	vec3* center;
	float* radius;

	Cylinder(int,float,float,int,float,vec3);
	float* getDensity(vec3*);

};