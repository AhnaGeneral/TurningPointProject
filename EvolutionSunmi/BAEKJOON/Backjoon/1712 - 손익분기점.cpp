// Baekjoon - 1712 손익분기점

#include <iostream> 
#include <cmath>
#include <vector>

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	unsigned long A, B, C;

	std::cin >> A >> B >> C;

	if (B >= C)
	{
		std::cout << -1;
		return 0; 
	}
	else
	{
		int tmp = C - B; 
		int result = (A / tmp) + 1; 
		std::cout << result; 
		return 0; 
	}
}
