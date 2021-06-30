// Baekjoon - 15650 N°úM(2)

#include <iostream> 
using namespace std;
#define _max 10
int n, m; 
int arr[_max];
int visitied[_max]; 

void dfs(int _count, int _t)
{
	if (_count == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " "; 
		cout << "\n"; 
		return; 
	}

	for (int i = _t; i <= n; i++)
	{
		if (!visitied[i])
		{
			visitied[i] = true;
			arr[_count] = i; // arr[0] = 1 arr[1] = 2 arr[2] = 
			dfs(_count + 1, _t);
		}
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	cin >> n >> m; 

	if (m != 1)
	{
		for (int i = 1; i < n; i++)
		{
			dfs(0, i);
			for (int i = 0; i < _max; i++)
				visitied[i] = 0;
		}
	}
	else 
		dfs(0, 1);
	return 0;
}
