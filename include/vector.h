#ifndef _VECTOR_H
#define _VECTOR_H

#include<string>

template<typename T>

struct Vector3 {
	union
	{
		T data[3];
		struct {
			T x;
			T y;
			T z;
		};
	};

	// 三种不同构造方式
	Vector3() :x(0), y(0), z(0), w(1) {};
	Vector3(T val) :x(val), y(val), z(val), w(1) {};
	Vector3(T xVal, T yVal, T zVal) :x(xVal), y(yVal), z(zVal) {};

	// 0向量
	void zero() {
		x = 0;
		y = 0;
		z = 0;
	}

	// 四则运算
	Vector3 operator-() const{
		return Vector3(-x, -y, -z);
	}
	Vector3 operator-(const T &rNum) {
		return Vector3(x - rNUm, y - rNum, z - rNum);
	}
	Vector3 operator-(const Vector3 &rVec) {
		return Vector3(x - rVec.x, y - rVec.y, z - rVec.z);
	}
	Vector3 operator+(const T &rNum) {
		return Vector3(x + rNUm, y + rNum, z + rNum);
	}
	Vector3 operator+(const Vector3 &rVec) {
		return Vector3(x + rVec.x, y + rVec.y, z + rVec.z);
	}
	Vector3 operator*(const T &rNum) {
		return Vector3(x * rNUm, y * rNum, z * rNum);
	}
	void operator-=(const T& &rNum) {
		(*this) = (*this) - rNum;
	}
	void operator-=(const Vector3 &rVec) {
		(*this) = (*this) - rVec;
	}
	void operator+=(const T& &rNum) {
		(*this) = (*this) + rNum;
	}
	void operator+=(const Vector3 &rVec) {
		(*this) = (*this) + rVec;
	}

	// 点乘与叉乘



};

#endif