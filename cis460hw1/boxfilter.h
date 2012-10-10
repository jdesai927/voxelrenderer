#include "primitive.h"

class Boxfilter : public Primitive { 
public:
	float* radius;

	Boxfilter(int,float,float,int,float);
	float* getDensity(vec3*);
	float* splatPixel(vec3*);
};