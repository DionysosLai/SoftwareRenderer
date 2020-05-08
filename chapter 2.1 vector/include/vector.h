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
	T w;

	// 三种不同构造方式
	Vector3() :x(0), y(0), z(0), w(1) {};
	Vector3(T val) :x(val), y(val), z(val), w(1) {};
	Vector3(T xVal, T yVal, T zVal) :x(xVal), y(yVal), z(zVal), w(1) {};



	// 四则运算
	Vector3 operator-() const{
		return Vector3(-x, -y, -z);
	}
	Vector3 operator-(const T &rNum) {
		return Vector3(x - rNum, y - rNum, z - rNum);
	}
	Vector3 operator-(const Vector3 &rVec) {
		return Vector3(x - rVec.x, y - rVec.y, z - rVec.z);
	}
	Vector3 operator+(const T &rNum) {
		return Vector3(x + rNum, y + rNum, z + rNum);
	}
	Vector3 operator+(const Vector3 &rVec) {
		return Vector3(x + rVec.x, y + rVec.y, z + rVec.z);
	}
	Vector3 operator*(const T &rNum) {
		return Vector3(x * rNum, y * rNum, z * rNum);
	}
	void operator-=(const T &rNum) {
		(*this) = (*this) - rNum;
	}
	void operator-=(const Vector3 &rVec) {
		(*this) = (*this) - rVec;
	}
	void operator+=(const T &rNum) {
		(*this) = (*this) + rNum;
	}
	void operator+=(const Vector3 &rVec) {
		(*this) = (*this) + rVec;
	}
	void operator*=(const T &rNum) {
		(*this) = (*this) * rNum;
	}

	// 点乘与叉乘
	T dotProduct(const Vector3 &rVec) {
		return x * rVec.x + y*rVec.y + z * rVec.z;
	}
	Vector3 crossProduct(const Vector3 &r) const{
		return Vector3((y*r.z - z * r.y), (z*r.x - x * r.z), (x*r.y - y * r.x));
	}

	// 常用属性
	void zero() {
		x = 0;
		y = 0;
		z = 0;
	}
	T lenght() {
		return std::sqrt(x*x + y * y + z * z);
	}
	Vector3 &normalized() {
		T len = lenght();
		T factor = 1.0 / len;
		x *= factor;
		y *= factor;
		z *= factor;
		return *this;
	}   
	//齐次坐标化
	Vector3 &perspectiveDivide() {
		x /= w;
		y /= w;
		z /= w;
		return *this;
	}
	   	 
	// 额外功能
	void print() const {
		std::string str;
		if (std::is_same<T, float>::value) {
			str = "Vecf:(%f, %f, %f)\n";

		}
		else if (std::is_same<T, int>::value) {
			str = "Veci:(%d, %d, %d)\n";
		}
		printf(str.c_str(), x, y, z);
	}
};

typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;
#endif