#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 128
int arr[MAX][MAX];
int blue, white;

void solve(int _x, int _y, int _size)
{
	int check = arr[_y][_x];
	for (int i = _y; i < _y + _size; i++)
	{
		for (int j = _x; j < _x + _size; j++)
		{
			if (check == 0 && arr[i][j] == 1)
			{
				check = 2;
			}
			else if (check == 1 && arr[i][j] == 0)
			{
				check = 2;
			}
			if (check == 2)
			{
				solve(_y, _x, _size / 2);
				solve(_y, _x + _size / 2, _size / 2);
				solve(_y + _size / 2, _x, _size / 2);
				solve(_y + _size / 2, _x + _size / 2, _size / 2);
				return;
			}
		}
	}
	if (check == 0)
		white++;
	else
		blue++;
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}
	solve(0, 0, n);
	cout << white << '\n';
	cout << blue << '\n';
	return 0;
}