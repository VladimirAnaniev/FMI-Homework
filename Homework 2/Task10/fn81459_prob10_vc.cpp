/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 10
* @compiler VC
*
*/

#include <iostream>
#include <algorithm>

using namespace std;

int getPadic(int p, int n)
{
	int num = p;
	int result = 0;
	int count = 1;

	while(num<=n)
	{
		if(n%num==0)
		{
			result = count;
		}
		
		num *= p;
		count++;
	}

	return result;
}

int main()
{
	int nq;

	cin >> nq;

	for(int i=0;i<nq;i++)
	{
		int p1, n, p2;
		cin >> p1 >> n >> p2;

		if (n == 0) {
			cout << "infinity" << endl;
			continue;
		}

		int v1 = getPadic(p1, n);
		int v2 = getPadic(p2, n);

		cout << max(v1, v2) << endl;;
	}

	return 0;
}