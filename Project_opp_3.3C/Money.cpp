#include "Money.h"
#include <sstream>

Money::Money()
{
	hryvnia = 0;
	kopiyku = 0;
}
Money::Money(long h, unsigned char k)
{
	SetHryvnia(h);
	SetKopiyku(k);
}
Money::Money(const Money& m)
{
	hryvnia = m.hryvnia;
	kopiyku = m.kopiyku;
}
bool Money::SetHryvnia(long value)
{
	if (value >= 0)
	{
		hryvnia = value;
		return true;
	}
	else
	{
		return false;
	}
}
bool Money::SetKopiyku(unsigned char value)
{
	if (value >= 0 && value < 100)
	{
		kopiyku = value;
		return true;
	}
	else
	{
		return false;
	}
}
double Money::MoneyToDoble() const
{
	return (double)hryvnia + kopiyku / 100.0;
}
void Money::DoubleToMoney(double value)
{
	hryvnia = trunc(value);
	kopiyku = trunc(abs((value - hryvnia)) * 100);
}


Money& Money::operator = (const Money& m)
{
	hryvnia = m.hryvnia;
	kopiyku = m.kopiyku;
	return *this;
}

istream& operator >> (istream& in, Money& m)
{
	double value;
	long hr;
	unsigned char kop;
	cout << " Summa = "; in >> value;
	do
	{
		hr = floor(value);
		kop = round((value - hr) * 100);
	} while (!(m.SetHryvnia(hr) && m.SetKopiyku(kop)));
	return in;
}
Money::operator string () const
{
	stringstream ss;
	ss << " Summa = " << hryvnia << "," << (int)kopiyku << " hrn " << endl;
	return ss.str();
}
ostream& operator << (ostream& out, const Money& p)
{
	out << string(p);
	return out;
}
Money operator - (const Money& x, const Money& y)
{
	Money result;
	result.DoubleToMoney(x.MoneyToDoble() - y.MoneyToDoble());
	return result;
}
Money operator * (const Money& x, const Money& y)
{
	Money result;
	result.DoubleToMoney(x.MoneyToDoble() * y.MoneyToDoble());
	return result;
}
bool operator < (const Money& x, const Money& y)
{
	return x.MoneyToDoble() < y.MoneyToDoble();
}
bool operator > (const Money& x, const Money& y)
{
	return x.MoneyToDoble() > y.MoneyToDoble();
}
bool operator == (const Money& x, const Money& y)
{
	return x.MoneyToDoble() == y.MoneyToDoble();
}

Money& Money::operator ++()
{
	if (kopiyku == 99)
		kopiyku = 1;
	else
		++kopiyku;
	return *this;
}
Money& Money::operator --()
{
	if (kopiyku == 0)
		kopiyku = 99;
	else
		--kopiyku;
	return *this;
}
Money Money::operator ++(int)
{
	Money t(*this);
	hryvnia++;
	return t;
}
Money Money::operator --(int)
{
	Money t(*this);
	hryvnia--;
	return t;
}