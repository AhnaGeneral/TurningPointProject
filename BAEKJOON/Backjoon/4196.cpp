#include <iostream>
#include <vector>
using namespace std; 

vector<int> vec[100'001]; 
bool visit[100'001];

void DFSs(int x)
{
	visit[x] = true;

	for (int i = 0; i < vec[x].size(); ++i)
	{
		int _next = vec[x][i]; 

		if (!visit[_next])
			DFSs(_next);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 

	int T; 
	cin >> T; 
	
	while (T--)
	{
		int N, M; 
		cin >> N >> M;
		for (int i = 0; i < M; ++i)
		{
			int x, y; 
			cin >> x >> y;
			vec[x].push_back(y);
		}
		int _count = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (!visit[i])
			{
				++_count;
				DFSs(i);
			}
		}
		cout << _count;
	}
	return 0;
}