#include "Quaternion.h"
#include "Vector3.h"

// Vector3 Functions
Vector3 Vector3::rotate(float uAngle, Vector3 uAxis) {
	Quaternion p(0, (*this));                           // Pure quaternion

	uAxis.normalize();                                  // Normalize rotation axis

	Quaternion q(uAngle, uAxis);                        // Real quaternion

	q.UnitNormConversion();                             // Quaternion to unit norm quaternion

	Quaternion qInverse = q.inverse();                  // Inverse

	Quaternion rotatedVector = q * p * qInverse;        // Rotate the quaternion

	return rotatedVector.v;                             // Get the vector from the rotated quaternion and return it
}