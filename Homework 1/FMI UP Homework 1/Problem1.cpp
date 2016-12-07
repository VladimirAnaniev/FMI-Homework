/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 1
* @compiler VC
*
*/

#include <iostream>
using namespace std;

void inRoman(int num)
{
	if (num>3000 || num<=0)
	{
		cout << "Invalid number!";
	}
	else
	{
		// --M--
		if (num == 3000) cout << "MMM";
		else if (num >= 2000) cout << "MM";
		else if (num > 1000) cout << "M";
		num = num % 1000;

		// --CM--
		if (num >= 900) cout << "CM";
		num = num % 900;

		// --D--
		if (num >= 500) cout << "D";
		num = num % 500;

		// --CD--
		if (num >= 400) cout << "CD";
		num = num % 400;

		// --C--
		if (num >= 300) cout << "CCC";
		else if (num >= 200) cout << "CC";
		else if (num >= 100) cout << "C";
		num = num % 100;

		// --XC--
		if (num >= 90) cout << "XC";
		num = num % 90;

		// --L--
		if (num >= 50) cout << "L";
		num = num % 50;

		// --XL--
		if (num >= 40) cout << "XL";
		num = num % 40;

		// --X--
		if (num >= 30) cout << "XXX";
		else if (num >= 20) cout << "XX";
		else if (num >= 10) cout << "X";
		num = num % 10;

		// --IX--
		if (num == 9) cout << "IX";
		num = num % 9;

		// --V--
		if (num > 5) cout << "V";
		num = num % 5;

		// --IV--
		if (num == 4) cout << "IV";
		num = num % 4;

		// --I--
		if (num == 3) cout << "III";
		else if (num == 2) cout << "II";
		else if (num == 1) cout << "I";
	}
}

int main()
{
	int num;
	cin >> num;

	inRoman(num);
}