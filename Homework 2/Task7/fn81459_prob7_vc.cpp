/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 7
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int getNthPower(int n, int pow)
{
	int result = 1;

	for(int i=0;i<pow;i++)
	{
		result *= n;
	}

	return result;
}

int main()
{
	int n, m, y;

	cin >> n >> m >> y;

	int count = 0;

	for (int i = 1; i < m; i++)
	{
		if(getNthPower(i, n) % m == y)
		{
			if (count) cout << " ";
			cout << i;
			count++;
		}
	}

	if (count == 0)
	{
		cout << -1;
	}

	system("pause");

	return 0;
}