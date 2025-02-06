#include <iostream>
#include "combinatorics.h"


int main() {
	std::vector<int> v{1, 2, 3, 3};
    auto res = IMD::unique_subsets(v);
    for (auto x : res) {
        for (auto y : x) std::cout << y << " ";
        std::cout << std::endl;
    }
}