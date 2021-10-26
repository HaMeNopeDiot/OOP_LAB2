#pragma once
#ifndef OOP_L2
#define OOP_L2

class Fractional
{
	long int* wholePart;
	unsigned short int* fractPart;
public:
	Fractional(const long int _wholePart = 0, const unsigned short int _fractPart = 0);
	Fractional(const Fractional& objCopy);
	~Fractional();
	//void minusSwap();

	const int getWhole();
	const int getFract();

	void setWhole(const long int number);
	void setFract(const unsigned short int number);

	friend std::ostream& operator<<(std::ostream& out, const Fractional& obj);
	friend std::istream& operator>>(std::istream& in, const Fractional& obj);

	float getRealNumber(Fractional newObject);
	Fractional getRealNumberReverse(float realnum);

	Fractional& operator= (const Fractional& newObject);
	Fractional operator+ (const Fractional& newObject);
	Fractional operator- (const Fractional& newObject);
	Fractional operator* (const Fractional& newObject);
	Fractional operator/ (const Fractional& newObject);

	Fractional operator+= (const Fractional& newObject);
	Fractional operator-= (const Fractional& newObject);
	Fractional operator*= (const Fractional& newObject);
	Fractional operator/= (const Fractional& newObject);

	bool operator== (Fractional& OtherObject);
	bool operator!= (Fractional& OtherObject);
	bool operator>= (Fractional& OtherObject);
	bool operator<= (Fractional& OtherObject);
	bool operator< (Fractional& OtherObject);
	bool operator> (Fractional& OtherObject);

	void output();

};


#endif