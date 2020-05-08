#ifndef _MATRIX_H
#define _MATRIX_H

#include <array>

#include "vector.h"

class Matrix
{
public:
	Matrix();
	~Matrix();

	// operator override
	// get matrix element
	float& operator()(size_t y, size_t x) {
		return mMatrix[y * 4 + x];
	}
	// two matrix mul p_{ij}=\sum_{k=1}^ma_{ik}b_{kj}
	Matrix operator* (Matrix &rMat);

	// mat mul vector，这里需要注意vector是列向量，同时需要在右边
	Vector3f matMulVec(const Vector3f &vec);

	// transpose and inverse
	Matrix transpose();
	Matrix inverse();
	

	// debug
	void print();
	void testMatrix();

private:
	std::array<float, 16> mMatrix{};
};

#endif
