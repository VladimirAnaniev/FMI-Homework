#include <iostream>
#include <sstream>
using namespace std;

void solve(double firstX, double firstY, double firstResult, double secondX, double secondY, double secondResult)
{
	if((firstX == 0 && firstY == 0 && firstResult != 0) || (secondX == 0 && secondY == 0 && secondResult != 0))
		cout << "No solution";

	else cout << "Many solutions";
}

int main()
{
	double firstX, firstY, firstResult, secondX, secondY, secondResult;
	cin >> firstX >> firstY >> firstResult >> secondX >> secondY >> secondResult;
	solve(firstX, firstY, firstResult, secondX, secondY, secondResult);

	system("pause");
}