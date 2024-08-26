#include <iostream>
#include <math.h>
using namespace std; 
int arr[20'000][20'000]; 
int resultcount = 0;


// 0 1 2 3 4 5 6 7 8
void Z(int N, int row, int col)
{
	if (N == 1)
	{
		arr[row][col]			= ++resultcount;
		arr[row][col + 1]		= ++resultcount;
		arr[row + 1][col]		= ++resultcount;
		arr[row + 1][col + 1]	= ++resultcount;
		return; 
	}
	
	float n_pow = pow(2, N - 1);

	Z(N - 1, row, col); 
	Z(N - 1, row, col + n_pow);
	Z(N - 1, row + n_pow, col);
	Z(N - 1, row + n_pow, col + n_pow);
}

int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	int N, r, c; 
	cin >> N >> r >> c;

	Z(N, 0, 0);


	cout << arr[r][c]-1 ;
	return 0; 
}