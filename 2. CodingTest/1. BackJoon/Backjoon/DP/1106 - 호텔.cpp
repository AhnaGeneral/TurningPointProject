#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;
int gN; // - ���� ����
int gC; // - C�� ���̱� ���� �����̰� �����ؾ��ϴ� ���� �ּڰ��� C
int gCost[101]; // - ���� ȫ���� �� ��� ���
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

	int mMin = 1000 * 100; // C�� max:1000, ��� max:100

	for (int i = 0; i < gN; ++i)
	{
		// ex) DFS(12[C��] - 5[�� ��]) + 3[���] 
		// ex) DFS(12[C��] - 1[�� ��]) + 1[���] 
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