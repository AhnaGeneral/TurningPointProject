// Baekjoon - 15650 N°úM(2)

#include <iostream> 
using namespace std;
#define _max 10
int arr[_max]; 
int visite[_max]; 


void solve(int n, int m, int index, int start)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " "; 
		}
		cout << "\n";
	}
	for (int i = start; i <= n; i++)
	{
		if (visite[i]) continue;
		visite[i] = true; 
		arr[index] = i;
		solve(n, m, index + 1, i + 1); 
		visite[i] = false; 
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();
	
	int n, m; 
	cin >> n >> m;
	int index = 0; 
	int start = 1; 
	solve(n, m, index, start);

	return 0;
}
