/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 8
* @compiler VC
*
*/

#include <iostream>
using namespace std;

void calculate(int sum)
{
	if(sum>0)
	{
		cout << sum << " = ";

		int fifties = sum / 50;
		sum = sum % 50;
		int twenties = sum / 20;
		sum = sum % 20;
		int tens = sum / 10;
		sum = sum % 10;
		int fifths = sum / 5;
		sum = sum % 5;
		int twos = sum / 2;
		int ones = sum % 2;

		if (fifties) cout << fifties << "*50";
		if (twenties)
		{
			if (fifties) cout << " + ";
			cout << twenties << "*20";
		}
		if (tens)
		{
			if (fifties || twenties) cout << " + ";
			cout << tens << "*10";
		}
		if (fifths)
		{
			if (fifties || twenties || tens) cout << " + ";
			cout << fifths << "*5";
		}
		if (twos)
		{
			if (fifties || twenties || tens || fifths) cout << " + ";
			cout << twos << "*2";
		}
		if (ones)
		{
			if (fifties || twenties || tens || fifths || twos) cout << " + ";
			cout << ones << "*1";
		}
	}
}

int main()
{
	int sum;
	cin >> sum;
	calculate(sum);
}