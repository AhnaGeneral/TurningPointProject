#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

int gN, gTC;
int gWeight[31];
//vector<int> gAllSum;
bool dp[31][15001];

void DFS(int pParm01, int pParm02)
{
	if (pParm01 > gN || dp[pParm01][pParm02])
	{
		return;
	}
	dp[pParm01][pParm02] = true;
	DFS(pParm01 + 1, pParm02);
	DFS(pParm01 + 1, abs(pParm02 - gWeight[pParm01]));
	DFS(pParm01 + 1, pParm02 + gWeight[pParm01]);
}

int main(void)
{
	cin >> gN;

	for (int idx = 0; idx < gN; ++idx)
	{
		cin >> gWeight[idx];
	}
	DFS(0, 0);

	//std::sort(gAllSum.begin(), gAllSum.end());

	cin >> gTC;

	for (int idx = 0; idx < gTC; ++idx)
	{
		int mTc;
		cin >> mTc;
		if (mTc > 15'000)
		{
			cout << "N";
		}
		else if (dp[gN][mTc])
		{
			cout << "Y";
		}
		else
		{
			cout << "N";
		}
	}
	return 0;
}