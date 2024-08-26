#include<iostream>
using namespace std;

long long  dp[21] = {0, };
long long factorial(int num)
{
	if (dp[num]) return dp[num];

	if (num == 0) return dp[0] = 1 ;
	if (num == 1) return dp[1] = 1; 

	return dp[num] = num * factorial(num - 1);
}

int main(void)
{
	int mTC;

	cin >> mTC;

	cout << factorial(mTC);

	return 0;
}