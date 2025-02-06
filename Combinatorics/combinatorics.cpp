#include <stdexcept>
#include <iostream>
#include "combinatorics.h"

namespace IMD {
	//Возвращает треугольник Паскаля
	std::vector<std::vector<int>> pascal_triangle(size_t row) {
		std::vector<std::vector<int>> result{ row };
		for (size_t i{ 0 }; i < row; ++i) {
			result[i].resize(i + 1);
			result[i][0] = 1;
			result[i][i] = 1;
			for (size_t j{ 1 }; j < i; ++j) result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
		return result;
	}
	//Возвращает значение биномиального коэффициента C(n, k)
	int binomial_coefficient(int k, int n) {
		return pascal_triangle(n+1)[n][k];
	}
}