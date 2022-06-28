#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
using PIPII = pair<int, pair<int, int>>;

int getParent(int* parent, int a)
{
	if (parent[a] == a) return a; 
	
	return parent[a] = getParent(parent, parent[a]);
}
void Union(int* parent, int a, int b)
{
	a = getParent(parent, a); 
	b = getParent(parent, b);
	
	if (a < b) 
		parent[b] = a;
	else
		parent[a] = b; 
}
int Find(int* parent, int a, int b) 
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b)
		return 1; 
	else
		return 0;
}

int KrusKal(int* parent, vector<PIPII> edge, int vertex)
{
	sort(edge.begin(), edge.end());
	int cnt = 0, idx = 0, ans = 0;
	while (cnt != vertex - 1)
	{
		int w = edge[idx].first;
		if (!Find(parent, edge[idx].second.first, edge[idx].second.second))
		{
			ans += w;
			Union(parent, edge[idx].second.first, edge[idx].second.second);
			idx++;
			cnt++;
		}
		else
			continue;
	}
}
int main()
{
	int cost; // 최종 비용
}