#ifndef __Combinatorics_
#define __Combinatorics_

#include <vector>

namespace IMD {
	//Возвращает факториал числа
	inline constexpr int factorial(const int value) {
		if (value < 0) throw std::invalid_argument("value < 0");
		if (value == 0 || value == 1) return 1;
		return value * factorial(value - 1);
	}
	//Возвращает треугольник Паскаля
	std::vector<std::vector<int>> pascal_triangle(size_t row);
	//Возвращает значение биномиального коэффициента C(n, k)
	int binomial_coefficient(int k, int n);
}



#endif __Combinatorics_