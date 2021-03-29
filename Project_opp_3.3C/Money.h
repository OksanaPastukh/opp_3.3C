#pragma once
#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

class Money : public Object
{
	long hryvnia;
	unsigned char kopiyku;
	double MoneyToDoble() const;
	void DoubleToMoney(double);

public:
	Money();
	Money(long, unsigned char);
	Money(const Money&);


	bool SetHryvnia(long);
	bool SetKopiyku(unsigned char);
	long GetHryvnia() const { return hryvnia; }
	unsigned char GetKopiyku() const { return kopiyku; }

	friend istream& operator >> (istream&, Money&);
	Money& operator = (const Money&);
	operator string() const;
	friend ostream& operator << (ostream&, const Money&);
	friend Money operator - (const Money&, const Money&);
	friend Money operator * (const Money&, const Money&);
	friend bool operator <(const Money&, const Money&);
	friend bool operator >(const Money&, const Money&);
	friend bool operator == (const Money&, const Money&);

	Money& operator ++();
	Money& operator --();
	Money operator ++(int);
	Money operator --(int);
};

