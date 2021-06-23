#include <iostream>
using namespace std;
// 에라토스테네스의 체
// 1은 소수가 아니다. 
// 2는 소수이다 -> 2의 배수는 소수가 아니다. 
// 3은 소수이다 -> 3의 배수는 소수가 아니다.
// 5는 소수이다 -> 5의 배수가 소수가 아니다.

bool sosu(int _k)
{
	if (_k == 1||_k==0)
		return false;
	for (int i = 2; i * i <= _k; i++)
	{
		if (_k != i)
		{
			if (_k % i == 0) return false;
		}
		for (int j = i + i; j <= _k; j += i)
		{
			if (_k % j == 0) return false; 
		}
	}
	return true; 
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();
	int M, N, First, sum = 0; 
	cin >> M >> N; 
	bool botton = false; 
	for (int k = M; k <= N; ++k)
	{
		if (sosu(k))
		{
			if (!botton) First = k; 
			sum += k;
			botton = true;
		}
	}
	if (botton)
		cout << sum << endl << First;
	else
		cout << -1;
	return 0; 
}