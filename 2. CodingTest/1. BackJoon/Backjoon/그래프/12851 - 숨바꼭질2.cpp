#include<iostream>
#include<queue>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

bool gVisit[100001] = {false, };
int	visit[100001] = { 0, };

queue<pair<int, int>> _que; 
vector<int> _vec;

int _count = 0; 
int main(void)
{
	int N, K;
	cin >> N >> K; 
	_que.push(make_pair(K, 0)); 
	
	while (!_que.empty())
	{
		pair<int,int> temp = _que.front();
		_que.pop();

		gVisit[temp.first] = true;

		if (temp.first == N)
		{
			_count = temp.second;
			break;
		}

		if (temp.first + 1 >= 0 && temp.first + 1 <= 100001
			&& gVisit[temp.first + 1] == false)
		{
			// visit[10] = 9 
			// visit[18] = 17 
			gVisit[temp.first + 1] = true; 
			visit[temp.first + 1] = temp.first;
			_que.push(make_pair(temp.first + 1, temp.second + 1));
		}

		if (temp.first - 1 >= 0 && temp.first - 1 <= 100001
			&& gVisit[temp.first - 1] == false)
		{
			gVisit[temp.first - 1] = true;
			visit[temp.first - 1] = temp.first;
			_que.push(make_pair(temp.first - 1, temp.second + 1));
		}

		if (temp.first % 2 == 0 && temp.first / 2 >= 0
			&& temp.first / 2 <= 100001 && gVisit[temp.first / 2] == false)
		{
			// visit[5] = 10
			// visit[9] = 18
			gVisit[temp.first / 2] = true;
			visit[temp.first / 2] = temp.first;
			_que.push(make_pair(temp.first / 2, temp.second + 1));
		}

	}

	if (N == K)
	{
		cout << _count << endl;
		cout << N; 
	}
	else
	{

		cout << _count << endl; 
		cout << N << " ";
		int next = N;
		while (visit[next] != K)
		{
			cout << visit[next] << " ";
			next = visit[next];
		}
		cout << K;
		//sort(_vec.begin(), _vec.end());
	}
	return 0;
}