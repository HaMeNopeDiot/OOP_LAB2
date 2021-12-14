#pragma once
#include <iostream>
#include <string>
#include "OOP_L2.h"

class Calculator
{
protected:
	Fractional first;
	Fractional second;
public:
	Calculator(long firstL = 0, unsigned short firstR = 0, long secondL  = 0, unsigned short secondR = 0) :first(firstL, firstR), second(secondL, secondR) {};

	int compareNum();

	Fractional plusNum();
	Fractional minusNum();
	Fractional multiplyNum();
	Fractional divideNum();

	friend std::ostream& operator<< (std::ostream& out, Calculator& const object);
	friend std::istream& operator>> (std::istream& in, Calculator& const object);

};


Fractional inputNum();