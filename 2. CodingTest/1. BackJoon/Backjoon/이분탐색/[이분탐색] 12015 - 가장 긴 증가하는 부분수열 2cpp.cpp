#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int A[1'000'000], DP[1'000'000 ];
vector<int> vec; 

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	vec.push_back(A[0]);

	for (int i = 1; i < N; ++i)
	{
		if (vec.back() < A[i])
		{
			vec.push_back(A[i]);
		}
		else
		{
			int st = 0; 
			int ed = vec.size() - 1;
			int mid = ed; 

			while (ed > st)
			{   // 10 20 30  <--- (15)
				int mid = (st + ed) / 2; 
				if (A[i] > vec[mid]) // 15 > 10 
				{
					st = mid + 1;
				}
				else // (15 > 20) X 
				{
					ed = mid; 
				}
			}
			vec[ed] = A[i]; 
		}
	}

	cout << vec.size();
	return 0; 
}