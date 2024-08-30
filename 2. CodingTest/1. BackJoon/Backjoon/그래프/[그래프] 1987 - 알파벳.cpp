#include<iostream>
#include<queue>
//#include<set>
#include<memory.h>
using namespace std;

int dx[4] = { -1, 1, 0 , 0 }; 
int dy[4] = { 0, 0, 1, -1 };

char Arr[21][21]; 
bool visited[21][21] = { false,  }; 
queue<pair<int, int>> que; 
bool alphabets[26] = {false, };
//set<char> alphabets; 
int R, C; 
int Results = 0;

int AlphabetToNum(char pChr)
{
	return pChr - 'A';
}

void DFS(int x, int y, int pCount)
{
	alphabets[AlphabetToNum(Arr[x][y])] = true;
	//alphabets.insert(Arr[x][y]);
	for (int i = 0; i < 4; ++i)
	{
		int next_x = dx[i] + x;
		int next_y = dy[i] + y;

		if (pCount == 0)
		{
			//alphabets.clear();
			//alphabets.insert(Arr[x][y]);
			memset(alphabets, false, sizeof(alphabets));
			alphabets[AlphabetToNum(Arr[x][y])] = true;
			memset(visited, false, sizeof(visited));
			visited[x][y] = true;
		}

		if (alphabets[AlphabetToNum(Arr[next_x][next_y])] == false
			&& next_x >= 0 && next_x < R && next_y >= 0 && next_y < C
			&& visited[next_x][next_y] == false)
		{
			visited[next_x][next_y] = true;
			DFS(next_x, next_y, pCount + 1);
			visited[next_x][next_y] = false;
			alphabets[AlphabetToNum(Arr[next_x][next_y])] = false;
		}

		if (Results < pCount)
		{
			Results = pCount;
		}
	}
	visited[x][y] = false; 
	//alphabets.erase(Arr[x][y]);
	//alphabets[AlphabetToNum(Arr[x][y])] = false;
}

int main(void)
{

	cin >> R >> C; 

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			char chr;
			cin >> chr;
			Arr[i][j] = chr;
		}
	}

	DFS(0, 0, 0);

	//
	//char StartChar = Arr[0][0];
	//que.push(make_pair(0,0)); 
	//visited[0][0] = true; 
	//alphabets.insert(StartChar); 
	//
	//int count = 0; 
	//
	//while (!que.empty())
	//{
	//	int sizet = que.size();

	//	for (int k = 0; k < sizet; ++k)
	//	{
	//		auto temp = que.front();
	//		int temp_x = temp.first;
	//		int temp_y = temp.second;
	//		visited[temp_x][temp_y];
	//		que.pop();

	//		for (int i = 0; i < 4; ++i)
	//		{
	//			int next_x = dx[i] + temp_x;
	//			int next_y = dy[i] + temp_y;

	//			if (alphabets.find(Arr[next_x][next_y]) == alphabets.end()
	//				&& next_x >= 0 && next_x < R && next_y >= 0 && next_y < C
	//				&& visited[next_x][next_y] == false)
	//			{
	//				que.push(make_pair(next_x, next_y));
	//				visited[next_x][next_y] = true;
	//				alphabets.insert(Arr[next_x][next_y]);
	//			}
	//		}

	//		count++; 
	//	}
	//}
	//
	cout << Results + 1;
	return 0;
}