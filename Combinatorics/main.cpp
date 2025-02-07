#include <iostream>
#include "combinatorics.h"


int main() {
	std::vector<int> v{1, 2, 3};
    auto res = IMD::unique_subsets(v);
    for (const auto& x : res) {
        for (const auto& y : x) std::cout << y << " ";
        std::cout << std::endl;
    }
}