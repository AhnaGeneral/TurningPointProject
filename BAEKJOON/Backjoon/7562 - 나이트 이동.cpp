#include <iostream> 
#include <vector>
#include <queue>
#include<cstring>
#include <algorithm>
using namespace std;

#define MAX 300

int visit[MAX][MAX];
int Lenth;
int movePosX[8]{ -1, -2, 1, 2, 2, 1, -1, -2 };
int movePosY[8]{ -2, -1, -2, -1, 1, 2, 2, 1 };

pair<int, int> Dest; 

void BFS(pair<int, int> _Data)
{
	queue<pair<pair<int, int>, int>> que; 
	que.push(make_pair(make_pair(_Data.first, _Data.second), 0));
	visit[_Data.first][_Data.second] = 0; 

	while (!que.empty())
	{
		pair<pair<int, int>, int> temp = que.front();
		int x = temp.first.first; 
		int y = temp.first.second; 
		if (x == Dest.first && y == Dest.second)
		{
			cout << temp.second << endl;
			return; 
		}
		que.pop();
		for (int i = 0; i < 8; ++i)
		{
			int posx = x + movePosX[i];
			int posy = y + movePosY[i];
		
			if (posx >= 0 && posx < Lenth && posy >= 0 && posy < Lenth)
			{
				if (!visit[posx][posy])
				{
					visit[posx][posy] = 1;
					que.push(make_pair(make_pair(posx, posy), temp.second + 1));
				}
			}
		}
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int TestCnt; 
	cin >> TestCnt; 
	
	while (TestCnt--)
	{
		
		pair<int, int> Pstart, Pend;
		cin >> Lenth;
		cin >> Pstart.first >> Pstart.second;
		cin >> Pend.first >> Pend.second;

		Dest.first = Pend.first; 
		Dest.second = Pend.second;
		
		memset(visit, 0, sizeof(visit));

		if (Pstart.first != Pend.first || Pstart.second != Pend.second)
		{
			BFS(make_pair(Pstart.first, Pstart.second));
		}

		else if (Pstart.first == Pend.first && Pstart.second == Pend.second)
		{
			cout << 0 << endl; 
			continue; 
		}

		
	}
}