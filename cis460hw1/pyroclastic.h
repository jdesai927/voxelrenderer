#include "primitive.h"
#include "WriteBMP.h"

class Pyroclastic : public Primitive {
public:
	float* radius;
	vec3* center;

	Pyroclastic(int,float,float,int,float,vec3);
	float* getDensity(vec3*);
};