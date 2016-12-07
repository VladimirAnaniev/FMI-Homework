/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 6
* @compiler VC
*
*/

#include <iostream>
#include <algorithm>
using namespace std;

int getArea(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	int newWidth = min(x1 + w1, x2 + w2) - max(x1, x2);
	int newHeight = min(y1 + h1, y2 + h2) - max(y1, y2);

	if(newWidth>=0 && newHeight>=0)
	{
		return newWidth*newHeight;
	}

	return 0;
}

int main()
{
	int x1, y1, w1, h1, x2, y2, w2, h2;
	cin >> x1 >> y1 >> h1 >> w1;
	cin >> x2 >> y2 >> h2 >> w2;

	int area = getArea(x1, y1, w1, h1, x2, y2, w2, h2);

	cout << area;
}