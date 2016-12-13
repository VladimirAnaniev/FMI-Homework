/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 9
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int removeNthElement(int num, int n)
{
	int result = 0;
	int count = 0;
	bool removed = false;

	while(num>0)
	{
		if (count != n)
		{
			int digit = num % 10;
			int multiply = 1;
			int innerCount = count;

			if (removed) innerCount--;

			for (int i = 0; i<innerCount; i++)
			{
				multiply *= 10;
			}

			result += multiply*digit;
			
		}
		else
		{
			removed = true;
		}
		

		num = num / 10;
		count++;
		
	}

	return result;
}

bool getResult(int first, int second)
{
	int n = 0;

	int firstNumber = first;

	if (first == 0 && second == 0) return true; //special case

	while(first>0)
	{
		int newNum = removeNthElement(firstNumber, n);

		if (newNum == second) return true;

		first = first / 10;
		n++;

	}

	return false;
}

int main()
{
	int first, second;

	cin >> first >> second;

	bool result = getResult(first, second);

	if (result) cout << "Yes";
	else cout << "No";

	return 0;
}