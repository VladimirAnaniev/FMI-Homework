/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 1
* @compiler VC
*
*/

#include <iostream>
#include <iomanip>

using namespace std;

void setNewPoint(double& xToChange, double& yToChange, double x, double y)
{
	//TODO: Kak da gi smenq basi?????
}

bool isOutside(double x, double y)
{
	return x < -5 || x>5 || y < -2 || y>2;
}

void distFormula(double &distance)
{
	distance = (3.14*distance / 2 + distance) / 2;
}

double getDistance(double x1, double y1, double x2, double y2)
{
	double dist;
	bool inside1 = isOutside(x1, y1);
	bool inside2 = isOutside(x2, y2);

	if (inside1 && inside2) //Both are outside
	{
		dist = 0;
	}
	else //At least one is inside
	{
		if(!inside1)
		{
			setNewPoint(x1, y1, x2, y2);
		}
		else if(!inside2)
		{
			setNewPoint(x2, y2, x1, y1);
		}

		dist = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	}
	distFormula(dist);
	return dist;

}

int main()
{
	int points;
	cin >> points;

	double lastX, lastY;
	double distance = 0;

	for (int i = 0; i < points; i++)
	{
		double x, y;
		cin >> x >> y;

		if(i>=1)
		{
			distance += getDistance(lastX, lastY, x, y);
		}

		lastX = x;
		lastY = y;
	}

	cout << fixed << setprecision(3) << distance;

	system("pause");
	
	return 0;
}