/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 2
* @compiler VC
*
*/

#include <iostream>

using namespace std;

bool isPrime(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0) return false;
	}

	return true;
}

bool isSpecial(int num)
{
	return isPrime(num) && isPrime(num + 2);
}

int findSpecialPrime(int startNum)
{
	int num = startNum;
	
	while(!isSpecial(num))
	{
		num++;
	}

	return num;
}

int main()
{
	int pairs;

	cin >> pairs;

	int first = 2;
	for(int i = 0; i < pairs; i++)
	{
		first = findSpecialPrime(first + 1);

		cout << first << ' ' << first + 2 << endl;
	}

	system("pause");

	return 0;
}