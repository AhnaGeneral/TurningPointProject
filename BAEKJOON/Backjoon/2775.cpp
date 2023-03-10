#include<iostream>
using namespace std; 

int arr[15][15];

int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	for (int i = 0; i <= 14; ++i)
	{
		arr[0][i] = i;
		arr[i][1] = 1;
	}

	for (int i = 1; i <= 14; ++i)
	{
		for (int j = 2; j <= 14; ++j)
		{
			arr[i][j] = arr[i][j-1] + arr[i-1][j];
		}
	}


	int T; 
	cin >> T; 

	while (T--)
	{
		int k, n; 
		cin >> k >> n; 

		cout << arr[k][n] << "\n";
	}
	return 0; 
}