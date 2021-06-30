// Baekjoon - 15649 N°úM(1)

#include <iostream> 
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;  
int arr[10];
bool visited[10]; 

void DFS(int _count, int _N, int _M, int _T)
{
	if (_count == _M)
	{
		for (int i = 0; i < _M; i++)
		{
			cout << arr[i] << " "; 
		}
		cout << "\n"; 
		return; 
	}

	for (int i = _T; i <= _N; i++)
	{
		if (!visited[i]) 
		{

			// i = 1  DFS(0) -> visited[1] = true , arr[0] = 1,
			// i = 1  DFS(1) -> visited[1] = true , arr[0] = 1, -> return -> visited[1] = false 
			// i = 2  visited[1], arr[0] = 2  DFS(1) -> v 
			// i = 3  visited [1] 
			// 
			arr[_count] = i; 
			DFS(_count + 1, _N ,_M, _T); 
			visited[i] = true; 
		}
	}
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	
	int N, M;

	
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		DFS(0, N, M, i);

		for (int i = 0; i < 10; i++)
			visited[i] = false;
	}
	return 0; 
	 
	
}
