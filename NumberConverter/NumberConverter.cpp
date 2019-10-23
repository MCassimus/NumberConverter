// NumberConverter.cpp : Defines the entry point for the application.
//

#include "NumberConverter.h"

int main()
{
	bool goodMenuSelect = false;
	unsigned short selection = 0;
	unsigned short base;

	std::cout << "Choose an option to continue." << std::endl;
	std::cout << "1. Convert from decimal      " << std::endl;
	std::cout << "2. Convert to decimal        " << std::endl;
	std::cout << ":";
	std::cin >> selection;

	while (!(selection == 1 || selection == 2))
	{
		std::cout << "Bad Selection. Try again.    " << std::endl;
		std::cout << "Choose an option to continue." << std::endl;
		std::cout << "1. Convert from decimal      " << std::endl;
		std::cout << "2. Convert to decimal        " << std::endl;
		std::cout << ":";
		std::cin >> selection;
	} 

	std::cout << std::endl << "Number Base : ";
	std::cin >> base;

	if (selection == 1)
	{
		long long input;
		std::cout << "Base 10 Number : ";
		std::cin >> input;
		std::cout << std::endl << convertFromDec(input, base);
	}
	else if (selection == 2)
	{
		std::string input;
		std::cout << "Input : ";
		std::cin >> input;
		std::cout << std::endl << convertToDec(input, base);
	}

	return 0;
}


long long pow(int num, int power)
{
	long long result = num;
	for (; power > 1; power--)
		result *= num;
	return result;
}


long long convertToDec(std::string num, unsigned short base)
{
	long long result = 0;

	if (base < 37)
		for (int i = 0; i < num.length(); i++)
			num.at(i) = toupper(num.at(i));

	for (int i = num.length() - 1; i >= 0; i--)
		result += (valueTable62.find(num.at(i)) * pow(base, (num.length() - 1) - i));

	return result;
}



std::string convertFromDec(long long input, unsigned short base)
{
	std::string result = "";

	for (int i = 1; input > 0; i++)
	{
		result = valueTable62.at(input % base) + result;
		input /= base;
	}

	result = result.substr(result.find_first_not_of('0'));

	return result;
}