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
#include <iomanip>

using namespace std;

double calcSpeed(int n, double* arr, double d)
{
	if (n == 0) return 0;
	double current = calcSpeed(n - 1, arr, d) + arr[n] * d;
	if (current > 0) return current;
	return 0;
}

double calcDistance(int n, double* arr, double d)
{
	double speed = calcSpeed(n-1, arr, d);
	if (speed < 0) speed = 0;
	double dist = speed*d + arr[n] * d*d / 2;
	if (dist > 0) return dist;
	return 0;
}

int main()
{
	int n;
	double d, sum = 0;
	double arr[100];

	cin >> n >> d;

	for (int i = 1; i <= n; i++)
	{
		double current;
		cin >> current;
		arr[i] = current;

		sum += calcDistance(i, arr, d);
	}

	cout << fixed << setprecision(5) << sum;

	return 0;
}