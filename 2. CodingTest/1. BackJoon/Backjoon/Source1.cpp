#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// 케빈 베이컨의 6단계의 법칙 

bool visited[101];
int lenth[101][101];
bool relation[101][101];
int n, m;

void BFS(int pPos)
{
	queue<int> que;
	que.push(pPos);
	visited[pPos] = true;

	while (!que.empty())
	{
		int i = que.front();
		que.pop();

		for (int j = 1; j <= n; ++j)
		{
			if (relation[i][j] == true && visited[j] == false)
			{
				que.push(j);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		relation[a][b] = relation[b][a] = true;
	}

	for (int i = 1; i <= n; ++i)
	{
		BFS(i);
	}

	return 0;
}