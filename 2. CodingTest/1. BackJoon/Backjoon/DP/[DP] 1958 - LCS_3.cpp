#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std; 
int dp[101][101][101] = {0, };

int main(void)
{
	string a, b, c; 
	cin >> a >> b >> c; 

	for (int i = 1; i <= a.size(); ++i)
	{
		for (int j = 1; j <= a.size(); ++j)
		{
			for (int k = 1; k <= a.size(); ++k)
			{
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					// dp[i][j - 1][k - 1]
					// dp[i - 1][j][k - 1]
					// dp[i - 1][j - 1][k]
					int temp = max(dp[i][j][k - 1], dp[i - 1][j][k]); 
					dp[i][j][k] = max(temp, dp[i][j - 1][k]);
				}
			}
		}
	}

	cout << dp[a.size()][b.size()][c.size()];
	return 0;
}