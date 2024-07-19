// -----------------------------
// [ 다리 놓기 ] ----------------
// -----------------------------
#include<iostream>
using namespace std;
int dp[30][30] = {0, };

int BridgeFunc(int N, int M)
{
	if (dp[N][M])
		return dp[N][M];

	if(N == M)
		return dp[N][M] = 1;

	if (N == 1)
		return dp[N][M] = M;

	for (int i = 1; i <= M-N+1 ; ++i)
	{
		dp[N][M] += BridgeFunc(N - 1, M - i);
	}

	return dp[N][M];
}

int main(void)
{
	int mTC;

	cin >> mTC;

	
	dp[1][1] = 1; 

	while (mTC--)
	{
		int N, M; // 0 < N <= M < 30
		cin >> N >> M; 
		
		cout << BridgeFunc(N, M) <<endl;
	}

	
	
	return 0;
}