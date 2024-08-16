// 연결 요소의 개수 

#include<iostream>
#include<queue>
#include<vector>
using namespace std; 

bool visit[1001] = { false, }; 
vector<int> distributingLine[1001]; 

int main(void)
{
	int N, M; 
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int u, v; 
		cin >> u >> v;
		distributingLine[u].push_back(v); 
	}

	int count = 0;
	for (int i = 1; i < N; ++i)
	{
		if (visit[i])
		{
			continue;
		}

		queue<int> que;
		que.push(i);
		visit[i] = true;

		bool check = false;

		while (!que.empty())
		{
			int temp = que.front(); 
			visit[temp] = true;
			que.pop();
			
			for (int j = 0; j < distributingLine[temp].size(); ++j)
			{
				if (visit[distributingLine[temp][j]] == false)
				{
					visit[distributingLine[temp][j]] = true;
					que.push(distributingLine[temp][j]);
					check = true; 
				}
			}
		}

		if (check)
		{
			count++;
		}
	}
	
	cout << count; 
	return 0; 
}