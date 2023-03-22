#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <math.h>
//#include <format>

#define PI           3.14159265358979323846f  /* pi */

using namespace std;

namespace TempestEngine
{
	class Vector3
	{
	public:
		// Variables
		float x;
		float y;
		float z;

		// Constructor
		Vector3() : x(0), y(0), z(0) {};
		Vector3(float x, float y, float z) : x(x), y(y), z(z) {};

		// Template Vectors, we only need 3 since you can just do -Vector3::right() for left
		static Vector3 up()
		{
			return Vector3(0, 1, 0);
		}
		static Vector3 forward()
		{
			return Vector3(0, 0, 1);
		}
		static Vector3 right()
		{
			return Vector3(1, 0, 0);
		}
		static Vector3 zero()
		{
			return Vector3(0, 0, 0);
		}





		// Static functions
		static float angle(const Vector3& from, const Vector3& to)
		{ // Get's angle with the formula a * b / |a||b|. (Dot product of vector v and w divided by normalized v times normalized w)
			float dotprod = dot(from, to);                              // Get dot product
			float magnitudes = magnitude(from) * magnitude(to);       // Get magnitudes
			return acos(dotprod / magnitudes) * 180.0f / PI;            // Return acos (radians) multiplied by 180 and then divided by PI (it's defined at the top)
		}

		static float dot(const Vector3& from, const Vector3& to)
		{ // Returns a float, this is the dot product which is v.x * w.x + v.y * w.y + v.z * w.z
			return from.x * to.x + from.y * to.y + from.z * to.z;       // Return dot product
		}

		static float magnitude(const Vector3& Vector)
		{ // Returns a flaot, this is the magnitude. The formula is: sqrt(each coordinate property^2)
			return sqrt(powf(Vector.x, 2) + powf(Vector.y, 2) + powf(Vector.z, 2));          // Magnitude
		}

		static float magnitude(const Vector3& Vector, const Vector3& Vector2)
		{ // Returns a flaot, this is the magnitude. The formula is: sqrt(each coordinate property^2)
			return sqrt(powf(Vector.x - Vector2.x, 2) + powf(Vector.y - Vector2.y, 2) + powf(Vector.z - Vector2.z, 2));          // Magnitude
		}

		static float distance(const Vector3& from, const Vector3& to)
		{ // Returns a float, this is the distance between the vectors. The formula is |v - w|
			return magnitude(from, to);               // Distance, this is the vectors subtracted eachother and then the mangitude of this new vector
		}

		static Vector3 cross(const Vector3& from, const Vector3& to)
		{
			return Vector3(from.y * to.z - from.z * to.y,
				from.z * to.x - from.x * to.z,
				from.x * to.y - from.y * to.x);
		}

		/*std::string toString()
		{
			return std::format("({}, {}, {})", x, y, z);
		}*/





		// Functions linked to the object
		float magnitude()
		{ // Returns a flaot, this is the magnitude. The formula is: sqrt(each coordinate property^2)
			return sqrt(powf(x, 2) + powf(y, 2) + powf(z, 2));          // Magnitude
		}

		Vector3 normalized()
		{ // Returnes a NEW normalized Vector3
			float normalized = sqrt(powf(x, 2) + powf(y, 2) + powf(z, 2));
			return Vector3(x / normalized, y / normalized, z / normalized);
		}

		void normalize()
		{ // Modifies our Vector3 to be normalized
			float normalized = sqrt(powf(x, 2) + powf(y, 2) + powf(z, 2));
			x = x / normalized;
			y = y / normalized;
			z = z / normalized;
		}

		Vector3 rotate(float uAngle, Vector3 uAxis);


		// Operations
		Vector3 operator+(const Vector3& other)
		{ // Returns a NEW vector. Example usage would be Vector3 Added = Vector3(2, 5, 1) + Vector(1, 0, 5) = Vector3(3, 5, 6)
			return Vector3(x + other.x, y + other.y, z + other.z);
		}
		Vector3 operator-(const Vector3& other)
		{ // Returns a NEW vector. Example usage would be Vector3 Subtracted = Vector3(2, 5, 1) - Vector(1, 0, 5) = Vector3(3, 5, 6)
			return Vector3(x - other.x, y - other.y, z - other.z);
		}
		Vector3 operator*(float scalar)
		{ // Returns a NEW vector. Example usage would be Vector3 Scaled = Vector3(2, 5, 1) * 4 = Vector3(8, 20, 4)
			return Vector3(x * scalar, y * scalar, z * scalar);
		}
		Vector3 operator*(const Vector3& v)
		{ // Returns a NEW vector. Example usage would be Vector4 Scaled = Vector4(2, 5, 1) * 4 = Vector4(8, 20, 4)
			return Vector3(x * v.x, y * v.y, z * v.z);
		}
		void operator*=(float scalar)
		{ // Modifies this vector to a certain scale. Example of this would be: Vector3 MovementVector *= 9.82f
			x = x * scalar;
			y = y * scalar;
			z = z * scalar;
		}
		void operator+=(const Vector3& other)
		{ // Modifies this vector. Example of this would be: Vector3 PushVector (it's downwards) += Vector3 GravitationalVector
			x, y, z += other.x, other.y, other.z;
		}
		void operator-=(const Vector3& other)
		{ // Modifies this vector. Example of this would be: Vector3 PushVector (it's sideways along a surface that has friction) -= Vector3 FrictionVector
			x, y, z -= other.x, other.y, other.z;
		}
		bool operator==(const Vector3& other)
		{ // Checks if our vector is equal to another vector
			return x == other.x && y == other.y && z == other.z;
		}
		bool operator!=(const Vector3& other)
		{ // Checks if our vector is NOT equal to another vector
			return x != other.x && y != other.y && z != other.z;
		}
	};
}

#endif