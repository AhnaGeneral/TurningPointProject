#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;
int gN; // - 도시 개수
int gC; // - C명 늘이기 위해 형택이가 투자해야하는 돈의 최솟값의 C
int gCost[101]; // - 도시 홍보할 때 대는 비용
int gCCnt[101]; 
int DP[1001];

int DFS(int pCustomCnt)
{
	if (pCustomCnt <= 0)
	{
		return 0;
	}
	
	if (DP[pCustomCnt] > 0)
	{
		return DP[pCustomCnt];
	}

	int mMin = 1000 * 100; // C명 max:1000, 비용 max:100

	for (int i = 0; i < gN; ++i)
	{
		// ex) DFS(12[C명] - 5[고객 수]) + 3[비용] 
		// ex) DFS(12[C명] - 1[고객 수]) + 1[비용] 
		int mCost = DFS(pCustomCnt - gCCnt[i]) + gCost[i];
		mMin = min(mCost, mMin);
	}
	DP[pCustomCnt] = mMin;

	return DP[pCustomCnt];
}
int main(void)
{
	cin >> gC >> gN; 
	for (int i = 0; i < gN; ++i)
	{
		cin >> gCost[i] >> gCCnt[i]; 
	}

	cout << DFS(gC) << endl;
	return 0; 
}