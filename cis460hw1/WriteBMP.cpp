#include "WriteBMP.h"

istringstream WriteBMP::getNumStream(string reader) {
	reader = reader.substr(5, reader.size() - 1);
	return static_cast<istringstream>(reader);
}

vec3* WriteBMP::getVec(string reader) {
	istringstream myStream = getNumStream(reader);
	int i = 0;
	float temp;
	vec3* ret = new vec3(0.0f, 0.0f, 0.0f);
	while (myStream >> temp) {
		(*ret)[i] = temp;
		i++;
	}
	return ret;
}

vec3* WriteBMP::getTaglessVec(string reader) {
	istringstream myStream = static_cast<istringstream>(reader);
	int i = 0;
	float temp;
	vec3* ret = new vec3(0.0f, 0.0f, 0.0f);
	while (myStream >> temp) {
		(*ret)[i] = temp;
		i++;
	}
	return ret;
}

vector<int>* WriteBMP::getInts(string reader) {
	istringstream myStream = getNumStream(reader);
	int temp;
	vector<int>* ivec = new vector<int>();
	while (myStream >> temp) {
		ivec->push_back(temp);
	}
	return ivec;
}

vec3 WriteBMP::mapPoint(float px, float py, vec3 M, vec3 H, vec3 V) {
	float sx = px/(*resoX - 1);
	float sy = py/(*resoY - 1);
	return (M + ((2 * sx) - 1) * H + ((2 * sy) - 1) * V);
}

vec3* WriteBMP::rayMarch(vec3* rayInit, vec3 rayDirect, float k) {
	finalColor = new vec3(0.0f, 0.0f, 0.0f);
	float* T = new float(1.0f);
	rayDirect *= *stepSize;
	rayIncr(finalColor, rayInit, rayDirect, T, k, length(*rayInit - *origin) + *numVoxZ);
	return finalColor;
}

int WriteBMP::getVoxelIndex(vec3* rayPos) {
	if (rayPos->x <= origin->x || rayPos->y <= origin->y || rayPos->z >= origin->z
		|| rayPos->x >= *voxSize * *numVoxX + origin->x || rayPos->y >= *voxSize * *numVoxY + origin->y 
		|| rayPos->z <= -1 * *numVoxZ * *voxSize + origin->z) {
			return -1;
	}
	return floorf(rayPos->x - origin->x) + (*numVoxX * (floorf(rayPos->y - origin->y))) + (*numVoxX * *numVoxY * floorf(-1.0f * (rayPos->z - origin->z)));
}

void WriteBMP::rayIncr(vec3* colorVec, vec3* rayPos, vec3 rayToIncr, float* T, float k, float rayLength) {
	*Q = 1.0f;
	int ind = WriteBMP::getVoxelIndex(rayPos);
	if (ind == -1) {
		if (*entered || length(*eye - *rayPos) > rayLength) {
			*colorVec += *T * *bgColor;
			return;
		}
		*dens = 0.0f;
	} else {
		*entered = true;
		Voxel vox = allVoxels[ind];
		*dens = *vox.density;
		if (*vox.lightVal == -1 && *dens != 0.0f) {
			lrPos->x = lightPos->x;
			lrPos->y = lightPos->y;
			lrPos->z = lightPos->z;
			vec3 lidir = normalize(*rayPos - *lightPos);
			vec3* ldir = new vec3(lidir.x, lidir.y, lidir.z);
			*ldir *= *stepSize;
			lightMarch(lrPos, ldir, Q, length(*lightPos - *rayPos), 0.5f);
			*vox.lightVal = *Q;
		} else {
			*Q = *vox.lightVal;
		}
	}
	vec3 col(lightCol->x * matColor->x, lightCol->y * matColor->y, lightCol->z * matColor->z);
	
	float dT = exp(-1.0f * k * *stepSize * *dens);
	*T *= dT;
	*rayPos += rayToIncr;
	*colorVec += ((1 - dT)/k) * *T * col * *Q;
	*colorVec = clamp(*colorVec, 0.0f, 1.0f);
	if (*T < 0.01) {
		*colorVec += *T * *bgColor;
		return;
	}
	rayIncr(colorVec, rayPos, rayToIncr, T, k, rayLength);
}

void WriteBMP::lightMarch(vec3* currentRay, vec3* incr, float* T, float len, float k) {
	int ind = WriteBMP::getVoxelIndex(currentRay);
	if (ind == -1) {
		*lightDens = 0.0f;
	} else {
		Voxel vox = allVoxels[ind];
		*lightDens = *vox.density;
	}
	*T *= exp(-1.0f * k * *stepSize * *lightDens);
	*currentRay += *incr;
	if (*T < 0.01 || length(*currentRay - *lightPos) > len) {
		return;
	}
	lightMarch(currentRay, incr, T, len, k);
}

bool WriteBMP::intersectsGrid(vec3 checkRay, vec3 posRay) {
	vec3 myRay = posRay + checkRay * (origin->z - posRay.z)/checkRay.z;
	return (myRay.x >= origin->x && myRay.x < origin->x + *numVoxX * *voxSize && myRay.y >= origin->y && myRay.y <= origin->y + *numVoxY * *voxSize);
}