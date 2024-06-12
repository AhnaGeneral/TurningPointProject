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

	int N; cin >> N; 
	int half = N / 2, SmallFactor =2;
	if (N == 1) return 0;

	while (true)
	{
		//if (SmallFactor > half)
		//{
		//	return 0; 
		//}
		if (!(N % SmallFactor)) { // 나머지가 0이라면, 
			cout << SmallFactor << "\n";
			N = N / SmallFactor;
			if (N == 1) return 0;
			continue;
		}
		else
		{
			SmallFactor++;
		}
	}
}