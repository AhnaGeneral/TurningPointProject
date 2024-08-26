#include<iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int mTC;

	cin >> mTC;

	int result = 0; 
	int starts = 4; 
	for (int i = 0; i < mTC; ++i)
	{
		starts *= 4;
		int num = pow(2, i) * 4 + 3;
		starts -= num;
	}

	cout << starts;
	
	return 0;
}