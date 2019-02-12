#pragma once
#include <math.h>
struct gdVec2 {
	double x;
	double y;
	double a;

	gdVec2() {//default constructor

	}

	gdVec2(double x, double y) {
		Set(x, y);
		
	}

	void SetZero() //function that sets things to 0
	{
		x = 0;
		y = 0;
	}

	void Set(double new_x, double new_y) {//sets doubles.
		x = new_x;
		y = new_y;
		a = 0;
	}
	gdVec2 operator /(double a) {
		gdVec2 result;
		result.x = x / a;
		result.y = y / a;
		return result;
	}

	gdVec2 operator /(gdVec2 a) {
		gdVec2 result;
		result.x = x / a.x;
		result.y = y / a.y;
		return result;
	}
	void operator +=(const gdVec2 &v) {//adds a vector using the pass by const reference.
		x += v.x;
		y += v.y;
	}
	gdVec2 operator +(const gdVec2 &v) {//adds a vector using the pass by const reference.
		gdVec2 result;
		result.x = x + v.x;
		result.y = y + v.y;
		//x += v.x;
		//y += v.y;
		return result;
	}

	gdVec2 operator -(const gdVec2 &v) {//adds a vector using the pass by const reference.
		gdVec2 result;
		result.x = x - v.x;
		result.y = y - v.y;

		return result;
	}

	void operator -=(const gdVec2 & v) {//substract a vector to this vector
		x -= v.x;
		y -= v.y;
	}
	gdVec2 operator *(double a) {//multiply a number by a
		gdVec2 result;
		result.x = x*a;
		result.y = y*a;
	
		return result;
	}

	gdVec2 operator  +(float a) {//multiply a number by a
		gdVec2 result;
		result.x = x+a;
		result.y = y+a;

		return result;
	}

	gdVec2 operator  *(float a) {//multiply a number by a
		gdVec2 result;
		result.x = x * a;
		result.y = y * a;

		return result;
	}

	gdVec2 operator *(gdVec2 a) {//multiply a number by a
		gdVec2 result;
		result.x = x*a.x;
		result.y = y*a.y;

		return result;
	}

	void operator *=(double a) {//multiply a number by a
		x *= a;
		y *= a;
	}

	gdVec2 operator -() const {//negates the vector
		double x2;
		double y2;

		x2 = x*-1;
		y2 = y*-1;

	}
	void operator /=(double a) {//divide a number by a
		x /= a;
		y /= a;
	}
	double Length() const {//returns the length of the vector
		double magnitude;

		magnitude = ((x*x) + (y*y));

		return magnitude;
	}
	void normalize() {//normalizes the vector so that the magnitude is equal to 1


		x = x / Length();
		y = y / Length();
	}

	double Dot(const gdVec2 & V) const {//Does the dot product without using magnitude.

		double dot = x + V.x + y + V.y;

		return dot;
	}
};