#include <iostream>
#include<cmath>
#include "OOP_L2.h"


Fractional::Fractional(const long int _wholePart, const unsigned short int _fractPart)
{
	wholePart = new long int(_wholePart);
	fractPart = new unsigned short int(_fractPart);
	/*std::cout << "---Конструктор---" << '\n';
	std::cout << *wholePart << '\n';
	std::cout << *fractPart << '\n';
	std::cout << "----------------" << '\n';*/
}

Fractional::Fractional(const Fractional& objCopy)
{
	wholePart = new long int(*objCopy.wholePart);
	fractPart = new unsigned short int(*objCopy.fractPart);
	/*std::cout << "---Копировалщик---" << '\n';
	std::cout << *wholePart << '\n';
	std::cout << *fractPart << '\n';
	std::cout << "----------------" << '\n';*/
}

const int Fractional::getWhole()
{
	return *wholePart;
}
const int Fractional::getFract()
{
	return *fractPart;
}

void Fractional::setWhole(const long int number)
{
	*wholePart = number;
}
void Fractional::setFract(const unsigned short int number)
{
	*fractPart = number;
}

Fractional::~Fractional()
{
	/*std::cout << "---Деструктор---" << '\n';
	std::cout << *wholePart << '\n';
	std::cout << *fractPart << '\n';
	std::cout << "----------------" << '\n';*/
	delete wholePart;
	delete fractPart;
}



float Fractional::getRealNumber(Fractional newObject)
{
	float realPart = *newObject.fractPart*1.0 / 10000; //65535
	if (*newObject.wholePart < 0)
		realPart *= -1;
	float realNum = realPart + *newObject.wholePart;
	return realNum;
}

Fractional Fractional::getRealNumberReverse(float realnum)
{
	Fractional G;
	*G.wholePart = int(realnum / 1);
	float num = realnum - *G.wholePart;
	num = round(num * 10000);
	if (num < 0)
		num *= -1;
	*G.fractPart = num;
	return G;
}

Fractional& Fractional::operator=(const Fractional& newObject)
{
	if (this != &newObject)
	{
		*wholePart = (*newObject.wholePart);
		*fractPart = (*newObject.fractPart);
	}

	return *this;
}
Fractional Fractional::operator+(const Fractional& newObject)
{
	float realnum1 = getRealNumber(*this);
	float realnum2 = getRealNumber(newObject);
	float realnum = realnum1 + realnum2;
	Fractional Prob = getRealNumberReverse(realnum);
	return Fractional(*Prob.wholePart,*Prob.fractPart);
}
Fractional Fractional::operator- (const Fractional& newObject)
{
	float realnum1 = getRealNumber(*this);
	float realnum2 = getRealNumber(newObject);
	float realnum = realnum1 - realnum2;
	Fractional Prob = getRealNumberReverse(realnum);
	return Fractional(*Prob.wholePart, *Prob.fractPart);
}
Fractional Fractional::operator* (const Fractional& newObject)
{
	float realnum1 = getRealNumber(*this);
	float realnum2 = getRealNumber(newObject);
	float realnum = realnum1 * realnum2;
	Fractional Prob = getRealNumberReverse(realnum);
	return Fractional(*Prob.wholePart, *Prob.fractPart);
}
Fractional Fractional::operator/ (const Fractional& newObject)
{
	if (*newObject.wholePart != 0 && *newObject.fractPart != 0)
	{
		float realnum1 = getRealNumber(*this);
		float realnum2 = getRealNumber(newObject);
		float realnum = realnum1*1.0 / realnum2;
		Fractional Prob = getRealNumberReverse(realnum);
		return Fractional(*Prob.wholePart, *Prob.fractPart);
	}
	else
	{
		return Fractional(0, 0);
	}
}

Fractional Fractional::operator+= (const Fractional& newObject)
{
	float realnum1 = getRealNumber(*this);
	float realnum2 = getRealNumber(newObject);
	float realnum = realnum1 + realnum2;
	Fractional Prob = getRealNumberReverse(realnum);
	*wholePart = *Prob.wholePart;
	*fractPart = *Prob.fractPart;
	return *this;
}
Fractional Fractional::operator-= (const Fractional& newObject)
{
	float realnum1 = getRealNumber(*this);
	float realnum2 = getRealNumber(newObject);
	float realnum = realnum1 - realnum2;
	Fractional Prob = getRealNumberReverse(realnum);
	*wholePart = *Prob.wholePart;
	*fractPart = *Prob.fractPart;
	return *this;
}
Fractional Fractional::operator*= (const Fractional& newObject)
{
	float realnum1 = getRealNumber(*this);
	float realnum2 = getRealNumber(newObject);
	float realnum = realnum1 * realnum2;
	Fractional Prob = getRealNumberReverse(realnum);
	*wholePart = *Prob.wholePart;
	*fractPart = *Prob.fractPart;
	return *this;
}
Fractional Fractional::operator/= (const Fractional& newObject)
{
	float realnum1 = getRealNumber(*this);
	float realnum2 = getRealNumber(newObject);
	if (realnum2 != 0)
	{
		float realnum = realnum1*1.0 / realnum2;
		Fractional Prob = getRealNumberReverse(realnum);
		*wholePart = *Prob.wholePart;
		*fractPart = *Prob.fractPart;
	}
	else
	{
		*wholePart = 0;
		*fractPart = 0;
	}
	return *this;
}

bool Fractional::operator== (Fractional& OtherObject)
{
	return getRealNumber(*this) == getRealNumber(OtherObject);
}
bool Fractional::operator!= (Fractional& OtherObject)
{
	return getRealNumber(*this) != getRealNumber(OtherObject);
}
bool Fractional::operator>= (Fractional& OtherObject)
{
	return getRealNumber(*this) >= getRealNumber(OtherObject);
}
bool Fractional::operator<= (Fractional& OtherObject)
{
	return getRealNumber(*this) <= getRealNumber(OtherObject);
}
bool Fractional::operator< (Fractional& OtherObject)
{
	return getRealNumber(*this) < getRealNumber(OtherObject);
}
bool Fractional::operator> (Fractional& OtherObject)
{
	return getRealNumber(*this) > getRealNumber(OtherObject);
}

void Fractional::output()
{
	std::cout << *wholePart << "|" << *fractPart<<'\n';
}




std::ostream& operator<<(std::ostream& out, const Fractional& obj)
{
	Fractional S(*obj.wholePart, *obj.fractPart);
	std::cout << "\nRealNum:" << S.getRealNumber(S) << "\n";
	out << "Whole:" << *obj.wholePart << "\nFract:" << *obj.fractPart;

	return out;
}
std::istream& operator>> (std::istream& in, const Fractional& obj)
{
	std::cout << "Whole:";
	in >> *obj.wholePart;
	std::cout << "\nFract:";
	in >> *obj.fractPart;
	std::cout << '\n';
	return in;
}


//65535