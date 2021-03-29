#include "Money.h"
#include <iostream>
using namespace std;

int main()
{
	Money m(10, 25);
	cout << "money1 = " << m << endl;
	cout << "count = " << Money::Count() << endl;
	Money m2;
	m2 = ++m;
	cout << "money2 = ++money: \n" << "money = " << m << "money2 = " << m2 << endl;
	m2 = --m;
	cout << "money2 = --money: \n" << "money = " << m << "money2 = " << m2 << endl;
	m2 = m++;
	cout << "money2 = money++: \n" << "money = " << m << "money2 = " << m2 << endl;
	m2 = m--;
	cout << "money2 = money--: \n" << "money = " << m << "money2 = " << m2 << endl;
	Money x;
	cout << "Input  value ->" << endl;
	cin >> x;
	cout << x << endl;
	Money b;
	cout << "Input  value ->" << endl;
	cin >> b;
	cout << b << endl;
	Money c = x - b;
	cout << c << endl;
	Money w = x * b;
	cout << w << endl;
	Money k;
	cout << "Enter compare summa "; cin >> k;
	bool f = x < k;
	if (x < k)
	{
		cout << "Yes, current value < comparative summa " << endl;
	}
	else
	{
		cout << "No, current value < comparative summa " << endl;
	}
	if (x > k)
	{
		cout << "Yes, current value > comparative summa " << endl;
	}
	else
	{
		cout << "No, current value < comparative summa " << endl;
	}
	if (x == k)
	{
		cout << "Yes, current value = comparative summa " << endl;
	}
	else
	{
		cout << "No, they are not equal " << endl;
   	}
	cout << "count = " << Object::Count() << endl;
	cin.get();
	return 0;
}