#ifndef __Combinatorics_
#define __Combinatorics_

#include <vector>
#include <ranges>

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
	template<typename T> requires requires(T a, T b) { { a < b }; }
	std::vector<T> next_permutation(const std::vector<T>& source) {
		//Алгоритм Нарайаны
		std::vector<T> result{ source };
		size_t j{};
		size_t l{};
		for (size_t i{ 0 }; i < result.size() - 1; ++i) {
			if (result[i] < result[i + 1]) j = i;
			if (result[i] > result[j]) l = i;
		}
		if (result[result.size() - 1] > result[j]) l = result.size() - 1;
		if (j == l) std::reverse(std::begin(result), std::end(result));
		else {
			std::swap(result[j], result[l]);
			std::reverse(std::begin(result) + j + 1, std::end(result));
		}
		return result;
	}
}



#endif __Combinatorics_