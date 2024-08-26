#include<iostream>
#include<queue>
#include<array>
using namespace std; 

int ArrMap[1001][1001] = { 0, };
int ArrResult[1001][1001] = { 0, };
bool visit[1001][1001] = { false };

pair<int, int> direction[4] = {{ -1, 0}, {1, 0}, { 0, -1}, {0, 1} };

int main(void)
{
	int N, M; 
	cin >> N >> M;
	pair<int, int> targetPoint;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> ArrMap[i][j]; 
			if (ArrMap[i][j] == 2)
			{
				targetPoint.first = i; 
				targetPoint.second = j;
			}
		}
	}

	queue<pair<int, int>>  que; 
	que.push(make_pair(targetPoint.first, targetPoint.second));
	ArrResult[targetPoint.first][targetPoint.second] = 0;

	while (!que.empty())
	{
		auto temp  = que.front();
		visit[temp.first][temp.second] = true; 
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int X = temp.first + direction[i].first; 
			int Y = temp.second + direction[i].second; 

			if (ArrMap[X][Y] == 0)
			{
				continue;
			}
			else if (X >= 0 && X < N && Y >= 0 && Y <M && visit[X][Y] == false)
			{
				ArrResult[X][Y] = ArrResult[temp.first][temp.second] + 1; 
				visit[X][Y] = true;
				que.push(make_pair(X, Y));
			}

		}
	}


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (i == targetPoint.first && j == targetPoint.second)
			{
				cout << 0 << " ";
			}
			else if (ArrResult[i][j] == 0 && ArrMap[i][j] != 0 )
			{
				cout << -1 << " ";
			}
			else
			{
				cout << ArrResult[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0; 
}