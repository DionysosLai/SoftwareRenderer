#include <iostream>
#include <algorithm>

#include "include/vector.h"

int main() {
	// ª˘¥°ƒ⁄»›≤‚ ‘
	printf("ª˘¥°ƒ⁄»›≤‚ ‘\n");
	Vector3f vec3f(1, 2, 3);
	vec3f += 3;
	vec3f *= 2;
	printf("%f\n", vec3f.lenght());
	Vector3f nvec3f = vec3f.normalized();
	vec3f.print();
	nvec3f.print();

	// µ„≥À≤‚ ‘
	printf("µ„≥À≤‚ ‘\n");
	Vector3f vec3f1(1, 2, 3);
	Vector3f vec3f2(3, 4, 5);
	printf("%f\n", vec3f1.dotProduct(vec3f2));

	// ≤Ê≥À≤‚ ‘
	printf("≤Ê≥À≤‚ ‘\n");
	(vec3f1.crossProduct(vec3f2)).print();

	

	while (true)
	{

	}
}