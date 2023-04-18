#ifndef MATRIX_TRANSFORM_H
#define MATRIX_TRANSFORM_H

#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"

namespace TempestEngine
{
    const static Matrix4 scale(const Matrix4 &m, const Vector3 &v)
    {
        // TODO: Optimize this
        Matrix4 Result;
        Result.data[0][0] = m.data[0][0] * v.x;
        Result.data[0][1] = m.data[0][1] * v.x;
        Result.data[0][2] = m.data[0][2] * v.x;
        Result.data[0][3] = m.data[0][3] * v.x;

        Result.data[1][0] = m.data[1][0] * v.y;
        Result.data[1][1] = m.data[1][1] * v.y;
        Result.data[1][2] = m.data[1][2] * v.y;
        Result.data[1][3] = m.data[1][3] * v.y;

        Result.data[2][0] = m.data[2][0] * v.z;
        Result.data[2][1] = m.data[2][1] * v.z;
        Result.data[2][2] = m.data[2][2] * v.z;
        Result.data[2][3] = m.data[2][3] * v.z;

        Result.data[3][0] = m.data[3][0];
        Result.data[3][1] = m.data[3][1];
        Result.data[3][2] = m.data[3][2];
        Result.data[3][3] = m.data[3][3];

        return Result;
    }

    const static Matrix4 rotate(Matrix4 const &m, float angle, Vector3 &v)
    {
        // TODO: Optimize this
        const float c = cos(angle);
        const float s = sin(angle);

        Vector3 axis = v.normalized();
        Vector3 temp = axis * (1 - c);

        Matrix4 rotate;
        rotate.data[0][0] = c + temp[0] * axis[0];
        rotate.data[0][1] = temp[0] * axis[1] + s * axis[2];
        rotate.data[0][2] = temp[0] * axis[2] - s * axis[1];

        rotate.data[1][0] = temp[1] * axis[0] - s * axis[2];
        rotate.data[1][1] = c + temp[1] * axis[1];
        rotate.data[1][2] = temp[1] * axis[2] + s * axis[0];

        rotate.data[2][0] = temp[2] * axis[0] + s * axis[1];
        rotate.data[2][1] = temp[2] * axis[1] - s * axis[0];
        rotate.data[2][2] = c + temp[2] * axis[2];

        Matrix4 Result;
        Result.data[0][0] = (m[0] * rotate.data[0][0] + m[1] * rotate.data[0][1] + m[2] * rotate.data[0][2]).x;
        Result.data[0][1] = (m[0] * rotate.data[0][0] + m[1] * rotate.data[0][1] + m[2] * rotate.data[0][2]).y;
        Result.data[0][2] = (m[0] * rotate.data[0][0] + m[1] * rotate.data[0][1] + m[2] * rotate.data[0][2]).z;
        Result.data[0][3] = (m[0] * rotate.data[0][0] + m[1] * rotate.data[0][1] + m[2] * rotate.data[0][2]).w;

        Result.data[1][0] = (m[0] * rotate.data[1][0] + m[1] * rotate.data[1][1] + m[2] * rotate.data[1][2]).x;
        Result.data[1][1] = (m[0] * rotate.data[1][0] + m[1] * rotate.data[1][1] + m[2] * rotate.data[1][2]).y;
        Result.data[1][2] = (m[0] * rotate.data[1][0] + m[1] * rotate.data[1][1] + m[2] * rotate.data[1][2]).z;
        Result.data[1][3] = (m[0] * rotate.data[1][0] + m[1] * rotate.data[1][1] + m[2] * rotate.data[1][2]).w;

        Result.data[2][0] = (m[0] * rotate.data[2][0] + m[1] * rotate.data[2][1] + m[2] * rotate.data[2][2]).x;
        Result.data[2][1] = (m[0] * rotate.data[2][0] + m[1] * rotate.data[2][1] + m[2] * rotate.data[2][2]).y;
        Result.data[2][2] = (m[0] * rotate.data[2][0] + m[1] * rotate.data[2][1] + m[2] * rotate.data[2][2]).z;
        Result.data[2][3] = (m[0] * rotate.data[2][0] + m[1] * rotate.data[2][1] + m[2] * rotate.data[2][2]).w;

        Result.data[3][0] = (m[3]).x;
        Result.data[3][1] = (m[3]).y;
        Result.data[3][2] = (m[3]).z;
        Result.data[3][3] = (m[3]).w;

        return Result;
    }

    const static Matrix4 rotate(Matrix4 const &m, float angle, Vector3 v)
    {
        // TODO: Optimize this
        const float c = cos(angle);
        const float s = sin(angle);

        Vector3 axis = v.normalized();
        Vector3 temp = axis * (1 - c);

        Matrix4 rotate;
        rotate.data[0][0] = c + temp[0] * axis[0];
        rotate.data[0][1] = temp[0] * axis[1] + s * axis[2];
        rotate.data[0][2] = temp[0] * axis[2] - s * axis[1];

        rotate.data[1][0] = temp[1] * axis[0] - s * axis[2];
        rotate.data[1][1] = c + temp[1] * axis[1];
        rotate.data[1][2] = temp[1] * axis[2] + s * axis[0];

        rotate.data[2][0] = temp[2] * axis[0] + s * axis[1];
        rotate.data[2][1] = temp[2] * axis[1] - s * axis[0];
        rotate.data[2][2] = c + temp[2] * axis[2];

        Matrix4 Result;
        Result.data[0][0] = (m[0] * rotate.data[0][0] + m[1] * rotate.data[0][1] + m[2] * rotate.data[0][2]).x;
        Result.data[0][1] = (m[0] * rotate.data[0][0] + m[1] * rotate.data[0][1] + m[2] * rotate.data[0][2]).y;
        Result.data[0][2] = (m[0] * rotate.data[0][0] + m[1] * rotate.data[0][1] + m[2] * rotate.data[0][2]).z;
        Result.data[0][3] = (m[0] * rotate.data[0][0] + m[1] * rotate.data[0][1] + m[2] * rotate.data[0][2]).w;

        Result.data[1][0] = (m[0] * rotate.data[1][0] + m[1] * rotate.data[1][1] + m[2] * rotate.data[1][2]).x;
        Result.data[1][1] = (m[0] * rotate.data[1][0] + m[1] * rotate.data[1][1] + m[2] * rotate.data[1][2]).y;
        Result.data[1][2] = (m[0] * rotate.data[1][0] + m[1] * rotate.data[1][1] + m[2] * rotate.data[1][2]).z;
        Result.data[1][3] = (m[0] * rotate.data[1][0] + m[1] * rotate.data[1][1] + m[2] * rotate.data[1][2]).w;

        Result.data[2][0] = (m[0] * rotate.data[2][0] + m[1] * rotate.data[2][1] + m[2] * rotate.data[2][2]).x;
        Result.data[2][1] = (m[0] * rotate.data[2][0] + m[1] * rotate.data[2][1] + m[2] * rotate.data[2][2]).y;
        Result.data[2][2] = (m[0] * rotate.data[2][0] + m[1] * rotate.data[2][1] + m[2] * rotate.data[2][2]).z;
        Result.data[2][3] = (m[0] * rotate.data[2][0] + m[1] * rotate.data[2][1] + m[2] * rotate.data[2][2]).w;

        Result.data[3][0] = (m[3]).x;
        Result.data[3][1] = (m[3]).y;
        Result.data[3][2] = (m[3]).z;
        Result.data[3][3] = (m[3]).w;

        return Result;
    }
}

#endif