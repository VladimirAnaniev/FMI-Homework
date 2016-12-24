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
	unsigned int a, b;

	cin >> a >> b;

	char arrA[10], arrB[10];

	_itoa_s(a, arrA, 10, 10);
	_itoa_s(b, arrB, 10, 10);

	int occurences = 0;

	int countA = 0, countB = 0;
	int maxLen = strlen(arrB) - strlen(arrA);

	while(arrB)
	{
		bool help = true;
		while(arrA)
		{
			if (arrA[countA] == '\0') break;
			if(arrB[countA+countB] != arrA[countA])
			{
				help = false;
				break;
			}
			countA++;
		}
		
		countA = 0;
		countB++;
		if (help) occurences++;
		if (countB > maxLen) break;
	}

	cout << occurences;

	return 0;
}