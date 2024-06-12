#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

vector<long long> dist, cost;
long gasStation (int _startIdx, int _endIdx) // 0, 5
{
	if (_startIdx == _endIdx) return 0; 

	long long _result = 1'000'000'000; 

	for (int i = _startIdx; i < _endIdx; ++i)
	{
		int maxDist = 0;
		for (int j = _startIdx; j < i + 1; ++j)
		{
			maxDist += dist[j];
		}
		_result = min(maxDist * cost[_startIdx] + gasStation(i + 1, _endIdx), _result);
	}
	return _result;
};

int main()
{
	int N; cin >> N; 
	//=================================================//

	for (int i = 0; i < N - 1; ++i)
	{
		int _dist; 
		cin >> _dist; 
		dist.emplace_back(_dist);
	}
	for (int i = 0; i < N; ++i)
	{
		int _cost;
		cin >> _cost;
		cost.emplace_back(_cost);
	}

	//=================================================//
	cout << gasStation(0, N-1);
	
}