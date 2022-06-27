#include <iostream>
#include <vector>
#include <deque>
using namespace std; 
#define MAX 100 
#define SIZE 6
vector<int> LadderAndSnake(MAX, 0);
pair<bool, vector<int>> Board[MAX];

// 16928�� - ��� ��ٸ� ����
// * 10x10 �� 100���� ĭ���� �������� �ִ� �����ǿ��� ����.
// * �÷��̾�� �ֻ����� ���� ���� �� ��ŭ �̵��ؾ� �Ѵ�. 
// * ��ٸ��� �̿��� �̵��� ĭ�� ��ȣ�� ���� �ִ� ĭ�� ��ȣ ���� ũ��,
// ���� �̿��� �̵��� ĭ�� ��ȣ�� ���� �ִ� ĭ�� ��ȣ ���� �۾ƾ� �Ѵ�. 

void BFS(int start); 

int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0); 

	int N, M; // N: ��ٸ��� ��, M: ���� �� 
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