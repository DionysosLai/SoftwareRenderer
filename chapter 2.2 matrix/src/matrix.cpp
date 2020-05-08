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
	Matrix transposeMatrix;
	//First row
	transposeMatrix(0, 0) = (*this)(0, 0);
	transposeMatrix(0, 1) = (*this)(1, 0);
	transposeMatrix(0, 2) = (*this)(2, 0);
	transposeMatrix(0, 3) = (*this)(3, 0);

	//Second row
	transposeMatrix(1, 0) = (*this)(0, 1);
	transposeMatrix(1, 1) = (*this)(1, 1);
	transposeMatrix(1, 2) = (*this)(2, 1);
	transposeMatrix(1, 3) = (*this)(3, 1);

	//Third row
	transposeMatrix(2, 0) = (*this)(0, 2);
	transposeMatrix(2, 1) = (*this)(1, 2);
	transposeMatrix(2, 2) = (*this)(2, 2);
	transposeMatrix(2, 3) = (*this)(3, 2);

	//Fourth row
	transposeMatrix(3, 0) = (*this)(0, 3);
	transposeMatrix(3, 1) = (*this)(1, 3);
	transposeMatrix(3, 2) = (*this)(2, 3);
	transposeMatrix(3, 3) = (*this)(3, 3);
	return transposeMatrix;
}

