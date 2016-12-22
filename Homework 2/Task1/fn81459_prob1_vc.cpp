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

double getSlope(double x1, double y1, double x2, double y2)
{
	if (x2 - x1 == 0) return 0;
	return (y2 - y1) / (x2 - x1);
}

double getB(double slope, double x, double y)
{
	return y - slope*x;
}

void setNewPoint(double& xToChange, double& yToChange, double x, double y)
{
	double slope = getSlope(xToChange, yToChange, x, y);
	double b = getB(slope, xToChange, yToChange);


	if (xToChange >= -5 && xToChange <= 5) // Above and below field
	{
		if (yToChange > 2)
		{
			yToChange = 2; 
		}
		else if(yToChange<-2)
		{
			yToChange = -2;  
		}

		if(slope!=0)
			xToChange = (yToChange - b) / slope;
	}

	else if(yToChange>=-2 && yToChange<=2) //Right and left
	{
		if(xToChange<-5)
		{
			xToChange = -5; 
		}
		else if(xToChange>5)
		{
			xToChange = 5; 
		}

		yToChange = slope*xToChange + b;
	}

	else if(xToChange<-5 && yToChange>2) //Upper left
	{
		if(slope*-5+b>2)
		{
			yToChange = 2;
			xToChange = (yToChange - b) / slope;
		}
		else
		{
			xToChange = -5;
			yToChange = slope*xToChange + b;
		}
	}

	else if (xToChange<-5 && yToChange<-2) //Lower Left
	{
		if (slope*-5 + b<-2)
		{
			yToChange = -2;
			xToChange = (yToChange - b) / slope;
		}
		else
		{
			xToChange = -5;
			yToChange = slope*xToChange + b;
		}
	}

	else if (xToChange>5 && yToChange>2) //Upper right
	{
		if (slope*5 + b>2)
		{
			yToChange = 2;
			xToChange = (yToChange - b) / slope;
		}
		else
		{
			xToChange = 5;
			yToChange = slope*xToChange + b;
		}
	}

	else if (xToChange>5 && yToChange<-2) //Lower right
	{
		if (slope*-5 + b<-2)
		{
			yToChange = -2;
			xToChange = (yToChange - b) / slope;
		}
		else
		{
			xToChange = 5;
			yToChange = slope*xToChange + b;
		}
	}

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
	bool outside1 = isOutside(x1, y1);
	bool outside2 = isOutside(x2, y2);

	if (outside1 && outside2) //Both are outside
	{
		dist = 0;
	}
	else //At least one is inside
	{
		if(outside1)
		{
			setNewPoint(x1, y1, x2, y2);
		}
		else if(outside2)
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
	
	return 0;
}