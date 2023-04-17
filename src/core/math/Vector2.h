#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
#include <math.h>
#include <fmt/core.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define PI           3.14159265358979323846f  /* pi */

using namespace std;

namespace TempestEngine {
    class Vector2 {
    public:
        // Variables
        float x;
        float y;

        // Constructor
        Vector2() : x(0), y(0) {};
        Vector2(float x, float y) : x(x), y(y) {};

        // Template Vectors, we only need 3 since you can just do -Vector2::right() for left
        static Vector2 up() {
            return Vector2(0, 1);
        }
        static Vector2 forward() {
            return Vector2(1, 0);
        }
        static Vector2 zero() {
            return Vector2(0, 0);
        }

        // Static functions
        static float angle(Vector2 from, Vector2 to) { // Get's angle with the formula a * b / |a||b|. (Dot product of vector v and w divided by normalized v times normalized w)
            float dotprod = dot(from, to);                              // Get dot product
            float magnitudes = from.magnitude() * to.magnitude();       // Get magnitudes
            return acos(dotprod / magnitudes) * 180.0f / PI;            // Return acos (radians) multiplied by 180 and then divided by PI (it's defined at the top)
        }

        static float dot(Vector2 from, Vector2 to) { // Returns a float, this is the dot product which is v.x * w.x + v.y * w.y + v.z * w.z
            return from.x * to.x + from.y * to.y;       // Return dot product
        }

        static float magnitude(Vector2 Vector) { // Returns a flaot, this is the magnitude. The formula is: sqrt(each coordinate property^2)
            return sqrt(powf(Vector.x, 2) + powf(Vector.y, 2));          // Magnitude
        }

        static float distance(Vector2 from, Vector2 to) { // Returns a float, this is the distance between the vectors. The formula is |v - w|
            return (from - to).magnitude();               // Distance, this is the vectors subtracted eachother and then the mangitude of this new vector
        }

        std::string toString() {
            return fmt::format("({}, {})", x, y);
        }

        // Functions linked to the object
        float magnitude() { // Returns a flaot, this is the magnitude. The formula is: sqrt(each coordinate property^2)
            return sqrt(powf(x, 2) + powf(y, 2));          // Magnitude
        }

        Vector2 normalized() { // Returnes a NEW normalized Vector2
            float normalized = sqrt(powf(x, 2) + powf(y, 2));
            return Vector2(x / normalized, y / normalized);
        }

        void normalize() { // Modifies our Vector2 to be normalized
            float normalized = sqrt(powf(x, 2) + powf(y, 2));
            x = x / normalized;
            y = y / normalized;
        }

        // Operations
        Vector2 operator+(Vector2 other) { // Returns a NEW vector. Example usage would be Vector2 Added = Vector2(2, 5, 1) + Vector(1, 0, 5) = Vector2(3, 5, 6)
            return Vector2(x + other.x, y + other.y);
        }
        Vector2 operator-(Vector2 other) { // Returns a NEW vector. Example usage would be Vector2 Subtracted = Vector2(2, 5, 1) - Vector(1, 0, 5) = Vector2(3, 5, 6)
            return Vector2(x - other.x, y - other.y);
        }
        Vector2 operator*(float scalar) { // Returns a NEW vector. Example usage would be Vector2 Scaled = Vector2(2, 5, 1) * 4 = Vector2(8, 20, 4)
            return Vector2(x * scalar, y * scalar);
        }
        void operator*=(float scalar) { // Modifies this vector to a certain scale. Example of this would be: Vector2 MovementVector *= 9.82f
            x = x * scalar;
            y = y * scalar;
        }
        void operator+=(Vector2 other) { // Modifies this vector. Example of this would be: Vector2 PushVector (it's downwards) += Vector2 GravitationalVector
            x, y += other.x, other.y;
        }
        void operator-=(Vector2 other) { // Modifies this vector. Example of this would be: Vector2 PushVector (it's sideways along a surface that has friction) -= Vector2 FrictionVector
            x, y -= other.x, other.y;
        }
        bool operator==(Vector2 other) { // Checks if our vector is equal to another vector
            if (x == other.x && y == other.y) {
                return true;
            }
            else {
                return false;
            }

            // Compiler warning when running: return x, y, z == other.x, other.y, other.z;
        }
        bool operator!=(Vector2 other) { // Checks if our vector is NOT equal to another vector
            if (x == other.x && y == other.y) {
                return false;
            }
            else {
                return true;
            }
        }
        Vector2 operator()(float x, float y) {
            return Vector2(x, y);
        }


        // Casts
        operator glm::vec2() const {
			return glm::vec2(x, y);
		}
    };
}

#endif