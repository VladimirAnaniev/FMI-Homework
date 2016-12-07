/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 3
* @compiler VC
*
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;

	cin >> a >> b;

	int occurences = 0;

	for (int i = 0; i < b.length(); i++)
	{
		bool helper = true;
		for (int u = 0; u < a.length(); u++)
		{
			if (b[i + u] != a[u]) helper = false;
		}
		if (helper) occurences++;
	}

	cout << occurences;

	system("pause");
}