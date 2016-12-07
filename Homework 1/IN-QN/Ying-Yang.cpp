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

int getStatus(double x, double y)
{
	double dist = sqrt(x*x + y*y);
	
	if(dist<6)
	{
		//inside
		int defaultPos;
		if (x < 0) defaultPos = 1;
		else defaultPos = -1;

		//upperCircles

		double upperDist = sqrt(x*x + (y - 3)*(y - 3));

		if (upperDist == 1) return 0;
		else if (upperDist < 1) return -1;
		else if (upperDist < 3) return 1;

		//bottom circles

		double bottomList = sqrt(x*x + (y + 3)*(y + 3));

		if (bottomList == 1) return 0;
		else if (bottomList < 1) return 1;
		else if (bottomList < 3) return -1;

		return defaultPos;
	}

	return 0;
}

int main()
{
	double x, y;
	cin >> x >> y;

	int status = getStatus(x, y);

	if (status == 1) cout << "Good";
	else if (status == 0) cout << "Neutral";
	else if (status == -1) cout << "Evil";
}