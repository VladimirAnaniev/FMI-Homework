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

int getBase10(int num, int base)
{
	int count = 0;
	int result = 0;

	while(num>0)
	{
		int baseMultiplier = 1;
		int digit = num % 10;

		if (digit >= base) return -1; //bad input data

		for(int i=0;i<count;i++)
		{
			baseMultiplier *= base;
		}

		result += baseMultiplier*digit;

		num = num / 10;
		count++;
	}

	return result;
}

int toBaseN(int num, int base)
{
	int result = 0;
	int count = 0;

	while(num>0)
	{
		int baseMultiplier = 1;
		int current = num%base;

		for(int i=0;i<count;i++)
		{
			baseMultiplier *= 10;
		}

		result += current*baseMultiplier;

		num = num / base;
		count++;
	}

	return result;
}

int main()
{
	int first, second, base;

	cin >> first >> second >> base;

	if(base<2 || base>10)
	{
		cout << "Bad input data!";
	}
	else
	{
		int firstNum = getBase10(first, base);
		int secondNum = getBase10(second, base);

		if (firstNum > 0 && secondNum > 0)
		{
			cout << toBaseN(firstNum + secondNum, base);
		}
		else
		{
			cout << "Bad input data!";
		}
	}

	system("pause");

	return 0;
}