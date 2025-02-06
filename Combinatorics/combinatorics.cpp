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
	int binomial_coefficient(size_t k, size_t n) {
		if (k > n) throw std::invalid_argument("k > n");
		return pascal_triangle(n+1)[n][k];
	}
	//Возвращает n-ое число Фибоначчи
	size_t fibonacci_number(size_t n) {
		size_t first = 0;
		size_t second = 1;
		while (n > 0) {
			size_t temp = first;
			first = second;
			second += temp;
			--n;
		}
		return first; //Использование рекурсии по принципу F(n) = F(n-1) + F(n-2) неэффективно из-за быстрого переполнения программного стека
	}
	//Возвращает n-ое число Люка
	size_t luke_number(size_t n) {
		size_t first = 2;
		size_t second = 1;
		while (n > 0) {
			size_t temp = first;
			first = second;
			second += temp;
			--n;
		}
		return first; //Использование рекурсии по принципу L(n) = L(n-1) + L(n-2) неэффективно из-за быстрого переполнения программного стека
	}
	//Возвращает n-ое число Каталана
	size_t catalan_number(size_t n) {
		size_t first = 1;
		for (size_t i{ 1 }; i <= n; ++i) {
			first *= 2 * (double)(2 * i - 1) / (i + 1);
		}
		return first;
	}
}