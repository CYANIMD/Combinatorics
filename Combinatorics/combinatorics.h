#ifndef __Combinatorics_
#define __Combinatorics_

#include <vector>

namespace IMD {
	//Возвращает факториал числа
	inline constexpr size_t factorial(const size_t value) {
		if (value == 0 || value == 1) return 1;
		return value * factorial(value - 1);
	}
	//Возвращает треугольник Паскаля
	std::vector<std::vector<int>> pascal_triangle(size_t row);
	//Возвращает значение биномиального коэффициента C(n, k)
	int binomial_coefficient(size_t k, size_t n);
	//Возвращает n-ое число Фибоначчи
	size_t fibonacci_number(size_t n);
	//Возвращает n-ое число Люка
	size_t luke_number(size_t n);
	//Возвращает n-ое число Каталана
	size_t catalan_number(size_t n);

}



#endif __Combinatorics_