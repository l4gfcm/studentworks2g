// daily1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<int> retListByReg(int number){
	std::vector<int> list;
	std::string sNumbers = std::to_string(number);
	for (int n = 0; n < sNumbers.size(); n++)
		list.push_back((int) sNumbers[n] -48);
	return list;
};


int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	vector<int> digits;
	int number;

	cout << "Enter number: ";
	cin >> number;
	digits = retListByReg(number);
	
	for (int i = 0; i < digits.size(); i++)
		cout << i + 1 << "th digit of number is " << digits[i] << endl;
	system("pause");
	return 0;
}

