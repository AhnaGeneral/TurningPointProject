#include<iostream>
#include<algorithm>
using namespace std;

long long dp[1001][10] = {0,};

int main()
{
	long long n; 
	cin >> n; 

	fill( &dp[0][0], &dp[1000][10], 1);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 8; j >= 0; --j)
		{
			dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % 10007;
		}
	}

	int result = 0; 
	for (int i = 0; i <= 9; ++i)
	{
		result += dp[n][i];
	}

	cout << result % 10007; 
	
	return 0;
}