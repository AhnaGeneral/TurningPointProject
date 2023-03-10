#include<iostream>
#include <vector>
using namespace std;
int A[1000], DP[1000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; 
	cin >> N; 

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
    int maxCount = 1; 
    int index = 0;
	DP[0] = 1;

	for (int i = 1; i < N; ++i) {
		DP[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if ((A[j] < A[i]) && (DP[i]< DP[j] + 1))
			{
				DP[i] = DP[i] + 1; 
                if(maxCount< DP[i])
                {
                    maxCount = DP[i]; 
                    index = i;
                }
			}
		}
	}
    
    cout << maxCount <<"\n";
    DP[index] = 1; 
	for (int j = 0; j < index; ++j)
	{
		if ((A[j] < A[index]) && (DP[index]< DP[j] + 1))
		{
			DP[index] = DP[index] + 1; 
            cout << A[j] <<" ";
		}
	}

	return 0;
}