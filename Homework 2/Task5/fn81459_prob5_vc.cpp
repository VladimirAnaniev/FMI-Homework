/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 5
* @compiler VC
*
*/

#include <iostream>

using namespace std;

double calcSpeed(int n, double a, double d)
{
	if (n == 0) return 0;
	return calcSpeed(n - 1, a, d) + a*d;
}

double calcDistance(int n, double a, double d)
{
	return calcSpeed(n - 1, a, d)*d + a*d*d / 2;
}

int main()
{
	int n;
	double d, sum = 0;

	cin >> n >> d;

	for (int i = 1; i <= n; i++)
	{
		double current;
		cin >> current;

		sum += calcDistance(i, current, d);
	}

	cout << sum;

	return 0;
}