#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 64
char arr[MAX][MAX]; 

void QuadTree(int _x, int _y, int _size)
{
	char check = arr[_y][_x];
	for (int i = _y; i < _y + _size; ++i)
	{
		for (int j = _x; j < _x + _size; ++j)
		{
			if( arr[i][j] != check)
			{
				cout << '(';
				QuadTree(_x, _y, _size / 2);
				QuadTree(_x + _size / 2, _y, _size / 2);
				QuadTree(_x, _y + _size / 2, _size / 2);
				QuadTree(_x + _size / 2, _y + _size / 2, _size / 2);
				cout << ')';
				return;
			}
		}
	}
	cout << check;

}
int main(void)
{
	std::ios::sync_with_stdio(false);

	int n;	cin >> n;
	string str;

	for (int i = 0; i < n; ++i)
	{
		cin >> str; 

		for (int j = 0; j < str.size(); ++j)
		{
			arr[i][j] = str[j];
		}
	}
	//for (int i = 0; i < n; ++i)
	//	for (int j = 0; j < n; ++j)
	//		cin >> arr[i][j];

	QuadTree(0, 0, n);
}