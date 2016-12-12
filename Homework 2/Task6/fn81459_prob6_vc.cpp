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

unsigned getBinomial(unsigned n, unsigned k)
{
	if (k > n - k) k = n - k;  // C of k and n-k are equal, so choose the smaller one

	unsigned result = 1;

	for (unsigned i = 1; i <= k; i++)
	{
		result *= n - k + i;
		result /= i;
	}

	return result;
}

int main()
{
	unsigned n;

	cin >> n;

	for (unsigned i = 0; i <= n; i++)
	{
		cout << getBinomial(n, i);
		if (i != n) cout << ' ';
	}

	system("pause");

	return 0;
}