// MathEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <format>

#include "Quaternion.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix.h"

/*int main()
{
    // Matrix
    Matrix m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;

    m1 *= 2;

    m1.print();

    std::cout << "\n";

    // Quaternion
    Quaternion p(90, Vector3(0, 0, 1));
    Quaternion q(10, Vector3(0, 1, 0));

    Quaternion pq = p + q;

    std::cout << pq.scalar << " + " << pq.v.toString() << "\n";

    // Rotate vector
    Vector3 v(0, 1, 0);
    Vector3 axis(1, 0, 0);

    Vector3 RotatedVector = v.rotate(90, axis);

    std::cout << RotatedVector.toString();

    return 0;
}*/