#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;

int main()
{
	srand((int)time(NULL));

	int numDoors = 3;
	int repeat = 100000;

	int stay = 0;
	int change = 0;
	
	for (int i = 0; i < repeat; i++)
	{
		int answer = rand() % 3;
		int choice1 = rand() % 3;

		pair<int, int> remaining(-1, -1);
		for (int i = 0; i < 3; i++)
		{
			if (i == choice1)
				continue;
			if (remaining.first == -1)
				remaining.first = i;
			else
				remaining.second = i;
		}

		int choice2;

		if (remaining.first == answer)
			choice2 = remaining.first;
		else if (remaining.second == answer)
			choice2 = remaining.second;
		else
			choice2 = rand() % 2 == 0 ? remaining.first : remaining.second;

		if (choice1 == answer)
			stay++;
		if (choice2 == answer)
			change++;
	}
	cout << "Not switching wins " << (double)stay / repeat * 100 << "% of the time" << endl;
	cout << "Switching wins " << (double)change / repeat * 100 << "% of the time" << endl;
}