#include <iostream>
#include <algorithm>

#include "include/vector.h"

int main() {
	// �������ݲ���
	printf("�������ݲ���\n");
	Vector3f vec3f(1, 2, 3);
	vec3f += 3;
	vec3f *= 2;
	printf("%f\n", vec3f.lenght());
	Vector3f nvec3f = vec3f.normalized();
	vec3f.print();
	nvec3f.print();

	// ��˲���
	printf("��˲���\n");
	Vector3f vec3f1(1, 2, 3);
	Vector3f vec3f2(3, 4, 5);
	printf("%f\n", vec3f1.dotProduct(vec3f2));

	// ��˲���
	printf("��˲���\n");
	(vec3f1.crossProduct(vec3f2)).print();

	

	while (true)
	{

	}
}