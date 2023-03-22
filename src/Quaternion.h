#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"

using namespace TempestEngine;

namespace TempestEngine {
	class Quaternion
	{
	public:
		float scalar;
		Vector3 v;

		// Default constructor
		Quaternion() {
			v = Vector3();
			scalar = 1;
		};

		// Constructor
		Quaternion(float oS, Vector3 ov) {
			v = ov;
			scalar = oS;
		};



		// Functions
		float norm() { // Returns the magnitude of the quaternion
			float s = scalar * scalar;
			float imaginary = Vector3::dot(v, v);

			return sqrtf(s + imaginary);
		}
		float magnitude() { // The same as norm
			return norm();
		}

		void normalize() {
			if (norm() != 0) {
				float normValue = 1 / norm();

				scalar *= normValue;
				v *= normValue;
			}
		}

		void UnitNormConversion() {
			float angle = scalar * (PI / 180);
			v.normalize();
			scalar = cosf(angle * 0.5f);
			v = v * sinf(angle * 0.5f);
		}

		Quaternion conjugate() {
			return Quaternion(scalar, v * (-1));
		}

		Quaternion inverse() {
			float absoluteVal = norm();
			absoluteVal *= absoluteVal;
			absoluteVal = 1 / absoluteVal;

			Quaternion conjugateVal = conjugate();

			float s = conjugateVal.scalar * absoluteVal;
			Vector3 imaginary = conjugateVal.v * absoluteVal;

			return Quaternion(s, imaginary);
		}



		// Operators which returns new values
		bool operator=(Quaternion val) {
			if (val.scalar == scalar && val.v == v) {
				return true;
			}
			return false;
		};

		Quaternion operator+(Quaternion other) {
			float AdditionScalar = scalar + other.scalar;
			Vector3 Imaginary = v + other.v;
			return Quaternion(AdditionScalar, Imaginary);
		};

		Quaternion operator-(Quaternion other) {
			float AdditionScalar = scalar - other.scalar;
			Vector3 Imaginary = v - other.v;
			return Quaternion(AdditionScalar, Imaginary);
		};

		Quaternion operator*(Quaternion other) { // Quaternion multiplication
			float s = scalar * other.scalar - Vector3::dot(v, other.v);
			Vector3 imaginary = other.v * scalar + v * other.scalar + Vector3::cross(v, other.v);
			return Quaternion(s, imaginary);
		};

		Quaternion operator*(float val) { // Scalar multiplication
			float s = scalar * val;
			Vector3 imaginary = v * val;
			return Quaternion(s, imaginary);
		};

		Quaternion operator()(float s, Vector3 vector) {
			scalar = s;
			v = vector;
			return Quaternion(s, v);
		};

		// Operators which modify values
		void operator+=(Quaternion other) {
			scalar += other.scalar;
			v += other.v;
		}

		void operator-=(Quaternion other) {
			scalar -= other.scalar;
			v -= other.v;
		}

		void operator*=(float val) { // Scalar multiplication
			scalar *= val;
			v *= val;
		};
	};
}

#endif