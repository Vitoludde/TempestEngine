#ifndef MATRIX_TRANSFORM_H
#define MATRIX_TRANSFORM_H

#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"

namespace TempestEngine
{
    static Matrix4 scale(Matrix4 m, Vector3 v)
    {
        Matrix4 res;
        res.data[0][0] = v.x;
        res.data[1][1] = v.y;
        res.data[2][2] = v.z;
        return m * res;
    }
}

#endif