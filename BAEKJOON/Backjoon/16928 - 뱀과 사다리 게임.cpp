#include <iostream>
#include <vector>
#include <deque>
using namespace std; 
#define MAX 100 
#define SIZE 6
vector<int> LadderAndSnake(MAX, 0);
pair<bool, vector<int>> Board[MAX];

// 16928번 - 뱀과 사다리 게임
// * 10x10 총 100개의 칸으로 나누어져 있는 보드판에서 진행.
// * 플레이어는 주사위를 굴려 나온 수 만큼 이동해야 한다. 
// * 사다리를 이용해 이동한 칸의 번호는 원래 있던 칸의 번호 보다 크고,
// 뱀을 이용해 이동한 칸의 번호는 원래 있던 칸의 번호 보다 작아야 한다. 

void BFS(int start); 

int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0); 

	int N, M; // N: 사다리의 수, M: 뱀의 수 
	cin >> N >> M; 
	
	for (int i = 0; i < N; ++i) { 
		int x, y; 
		cin >> x >> y; 
		LadderAndSnake[x] = y;
	}

	for (int i = 0; i < M; ++i) {
		int u, v; 
		cin >> u >> v;
		LadderAndSnake[u] = v;
	}

	//int BoardCount = 0; 
	//for (int i = 0; i < SIZE; ++i) {
	//	for (int j = 0; j < SIZE; ++j) {
	//		Board[i][j] = ++BoardCount;
	//	}
	//}
	/*=======================================*/
}

void BFS(int start)
{
	deque<int> deq; 
	deq.emplace_back(start); 
	Board[start].first = true; 
	
	while (!deq.empty())
	{
		int _next = deq.front(); 
		deq.pop_front(); 
		for (int i = 1; i <= 6; ++i) {
			
		}

	}
}