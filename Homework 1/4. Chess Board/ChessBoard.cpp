/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Vladimir Ananiev
* @idnumber 81459
* @task 4
* @compiler VC
*
*/

#include <iostream>
using namespace std;

bool isCheck(char figureType, char figureX, int figureY, char kingX, int kingY)
{
	int offsetX = abs(figureX - kingX);
	int offsetY = abs(figureY - kingY);
	if (figureType == 'R') return (figureX == kingX) || (figureY == kingY);
	else if (figureType == 'B') return offsetX == offsetY;
	else if (figureType == 'Q') return (figureX == kingX) || (figureY == kingY) || offsetX == offsetY;
	else if (figureType == 'N') return (offsetX == 1 && offsetY == 2) || (offsetX == 2 && offsetY == 1);
}

int main()
{
	char figureType, figureX, kingX;
	int figureY, kingY;
	cin >> figureType >> figureX >> figureY >> kingX >> kingY;

	bool result = isCheck(figureType, figureX, figureY, kingX, kingY);

	if (result) cout << "Yes";
	else cout << "No";
}