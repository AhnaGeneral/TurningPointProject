#include <iostream>
#include <memory.h>
using namespace std;
long long Mat[6][6];


long long(*power(long long MatA[][6], long long MatB[][6], int N))[6] // N * N 
{
	long long SumAB[6][6];
	memset(SumAB, 0, sizeof(SumAB));

	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < N; ++k)
		{
			for (int j = 0; j < N; ++j)
			{
				SumAB[i][k] += MatA[i][j] * MatB[j][k];
			}
			SumAB[i][k] %= 1000;
		}
	}

	return SumAB;
}

long long(*_power(int N, int B))[6]
{
	if (B == 1) return Mat;

	long long(*x)[6] = _power(N, B / 2);
	
	long long temp[6][6];

	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			temp[i][j] = x[i][j]; 
		}
	}

if (B % 2) // odd
{
	long long(*xs)[6] = power(temp, temp, N);

	long long temps[6][6];

	memset(temps, 0, sizeof(temps));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			temps[i][j] = xs[i][j];
		}
	}
	return power(temps, Mat, N);
}
else //even
{
	return power(temp, temp, N);
}
}
int main(void)
{
	int N, B;
	cin >> N >> B;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			int data;
			cin >> data;
			Mat[i][j] = data;
		}

	long long(*_result)[6] = _power(N, B);

	long long temps[6][6];

	memset(temps, 0, sizeof(temps));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			temps[i][j] = _result[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << temps[i][j] % 1000 << " ";
		}
		cout << endl; 
	}
	return 0;
}
