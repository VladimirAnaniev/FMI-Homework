/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 6
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int factorial(int n)
{
	int result = 1;

	for(int i=1;i<=n;i++)
	{
		result *= i;
	}

	return result;
}

int getBinomial (int n, int k)
{
	return factorial(n) / (factorial(k)*factorial(n - k));
}

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		cout << getBinomial(n, i) << " ";
	}

	system("pause");

	return 0;
}