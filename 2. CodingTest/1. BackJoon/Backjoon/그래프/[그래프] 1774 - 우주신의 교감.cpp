#include<iostream>
#include<vector>
using namespace std; 
#define MAX 1000 

int gAlien[MAX]; //외계인 수

int getParent(int pA)
{
	if (gAlien[pA] == pA) return pA;
	else return getParent(gAlien[pA]);
}

void Union(int pA, int pB)
{
	pA = getParent(pA);
	pB = getParent(pB);

	if (pA < pB) gAlien[pB] = pA;
	else gAlien[pA] = pB;
}

bool Find(int pA, int pB)
{
	pA = getParent(pA);
	pB = getParent(pB);
	if (pA == pB) return true;
	else return false; 
}
int main()
{
	int N, M; 
	cin >> N >> M;
	vector<pair<int, int>> vec; 
	
	for (int i = 0; i < N; ++i)
	{
		int x, y; 
		cin >> x >> y; 
		vec.push_back(make_pair(x, y)); 
		gAlien[i] = i; 
	}
	
	for (int i = 0; i < M; ++i)
	{
		int a, b; 
		cin >> a >> b;

		if (a < b) gAlien[b] = a;
		else gAlien[a] = b;
	}
}
