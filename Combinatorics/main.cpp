#include <iostream>
#include "combinatorics.h"

int main() {
	std::vector<int> v{ 1, 3, 5 };
	v = IMD::next_permutation(v);
	v = IMD::next_permutation(v);
	v = IMD::next_permutation(v);
	v = IMD::next_permutation(v);
	v = IMD::next_permutation(v);
	v = IMD::next_permutation(v);
	for (auto x : v)
		std::cout << x << " ";

}