/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 5
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int getPoints(double x, double y, double offsetX, double offsetY)
{
	int points = 0;
	double dist = sqrt((x+offsetX)*(x + offsetX) + (y+offsetY)*(y + offsetY));

	if (dist < 1) points = 60;
	else if (dist < 3 && dist>1) points = 20;
	else if (dist<8 && dist>3) points = 10;
	
	return points;
}

int main()
{
	double x, y, offsetX, offsetY;
	cin >> x >> y >> offsetX >> offsetY;

	int points = getPoints(x, y, offsetX, offsetY);

	cout << points;
}