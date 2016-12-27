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

using namespace std;

void stringify(int num, char* arr, int& len) //Returns the number reversed, but still works
{
	len = 0;
	while(num && len<10)
	{
		arr[len] = num % 10 + 48;
		num /= 10;
		len++;
	}
	arr[len] = '\0';
}

int main()
{
	unsigned int a, b;
	int  lenA, lenB;

	cin >> a >> b;

	char arrA[11], arrB[11];

	stringify(a, arrA, lenA);
	stringify(b, arrB, lenB);

	int occurences = 0;

	int countA = 0, countB = 0;
	int maxLen = lenB-lenA;

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

	system("pause");
	return 0;
}