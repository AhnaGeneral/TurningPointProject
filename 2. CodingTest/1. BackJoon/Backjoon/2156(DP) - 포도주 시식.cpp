#include <iostream> 
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
// �����ָ� ������ �������� ���� �� ���ٴ� ���� ����ؼ� �޸����̼��� �ϸ� �ȴ�
// �� ���� ���� �������� ���� �ִ��� ��츦 �����غ���
// - ���� ������ �����ָ� ���� �ʾ��� ���� 
// - ������ �����ָ� ���ð� �������� �ȸ��� ���
// - ������ �����ֿ� ������ �����ָ� ���� ��� 

// i = 1 
// dp[1] = 6
// dp[2] = 16 

// �׷� dp[3]? 
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