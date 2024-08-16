#include<iostream>
#include<vector>
#include<queue>
#include<memory>
using namespace std;

vector<int> arr[101]; 
int Floyed[101][101] = {0, };
bool visit[101] = { false, };
queue<int> que;

int main(void)
{
	int N; cin >> N; 

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int a; 
			cin >> a; 

			if (a)
			{
				arr[i].push_back(j); 
			}
		}
	}

	//=============================================//

	for (int i = 1; i <= N; ++i)
	{
		memset(visit, false, sizeof(visit));

		if (visit[i])
		{
			continue;
		}

		que.push(i);
		visit[i] = true;

		while (!que.empty())
		{
			int temp = que.front();
			visit[temp] = true;
			que.pop();

			for (int j = 0; j < arr[temp].size(); ++j)
			{
				if (visit[arr[temp][j]] == false)
				{
					visit[arr[temp][j]] = true;
					Floyed[i][arr[temp][j]] = 1;
					que.push(arr[temp][j]);
				}
				else if(visit[arr[temp][j]] == true && arr[temp][j] == i)
				{
					Floyed[i][i] = 1;
				}
			}
		}
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << Floyed[i][j] << " ";
		}
		cout << endl; 
	}
	return 0; 
}