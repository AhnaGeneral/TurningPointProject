#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<memory.h>

using namespace std;
const int MAX = 21;
const int INF = 0x3f3f3f3f;
int a[MAX][MAX], dp[MAX][1 << 21];
int N;
int DP(int cur, int flag)
{
	if (cur >= N)
		return flag == (1 << N) - 1 ? 0 : INF;
	int& ret = dp[cur][flag];

	if(ret != -1)
		return ret; 

	ret = INF; 

	for (int i = 0; i < N; ++i)
	{
		if (!(flag & (1 << i)))
			ret = min(ret, DP(cur + 1, flag | (1 << i)) + a[cur][i]);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 

	//누가 어떤 일을 하고 있는지에 따라 dp값이 달라진다. 


	cin >> N; 

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> a[i][j]; 
		}
	}
	memset(dp, -1, sizeof(dp)); 
	cout << DP(0, 0) << "\n"; 
	return 0;
}