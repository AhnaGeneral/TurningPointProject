#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int power(int value, int n)
{
	if(n==1) return value;
	else
	{
		int x = power(value, n/2);
		if(n % 2) // odd
		{
			return x*x*value;
		}
		else // even
		{
			return x*x;
		}
	}
}

int main(void)
{
	int N, K;
	vector<int> vec;
	cin >> N >> K;


}