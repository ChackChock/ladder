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


int charToInt(char* string)
{
	int i, n = 0;
	for (i = 0; i < strlen(string); ++i) {
		if (isdigit(string[i])) {
			n = 10 * n + (string[i] - '0');
		}
		else {
			return -1;
		}
	}
	return n;
}


ErrorCode isNumberCorrect(int number) {
	if (number == -1) {
		return ErrorCode::IncorrectInputData;
	}
	if (number == -2) {
		return ErrorCode::IncorrectInputFile;
	}
	if (number < 1 || number > 100) {
		return ErrorCode::IncorrectNumber;
	}
	return ErrorCode::NoError;
}


int readNumberFromFile(char* path) {
	char temp[5];
	ifstream file(path);

	if (file.is_open())
	{
		file.getline(temp, 5);
		file.close();
	}
	else {
		return -2;
	}

	return charToInt(temp);
}
