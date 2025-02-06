#include <iostream>
#include "combinatorics.h"

int main() {
	for (size_t i{ 0 }; i < 10; ++i)
		std::cout << IMD::catalan_number(i) << std::endl;

}