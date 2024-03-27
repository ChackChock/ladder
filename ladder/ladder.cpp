#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;


int main(const int argc, char** argv)
{

}


int calculateLaddersNumber(int prev_level, int number) {
	if (number == 0) return 1;

	int count = 0;
	for (int level = 1; level < prev_level; ++level) {
		if (level > number) break;
		count += calculateLaddersNumber(level, number - level);
	}

	return count;
}
