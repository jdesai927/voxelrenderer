#include <math.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include "voxel.h"
#include <string>
#include <vector>
#include "EasyBMP.h"

using namespace std;
using namespace glm;

static class WriteBMP {

public:
	static vec3* eye;
	static vec3* camDirection;
	static vec3* upVec;
	static vec3* finalColor;
	static vec3* bgColor;
	static vec3* matColor;
	static vec3* ray;
	static Voxel* allVoxels;
	static vec3* A;
	static float* voxSize;
	static float* stepSize;
	static float* fovx;
	static float* fovy;
	static float* numVoxX;
	static float* numVoxY;
	static float* numVoxZ;
	static float* resoX;
	static float* resoY;
	static float* dens;
	static vec3* lightCol;
	static vec3* lightPos;
	static vec3* lrPos;
	static float* Q;
	static vec3* finalLight;
	static bool* entered;
	static float* lightDens;
	static vec3* origin;
	static vec3* center;
	//static bool* lightIn;

	static istringstream getNumStream(string);
	static vec3* getTaglessVec(string);
	static vec3* getVec(string);
	static vector<int>* getInts(string);
	static vec3 mapPoint(float, float, vec3, vec3, vec3);
	static int getVoxelIndex(vec3* rayPos);
	static vec3* rayMarch(vec3*, vec3, float);
	static void rayIncr(vec3*, vec3*, vec3, float*, float, float);
	static void lightMarch(vec3*,vec3*,float*,float,float);
	static bool intersectsGrid(vec3, vec3);

};