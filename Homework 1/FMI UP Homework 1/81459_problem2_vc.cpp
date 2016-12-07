/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 2
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int decode(long long num)
{
	//Get all digits
	int firstDigit = num / 1000000000;
	int secondDigit = (num / 100000000) % 10;
	int thirdDigit = (num / 10000000) % 10;
	int fourthDigit = (num / 1000000) % 10;
	int fifthDigit = (num / 100000) % 10;
	int sixthDigit = (num / 10000) % 10;
	int seventhDigit = (num / 1000) % 10;
	int eighthDigit = (num / 100) % 10;
	int ninthDigit = (num / 10) % 10;
	int tenthDigit = num % 10;

	//Get birth date
	int year = num / 100000000;
	int month = (num / 1000000) % 100;
	int date = (num / 10000) % 100;

	//Check Length
	if (num / 1000000000 >= 10) return 0;
	
	//Check last digit
	int lastDigit = (2 * firstDigit + 4 * secondDigit + 8 * thirdDigit + 5 * fourthDigit + 10 * fifthDigit + 9 * sixthDigit + 7 * seventhDigit + 3 * eighthDigit + 6 * ninthDigit) % 11;
	if (lastDigit >= 10) lastDigit = 0;
	if (lastDigit != tenthDigit) return 0;

	//Get correct year and month
	if (month > 40 && month < 53)
	{
		//2000-2099
		year = 2000 + year;
		month = month - 40;
	}
	else if (month > 20 && month < 33)
	{
		//1800-1899
		year = 1800 + year;
		month = month - 20;
	}
	else if (month > 0 && month < 13)
	{
		//1900-1999
		year = 1900 + year;
	}
	else return 0;

	//Check days in month
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (date > 31) return 0;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (date > 30) return 0;
	}
	else if(month==2)
	{
		int days = 28;
		if (year % 4 == 0 && ((year % 100 != 0) || year % 400 == 0))
		{
			days++;
		}

		if (date > days) return 0;
	}
	else return 0;

	//Get gender
	char gender;
	if (ninthDigit % 2) gender = 'F';
	else gender = 'M';

	//All went well, pritn result
	if (date < 10) cout << 0;
	cout << date << ".";

	if (month < 10) cout << 0;
	cout << month << "." << year << " " << gender;
	return 1;
}

int main()
{
	long long num;
	cin >> num;

	int res = decode(num);
	if (res == 0) cout << "Bad input data!";
}