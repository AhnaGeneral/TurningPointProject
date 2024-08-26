#include<iostream>
#include<vector>
using namespace std;
int dp[1'000'001] = { 0, };
int track[1'000'001] = { 0, };

int main(void)
{
	int mTC;
	cin >> mTC;

	dp[0] = 0;
	dp[1] = 0;
	track[1] = 1;

	for (int i = 2; i <= mTC; ++i)
	{
		dp[i] = dp[i - 1] + 1; 
		track[i] = i - 1;
		
		if (i % 2 == 0 && (dp[i] > dp[i / 2] + 1))
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
			track[i] = i / 2;
		}

		if (i % 3 == 0 && (dp[i] > dp[i / 3] + 1))
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
			track[i] = i / 3;
		}
	}


	cout << dp[mTC] << endl; 
	cout << mTC << " ";
	while (mTC!= 1)
	{
		cout << track[mTC] << " ";
		mTC = track[mTC];
	}
	return 0;
}