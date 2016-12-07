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
#include <sstream>
using namespace std;

bool checkNum(int num)
{
	stringstream ss;
	ss << hex << num;
	string str = ss.str();

	if(str.length()==1) return true;
	else if (str.length() == 2) return str[0] == str[1];
	else if (str.length() == 3) return str[0] == str[1] && str[0] == str[2];
	else if (str.length() == 4) return str[0] == str[1] && str[0] == str[2] && str[0] == str[3];
	else if (str.length() == 5) return str[0] == str[1] && str[0] == str[2] && str[0] == str[3] && str[0] == str[4];
	else if (str.length() == 6) return str[0] == str[1] && str[0] == str[2] && str[0] == str[3] && str[0] == str[4] && str[0] == str[5];
	else return false;
}

int main()
{
	int num;
	cin >> num;

	bool result = checkNum(num);

	if (result) cout << "Yes";
	else cout << "No";
	system("pause");
}