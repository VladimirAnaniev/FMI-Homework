/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 4
* @compiler VC
*
*/

#include <iostream>

using namespace std;

bool aIsInB(int a, int b)
{
	int first = a;
	

	while (first>0)
	{
		int digit = first % 10;
		bool helper = false;

		int second = b;
		while (second>0)
		{
			int digit2 = second % 10;
			if (digit == digit2) helper = true;
			second = second / 10;
		}

		if (!helper) return false;
		first = first / 10;
	}

	return true;
}

int main()
{
	int a, b;
	cin >> a >> b;

	a = abs(a);
	b = abs(b);

	if (aIsInB(a, b) && aIsInB(b, a)) cout << "Yes";
	else cout << "No";

	system("pause");

	return 0;
}