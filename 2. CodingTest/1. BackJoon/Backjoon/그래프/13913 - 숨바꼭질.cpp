//#include <iostream>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//int dp[100001] = {0,};
//
//int N, M;
//int DFS(int pN)
//{
//	if (pN < 0 && pN * 2 > pN)
//	{
//		return 0; 
//	}
//	
//	if (dp[pN])
//		return dp[pN];
//
//	if (N - 1 == pN)
//	{
//		return dp[M - 1] = 1;
//	}
//
//	int _minus = 0;
//	int _plue = 0; 
//	int _square = 0;
//	
//	_minus = dp[pN - 1] + DFS(pN - 1);
//	_plue = dp[pN + 1] + DFS(pN + 1);
//	_square = dp[pN * 2] + DFS(pN * 2);
//	_minus = min(_minus, _plue); 
//	_square =  min(_minus, _square);
//	dp[pN] = _square;
//}
//int main(void)
//{
//
//	cin >> N >> M; 
//
//	DFS(M);
//	return 0; 
//}


#include <iostream>
#include <queue>

#define MAX 100000

using namespace std;

bool visited[MAX + 1];
queue<int> q;
int minTime;

void BFS(int K)
{
	int temp;
	int time = 0;
	while (true)
	{
		int totSize = q.size();
		for (int i = 0; i < totSize; ++i)
		{
			temp = q.front();
			q.pop();
			if (temp == K)
			{
				minTime = time;
				return;
			}

			if (temp + 1 >= 0 && temp + 1 <= MAX && !visited[temp + 1])
			{
				q.push(temp + 1);
				visited[temp + 1] = true; // �̰� �����غôµ� ����� ���ƿ°Ÿ� ������� ����
			}
			if (temp - 1 >= 0 && temp - 1 <= MAX && !visited[temp - 1])
			{
				q.push(temp - 1);
				visited[temp - 1] = true; // �̰� �����غôµ� ����� ���ƿ°Ÿ� ������� ����
			}
			if (temp << 1 >= 0 && temp << 1 <= MAX && !visited[temp << 1])
			{
				q.push(temp << 1);
				visited[temp << 1] = true; // �̰� �����غôµ� ����� ���ƿ°Ÿ� ������� ����
			}
		}
		time++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	// N : ������ ��ġ,  <= 10��
	// K : ���� ��ġ <= 10��

	cin >> N >> K;

	// visited[N] = true;
	q.push(N);
	visited[N] = true;
	BFS(K);

	cout << minTime << endl;
}
