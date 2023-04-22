#ifndef MATRIX_CLIP_SPACE_H
#define MATRIX_CLIP_SPACE_H

#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"

namespace TempestEngine
{
    Matrix4 ortho(float left, float right, float bottom, float top, float zNear, float zFar)
    {
        Matrix4 Result(1);
        Result.data[0][0] = 2 / (right - left);
        Result.data[1][1] = 2 / (top - bottom);
        Result.data[2][2] = -2 / (zFar - zNear);
        Result.data[3][0] = -(right + left) / (right - left);
        Result.data[3][1] = -(top + bottom) / (top - bottom);
        Result.data[3][2] = -(zFar + zNear) / (zFar - zNear);
        return Result;
    }

    Matrix4 perspective(float fovy, float aspect, float zNear, float zFar)
    {
        float const tanHalfFovy = tan(fovy / 2);

        Matrix4 Result(0.0f);
        Result.data[0][0] = 1 / (aspect * tanHalfFovy);
        Result.data[1][1] = 1 / (tanHalfFovy);
        Result.data[2][2] = -(zFar + zNear) / (zFar - zNear);
        Result.data[2][3] = -1;
        Result.data[3][2] = -(2 * zFar * zNear) / (zFar - zNear);
        return Result;
    }
}

#endif