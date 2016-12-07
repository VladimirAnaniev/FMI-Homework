/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 9
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int calculate(int num1, int num2, char operation)
{
	if (num1 < 0) num1 = 16 + num1;
	if (num2 < 0) num2 = 16 + num2;
	num1 = num1 % 16;
	num2 = num2 % 16;

	int result = 0;

	if(operation=='+')
	{
		result = num1 + num2;
	}
	else if(operation =='-')
	{
		result = num1 - num2;
	}
	else if(operation == '.')
	{
		result = num1*num2;
	}
	else if(operation == '/')
	{
		if (num2) result = num1 / num2;
		else {
			cout << "Division by zero!";
			return -1;
		}
	}
	else if(operation == '%')
	{
		if (num2) result = num1 % num2;
		else {
			cout << "Division by zero!";
			return -1;
		}
	}

	if (result < 0) result = 16 + result;

	return result % 16;
}

int main()
{
	int num1, num2;
	char operation;
	cin >> num1 >> operation >> num2;
	int result = calculate(num1, num2, operation);
	if(result!=-1)
	{
		cout << result;
	}
}