// »öÁ¾ÀÌ
#include <iostream>
using namespace std;
int Mat[100][100];


int(*power(int MatA[][100], int MatB[][100], int N))[100] // N * N 
{
	int SumAB[100][100];
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

int(*_power(int N, int B))[100]
{
	if (N == 1) return Mat;

	int(*x)[100] = _power(N, B/2);
	if (N % 2) // odd
	{
		return power(x, x, N);
	}
	else //even
	{
		return power(x, x, N);
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

	_power(N, B);

	return 0;
}