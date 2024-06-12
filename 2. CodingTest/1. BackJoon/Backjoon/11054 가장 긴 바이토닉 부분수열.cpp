// Baekjoon 

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();
	// ===========================
	int N; cin >> N; 
	vector<int> seq(N); 
	for (int i = 0; i < N; i++)
		cin >> seq[i];
	// ===========================
	vector<int> InC(N,1), DeC(N,1);
	for(int i =1; i < N; i++)
		for (int j = 0; j < i; j++)
		{
			if (seq[i] > seq[j])
				InC[i] = max(InC[j] + 1, InC[i]);

			if(seq[N-i-1]>seq[N-j-1])
				DeC[N - i - 1] = max(DeC[N - j - 1 ] + 1, DeC[N - i - 1]);
		}
	// ===========================
	int _max = -1000;
	for (int i = 0; i < N; i++)
	{
		if (_max < InC[i] + DeC[i])
			_max = InC[i] + DeC[i]; 
	}
	cout << _max - 1; 
}