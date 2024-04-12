#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;


int main(const int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	if (argc != 3) {
		cout << "Не указаны файл(-ы) с входными и(или) выходными данными." << endl;
		return 1;
	}

	int number = readNumberFromFile(argv[1]);
	ErrorCode code = isNumberCorrect(number);
	int error_number = static_cast<int>(code);

	if (error_number == 1) {
		cout << "Неверно указан файл с входными данными. Возможно, файл не существует." << endl;
		return 1;
	}
	if (error_number == 2) {
		cout << "Неверно записаны входные данные. В файле не должны быть не цифровые значения." << endl;
		return 1;
	}
	if (error_number == 3) {
		cout << "Неверно записаны входные данные. Файл должен содержать натуральное число от 1 до 100 включительно." << endl;
		return 1;
	}

	int ladders_number = calculateLaddersNumber(number + 1, number);
	code = writeResultToFile(ladders_number, argv[2]);
	error_number = static_cast<int>(code);

	if (error_number == 4) {
		cout << "Неверно указан файл для выходных данных. Возможно, указанного расположения не существует или нет прав на запись." << endl;
	}

	return 0;
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

	return atoi(temp);
}


ErrorCode writeResultToFile(int result, char* path) {
	ofstream file(path);

	if (file.is_open())
	{
		file << result;
		file.close();
	}
	else {
		return ErrorCode::IncorrectOutputFile;
	}
	return ErrorCode::NoError;
}
