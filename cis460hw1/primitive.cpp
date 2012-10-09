#include "primitive.h"

Primitive::Primitive() {

}

Primitive::Primitive(int oct, float freq, float amp, int seed) {
	per = new Perlin(oct,freq,amp,seed);
}