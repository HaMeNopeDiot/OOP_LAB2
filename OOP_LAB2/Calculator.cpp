#include <iostream>
#include <string>
#include <fstream>
#include "Calculator.h"

int Calculator::compareNum()
{
	int caseCompare=-1;
	if (first > second)
		caseCompare = 2;
	else if (first == second)
		caseCompare = 1;
	else 
		caseCompare = 0;
	return caseCompare;
}

Fractional Calculator::plusNum()
{
	return Fractional(first + second);
}
Fractional Calculator::minusNum()
{
	return Fractional(first - second);
}
Fractional Calculator::multiplyNum()
{
	return Fractional(first * second);
}
Fractional Calculator::divideNum()
{
	return Fractional(first / second);
}

std::ostream& operator<< (std::ostream& out, Calculator& const object)
{
	out << "\n:Первое:";
	out << object.first;
	out << "\n:Второе:";
	out << object.second;
	return out;
}

std::istream& operator>>(std::istream& in, Calculator& const object)
{
	long firstL, secondL;
	unsigned short firstR, secondR;

	std::cout << "Начнём с первого:";
	object.first = inputNum();
	std::cout << "Закончим вторым:";
	object.second = inputNum();
	std::cout << '\n';

	return in;
}

Fractional inputNum()
{
	float realNum; //2.53 -> 2 53 //0.0001        *10000 ->round
	std::cin >> realNum;
	float accurNum = round(realNum * 10000) * 1.0 / 10000;
	Fractional* S = new Fractional;
	return S->getRealNumberReverse(realNum);
}