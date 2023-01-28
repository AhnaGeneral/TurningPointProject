#include <iostream>
using namespace std; 

int A[1'000], DP[1'000], index[1'000];

int main()
{
	int N; 
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	DP[0] = 1;
	int maxNumber = 1; 

	for (int i = 1; i < N; ++i)
	{
		DP[i] = 1;

		for (int j = 0; j < i; ++j)
		{
			if (A[i] > A[j] && DP[i] < DP[j] + 1)
			{
				DP[i] = DP[j] + 1; 
				if (maxNumber < DP[i])
				{
					maxNumber = DP[i];
				}
			}

		}
	}

	cout << maxNumber;
	return 0; 
}