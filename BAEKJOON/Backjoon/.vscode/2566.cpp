#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10][10];
int main(void)
{
	int ceilingValue = 0;
	pair <int, int> Position{ 1,1 };
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			int number; 
			cin >> number; 
			if (ceilingValue < number)
			{
				ceilingValue = number;
				Position.first = i; 
				Position.second = j;
			}
		}
	}
	cout << ceilingValue << endl;
	cout << Position.first <<" "<< Position.second; 
	return 0;
}