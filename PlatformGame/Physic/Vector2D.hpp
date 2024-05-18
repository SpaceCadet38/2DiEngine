#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <string>
#include <iostream>


class Vector2D
{
public:
	float X, Y;

	inline Vector2D operator+(const Vector2D& v2)const {
		return Vector2D(X + v2.X, Y + v2.Y);
	}
	inline Vector2D operator-(const Vector2D& v2)const {
		return Vector2D(X - v2.X, Y - v2.Y);
	}
	inline Vector2D operator*(const float scalar)const {
		return Vector2D(X * scalar, Y * scalar);
	}
	//inline Vector2D& operator+=(const Vector2D& v2) {
	//	X += v2.X;
	//	Y += v2.X;
	//	return *this;
	//}
	void Log(std::string msg = "") {
		std::cout << msg << "(X, Y) = " << "(" << X << " " << Y << ")" << std::endl;
	}
	Vector2D(float x = 0, float y = 0) :X(x), Y(y) {}
};


#endif // !VECTOR2D_H
