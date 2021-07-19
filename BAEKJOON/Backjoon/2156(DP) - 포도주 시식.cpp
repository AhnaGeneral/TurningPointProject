#include <iostream> 
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
// 포도주를 세개를 연속으로 먹을 수 없다는 것을 고려해서 메모리제이션을 하면 된다
// 즉 현재 먹은 포도주의 합이 최대일 경우를 생각해보면
// - 내가 현재의 포도주를 먹지 않았을 경우와 
// - 현재의 포도주를 마시고 이전꺼를 안마실 경우
// - 현재의 포도주와 이전의 포도주를 마신 경우 

// i = 1 
// dp[1] = 6
// dp[2] = 16 

// 그럼 dp[3]? 
// 1. dp[i-1]
// 2. dp[i-1]+wine[i]
// 3. dp[i-2]+wine[i]

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int n; 
	int wine[10010] = {}; 
	int DP[10010] = {}; 
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> wine[i]; 
	}
	for (int i = 1; i < 3 && i <= n; i++) {
		if (i == 1) DP[i] = wine[i];
		else
			DP[i] = wine[i] + wine[i - 1];
	}
	for (int i = 3; i <= n; i++) {
		int result = 0;
		result = max(wine[i] + DP[i - 2], DP[i - 1]);
		result = max(result, wine[i] + wine[i - 1] + DP[i - 3]);
		DP[i] = result;
	}
	cout << DP[n];

}