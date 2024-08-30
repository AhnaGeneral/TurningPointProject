#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

int N, M, A, B;
int dist[1'001] = { 0, };
//bool visited[1'001] = { false, };
vector<pair<int, int>> vec[1'001];


struct comparess
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, comparess> que;

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b, cost; // - 방향 그래프
		cin >> a >> b >> cost;
		vec[a].push_back(make_pair(b, cost));
	}

	cin >> A >> B;

	for (int i = 0; i <= N; ++i)
	{
		dist[i] = 1e9;
	}
	//memset(dist, 100'000, sizeof(int)*1001); 
	que.push(make_pair(A, 0));
	dist[A] = 0;
	//visited[A] = true; 

	while (!que.empty())
	{
		auto temp = que.top();

		//if (visited[temp.first])
			//continue;

		//visited[temp.first] = true;
		if (temp.first == B)
			break;

		que.pop();

		for (int i = 0; i < vec[temp.first].size(); ++i)
		{
			if (dist[vec[temp.first][i].first] > temp.second + vec[temp.first][i].second)
			{
				dist[vec[temp.first][i].first] = temp.second + vec[temp.first][i].second;
				//visited[vec[temp][i].first] = true;
				que.push(make_pair(vec[temp.first][i].first, temp.second + vec[temp.first][i].second));
			}
		}
	}

	cout << dist[B];
	return 0;
}