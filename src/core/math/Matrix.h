#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>

namespace TempestEngine {
	class Matrix
	{
	private:
		int rows;
		int cols;
		int** data;

	public:
		Matrix(int r, int c) {
			rows = r;
			cols = c;
			data = new int* [rows];
			for (int i = 0; i < rows; i++) {
				data[i] = new int[cols];
			}
		}

		Matrix() : rows(0), cols(0) {
			data = new int* [rows];
			for (int i = 0; i < rows; i++) {
				data[i] = new int[cols];
			}
		};

		~Matrix() {
			for (int i = 0; i < rows; i++) {
				delete[] data[i];
			}
			delete[] data;
		}

		int& operator()(int i, int j) {
			if (i < 0 || i >= rows || j < 0 || j >= cols) {
				throw std::out_of_range("Indice out of matrix range!");
			}

			return data[i][j];
		}

		Matrix operator+(Matrix other) {
			if (rows != other.rows || cols != other.cols) {
				throw std::invalid_argument("Matrixes does not have the same dimensions!");
			}

			Matrix result(rows, cols);

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					result(i, j) = data[i][j] + other(i, j);
				}
			}
			return result;
		}

		Matrix operator*(Matrix other) {
			// TODO: Implement
		}

		void operator*=(int scalar) {
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++) {
					data[r][c] *= scalar;
				}
			}
		}

		void print() {
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++) {
					std::cout << data[r][c] << " ";
				}

				std::cout << "\n";
			}
		}
	};
}

#endif