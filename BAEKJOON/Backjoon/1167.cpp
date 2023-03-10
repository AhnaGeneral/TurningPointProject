#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
vector<pair<int, int>> vec[10'001];
bool visit[10'001];
int max_num = 0;
int end_Point = 0;
void _Fdfs(int pStart, int pDist)
{
	visit[pStart] = true;

	if (max_num < pDist)
	{
		max_num = pDist;
		end_Point = pStart;
	}
	for (size_t i = 0; i < vec[pStart].size(); ++i)
	{
		int _next = vec[pStart][i].first; 
		int _dist = vec[pStart][i].second; 
		if (!visit[_next])
		{
			_Fdfs(_next, _dist + pDist);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1 ; ++i)
	{
		int a, b, c; 
		cin >> a >> b >> c; 
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c));
	}
	_Fdfs(1, 0);
	max_num = 0; 
	memset(visit, false, sizeof(visit));
	_Fdfs(end_Point, 0);
	cout << max_num;
	return 0;
}