#include "../include/matrix.h"

Matrix::Matrix(){
}

Matrix::~Matrix() {

}

Matrix Matrix::operator*(Matrix &rMat) {
	Matrix results;
	int n = 4;
	// p_{ij}=\sum_{k=1}^ma_{ik}b_{kj}
	for (int rows = 0; rows < n; ++rows) {
		for (int cols = 0; cols < n; ++cols) {
			float total = 0;
			for (int sub = 1; sub < n + 1; ++sub) {
				int rowLhs = rows; //row ind left matrix
				int colLhs = sub - 1; //col ind left matrix
				int rowRhs = sub - 1; //row ind right matrix
				int colRhs = cols; //col ind right matrix

				total += (*this)(rowLhs, colLhs) * rMat(rowRhs, colRhs);
			}
			results(rows, cols) = total;
		}
	}
	return results;
}

// mat mul vector，这里需要注意vector是列向量，同时需要在右边
Vector3f Matrix::matMulVec(const Vector3f &vec) {
	Vector3f newVec(0, 0, 0);
	float w2 = 0;
	newVec.x = vec.x*(*this)(0, 0) +
		vec.y*(*this)(0, 1) +
		vec.z*(*this)(0, 2) +
		vec.w*(*this)(0, 3);

	newVec.y = vec.x*(*this)(1, 0) +
		vec.y*(*this)(1, 1) +
		vec.z*(*this)(1, 2) +
		vec.w*(*this)(1, 3);

	newVec.z = vec.x*(*this)(2, 0) +
		vec.y*(*this)(2, 1) +
		vec.z*(*this)(2, 2) +
		vec.w*(*this)(2, 3);

	newVec.w = vec.x*(*this)(3, 0) +
		vec.y*(*this)(3, 1) +
		vec.z*(*this)(3, 2) +
		vec.w*(*this)(3, 3);
	return newVec;
}

Matrix Matrix::transpose() {

}

Matrix Matrix::inverse() {

}