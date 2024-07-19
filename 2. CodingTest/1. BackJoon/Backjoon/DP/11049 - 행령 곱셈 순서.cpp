
//== [ 행렬 곱셈 순서 ] ==

#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int col[500], row[500];
int dp[500][500];

int func(int idx_x, int idx_y)
{
	if (dp[idx_x][idx_y]) 
		return dp[idx_x][idx_y];

 	if (idx_x == idx_y)
		return 0; 
	
	int mm = INT_MAX; 

	for (int j = idx_x; j < idx_y; ++j) 
	// (j == idx_x) 경우는 ABCD 있다면 AB경우.
	{
		mm = min(mm, row[idx_x] * col[j] * col[idx_y] + func(idx_x, j) + func(j + 1, idx_y));
	}

	return dp[idx_x][idx_y] = mm;
}
int main(void)
{
	int n; 
	cin >> n; 

	for (int i = 0; i < n; ++i)
		cin >> row[i] >> col[i];

	cout << func(0, n - 1);

	return 0;
}