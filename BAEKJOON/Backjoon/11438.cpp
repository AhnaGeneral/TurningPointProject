#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;


constexpr int st = 21;

vector<int> gLink[100'101];
int gSparseTable[st][100'001];
int gDepth[100'001];

void DFS(int pIdx, int pDepth)
{
	if(gDepth[pIdx] == -1)
		gDepth[pIdx] = pDepth;


	for (size_t i = 0; i < gLink[pIdx].size(); ++i)
	{
		int aNext = gLink[pIdx][i];

		if (gDepth[aNext] == -1)
			DFS(aNext, pDepth + 1);
		else
			continue;
	}
}

void LCA(int pN)
{
	// 초기 세팅 ------------------------------------
	for (int i = 1; i <= pN; ++i)
	{
		for (size_t j = 0; j < gLink[i].size(); ++j)
		{
			if (gDepth[i] < gDepth[gLink[i][j]])
			{
				gSparseTable[0][gLink[i][j]] = i;
			}
			else
			{
				gSparseTable[0][i] = gLink[i][j];
			}
		}
	}

	// -----------------------------------------------
	for (int i = 1; i < st; ++i)
	{
		for (int j = 1; j <= pN; ++j)
		{
			int temp = gSparseTable[i - 1][j];
			gSparseTable[i][j] = gSparseTable[i - 1][temp]; 
		}
	}	
}

int aFindDepth (int pParm, int pDiff)
{
	int cur = pParm;
	for (int i = 0; i < st; ++i)
	{
		if (pDiff & (1 << i))
		{
			cur = gSparseTable[i][cur];
		}
	}
	return cur;
};

int FindLCA(int pA, int pB, int pN)
{
	int H = 0; 

	while (pN > 1)
	{
		pN /= 2; 
		H++;
	}

	if (pA != pB)
	{
		for (int i = H; i >= 0; --i)
		{
			if(gSparseTable[i][pA]!=0 && gSparseTable[i][pA]!= gSparseTable[i][pB])
			{
				pA = gSparseTable[i][pA];
				pB = gSparseTable[i][pB];
			}
		}

		return gSparseTable[0][pA];
	}
	else
	{
		return pA;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 

	memset(gDepth, -1, sizeof(gDepth));

	// root = 1 
	int n; cin >> n; 

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; 
		cin >> a >> b; 
		gLink[a].push_back(b); 
		gLink[b].push_back(a);
	}

	DFS(1, 0);
	LCA(n);

	int m; cin >> m; 

	for (int i = 0; i < m; ++i)
	{
		int a, b; 
		cin >> a >> b;

		int aDiff = 0; 
		
		if (gDepth[a] != gDepth[b])
		{
			if (gDepth[a] < gDepth[b]) // a가 b보다 위에 있다. 
			{
				aDiff = gDepth[b] - gDepth[a];
				b = aFindDepth(b, aDiff);
			}
			else
			{
				aDiff = gDepth[a] - gDepth[b];
				a = aFindDepth(a, aDiff);
			}
		}

		cout << FindLCA(a, b, n) << "\n";
	}
	return 0;
}