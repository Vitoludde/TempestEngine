#ifndef VECTOR4_H
#define VECTOR4_H

#include <iostream>
#include <math.h>
#include <fmt/core.h>

#define PI           3.14159265358979323846f  /* pi */

using namespace std;

namespace TempestEngine {
    class Vector4 {
    public:
        // Variables
        float x;
        float y;
        float z;
        float w;

        // Constructor
        Vector4() : x(0), y(0), z(0), w(0) {};
        Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};

        // Template Vectors
        static Vector4 zero() {
            return Vector4(0, 0, 0, 0);
        }




        // Static functions
        static float angle(const Vector4& from, const Vector4& to) { // Get's angle with the formula a * b / |a||b|. (Dot product of vector v and w divided by normalized v times normalized w)
            float dotprod = dot(from, to);                              // Get dot product
            float magnitudes = magnitude(from) * magnitude(to);         // Get magnitudes
            return acos(dotprod / magnitudes) * 180.0f / PI;            // Return acos (radians) multiplied by 180 and then divided by PI (it's defined at the top)
        }

        static float dot(const Vector4& from, const Vector4& to) { // Returns a float, this is the dot product which is v.x * w.x + v.y * w.y + v.z * w.z
            return from.x * to.x + from.y * to.y + from.z * to.z;       // Return dot product
        }

        static float magnitude(const Vector4& Vector) { // Returns a flaot, this is the magnitude. The formula is: sqrt(each coordinate property^2)
            return sqrt(powf(Vector.x, 2) + powf(Vector.y, 2) + powf(Vector.z, 2) + powf(Vector.w, 2));          // Magnitude
        }

        static float magnitude(const Vector4& Vector, const Vector4& Vector2) { // Returns a flaot, this is the magnitude. The formula is: sqrt(each coordinate property^2)
            return sqrt(powf(Vector.x - Vector2.x, 2) + powf(Vector.y - Vector2.y, 2) + powf(Vector.z - Vector2.z, 2) + powf(Vector.w - Vector2.w, 2));          // Magnitude
        }

        static float distance(const Vector4& from, const Vector4& to) { // Returns a float, this is the distance between the vectors. The formula is |v - w|
            return magnitude(from, to);               // Distance, this is the vectors subtracted eachother and then the mangitude of this new vector
        }

        static Vector4 cross(const Vector4& from, const Vector4& to) {
            
        }

        std::string toString() {
            return fmt::format("({}, {}, {})", x, y, z);
        }





        // Functions linked to the object
        float magnitude() { // Returns a flaot, this is the magnitude. The formula is: sqrt(each coordinate property^2)
            return sqrt(powf(x, 2) + powf(y, 2) + powf(z, 2) + powf(w, 2));          // Magnitude
        }

        Vector4 normalized() { // Returnes a NEW normalized Vector4
            float normalized = sqrt(powf(x, 2) + powf(y, 2) + powf(z, 2) + powf(w, 2));
            return Vector4(x / normalized, y / normalized, z / normalized, w / normalized);
        }

        void normalize() { // Modifies our Vector4 to be normalized
            float normalized = sqrt(powf(x, 2) + powf(y, 2) + powf(z, 2) + powf(w, 2));
            x = x / normalized;
            y = y / normalized;
            z = z / normalized;
            w = w / normalized;
        }


        // Operations
        Vector4 operator+(const Vector4& other) { // Returns a NEW vector. Example usage would be Vector4 Added = Vector4(2, 5, 1) + Vector(1, 0, 5) = Vector4(3, 5, 6)
            return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
        }
        Vector4 operator-(const Vector4& other) { // Returns a NEW vector. Example usage would be Vector4 Subtracted = Vector4(2, 5, 1) - Vector(1, 0, 5) = Vector4(3, 5, 6)
            return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
        }
        Vector4 operator*(float scalar) { // Returns a NEW vector. Example usage would be Vector4 Scaled = Vector4(2, 5, 1) * 4 = Vector4(8, 20, 4)
            return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
        }
        Vector4 operator*(Vector4 v) { // Returns a NEW vector. Example usage would be Vector4 Scaled = Vector4(2, 5, 1) * 4 = Vector4(8, 20, 4)
            return Vector4(x * v.x, y * v.y, z * v.z, w * v.w);
        }
        void operator*=(float scalar) { // Modifies this vector to a certain scale. Example of this would be: Vector4 MovementVector *= 9.82f
            x *= scalar;
            y *= scalar;
            z *= scalar;
            w *= scalar;
        }
        void operator+=(const Vector4& other) { // Modifies this vector. Example of this would be: Vector4 PushVector (it's downwards) += Vector4 GravitationalVector
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;
        }
        void operator-=(const Vector4& other) { // Modifies this vector. Example of this would be: Vector4 PushVector (it's sideways along a surface that has friction) -= Vector4 FrictionVector
            x -= other.x;
            y -= other.y;
            z -= other.z;
            w -= other.w;
        }
        bool operator==(const Vector4& other) { // Checks if our vector is equal to another vector
            return x == other.x && y == other.y && z == other.z && w == other.w;

            // Compiler warning when running: return x, y, z == other.x, other.y, other.z;
        }
        bool operator!=(const Vector4& other) { // Checks if our vector is NOT equal to another vector
            return x != other.x && y != other.y && z != other.z && w != other.w;
        }
    };
}

#endif