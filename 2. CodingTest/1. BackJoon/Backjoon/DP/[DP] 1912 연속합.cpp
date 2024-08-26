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
	
	int arr[100'001], DP[100'001], N;
	cin >> N;
	cin >> arr[1];
	DP[1] = arr[1]; 

	for (int i = 2; i <= N; i++) {
		cin >> arr[i];
		if (arr[i] < arr[i] + DP[i - 1])
			DP[i] = arr[i] + DP[i - 1];
		else
			DP[i] = arr[i];
	}
	int _max = -1'000; 
	for (int i = 1; i <= N; i++) {
		if (DP[i] > _max)
			_max = DP[i];
	}

	cout << _max; 


}