Matrix Matrix::inverse() {
	Matrix inverseMat;

	float det;
	int i, j;

	inverseMat(0, 0) = mMatrix[5] * mMatrix[10] * mMatrix[15] -
		mMatrix[5] * mMatrix[11] * mMatrix[14] -
		mMatrix[9] * mMatrix[6] * mMatrix[15] +
		mMatrix[9] * mMatrix[7] * mMatrix[14] +
		mMatrix[13] * mMatrix[6] * mMatrix[11] -
		mMatrix[13] * mMatrix[7] * mMatrix[10];

	inverseMat(1, 0) = -mMatrix[4] * mMatrix[10] * mMatrix[15] +
		mMatrix[4] * mMatrix[11] * mMatrix[14] +
		mMatrix[8] * mMatrix[6] * mMatrix[15] -
		mMatrix[8] * mMatrix[7] * mMatrix[14] -
		mMatrix[12] * mMatrix[6] * mMatrix[11] +
		mMatrix[12] * mMatrix[7] * mMatrix[10];

	inverseMat(2, 0) = mMatrix[4] * mMatrix[9] * mMatrix[15] -
		mMatrix[4] * mMatrix[11] * mMatrix[13] -
		mMatrix[8] * mMatrix[5] * mMatrix[15] +
		mMatrix[8] * mMatrix[7] * mMatrix[13] +
		mMatrix[12] * mMatrix[5] * mMatrix[11] -
		mMatrix[12] * mMatrix[7] * mMatrix[9];

	inverseMat(3, 0) = -mMatrix[4] * mMatrix[9] * mMatrix[14] +
		mMatrix[4] * mMatrix[10] * mMatrix[13] +
		mMatrix[8] * mMatrix[5] * mMatrix[14] -
		mMatrix[8] * mMatrix[6] * mMatrix[13] -
		mMatrix[12] * mMatrix[5] * mMatrix[10] +
		mMatrix[12] * mMatrix[6] * mMatrix[9];

	inverseMat(0, 1) = -mMatrix[1] * mMatrix[10] * mMatrix[15] +
		mMatrix[1] * mMatrix[11] * mMatrix[14] +
		mMatrix[9] * mMatrix[2] * mMatrix[15] -
		mMatrix[9] * mMatrix[3] * mMatrix[14] -
		mMatrix[13] * mMatrix[2] * mMatrix[11] +
		mMatrix[13] * mMatrix[3] * mMatrix[10];

	inverseMat(1, 1) = mMatrix[0] * mMatrix[10] * mMatrix[15] -
		mMatrix[0] * mMatrix[11] * mMatrix[14] -
		mMatrix[8] * mMatrix[2] * mMatrix[15] +
		mMatrix[8] * mMatrix[3] * mMatrix[14] +
		mMatrix[12] * mMatrix[2] * mMatrix[11] -
		mMatrix[12] * mMatrix[3] * mMatrix[10];

	inverseMat(2, 1) = -mMatrix[0] * mMatrix[9] * mMatrix[15] +
		mMatrix[0] * mMatrix[11] * mMatrix[13] +
		mMatrix[8] * mMatrix[1] * mMatrix[15] -
		mMatrix[8] * mMatrix[3] * mMatrix[13] -
		mMatrix[12] * mMatrix[1] * mMatrix[11] +
		mMatrix[12] * mMatrix[3] * mMatrix[9];

	inverseMat(3, 1) = mMatrix[0] * mMatrix[9] * mMatrix[14] -
		mMatrix[0] * mMatrix[10] * mMatrix[13] -
		mMatrix[8] * mMatrix[1] * mMatrix[14] +
		mMatrix[8] * mMatrix[2] * mMatrix[13] +
		mMatrix[12] * mMatrix[1] * mMatrix[10] -
		mMatrix[12] * mMatrix[2] * mMatrix[9];

	inverseMat(0, 2) = mMatrix[1] * mMatrix[6] * mMatrix[15] -
		mMatrix[1] * mMatrix[7] * mMatrix[14] -
		mMatrix[5] * mMatrix[2] * mMatrix[15] +
		mMatrix[5] * mMatrix[3] * mMatrix[14] +
		mMatrix[13] * mMatrix[2] * mMatrix[7] -
		mMatrix[13] * mMatrix[3] * mMatrix[6];

	inverseMat(1, 2) = -mMatrix[0] * mMatrix[6] * mMatrix[15] +
		mMatrix[0] * mMatrix[7] * mMatrix[14] +
		mMatrix[4] * mMatrix[2] * mMatrix[15] -
		mMatrix[4] * mMatrix[3] * mMatrix[14] -
		mMatrix[12] * mMatrix[2] * mMatrix[7] +
		mMatrix[12] * mMatrix[3] * mMatrix[6];

	inverseMat(2, 2) = mMatrix[0] * mMatrix[5] * mMatrix[15] -
		mMatrix[0] * mMatrix[7] * mMatrix[13] -
		mMatrix[4] * mMatrix[1] * mMatrix[15] +
		mMatrix[4] * mMatrix[3] * mMatrix[13] +
		mMatrix[12] * mMatrix[1] * mMatrix[7] -
		mMatrix[12] * mMatrix[3] * mMatrix[5];

	inverseMat(3, 2) = -mMatrix[0] * mMatrix[5] * mMatrix[14] +
		mMatrix[0] * mMatrix[6] * mMatrix[13] +
		mMatrix[4] * mMatrix[1] * mMatrix[14] -
		mMatrix[4] * mMatrix[2] * mMatrix[13] -
		mMatrix[12] * mMatrix[1] * mMatrix[6] +
		mMatrix[12] * mMatrix[2] * mMatrix[5];

	inverseMat(0, 3) = -mMatrix[1] * mMatrix[6] * mMatrix[11] +
		mMatrix[1] * mMatrix[7] * mMatrix[10] +
		mMatrix[5] * mMatrix[2] * mMatrix[11] -
		mMatrix[5] * mMatrix[3] * mMatrix[10] -
		mMatrix[9] * mMatrix[2] * mMatrix[7] +
		mMatrix[9] * mMatrix[3] * mMatrix[6];

	inverseMat(1, 3) = mMatrix[0] * mMatrix[6] * mMatrix[11] -
		mMatrix[0] * mMatrix[7] * mMatrix[10] -
		mMatrix[4] * mMatrix[2] * mMatrix[11] +
		mMatrix[4] * mMatrix[3] * mMatrix[10] +
		mMatrix[8] * mMatrix[2] * mMatrix[7] -
		mMatrix[8] * mMatrix[3] * mMatrix[6];

	inverseMat(2, 3) = -mMatrix[0] * mMatrix[5] * mMatrix[11] +
		mMatrix[0] * mMatrix[7] * mMatrix[9] +
		mMatrix[4] * mMatrix[1] * mMatrix[11] -
		mMatrix[4] * mMatrix[3] * mMatrix[9] -
		mMatrix[8] * mMatrix[1] * mMatrix[7] +
		mMatrix[8] * mMatrix[3] * mMatrix[5];

	inverseMat(3, 3) = mMatrix[0] * mMatrix[5] * mMatrix[10] -
		mMatrix[0] * mMatrix[6] * mMatrix[9] -
		mMatrix[4] * mMatrix[1] * mMatrix[10] +
		mMatrix[4] * mMatrix[2] * mMatrix[9] +
		mMatrix[8] * mMatrix[1] * mMatrix[6] -
		mMatrix[8] * mMatrix[2] * mMatrix[5];

	det = mMatrix[0] * inverseMat(0, 0) + mMatrix[1] * inverseMat(1, 0) + mMatrix[2] * inverseMat(2, 0) + mMatrix[3] * inverseMat(3, 0);

	if (det != 0) {
		det = 1.0 / det;

		for (i = 0; i < 4; ++i) {
			for (j = 0; j < 4; ++j) {
				inverseMat(i, j) = inverseMat(i, j) * det;
			}
		}
		return inverseMat;
	}
	return inverseMat;

}

void Matrix::print() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%f\t", (*this)(i, j));
		}
		printf("\n");
	}
	printf("\n");
}

void Matrix::testMatrix() {
	Matrix testMat;
	int n = 4;
	int val = 1;
	for (int rows = 0; rows < n; ++rows) {
		for (int cols = 0; cols < n; ++cols) {
			testMat(rows, cols) = val;
			++val;
		}
	}

	testMat.print();
	testMat.transpose().print();
	testMat.inverse().print();
}