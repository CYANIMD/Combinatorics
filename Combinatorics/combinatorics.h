#ifndef __Combinatorics_
#define __Combinatorics_

#include <vector>
#include <ranges>
#include <algorithm>
#include <map>

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
	//Возвращает следующую лексикографическую подстановку
	template<typename T> requires requires(T a, T b) { { a < b }; { a > b }; }
	std::vector<T> next_permutation(const std::vector<T>& source) {
		//Алгоритм Нарайаны.
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
	//Возвращает все подмножества исходного множества
	template<typename T>
	std::vector<std::vector<T>> subsets(const std::vector<T>& source) {
		std::vector<std::vector<T>> result{ std::vector<T> {} };
		for (size_t i{ 0 }; i < source.size(); ++i) {
			size_t l = result.size();
			for (size_t j{ 0 }; j < l; ++j) {
				auto current_subset = result[j];
				current_subset.push_back(source[i]);
				result.push_back(current_subset);
			}
		}
		return result;
	}
	/*
	In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10.
	The player who first causes the running total to reach or exceed 100 wins.
	What if we change the game so that players cannot re-use integers?
	For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
	Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false.
	Assume both players play optimally.
	*/
	bool canIWin(int maxChoosableInteger, int desiredTotal);
	/*
	You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
	Find two lines that together with the x-axis form a container, such that the container contains the most water.
	Return the maximum amount of water a container can store.
	Notice that you may not slant the container.
	*/
	int maxArea(const std::vector<int>& height);
}



#endif __Combinatorics_