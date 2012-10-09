#pragma once

#include "glm-0.9.3.4\glm\glm.hpp"
#include "perlin.h"

using namespace glm;

class Primitive {

public:
	Perlin* per;

	Primitive();
	Primitive(int,float,float,int);
	virtual float* getDensity(vec3*) = 0;

};