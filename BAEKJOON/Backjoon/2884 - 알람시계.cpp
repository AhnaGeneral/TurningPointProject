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

	int N, M; cin >> N >> M; 
	// (0 ¡Â H ¡Â 23, 0 ¡Â M ¡Â 59) 

	if (M >= 45)
	{
		cout << N << " " << M - 45;
	}
	else {
		int _M = M - 45; 
		_M = 60 + _M; 
		
		if (N == 0)
			cout << 23 << " " << _M;
		else
			cout << N - 1 << " " << _M;
	}

}