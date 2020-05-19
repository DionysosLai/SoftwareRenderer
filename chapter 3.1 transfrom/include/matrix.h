#ifndef _MATRIX_H
#define _MATRIX_H

#include <array>

#include "vector.h"

#define M_PI 3.1415826

// 构造一个复杂变换矩阵，由基础旋转、平移、缩放组成，顺序先scale->rorate->translate;
struct TransformParameters {
	TransformParameters() :scaling(Vector3f(1, 1, 1)) {};
	Vector3f translation;
	Vector3f rotation;
	Vector3f scaling;
};

class Matrix
{
public:
	Matrix();
	~Matrix();

	// get matrix element
	float& operator()(size_t y, size_t x) {
		return mMatrix[y * 4 + x];
	}
	// two matrix mul p_{ij}=\sum_{k=1}^ma_{ik}b_{kj}
	Matrix operator* (Matrix &rMat);

	// mat mul vector，这里需要注意vector是列向量，同时需要在右边
	Vector3f matMulVec(const Vector3f &vec);

	// 单位矩阵
	Matrix unitMatrix();

	// transpose and inverse
	Matrix transpose();
	Matrix inverse();

	// base transform
	Matrix rotMat(float alpha, float beta, float gamma);
	Matrix scaleMat(float scaleX, float scaleY, float scaleZ);
	Matrix translateMat(float dx, float dy, float dz);
	Matrix transformMat(TransformParameters trans);

	// perspective Projection
	//defined as X[-1,1] Y[-1,1] Z[1,0] 
	Matrix projectionMatrix(float fov, float AR, float near, float far);

	// debug
	void print();
	void testMatrix();

private:
	std::array<float, 16> mMatrix{};
};

#endif
