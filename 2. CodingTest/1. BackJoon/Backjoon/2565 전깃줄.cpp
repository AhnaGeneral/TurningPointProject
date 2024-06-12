#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();
	
	int N; cin >> N;
	vector<pair<int, int>> El(N);
	vector<int> dp(N, 1); 
	for (int i = 0; i < N; i++) {
		cin >> El[i].first >> El[i].second;
	}
	sort(El.begin(), El.end());
	
	for(int i = 1; i< N; i++)
		for (int j = 0; j < i; j++)
		{
			if (El[i].second > El[j].second)
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}

	int _max = -10000; 
	for (int i = 0; i < N; i++) {
		if (_max < dp[i])
			_max = dp[i];
	}

	cout << N - _max + 1; 
	
}