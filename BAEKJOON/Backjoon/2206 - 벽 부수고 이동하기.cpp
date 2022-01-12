#include <iostream> 
#include <vector>
#include <queue>
#include<cstring>
#include <algorithm>
using namespace std;

#define MAX 1000

using IIT = pair<int, int>;
bool visit[MAX][MAX][2];
int wall[MAX][MAX]; 

int gWide, gHigh;

int gMoveX[4] = { 0, 0, -1,  1}; // ╩С го аб ©Л 
int gMoveY[4] = {-1, 1 , 0 , 0};

// 
void bfs(IIT _Data)
{
	queue<pair<IIT, IIT>> que;
	que.push(make_pair(make_pair(_Data.first, _Data.second), make_pair(1, 0)));
	visit[_Data.first][_Data.second][0] = visit[_Data.first][_Data.second][1] = true;

	while (!que.empty())
	{
		pair<IIT, IIT> temp = que.front();
		int x = temp.first.first;
		int y = temp.first.second;

		if (x == gWide - 1 && y == gHigh - 1)
		{
			cout << temp.second.first << endl;
			return;
		}
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int posx = x + gMoveX[i];
			int posy = y + gMoveY[i];
			int breakCnt = temp.second.second; 
			if (posx >= 0 && posx < gWide && posy >= 0 && posy < gHigh)
			{
				if (!wall[posy][posx])
				{
					if (!visit[posy][posx][breakCnt])
					{
						visit[posy][posx][breakCnt] = true;
						que.push(make_pair(make_pair(posx, posy),
							make_pair(temp.second.first + 1, breakCnt)));
					}
				}
				else if (wall[posy][posx] && !breakCnt)
				{
					if (!visit[posy][posx][breakCnt])
					{
						visit[posy][posx][breakCnt + 1] = true;
						que.push(make_pair(make_pair(posx, posy),
							make_pair(temp.second.first + 1, breakCnt + 1)));
					}
				}
			}
		}
	}

	cout << -1 << endl;
	return;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	// ===================================
	cin >> gHigh >> gWide;

	
	memset(visit, false, sizeof(visit));
	memset(wall, 0, sizeof(wall));

	for (int w = 0; w < gHigh; ++w)
	{
		for (int h = 0; h < gWide; ++h)
		{
			char Iswall;
			cin >> Iswall ;
			wall[w][h] = Iswall - '0';
		}
	}
	
	bfs(make_pair(0, 0)); 
}