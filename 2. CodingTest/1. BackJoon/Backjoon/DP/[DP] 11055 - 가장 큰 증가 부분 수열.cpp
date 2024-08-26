#include <iostream>
#include <algorithm>
using namespace std;
int A[1000];
int DP[1000];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	// A[10] = {1, 100, 2, 50, 60, 3, 4, 8, 3}
	DP[0] = A[0];

	int _result = DP[0];

	for (int i = 1; i < N; ++i)
	{
        DP[i] = A[i]; 
		for (int j = 0; j < i; ++j)
		{
			// ex) (A[0] == 1 < A[1] == 100) (DP[1]==0 < DP[0]+100 ==101) 
			// ex) (A[0] == 1 < A[4] == 60) (DP[4]==0 < DP[0]+A[0] ==101) 
			if ((A[j] < A[i]) && (DP[i] < DP[j] + A[i]))
			{
				DP[i] = DP[j] + A[i];
				_result = max(DP[i], _result); 
			}
		}
	}


	cout << _result; 
	return 0;
}