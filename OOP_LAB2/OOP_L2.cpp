#include <iostream>
#include "OOP_L2.h"

#include <iomanip>

Fractional::Fractional(const long int _wholePart, const short int _fractPart)
{
	wholePart = new long int(_wholePart);
	fractPart = new short int(_fractPart);
	std::cout << "---Конструктор---" << '\n';
	std::cout << *wholePart << '\n';
	std::cout << *fractPart << '\n';
	std::cout << "----------------" << '\n';
	minusSwap();
}

Fractional::Fractional(const Fractional& objCopy)
{
	wholePart = new long int(*objCopy.wholePart);
	fractPart = new short int(*objCopy.fractPart);
	std::cout << "---Копировалщик---" << '\n';
	std::cout << *wholePart << '\n';
	std::cout << *fractPart << '\n';
	std::cout << "----------------" << '\n';
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
void Fractional::setFract(const short int number)
{
	*fractPart = number;
}

Fractional::~Fractional()
{
	std::cout << "---Деструктор---" << '\n';
	std::cout << *wholePart << '\n';
	std::cout << *fractPart << '\n';
	std::cout << "----------------" << '\n';
	delete wholePart;
	delete fractPart;
}


void Fractional::minusSwap()
{
	if (fractPart < 0)
	{
		(*wholePart) *= -1;
		(*fractPart) *= -1;
	}
}

float Fractional::getRealNumber(Fractional newObject)
{
	float realNum = *newObject.wholePart;
	float t = 1;
	int ten = *newObject.fractPart;
	while (ten > 10)
	{
		ten /= 10;
		t /= 10;
	}
	realNum += t * ten;
	return realNum;
}

Fractional Fractional::getRealNumberReverse(float realnum)
{
	Fractional G;
	*G.wholePart = int(realnum / 1);

	std::cout << ":::" << *G.wholePart << "|" << G.wholePart << '\n';

	float realPart = realnum - *G.wholePart;
	float ten = 1;

	std::cout << "||" << realPart << " r " << ten << '\n';
	float e = 0.00001;
	std::cout << "%%$$%$%$%$%$^ " << e <<'\n';
	while(int(realPart)/realPart*1.0<e)          
	{
		realPart *= 10;
		/*if (realPart < 1)
			ten *= 10;*/
	}

	std::cout << "||" << realPart <<" r " << ten<<  '\n';

	*G.fractPart = realPart * ten;

	std::cout << ":::" << *G.fractPart << "|" << G.fractPart << '\n';

	return G;
}

Fractional Fractional::operator+ (const Fractional& newObject)
{
	return Fractional((*wholePart) + (*newObject.wholePart), (*fractPart)+(*newObject.fractPart));
}
Fractional Fractional::operator- (const Fractional& newObject)
{
	return Fractional((*wholePart) - (*newObject.wholePart), (*fractPart) - (*newObject.fractPart));
}
Fractional Fractional::operator* (const Fractional& newObject)
{
	return Fractional(*getRealNumberReverse(getRealNumber(newObject)*getRealNumber(*this)).wholePart, *getRealNumberReverse(getRealNumber(newObject) * getRealNumber(*this)).fractPart);
}
Fractional Fractional::operator/ (const Fractional& newObject)
{
	if (*wholePart != 0 && *fractPart != 0)
	{
		return Fractional(*getRealNumberReverse(getRealNumber(newObject) / getRealNumber(*this)).wholePart, *getRealNumberReverse(getRealNumber(newObject) / getRealNumber(*this)).fractPart);
	}
	else
	{
		return Fractional(0, 0);
	}
}

Fractional Fractional::operator+= (const Fractional& newObject)
{
	*wholePart += *newObject.wholePart;
	*fractPart += *newObject.fractPart;
	minusSwap();
	return *this;
}
Fractional Fractional::operator-= (const Fractional& newObject)
{
	*wholePart -= *newObject.wholePart;
	*fractPart -= *newObject.fractPart;
	minusSwap();
	return *this;
}
Fractional Fractional::operator*= (const Fractional& newObject)
{
	*wholePart *= *newObject.wholePart;
	*fractPart *= *newObject.fractPart;
	minusSwap();
	return *this;
}
Fractional Fractional::operator/= (const Fractional& newObject)
{
	if (*newObject.wholePart != 0)
	{
		*wholePart /= *newObject.wholePart;
	}
	else
		*wholePart = 0;

	if (*newObject.fractPart != 0)
	{
		*fractPart /= *newObject.fractPart;
	}
	else
		*fractPart = 0;

	minusSwap();
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


//
//
//std::ostream& operator<<(std::ostream& out, const Fractional& obj)
//{
//	out << "Whole:" << *obj.wholePart << "\nFract:" << *obj.fractPart;
//
//	return out;
//}
//std::istream& operator>> (std::istream& in, const Fractional& obj)
//{
//	std::cout << "\nWhole:";
//	in >> *obj.wholePart;
//
//	std::cout << "\nFract:";
//	in >> *obj.fractPart;
//	std::cout << '\n';
//	return in;
//}