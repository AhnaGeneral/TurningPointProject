#include<iostream>
using namespace std; 
int a[100][100];
int b[100][100];
int result[100][100];
int n, m, k; 
void DivideAndConquer(int _n, int _m, int _k)
{
	int sum = 0; 
	for (int i = 0; i < _m; ++i)
	{
		sum += a[_n][i] * b[i][_k];
	}
	result[_n][_k] = sum;
	if (_k == k) return;
	DivideAndConquer(_n, _m, _k + 1);
	DivideAndConquer(_n + 1, _m, _k);
}
int main()
{

	cin >> n >> m; 
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}

	int  k;
	cin >> m >> k; 

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			cin >> b[i][j];
		}
	}
	DivideAndConquer(0, m, 0);

}