#include<iostream>
#include <vector>
using namespace std;
int A[1000], DP[1000];
vector<int> vec[1000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; 
	pair<int, int> Result = {1,0};
	cin >> N; 

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	DP[0] = 1;
	for (int i = 1; i < N; ++i) {
		DP[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if ((A[j] < A[i]) && (DP[i]< DP[j] + 1))
			{
				DP[i] = DP[i] + 1; 
				vec[i].push_back(A[j]);
				if (Result.first < DP[i])
				{
					Result.first = DP[i];
					Result.second = i; 
				
				}
			}
		}
	}

	cout << Result.first <<"\n";

	if (Result.first != 1)
	{
		for (int j = 0; j < vec[Result.second].size(); ++j)
		{
			cout << vec[Result.second][j] << " ";
		}
		cout << A[Result.second];
	}
	else
	{
		cout << A[0]; 
	}
	return 0;
}