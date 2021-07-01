// Baekjoon 

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int arr[10]; 
int visit[10]; 

void solve(int _N, int _M, int _index, int _start)
{

	if (_M == _index)
	{
		for (int i = 0; i < _M; i++)
			cout << arr[i] << " "; 
		cout << "\n";
		return; 
	}

	for (int i = _start; i <= _N; i++)
	{
		visit[i] = true; // [1] = ture  [1] = ture  [2] = ture
		arr[_index] = i; // [0] = 1     [1] = 1     [1] = 2 
		solve(_N, _M, _index + 1, i);
		visit[i] = false; //                        [1] = false; 
	}
} 
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int N, M;
	cin >> N >> M;

	solve(N, M, 0, 1); 
}