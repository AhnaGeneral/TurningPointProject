#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

int gN; // - n�� �ִ� 100
int gMaxMemory; // - max �޸�
int gCost[101]; 
int gMemory[101];
int DP[100][100 * 100 + 1];

int main(void)
{
	cin >> gN >> gMaxMemory; 

	int mMaxCost = 0;
	for (int idx = 1; idx <= gN; ++idx)
	{
		cin >> gMemory[idx]; 
	}

	for (int idx = 1; idx <= gN; ++idx)
	{
		cin >> gCost[idx];
		mMaxCost += gCost[idx];
	}

	for (int idx = 1; idx <= gN; ++idx)
	{
		for (int aCost = 0; aCost <= mMaxCost; ++aCost)
		{
			if (aCost - gCost[idx] >= 0) // gCost[5] = 4�� �� 4���� ������ idx = 5�� ���Եɼ��� ����.
				DP[idx][aCost] = max(DP[idx][aCost], DP[idx - 1][aCost - gCost[idx]] + gMemory[idx]);
			//else
				DP[idx][aCost] = max(DP[idx][aCost], DP[idx - 1][aCost]);
		}
	}

	for (int aCost = 0; aCost <= mMaxCost; ++aCost)
	{
		if (DP[gN][aCost] >= gMaxMemory)
		{
			cout << aCost;
			break;
		}
	}

	return 0;
}