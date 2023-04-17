#ifndef MATRIX4_H
#define MATRIX4_H

#include <stdexcept>

#include "Vector4.h"
#include "Vector3.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace TempestEngine
{
	class Matrix4
	{
	public:
		float data[4][4];

		Matrix4()
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					data[i][j] = 0;
				}
			}
		}

		Matrix4(Vector4 in)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					data[i][j] = 0;
				}
			}

			data[0][0] = in.x;
			data[1][1] = in.y;
			data[2][2] = in.z;
			data[3][3] = in.w;
		}

		Matrix4(float diagonal)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					data[i][j] = 0;
				}
			}

			data[0][0] = diagonal;
			data[1][1] = diagonal;
			data[2][2] = diagonal;
			data[3][3] = diagonal;
		}

		/*~Matrix4() {
			for (int i = 0; i < 4; i++) {
				delete[] data[i];
			}
			delete[] data;
		}*/

		static Vector4 translate(const Matrix4 &TranslationMatrix, const Vector4 &TranslationVector)
		{
			return TranslationMatrix * TranslationVector;
		}

		static Vector4 translate(const Matrix4 &TranslationMatrix, const Vector3 &TranslationVector)
		{
			return TranslationMatrix * TranslationVector;
		}

		static Matrix4 translateMatrix(Matrix4 m, Vector3 v)
		{
			Matrix4 Result = m;

			Result.data[3][0] += v.x;
			Result.data[3][1] += v.y;
			Result.data[3][2] += v.z;
			Result.data[3][3] = 1;

			return Result;
		}

		static Matrix4 translateMatrix(Matrix4 m, Vector4 v)
		{
			Matrix4 Result = m;

			Result.data[3][0] += v.x;
			Result.data[3][1] += v.y;
			Result.data[3][2] += v.z;
			Result.data[3][3] += v.w;

			return Result;
		}

		Matrix4 operator+(Matrix4 other)
		{
			// TODO: Implement
		}

		Matrix4 operator*(Matrix4 other) const
		{
			Matrix4 result;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					float sum = 0;
					for (int k = 0; k < 4; k++)
					{
						sum += data[i][k] * other.data[k][j];
					}
					result.data[i][j] = sum;
				}
			}
			return result;
		}

		Vector4 operator*(const Vector3 &vector) const
		{
			return Vector4(
				vector.x * data[0][0] + vector.y * data[1][0] + vector.z * data[2][0] + 1 * data[3][0],
				vector.x * data[0][1] + vector.y * data[1][1] + vector.z * data[2][1] + 1 * data[3][1],
				vector.x * data[0][2] + vector.y * data[1][2] + vector.z * data[2][2] + 1 * data[3][2],
				vector.x * data[0][3] + vector.y * data[1][3] + vector.z * data[2][3] + 1 * data[3][3]);
		}

		Vector4 operator*(const Vector4 &vector) const
		{
			return Vector4(
				vector.x * data[0][0] + vector.y * data[1][0] + vector.z * data[2][0] + vector.w * data[3][0],
				vector.x * data[0][1] + vector.y * data[1][1] + vector.z * data[2][1] + vector.w * data[3][1],
				vector.x * data[0][2] + vector.y * data[1][2] + vector.z * data[2][2] + vector.w * data[3][2],
				vector.x * data[0][3] + vector.y * data[1][3] + vector.z * data[2][3] + vector.w * data[3][3]);
		}

		void operator*=(int scalar)
		{
			for (int r = 0; r < 4; r++)
			{
				for (int c = 0; c < 4; c++)
				{
					data[r][c] *= scalar;
				}
			}
		}
	};
}

#endif