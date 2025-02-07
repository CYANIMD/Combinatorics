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
	/*
	In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10.
	The player who first causes the running total to reach or exceed 100 wins.
	What if we change the game so that players cannot re-use integers?
	For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
	Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false.
	Assume both players play optimally.
	*/
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		std::map<int, bool> ways{}; //Словарь всех возможных ходов
		bool Flag{ true };
		return Flag;
	}
	/*
	You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
	Find two lines that together with the x-axis form a container, such that the container contains the most water.
	Return the maximum amount of water a container can store.
	Notice that you may not slant the container.
	*/
	int maxArea(const std::vector<int>& height) {
		int left{ 0 };
		int right(height.size() - 1);
		int S{ 0 }; //"Объём" хранимой воды: S(right, left) = (right - left) * min{height[right], height[left]}
		while (left < right) {
			S = std::max(S, (right - left) * std::min(height[right], height[left]));
			if (height[left] < height[right]) left++;
			else right--;
		}
		return S;
	}
}